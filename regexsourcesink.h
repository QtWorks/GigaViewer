#ifndef REGEXSOURCESINK_H
#define REGEXSOURCESINK_H

#include "imagesourcesink.h"
#include <QtGui>

class RegexSourceSink : public ImageSourceSink
{
public:
    bool Init();
    bool StartAcquisition(QString dev="0");
    bool StopAcquisition();
    bool ReleaseCamera();
    bool GrabFrame(ImagePacket& target,int indexIncrement=1);
    bool RecordFrame(ImagePacket& source);
    bool StartRecording(QString recFold, QString codec, int fps, int cols, int rows);
    bool StopRecording();
    bool IsOpened();
    bool SkipFrames(bool forward);

private:

    QStringList *goodFiles;
    QString dir;
    QString basename;
    QString extension;
    int index;
    int nFrames;

    QVector<double> timestamps;
    double startTime;

};

#endif // REGEXSOURCESINK_H
