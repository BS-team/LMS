#include "date.h"
#include<math.h>

date::date()
{
    day=month=year=0;
}

date::date(int z, int y, int x)
{
    this->day=z;
    this->month=y;
    this->year=x;
}

date::date(const date & x)
{
    this->day=x.day;
    this->month=x.month;
    this->year=x.year;
}

int date::getDay()
{
    return this->day;
}

void date::setDay(int x)
{
    day=x;
}

int date::getMonth()
{
    return month;
}

void date::setMonth(int x)
{
    month=x;
}

int date::getYear()
{
    return  year;
}

void date::setYear(int x)
{
    year=x;
}

int date::operator-(date x)
{
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long int n1 = this->year*365 + this->day;

    for (int i=0; i<this->month - 1; i++)
        n1 += monthDays[i];

    int years = this->year;
    if (this->month <= 2)
        years--;
    n1+= (years / 4) - (years / 100) + (years / 400);



    long int n2 = x.year*365 + x.day;
    for (int i=0; i<x.month - 1; i++)
        n2 += monthDays[i];
    n2 += count_dor_of_Years(x);


    return abs(n2 - n1);
}

int date::count_dor_of_Years(date d)
{
    int years = d.getYear();
        if (d.getMonth() <= 2)
              years--;
          return (years / 4) - (years / 100) + (years / 400);
}

int date::operator>(date x)
{
    if (this->year > x.year || this->year == x.year & this->month > x.month || this->year == x.year & this->month == x.month & this->day > x.day)
        return 1;
    else
        return 0;
}

int date::operator<(date x)
{
    if (this->year < x.year || this->year == x.year & this->month < x.month || this->year == x.year & this->month == x.month & this->day < x.day)
        return 1;
    else
        return 0;
}

int date::operator==(date x)
{
    if(this->day==x.getDay() && this->month==x.getMonth() && this->year==x.getYear())
        return 1;
    else
        return 0;
}
