#include "karbar.h"

karbar::karbar()
{
    national_code="";
    phone="";
    password="";
    mojodi_in_library=0;
}

karbar::karbar(QString _name, QString _family, QString _national_code,QString _email, QString _phone, QString _password,
               date _birth_date, date _entery_date, address _home_add,int _mojodi):human(_name,_family,_birth_date)
{
    national_code=_national_code;
    phone=_phone;
    password=_password;
    entery_date=_entery_date;
    home_add=_home_add;
    this->Email=_email;
    this->mojodi_in_library=_mojodi;
}

karbar::karbar(const karbar & x)
{
    national_code=x.national_code;
    phone=x.phone;
    password=x.password;
    entery_date=x.entery_date;
    home_add=x.home_add;
    this->Email=x.Email;
    this->family=x.family;
    this->name=x.name;
    this->birth_date=x.birth_date;
    this->mojodi_in_library=x.mojodi_in_library;
}

date karbar::getEnter()
{
    return entery_date;
}

void karbar::setEntery(date s)
{
    this->entery_date=s;
}

QString karbar::getPhone()
{
    return phone;
}

void karbar::setPhone(QString s)
{
    phone=s;
}

QString karbar::getNational_code()
{
    return  national_code;
}

void karbar::setNational_code(QString s)
{
    national_code=s;
}

address karbar::getAddress()
{
    return  this->home_add;
}

void karbar::setAddress(address s)
{
    home_add=s;
}

void karbar::setPassword(QString s)
{
    this->password=s;
}

QString karbar::getPassword()
{
    return password;
}

void karbar::setEmail(QString s)
{
    Email=s;
}

QString karbar::getEmail()
{
    return  Email;
}

int karbar::getMojodi()
{
    return this->mojodi_in_library;
}

void karbar::setMojodi(int s)
{
    this->mojodi_in_library=s;
}
