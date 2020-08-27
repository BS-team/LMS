#include "edit_profile_of_manager.h"
#include "ui_edit_profile_of_manager.h"
#include"manger_facility.h"
#include<QFile>
#include<QTextStream>
#include"manager.h"
#include<QMessageBox>
#include"checkpersianstring.h"


edit_profile_of_manager::edit_profile_of_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_profile_of_manager)
{
    ui->setupUi(this);

    ui->lineEdit_prev_spec->setEchoMode(QLineEdit::Password);
    ui->lineEdit_prevusual->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3_speci->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3_speci->setEchoMode(QLineEdit::Password);

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


    QPixmap bkgnd("C:/Users/erfan/Documents/ProjectOfTerm2/profilemanagerpic.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
	
    this->setWindowTitle("تغییرمشخصات");

    QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/mangerInformation.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    manger mng;
    QString s,s1,s2,s3;
    char z;

    while(1)
    {
        stream>>s1;
        s+=s1;

        stream>>z;
        if(z=='\t')
        {
            mng.setName(s);
            s3=s;
            s="\0";
            ui->label_previous_name_2->setText(s3);
            break;
        }
        else if(z=='\0')
            break;
        s+=' ';
    }

    while(1)
    {
        stream>>s1;
        s+=s1;

        stream>>z;
        if(z=='\t')
        {
            mng.setFamily(s);
            s3=s;
            s="\0";
            ui->label_previous_lastname_2->setText(s3);
            break;
        }
        else if(z=='\0')
            break;
        s+=' ';
    }

    stream>>s;
    mng.setPhone(s);
    ui->label_previous_phone_2->setText(s);

    stream>>s;
    mng.setNationlCode(s);
    ui->label_previous_nationalcode_2->setText(s);

    stream>>s;
    mng.setUsual_password(s);

    stream>>s;
    mng.setSpecial_password(s);

    file.close();

    ui->label_6_national->hide();
    ui->label_2_phone->hide();
    ui->label_3_name->hide();
    ui->label_5_usualpass->hide();
    ui->label_specialpass->hide();
    ui->label_prev_spec->hide();
    ui->label_prev_usual->hide();
    ui->lineEdit_prevusual->hide();
    ui->lineEdit_prev_spec->hide();

    ui->label_previous_name->hide();
    ui->label_previous_nationalcode->hide();
    ui->label_previous_phone->hide();

    ui->label_previous_name_2->hide();
    ui->label_previous_nationalcode_2->hide();
    ui->label_previous_phone_2->hide();

    ui->comboBox->addItem("نام خانوادگی");
    ui->comboBox->addItem("نام");
    ui->comboBox->addItem("کد ملی");
    ui->comboBox->addItem("رمز معمولی");
    ui->comboBox->addItem("رمزویژه");
    ui->comboBox->addItem("شماره تلفن");

    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(changemoshmanager(int)));

}

edit_profile_of_manager::~edit_profile_of_manager()
{
    delete ui;
}

Ui::edit_profile_of_manager *edit_profile_of_manager::getUi()
{
    return  ui;
}

void edit_profile_of_manager::on_pushButton_2_clicked()  //back
{
    this->close();
    manger_facility* mngf=new manger_facility();
    mngf->show();
}




