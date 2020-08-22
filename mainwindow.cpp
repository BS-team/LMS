#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include"manager.h"
#include"manger_facility.h"
#include"about_us.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = palette();
    // set black background
    pal.setColor(QPalette::Background, Qt::yellow);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowTitle("Main Page");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_karbar_clicked()
{
    login_page* login=new login_page();
    this->close();
    login->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_help_clicked()
{
    this->close();
    About_us* abus=new About_us();
    abus->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    login_by_manager* lgm=new login_by_manager();
    lgm->show();
    connect(lgm,SIGNAL(checkmanger(QString,QString,QString,login_by_manager*)),this,SLOT(checkLogin(QString,QString,QString,login_by_manager*)));
}

void MainWindow::checkLogin(QString s1,QString s2,QString s3,login_by_manager * mnglgl)
{
    QFile f("C:/Users/albaloo/Documents/ProjectOfTerm2/mangerInformation.txt");
    QTextStream stream(&f);
    stream.setCodec("UTF-8");

    f.open(QIODevice::ReadOnly);

    QString s,ss1,ss2,ss3;
    char z;
    manger mng;

    while(1)
    {
        stream>>ss1;
        s+=ss1;

        stream>>z;
        if(z=='\t')
        {
            mng.setName(s);
            ss3=s;
            s="\0";
            break;
        }
        else if(z=='\0')
            break;
        s+=' ';
    }

    while(1)
    {
        stream>>ss1;
        s+=ss1;

        stream>>z;
        if(z=='\t')
        {
            mng.setFamily(s);
            ss3=s;
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

    f.close();


    if(s1==mng.getNationlCode()&&s2==mng.getUsual_password()&&mng.getSpetial_password()==s3)//mnglgl->getUi()->rob_text->text()==mnglgl->getUi()->rob1->text() && mnglgl->getUi()->id->text()==mng.getNationlCode() && mnglgl->getUi()->special->text()==mng.getSpetial_password()&&mnglgl->getUi()->usual->text()==mng.getUsual_password())
    {
        QMessageBox::information(this,"خطا",mng.getName()+" "+mng.getFamily()+" شما با موفقیت وارد سامانه شدید  ",QMessageBox::Ok);
        mnglgl->close();
        this->close();
        manger_facility* mngf=new manger_facility();
        mngf->show();
    }
    else
    {
        QMessageBox::information(this,"خطا","نام کاربری یا رمز عبور اشتباه است",QMessageBox::Ok);
    }
}

