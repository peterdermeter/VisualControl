#ifndef IMAGEFUNCTIONS_H
#define IMAGEFUNCTIONS_H

#define _USE_MATH_DEFINES
#include "histogram.h"
#include <QThread>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <cmath>
#include <limits>


class imageFunctions : public QThread
{
    Q_OBJECT

private:
    double max, min;
    Histogram h;
    cv::MatND hist;
    cv::Point minIndex, maxIndex;
    cv::Mat elementOpen;
    cv::Mat elementClose;

public:
    explicit imageFunctions(QObject *parent = 0);

    ~imageFunctions();

    void    getROI(const cv::Mat &src);

    void    getMassCenters(const cv::Mat &src, std::vector<cv::Point2f> &mc) const;

    void    drawMassCenters(cv::Mat &src, const std::vector<cv::Point2f> &mc) const;

    void    getAngles(const cv::Mat &src, const cv::Point2f &MassCenter, cv::Vec3d &AngleData) const;

    void    getMotorData(const cv::Vec3d &AngleData, const cv::Vec2d &AngleDataBefore, cv::Vec2d &AngleDataAfter, cv::Vec2i &MotorData) const;
};


double  round(double x);



#endif // IMAGEFUNCTIONS_H

