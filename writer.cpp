#include "writer.h"

writer::writer():human()
{
    this->nationality="";
}

writer::writer(QString _name,QString _family, date _birth_date,QString ns):human(_name,_family,_birth_date)
{
    this->nationality=ns;
}

QString writer::getNationality()
{
    return this->nationality;
}

void writer::setNationality(QString sn)
{
    nationality=sn;
}

