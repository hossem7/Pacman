#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"

Dialog *d;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    d = new Dialog();
    w.show();

    return a.exec();
}
