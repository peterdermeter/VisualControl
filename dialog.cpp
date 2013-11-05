#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    cThread =  new QThread(this);
    Epiphan = new Epiphan2USB;                  //Initialize Framegrabber Class
    Epiphan->InitializeThread(cThread);
    Epiphan->moveToThread(cThread);
    image   = new imageFunctions(this);         //Initialize ImageProcessing Class
    AngleDataAfter[0] = 0;
    AngleDataAfter[1] = 0;

    ///////////////////////////////////////////////////////////////////////////////////////////
    ////! Set Fixed Dialog-Size and display TUM/MIMED Label  !/////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
    unsigned int ScreenWidth  = QApplication::desktop()->screenGeometry().width();
    unsigned int ScreenHeight = QApplication::desktop()->screenGeometry().height();
    pixmapWidth  = ScreenWidth/2.732;
    pixmapHeight = ScreenHeight/2.048;
    unsigned int dialogWidth  = 1270;
    unsigned int dialogHeight = 570;
    processingWidth  = 700;
    processingHeight = 525;

    qDebug() << ScreenWidth;
    qDebug() << ScreenHeight;
    qDebug() << pixmapHeight;
    qDebug() << pixmapWidth;


    QWidget::setFixedSize(dialogWidth, dialogHeight);
    ui->lblOriginal->setFixedSize(pixmapWidth, pixmapHeight);
    ui->lblProcessed->setFixedSize(pixmapWidth, pixmapHeight);

    QImage MIMED;
    QImage TUM;
    MIMED.load("MIMED.jpg");
    TUM.load("TUM.jpg");
    ui->MIMEDLabel->setPixmap(QPixmap::fromImage(MIMED));
    ui->TUMLabel->setPixmap(QPixmap::fromImage(TUM));
    matOriginalAndCircleCreated = false;


    ///////////////////////////////////////////////////////////////////////////////////////////
    ////! Initialize Timer and set Buttons disabled !//////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGui()));
    tmrTimer->stop();
    ui->btnStartOrPause->setDisabled(true);
    ui->closeFrmGrab->setDisabled(true);
    ui->btnSaveImage->setDisabled(true);
}

Dialog::~Dialog()
{
    delete ui;
}


///////////////////////////////////////////////////////////////////////////////////////////
////! Process Frame and Display  !/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Dialog::processFrameAndUpdateGui()
{
    ////! Check if Framegrab worked  !/////////////////////////////////////////////////////////
    if(Epiphan->framegrabIsFailed())
    {
        QMessageBox::warning(this, "Warning", "USB or Videosource not connected!");
        tmrTimer->stop();
        ui->btnStartOrPause->setText("Start");
        ui->btnStartOrPause->setDisabled(true);
        ui->closeFrmGrab->setDisabled(true);
        ui->openFrmGrab->setDisabled(false);
        ui->textBrowser->setText("Framegrabber successfully closed");
        Epiphan->Close();
        return;
    }


    ////! Processing Image  !//////////////////////////////////////////////////////////////////
    AngleDataBefore = AngleDataAfter;
    cv::resize(matOriginal,   matOriginalProcessing,  matCircle.size());
    cv::cvtColor(matOriginalProcessing, matProcessedProcessing, CV_BGR2GRAY);
    cv::blur(matProcessedProcessing, matProcessedProcessing, cv::Size(3,3));
    matProcessedProcessing = matProcessedProcessing + matCircle;

    image->getROI(matProcessedProcessing);

    image->getMassCenters(matProcessedProcessing, MassCenter);

    image->drawMassCenters(matOriginalProcessing, MassCenter);

    image->getAngles(matProcessedProcessing, MassCenter[0], AngleData);

    image->getMotorData(AngleData, AngleDataBefore, AngleDataAfter, MotorData);



    ////! Displaying Images on GUI  !//////////////////////////////////////////////////////////
    cv::resize(matOriginalProcessing,  matOriginalPixmap,  cv::Size(pixmapWidth, pixmapHeight));
    cv::resize(matProcessedProcessing, matProcessedPixmap, cv::Size(pixmapWidth, pixmapHeight));
    cv::cvtColor(matOriginalPixmap, matOriginalPixmap, CV_BGR2RGB);             //QImage cannot handle BGR-Format -> convert
    QImage qimgOriginal((uchar*)matOriginalPixmap.data, matOriginalPixmap.cols, matOriginalPixmap.rows, matOriginalPixmap.step, QImage::Format_RGB888);
    QImage qimgProcessed((uchar*)matProcessedPixmap.data, matProcessedPixmap.cols, matProcessedPixmap.rows, matProcessedPixmap.step, QImage::Format_Indexed8);
    ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));
    ui->lblProcessed->setPixmap(QPixmap::fromImage(qimgProcessed));
    return;
}




