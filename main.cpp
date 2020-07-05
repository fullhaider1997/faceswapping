#include "maingui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGUi w;
    w.show();
    return a.exec();
}
