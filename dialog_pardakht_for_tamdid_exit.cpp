#include "dialog_pardakht_for_tamdid_exit.h"
#include "ui_dialog_pardakht_for_tamdid_exit.h"
#include"facilities_for_karbar.h"
#include"functioforgharzandpassofbook.h"
#include"functionToExplorUser.h"
#include"functiotoexploreesab.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include"now_date.h"
#include"login_page.h"
#include"confirm_of_pardakht_for_exit.h"

dialog_pardakht_for_tamdid_exit::dialog_pardakht_for_tamdid_exit(QString s1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_pardakht_for_tamdid_exit)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/erfan/Documents/ProjectOfTerm2/tamdidexitpic.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->id_loginer=s1;
    for(int i=1396;i<1410;i++)
        ui->year->addItem(QString::number(i));

    ui->month->setMaximum(12);
    ui->month->setMinimum(1);


    this->setWindowTitle("درگاه پرداخت");

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

dialog_pardakht_for_tamdid_exit::~dialog_pardakht_for_tamdid_exit()
{
    delete ui;
}

int Checkrobat(QString s1,QString s2)
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

void dialog_pardakht_for_tamdid_exit::on_buttonBox_accepted()
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
    else
    {
        int k=0;
        hesab_node* tmp=checkEtelatHesab();
        for(;tmp!=nullptr;tmp=tmp->getNext())
        {
            if(tmp->getData().getNumber_of_creditcard()==ui->number_of_creditcard->text())
            {
                if(tmp->getData().getExpiration().getYear()==ui->year->currentText().toInt()
                        &&ui->month->text().toInt()==tmp->getData().getExpiration().getMonth() )
                {
                    if(Checkrobat(ui->robat->text(),ui->sure->text()))
                    {
                        if(tmp->getData().getExpiration().getYear()==ui->year->currentText().toInt()
                                && tmp->getData().getExpiration().getMonth()==ui->month->text().toInt())
                        {
                            this->close();
                            confirm_of_pardakht_for_exit* cnfopfe=new confirm_of_pardakht_for_exit(tmp,this->id_loginer);
                            cnfopfe->show();
                            k=1;
                            break;
                        }
                    }
                }
            }
        }
        if(k!=1)
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

void dialog_pardakht_for_tamdid_exit::on_buttonBox_rejected()
{
    this->close();
    facilities_for_karbar* ffk=new facilities_for_karbar(this->id_loginer);
    ffk->show();
}


void dialog_pardakht_for_tamdid_exit::on_pushButton_back_clicked(){}  //alaki
void dialog_pardakht_for_tamdid_exit::changeInfile(hesab_node *tmp){}  //alaki
void dialog_pardakht_for_tamdid_exit::on_pushButton_finish_clicked(){}  //alaki
