#include "checkforsearch_book_user.h"

int barresinationalcodeandpas(QString s1,QString s2)
{
    if(s2!="")
    {
        for(int i=0;i<s2.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                return 0;
            }
        }
    }
    return 1;
}
