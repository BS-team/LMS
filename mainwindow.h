#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"login_by_manager.h"
#include"login_page.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_karbar_clicked();

    void on_pushButton_4_clicked();

    void on_help_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
public slots:
    void checkLogin(QString,QString,QString,login_by_manager*);//,QString,QString);
};
#endif // MAINWINDOW_H
