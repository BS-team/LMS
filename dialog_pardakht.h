#ifndef DIALOG_PARDAKHT_H
#define DIALOG_PARDAKHT_H

#include <QDialog>
#include "ui_dialog_moshakhasats.h"

#include<QTimer>

namespace Ui {
class dialog_pardakht;
}

class dialog_pardakht : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_pardakht(int,QString,QString="",QString="",QString="",QString="",int=0,int=0,int=0,QString="",QString="",QString="",QString="",QWidget *parent = nullptr);
    ~dialog_pardakht();
     Ui::dialog_pardakht* getUi();

private:
    Ui::dialog_pardakht *ui;
    QTimer* _time;
    QString karbar_name;
    QString karbar_last_name;
    QString karbar_phone;
    QString karbar_national_code;
    QString karbar_email;
    QString karbar_add_city;
    QString karbar_add_street;
    QString karbar_add_alley;
    QString karbar_add_postCode;
    int karbar_birth_day;
    int karbar_birth_month;
    int karbar_birth_year;
    int manager_or_user;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

public slots:
    void writing_in_fil(QString);
    void checkProgressbr();

};

#endif // DIALOG_PARDAKHT_H
