#ifndef USERSOPTIONFORMANGER_H
#define USERSOPTIONFORMANGER_H

#include <QDialog>
#include<QCheckBox>
#include"karbar_node.h"

namespace Ui {
class usersoptionformanger;
}

class usersoptionformanger : public QDialog
{
    Q_OBJECT
public:
    explicit usersoptionformanger(QWidget *parent = nullptr);
    ~usersoptionformanger();
    Ui::usersoptionformanger* getUi();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::usersoptionformanger *ui;
    QCheckBox** checkBox1;
    QCheckBox** checkBox2;
    QCheckBox** checkBox3;
    int *checkCheckBox;
    int *checkRemove;
public slots:
    void checkEdit(int);
    void searchExplor(QString);
    void showcomb(int);
};

#endif // USERSOPTIONFORMANGER_H
