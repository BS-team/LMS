#include "manager.h"

manger::manger():human()
{
    usual_password="";
    special_password= "";
}

manger::manger(QString s1, QString s2 , QString s3 , QString s4,QString s5,QString s6, date x):human(s1,s2,x)
{
    usual_password=s3;
    special_password=s4;
    phone=s5;
    national_code=s6;
}

void manger::setSpecial_password(QString s)
{
    special_password=s;
}

QString manger::getSpetial_password()
{
    return special_password;
}

void manger::setUsual_password(QString s)
{
    usual_password=s;
}

QString manger::getUsual_password()
{
    return usual_password;
}

void manger::setNationlCode(QString s)
{
    national_code=s;
}

QString manger::getNationlCode()
{
    return this->national_code;
}

void manger::setPhone(QString _phone)
{
    phone=_phone;
}

QString manger::getPhone()
{
    return phone;
}
