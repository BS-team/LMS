#include"functionToExplorUser.h"
#include<QFile>
#include<QTextStream>


karbar_node* checkUserInformation()
{
    karbar krb;
    karbar_linkedlist* krblist;
    krblist=new karbar_linkedlist();

    QFile file("E:/LastOne/ProjectOfTerm2/karbarInformation.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    QString s,s1,s3,s4;
    char z;
    int n;
    address ad1;
    date da1,da2;

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
                krb.setFamily(s);
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

        stream>>s;
        krb.setNational_code(s);
        stream>>s;
        krb.setPassword(s);
        stream>>s;
        krb.setPhone(s);
        stream>>s;
        krb.setEmail(s);
        s="\0";

        stream>>n;
        da1.setDay(n);                            //krb.getBirth().setDay(n);
        stream>>n;
        da1.setMonth(n);                          //krb.getBirth().setMonth(n);
        stream>>n;
        da1.setYear(n);                           //krb.getBirth().setYear(n);
        krb.setBirth(da1);

        stream>>n;
        da1.setDay(n);                            //krb.getBirth().setDay(n);
        stream>>n;
        da1.setMonth(n);                          //krb.getBirth().setMonth(n);
        stream>>n;
        da1.setYear(n);                           //krb.getBirth().setYear(n);
        krb.setEntery(da1);

        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                ad1.setCity(s);                            // krb.getAddress().setCity(s);
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
                ad1.setStreet(s);                   //krb.getAddress().setStreet(s);
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }
        while(1)
        {
            stream>>s1;
            if(s1=="")
                break;
            s+=s1;
            stream>>z;
            if(z=='\t')
            {
                ad1.setAlley(s);                                //krb.getAddress().setAlley(s);
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }

        stream>>s;
        ad1.setPostcode(s);                 //krb.getAddress().setPostcode(s);
        krb.setAddress(ad1);

        stream>>s;
        krb.setMojodi(s.toUInt());

        if(krb.getNational_code()!="")
            krblist->pushback(krb);

        stream>>z;
        if(z!='\r' && z!='\n')
            stream>>z;

        s="\0";

        if(z!='\r' && z!='\n' )
            s[0]=z;
    }
    file.close();
    return krblist->getHead();
}
