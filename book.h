#ifndef BOOK_H
#define BOOK_H


#include <QString>
#include "writer.h"

class book
{
private:
    int number;
    date ehda_book;
    QString id_ehadconande;
    QString code;
    QString name;
    writer author;
    human translator;
    QString entesharat;
    QString subject;
public:
    book();
    book(QString _code,QString _name,writer _author,human _translator,QString _nasher,QString subject,date _ehda_book,int n,QString _id);
    book(const book&);

    QString getCode();
    void setCode(QString cd);

    QString getName();
    void setName(QString nm);

    QString getIdEhdaconande();
    void setIdEhdaconande(QString nm);

    writer getAuthor();
    void setAuthor(writer auth);

    human getTranslator();
    void setTranslator(human trans);

    QString getEntesharatr();
    void setEntesharat(QString nsh);

    QString getSubject();
    void setSubject(QString sbj);

    void setEhda(date s);
    date getEhda();

    int getNumber();
    void setNumber(int );

};

#endif // BOOK_H
