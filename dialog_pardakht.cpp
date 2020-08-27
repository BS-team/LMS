#include "dialog_pardakht.h"
#include "ui_dialog_pardakht.h"
#include "dialog_pasword.h"
#include<QString>
#include<random>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include"now_date.h"
#include<QFile>
#include<QTextStream>
#include"dialog_moshakhasats.h"
#include"functiotoexploreesab.h"
#include <QMessageBox>
#include"hesab_node.h"
#include"dialog_password_by_manager.h"
#include"functionToExplorUser.h"
#include"dialog_moshakhasats_by_manager.h"
#include"facilities_for_karbar.h"
#include"usersoptionformanger.h"

int priceInKart=0;

dialog_pardakht::dialog_pardakht(int _manager_or_user,QString _name,QString _lastName,QString _national,QString _phone,QString _email
    ,int birth_day,int birth_month,int birth_year,QString _city,QString _street,QString _alley,QString _postCode,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_pardakht)
{
    ui->setupUi(this);
    ui->second_password->setEchoMode(QLineEdit::Password);

    QPixmap bkgnd("C:/Users/erfan/Documents/ProjectOfTerm2/pardakhtpic.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

    _time=new QTimer();
    _time->setInterval(3000);
    connect(_time,SIGNAL(timeout()),this,SLOT(checkProgressbr()));
    _time->start();

    this->manager_or_user=_manager_or_user;
    this->karbar_name=_name;
    this->karbar_email=_email;
    this->karbar_phone=_phone;
    this->karbar_last_name=_lastName;
    this->karbar_add_city=_city;
    this->karbar_add_street=_street;
    this->karbar_national_code=_national;
    this->karbar_add_alley=_alley;
    this->karbar_add_postCode=_postCode;
    this->karbar_birth_day=birth_day;
    this->karbar_birth_month=birth_month;
    this->karbar_birth_year=birth_year;

    if(manager_or_user==0||manager_or_user==1)
    {
        ui->label_7_price->setText("مبلغ20000 تومان را برای عضویت پرداخت کنید");
    }
    else
    {
        int aa;
        for(karbar_node* tmpp=checkUserInformation();tmpp!=nullptr;tmpp=tmpp->getNext())
        {
            if(tmpp->getData().getNational_code()==this->karbar_national_code)
            {
                aa=tmpp->getData().getMojodi();
                break;
            }
        }
        ui->label_7_price->setText("پرداخت کنید  "+QString::number(20000-aa)+" برای تمدیدعضویت در کتاب خانه ");
        priceInKart=20000-aa;
    }

    this->setWindowTitle("درگاه پرداخت");

    for(int i=1396;i<1410;i++)
        ui->comboBox->addItem(QString::number(i));

    srand(time(0));
    QString s;
    int a=0;
    int b;
    int sss=0;
    for(int i=0;i<5;i+=1)
    {
        if(sss==0)
        {
            while(1)
            {
                b=rand()%10;
                if(b!=0)
                    break;
            }
            a=a*10+b;
            sss++;
        }
        else
        {
            a=a*10+rand()%10;
        }
    }
    s=QString::number(a);
    QString ss;
    int j=0;
    for(int i=0;i<10;i+=2)
    {
        ss[i]=s[j];
        j++;
        ss[i+1]=' ';
    }
    this->ui->sure->setText(ss);
}


dialog_pardakht::~dialog_pardakht()
{
    delete ui;
}


Ui::dialog_pardakht *dialog_pardakht::getUi()
{
    return ui;
}

int checkRamzAndCVV2(QString s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>57||s[i]<48)
            return 1;
    }
    return 0;
}

int checkrobat(QString s1,QString s2)
{
    int j=0;
    if(s1=="")
        return 0;
    if(s1.length()*2!=s2.length())
        return 0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[j])
            return 0;
        j+=2;
    }
    return 1;
}

