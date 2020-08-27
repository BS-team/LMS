#include "checkjarime.h"
#include"functioforgharzandpassofbook.h"
#include"functionToExplorUser.h"
#include"book_gharz_pass_node.h"
#include"now_date.h"
#include"karbar_node.h"
#include<QFile>
#include<QTextStream>

void setJarime()
{
    int k=0;
    book_gharz_pass_node* tmp=checkBookgharzandpass();
    QFile ("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt").remove();
    for(;tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getGharz().getDay()!=0 && tmp->getData().getPass().getDay()==0)
        {
            if(date_now()-tmp->getData().getGharz()>14)
            {
                if(date_now()-tmp->getData().getTimeOfjarime()>0)
                {
                    k=1;
                    int _day_for_jarime;
                    if(tmp->getData().getTimeOfjarime().getDay()==0)
                    {
                        _day_for_jarime=date_now()-tmp->getData().getGharz()-14;
                    }
                    else
                    {
                        _day_for_jarime=date_now()-tmp->getData().getTimeOfjarime();
                    }

                    QFile fi("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
                    fi.open(QIODevice::Append);
                    QTextStream stream2(&fi);
                    stream2.setCodec("UTF-8");

                    stream2<<tmp->getData().getNational_gharzgirande()<<"\t";
                    stream2<<tmp->getData().getCode_of_book()<<"\t";
                    stream2<<tmp->getData().getSefaresh().getDay()<<"\t";
                    stream2<<tmp->getData().getSefaresh().getMonth()<<"\t";
                    stream2<<tmp->getData().getSefaresh().getYear()<<"\t";
                    stream2<<tmp->getData().getGharz().getDay()<<"\t";
                    stream2<<tmp->getData().getGharz().getMonth()<<"\t";
                    stream2<<tmp->getData().getGharz().getYear()<<"\t";
                    stream2<<tmp->getData().getPass().getDay()<<"\t";
                    stream2<<tmp->getData().getPass().getMonth()<<"\t";
                    stream2<<tmp->getData().getPass().getYear()<<"\t";
                    stream2<<date_now().getDay()<<"\t";
                    stream2<<date_now().getMonth()<<"\t";
                    stream2<<date_now().getYear()<<"\n";
                    fi.close();

                    karbar_node* tmp1=checkUserInformation();
                    karbar_node* tmp6=tmp1;


                    QFile ("C:/Users/albaloo/Documents/ProjectOfTerm2/karbarInformation.txt").remove();
                    for(;tmp1!=nullptr;tmp1=tmp1->getNext())
                    {
                        if(tmp1->getData().getNational_code()==tmp->getData().getNational_gharzgirande())
                        {
                            karbar krb;
                            krb.setEmail(tmp1->getData().getEmail());
                            krb.setName(tmp1->getData().getName());
                            krb.setFamily(tmp1->getData().getFamily());
                            krb.setPassword(tmp1->getData().getPassword());
                            krb.setNational_code(tmp1->getData().getNational_code());
                            krb.setBirth(tmp1->getData().getBirth());
                            krb.setEntery(tmp1->getData().getEnter());
                            krb.setAddress(tmp1->getData().getAddress());
                            krb.setPhone(tmp1->getData().getPhone());
                            if(_day_for_jarime*100>tmp1->getData().getMojodi())
                                krb.setMojodi(0);
                            else
                            {
                                krb.setMojodi(tmp1->getData().getMojodi()-_day_for_jarime*100);
                            }
                            tmp1->setData(krb);
                            QFile file("C:/Users/albaloo/Documents/ProjectOfTerm2/karbarInformation.txt");
                            file.open(QIODevice::Append);
                            QTextStream stream(&file);
                            stream.setCodec("UTF-8");
                            for(;tmp6!=nullptr;tmp6=tmp6->getNext())
                            {
                                stream
                                    <<tmp6->getData().getName() << "\t"
                                    <<tmp6->getData().getFamily() << "\t"
                                    <<tmp6->getData().getNational_code() << "\t"
                                    <<tmp6->getData().getPassword()<<"\t"
                                    <<tmp6->getData().getPhone() << "\t"
                                    <<tmp6->getData().getEmail()<<"\t"
                                    <<tmp6->getData().getBirth().getDay()<<"\t"
                                    <<tmp6->getData().getBirth().getMonth()<<"\t"
                                    <<tmp6->getData().getBirth().getYear()<<"\t"
                                    <<tmp6->getData().getEnter().getDay()<<"\t"
                                    <<tmp6->getData().getEnter().getMonth()<<"\t"
                                    <<tmp6->getData().getEnter().getYear()<<"\t"
                                    <<tmp6->getData().getAddress().getCity() << "\t"
                                    <<tmp6->getData().getAddress().getStreet() << "\t"
                                    <<tmp6->getData().getAddress().getAlley()<< "\t"
                                    <<tmp6->getData().getAddress().getPostcode()<<"\t"
                                    <<tmp6->getData().getMojodi()<<"\n";
                                 }
                            file.close();
                        }
                    }
                }
            }
        }

        if(k==0)
        {
            QFile fil("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
            fil.open(QIODevice::Append);
            QTextStream stream1(&fil);
            stream1.setCodec("UTF-8");

            stream1<<tmp->getData().getNational_gharzgirande()<<"\t";
            stream1<<tmp->getData().getCode_of_book()<<"\t";
            stream1<<tmp->getData().getSefaresh().getDay()<<"\t";
            stream1<<tmp->getData().getSefaresh().getMonth()<<"\t";
            stream1<<tmp->getData().getSefaresh().getYear()<<"\t";
            stream1<<tmp->getData().getGharz().getDay()<<"\t";
            stream1<<tmp->getData().getGharz().getMonth()<<"\t";
            stream1<<tmp->getData().getGharz().getYear()<<"\t";
            stream1<<tmp->getData().getPass().getDay()<<"\t";
            stream1<<tmp->getData().getPass().getMonth()<<"\t";
            stream1<<tmp->getData().getPass().getYear()<<"\t";
            stream1<<tmp->getData().getTimeOfjarime().getDay()<<"\t";
            stream1<<tmp->getData().getTimeOfjarime().getMonth()<<"\t";
            stream1<<tmp->getData().getTimeOfjarime().getYear()<<"\n";
            fil.close();
        }
        k=0;
    }
}

