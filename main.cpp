#include "mainwindow_login.h"
#include "connexion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnect();
    a.setWindowIcon(QIcon(":/new/images/src/brainwave.png"));
    MainWindow_Login w;
    if(test)
     w.show();
     return a.exec();



}
