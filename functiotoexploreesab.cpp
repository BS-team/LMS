#include "functiotoexploreesab.h"
#include<QFile>
#include<QTextStream>

hesab_node* checkEtelatHesab()
{
    hesab krb;
    hesab_linkedlist* krblist;
    krblist=new hesab_linkedlist();
    QFile fil("C:/Users/erfan/Documents/ProjectOfTerm2/etelaateEsabBanki.txt");
    fil.open(QIODevice::ReadOnly);
    QTextStream stream(&fil);
    stream.setCodec("UTF-8");

    QString s,s1;
    char z;
    int n;

//shomarekart ramzedovom cvv2 tarikh  mojodi

    date da1;

    while(true)
    {
        stream>>s1;
        s+=s1;
        krb.setNumber_of_creditcard(s);
        s="\0";
        stream>>s;
        krb.setSecond_password(s);
        s="\0";
        stream>>s;
        krb.setCvv2(s);
        s="\0";

        s="\0",s1="\0";
        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                krb.setNameOfOwner(s);                   //krb.getAddress().setStreet(s);
                s="\0";
                break;
            }            
            s+=' ';
        }
        s="\0",s1="\0";

        stream>>n;
        da1.setMonth(n);
        stream>>n;
        da1.setYear(n);
        krb.setExpiration(da1);

        stream>>s;
        krb.setMojodiHesab(s);



        if(krb.getNumber_of_creditcard()!="")
            krblist->pushback(krb);


        stream>>z;
        if(z!='\r')
            stream>>z;

        if(z=='\0')
            break;
        s="\0";

        if(z!='\r' && z!='\n')
            s[0]=z;
    }
    fil.close();
    return krblist->getHead();
}
