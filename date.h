#ifndef DATE_H
#define DATE_H


class date
{
    int day;
    int month;
    int year;
public:
    date();
    date(int,int ,int);
    date(const date &);

    int getDay();
    void setDay(int x);

    int getMonth();
    void setMonth(int x);

    int getYear();
    void setYear(int x);

    int operator-(date x);

    int count_dor_of_Years(date d);


    int operator>(date x);
    int operator<(date x);
    int operator==(date x);


};

#endif // DATE_H
