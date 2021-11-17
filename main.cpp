#include "mainwindow.h"
#include "misc.h"
#include <iostream>
#include <QDebug>
#include <QApplication>






int main(int argc, char *argv[])
{
    QApplication MyApp(argc, argv);
    MainWindow w;
    w.show();

    return MyApp.exec();
}
