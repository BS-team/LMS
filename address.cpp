#include "address.h"
#include<string.h>
address::address()
{
    city=" ";
    alley=" ";
    street=" ";
    postcode=" ";
}

address::address(QString s1, QString s2, QString s3, QString s4)
{
    city=s1;
    alley=s3;
    street=s2;
    postcode=s4;
}

address::address(const address & x)
{
    this->city=x.city;
    this->street=x.street;
    this->alley=x.alley;
    this->postcode=x.postcode;
}

QString address::getCity()
{
    return city;
}

void address::setCity(QString s)
{
    city=s;
}

QString address::getStreet()
{
    return street;
}

void address::setStreet(QString s)
{
    street=s;
}

QString address::getAlley()
{
    return alley;
}

void address::setAlley(QString s)
{
    alley=s;
}

QString address::getPostcode()
{
    return postcode;
}

void address::setPostcode(QString s)
{
    postcode=s;
}
