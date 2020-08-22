#ifndef HESAB_H
#define HESAB_H

#include <QString>
#include <date.h>


class hesab
{
    QString number_of_creditcard;
    QString cvv2;
    QString second_password;
    date expiration;
    QString mojodi_hesab;
    QString name_of_owner;
public:
    hesab();
    hesab(QString _number_of_creditcard,QString _cvv2,date _expiration,QString _second_password,QString);
    hesab(const hesab &);

    QString getNumber_of_creditcard();
    void setNumber_of_creditcard(QString s);

    QString getCvv2();
    void setCvv2(QString s);

    date getExpiration();
    void setExpiration(date s);

    QString getSecond_password();
    void setSecond_password(QString s);

    QString getNameOfOwner();
    void setNameOfOwner(QString s);


    QString getMojodiHesab();
    void setMojodiHesab(QString s);
};

#endif // HESAB_H
