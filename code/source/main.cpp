#include "mainwindow.h"
#include "openglwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *window = new MainWindow;
    window->setFixedSize(1000, 600);
    window->show();

    return a.exec();
}
