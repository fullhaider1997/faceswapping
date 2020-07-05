#include "videoprocessor.h"

VideoProcessor::VideoProcessor()
{

}
VideoProcessor::~VideoProcessor(){

}

void VideoProcessor::receivedBlink(bool answer){

    qDebug() << "Video processor recieved the blinking signals...:"  << answer;

}

void VideoProcessor::loopButtons(){

    qDebug() << "Hello world";

}

void VideoProcessor::displayVideo(){


    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(2);
    cv::Mat faceFrame;
    cv::Mat orig;
    cv::Mat processsed;


    while(camera.isOpened())
    {

        camera >> faceFrame;


        cv::flip(faceFrame,faceFrame,+1);



        emit display(QPixmap::fromImage(
                 QImage(processsed.data,
                        processsed.cols,
                        processsed.rows,
                        processsed.step,
                 QImage::Format_RGB888).rgbSwapped()));
         }






 emit finished();
}



