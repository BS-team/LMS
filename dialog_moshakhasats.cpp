#include "dialog_moshakhasats.h"
#include "ui_dialog_moshakhasats.h"
#include<ctime>
#include<time.h>
#include<QFile>
#include<QTextStream>
#include"dialog_pasword.h"
#include"login_page.h"
#include<QMessageBox>
#include"functionToExplorUser.h"
#include"now_date.h"
#include"dialog_pardakht.h"
#include"checkpersianstring.h"
Dialog_moshakhasats::Dialog_moshakhasats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_moshakhasats)
{
    ui->setupUi(this);
    QPixmap bkgnd("E:/LastOne/ProjectOfTerm2/moshakhasatpic.jpg");
                    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
                    QPalette palette;
                    palette.setBrush(QPalette::Background, bkgnd);
                    this->setPalette(palette);




        this->setWindowTitle("مشخصات کاربر");

    for(int i=1350;i<1399;i++)
        ui->comboBox_year2->addItem(QString::number(i));

}

Dialog_moshakhasats::~Dialog_moshakhasats()
{
    delete ui;
}

Ui::Dialog_moshakhasats *Dialog_moshakhasats::getUi()
{
    return ui;
}

void Dialog_moshakhasats::on_pushButton_clicked()   //next button
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
            dialog_pardakht* dpl=new dialog_pardakht(1,this->ui->name->text(),this->ui->last_name->text(),this->ui->national->text(),this->ui->phone->text()
            ,this->ui->email->text(),this->ui->day->value(),this->ui->month->value(),this->ui->comboBox_year2->currentText().toUInt()
            ,this->ui->city->text(),this->ui->street->text(),this->ui->alley->text()
            ,this->ui->postcode->text());
            dpl->show();
        }
        else if(k==1)
        {
            QMessageBox::information(this,"خطا","بااین کدملی نمی توانید ثبت نام کنید",QMessageBox::Ok);
        }
    }
}


void Dialog_moshakhasats::on_back_clicked()
{
    login_page* lgp=new login_page();
    lgp->show();
    this->close();
}












void Dialog_moshakhasats::on_cancle_clicked()
{

}
