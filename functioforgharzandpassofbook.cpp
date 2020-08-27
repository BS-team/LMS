#include<QFile>
#include<QTextStream>
#include"functioforgharzandpassofbook.h"
book_gharz_pass_node* checkBookgharzandpass()
{
    // id code gharz pass

    book_gharz_pass krb;
    book_gharz_pass_linkedList* krblist;
    krblist=new book_gharz_pass_linkedList();
    QFile file("E:/LastOne/ProjectOfTerm2/gharzandpassbook.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    QString s,s1,s3="\0",s4;
    char z='\0';
    int n,n1=0;

    date da1,da2,da3,da4;

    while(true)
    {
        stream>>s;
        s3+=s;
        krb.setNational_gharzgirande(s3);
        stream>>s;
        krb.setCode_of_book(s);
        s="\0";
        s3="\0";

        stream>>n;
        da3.setDay(n);
        stream>>n;
        da3.setMonth(n);
        stream>>n;
        da3.setYear(n);
        krb.setSefaresh(da3);

        stream>>n;
        da1.setDay(n);
        stream>>n;
        da1.setMonth(n);
        stream>>n;
        da1.setYear(n);
        krb.setGhaz(da1);

        stream>>n;
        da2.setDay(n);
        stream>>n;
        da2.setMonth(n);
        stream>>n;
        da2.setYear(n);
        krb.setPass(da2);

        stream>>n;
        da4.setDay(n);
        stream>>n;
        da4.setMonth(n);
        stream>>n;
        da4.setYear(n);
        krb.setTimeOfjarime(da4);

        krblist->pushback(krb);

        stream>>z;    //\n
        stream>>z;     //EOF

        if(z=='\0')
            break;
        s="\0";
        s3[0]=z;
    }
    file.close();
    return krblist->getHead();
}
