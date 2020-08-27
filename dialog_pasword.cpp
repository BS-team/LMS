#include "dialog_pasword.h"
#include "ui_dialog_pasword.h"
#include<QMessageBox>
#include"login_page.h"
#include<QFile>
#include<QTextStream>
#include"functionToExplorUser.h"

Dialog_pasword::Dialog_pasword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_pasword)
{
    ui->setupUi(this);
	
    QPalette pal = palette();
    QPixmap bkgnd("E:/LastOne/ProjectOfTerm2/passpic.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


	
    this->setWindowTitle("ایجادرمزعبور");
    this->ui->pass_line->setEchoMode(QLineEdit::Password);
    this->ui->lineEdit_2->setEchoMode(QLineEdit::Password);


    connect(ui->checkBox_pass,SIGNAL(stateChanged(int)),this,SLOT(showpassword(int)));
    connect(ui->checkBox_2,SIGNAL(stateChanged(int)),this,SLOT(showrepetofpassword(int)));
}

Dialog_pasword::~Dialog_pasword()
{
    delete ui;
}

int checkPassCorrect(QString s)
{
    for(int i=0;i<s.length();i++)
    {
        if((s[i]<65&&s[i]>57)||s[i]<48||(s[i]>91&&s[i]<97)||s[i]>123)
        {
            return 0;
        }
    }
    return 1;
}


void Dialog_pasword::on_buttonBox_accepted()
{
    int k=0;
    if(checkPassCorrect(ui->pass_line->text()))
    {
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
            if(tmp->getData().getPassword()==ui->pass_line->text())
            {
                k=1;
                break;
            }

        }
        if(k==0)
        {


            if(ui->pass_line->text()==ui->lineEdit_2->text())
            {
                if(ui->pass_line->text().length()>=8)
                {
                    emit(pass(this->ui->pass_line->text()));
                    QMessageBox::information(this,"موفقیت امیز","شما با موفقیت عضو شدید",QMessageBox::Ok);
                    this->close();
                    login_page* lgpp=new login_page();
                    lgpp->show();
                }
                else
                {
                    QMessageBox::information(this,"توجه","حداقل 8 کاراکتر وارد کنید",QMessageBox::Ok);
                    this->ui->pass_line->setText("");
                    ui->lineEdit_2->setText("");
                }
            }
            else
            {
                QMessageBox::information(this,"توجه","تکرار رمز عبور با رمز عبور یکسان نیست",QMessageBox::Ok);
                this->ui->pass_line->setText("");
                ui->lineEdit_2->setText("");
            }
        }
        else
        {
            QMessageBox::information(this,"توجه","شما نمی توانید بااین رمز عضو شوید",QMessageBox::Ok);
        }


    }
    else
    {
        QMessageBox::information(this,"توجه","رمز عبور تنها باید از حروف انگلیسی و اعداد باشد",QMessageBox::Ok);
        this->ui->pass_line->setText("");
        ui->lineEdit_2->setText("");
    }
}

void Dialog_pasword::on_buttonBox_rejected()
{
    this->close();
    login_page* lpg=new login_page();
    lpg->show();

}

void Dialog_pasword::showpassword(int bl)
{
    if(bl==0)
    {
        ui->pass_line->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->pass_line->setEchoMode(QLineEdit::Normal);
    }
}

void Dialog_pasword::showrepetofpassword(int bl)
{
    if(bl==0)
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
}










void Dialog_pasword::on_pass_line_cursorPositionChanged(int arg1, int arg2){}

void Dialog_pasword::on_show1_pressed(){}

