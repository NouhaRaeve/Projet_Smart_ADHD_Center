#ifndef MAINWINDOW_LOGIN_H
#define MAINWINDOW_LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_Login; }
QT_END_NAMESPACE

class MainWindow_Login : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_Login(QWidget *parent = nullptr);
    ~MainWindow_Login();

private slots:

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow_Login *ui;
};
#endif // MAINWINDOW_LOGIN_H
