#include "tamdidbookbyuser.h"
#include "ui_tamdidbookbyuser.h"
#include"facilities_for_karbar.h"
#include"functioforgharzandpassofbook.h"
#include"functionToExplorebooks.h"
#include"checkifsefareshismorethat2daybookezafe.h"
#include"now_date.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include"checkforsearch_book_user.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include"correcttamdid.h"
#include"checkjarime.h"
int nummm=0;

TamdidBookByUser::TamdidBookByUser(QString _id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TamdidBookByUser)
{
    ui->setupUi(this);

    setJarime();
    setBookNumberWithDateOfsabtByUser();
	
	ui->pushButton->setStyleSheet(QString::fromUtf8("QPushButton{"
    "padding: -6px;"
    //   "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
       //                                                                                "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
        //                                                                                "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
    //"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.977528 rgba(60, 60, 60, 255), stop:1 rgba(0, 0, 0, 0));"
    "background-color: lightgray;"
                                                "  left: -2px;"
    "min-width: 8em;"
    "border-style: solid;"
    "border-color: black;"
    "border-width: 3px;"
    //"subcontrol-position: center;"
    //"border-left-style: outset;"
      //"border-right-style: outset;"
               "selection-color: yellow;"
                 "selection-background-color: blue;"

    "border-bottom-left-radius: 30px;"
    "border-top-right-radius: 30px;"
    "}"));
    ui->pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{"
    "padding: -6px;"
    //   "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
       //                                                                                "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
        //                                                                                "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
    //"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.977528 rgba(60, 60, 60, 255), stop:1 rgba(0, 0, 0, 0));"
    "background-color: lightgray;"
                                                "  left: -2px;"
    "min-width: 8em;"
    "border-style: solid;"
    "border-color: black;"
    "border-width: 3px;"
    //"subcontrol-position: center;"
    //"border-left-style: outset;"
      //"border-right-style: outset;"
               "selection-color: yellow;"
                 "selection-background-color: blue;"

    "border-bottom-left-radius: 30px;"
    "border-top-right-radius: 30px;"
    "}"));

    QPixmap bkgnd("C:/Users/albaloo/Documents/ProjectOfTerm2/tamdidbookpic.html");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
	

    this->id_loginer=_id;

    QStringList my_list;
    ui->tableWidget->setColumnCount(5);


    my_list<<"نام کتاب"<<"موضوع"<<"کدکتاب"<<"تاریخ قرض گرفتن کتاب"<<"تمدید";

    this->setWindowTitle("تمدید کتاب");

    int num=0;
    for(book_gharz_pass_node* tmp=checkBookgharzandpass();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getNational_gharzgirande()==this->id_loginer)
        {
            if(tmp->getData().getGharz().getDay()!=0)
            {
                if(tmp->getData().getPass().getDay()==0)
                {
                    num++;
                }
            }
        }
    }


    for(int i=ui->tableWidget->rowCount();i>=0;i--)
        ui->tableWidget->removeRow(i);

    checktamdid=new QCheckBox*[num];

    for(int i=0;i<num;i++)
        checktamdid[i]=new QCheckBox();

    for(book_gharz_pass_node* tmp=checkBookgharzandpass();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(correctTamdid(tmp->getData().getNational_gharzgirande(),tmp->getData().getCode_of_book()))
        {
            if(tmp->getData().getCode_of_book()!="")
            {
               if(tmp->getData().getNational_gharzgirande()==this->id_loginer)
               {
                   if(tmp->getData().getPass().getDay()==0  && tmp->getData().getGharz().getDay()!=0)
                   {
                       for(book_node* tmp1=checkBookInformation();tmp1!=nullptr;tmp1=tmp1->getNext())
                       {
                           if(tmp1->getData().getCode()==tmp->getData().getCode_of_book())
                           {
                               ui->tableWidget->insertRow(ui->tableWidget->rowCount());

                               QTableWidgetItem *item = new QTableWidgetItem(tmp1->getData().getName());
                               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,item);
                               item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                               QTableWidgetItem *item1 = new QTableWidgetItem(tmp1->getData().getSubject());
                               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,item1);
                               item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                               QTableWidgetItem *item2 = new QTableWidgetItem(tmp1->getData().getCode());
                               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,item2);
                               item2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                               QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(tmp->getData().getGharz().getDay())+'/'+QString::number(tmp->getData().getGharz().getMonth())+'/'+QString::number(tmp->getData().getGharz().getYear()));
                               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,item3);
                               item3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                               if(date_now()-tmp->getData().getGharz()<14)
                               {
                                   QWidget *checkBoxWidget1 = new QWidget();
                                   //QCheckBox* checkbox=new QCheckBox();
                                   QHBoxLayout *layoutCheckBox1 = new QHBoxLayout(checkBoxWidget1); // create a layer with reference to the widget
                                   layoutCheckBox1->addWidget(checktamdid[ui->tableWidget->rowCount()-1]);            // Set the checkbox in the layer
                                   layoutCheckBox1->setAlignment(Qt::AlignCenter);  // Center the checkbox
                                   layoutCheckBox1->setContentsMargins(0,0,0,0);    // Set the zero padding
                                   ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,4, checkBoxWidget1);
                               }
                               nummm++;
                               break;
                           }
                        }
                    }
                }
            }
        }
    }
}

