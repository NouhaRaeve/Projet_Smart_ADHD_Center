#include "mainwindow_login.h"
#include "ui_mainwindow_login.h"
#include "dialog.h"

MainWindow_Login::MainWindow_Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_Login)
{
    ui->setupUi(this);
     setFixedSize(1130,750);  //fixe la taille de la fenêtre

     setWindowFlags(Qt::CustomizeWindowHint); //supprime les paramétrages de fenêtre par défaut. Oblige donc de préciser les réglagess autorisés

     setWindowFlags(Qt::WindowTitleHint); //Autorise le titre de la fenêtre

     setWindowFlags(Qt::WindowSystemMenuHint);//autorise le bouton de fermeture dans le bandeau de fenêtre

     setWindowFlags(Qt::WindowMinimizeButtonHint);//autorise le bouton de réduction de fenêtre


}

MainWindow_Login::~MainWindow_Login()
{
    delete ui;
}

void MainWindow_Login::on_pushButton_login_clicked()
{
    Dialog d;
    d.exec();
}