void edit_profile_of_manager::changemoshmanager(int n)
{
    if(n==0)
    {
        ui->label_6_national->hide();
        ui->label_3_name->hide();
        ui->label_2_phone->hide();
        ui->label_4_lastname->show();
        ui->label_5_usualpass->hide();
        ui->label_specialpass->hide();
        ui->label_6_national->hide();

        ui->lineEdit_prevusual->hide();
        ui->label_prev_spec->hide();
        ui->lineEdit_prevusual->hide();
        ui->label_prev_usual->hide();

        ui->lineEdit_4_name->hide();
        ui->lineEdit_phone->hide();
        ui->lineEdit_3_speci->hide();
        ui->lineEdit_2_ususal->hide();
        ui->lineEdit_national->hide();
        ui->lineEdit_5_lastname->show();

        ui->label_previous_lastname->show();
        ui->label_previous_name->hide();
        ui->label_previous_nationalcode->hide();
        ui->label_previous_phone->hide();


        ui->label_previous_name_2->hide();
        ui->label_previous_lastname_2->show();
        ui->label_previous_nationalcode_2->hide();
        ui->label_previous_phone_2->hide();



    }
    else if(n==1)
    {
        ui->label_6_national->hide();
        ui->label_3_name->show();
        ui->label_2_phone->hide();
        ui->label_4_lastname->hide();
        ui->label_5_usualpass->hide();
        ui->label_specialpass->hide();
        ui->lineEdit_2_ususal->hide();
        ui->lineEdit_prevusual->hide();
        ui->label_prev_spec->hide();
        ui->lineEdit_prev_spec->hide();
        ui->label_prev_usual->hide();

        ui->lineEdit_4_name->show();
        ui->lineEdit_phone->hide();
        ui->lineEdit_3_speci->hide();
        ui->lineEdit_2_ususal->hide();
        ui->lineEdit_national->hide();
        ui->lineEdit_5_lastname->hide();


        ui->label_previous_lastname->hide();
        ui->label_previous_name->show();
        ui->label_previous_nationalcode->hide();
        ui->label_previous_phone->hide();

        ui->label_previous_name_2->show();
        ui->label_previous_lastname_2->hide();
        ui->label_previous_nationalcode_2->hide();
        ui->label_previous_phone_2->hide();

    }
    else if(n==2)
    {
        ui->label_6_national->show();
        ui->label_3_name->hide();
        ui->label_2_phone->hide();
        ui->label_4_lastname->hide();
        ui->label_5_usualpass->hide();
        ui->label_specialpass->hide();

        ui->lineEdit_prevusual->hide();
        ui->label_prev_spec->hide();
        ui->lineEdit_prev_spec->hide();
        ui->label_prev_usual->hide();

        ui->lineEdit_4_name->hide();
        ui->lineEdit_phone->hide();
        ui->lineEdit_3_speci->hide();
        ui->lineEdit_2_ususal->hide();
        ui->lineEdit_national->show();
        ui->lineEdit_5_lastname->hide();



        ui->label_previous_lastname->hide();
        ui->label_previous_name->hide();
        ui->label_previous_nationalcode->show();
        ui->label_previous_phone->hide();



        ui->label_previous_name_2->hide();
        ui->label_previous_lastname_2->hide();
        ui->label_previous_nationalcode_2->show();
        ui->label_previous_phone_2->hide();


//        ui->lineEdit_prev_spec->text()

    }
    else if(n==3)
    {
        ui->label_6_national->hide();
        ui->label_3_name->hide();
        ui->label_2_phone->hide();
        ui->label_4_lastname->hide();
        ui->label_5_usualpass->show();
        ui->label_specialpass->hide();
        ui->lineEdit_phone->hide();

        ui->lineEdit_prevusual->show();
        ui->label_prev_spec->hide();
        ui->lineEdit_prev_spec->hide();
        ui->label_prev_usual->show();

        ui->lineEdit_4_name->hide();
        ui->lineEdit_phone->hide();
        ui->lineEdit_3_speci->hide();
        ui->lineEdit_2_ususal->show();
        ui->lineEdit_national->hide();
        ui->lineEdit_5_lastname->hide();

        ui->label_previous_lastname->hide();
        ui->label_previous_name->hide();
        ui->label_previous_nationalcode->hide();
        ui->label_previous_phone->hide();


        ui->label_previous_name_2->hide();
        ui->label_previous_lastname_2->hide();
        ui->label_previous_nationalcode_2->hide();
        ui->label_previous_phone_2->hide();

    }
    else if(n==4)
    {
        ui->label_6_national->hide();
        ui->label_3_name->hide();
        ui->label_2_phone->hide();
        ui->label_4_lastname->hide();
        ui->label_5_usualpass->hide();
        ui->label_specialpass->show();

        ui->lineEdit_4_name->hide();
        ui->lineEdit_phone->hide();
        ui->lineEdit_3_speci->show();
        ui->lineEdit_2_ususal->hide();
        ui->lineEdit_national->hide();
        ui->lineEdit_5_lastname->hide();


        ui->lineEdit_prevusual->hide();
        ui->label_prev_spec->show();
        ui->lineEdit_prev_spec->show();
        ui->label_prev_usual->hide();

        ui->label_previous_lastname->hide();
        ui->label_previous_name->hide();
        ui->label_previous_nationalcode->hide();
        ui->label_previous_phone->hide();


        ui->label_previous_name_2->hide();
        ui->label_previous_lastname_2->hide();
        ui->label_previous_nationalcode_2->hide();
        ui->label_previous_phone_2->hide();
    }
    else if(n==5)
    {
        ui->label_6_national->hide();
        ui->label_3_name->hide();
        ui->label_2_phone->show();
        ui->label_4_lastname->hide();
        ui->label_5_usualpass->hide();
        ui->label_specialpass->hide();
        ui->lineEdit_5_lastname->hide();

        ui->lineEdit_prevusual->hide();
        ui->label_prev_spec->hide();
        ui->lineEdit_prev_spec->hide();
        ui->label_prev_usual->hide();

        ui->lineEdit_4_name->hide();
        ui->lineEdit_phone->show();
        ui->lineEdit_3_speci->hide();
        ui->lineEdit_2_ususal->hide();
        ui->lineEdit_national->hide();
        ui->lineEdit_5_lastname->hide();

        ui->label_previous_lastname->hide();
        ui->label_previous_name->hide();
        ui->label_previous_nationalcode->hide();
        ui->label_previous_phone->show();

        ui->label_previous_name_2->hide();
        ui->label_previous_lastname_2->hide();
        ui->label_previous_nationalcode_2->hide();
        ui->label_previous_phone_2->show();

    }
}

