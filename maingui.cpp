#include "maingui.h"
#include "ui_maingui.h"

MainGUi::MainGUi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGUi),
      videoProcessor(new VideoProcessor),
      videoThread(new QThread)
{
    ui->setupUi(this);



     videoProcessor->moveToThread(videoThread);

    connect( videoProcessor,SIGNAL(videoProcessorBlinked(bool)),this,SLOT(userIsBlinking(bool)));

    connect(videoThread, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(videoThread, SIGNAL(started()), videoProcessor, SLOT(displayVideo()));
    connect( videoThread, SIGNAL(finished()), videoThread, SLOT(deleteLater()));
    connect(videoProcessor, SIGNAL(finished()),  videoProcessor, SLOT(quit()));
    connect(videoProcessor, SIGNAL(finished()), videoProcessor, SLOT(deleteLater()));
    connect(videoProcessor,SIGNAL(display(QPixmap)),ui->original,SLOT(setPixmap(QPixmap)));

    connect( videoThread, SIGNAL(started()), videoProcessor, SLOT(displayVideo()));


    videoThread->start();


}

MainGUi::~MainGUi()
{
    delete ui;
}

