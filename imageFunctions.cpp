#include "imageFunctions.h"


double round(double x)
{
    using namespace std;

    if ((numeric_limits<double>::max() - 0.5) <= x)
        return numeric_limits<double>::max();

    if ((-1*std::numeric_limits<double>::max() + 0.5) > x)
        return (-1*std::numeric_limits<double>::max());

    double intpart;
    double fractpart = modf(x, &intpart);

    if (fractpart >= 0.5)
        return (intpart + 1);
    else if (fractpart >= -0.5)
        return intpart;
    else
        return (intpart - 1) ;

}



imageFunctions::imageFunctions(QObject *parent) : QThread(parent)
{
    max = 0;
    min = 0;
    elementOpen = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(9,9));
    elementClose = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(9,9));
}


imageFunctions::~imageFunctions()
{}


void imageFunctions::getROI(const cv::Mat &src)
{
    hist = h.getHistogramValues(src);
    cv::minMaxLoc(cv::MatND(hist, cv::Rect(0,0,1,100)), 0, &max, 0, &maxIndex);					//first max
    cv::minMaxLoc(cv::MatND(hist, cv::Rect(0,maxIndex.y+10,1,30)), &min, 0, &minIndex, 0);		//first min after first max
    minIndex.y += maxIndex.y + 10;

    cv::threshold(src, src, minIndex.y, 255, CV_THRESH_BINARY_INV);
    cv::morphologyEx(src, src, cv::MORPH_CLOSE, elementClose);
    cv::morphologyEx(src, src, cv::MORPH_OPEN, elementOpen);
}


void imageFunctions::getMassCenters(const cv::Mat &src, std::vector<cv::Point2f> &mc) const
{
    cv::Mat Edges;
    std::vector<std::vector<cv::Point> > Contours;
    std::vector<cv::Vec4i> Hierarchy;

    /// Detect edges using canny
    cv::Canny(src, Edges, 100, 100*2, 3);
    /// Find contours
    cv::findContours(Edges, Contours, Hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point(0,0));

    /// Get the moments
    std::vector<cv::Moments> mu(Contours.size());
    for(unsigned int i = 0; i < Contours.size(); i++)
    {
        mu[i] = cv::moments(Contours[i], false);
    }

    ///  Get the mass centers:
    mc.resize(Contours.size());
    for(unsigned int i = 0; i < Contours.size(); i++)
    {
        mc[i] = cv::Point2f(float(mu[i].m10/mu[i].m00), float(mu[i].m01/mu[i].m00));
    }
}



void imageFunctions::drawMassCenters(cv::Mat &src, const std::vector<cv::Point2f> &mc) const
{
    for(unsigned int i = 0; i < mc.size(); i++)
    {
        cv::circle(src, mc[i], 4, cv::Scalar(0,0,255), -1, 8, 0);
    }
}



void imageFunctions::getAngles(const cv::Mat &src, const cv::Point2f &MassCenter, cv::Vec3d &AngleData) const
{
    unsigned int rows = src.rows;
    unsigned int cols = src.cols;

    unsigned int k = 2100;

    AngleData[0] = std::atan(std::abs(MassCenter.x-cols/2)/std::abs(MassCenter.y-rows/2)) * 180/M_PI;						//Angle_Rot
    AngleData[1] = std::atan((std::sqrt(pow((MassCenter.x-cols/2), 2) + pow((MassCenter.y-rows/2), 2)))/k) * 180/M_PI;		//Angle_Bend

    if(MassCenter.x >= cols/2)		//rechte hälfte
    {
        if(MassCenter.y <= rows/2)	//rechts oben
        {
            AngleData[2] = 1;
        }
        else							//rechts unten
        {
            AngleData[2] = 4;
        }
    }
    else								//linke hälfte
    {
        if(MassCenter.y <=rows/2)	//links oben
        {
            AngleData[2] = 2;
        }
        else							//links unten
        {
            AngleData[2] = 3;
        }
    }
}



