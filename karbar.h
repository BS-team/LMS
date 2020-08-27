#ifndef KARBAR_H
#define KARBAR_H


#include"human.h"
#include"address.h"
#include"book_linkedlist.h"

class karbar:public human
{
    QString national_code;
    QString password;
    QString phone;
    address home_add;
    date entery_date;
    QString Email;
    int mojodi_in_library;
public:
    karbar();
    karbar(QString _name,QString _family,QString _national_code,QString _Email,QString _phone,QString _password,date _birth_date,
           date _entery_date,address _home_add,int _mojodi);
    karbar(const karbar&);



    QString getPhone();
    void setPhone(QString s);

    date getEnter();
    void setEntery(date);

    QString getNational_code();
    void setNational_code(QString s);

    address getAddress();
    void setAddress(address s);

    void setPassword(QString s);
    QString getPassword();

    void setEmail(QString s);
    QString getEmail();

    int getMojodi();
    void setMojodi(int s);


};

#endif // KARBAR_H
