#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(!QDir("./Dicts").exists()){
        QDir().mkdir("./Dicts");
    };
    w.show();

    return a.exec();
}