void imageFunctions::getMotorData(const cv::Vec3d &AngleData, const cv::Vec2d &AngleDataBefore, cv::Vec2d &AngleDataAfter, cv::Vec2i &MotorData) const
{
    if (AngleData[2] == 1)
    {
        AngleDataAfter[0] = 90 - AngleData[0];
        if(AngleDataAfter[0] <= -30)
        {
            AngleDataAfter[0] = -30.0;
        }
        else if(AngleDataAfter[0] >= 30)
        {
            AngleDataAfter[0] = 30.0;
        }
        MotorData[0] = int(round(-((AngleDataAfter[0] + 32) * 1750/93 + 2150)));

        AngleDataAfter[1] = AngleDataBefore[1] - AngleData[1];
        if(AngleDataAfter[1] <= -40)
        {
            AngleDataAfter[1] = -40.0;
        }
        else if(AngleDataAfter[1] >= 40)
        {
            AngleDataAfter[1] = 40;
        }
        if((AngleDataAfter[1] >= -40) && (AngleDataAfter[1] < (-16)))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 143) * 450/103 +1800));
        }
        else if((AngleDataAfter[1] >= (-16)) && (AngleDataAfter[1] <= 40))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 16) *450/85 +2400));
        }
    }

    else if (AngleData[2] == 2)
    {
        AngleDataAfter[0] = AngleData[0];
        if(AngleDataAfter[0] <= -30)
        {
            AngleDataAfter[0] = -30.0;
        }
        else if(AngleDataAfter[0] >= 30)
        {
            AngleDataAfter[0] = 30.0;
        }
        MotorData[0] = int(round(-((AngleDataAfter[0] + 32) * 1750/93 + 2150)));

        AngleDataAfter[1] = AngleDataBefore[1] - AngleData[1];
        if(AngleDataAfter[1] <= -40)
        {
            AngleDataAfter[1] = -40.0;
        }
        else if(AngleDataAfter[1] >= 40)
        {
            AngleDataAfter[1] = 40;
        }
        if((AngleDataAfter[1] >= -40) && (AngleDataAfter[1] < (-16)))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 143) * 450/103 +1800));
        }
        else if((AngleDataAfter[1] >= (-16)) && (AngleDataAfter[1] <= 40))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 16) *450/85 +2400));
        }
    }

    else if (AngleData[2] == 3)
    {
        AngleDataAfter[0] = 90 - AngleData[0];
        if(AngleDataAfter[0] <= -30)
        {
            AngleDataAfter[0] = -30.0;
        }
        else if(AngleDataAfter[0] >= 30)
        {
            AngleDataAfter[0] = 30.0;
        }
        MotorData[0] = int(round(-((AngleDataAfter[0] + 32) * 1750/93 + 2150)));

        AngleDataAfter[1] = AngleDataBefore[1] + AngleData[1];
        if(AngleDataAfter[1] <= -40)
        {
            AngleDataAfter[1] = -40.0;
        }
        else if(AngleDataAfter[1] >= 40)
        {
            AngleDataAfter[1] = 40;
        }
        if((AngleDataAfter[1] >= -40) && (AngleDataAfter[1] < (20)))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 107) * 600/127 +2100));
        }
        else if((AngleDataAfter[1] >= (20)) && (AngleDataAfter[1] <= 40))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 57) *150/18 +2850));
        }
    }

    else
    {
        AngleDataAfter[0] = AngleData[0];
        if(AngleDataAfter[0] <= -30)
        {
            AngleDataAfter[0] = -30.0;
        }
        else if(AngleDataAfter[0] >= 30)
        {
            AngleDataAfter[0] = 30.0;
        }
        MotorData[0] = int(round(-((AngleDataAfter[0] + 32) * 1750/93 + 2150)));

        AngleDataAfter[1] = AngleDataBefore[1] + AngleData[1];
        if(AngleDataAfter[1] <= -40)
        {
            AngleDataAfter[1] = -40.0;
        }
        else if(AngleDataAfter[1] >= 40)
        {
            AngleDataAfter[1] = 40;
        }
        if((AngleDataAfter[1] >= -40) && (AngleDataAfter[1] < (20)))
        {
            MotorData[1] = int(round((AngleDataAfter[1] + 107) * 600/127 + 2100));
        }
        else if((AngleDataAfter[1] >= (20)) && (AngleDataAfter[1] <= 40))
        {
            MotorData[1] = int(round((AngleDataAfter[1] - 57) *150/18 + 2850));
        }
    }
}
