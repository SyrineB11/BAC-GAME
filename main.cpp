#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainwindow w;
    w.showNormal();
    return a.exec();
}