int checkmanagermosh(edit_profile_of_manager* epom)
{
    QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/mangerInformation.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    manger mng;
    QString s,s1,s2,s3;
    char z;

    while(1)
    {
        stream>>s1;
        s+=s1;

        stream>>z;
        if(z=='\t')
        {
            mng.setName(s);
            s3=s;
            s="\0";
            break;
        }
        else if(z=='\0')
            break;
        s+=' ';
    }

    while(1)
    {
        stream>>s1;
        s+=s1;

        stream>>z;
        if(z=='\t')
        {
            mng.setFamily(s);
            s3=s;
            s="\0";
            break;
        }
        else if(z=='\0')
            break;
        s+=' ';
    }

    stream>>s;
    mng.setPhone(s);

    stream>>s;
    mng.setNationlCode(s);

    stream>>s;
    mng.setUsual_password(s);

    stream>>s;
    mng.setSpecial_password(s);

    file.close();


    int k=0;
    if(epom->getUi()->lineEdit_national->text()!="")
    {
        QString s1=epom->getUi()->lineEdit_national->text();
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]>57||s1[i]<48)
            {
                k=1;
                QMessageBox::information(epom,"خطا","کدملی قابل قبول نمی باشد",QMessageBox::Ok);
                break;
            }
        }
        if(k==0)
        {
            if(s1.length()!=10)
            {
                k=1;
                QMessageBox::information(epom,"خطا","کدملی قابل قبول نمی باشد",QMessageBox::Ok);

            }
        }
    }

    if(checkPersianStrings(epom->getUi()->lineEdit_4_name->text())==0)
    {
        k=1;
        QMessageBox::information(epom,"خطا","نام شما قابل قبول نمیباشد",QMessageBox::Ok);
    }
    if(checkPersianStrings(epom->getUi()->lineEdit_5_lastname->text())==0)
    {
        k=1;
        QMessageBox::information(epom,"خطا","نام خانوادگی شما قابل قبول نمیباشد",QMessageBox::Ok);
    }

    if(k==0)
    {
        QString s2=epom->getUi()->lineEdit_phone->text();
        if(s2!="")
        {
            for(int i=0;i<s2.length();i++)
            {
                if(s2[i]<48||s2[i]>57)
                {
                    k=1;
                    QMessageBox::information(epom,"خطا","شماره تلفن قابل قبول نمی باشد",QMessageBox::Ok);
                    break;
                }
            }
            if(k==0)
            {
                if(s2.length()!=11)
                {
                    k=1;
                    QMessageBox::information(epom,"خطا","شماره تلفن قابل قبول نمی باشد",QMessageBox::Ok);
                }
            }
        }
        if(k==0)
        {
            QString s3=epom->getUi()->lineEdit_3_speci->text();
            if(s3!="" )
            {
                int l=1;
                if(epom->getUi()->lineEdit_prev_spec->text()!=mng.getSpetial_password())
                {
                    QMessageBox::information(epom,"خطا","رمزعبور ویژه قبلی قابل قبول نمیباشد قابل قبول نمی باشد",QMessageBox::Ok);
                    k=1;
                    l=0;
                }

                int star=0,captal=0,small=0,adad=0;
                if(k==0)
                {
                    if(s3.length()>=10)
                    {
                        for(int i=0;i<s3.length();i++)
                        {
                            if(s3[i]==42)
                            {
                                star=1;
                            }
                            else if(s3[i]>=65&&s3[i]<=91)
                            {
                                captal=1;
                            }
                            else if(s3[i]>=97&&s3[i]<=123)
                            {
                                small=1;
                            }
                            else if(s3[i]>=48&&s3[i]<=57)
                            {
                                adad=1;
                            }
                            else
                            {
                                k=1;
                            }
                        }
                        if(k==1 && l==1)
                        {
                            QMessageBox::information(epom,"خطا","رمز ویژه باید شامل حروف بزرگ وکوچک انگلیسی و حرف ستاره باشد",QMessageBox::Ok);
                        }
                        else if(captal==0)
                        {
                            QMessageBox::information(epom,"خطا","رمز ویژه باید حرف بزرگ داشته باشد",QMessageBox::Ok);
                            k=1;
                        }
                        else if(small==0)
                        {
                            QMessageBox::information(epom,"خطا","رمز ویژه باید حرف کوچک داشته باشد",QMessageBox::Ok);
                            k=1;
                        }
                        else if(star==0)
                        {
                            QMessageBox::information(epom,"خطا","رمز ویژه باید ستاره داشته باشد",QMessageBox::Ok);
                            k=1;
                        }
                        else if(adad==0)
                        {
                            QMessageBox::information(epom,"خطا","رمز ویژه باید عدد داشته باشد",QMessageBox::Ok);
                            k=1;
                        }

                    }
                    else
                    {
                        k=1;
                        QMessageBox::information(epom,"خطا","رمز ویژه باید بیش از 10 کاراکتر باشد",QMessageBox::Ok);
                    }
                }
            }
            if(k==0)
            {
                if(epom->getUi()->lineEdit_2_ususal->text()!="" )
                {
                    if(epom->getUi()->lineEdit_prevusual->text()!=mng.getUsual_password())
                    {
                        QMessageBox::information(epom,"خطا","رمز عادی قبلی وارد شده صحیح نمی باشد",QMessageBox::Ok);
                       k=1;
                    }
                    QString s5=epom->getUi()->lineEdit_2_ususal->text();
                    for(int i=0;i<s5.length();i++)
                    {
                        if((s5[i]<65&&s5[i]>57)||s5[i]<48||(s5[i]>91&&s5[i]<97)||s5[i]>123)
                        {
                            k=1;
                            QMessageBox::information(epom,"خطا","رمز عادی وارد شده قابل قبول نمی باشد",QMessageBox::Ok);
                            break;
                        }
                    }
                    if(k==0)
                    {
                        if(s5.length()<8)
                        {
                            k=1;
                            QMessageBox::information(epom,"خطا","رمزعادی نباید کمتر از 8 کاراکتر باشد",QMessageBox::Ok);
                        }
                    }
                }
            }
        }
    }


    if(k==0)
        return 1;
    else
        return  0;
}

