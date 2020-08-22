#ifndef BOOK_GHARZ_PASS_H
#define BOOK_GHARZ_PASS_H

#include"book.h"

class book_gharz_pass
{
    date sefaresh;
    date pass;
    date gharz;
    date last_time_of_jarime;
    QString national_gharzgirande;
    QString code_of_book;
public:
    book_gharz_pass();
    book_gharz_pass(QString,date,date,date);

    date getGharz();
    void setGhaz(date);

    date getSefaresh();
    void setSefaresh(date);

    date getPass();
    void setPass(date);

    date getTimeOfjarime();
    void setTimeOfjarime(date);

    QString getNational_gharzgirande();
    void setNational_gharzgirande(QString);

    QString getCode_of_book();
    void setCode_of_book(QString);



};

#endif // BOOK_GHARZ_PASS_H
