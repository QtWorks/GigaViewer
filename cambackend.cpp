#include "cambackend.h"
#include <QDebug>

CamBackend::CamBackend(QObject *parent) :
    QThread(parent),timerInterval(20)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(GrabFrame()), Qt::DirectConnection);
}

bool CamBackend::IsLive() {
    if (liveMode) {
        if (camera.isOpened()) {
            return TRUE;
        }
    }
    return FALSE;
}

void CamBackend::run()
{
    if (camera.isOpened()) {
        timer.setInterval(timerInterval);
        timer.start();
        exec(); //will go beyond this point when quit() is send from within this thread
        timer.stop();
    } else {
        qDebug()<<"Could not open camera";
    }
}

void CamBackend::GrabFrame()
{
    if (!camera.isOpened()) quit();
    if (liveMode) {
        camera >> currImage.image;
        emit NewImageReady(currImage);
    }
}

bool CamBackend::StartAcquisition()
{
//    camera = new cv::VideoCapture("/home/sam/ULB/Movies/VapourCloudDynamics.mp4");
    camera.open(0);
    if (camera.isOpened()) {
        liveMode=TRUE;
        return TRUE;
    } else {
        liveMode=FALSE;
        return FALSE;
    }
    return FALSE;
}

void CamBackend::StopAcquisition()
{
    quit();
    liveMode=FALSE;
}

void CamBackend::ReleaseCamera()
{
    camera.release();
}

bool CamBackend::Init()
{
    //No real need to init opencv separately
    return TRUE;
}
