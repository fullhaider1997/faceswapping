#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include <QObject>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"

class VideoProcessor:  public QObject
{
public:
    VideoProcessor();
    ~VideoProcessor();
public slots:
    void displayVideo();
    void loopButtons();
    void receivedBlink(bool answer);

signals:
    void videoProcessorBlinked(bool answer);
    void display(QPixmap pixmap);
    void finished();
    void error(QString);



};

#endif // VIDEOPROCESSOR_H
