#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


static int histSize = 256;
static float range[] = { 0, 255 };
static const float* histRange = { range };


class Histogram
{
private:

public:
    Histogram();                //default constructor

    cv::MatND getHistogramValues(const cv::Mat &image) const;

    cv::Mat   getHistogramImage(const cv::Mat &image) const;
};

#endif // HISTOGRAM_H
