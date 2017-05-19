#ifndef ELLIPSEDETECTION_H
#define ELLIPSEDETECTION_H

#include <opencv2/opencv.hpp>
#include <QtCore>
#include "imagepacket.h"

class EllipseDetection
{
private:
    int threshold;
    int targetX;
    int targetY;
    int targetAspectRatio;
    //double CenterLine;
    //double VerticalLine;
    bool UseAspectRatio;
    //bool UseContourLimits;
    bool UseBlackWhite;
    bool UseCenterLine;
    bool UseVertical;
    bool UseDiamateterIntervalle;

    bool activated;
    bool shouldTrack;
    QStringList dataToSave;
public:
    EllipseDetection(int thresh);
    void ChangeSettings(QMap<QString,QVariant> settings);
    bool processImage(ImagePacket& currIm);

};

cv::Point GetSamplePositions(cv::RotatedRect Ellipse,int i,int NbreEchantillon);
double ExtractValues(cv::Mat I,cv::Point Pixel);

#endif // ELLIPSEDETECTION_H
