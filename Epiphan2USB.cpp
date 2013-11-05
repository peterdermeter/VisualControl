#include "Epiphan2USB.h"
#include <QEventLoop>


Epiphan2USB::Epiphan2USB(QObject *parent) :  QObject(parent)
{
    Grabber = (FrmGrabber*) malloc(sizeof(FrmGrabber*));            //allocating memory for Pointer to Epiphan2USB
    memset (Grabber, 0, sizeof(FrmGrabber*));                       //setting allocated memory to zero
    Frame = (V2U_GrabFrame2*) malloc(sizeof(V2U_GrabFrame2*));      //allocating memory for Pointer to grabbed Frame
    memset(Frame, 0, sizeof(V2U_GrabFrame2*));                      //setting allocated memory to zero
    ImageDataSize = 0;
    ImageWidth = 0;
    ImageHeight = 0;
    ImageBpp = 0;
    GrabFormat = 0;
    video_mode_detected = false;
    Epiphan2USB_open = false;
    framegrab_failed = false;
    stopThread = false;
}



Epiphan2USB::~Epiphan2USB()
{
  Close();
}

bool Epiphan2USB::Open()
{
    if(!Epiphan2USB_open)
    {
        Grabber = FrmGrabLocal_Open();                  //Pointer is set to Epiphan2USB
        if (!Grabber) return false;
        GrabFormat = V2U_GRABFRAME_FORMAT_BGR24;
        Epiphan2USB_open = true;

        if(!video_mode_detected)
        {
            if(!FrmGrab_DetectVideoMode(Grabber, &vm)) return false;        //Detecting Width, Height
            video_mode_detected = true;
        }
        cropRect.x = 0;
        cropRect.y = 0;
        cropRect.width = vm.width;
        cropRect.height = vm.height;
        ImageWidth	= vm.width;
        ImageHeight	= vm.height;
        ImageBpp	= V2UPALETTE_2_BPP (GrabFormat);
        ImageDataSize = ImageWidth * ImageHeight * ImageBpp/8;
        ImageData = new unsigned char[ImageDataSize];                       //allocating memory for Imagedata
        framegrab_failed = false;
    }
    return true;
}

bool Epiphan2USB::Close()
{
    if(Epiphan2USB_open)
    {
        FrmGrab_Close(Grabber);
        delete[] ImageData;                 //free memory
        Epiphan2USB_open = false;
        video_mode_detected = false;
    }
    return true;
}

bool Epiphan2USB::isOpen() const
{
    return Epiphan2USB_open;
}


bool Epiphan2USB::getFrame(cv::Mat& Picture) const
{
    if (!Epiphan2USB_open) return false;

    Picture.data = ImageData;               //Pointer of Mat Picture is set to Imagedata(no copy)

    return true;
}


bool Epiphan2USB::getImageFormat(unsigned int& nWidth, unsigned int& nHeight, unsigned int& Bpp) const
{
    if (!Epiphan2USB_open) return false;

    nWidth = ImageWidth;
    nHeight = ImageHeight;
    Bpp = ImageBpp;

    return true;
}


bool Epiphan2USB::setCropArea(const unsigned int& x0, const unsigned int& y0, const unsigned int& nWidth, const unsigned int& nHeight)
{
    if (!Epiphan2USB_open) return false;

    cropRect.x = x0;
    cropRect.y = y0;
    cropRect.width = nWidth;
    cropRect.height = nHeight;
    //GrabFormat &= ~V2U_GRABFRAME_SCALE_NEAREST;  // disable scaling
    return true;
}

bool Epiphan2USB::getCropArea(unsigned int &nCropX0, unsigned int &nCropY0, unsigned int &nCropWidth, unsigned int &nCropHeight, unsigned int &nWidth, unsigned int &nHeight) const
{
    if (!Epiphan2USB_open) return false;

    nCropX0 = cropRect.x;
    nCropY0 = cropRect.y;
    nCropWidth = cropRect.width;
    nCropHeight = cropRect.height;
    nWidth = ImageWidth;
    nHeight = ImageHeight;

    return true;
}


unsigned int Epiphan2USB::getImageDataSize() const
{
    return ImageDataSize;
}

unsigned int Epiphan2USB::getGrabFormat() const
{
    return GrabFormat;
}

void Epiphan2USB::setGrabFormat(const unsigned int& format)
{
    GrabFormat = format;
    ImageBpp	= V2UPALETTE_2_BPP (GrabFormat);
    ImageDataSize = ImageWidth * ImageHeight * ImageBpp/8;
    return;
}

bool Epiphan2USB::framegrabIsFailed()
{
    return framegrab_failed;
}

void Epiphan2USB::InitializeThread(QThread *cThread)
{
    connect(cThread, SIGNAL(started()), this, SLOT(DoWork()));
    connect(this, SIGNAL(finished()), cThread, SLOT(quit()));
    connect(this, SIGNAL(started()), cThread, SLOT(start()));
    return;
}

void Epiphan2USB::startDoWork()
{
    stopThread = false;
    emit started();
    return;
}

void Epiphan2USB::stopDoWork()
{
    stopThread = true;
    return;
}

void Epiphan2USB::DoWork()
{
    while(!stopThread)
    {
        if (!Epiphan2USB_open) break;
        Frame = FrmGrab_Frame(Grabber, GrabFormat, &cropRect);
        if(!Frame)
        {
            framegrab_failed = true;
            break;
        }

        memcpy(this->ImageData, (unsigned char*)Frame->pixbuf, ImageDataSize);
        FrmGrab_Release(Grabber, Frame);
    }
    emit finished();
    return;
}
