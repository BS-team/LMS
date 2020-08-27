
#include"functionToExplorebooks.h"
#include<QFile>
#include<QTextStream>

book_node* checkBookInformation()
{
    book_linkedlist* bklnklst=new book_linkedlist();
    book krb;
    QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/booksInformations.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    QString s,s1,s3,s4,s5;
    char z;
    int n,n1=0;
    date da;

    while(true)
    {
        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;


            stream>>z;
            if(z=='\t')
            {
                krb.setName(s);
                s3=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;


        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                krb.setSubject(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                krb.setEntesharat(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                krb.setCode(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        stream>>s5;
        krb.setIdEhdaconande(s5);

        stream>>n;
        krb.setNumber(n);

        writer wrt;

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                wrt.setName(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                wrt.setFamily(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                wrt.setNationality(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        krb.setAuthor(wrt);

        human trnltr;
        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                trnltr.setName(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                trnltr.setFamily(s);
                s4=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        if(s1=="")
            break;

        krb.setTranslator(trnltr);


        stream>>n;
        da.setDay(n);
        stream>>n;
        da.setMonth(n);
        stream>>n;
        da.setYear(n);
        krb.setEhda(da);

        if(krb.getCode()!="")
            bklnklst->pushback(krb);

        stream>>z;
        if(z!='\r' && z!='\n')
            stream>>z;

        s="\0";

        if(z!='\r' && z!='\n' )
            s[0]=z;
    }
    file.close();

    return bklnklst->getHead();
}
