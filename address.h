#ifndef ADDRESS_H
#define ADDRESS_H
#include<QString>

class address
{
    QString city;
    QString street;
    QString alley;
    QString postcode;
public:
    address();
    address(QString,QString,QString,QString);
    address(const address &);

    QString getCity();
    void setCity(QString s);

    QString getStreet();
    void setStreet(QString s);

    QString getAlley();
    void setAlley(QString s);

    QString getPostcode();
    void setPostcode(QString s);

};

#endif // ADDRESS_H
