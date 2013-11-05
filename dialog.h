#ifndef DIALOG_H
#define DIALOG_H

#include "Epiphan2USB.h"
#include "histogram.h"
#include "imageFunctions.h"


//! Qt Libraries
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QThread>
#include <QDesktopWidget>
#include <QRect>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    
private slots:
    void processFrameAndUpdateGui();

    void on_btnStartOrPause_clicked();

    void on_openFrmGrab_clicked();

    void on_CloseApp_clicked();

    void on_closeFrmGrab_clicked();
    void CloseFrameGrabber();

    void on_btnSaveImage_clicked();

private:
    Ui::Dialog *ui;

    unsigned int pixmapWidth, pixmapHeight, processingWidth, processingHeight;
    std::vector<cv::Point2f> MassCenter;
    cv::Vec3d AngleData;
    cv::Vec2d AngleDataBefore;
    cv::Vec2d AngleDataAfter;
    cv::Vec2i MotorData;

///////////////////////////////////////////////////
///!  Framegrabber  !//////////////////////////////
    Epiphan2USB *Epiphan;
    QThread *cThread;

///////////////////////////////////////////////////
///!  ImageFunctions  !////////////////////////////
    imageFunctions *image;

///////////////////////////////////////////////////
///!  Matrixes  !//////////////////////////////////
    cv::Mat matOriginal;
    cv::Mat matCircle;

    cv::Mat matOriginalProcessing;
    cv::Mat matProcessedProcessing;

    cv::Mat matOriginalPixmap;
    cv::Mat matProcessedPixmap;

    bool matOriginalAndCircleCreated;

///////////////////////////////////////////////////
///!  QImages  !///////////////////////////////////
    QImage qimgOriginal;
    QImage qimgProcessed;

///////////////////////////////////////////////////
///!  Time  !//////////////////////////////////////
    QTimer *tmrTimer;

    time_t t;
    struct tm * now;
    std::string DateAndTime;

};

#endif // DIALOG_H
