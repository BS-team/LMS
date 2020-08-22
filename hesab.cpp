#include "hesab.h"

hesab::hesab()
{
  number_of_creditcard="";
  cvv2="";
  second_password="";
  name_of_owner="";
}

hesab::hesab(QString _number_of_creditcard,QString _cvv2,date _expiration,QString _second_password,QString _owner)
{
    number_of_creditcard=_number_of_creditcard;
    cvv2 = _cvv2;
    expiration = _expiration;
    second_password = _second_password;
    this->name_of_owner=_owner;
}


hesab::hesab(const hesab & x)
{
    number_of_creditcard = x.number_of_creditcard;
    cvv2 = x.cvv2;
    expiration = x.expiration;
    second_password = x.second_password;
    this->mojodi_hesab=x.mojodi_hesab;
    name_of_owner=x.name_of_owner;
}

QString hesab::getNumber_of_creditcard()
{
    return this->number_of_creditcard;
}
void hesab::setNumber_of_creditcard(QString s)
{
    this->number_of_creditcard = s;
}

QString hesab::getCvv2()
{
    return this->cvv2;
}

void hesab::setCvv2(QString s)
{
    this->cvv2 = s;
}

date hesab::getExpiration()
{
    return this->expiration;
}

void hesab::setExpiration(date s)
{
    this->expiration = s;
}

QString hesab::getSecond_password()
{
    return this->second_password;
}
void hesab::setSecond_password(QString s)
{
    this->second_password = s;
}

QString hesab::getNameOfOwner()
{
    return name_of_owner;
}

void hesab::setNameOfOwner(QString s)
{
    this->name_of_owner=s;
}

QString hesab::getMojodiHesab()
{
    return this->mojodi_hesab;
}

void hesab::setMojodiHesab(QString s)
{
    this->mojodi_hesab=s;
}
