#include "login_by_manager.h"
#include "ui_login_by_manager.h"
#include"mainwindow.h"

login_by_manager::login_by_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_by_manager)
{
    ui->setupUi(this);
    this->ui->usual->setEchoMode(QLineEdit::Password);
    this->ui->special->setEchoMode(QLineEdit::Password);

    QPalette pal = palette();
    // set black background
    pal.setColor(QPalette::Background, Qt::darkGreen);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowTitle("login manager");
//    this->ui->rob_text->setText("");

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

login_by_manager::~login_by_manager()
{
    delete ui;
}

Ui::login_by_manager *login_by_manager::getUi()
{
    return ui;
}

int checkrobatt(QString s1,QString s2)
{
    int j=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]!=s2[j])
            return 0;
        j+=2;
    }
    return 1;
}


void login_by_manager::on_buttonBox_accepted()
{
    if(checkrobatt(ui->robat->text(),ui->sure->text())==1)
        emit(checkmanger(ui->id->text(),ui->usual->text(),ui->special->text(),this));
    else
    {
        ui->robat->setText("");
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
}

void login_by_manager::on_buttonBox_rejected()
{
    this->close();
    MainWindow* mnmn=new MainWindow();
    mnmn->show();
}
