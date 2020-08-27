#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include"login_by_manager.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_karbar_clicked();

    void on_pushButton_2_manager_clicked();

    void on_pushButton_3_about_clicked();

    void on_pushButton_4_exit_clicked();
    void checkLogin(QString,QString,QString,login_by_manager*);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