void dialog_pardakht::on_buttonBox_accepted()
{
   if(ui->number_of_creditcard->text()=="")
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت را پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text().count()!=16)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[0]>57 || ui->number_of_creditcard->text()[0]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[1]>57 || ui->number_of_creditcard->text()[1]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[2]>57 || ui->number_of_creditcard->text()[2]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[3]>57 || ui->number_of_creditcard->text()[3]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[4]>57 || ui->number_of_creditcard->text()[4]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[5]>57 || ui->number_of_creditcard->text()[5]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[6]>57 || ui->number_of_creditcard->text()[6]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[7]>57 || ui->number_of_creditcard->text()[7]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[8]>57 || ui->number_of_creditcard->text()[8]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[9]>57 || ui->number_of_creditcard->text()[9]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[10]>57 || ui->number_of_creditcard->text()[10]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[11]>57 || ui->number_of_creditcard->text()[11]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[12]>57 || ui->number_of_creditcard->text()[12]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[13]>57 || ui->number_of_creditcard->text()[13]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[14]>57 || ui->number_of_creditcard->text()[14]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->number_of_creditcard->text()[15]>57 || ui->number_of_creditcard->text()[15]<48)
   {
       QMessageBox::information(this,"خطا","فیلد شماره کارت رابه درستی پرکنید",QMessageBox::Ok);
   }
   else if(ui->CVV2->text()=="")
   {
       QMessageBox::information(this,"خطا","فیلد سی وی وی 2 کارت را پرکنید",QMessageBox::Ok);
   }
   else if(checkRamzAndCVV2(ui->CVV2->text()))
   {
       QMessageBox::information(this,"خطا","فیلد سی وی وی 2 کارت را به درستی پرکنید",QMessageBox::Ok);
   }
   else if(checkRamzAndCVV2(ui->second_password->text()))
   {
       QMessageBox::information(this,"خطا","فیلد رمز دوم کارت را به درستی پرکنید",QMessageBox::Ok);
   }
   else
   {
       int k=0;
       hesab_node* tmp1=checkEtelatHesab();
       for(hesab_node* tmp=checkEtelatHesab();tmp!=nullptr;tmp=tmp->getNext())
       {
           if(tmp->getData().getSecond_password()==ui->second_password->text()&&tmp->getData().getCvv2()==ui->CVV2->text() && tmp->getData().getNumber_of_creditcard()==ui->number_of_creditcard->text()
                   && tmp->getData().getExpiration().getYear()==ui->comboBox->currentText().toInt() && tmp->getData().getExpiration().getMonth()==ui->month->text().toInt())
           {
               if(checkrobat(ui->robat->text(),ui->sure->text()))
               {
                   if(tmp->getData().getExpiration().getYear()==ui->comboBox->currentText().toInt()
                           && tmp->getData().getExpiration().getMonth()==ui->month->text().toInt())
                   {
                       if((tmp->getData().getMojodiHesab().toInt()>20000 && this->manager_or_user==1)||
                             (tmp->getData().getMojodiHesab().toInt()>20000 && this->manager_or_user==0)||
                               (tmp->getData().getMojodiHesab().toInt()>priceInKart && this->manager_or_user==2)) //bug
                       {
                           k=1;
                           QFile fil("C:/Users/erfan/Documents/ProjectOfTerm2/etelaateEsabBanki.txt");
                           fil.open(QIODevice::WriteOnly);
                           QTextStream stream(&fil);
                           stream.setCodec("UTF-8");
                           for(;tmp1!=nullptr;tmp1=tmp1->getNext())
                           {
                               if(tmp1->getData().getNumber_of_creditcard()==tmp->getData().getNumber_of_creditcard())
                               {
                                   hesab hsb;
                                   hsb.setCvv2(tmp1->getData().getCvv2());
                                   hsb.setSecond_password(tmp1->getData().getSecond_password());
                                   hsb.setExpiration(tmp1->getData().getExpiration());
                                   hsb.setNumber_of_creditcard(tmp1->getData().getNumber_of_creditcard());
                                   hsb.setNameOfOwner(tmp1->getData().getNameOfOwner());
                                   long long int aa=tmp1->getData().getMojodiHesab().toInt();
                                   if(this->manager_or_user==1 || this->manager_or_user==0)
                                       aa-=20000;
                                   else if(this->manager_or_user==2)
                                   {
                                        for(karbar_node* tmp5=checkUserInformation();tmp5!=nullptr;tmp5=tmp5->getNext())
                                        {
                                            if(tmp5->getData().getNational_code()==this->karbar_national_code)
                                            {
                                                aa-=20000-tmp5->getData().getMojodi();
                                                break;
                                            }
                                        }
                                   }
                                   hsb.setMojodiHesab(QString::number(aa));
                                   tmp1->setData(hsb);
                               }

                               stream<<tmp1->getData().getNumber_of_creditcard()<<"\t";
                               stream<<tmp1->getData().getSecond_password()<<"\t";
                               stream<<tmp1->getData().getCvv2()<<"\t";
                               stream<<tmp1->getData().getNameOfOwner()<<"\t";
                               stream<<tmp1->getData().getExpiration().getMonth()<<"\t";
                               stream<<tmp1->getData().getExpiration().getYear()<<"\t";
                               stream<<tmp1->getData().getMojodiHesab()<<"\n";
                           }
                           fil.close();

                           ui->progressBar->setValue(0);
                           _time->stop();

                           break;
                       }
                   }
               }
           }
       }

       if(k==1)
       {
           if(this->manager_or_user==1)
           {
               this->close();
               Dialog_pasword* pas=new Dialog_pasword();
               pas->show();
               connect(pas,SIGNAL(pass(QString)),this,SLOT(writing_in_fil(QString)));
           }
           else if(this->manager_or_user==0)
           {
               this->close();
               Dialog_password_by_manager* pas=new Dialog_password_by_manager();
               pas->show();
               connect(pas,SIGNAL(ret_pass_manger(QString)),this,SLOT(writing_in_fil(QString)));
           }
           else if(this->manager_or_user==2)
           {
               karbar_node* tmp10=checkUserInformation();
               QFile fileee("C:/Users/erfan/Documents/ProjectOfTerm2/karbarInformation.txt");
               fileee.open(QIODevice::WriteOnly);
               QTextStream stream10(&fileee);
               stream10.setCodec("UTF-8");
               for(;tmp10!=nullptr;tmp10=tmp10->getNext())
               {
                   if(tmp10->getData().getNational_code()==this->karbar_national_code)
                   {
                       stream10
                           <<tmp10->getData().getName() << "\t"
                           <<tmp10->getData().getFamily() << "\t"
                           <<tmp10->getData().getNational_code() << "\t"
                           <<tmp10->getData().getPassword()<<"\t"
                           <<tmp10->getData().getPhone() << "\t"
                           <<tmp10->getData().getEmail()<<"\t"
                           <<tmp10->getData().getBirth().getDay()<<"\t"
                           <<tmp10->getData().getBirth().getMonth()<<"\t"
                           <<tmp10->getData().getBirth().getYear()<<"\t"
                           <<date_now().getDay()<<"\t"
                           <<date_now().getMonth()<<"\t"
                           <<date_now().getYear()<<"\t"
                           <<tmp10->getData().getAddress().getCity() << "\t"
                           <<tmp10->getData().getAddress().getStreet() << "\t"
                           <<tmp10->getData().getAddress().getAlley()<< "\t"
                           <<tmp10->getData().getAddress().getPostcode()<<"\t"
                           <<"13000"<<"\n";
                   }
                   else
                   {
                       stream10
                           <<tmp10->getData().getName() << "\t"
                           <<tmp10->getData().getFamily() << "\t"
                           <<tmp10->getData().getNational_code() << "\t"
                           <<tmp10->getData().getPassword()<<"\t"
                           <<tmp10->getData().getPhone() << "\t"
                           <<tmp10->getData().getEmail()<<"\t"
                           <<tmp10->getData().getBirth().getDay()<<"\t"
                           <<tmp10->getData().getBirth().getMonth()<<"\t"
                           <<tmp10->getData().getBirth().getYear()<<"\t"
                           <<tmp10->getData().getEnter().getDay()<<"\t"
                           <<tmp10->getData().getEnter().getMonth()<<"\t"
                           <<tmp10->getData().getEnter().getYear()<<"\t"
                           <<tmp10->getData().getAddress().getCity() << "\t"
                           <<tmp10->getData().getAddress().getStreet() << "\t"
                           <<tmp10->getData().getAddress().getAlley()<< "\t"
                           <<tmp10->getData().getAddress().getPostcode()<<"\t"
                           <<tmp10->getData().getMojodi()<<"\n";
                   }
               }
               this->close();
               facilities_for_karbar* ffk=new facilities_for_karbar(this->karbar_national_code);
               ffk->show();
           }
           ui->progressBar->setValue(0);
           _time->stop();
       }

       else
       {
           QString s;
           int a=0;
           int b;
           int sss=0;
           for(int i=0;i<5;i+=1)
           {
               if(sss==0)
               {
                   while(1)
                   {
                       b=rand()%10;
                       if(b!=0)
                           break;
                   }
                   a=a*10+b;
                   sss++;
               }
               else
               {
                   a=a*10+rand()%10;
               }
           }
           s=QString::number(a);
           QString ss;
           int j=0;
           for(int i=0;i<10;i+=2)
           {
               ss[i]=s[j];
               j++;
               ss[i+1]=' ';
           }
           this->ui->sure->setText(ss);
       }
   }
}

