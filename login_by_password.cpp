#include "login_by_password.h"
#include "ui_login_by_password.h"
#include<QString>
#include<random>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include"login_page.h"
#include"functionToExplorUser.h"

login_by_password::login_by_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_by_password)
{
    ui->setupUi(this);


    QPixmap bkgnd("C:/Users/erfan/Documents/ProjectOfTerm2/loginpasswordpic.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->setWindowTitle("صفحه ورود کاربران");

    srand(time(0));
    this->ui->pass->setEchoMode(QLineEdit::Password);
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

    connect(ui->checkBox,SIGNAL(stateChanged(int)),this,SLOT(SHowpassword(int)));

}

login_by_password::~login_by_password()
{
    delete ui;
}

Ui::login_by_password *login_by_password::getUi()
{
    return ui;
}

void login_by_password::on_buttonBox_accepted()
{
    emit(loginByPass(this));
}

void login_by_password::on_buttonBox_rejected()
{
    this->close();
    login_page* lpg=new login_page();
    lpg->show();
}

void login_by_password::SHowpassword(int bl)
{
    if(bl==0)
    {
        ui->pass->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->pass->setEchoMode(QLineEdit::Normal);
    }
}

void login_by_password::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "ایمیل فرستاده شد!\n\n" ) );
}

void login_by_password::on_pushButton_clicked()
{
    int kk=0;
    karbar_node* tmp=checkUserInformation();
    for(;tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getNational_code()==ui->id->text())
        {
            kk=1;
            break;
        }
    }
    if(ui->pass->text()=="")
    {
        if(kk==0)
        {
            QMessageBox::information(this,"خطا","کدملی خودرا به درستی وارد کنید",QMessageBox::Ok);
        }
        else
        {
            Smtp* smtp = new Smtp("ali1380panahi@gmail.com", "AliP1380","smtp.gmail.com", 465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("ali1380panahi@gmail.com", tmp->getData().getEmail() , "Forgetting password from Library Managment System","You Password is : "+tmp->getData().getPassword());
        }
    }
    else
    {
        QMessageBox::information(this,"خطا","برای دریافت رمز خود از طریق ایمیل فیلد رمز عبور خود را خالی قراردهید",QMessageBox::Ok);
    }
}
