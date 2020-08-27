#include "dialog_moshakhasats_by_manager.h"
#include "ui_dialog_moshakhasats_by_manager.h"
#include<QMessageBox>
#include"dialog_password_by_manager.h"
#include"functionToExplorUser.h"
#include<QFile>
#include<QTextStream>
#include"usersoptionformanger.h"
#include"dialog_pardakht.h"
#include"checkpersianstring.h"

Dialog_moshakhasats_by_manager::Dialog_moshakhasats_by_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_moshakhasats_by_manager)
{
    ui->setupUi(this);
    QPalette pal = palette();
        // set black background
       // pal.setColor(QPalette::Background, Qt::green);
       // this->setAutoFillBackground(true);
       // this->setPalette(pal);
        QPixmap bkgnd("E:/LastOne/ProjectOfTerm2/sabtenambymanager.jpg");
                        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
                        QPalette palette;
                        palette.setBrush(QPalette::Background, bkgnd);
                        this->setPalette(palette);
        this->setWindowTitle("ویژگی های کاربر");



                        // ui->back->setStyleSheet("border-radius:50px");
                     //                    QRegion* region = new QRegion(*(new QRect(ui->back->x()+5,ui->back->y()+5,190,190)),QRegion::Ellipse);
                     //                       ui->back->setMask(*region);
                     //                       ui->back->show();
                     ui->back->setCheckable("true");


                     ui->back->setStyleSheet(QString::fromUtf8("QPushButton{"
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
                     ui->back->setFlat("true");



                     // ui->back->setStyleSheet("border-radius:50px");
                  //                    QRegion* region = new QRegion(*(new QRect(ui->back->x()+5,ui->back->y()+5,190,190)),QRegion::Ellipse);
                  //                       ui->back->setMask(*region);
                  //                       ui->back->show();
                  ui->pushButton->setCheckable("true");


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
                  ui->pushButton->setFlat("true");

    for(int i=1350;i<1399;i++)
        ui->year->addItem(QString::number(i));
}

Dialog_moshakhasats_by_manager::~Dialog_moshakhasats_by_manager()
{
    delete ui;
}

void Dialog_moshakhasats_by_manager::on_pushButton_clicked()
{
    int ki=1;

    for(int i=0;i<ui->email->text().length();i++)
    {
        if(ui->email->text()[i]!='@')
        {
            if(ui->email->text()[i]!='.')
            {
                if(ui->email->text()[i]>123 ||
                    (ui->email->text()[i]>57&&ui->email->text()[i]<65)
                    ||(ui->email->text()[i]>91&&ui->email->text()[i]<97)
                    ||ui->email->text()[i]<48)
                {
                    ki=0;
                    break;
                }

            }
        }
    }

    if(ki==0)
    {
        QMessageBox::information(this,"خطا","ایمیل خود رابه درستی وارد کنید",QMessageBox::Ok);
    }
    else if(ui->name->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد نام را پرکنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->name->text())==0)
    {
        QMessageBox::information(this,"خطا","فیلد نام رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->last_name->text())==0)
    {
        QMessageBox::information(this,"خطا","فیلد نام خانوادگی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->city->text())==0)
    {
        QMessageBox::information(this,"خطا","فیلد نام شهر رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->alley->text())==0)
    {
        QMessageBox::information(this,"خطا","فیلد نام کوچه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->name->text())==0)
    {
        QMessageBox::information(this,"خطا","فیلد نام خیابان رابه درستی پرکنید",QMessageBox::Ok);
    }

    else if(ui->last_name->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد نام خانوادگی را پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی را پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text().count()!=10 )
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[0]>57 || ui->national->text()[0]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[1]>57 || ui->national->text()[1]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[2]>57 || ui->national->text()[2]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[3]>57 || ui->national->text()[3]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[4]>57 || ui->national->text()[4]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[5]>57 || ui->national->text()[5]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[6]>57 || ui->national->text()[6]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[7]>57 || ui->national->text()[7]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[8]>57 || ui->national->text()[8]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->national->text()[9]>57 || ui->national->text()[9]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکد ملی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->email->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدایمیل همراه پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدتلفن همراه پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text().count()!=11)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }

    else if(ui->phone->text()[0]>57 || ui->phone->text()[0]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[1]>57 || ui->phone->text()[1]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[2]>57 || ui->phone->text()[2]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[3]>57 || ui->phone->text()[3]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[4]>57 || ui->phone->text()[4]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[5]>57 || ui->phone->text()[5]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[6]>57 || ui->phone->text()[6]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[7]>57 || ui->phone->text()[7]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[8]>57 || ui->phone->text()[8]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[9]>57 || ui->phone->text()[9]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->phone->text()[10]>57 || ui->phone->text()[10]<48)
    {
        QMessageBox::information(this,"خطا","فیلدشماره همراه رابه درستی پرکنید",QMessageBox::Ok);
    }

    else if(ui->city->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدشهررا پرکنید",QMessageBox::Ok);
    }
    else if(ui->street->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدخیابان را پرکنید",QMessageBox::Ok);
    }
    else if(ui->alley->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدکوچه را پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی را پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text().length()!=10)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی(10 رقم) رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[0]>57 || ui->postcode->text()[0]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[1]>57 || ui->postcode->text()[1]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[2]>57 || ui->postcode->text()[2]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[3]>57 || ui->postcode->text()[3]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[4]>57 || ui->postcode->text()[4]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[5]>57 || ui->postcode->text()[5]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[6]>57 || ui->postcode->text()[6]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[7]>57 || ui->postcode->text()[7]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[8]>57 || ui->postcode->text()[8]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }
    else if(ui->postcode->text()[9]>57 || ui->postcode->text()[9]<48)
    {
        QMessageBox::information(this,"خطا","فیلدکدپستی رابه درستی پرکنید",QMessageBox::Ok);
    }

    else
    {
        int k=0;
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
            if(tmp->getData().getNational_code()==ui->national->text())
                k=1;
        }
        if(k==0)
        {
            this->close();
                        dialog_pardakht* dpl=new dialog_pardakht(0,this->ui->name->text(),this->ui->last_name->text(),this->ui->national->text(),this->ui->phone->text()
                        ,this->ui->email->text(),this->ui->day->value(),this->ui->month->value(),this->ui->year->currentText().toUInt()
                        ,this->ui->city->text(),this->ui->street->text(),this->ui->alley->text()
                        ,this->ui->postcode->text());
                        dpl->show();
        }
        else if(k==1)
        {
            QMessageBox::information(this,"خطا","بااین کدملی نمی توان کسی را عضو کرد چرا که قبلا چنین کد ملی ثبت شده است",QMessageBox::Ok);
        }
    }

}



void Dialog_moshakhasats_by_manager::on_back_clicked()
{
    this->close();
    usersoptionformanger* usop=new usersoptionformanger();
    usop->show();
}