void dialog_pardakht::on_buttonBox_rejected()
{
    ui->progressBar->setValue(0);
    _time->stop();
    if(manager_or_user==0)
    {
        this->close();
        Dialog_moshakhasats_by_manager* dlgmsh=new Dialog_moshakhasats_by_manager();
        dlgmsh->show();
    }
    else if(manager_or_user==1)
    {
        this->close();
        Dialog_moshakhasats* dlgmsh=new Dialog_moshakhasats();
        dlgmsh->show();
    }
    else if(manager_or_user==2)
    {
        this->close();
        facilities_for_karbar* dlgmsh=new facilities_for_karbar(this->karbar_national_code);
        dlgmsh->show();
    }
}

void dialog_pardakht::writing_in_fil(QString ps)
{
    date now1=date_now();
    QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/karbarInformation.txt");
    file.open(QIODevice::Append);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    stream
     <<this->karbar_name << "\t"
     <<this->karbar_last_name << "\t"
     <<this->karbar_national_code << "\t"
     <<ps<<"\t"
     <<this->karbar_phone << "\t"
     <<this->karbar_email<<"\t"
     <<this->karbar_birth_day<<"\t"
     <<this->karbar_birth_month<<"\t"
     <<this->karbar_birth_year<<"\t"
     <<now1.getDay()<<"\t"
     <<now1.getMonth()<<"\t"
     <<now1.getYear()<<"\t"
     <<this->karbar_add_city << "\t"
     <<this->karbar_add_street<< "\t"
     <<this->karbar_add_alley<< "\t"
     <<this->karbar_add_postCode<<"\t"
     <<"13000"<<"\n";

    file.close();

    this->close();
}


void dialog_pardakht::checkProgressbr()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
    if(ui->progressBar->value()==100)
    {
        if(manager_or_user==1)
        {
            this->close();
            login_page* dms=new login_page();
            dms->show();
        }
        else if(manager_or_user==0)
        {
            this->close();
            usersoptionformanger* dms=new usersoptionformanger();
            dms->show();
        }
        else if(manager_or_user==2)
        {
            this->close();
            facilities_for_karbar* fdm=new facilities_for_karbar(this->karbar_national_code);
            fdm->show();
        }
        ui->progressBar->setValue(0);
        _time->stop();
    }
}
