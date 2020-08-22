#include "usersoptionformanger.h"
#include "ui_usersoptionformanger.h"
#include"manger_facility.h"
#include<QHBoxLayout>
#include"functionToExplorUser.h"
#include<QFile>
#include<QTextStream>
#include"dialog_moshakhasats.h"
#include"dialog_pasword.h"
#include"dialog_moshakhasats_by_manager.h"
#include"checkforsearch_book_user.h"
#include"now_date.h"
#include"functioforgharzandpassofbook.h"
int num1=0;

usersoptionformanger::usersoptionformanger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usersoptionformanger)
{
    ui->setupUi(this);

    ui->comb_search->addItem("nationalCode");
    ui->comb_search->addItem("password");
    ui->comb_search->addItem("name");
    ui->comb_search->addItem("lastname");
    ui->comb_search->addItem("email");
    ui->comb_search->addItem("entry date");
    ui->comb_search->addItem("birth date");
    ui->comb_search->addItem("address");
    ui->comb_search->addItem("phone number");

    ui->comboBox_addresss->addItem("city");
    ui->comboBox_addresss->addItem("street");
    ui->comboBox_addresss->addItem("alley");
    ui->comboBox_addresss->addItem("postcode");

    ui->comboBox_birthdate->addItem("day");
    ui->comboBox_birthdate->addItem("month");
    ui->comboBox_birthdate->addItem("year");

    ui->comboBox_entrydate->addItem("day");
    ui->comboBox_entrydate->addItem("month");
    ui->comboBox_entrydate->addItem("year");

    ui->comboBox_addresss->hide();
    ui->comboBox_birthdate->hide();
    ui->comboBox_entrydate->hide();

    QStringList my_list;
    ui->tableWidget->setColumnCount(12);
    my_list<<"Name"<<"lastname"<<"phone number"<<"emial address"<<"birthdate"<<"entry date"<<"home address"<<"national code"<<"password"<<"mojodi"<<"remove"<<"edite";
    ui->tableWidget->setHorizontalHeaderLabels(my_list);
    QPalette pal = palette();
    // set black background
    pal.setColor(QPalette::Background, Qt::yellow);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowTitle("Users option For Manager");

    int num=0;
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        num++;

    checkBox2=new QCheckBox*[num];
    for(int i=0;i<num;i++)                    //for edit
        checkBox2[i]=new QCheckBox () ;

    checkBox3=new QCheckBox*[num];
    for(int i=0;i<num;i++)                    //for remove 2
        checkBox3[i]=new QCheckBox () ;

    checkCheckBox=new int[num];
    for(int i=0;i<num;i++)
        checkCheckBox[i]=0;

    checkRemove=new int[num];
    for(int i=0;i<num;i++)
        checkRemove[i]=0;

    for(int i=ui->tableWidget->rowCount();i>=0;i--)
        ui->tableWidget->removeRow(i);

    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
       if(tmp->getData().getPassword()!="")
       {
           ui->tableWidget->insertRow(ui->tableWidget->rowCount());

           QTableWidgetItem *item = new QTableWidgetItem(tmp->getData().getName());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,item);
           item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item1 = new QTableWidgetItem(tmp->getData().getFamily());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,item1);
           item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item2 = new QTableWidgetItem(tmp->getData().getPhone());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,item2);
           item2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item3 = new QTableWidgetItem(tmp->getData().getEmail());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,item3);
           item3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(tmp->getData().getBirth().getDay())+'/'+QString::number(tmp->getData().getBirth().getMonth())+'/'+QString::number(tmp->getData().getBirth().getYear()));
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,item4);
           item4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(tmp->getData().getEnter().getDay())+'/'+QString::number(tmp->getData().getEnter().getMonth())+'/'+QString::number(tmp->getData().getEnter().getYear()));
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,item5);
           item5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item6 = new QTableWidgetItem(tmp->getData().getAddress().getCity()+'/'+tmp->getData().getAddress().getStreet()+'/'+tmp->getData().getAddress().getAlley()+'/'+tmp->getData().getAddress().getPostcode());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,item6);
           item6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item7 = new QTableWidgetItem(tmp->getData().getNational_code());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,item7);
           item7->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item8 = new QTableWidgetItem(tmp->getData().getPassword());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8,item8);
           item8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QTableWidgetItem *item9 = new QTableWidgetItem(QString::number(tmp->getData().getMojodi()));
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,9,item9);
           item9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

           QWidget *checkBoxWidget3 = new QWidget();
           QHBoxLayout *layoutCheckBox3 = new QHBoxLayout(checkBoxWidget3); // create a layer with reference to the widget
           layoutCheckBox3->addWidget(checkBox3[ui->tableWidget->rowCount()-1]);            // Set the checkbox in the layer
           layoutCheckBox3->setAlignment(Qt::AlignCenter);  // Center the checkbox
           layoutCheckBox3->setContentsMargins(0,0,0,0);    // Set the zero padding
           ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,10, checkBoxWidget3);

           QWidget *checkBoxWidget2 = new QWidget();
           QHBoxLayout *layoutCheckBox2 = new QHBoxLayout(checkBoxWidget2); // create a layer with reference to the widget
           layoutCheckBox2->addWidget(checkBox2[ui->tableWidget->rowCount()-1]);            // Set the checkbox in the layer
           layoutCheckBox2->setAlignment(Qt::AlignCenter);  // Center the checkbox
           layoutCheckBox2->setContentsMargins(0,0,0,0);    // Set the zero padding
           ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,11, checkBoxWidget2);
       }
    }

    for(int i=0;i<num;i++)
        connect(checkBox2[i],SIGNAL(stateChanged(int)),this,SLOT(checkEdit(int)));

    connect(ui->search,SIGNAL(textChanged(QString)),this,SLOT(searchExplor(QString)));

    connect(ui->comb_search,SIGNAL(activated(int)),this,SLOT(showcomb(int)));
}

