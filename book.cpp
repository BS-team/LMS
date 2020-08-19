#include "book.h"

book::book()
{
    code="";
    name="";
    entesharat="";
    subject="";
    number=0;
}

book::book(QString _code,QString _name,writer _author,human _translator,QString _nasher,QString _subject,date _ehda_book,int n,QString _id)
{
    this->code=_code;
    this->name=_name;
    this->author=_author;
    this->translator=_translator;
    this->entesharat=_nasher;
    this->subject=_subject;
    this->ehda_book=_ehda_book;
    this->number=n;
    id_ehadconande=_id;
}

book::book(const book & x)
{
    this->code=x.code;
    this->name=x.name;
    this->author=x.author;
    this->translator=x.translator;
    this->entesharat=x.entesharat;
    this->subject=x.subject;
    this->ehda_book=x.ehda_book;
    number=x.number;
    id_ehadconande=x.id_ehadconande;
}

QString book::getCode()
{
    return this->code;
}

void book::setCode(QString cd)
{
    code=cd;
}

QString book::getName()
{
    return this->name;
}

void book::setName(QString nm)
{
    name=nm;
}

QString book::getIdEhdaconande()
{
    return  id_ehadconande;
}

void book::setIdEhdaconande(QString nm)
{
    this->id_ehadconande=nm;
}


writer book::getAuthor()
{
    return this->author;
}
void book::setAuthor(writer auth)
{
    author=auth;
}


human book::getTranslator()
{
    return this->translator;
}
void book::setTranslator(human trans)
{
    translator=trans;
}

QString book::getEntesharatr()
{
    return this->entesharat;
}

void book::setEntesharat(QString nsh)
{
    entesharat=nsh;
}

QString book::getSubject()
{
    return this->subject;
}

void book::setSubject(QString sbj)
{
    subject=sbj;
}

void book::setEhda(date s)
{
    this->ehda_book=s;
}

date book::getEhda()
{
    return  this->ehda_book;
}

int book::getNumber()
{
    return number;
}

void book::setNumber(int x)
{
    number=x;
}
