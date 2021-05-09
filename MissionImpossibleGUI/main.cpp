#include "mainwindow.h"
#include "wstep.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wstep w;
    w.show();

    return a.exec();
}