usersoptionformanger::~usersoptionformanger()
{
    delete ui;
}

Ui::usersoptionformanger *usersoptionformanger::getUi()
{
    return  ui;
}

void usersoptionformanger::on_pushButton_2_clicked()  //back
{
    this->close();
    manger_facility* mngf=new manger_facility();
    mngf->show();
}

int checktablefiling(usersoptionformanger* usfm)
{
    int num=0,k=0;
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getNational_code()!="")
        {
            QString s1=usfm->getUi()->tableWidget->item(num,0)->text();
            QString s2=usfm->getUi()->tableWidget->item(num,1)->text();
            QString s3=usfm->getUi()->tableWidget->item(num,2)->text();
            QString s4=usfm->getUi()->tableWidget->item(num,3)->text();
            QString s5=usfm->getUi()->tableWidget->item(num,4)->text();
            QString s6=usfm->getUi()->tableWidget->item(num,5)->text();
            QString s7=usfm->getUi()->tableWidget->item(num,6)->text();
            QString s8=usfm->getUi()->tableWidget->item(num,7)->text();
            QString s9=usfm->getUi()->tableWidget->item(num,8)->text();
            QString s10=usfm->getUi()->tableWidget->item(num,9)->text();


            if(s1=="")
            {
                QMessageBox::information(usfm,"failed","fill name of user in row" + QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s2=="")
            {
                QMessageBox::information(usfm,"failed","fill lastname of user in row"+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s3=="")
            {
                QMessageBox::information(usfm,"failed","fill phone number of user in row"+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s4=="")
            {
                QMessageBox::information(usfm,"failed","fill email of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s5=="")
            {
                QMessageBox::information(usfm,"failed","fill birth date of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s6=="")
            {
                QMessageBox::information(usfm,"failed","fill entry date of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s7=="")
            {
                QMessageBox::information(usfm,"failed","fill address of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s8=="")
            {
                QMessageBox::information(usfm,"failed","fill national code of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s9=="")
            {
                QMessageBox::information(usfm,"failed","fill password of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }
            else if(s10=="")
            {
                QMessageBox::information(usfm,"failed","fill inventory of user in row "+ QString::number(num+1),QMessageBox::Ok);
                k=1;
                break;
            }


            for(int i=0;i<s1.length();i++)
            {
                if(s1[i]<65||s1[i]>123||(s1[i]>91&&s1[i]<97))
                {
                    QMessageBox::information(usfm,"failed","fill name of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;

            for(int i=0;i<s2.length();i++)
            {
                if(s2[i]<65||s2[i]>123||(s2[i]>91&&s2[i]<97))
                {
                    QMessageBox::information(usfm,"failed","fill lastname of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;

            for(int i=0;i<s3.length();i++)
            {
                if(s3[i]>57||s3[i]<48 || s3.length()!=11)
                {
                    QMessageBox::information(usfm,"failed","fill phone number of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;

            date d_birth;
            QString s_day="\0",s_month="\0",s_year="\0";
            int t=0,tt=0;;
            for(int i=0;i<s5.length();i++)
            {
                if(s5[i]!='/')
                {
                    if(tt==0)
                    {
                        s_day[t]=s5[i];
                        t++;
                    }
                    else if(tt==1)
                    {
                        s_month[t]=s5[i];
                        t++;
                    }
                    else if(tt==2)
                    {
                        s_year[t]=s5[i];
                        t++;
                    }
                    if(s5[i]<48||s5[i]>57)
                    {
                        k=1;
                        QMessageBox::information(usfm,"failed","fill the birth date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                        break;
                    }
                }
                else
                {

                    tt++,t=0;
                }
            }

            if(s_year.length()!=4)
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the birth date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }
            if(k==1)
                break;
            d_birth.setDay(s_day.toUInt());
            d_birth.setMonth(s_month.toUInt());
            d_birth.setYear(s_year.toUInt());

            if(s_day.toUInt()>31 || s_month.toInt()>12 ||s_day.toUInt()<1 || s_month.toInt()<1)
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the birth date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }

            if(d_birth>date_now())
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the birth date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }

            date d_enter;
            s_day="\0",s_month="\0",s_year="\0";
            t=0,tt=0;;
            for(int i=0;i<s6.length();i++)
            {
                if(s6[i]!='/')
                {
                    if(tt==0)
                    {
                        s_day[t]=s6[i];
                        t++;
                    }
                    else if(tt==1)
                    {
                        s_month[t]=s6[i];
                        t++;
                    }
                    else if(tt==2)
                    {
                        s_year[t]=s6[i];
                        t++;
                    }
                    if(s6[i]<48||s6[i]>57)
                    {
                        k=1;
                        QMessageBox::information(usfm,"failed","fill the birth date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                        break;
                    }
                }
                else
                {

                    tt++,t=0;
                }
            }

            if(s_day.toUInt()>31 || s_month.toInt()>12 ||s_day.toUInt()<1 || s_month.toInt()<1)
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the entry date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }

            if(s_year.length()!=4)
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the entry date of book correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }
            if(k==1)
                break;
            d_enter.setDay(s_day.toUInt());
            d_enter.setMonth(s_month.toUInt());
            d_enter.setYear(s_year.toUInt());

            if(d_birth>date_now())
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the entry date of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }

            int tedad=0;
            for(int i=0;i<s7.length();i++)
            {
                if(s7[i]=='/')
                {
                    if(s7[i-1]=='/' ||s7[i+1]=='/' || i==0 || i==s7.length()-1)
                    {
                        k=1;
                        QMessageBox::information(usfm,"failed","fill the address of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                        break;
                    }
                    tedad++;
                }
                else
                {
                    if(s7[i]<65 || s7[i]>123 || (s7[i]<97&&s7[i]>91))
                    {
                        if(s7[i]!=' ' && tedad!=3)
                        {
                            if(tedad==3)
                            {
                                k=1;
                                QMessageBox::information(usfm,"failed","fill the address of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                                break;
                            }
                        }
                    }
                }
            }
            if(tedad!=3)
            {
                k=1;
                QMessageBox::information(usfm,"failed","fill the address of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                break;
            }
            if(k==1)
                break;

            for(int i=0;i<s8.length();i++)
            {
                if(s8[i]>57||s8[i]<48 || s8.length()!=10)
                {
                    QMessageBox::information(usfm,"failed","fill national code of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;


            int ii=0;
            for(karbar_node* tmp1=checkUserInformation();tmp1!=nullptr;tmp1=tmp1->getNext())
            {
                if(tmp1->getData().getNational_code()==s8)
                {
                    if(ii!=num)
                    {
                        QMessageBox::information(usfm,"failed","this national code has saved befor in row "+QString::number(num+1),QMessageBox::Ok);
                        k=1;
                        break;
                    }
                }
                ii++;
            }


            for(int i=0;i<s9.length();i++)
            {
                if(s9[i]>57||s9[i]<48 ||s9[i]>123||(s9[i]>91&&s9[i]<97) ||(s9[i]>57&&s9[i]<65)||s9.length()<8)
                {
                    QMessageBox::information(usfm,"failed","fill password of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;

            ii=0;
            for(karbar_node* tmp1=checkUserInformation();tmp1!=nullptr;tmp1=tmp1->getNext())
            {
                if(tmp1->getData().getPassword()==s9)
                {
                    if(ii!=num)
                    {
                        QMessageBox::information(usfm,"failed","this password has saved befor in row "+QString::number(num+1),QMessageBox::Ok);
                        k=1;
                        break;
                    }
                }
                ii++;
            }

            for(int i=0;i<s10.length();i++)
            {
                if(s10[i]>57||s10[i]<48)
                {
                    QMessageBox::information(usfm,"failed","fill inventory of user correctly in row "+QString::number(num+1),QMessageBox::Ok);
                    k=1;
                    break;
                }
            }

            num++;
        }
    }

    if(k==1)
        return 0;
    else
        return 1;

}

void usersoptionformanger::on_pushButton_clicked()  //set change
{
    int num=0;
    if(checktablefiling(this))
    {
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            num++;

        num1=num;
        karbar_node* tmp10=checkUserInformation();
        QFile("C:/Users/albaloo/Documents/ProjectOfTerm2/karbarInformation.txt").remove();

        int tt=0;
        QString dd;
        karbar_node* tmp5,*tmp7;
        int l=0;
        karbar_node* tmp6;
        karbar one_karbar;
        date da,da2;
        address add;

        int jj=0;

        for(int i=0;i<num;i++)       //read from table
        {
            if(!checkBox3[i]->isChecked())
            {
                tmp5=new karbar_node();
                one_karbar.setName(ui->tableWidget->item(tt,0)->text());
                one_karbar.setFamily(ui->tableWidget->item(tt,1)->text());
                one_karbar.setPhone(ui->tableWidget->item(tt,2)->text());
                one_karbar.setEmail(ui->tableWidget->item(tt,3)->text());
                QString ss=ui->tableWidget->item(tt,4)->text(),ss1,ss2,ss3;
                int t=0,t1=0;
                for(int i=0;i<ss.length();i++)
                {
                    if(t==0)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss1[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==1)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss2[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==2)
                    {
                        ss3[t1]=ss[i];
                        t1++;
                    }
                }
                da.setDay(ss1.toInt());
                da.setMonth(ss2.toInt());
                da.setYear(ss3.toInt());
                one_karbar.setBirth(da);
                ss=ui->tableWidget->item(tt,5)->text(),ss1="\0",ss2="\0",ss3="\0";
                t=0,t1=0;
                for(int i=0;i<ss.length();i++)
                {
                    if(t==0)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss1[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==1)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss2[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==2)
                    {
                        ss3[t1]=ss[i];
                        t1++;
                    }
                }
                da2.setDay(ss1.toInt());
                da2.setMonth(ss2.toInt());
                da2.setYear(ss3.toInt());
                one_karbar.setEntery(da2);
                QString ss4="\0";
                t=0,t1=0;
                ss=ui->tableWidget->item(tt,6)->text(),ss1="",ss2="",ss3="";
                for(int i=0;i<ss.length();i++)
                {
                    if(t==0)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss1[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==1)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss2[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==2)
                    {
                        if(ss[i]=='/')
                        {
                            t++;
                            t1=0;
                        }
                        else
                        {
                            ss3[t1]=ss[i];
                            t1++;
                        }
                    }
                    else if(t==3)
                    {
                        ss4[t1]=ss[i];
                        t1++;
                    }
                }
                add.setCity(ss1);
                add.setStreet(ss2);
                add.setAlley(ss3);
                add.setPostcode(ss4);
                one_karbar.setAddress(add);
                one_karbar.setNational_code(ui->tableWidget->item(tt,7)->text());
                one_karbar.setPassword(ui->tableWidget->item(tt,8)->text());
                one_karbar.setMojodi(ui->tableWidget->item(tt,9)->text().toInt());
                tmp5->setData(one_karbar);
                if(l==0)
                {
                    tmp7=tmp6=tmp5;
                    l++;
                }
                else
                {
                    tmp7->setNext(tmp5);
                    tmp7=tmp5;
                }
                jj++;
                if(tmp10->getData().getNational_code()!=tmp5->getData().getNational_code())
                {
                    book_gharz_pass_node* tmp12=checkBookgharzandpass();
                    QFile fi("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
                    fi.open(QIODevice::WriteOnly);
                    QTextStream stream2(&fi);
                    stream2.setCodec("UTF-8");
                    for(;tmp12!=nullptr;tmp12=tmp12->getNext())
                    {
                        if(tmp12->getData().getNational_gharzgirande()==tmp10->getData().getNational_code())
                        {
                            stream2<<tmp5->getData().getNational_code()<<"\t";
                            stream2<<tmp12->getData().getCode_of_book()<<"\t";
                            stream2<<tmp12->getData().getSefaresh().getDay()<<"\t";
                            stream2<<tmp12->getData().getSefaresh().getMonth()<<"\t";
                            stream2<<tmp12->getData().getSefaresh().getYear()<<"\t";
                            stream2<<tmp12->getData().getGharz().getDay()<<"\t";
                            stream2<<tmp12->getData().getGharz().getMonth()<<"\t";
                            stream2<<tmp12->getData().getGharz().getYear()<<"\t";
                            stream2<<tmp12->getData().getPass().getDay()<<"\t";
                            stream2<<tmp12->getData().getPass().getMonth()<<"\t";
                            stream2<<tmp12->getData().getPass().getYear()<<"\t";
                            stream2<<tmp12->getData().getTimeOfjarime().getDay()<<"\t";
                            stream2<<tmp12->getData().getTimeOfjarime().getMonth()<<"\t";
                            stream2<<tmp12->getData().getTimeOfjarime().getYear()<<"\n";
                        }
                        else
                        {
                            stream2<<tmp12->getData().getNational_gharzgirande()<<"\t";
                            stream2<<tmp12->getData().getCode_of_book()<<"\t";
                            stream2<<tmp12->getData().getSefaresh().getDay()<<"\t";
                            stream2<<tmp12->getData().getSefaresh().getMonth()<<"\t";
                            stream2<<tmp12->getData().getSefaresh().getYear()<<"\t";
                            stream2<<tmp12->getData().getGharz().getDay()<<"\t";
                            stream2<<tmp12->getData().getGharz().getMonth()<<"\t";
                            stream2<<tmp12->getData().getGharz().getYear()<<"\t";
                            stream2<<tmp12->getData().getPass().getDay()<<"\t";
                            stream2<<tmp12->getData().getPass().getMonth()<<"\t";
                            stream2<<tmp12->getData().getPass().getYear()<<"\t";
                            stream2<<tmp12->getData().getTimeOfjarime().getDay()<<"\t";
                            stream2<<tmp12->getData().getTimeOfjarime().getMonth()<<"\t";
                            stream2<<tmp12->getData().getTimeOfjarime().getYear()<<"\n";
                        }
                    }
                    fi.close();
                }
            }
            tmp10=tmp10->getNext();
            tt++;
        }

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


        book_gharz_pass_node* tmp13=checkBookgharzandpass();
        QFile filee("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
        filee.open(QIODevice::WriteOnly);
        QTextStream stream3(&filee);
        stream3.setCodec("UTF-8");
        int k=0;
        for(;tmp13!=nullptr;tmp13=tmp13->getNext())
        {
            for(karbar_node* tmp14=checkUserInformation();tmp14!=nullptr;tmp14=tmp14->getNext())
            {
                if(tmp14->getData().getNational_code()==tmp13->getData().getNational_gharzgirande())
                {
                    k=1;
                    break;
                }
            }
            if(k==1)
            {
                stream3<<tmp13->getData().getNational_gharzgirande()<<"\t";
                stream3<<tmp13->getData().getCode_of_book()<<"\t";
                stream3<<tmp13->getData().getSefaresh().getDay()<<"\t";
                stream3<<tmp13->getData().getSefaresh().getMonth()<<"\t";
                stream3<<tmp13->getData().getSefaresh().getYear()<<"\t";
                stream3<<tmp13->getData().getGharz().getDay()<<"\t";
                stream3<<tmp13->getData().getGharz().getMonth()<<"\t";
                stream3<<tmp13->getData().getGharz().getYear()<<"\t";
                stream3<<tmp13->getData().getPass().getDay()<<"\t";
                stream3<<tmp13->getData().getPass().getMonth()<<"\t";
                stream3<<tmp13->getData().getPass().getYear()<<"\t";
                stream3<<tmp13->getData().getTimeOfjarime().getDay()<<"\t";
                stream3<<tmp13->getData().getTimeOfjarime().getMonth()<<"\t";
                stream3<<tmp13->getData().getTimeOfjarime().getYear()<<"\n";
            }

            k=0;
        }
        filee.close();

        QMessageBox::information(this,"succesful","you changed correctly",QMessageBox::Ok);

        delete [] checkBox2;

        delete [] checkBox3;

//        delete checkCheckBox;


        checkBox2=new QCheckBox*[jj];
        for(int i=0;i<jj;i++)                    //for edit
            checkBox2[i]=new QCheckBox () ;

        checkBox3=new QCheckBox*[jj];
        for(int i=0;i<jj;i++)                    //for remove 2
            checkBox3[i]=new QCheckBox () ;

        checkCheckBox=new int[jj];
        for(int i=0;i<num;i++)
            checkCheckBox[i]=0;

        checkRemove=new int[jj];
        for(int i=0;i<jj;i++)
            checkRemove[i]=0;

        for(int i=ui->tableWidget->rowCount();i>=0;i--)
            ui->tableWidget->removeRow(i);



        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
           if(tmp->getData().getPassword()!="")
           {
               ui->tableWidget->insertRow(ui->tableWidget->rowCount());

               QTableWidgetItem *item = new QTableWidgetItem(tmp->getData().getName());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,item);
               item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item1 = new QTableWidgetItem(tmp->getData().getFamily());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,item1);
               item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item2 = new QTableWidgetItem(tmp->getData().getPhone());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,item2);
               item2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item3 = new QTableWidgetItem(tmp->getData().getEmail());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,item3);
               item3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(tmp->getData().getBirth().getDay())+'/'+QString::number(tmp->getData().getBirth().getMonth())+'/'+QString::number(tmp->getData().getBirth().getYear()));
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,item4);
               item4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(tmp->getData().getEnter().getDay())+'/'+QString::number(tmp->getData().getEnter().getMonth())+'/'+QString::number(tmp->getData().getEnter().getYear()));
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,item5);
               item5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item6 = new QTableWidgetItem(tmp->getData().getAddress().getCity()+'/'+tmp->getData().getAddress().getStreet()+'/'+tmp->getData().getAddress().getAlley()+'/'+tmp->getData().getAddress().getPostcode());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,item6);
               item6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item7 = new QTableWidgetItem(tmp->getData().getNational_code());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,item7);
               item7->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item8 = new QTableWidgetItem(tmp->getData().getPassword());
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8,item8);
               item8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QTableWidgetItem *item9 = new QTableWidgetItem(QString::number(tmp->getData().getMojodi()));
               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,9,item9);
               item9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

               QWidget *checkBoxWidget3 = new QWidget();
               QHBoxLayout *layoutCheckBox3 = new QHBoxLayout(checkBoxWidget3); // create a layer with reference to the widget
               layoutCheckBox3->addWidget(checkBox3[ui->tableWidget->rowCount()-1]);            // Set the checkbox in the layer
               layoutCheckBox3->setAlignment(Qt::AlignCenter);  // Center the checkbox
               layoutCheckBox3->setContentsMargins(0,0,0,0);    // Set the zero padding
               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,10, checkBoxWidget3);

               QWidget *checkBoxWidget2 = new QWidget();
               QHBoxLayout *layoutCheckBox2 = new QHBoxLayout(checkBoxWidget2); // create a layer with reference to the widget
               layoutCheckBox2->addWidget(checkBox2[ui->tableWidget->rowCount()-1]);            // Set the checkbox in the layer
               layoutCheckBox2->setAlignment(Qt::AlignCenter);  // Center the checkbox
               layoutCheckBox2->setContentsMargins(0,0,0,0);    // Set the zero padding
               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,11, checkBoxWidget2);
           }
        }
        for(int i=0;i<jj;i++)
            connect(checkBox2[i],SIGNAL(stateChanged(int)),this,SLOT(checkEdit(int)));

        connect(ui->search,SIGNAL(textChanged(QString)),this,SLOT(searchExplor(QString)));

        connect(ui->comb_search,SIGNAL(activated(int)),this,SLOT(showcomb(int)));
    }
    else
    {
        karbar_node* tmp1=checkUserInformation();
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
            ui->tableWidget->item(i,0)->setText(tmp1->getData().getName());
            ui->tableWidget->item(i,1)->setText(tmp1->getData().getFamily());
            ui->tableWidget->item(i,2)->setText(tmp1->getData().getPhone());
            ui->tableWidget->item(i,3)->setText(tmp1->getData().getEmail());
            ui->tableWidget->item(i,4)->setText(QString::number(tmp1->getData().getBirth().getDay())+'/'+QString::number(tmp1->getData().getBirth().getMonth())+'/'+QString::number(tmp1->getData().getBirth().getYear()));
            ui->tableWidget->item(i,5)->setText(QString::number(tmp1->getData().getEnter().getDay())+'/'+QString::number(tmp1->getData().getEnter().getMonth())+'/'+QString::number(tmp1->getData().getEnter().getYear()));
            ui->tableWidget->item(i,6)->setText(tmp1->getData().getAddress().getCity()+'/'+tmp1->getData().getAddress().getStreet()+'/'+tmp1->getData().getAddress().getAlley()+'/'+tmp1->getData().getAddress().getPostcode());
            ui->tableWidget->item(i,7)->setText(tmp1->getData().getNational_code());
            ui->tableWidget->item(i,8)->setText(tmp1->getData().getPassword());

            tmp1=tmp1->getNext();

            checkBox2[i]->setCheckState(Qt::Unchecked);
            checkBox3[i]->setCheckState(Qt::Unchecked);
        }
    }
}

void usersoptionformanger::checkEdit(int bl)
{
    int num=0;
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        num++;
    for(int i=0;i<num;i++)
    {
        if(checkBox2[i]->isChecked())
        {
            if(checkCheckBox[i]==0)
            {
                for(int j=0;j<9;j++)
                    ui->tableWidget->item(i,j)->setFlags(ui->tableWidget->item(i,j)->flags() ^ Qt::ItemIsEditable);
            }
            checkCheckBox[i]=1;
        }
        else
        {
            if(checkCheckBox[i]==0)
            {
                for(int j=0;j<9;j++)
                {
                   ui->tableWidget->item(i,j)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                }
             }
             checkCheckBox[i]=0;
        }
    }
}

void usersoptionformanger::searchExplor(QString s)
{
    if(ui->search->text()=="")
    {
        int row_num=0;
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
             ui->tableWidget->showRow(row_num);
             for(int i=0;i<10;i++)
                  ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
             row_num++;
        }
    }
    else
    {
        if(ui->comb_search->currentText()=="name")
        {
            int row_num=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getName(),ui->search->text()))
                {
                   ui->tableWidget->showRow(row_num);
                   for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                }
                else
                {
                    ui->tableWidget->hideRow(row_num);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="lastname")
        {
            int row_num=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getFamily(),ui->search->text()))
                {
                   ui->tableWidget->showRow(row_num);
                   for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                }
                else
                {
                    ui->tableWidget->hideRow(row_num);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="nationalCode")
        {
            int row_num=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getNational_code(),ui->search->text()))
                {
                   ui->tableWidget->showRow(row_num);
                   for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                }
                else
                {
                    ui->tableWidget->hideRow(row_num);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="password")
        {
            int row_num=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getPassword(),ui->search->text()))
                {
                   ui->tableWidget->showRow(row_num);
                   for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                }
                else
                {
                    ui->tableWidget->hideRow(row_num);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="birth date")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(ui->comboBox_birthdate->currentText()=="day")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(QString::number(tmp->getData().getBirth().getDay()),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_birthdate->currentText()=="month")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(QString::number(tmp->getData().getBirth().getMonth()),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_birthdate->currentText()=="year")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(QString::number(tmp->getData().getBirth().getYear()),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
            }
        }
        else if(ui->comb_search->currentText()=="address")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(ui->comboBox_addresss->currentText()=="city")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(tmp->getData().getAddress().getCity(),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_addresss->currentText()=="street")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(tmp->getData().getAddress().getStreet(),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_addresss->currentText()=="alley")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(tmp->getData().getAddress().getAlley(),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_addresss->currentText()=="postcode")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(tmp->getData().getAddress().getPostcode(),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
            }
        }
        else if(ui->comb_search->currentText()=="email")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                int row_num=0;
                for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                {
                    if(barresinationalcodeandpas(tmp->getData().getEmail(),ui->search->text()))
                    {
                       ui->tableWidget->showRow(row_num);
                       for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    }
                    else
                    {
                        ui->tableWidget->hideRow(row_num);
                    }
                    row_num++;
                }
            }
        }
        else if(ui->comb_search->currentText()=="phone number")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                int row_num=0;
                for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                {
                    if(barresinationalcodeandpas(tmp->getData().getPhone(),ui->search->text()))
                    {
                       ui->tableWidget->showRow(row_num);
                       for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    }
                    else
                    {
                        ui->tableWidget->hideRow(row_num);
                    }
                    row_num++;
                }
            }
        }
        else if(ui->comb_search->currentText()=="entry date")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(ui->comboBox_entrydate->currentText()=="day")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(QString::number(tmp->getData().getEnter().getDay()),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_entrydate->currentText()=="month")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(QString::number(tmp->getData().getEnter().getMonth()),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<10;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                else if(ui->comboBox_entrydate->currentText()=="year")
                {
                    int row_num=0;
                    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
                    {
                        if(barresinationalcodeandpas(QString::number(tmp->getData().getEnter().getYear()),ui->search->text()))
                        {
                           ui->tableWidget->showRow(row_num);
                           for(int i=0;i<9;i++)
                                ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        }
                        else
                        {
                            ui->tableWidget->hideRow(row_num);
                        }
                        row_num++;
                    }
                }
                row_num++;
            }
        }
    }
}

void usersoptionformanger::showcomb(int n)
{
    if(n==7)
    {
        ui->comboBox_entrydate->hide();
        ui->comboBox_birthdate->hide();
        ui->comboBox_addresss->show();
    }
    else if(n==6)
    {
        ui->comboBox_entrydate->hide();
        ui->comboBox_birthdate->show();
        ui->comboBox_addresss->hide();
    }
    else if(n==5)
    {
        ui->comboBox_entrydate->show();
        ui->comboBox_birthdate->hide();
        ui->comboBox_addresss->hide();
    }
    else
    {
        ui->comboBox_entrydate->hide();
        ui->comboBox_birthdate->hide();
        ui->comboBox_addresss->hide();
    }
    if(ui->search->text()=="")
    {
        int row_num=0;
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
                for(int i=0;i<10;i++)
                     ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
            row_num++;
        }
    }
    else
    {
        if(ui->comb_search->currentText()=="name")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getName(),ui->search->text()))
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    k=1;
                }
                else
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                }
                row_num++;
            }
            row_num--;
        }
        else if(ui->comb_search->currentText()=="lastname")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getFamily(),ui->search->text()))
                {
                    for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    k=1;
                }
                else
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="nationalCode")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getNational_code(),ui->search->text()))
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    k=1;
                }
                else
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="password")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getPassword(),ui->search->text()))
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    k=1;
                }
                else
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="birth date")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(ui->comboBox_birthdate->currentText()=="day")
                {
                    if(barresinationalcodeandpas(QString::number(tmp->getData().getBirth().getDay()),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_birthdate->currentText()=="month")
                {
                    if(barresinationalcodeandpas(QString::number(tmp->getData().getBirth().getMonth()),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_birthdate->currentText()=="year")
                {
                    if(barresinationalcodeandpas(QString::number(tmp->getData().getBirth().getYear()),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="address")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(ui->comboBox_addresss->currentText()=="city")
                {
                    if(barresinationalcodeandpas(tmp->getData().getAddress().getCity(),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_addresss->currentText()=="street")
                {
                    if(barresinationalcodeandpas(tmp->getData().getAddress().getStreet(),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_addresss->currentText()=="alley")
                {
                    if(barresinationalcodeandpas(tmp->getData().getAddress().getAlley(),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_addresss->currentText()=="postcode")
                {
                    if(barresinationalcodeandpas(tmp->getData().getAddress().getPostcode(),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }

                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="email")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getEmail(),ui->search->text()))
                {
                    for(int i=0;i<10;i++)
                     ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    k=1;
                }
                else
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="phone number")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(barresinationalcodeandpas(tmp->getData().getPhone(),ui->search->text()))
                {
                    for(int i=0;i<10;i++)
                     ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                    k=1;
                }
                else
                {
                    for(int i=0;i<10;i++)
                        ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                }
                row_num++;
            }
        }
        else if(ui->comb_search->currentText()=="entry date")
        {
            int row_num=0;
            int k=0;
            for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(ui->comboBox_entrydate->currentText()=="day")
                {
                    if(barresinationalcodeandpas(QString::number(tmp->getData().getEnter().getDay()),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_entrydate->currentText()=="month")
                {
                    if(barresinationalcodeandpas(QString::number(tmp->getData().getEnter().getMonth()),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                else if(ui->comboBox_entrydate->currentText()=="year")
                {
                    if(barresinationalcodeandpas(QString::number(tmp->getData().getEnter().getYear()),ui->search->text()))
                    {
                        for(int i=0;i<10;i++)
                         ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::green);
                        k=1;
                    }
                    else
                    {
                        for(int i=0;i<10;i++)
                            ui->tableWidget->item(row_num,i)->setBackgroundColor(Qt::white);
                    }
                }
                row_num++;
            }
        }
    }

}

void usersoptionformanger::on_pushButton_3_clicked()  //add user
{
    this->close();
    Dialog_moshakhasats_by_manager* moshbymng=new Dialog_moshakhasats_by_manager();
    moshbymng->show();
}