TamdidBookByUser::~TamdidBookByUser()
{
    delete ui;
}

void TamdidBookByUser::on_pushButton_2_clicked()
{
    int zz=0;
    int nn=nummm;
    for(int i=0;i<nummm;i++)
    {
        if(checktamdid[i]->isChecked())
        {
            zz=1;

            if(correctTamdid(this->id_loginer,ui->tableWidget->item(i,2)->text()))
            {
                int num=0;
                for(book_gharz_pass_node* tmp=checkBookgharzandpass();tmp!=nullptr;tmp=tmp->getNext())
                    num++;

                book_gharz_pass_node* tmp1=checkBookgharzandpass();
                book_gharz_pass_node* tmp6=tmp1;
                for(;tmp1!=nullptr;tmp1=tmp1->getNext())
                {
                    if(tmp1->getData().getNational_gharzgirande()==this->id_loginer && tmp1->getData().getCode_of_book()==ui->tableWidget->item(i,2)->text())
                    {
                        if(tmp1->getData().getPass().getDay()==0)
                        {
                            book_gharz_pass bghp;
                            bghp.setGhaz(tmp1->getData().getGharz());
                            bghp.setSefaresh(tmp1->getData().getSefaresh());
                            bghp.setNational_gharzgirande(tmp1->getData().getNational_gharzgirande());
                            bghp.setPass(date_now());
                            bghp.setCode_of_book(tmp1->getData().getCode_of_book());
                            tmp1->setData(bghp);
                            break;
                        }
                    }
                }

                QFile("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt").remove();
                QFile file("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
                file.open(QIODevice::Append);
                QTextStream stream1(&file);
                stream1.setCodec("UTF-8");

                for(;tmp6!=nullptr;tmp6=tmp6->getNext())
                {
                    stream1<<tmp6->getData().getNational_gharzgirande()<<"\t";
                    stream1<<tmp6->getData().getCode_of_book()<<"\t";
                    stream1<<tmp6->getData().getSefaresh().getDay()<<"\t";
                    stream1<<tmp6->getData().getSefaresh().getMonth()<<"\t";
                    stream1<<tmp6->getData().getSefaresh().getYear()<<"\t";
                    stream1<<tmp6->getData().getGharz().getDay()<<"\t";
                    stream1<<tmp6->getData().getGharz().getMonth()<<"\t";
                    stream1<<tmp6->getData().getGharz().getYear()<<"\t";
                    stream1<<tmp6->getData().getPass().getDay()<<"\t";
                    stream1<<tmp6->getData().getPass().getMonth()<<"\t";
                    stream1<<tmp6->getData().getPass().getYear()<<"\t";
                    stream1<<tmp6->getData().getTimeOfjarime().getDay()<<"\t";
                    stream1<<tmp6->getData().getTimeOfjarime().getMonth()<<"\t";
                    stream1<<tmp6->getData().getTimeOfjarime().getYear()<<"\n";
                }
                stream1<<this->id_loginer<<"\t";
                stream1<<ui->tableWidget->item(i,2)->text()<<"\t";
                stream1<<date_now().getDay()<<"\t";
                stream1<<date_now().getMonth()<<"\t";
                stream1<<date_now().getYear()<<"\t";
                stream1<<date_now().getDay()<<"\t";
                stream1<<date_now().getMonth()<<"\t";
                stream1<<date_now().getYear()<<"\t";
                stream1<<0<<"\t";
                stream1<<0<<"\t";
                stream1<<0<<"\t";
                stream1<<0<<"\t";
                stream1<<0<<"\t";
                stream1<<0<<"\n";
                file.close();
                qDebug()<<"done";
            }
        }
    }
    if(zz==1)
    {
        QMessageBox::information(this,"موفقیت امیز","شما با موفقیت تغییر دادید",QMessageBox::Ok);
        for(int i=0;i<nummm;i++)
        {
            if(checktamdid[i]->isChecked())
                ui->tableWidget->hideRow(i);
        }
        for(int i=0;i<nummm;i++)
        {
            checktamdid[i]->setCheckState(Qt::Unchecked);
        }
    }
}

void TamdidBookByUser::on_pushButton_clicked()
{
    this->close();
    facilities_for_karbar* fcfk=new facilities_for_karbar(this->id_loginer);
    fcfk->show();
}