void edit_profile_of_manager::on_pushButton_clicked() //setchange
{
    if(checkmanagermosh(this))
    {
        QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/mangerInformation.txt");
        file.open(QIODevice::ReadOnly);
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        manger mng;
        QString s,s1,s2,s3;
        char z;

        while(1)
        {
            stream>>s1;
            s+=s1;

            stream>>z;
            if(z=='\t')
            {
                mng.setName(s);
                s3=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }

        while(1)
        {
            stream>>s1;
            s+=s1;

            stream>>z;
            if(z=='\t')
            {
                mng.setFamily(s);
                s3=s;
                s="\0";
                break;
            }
            else if(z=='\0')
                break;
            s+=' ';
        }

        stream>>s;
        mng.setPhone(s);

        stream>>s;
        mng.setNationlCode(s);

        stream>>s;
        mng.setUsual_password(s);

        stream>>s;
        mng.setSpecial_password(s);

        file.close();

        if(ui->lineEdit_national->text()!="")
        {
            mng.setNationlCode(ui->lineEdit_national->text());

        }
        else if(ui->lineEdit_2_ususal->text()!="")
        {
            mng.setUsual_password(ui->lineEdit_2_ususal->text());
        }
        else if(ui->lineEdit_phone->text()!="")
        {
            mng.setPhone(ui->lineEdit_phone->text());

        }
        else if(ui->lineEdit_4_name->text()!="")
        {
            mng.setName(ui->lineEdit_4_name->text());
        }

        else if(ui->lineEdit_5_lastname->text()!="")
        {
            mng.setFamily(ui->lineEdit_5_lastname->text());
        }
        else if(ui->lineEdit_3_speci->text()!="")
        {
            mng.setSpecial_password(ui->lineEdit_3_speci->text());
        }
        QFile("C:/Users/erfan/Documents/ProjectOfTerm2/mangerInformation.txt").remove();


        QFile fil("C:/Users/erfan/Documents/ProjectOfTerm2/mangerInformation.txt");
        fil.open(QIODevice::WriteOnly);
        QTextStream stream1(&fil);
        stream1.setCodec("UTF-8");

        stream1<<mng.getName()<<"\t";
        stream1<<mng.getFamily()<<"\t";
        stream1<<mng.getPhone()<<"\t";
        stream1<<mng.getNationlCode()<<"\t";
        stream1<<mng.getUsual_password()<<"\t";
        stream1<<mng.getSpetial_password()<<"\t";

        file.close();

        QMessageBox::information(this,"موفقیت امیز","مشخصات شما با موفقیت تغییر یافت",QMessageBox::Ok);
        ui->label_previous_name_2->setText(mng.getName());
        ui->label_previous_lastname_2->setText(mng.getFamily());
        ui->label_previous_phone_2->setText(mng.getPhone());
        ui->label_previous_nationalcode_2->setText(mng.getNationlCode());

        ui->lineEdit_phone->setText("");
        ui->lineEdit_4_name->setText("");
        ui->lineEdit_2_ususal->setText("");
        ui->lineEdit_3_speci->setText("");
        ui->lineEdit_national->setText("");
        ui->lineEdit_5_lastname->setText("");
        ui->lineEdit_prevusual->setText("");
        ui->lineEdit_prev_spec->setText("");
    }
}
