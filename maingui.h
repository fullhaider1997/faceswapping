#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>
#include <qthread.h>
#include "videoprocessor.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainGUi; }
QT_END_NAMESPACE

class MainGUi : public QMainWindow
{
    Q_OBJECT

public:
    MainGUi(QWidget *parent = nullptr);
    ~MainGUi();

private:
    Ui::MainGUi *ui;
    QThread * videoThread;
    VideoProcessor * videoProcessor;
};
#endif // MAINGUI_H
