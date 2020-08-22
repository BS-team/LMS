#include "edit_profile_of_karbar_by_himself.h"
#include "ui_edit_profile_of_karbar_by_himself.h"
#include "facilities_for_karbar.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "karbar.h"
#include"karbar_node.h"
#include "functionToExplorUser.h"
#include"functioforgharzandpassofbook.h"
#include<QDebug>


edit_profile_of_karbar_by_himself::edit_profile_of_karbar_by_himself(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_profile_of_karbar_by_himself)
{
    ui->setupUi(this);

    this->id_Loginer=s;

//    QPalette pal = palette();
//    // set black background
//    pal.setColor(QPalette::Background, Qt::red);
//    this->setAutoFillBackground(true);
//    this->setPalette(pal);
    this->setWindowTitle("تغییرمشخصات");
    for(int i=1950;i<2020;i++)
    {
        ui->comboBox_year->addItem(QString::number(i));
    }

    ui->label_previous_name->hide();
    ui->label_previous_name_2->hide();
    ui->label_previous_lastname->hide();
    ui->label_previous_lastname_2->hide();
    ui->label_previous_phonenumber->hide();
    ui->label_previous_phonenumber_2->hide();
    ui->label_previous_email->hide();
    ui->label_previous_email_2->hide();
    ui->label_previous_address->hide();
    ui->label_previous_city->hide();
    ui->label_previous_city_2->hide();
    ui->label_previous_street->hide();
    ui->label_previous_street_2->hide();
    ui->label_previous_alley->hide();
    ui->label_previous_alley_2->hide();
    ui->label_previous_postcard->hide();
    ui->label_previous_postcard_2->hide();
    ui->label_previous_birthdate->hide();
    ui->label_previous_day->hide();
    ui->label_previous_day_2->hide();
    ui->label_previous_month->hide();
    ui->label_previous_month_2->hide();
    ui->label_previous_year->hide();
    ui->label_previous_year_2->hide();
    ui->label_prevpas->hide();


    ui->label_name->hide();
    ui->label_lastname->hide();
    ui->label_phonenumber->hide();
    ui->label_email->hide();
    ui->label_address->hide();
    ui->label_city->hide();
    ui->label_street->hide();
    ui->label_alley->hide();
    ui->label_postcard->hide();
    ui->label_birthdate->hide();
    ui->label_day->hide();
    ui->label_month->hide();
    ui->label_year->hide();
    ui->label->hide();
    ui->label_nationalcode->hide();
    ui->label_entrydate_day->hide();
    ui->label_entrydate_month->hide();
    ui->label_entrydate_year->hide();

    ui->lineEdit_name->hide();
    ui->lineEdit_lastname->hide();
    ui->lineEdit_phonenumber->hide();
    ui->lineEdit_email->hide();
    ui->lineEdit_city->hide();
    ui->lineEdit_street->hide();
    ui->lineEdit_alley->hide();
    ui->lineEdit_postcard->hide();
    ui->lineEdit_password->hide();
    ui->lineEdit_previouspassword->hide();
    ui->spinBox_day->hide();
    ui->spinBox_month->hide();
    ui->comboBox_year->hide();


    ui->label_password->show();
    ui->label_previouspassword->show();
    ui->lineEdit_password->show();
    ui->lineEdit_previouspassword->show();
    ui->label->show();


    ui->comboBox->addItem("رمزعبور");
    ui->comboBox->addItem("اسم");
    ui->comboBox->addItem("نام خانوادگی");
    ui->comboBox->addItem("شماره همراه");
    ui->comboBox->addItem("ایمیل");
    ui->comboBox->addItem("ادرس");
    ui->comboBox->addItem("تاریخ تولد");

    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(changemoshkarbar(int)));

    karbar_node* tmp1;
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getNational_code()==id_Loginer)
        {
            tmp1=tmp;
            break;
        }
    }

    ui->label_previous_name_2->setText(tmp1->getData().getName());
    ui->label_previous_lastname_2->setText(tmp1->getData().getFamily());
    ui->label_previous_phonenumber_2->setText(tmp1->getData().getPhone());
    ui->label_previous_email_2->setText(tmp1->getData().getEmail());
    ui->label_previous_city_2->setText(tmp1->getData().getAddress().getCity());
    ui->label_previous_street_2->setText(tmp1->getData().getAddress().getStreet());
    ui->label_previous_alley_2->setText(tmp1->getData().getAddress().getAlley());
    ui->label_previous_postcard_2->setText(tmp1->getData().getAddress().getPostcode());
    ui->label_previous_day_2->setText(QString::number(tmp1->getData().getBirth().getDay()));
    ui->label_previous_month_2->setText(QString::number(tmp1->getData().getBirth().getMonth()));
    ui->label_previous_year_2->setText(QString::number(tmp1->getData().getBirth().getYear()));
    ui->label_prevpas->setText(tmp1->getData().getPassword());
    ui->label_nationalcode->setText(tmp1->getData().getNational_code());
    ui->label_entrydate_day->setText(QString::number(tmp1->getData().getEnter().getDay()));
    ui->label_entrydate_month->setText(QString::number(tmp1->getData().getEnter().getMonth()));
    ui->label_entrydate_year->setText(QString::number(tmp1->getData().getEnter().getYear()));


}

