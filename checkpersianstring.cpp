#include "checkpersianstring.h"

int checkPersianStrings(QString s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i].isDigit() || s[i].isLower() || s[i].isUpper()|| s[i]=='*'|| s[i]=='&'
                || s[i]=='('|| s[i]==')'|| s[i]=='*'|| s[i]=='='|| s[i]=='+'||
                s[i]=='^'|| s[i]=='%'|| s[i]=='#'|| s[i]=='!'|| s[i]=='@'
                || s[i]=='_'|| s[i]=='}'|| s[i]=='{'|| s[i]==']'|| s[i]=='['|| s[i]=='>'|| s[i]=='<'|| s[i]=='/'||
                 s[i]=='?'|| s[i]=='.'|| s[i]==','|| s[i]=='"'|| s[i]==';'|| s[i]==':'|| s[i]=='|')
        {
            return 0;
        }
    }
    return 1;
}
