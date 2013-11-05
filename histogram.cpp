#include "histogram.h"

Histogram::Histogram()
{
}


cv::MatND Histogram::getHistogramValues(const cv::Mat &image) const
{
    cv::MatND hist;

    cv::calcHist(&image,
                 1,          //1 image only
                 0,          //channels
                 cv::Mat(),  //no mask
                 hist,       //destination
                 1,          //1D histogram
                 &histSize,  //number of bins
                 &histRange,
                 true,
                 false);
    return hist;
}

cv::Mat Histogram::getHistogramImage(const cv::Mat &image) const
{
    cv::MatND hist = getHistogramValues(image);     //get HistogramValues and save in hist

    double max = 0;
    double min = 0;
    cv::minMaxLoc(hist, &min, &max);

    cv::Mat histImg (256, 256, CV_8UC1, cv::Scalar(255));

    for(int i = 0; i < 256; i++)
    {
        float value = hist.at<float>(i);
        int intensity = static_cast<int>(value/max * 0.9*256);

        cv::line(histImg, cv::Point(i,256), cv::Point(i,256-intensity), cv::Scalar(0));
    }

    return histImg;
}