///////////////////////////////////////////////////////////////////////////////////////////
////! Start and Pause Imagestream  !///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Dialog::on_btnStartOrPause_clicked()
{
    if(tmrTimer->isActive() == true)
    {
        tmrTimer->stop();
        Epiphan->stopDoWork();
        ui->btnStartOrPause->setText("Start");
    }
    else
    {
        Epiphan->startDoWork();
        while(cThread->isFinished()) {}
        tmrTimer->start(20);
        ui->btnStartOrPause->setText("Pause");
        ui->btnSaveImage->setDisabled(false);
    }
    return;
}




///////////////////////////////////////////////////////////////////////////////////////////
////! Open Framegrabber  !/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Dialog::on_openFrmGrab_clicked()
{
    if(Epiphan->Open())
    {
        if(!matOriginalAndCircleCreated)
        {
            unsigned int w, h, bpp;
            Epiphan->getImageFormat(w, h, bpp);
            matOriginal.create(cv::Size(w,h), CV_8UC3);
            Epiphan->getFrame(matOriginal);                                                 //set Pointer of matOriginal to V2UFrame2
            matCircle.create(cv::Size(processingWidth, processingHeight), CV_8UC1);         //create matCircle (Grayscale, 700x525)
            matCircle = cv::Scalar(255);                                                    //make matCircle completely white
            cv::circle(matCircle, cv::Point(processingWidth/2,processingHeight/2), 250, cv::Scalar(0), CV_FILLED);       //fill matCircle with black cirle
            matOriginalAndCircleCreated = true;
        }

        ui->textBrowser->setText("Framegrabber successfully opened");
        ui->openFrmGrab->setDisabled(true);
        ui->closeFrmGrab->setDisabled(false);
        ui->btnStartOrPause->setDisabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Information", "Framegrabber not properly connected!");
    }
    return;
}




///////////////////////////////////////////////////////////////////////////////////////////
////! Close Framegrabber  !////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Dialog::on_closeFrmGrab_clicked()
{
    tmrTimer->stop();
    cThread->start();

    Epiphan->stopDoWork();
    connect(cThread, SIGNAL(finished()), this, SLOT(CloseFrameGrabber()));

    return;
}

void Dialog::CloseFrameGrabber()
{
    Epiphan->Close();
    ui->btnStartOrPause->setText("Start");
    ui->btnStartOrPause->setDisabled(true);
    ui->closeFrmGrab->setDisabled(true);
    ui->openFrmGrab->setDisabled(false);
    ui->textBrowser->setText("Framegrabber successfully closed");
    disconnect(cThread, SIGNAL(finished()), this, SLOT(CloseFrameGrabber()));
    return;
}




///////////////////////////////////////////////////////////////////////////////////////////
////! Close Application  !/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Dialog::on_CloseApp_clicked()
{
    tmrTimer->stop();
    Epiphan->stopDoWork();
    connect(cThread, SIGNAL(finished()), this, SLOT(close()));
    if(!cThread->isRunning())
    {
        close();
    }

    return;
}


///////////////////////////////////////////////////////////////////////////////////////////
////! Save Image to harddrive  !///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Dialog::on_btnSaveImage_clicked()
{
    std::stringstream convert;
    t = time(0);
    now = localtime( & t );
    convert     << (now->tm_year + 1900)    << '.'
                << (now->tm_mon + 1)        << '.'
                <<  now->tm_mday            << '-'
                <<  now->tm_hour            << '.'
                <<  now->tm_min             << '.'
                <<  now->tm_sec             << '_';
    DateAndTime = convert.str();

    cv::imwrite("../Images/" + DateAndTime + "image.bmp", matOriginal);
    return;
}