edit_profile_of_karbar_by_himself::~edit_profile_of_karbar_by_himself()
{
    delete ui;
}

Ui::edit_profile_of_karbar_by_himself *edit_profile_of_karbar_by_himself::getUi()
{
    return  ui;
}

void edit_profile_of_karbar_by_himself::on_pushButton_2_clicked() //back
{
    this->close();
    facilities_for_karbar *ffk = new facilities_for_karbar(this->id_Loginer);
    ffk->show();
}

void edit_profile_of_karbar_by_himself::changemoshkarbar(int n)
{
   if(n==0)
   {
       ui->label_previous_name->hide();
       ui->label_previous_name_2->hide();
       ui->label_previous_lastname->hide();
       ui->label_previous_lastname_2->hide();
       ui->label_previous_phonenumber->hide();
       ui->label_previous_phonenumber_2->hide();
       ui->label_previous_email->hide();
       ui->label_previous_email_2->hide();
       ui->label_previous_address->hide();
       ui->label_previous_city->hide();
       ui->label_previous_city_2->hide();
       ui->label_previous_street->hide();
       ui->label_previous_street_2->hide();
       ui->label_previous_alley->hide();
       ui->label_previous_alley_2->hide();
       ui->label_previous_postcard->hide();
       ui->label_previous_postcard_2->hide();
       ui->label_previous_birthdate->hide();
       ui->label_previous_day->hide();
       ui->label_previous_day_2->hide();
       ui->label_previous_month->hide();
       ui->label_previous_month_2->hide();
       ui->label_previous_year->hide();
       ui->label_previous_year_2->hide();
       ui->label_prevpas->hide();


       ui->label_name->hide();
       ui->label_lastname->hide();
       ui->label_phonenumber->hide();
       ui->label_email->hide();
       ui->label_address->hide();
       ui->label_city->hide();
       ui->label_street->hide();
       ui->label_alley->hide();
       ui->label_postcard->hide();
       ui->label_birthdate->hide();
       ui->label_day->hide();
       ui->label_month->hide();
       ui->label_year->hide();


       ui->lineEdit_name->hide();
       ui->lineEdit_lastname->hide();
       ui->lineEdit_phonenumber->hide();
       ui->lineEdit_email->hide();
       ui->lineEdit_city->hide();
       ui->lineEdit_street->hide();
       ui->lineEdit_alley->hide();
       ui->lineEdit_postcard->hide();
       ui->spinBox_day->hide();
       ui->spinBox_month->hide();
       ui->comboBox_year->hide();

       ui->label_password->show();
       ui->label_previouspassword->show();
       ui->lineEdit_password->show();
       ui->lineEdit_previouspassword->show();
       ui->label->show();
   }
   else if(n==1)
   {
       ui->label_previous_lastname->hide();
       ui->label_previous_lastname_2->hide();
       ui->label_previous_phonenumber->hide();
       ui->label_previous_phonenumber_2->hide();
       ui->label_previous_email->hide();
       ui->label_previous_email_2->hide();
       ui->label_previous_address->hide();
       ui->label_previous_city->hide();
       ui->label_previous_city_2->hide();
       ui->label_previous_street->hide();
       ui->label_previous_street_2->hide();
       ui->label_previous_alley->hide();
       ui->label_previous_alley_2->hide();
       ui->label_previous_postcard->hide();
       ui->label_previous_postcard_2->hide();
       ui->label_previous_birthdate->hide();
       ui->label_previous_day->hide();
       ui->label_previous_day_2->hide();
       ui->label_previous_month->hide();
       ui->label_previous_month_2->hide();
       ui->label_previous_year->hide();
       ui->label_previous_year_2->hide();
       ui->label_prevpas->hide();

       ui->label_lastname->hide();
       ui->label_phonenumber->hide();
       ui->label_email->hide();
       ui->label_address->hide();
       ui->label_city->hide();
       ui->label_street->hide();
       ui->label_alley->hide();
       ui->label_postcard->hide();
       ui->label_password->hide();
       ui->label_previouspassword->hide();
       ui->label_birthdate->hide();
       ui->label_day->hide();
       ui->label_month->hide();
       ui->label_year->hide();
       ui->label->hide();

       ui->lineEdit_lastname->hide();
       ui->lineEdit_phonenumber->hide();
       ui->lineEdit_email->hide();
       ui->lineEdit_city->hide();
       ui->lineEdit_street->hide();
       ui->lineEdit_alley->hide();
       ui->lineEdit_postcard->hide();
       ui->lineEdit_password->hide();
       ui->lineEdit_previouspassword->hide();
       ui->spinBox_day->hide();
       ui->spinBox_month->hide();
       ui->comboBox_year->hide();

       ui->label_name->show();
       ui->lineEdit_name->show();
       ui->label_previous_name->show();
       ui->label_previous_name_2->show();
   }
   else if(n==2)
   {
       ui->label_previous_name->hide();
       ui->label_previous_name_2->hide();
       ui->label_previous_phonenumber->hide();
       ui->label_previous_phonenumber_2->hide();
       ui->label_previous_email->hide();
       ui->label_previous_email_2->hide();
       ui->label_previous_address->hide();
       ui->label_previous_city->hide();
       ui->label_previous_city_2->hide();
       ui->label_previous_street->hide();
       ui->label_previous_street_2->hide();
       ui->label_previous_alley->hide();
       ui->label_previous_alley_2->hide();
       ui->label_previous_postcard->hide();
       ui->label_previous_postcard_2->hide();
       ui->label_previous_birthdate->hide();
       ui->label_previous_day->hide();
       ui->label_previous_day_2->hide();
       ui->label_previous_month->hide();
       ui->label_previous_month_2->hide();
       ui->label_previous_year->hide();
       ui->label_previous_year_2->hide();
       ui->label_prevpas->hide();

       ui->label_name->hide();
       ui->label_phonenumber->hide();
       ui->label_email->hide();
       ui->label_address->hide();
       ui->label_city->hide();
       ui->label_street->hide();
       ui->label_alley->hide();
       ui->label_postcard->hide();
       ui->label_password->hide();
       ui->label_previouspassword->hide();
       ui->label_birthdate->hide();
       ui->label_day->hide();
       ui->label_month->hide();
       ui->label_year->hide();
       ui->label->hide();

       ui->lineEdit_name->hide();
       ui->lineEdit_phonenumber->hide();
       ui->lineEdit_email->hide();
       ui->lineEdit_city->hide();
       ui->lineEdit_street->hide();
       ui->lineEdit_alley->hide();
       ui->lineEdit_postcard->hide();
       ui->lineEdit_password->hide();
       ui->lineEdit_previouspassword->hide();
       ui->spinBox_day->hide();
       ui->spinBox_month->hide();
       ui->comboBox_year->hide();

       ui->label_lastname->show();
       ui->lineEdit_lastname->show();
       ui->label_previous_lastname->show();
       ui->label_previous_lastname_2->show();
   }
   else if(n==3)
   {
       ui->label_previous_name->hide();
       ui->label_previous_name_2->hide();
       ui->label_previous_lastname->hide();
       ui->label_previous_lastname_2->hide();
       ui->label_previous_email->hide();
       ui->label_previous_email_2->hide();
       ui->label_previous_address->hide();
       ui->label_previous_city->hide();
       ui->label_previous_city_2->hide();
       ui->label_previous_street->hide();
       ui->label_previous_street_2->hide();
       ui->label_previous_alley->hide();
       ui->label_previous_alley_2->hide();
       ui->label_previous_postcard->hide();
       ui->label_previous_postcard_2->hide();
       ui->label_previous_birthdate->hide();
       ui->label_previous_day->hide();
       ui->label_previous_day_2->hide();
       ui->label_previous_month->hide();
       ui->label_previous_month_2->hide();
       ui->label_previous_year->hide();
       ui->label_previous_year_2->hide();
       ui->label_prevpas->hide();

       ui->label_name->hide();
       ui->label_lastname->hide();
       ui->label_email->hide();
       ui->label_address->hide();
       ui->label_city->hide();
       ui->label_street->hide();
       ui->label_alley->hide();
       ui->label_postcard->hide();
       ui->label_password->hide();
       ui->label_previouspassword->hide();
       ui->label_birthdate->hide();
       ui->label_day->hide();
       ui->label_month->hide();
       ui->label_year->hide();
       ui->label->hide();

       ui->lineEdit_name->hide();
       ui->lineEdit_lastname->hide();
       ui->lineEdit_email->hide();
       ui->lineEdit_city->hide();
       ui->lineEdit_street->hide();
       ui->lineEdit_alley->hide();
       ui->lineEdit_postcard->hide();
       ui->lineEdit_password->hide();
       ui->lineEdit_previouspassword->hide();
       ui->spinBox_day->hide();
       ui->spinBox_month->hide();
       ui->comboBox_year->hide();

       ui->label_phonenumber->show();
       ui->lineEdit_phonenumber->show();
       ui->label_previous_phonenumber->show();
       ui->label_previous_phonenumber_2->show();
   }
   else if(n==4)
   {
       ui->label_previous_name->hide();
       ui->label_previous_name_2->hide();
       ui->label_previous_lastname->hide();
       ui->label_previous_lastname_2->hide();
       ui->label_previous_phonenumber->hide();
       ui->label_previous_phonenumber_2->hide();
       ui->label_previous_address->hide();
       ui->label_previous_city->hide();
       ui->label_previous_city_2->hide();
       ui->label_previous_street->hide();
       ui->label_previous_street_2->hide();
       ui->label_previous_alley->hide();
       ui->label_previous_alley_2->hide();
       ui->label_previous_postcard->hide();
       ui->label_previous_postcard_2->hide();
       ui->label_previous_birthdate->hide();
       ui->label_previous_day->hide();
       ui->label_previous_day_2->hide();
       ui->label_previous_month->hide();
       ui->label_previous_month_2->hide();
       ui->label_previous_year->hide();
       ui->label_previous_year_2->hide();
       ui->label_prevpas->hide();

       ui->label_name->hide();
       ui->label_lastname->hide();
       ui->label_phonenumber->hide();
       ui->label_address->hide();
       ui->label_city->hide();
       ui->label_street->hide();
       ui->label_alley->hide();
       ui->label_postcard->hide();
       ui->label_password->hide();
       ui->label_previouspassword->hide();
       ui->label_birthdate->hide();
       ui->label_day->hide();
       ui->label_month->hide();
       ui->label_year->hide();
       ui->label->hide();

       ui->lineEdit_name->hide();
       ui->lineEdit_lastname->hide();
       ui->lineEdit_phonenumber->hide();
       ui->lineEdit_city->hide();
       ui->lineEdit_street->hide();
       ui->lineEdit_alley->hide();
       ui->lineEdit_postcard->hide();
       ui->lineEdit_password->hide();
       ui->lineEdit_previouspassword->hide();
       ui->spinBox_day->hide();
       ui->spinBox_month->hide();
       ui->comboBox_year->hide();

      ui->label_email->show();
      ui->lineEdit_email->show();
      ui->label_previous_email->show();
      ui->label_previous_email_2->show();
   }
   else if(n==5)
   {
       ui->label_previous_name->hide();
       ui->label_previous_name_2->hide();
       ui->label_previous_lastname->hide();
       ui->label_previous_lastname_2->hide();
       ui->label_previous_phonenumber->hide();
       ui->label_previous_phonenumber_2->hide();
       ui->label_previous_email->hide();
       ui->label_previous_email_2->hide();
       ui->label_previous_birthdate->hide();
       ui->label_previous_day->hide();
       ui->label_previous_day_2->hide();
       ui->label_previous_month->hide();
       ui->label_previous_month_2->hide();
       ui->label_previous_year->hide();
       ui->label_previous_year_2->hide();
       ui->label_prevpas->hide();

       ui->label_name->hide();
       ui->label_lastname->hide();
       ui->label_phonenumber->hide();
       ui->label_email->hide();
       ui->label_password->hide();
       ui->label_previouspassword->hide();
       ui->label_birthdate->hide();
       ui->label_day->hide();
       ui->label_month->hide();
       ui->label_year->hide();
       ui->label->hide();

       ui->lineEdit_name->hide();
       ui->lineEdit_lastname->hide();
       ui->lineEdit_phonenumber->hide();
       ui->lineEdit_email->hide();
       ui->lineEdit_password->hide();
       ui->lineEdit_previouspassword->hide();
       ui->spinBox_day->hide();
       ui->spinBox_month->hide();
       ui->comboBox_year->hide();

       ui->label_address->show();
       ui->label_city->show();
       ui->label_street->show();
       ui->label_alley->show();
       ui->label_postcard->show();
       ui->lineEdit_city->show();
       ui->lineEdit_street->show();
       ui->lineEdit_alley->show();
       ui->lineEdit_postcard->show();
       ui->label_previous_address->show();
       ui->label_previous_city->show();
       ui->label_previous_city_2->show();
       ui->label_previous_street->show();
       ui->label_previous_street_2->show();
       ui->label_previous_alley->show();
       ui->label_previous_alley_2->show();
       ui->label_previous_postcard->show();
       ui->label_previous_postcard_2->show();
   }
   else if(n==6)
   {
       ui->label_previous_name->hide();
       ui->label_previous_name_2->hide();
       ui->label_previous_lastname->hide();
       ui->label_previous_lastname_2->hide();
       ui->label_previous_phonenumber->hide();
       ui->label_previous_phonenumber_2->hide();
       ui->label_previous_email->hide();
       ui->label_previous_email_2->hide();
       ui->label_previous_address->hide();
       ui->label_previous_city->hide();
       ui->label_previous_city_2->hide();
       ui->label_previous_street->hide();
       ui->label_previous_street_2->hide();
       ui->label_previous_alley->hide();
       ui->label_previous_alley_2->hide();
       ui->label_previous_postcard->hide();
       ui->label_previous_postcard_2->hide();
       ui->label_prevpas->hide();

       ui->label_name->hide();
       ui->label_lastname->hide();
       ui->label_phonenumber->hide();
       ui->label_email->hide();
       ui->label_address->hide();
       ui->label_city->hide();
       ui->label_street->hide();
       ui->label_alley->hide();
       ui->label_postcard->hide();
       ui->label_password->hide();
       ui->label_previouspassword->hide();
       ui->label->hide();

       ui->lineEdit_name->hide();
       ui->lineEdit_lastname->hide();
       ui->lineEdit_phonenumber->hide();
       ui->lineEdit_email->hide();
       ui->lineEdit_city->hide();
       ui->lineEdit_street->hide();
       ui->lineEdit_alley->hide();
       ui->lineEdit_postcard->hide();
       ui->lineEdit_password->hide();
       ui->lineEdit_previouspassword->hide();

       ui->label_birthdate->show();
       ui->label_day->show();
       ui->label_month->show();
       ui->label_year->show();
       ui->spinBox_day->show();
       ui->spinBox_month->show();
       ui->comboBox_year->show();
       ui->label_previous_birthdate->show();
       ui->label_previous_day->show();
       ui->label_previous_day_2->show();
       ui->label_previous_month->show();
       ui->label_previous_month_2->show();
       ui->label_previous_year->show();
       ui->label_previous_year_2->show();
   }
}

