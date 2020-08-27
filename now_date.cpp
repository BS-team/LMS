#include "now_date.h"

#include"date.h"
#include<time.h>

date date_now()
{
    time_t now;
    time(&now);
    struct tm* local=localtime(&now);
    date today_date;
    today_date.setDay(local->tm_mday);
    today_date.setMonth(local->tm_mon+1);
    today_date.setYear(local->tm_year+1900);

    return today_date;

}

