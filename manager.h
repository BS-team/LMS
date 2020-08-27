#ifndef MANAGER_H
#define MANAGER_H


#include"human.h"

class manger:public human
{
    QString special_password;
    QString usual_password;
    QString phone;
    QString national_code;
public:
    manger();
    manger(QString s1, QString s2, QString s3, QString s4,QString s5,QString s6 ,date x);

    void setSpecial_password(QString s);
    QString getSpetial_password();

    void setUsual_password(QString s);
    QString getUsual_password();

    void setNationlCode(QString s);
    QString getNationlCode();

    void setPhone(QString _phone);
    QString getPhone();
};


#endif // MANAGER_H
