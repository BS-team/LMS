#include "book_gharz_pass.h"

book_gharz_pass::book_gharz_pass()
{
    national_gharzgirande="";
}

book_gharz_pass::book_gharz_pass(QString s, date d1, date d2,date d3)
{
    national_gharzgirande=s;
    gharz=d1;
    pass=d2;
    last_time_of_jarime=d3;
}

date book_gharz_pass::getGharz()
{
    return gharz;
}

void book_gharz_pass::setGhaz(date s)
{
    gharz=s;
}

date book_gharz_pass::getSefaresh()
{
    return  this->sefaresh;
}

void book_gharz_pass::setSefaresh(date s)
{
    this->sefaresh=s;
}

date book_gharz_pass::getPass()
{
    return pass;
}

void book_gharz_pass::setPass(date s)
{
    pass=s;
}

date book_gharz_pass::getTimeOfjarime()
{
    return last_time_of_jarime;
}

void book_gharz_pass::setTimeOfjarime(date s)
{
    this->last_time_of_jarime=s;
}

QString book_gharz_pass::getNational_gharzgirande()
{
    return national_gharzgirande;
}

void book_gharz_pass::setNational_gharzgirande(QString s)
{
    this->national_gharzgirande=s;
}

QString book_gharz_pass::getCode_of_book()
{
    return  code_of_book;
}

void book_gharz_pass::setCode_of_book(QString s )
{
    code_of_book=s;
}
