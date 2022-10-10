#include "mainwindow.h"
#include "systrayiconwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SysTrayIconWidget w1;
    w1.show();
    return a.exec();
}
