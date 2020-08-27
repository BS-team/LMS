#include"now_date.h"
#include"checkifsefareshismorethat2daybookezafe.h"
#include<QFile>
#include<QTextStream>
void setBookNumberWithDateOfsabtByUser()
{
    book_gharz_pass_node* tmp1=checkBookgharzandpass();
    QFile("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt").remove();

    for(;tmp1!=nullptr;tmp1=tmp1->getNext())
    {
        if((tmp1->getData().getGharz().getDay()!=0 && date_now()-tmp1->getData().getSefaresh()>2) ||date_now()-tmp1->getData().getSefaresh()<=2)
        {
            QFile fil("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
            fil.open(QIODevice::Append);
            QTextStream stream1(&fil);
            stream1.setCodec("UTF-8");

            if(tmp1->getData().getSefaresh().getDay()!=0)
            {
                stream1<<tmp1->getData().getNational_gharzgirande()<<"\t";
                stream1<<tmp1->getData().getCode_of_book()<<"\t";
                stream1<<tmp1->getData().getSefaresh().getDay()<<"\t";
                stream1<<tmp1->getData().getSefaresh().getMonth()<<"\t";
                stream1<<tmp1->getData().getSefaresh().getYear()<<"\t";
                stream1<<tmp1->getData().getGharz().getDay()<<"\t";
                stream1<<tmp1->getData().getGharz().getMonth()<<"\t";
                stream1<<tmp1->getData().getGharz().getYear()<<"\t";
                stream1<<tmp1->getData().getPass().getDay()<<"\t";
                stream1<<tmp1->getData().getPass().getMonth()<<"\t";
                stream1<<tmp1->getData().getPass().getYear()<<"\t";
                stream1<<tmp1->getData().getTimeOfjarime().getDay()<<"\t";
                stream1<<tmp1->getData().getTimeOfjarime().getMonth()<<"\t";
                stream1<<tmp1->getData().getTimeOfjarime().getYear()<<"\n";
            }
            fil.close();
        }
        else
        {
            book_node* tmp=checkBookInformation();
            book_node* tmp6=tmp;
            for(;tmp!=nullptr;tmp=tmp->getNext())
            {
                if(tmp->getData().getCode()==tmp1->getData().getCode_of_book())
                {
                    book bk;
                    bk.setCode(tmp->getData().getCode());
                    bk.setIdEhdaconande(tmp->getData().getIdEhdaconande());
                    bk.setName(tmp->getData().getName());
                    bk.setSubject(tmp->getData().getSubject());
                    bk.setEhda(tmp->getData().getEhda());
                    bk.setEntesharat(tmp->getData().getEntesharatr());
                    bk.setAuthor(tmp->getData().getAuthor());
                    bk.setTranslator(tmp->getData().getTranslator());
                    bk.setNumber(tmp->getData().getNumber()+1);
                    tmp->setData(bk);
                }
            }
            //QFile("C:/Users/albaloo/Documents/mainProjectTerm2/booksInformations.txt").remove();
            QFile file("C:/Users/albaloo/Documents/ProjectOfTerm2/booksInformations.txt");
            file.open(QIODevice::WriteOnly);
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            for(;tmp6!=nullptr;tmp6=tmp6->getNext())
            {
                stream
                        <<tmp6->getData().getName()<<"\t"
                        <<tmp6->getData().getSubject()<<"\t"
                        <<tmp6->getData().getEntesharatr()<<"\t"
                        <<tmp6->getData().getCode()<<"\t"
                        <<tmp6->getData().getIdEhdaconande()<<"\t"
                        <<tmp6->getData().getNumber()<<"\t"
                        <<tmp6->getData().getAuthor().getName()<<"\t"
                        <<tmp6->getData().getAuthor().getFamily()<<"\t"
                        <<tmp6->getData().getAuthor().getNationality()<<"\t"
                        <<tmp6->getData().getTranslator().getName()<<"\t"
                        <<tmp6->getData().getTranslator().getFamily()<<"\t"
                        <<tmp6->getData().getEhda().getDay()<<"\t"
                        <<tmp6->getData().getEhda().getMonth()<<"\t"
                        <<tmp6->getData().getEhda().getYear()<<"\n";

            }
            file.close();

        }
    }
}
