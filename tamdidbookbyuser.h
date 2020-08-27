#ifndef TAMDIDBOOKBYUSER_H
#define TAMDIDBOOKBYUSER_H

#include <QDialog>

namespace Ui {
class TamdidBookByUser;
}
#include<QCheckBox>
class TamdidBookByUser : public QDialog
{
    Q_OBJECT

public:
    explicit TamdidBookByUser(QString _id,QWidget *parent = nullptr);
    ~TamdidBookByUser();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TamdidBookByUser *ui;
    QString id_loginer;
    QCheckBox** checktamdid;
};

#endif // TAMDIDBOOKBYUSER_H
