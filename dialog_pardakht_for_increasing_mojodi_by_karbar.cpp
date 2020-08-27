#include "dialog_pardakht_for_increasing_mojodi_by_karbar.h"
#include "ui_dialog_pardakht_for_increasing_mojodi_by_karbar.h"
#include"facilities_for_karbar.h"
#include"hesab_node.h"
#include "functiotoexploreesab.h"
#include<QMessageBox>
#include"now_date.h"
#include<QFile>
#include<QTextStream>
#include"karbar_node.h"
#include"functionToExplorUser.h"

Dialog_pardakht_for_increasing_mojodi_by_karbar::Dialog_pardakht_for_increasing_mojodi_by_karbar(QString ssss,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_pardakht_for_increasing_mojodi_by_karbar)
{
    ui->setupUi(this);
    this->Id_Loginer=ssss;
    ui->second_password->setEchoMode(QLineEdit::Password);

    QPixmap bkgnd("C:/Users/erfan/Documents/ProjectOfTerm2/increasepic.gif");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    _tm=new QTimer();
    _tm->setInterval(3000);
    connect(_tm,SIGNAL(timeout()),this,SLOT(checkedProgressBar()));
    _tm->start();

    for(int i=1000;i<=20000;i+=1000)
        ui->comboBox_2_price->addItem(QString::number(i));
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

Dialog_pardakht_for_increasing_mojodi_by_karbar::~Dialog_pardakht_for_increasing_mojodi_by_karbar()
{
    delete ui;
}

int checkramzAndCVV2(QString s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>57||s[i]<48)
            return 1;
    }
    return 0;
}

int checkRRobat(QString s1,QString s2)
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


void Dialog_pardakht_for_increasing_mojodi_by_karbar::on_buttonBox_accepted()
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
    else if(checkramzAndCVV2(ui->CVV2->text()))
    {
        QMessageBox::information(this,"خطا","فیلد سی وی وی 2 کارت را به درستی پرکنید",QMessageBox::Ok);
    }
    else if(checkramzAndCVV2(ui->second_password->text()))
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
                if(checkRRobat(ui->robat->text(),ui->sure->text()))
                {
                    if(tmp->getData().getExpiration().getYear()==ui->comboBox->currentText().toInt()
                            && tmp->getData().getExpiration().getMonth()==ui->month->text().toInt())
                    {
                        if(tmp->getData().getMojodiHesab().toInt()>ui->comboBox_2_price->currentText().toInt())
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
                                    long long int aa=tmp1->getData().getMojodiHesab().toInt();
                                    aa-=ui->comboBox_2_price->currentText().toInt();
                                    hsb.setMojodiHesab(QString::number(aa));
                                    hsb.setNameOfOwner(tmp1->getData().getNameOfOwner());
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
                            break;
                        }
                    }
                }
            }
        }

        if(k==1)
        {
            QMessageBox::information(this,"موفقیت امیز","موجودی شما افزایش یافت",QMessageBox::Ok);

            karbar_node* tmp1=checkUserInformation();
            karbar_node* tmp6=tmp1;


            for(;tmp1!=nullptr;tmp1=tmp1->getNext())
            {
                if(tmp1->getData().getNational_code()==this->Id_Loginer)
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
                    krb.setMojodi(tmp1->getData().getMojodi()+ui->comboBox_2_price->currentText().toInt());
                    tmp1->setData(krb);
                }
            }

            QFile ("C:/Users/erfan/Documents/ProjectOfTerm2/karbarInformation.txt").remove();
            QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/karbarInformation.txt");
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

            ui->progressBar->setValue(0);
            _tm->stop();

            this->close();
            facilities_for_karbar* fc=new facilities_for_karbar(this->Id_Loginer);
            fc->show();
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

void Dialog_pardakht_for_increasing_mojodi_by_karbar::on_buttonBox_rejected()
{
    ui->progressBar->setValue(0);
    _tm->stop();

    this->close();
    facilities_for_karbar* fcfk=new facilities_for_karbar(this->Id_Loginer);
    fcfk->show();
}

void Dialog_pardakht_for_increasing_mojodi_by_karbar::checkedProgressBar()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
    if(ui->progressBar->value()==100)
    {
        ui->progressBar->setValue(0);
        _tm->stop();

        this->close();
        facilities_for_karbar* fdm=new facilities_for_karbar(this->Id_Loginer);
        fdm->show();
    }
}