void edit_profile_of_karbar_by_himself::on_pushButton_clicked()  //set change
{
    int k=1;

    if(ui->lineEdit_phonenumber->text()!="")
    {
        if(ui->lineEdit_phonenumber->text()[0] >57 || ui->lineEdit_phonenumber->text()[0] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[1] >57 || ui->lineEdit_phonenumber->text()[1] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[2] >57 || ui->lineEdit_phonenumber->text()[2] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[3] >57 || ui->lineEdit_phonenumber->text()[3] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[4] >57 || ui->lineEdit_phonenumber->text()[4] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[5] >57 || ui->lineEdit_phonenumber->text()[5] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[6] >57 || ui->lineEdit_phonenumber->text()[6] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[7] >57 || ui->lineEdit_phonenumber->text()[7] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[8] >57 || ui->lineEdit_phonenumber->text()[8] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[9] >57 || ui->lineEdit_phonenumber->text()[9] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
        else if(ui->lineEdit_phonenumber->text()[10] >57 || ui->lineEdit_phonenumber->text()[10] <48)
        {
            QMessageBox::information(this,"failed","this phone number is not accaptable",QMessageBox::Ok);
            k=0;
        }
    }
    else if(ui->lineEdit_password->text()!="")
    {
        for(int i=0;i<ui->lineEdit_password->text().length();i++)
        {
            if((ui->lineEdit_password->text()[i]<65&&ui->lineEdit_password->text()[i]>57)||ui->lineEdit_password->text()[i]<48||(ui->lineEdit_password->text()[i]>91&&ui->lineEdit_password->text()[i]<97)||ui->lineEdit_password->text()[i]>123)
            {
                QMessageBox::information(this,"failed","this password is not acceptable look at note",QMessageBox::Ok);
                k=0;
                break;
            }
        }
        if(ui->lineEdit_password->text().length()<8)
        {
            QMessageBox::information(this,"failed","this password is less than 8 charactors",QMessageBox::Ok);
            k=0;
        }
        if(ui->lineEdit_previouspassword->text()!=ui->label_prevpas->text()  )
        {
            QMessageBox::information(this,"failed","your previous password is not correct try again",QMessageBox::Ok);
            k=0;
        }
    }

    if(k==1)
    {
        QMessageBox::information(this,"موفقیت امیز","شما با موفقیت مشخصات خود را تغییردادید",QMessageBox::Ok);

        karbar_node* tmp=checkUserInformation();
        karbar_node* tmp2=tmp;

        date dt;
        date dt1;
        address add1;
        karbar xx;
        for(;tmp!=nullptr;tmp=tmp->getNext())
        {
            if(tmp->getData().getNational_code()==id_Loginer)
            {
                xx.setMojodi(tmp->getData().getMojodi());
                if(ui->lineEdit_name->text()!="")
                {
                   tmp->getData().setName(ui->lineEdit_name->text());
                   xx.setName(ui->lineEdit_name->text());
                }
                else
                {
                    tmp->getData().setName(ui->label_previous_name_2->text());
                    xx.setName(ui->label_previous_name_2->text());
                }
                if(ui->lineEdit_lastname->text()!="")
                {
                    tmp->getData().setFamily(ui->lineEdit_lastname->text());
                    xx.setFamily(ui->lineEdit_lastname->text());
                }
                else
                {
                     tmp->getData().setFamily(ui->label_previous_lastname_2->text());
                     xx.setFamily(ui->label_previous_lastname_2->text());
                }

                if(ui->lineEdit_phonenumber->text()!="")
                {
                    tmp->getData().setPhone(ui->lineEdit_phonenumber->text());
                    xx.setPhone(ui->lineEdit_phonenumber->text());
                }
                else
                {
                    tmp->getData().setPhone(ui->label_previous_phonenumber_2->text());
                    xx.setPhone(ui->label_previous_phonenumber_2->text());
                }

                if(ui->lineEdit_email->text()!="")
                {
                    tmp->getData().setEmail(ui->lineEdit_email->text());
                    xx.setEmail(ui->lineEdit_email->text());
                    tmp->setData(xx);
                }
                else
                {
                    tmp->getData().setEmail(ui->label_previous_email_2->text());
                    xx.setEmail(ui->label_previous_email_2->text());
                    tmp->setData(xx);
                }

                if(ui->lineEdit_city->text()!="")
                {
                    add1.setCity(ui->lineEdit_city->text());
                }
                else
                {
                    add1.setCity(ui->label_previous_city_2->text());
                }

                if(ui->lineEdit_street->text()!="")
                {
                     add1.setStreet(ui->lineEdit_street->text());
                }
                else
                {
                     add1.setStreet(ui->label_previous_street_2->text());
                 }

                if(ui->lineEdit_alley->text()!="")
                {
                     add1.setStreet(ui->lineEdit_alley->text());
                }
                else
                {
                     add1.setAlley(ui->label_previous_alley_2->text());
                }

                if(ui->lineEdit_postcard->text()!="")
                {
                     add1.setPostcode(ui->lineEdit_postcard->text());
                }
                else
                {
                     add1.setPostcode(ui->label_previous_postcard_2->text());
                 }
                 xx.setAddress(add1);

                if(ui->lineEdit_password->text()!="")
                {
                    tmp->getData().setPassword(ui->lineEdit_password->text());
                    xx.setPassword(ui->lineEdit_password->text());
                }
                else
                {
                    tmp->getData().setPassword(ui->label_prevpas->text());
                    xx.setPassword(ui->label_prevpas->text());
                }

                if(ui->spinBox_day->text().toInt()!=0)
                {
                    dt.setDay(ui->spinBox_day->text().toInt());
                }
                else
                {
                    dt.setDay(ui->label_previous_day_2->text().toInt());
                }

                if(ui->spinBox_month->text().toInt()!=0)
                {
                    dt.setMonth(ui->spinBox_month->text().toInt());
                }
                else
                {
                    dt.setMonth(ui->label_previous_month_2->text().toInt());
                }

                if(ui->comboBox_year->currentText().toInt()!=1950)
                {
                    dt.setYear(ui->comboBox_year->currentText().toInt());
                }
                else
                {
                    dt.setYear(ui->label_previous_year_2->text().toInt());
                }

                xx.setBirth(dt);
                xx.setNational_code(ui->label_nationalcode->text());
                dt1.setDay(ui->label_entrydate_day->text().toInt());
                dt1.setMonth(ui->label_entrydate_month->text().toInt());
                dt1.setYear(ui->label_entrydate_year->text().toInt());
                xx.setEntery(dt1);

                tmp->setData(xx);
            }
        }


        QFile fil("C:/Users/albaloo/Documents/ProjectOfTerm2/karbarInformation.txt");

        fil.open(QIODevice::WriteOnly);
        QTextStream stream1(&fil);
        stream1.setCodec("UTF-8");
        tmp=tmp2;

        for(;tmp!=nullptr;tmp=tmp->getNext())
        {

            if(tmp->getData().getNational_code()==this->id_Loginer)
            {
                ui->label_previous_name_2->setText(tmp->getData().getName());
                ui->label_previous_lastname_2->setText(tmp->getData().getFamily());
                ui->label_previous_phonenumber_2->setText(tmp->getData().getPhone());
                ui->label_previous_email_2->setText(tmp->getData().getEmail());
                ui->label_previous_city_2->setText(tmp->getData().getAddress().getCity());
                ui->label_previous_street_2->setText(tmp->getData().getAddress().getStreet());
                ui->label_previous_alley_2->setText(tmp->getData().getAddress().getAlley());
                ui->label_previous_postcard_2->setText(tmp->getData().getAddress().getPostcode());
                ui->label_previous_day_2->setText(QString::number(tmp->getData().getBirth().getDay()));
                ui->label_previous_month_2->setText(QString::number(tmp->getData().getBirth().getMonth()));
                ui->label_previous_year_2->setText(QString::number(tmp->getData().getBirth().getYear()));
                ui->label_prevpas->setText(tmp->getData().getPassword());
                ui->label_nationalcode->setText(tmp->getData().getNational_code());
                ui->label_entrydate_day->setText(QString::number(tmp->getData().getEnter().getDay()));
                ui->label_entrydate_month->setText(QString::number(tmp->getData().getEnter().getMonth()));
                ui->label_entrydate_year->setText(QString::number(tmp->getData().getEnter().getYear()));
            }
            stream1<<tmp->getData().getName()<<"\t";
            stream1<<tmp->getData().getFamily()<<"\t";
            stream1<<tmp->getData().getNational_code()<<"\t";
            stream1<<tmp->getData().getPassword()<<"\t";
            stream1<<tmp->getData().getPhone()<<"\t";
            stream1<<tmp->getData().getEmail()<<"\t";
            stream1<<tmp->getData().getBirth().getDay()<<"\t";
            stream1<<tmp->getData().getBirth().getMonth()<<"\t";
            stream1<<tmp->getData().getBirth().getYear()<<"\t";
            stream1<<tmp->getData().getEnter().getDay()<<"\t";
            stream1<<tmp->getData().getEnter().getMonth()<<"\t";
            stream1<<tmp->getData().getEnter().getYear()<<"\t";
            stream1<<tmp->getData().getAddress().getCity()<<"\t";
            stream1<<tmp->getData().getAddress().getStreet()<<"\t";
            stream1<<tmp->getData().getAddress().getAlley()<<"\t";
            stream1<<tmp->getData().getAddress().getPostcode()<<"\t";
            stream1<<tmp->getData().getMojodi()<<"\n";
        }
        fil.close();

        ui->lineEdit_city->setText("");
        ui->lineEdit_name->setText("");
        ui->lineEdit_alley->setText("");
        ui->lineEdit_email->setText("");
        ui->lineEdit_street->setText("");
        ui->lineEdit_password->setText("");
        ui->lineEdit_postcard->setText("");
        ui->lineEdit_phonenumber->setText("");
        ui->lineEdit_previouspassword->setText("");

    }//end of if contains k
}  //end of function
