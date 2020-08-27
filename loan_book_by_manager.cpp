#include "loan_book_by_manager.h"
#include "ui_loan_book_by_manager.h"
#include"functionToExplorUser.h"
#include"functioforgharzandpassofbook.h"
#include"functionToExplorebooks.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include"now_date.h"
#include"manageroption_for_pass_gharz_book.h"
#include"checkifsefareshismorethat2daybookezafe.h"
#include"checkforsearch_book_user.h"
#include<QDebug>

int main_num=0;

loan_book_by_manager::loan_book_by_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loan_book_by_manager)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/albaloo/Documents/ProjectOfTerm2/9828.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

	
    this->setWindowTitle("قرض کتاب برای کاربران");



    ui->listWidget_id->hide();
    ui->label_4_nameofbook->hide();
    ui->label_4_subjectOfbook->hide();
    ui->label_6_enteshbook->hide();
    ui->label_5_writerOfbook->hide();
    ui->label_3_transelBook->hide();
    ui->label_10_phonuser->hide();
    ui->label_8_emailofuser->hide();
    ui->label_7_nameuser->hide();
    int number=0;
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        ui->listWidget_id->insertItem(number,new QListWidgetItem (tmp->getData().getNational_code()));
        number++;
    }

    number=0;
    for(book_node* tmp=checkBookInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        ui->listWidget_codeBook->insertItem(number,new QListWidgetItem (tmp->getData().getCode()));
        number++;
    }

    ui->listWidget_codeBook->hide();

    connect(ui->lineEdit_id_loaner,SIGNAL(textChanged(QString)),this,SLOT(searchExplor_id_loaner(QString)));
    connect(ui->lineEdit_2_codeofbook,SIGNAL(textChanged(QString)),this,SLOT(searchExplor_code_book(QString)));

}

loan_book_by_manager::~loan_book_by_manager()
{
    delete ui;
}

void loan_book_by_manager::on_buttonBox_rejected()
{
    this->close();
    manageroption_for_pass_gharz_book* mnngg=new manageroption_for_pass_gharz_book();
    mnngg->show();
}

int checkhasBookOrNothisuser(loan_book_by_manager* lbbm,QString _id,QString _code)
{
    setBookNumberWithDateOfsabtByUser();
    int k=0;
    for(book_node* tmp=checkBookInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getCode()==_code)
        {
            if(tmp->getData().getNumber()==0)
            {
                k=1;
                QMessageBox::information(lbbm,"خطا","این کتاب موجودی ندارد",QMessageBox::Ok);
                break;
            }
        }
    }
    int tedad=0;
    for(book_gharz_pass_node* tmp2=checkBookgharzandpass();tmp2!=nullptr;tmp2=tmp2->getNext())
    {
        if(tmp2->getData().getNational_gharzgirande()==_id && tmp2->getData().getPass().getDay()==0)
        {
            tedad++;
        }
    }
    if(tedad>=3)
    {
        k=1;
        QMessageBox::information(lbbm,"خطا","چون مجموع کتاب های به امانت گرفته شده و پس نیاورده شده توسط کاربر از 3 بیشتر یا مساوی 3 میباشددر حال حاضر قادر به  قرض گرفتن کتاب جدید نیست",QMessageBox::Ok);
    }

    if(k==0)
    {
        for(book_gharz_pass_node* tmp=checkBookgharzandpass();tmp!=nullptr;tmp=tmp->getNext())
        {
            if(tmp->getData().getNational_gharzgirande()==_id &&tmp->getData().getCode_of_book()==_code)
            {
                if(tmp->getData().getGharz().getDay()==0)
                {
                    k=1;
                    QMessageBox::information(lbbm,"خطا","این کاربر این کتاب را سفارش داده اماهنوز دریافت نکرده است",QMessageBox::Ok);
                    break;
                }
                if(tmp->getData().getPass().getDay()==0)
                {
                    k=1;
                    QMessageBox::information(lbbm,"خطا","این کاربر در حال حاضر این کتاب را قرض کرده و پس نیاورده است",QMessageBox::Ok);
                    break;
                }
                else if(date_now()-tmp->getData().getPass()<14)
                {
                    k=1;
                    QMessageBox::information(lbbm,"توجه","باید حداقل دوهفته از اخرین تاریخ پس اوردن کتاب توسط کاربر برای به امانت گرفتن این کتاب گذشته باشد",QMessageBox::Ok);
                    break;

                }
            }
            else if(tmp->getData().getNational_gharzgirande()==_id)
            {
                if(tmp->getData().getPass().getDay()==0)
                {
                    if(date_now()-tmp->getData().getGharz()>14)
                    {
                        k=1;
                        QMessageBox::information(lbbm,"توجه","این کاربر کتابی را قرض کرده و برای بیش از دو هفته ان را پس نیاورده است",QMessageBox::Ok);
                        break;
                    }
                }
            }
        }
    }
    if(k==0)
        return 1;
    else
        return 0;
}

void loan_book_by_manager::on_buttonBox_accepted()
{
    int k=0;
    if(checkhasBookOrNothisuser( this,ui->lineEdit_id_loaner->text(),ui->lineEdit_2_codeofbook->text()))
    {
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
            if(tmp->getData().getNational_code()==ui->lineEdit_id_loaner->text())
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {
            QMessageBox::information(this,"خطا","کاربری با این کدملی وجود ندارد",QMessageBox::Ok);
            ui->lineEdit_id_loaner->setText("");
            ui->lineEdit_2_codeofbook->setText("");
        }
        else if(k==1)
        {
            k=0;
            for(book_node* tmp=checkBookInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(tmp->getData().getCode()==ui->lineEdit_2_codeofbook->text())
                {
                    k=1;
                    break;
                }
            }
            if(k==0)
            {
                QMessageBox::information(this,"خطا","کتابی با این کد وجود ندارد",QMessageBox::Ok);
                ui->lineEdit_id_loaner->setText("");
                ui->lineEdit_2_codeofbook->setText("");
            }
        }
        if(k==1)
        {

            QFile fil("C:/Users/albaloo/Documents/ProjectOfTerm2/gharzandpassbook.txt");
            fil.open(QIODevice::Append);
            QTextStream stream1(&fil);
            stream1.setCodec("UTF-8");
            date da=date_now();
            stream1<<ui->lineEdit_id_loaner->text()<<"\t";
            stream1<<ui->lineEdit_2_codeofbook->text()<<"\t";
            stream1<<da.getDay()<<"\t";
            stream1<<da.getMonth()<<"\t";
            stream1<<da.getYear()<<"\t";
            stream1<<da.getDay()<<"\t";
            stream1<<da.getMonth()<<"\t";
            stream1<<da.getYear()<<"\t";
            stream1<<0<<"\t";
            stream1<<0<<"\t";
            stream1<<0<<"\t";
            stream1<<0<<"\t";
            stream1<<0<<"\t";
            stream1<<0<<"\n";
            fil.close();

            book_node* tmp6=checkBookInformation();
            QFile filll("C:/Users/albaloo/Documents/ProjectOfTerm2/booksInformations.txt");
            filll.open(QIODevice::WriteOnly);
            QTextStream stream2(&filll);
            stream2.setCodec("UTF-8");
            for(;tmp6!=nullptr;tmp6=tmp6->getNext())
            {
                stream2
                        <<tmp6->getData().getName()<<"\t"
                        <<tmp6->getData().getSubject()<<"\t"
                        <<tmp6->getData().getEntesharatr()<<"\t"
                        <<tmp6->getData().getCode()<<"\t"
                        <<tmp6->getData().getIdEhdaconande()<<"\t";
                if(tmp6->getData().getCode()==ui->lineEdit_2_codeofbook->text())
                {
                     stream2<<tmp6->getData().getNumber()-1<<"\t";
                }
                else
                {
                    stream2<<tmp6->getData().getNumber()<<"\t";
                }
                stream2
                        <<tmp6->getData().getAuthor().getName()<<"\t"
                        <<tmp6->getData().getAuthor().getFamily()<<"\t"
                        <<tmp6->getData().getAuthor().getNationality()<<"\t"
                        <<tmp6->getData().getTranslator().getName()<<"\t"
                        <<tmp6->getData().getTranslator().getFamily()<<"\t"
                        <<tmp6->getData().getEhda().getDay()<<"\t"
                        <<tmp6->getData().getEhda().getMonth()<<"\t"
                        <<tmp6->getData().getEhda().getYear()<<"\n";
            }
            filll.close();

            QMessageBox::information(this,"موفقیت امیز","شما برای فردی به طور موفقیت امیز کتاب قرض کردید",QMessageBox::Ok);
            this->close();
            manageroption_for_pass_gharz_book* mnngg=new manageroption_for_pass_gharz_book();
            mnngg->show();
        }
    }
}

void loan_book_by_manager::searchItem_user(int k)
{
    QString s=ui->listWidget_id->item(k)->text();
    ui->lineEdit_id_loaner->setText(s);
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getNational_code()==ui->lineEdit_id_loaner->text())
        {
            ui->label_10_phonuser->show();
            ui->label_8_emailofuser->show();
            ui->label_7_nameuser->show();

            ui->label_3_user_name->setText(tmp->getData().getName()+" "+tmp->getData().getFamily());
            ui->label_9_useremail->setText(tmp->getData().getEmail());
            ui->label_11_userPhon->setText(tmp->getData().getPhone());

            break;
        }
    }
}

void loan_book_by_manager::searchExplor_id_loaner(QString _id)
{
    for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getNational_code()==ui->lineEdit_id_loaner->text())
        {
            ui->label_10_phonuser->show();
            ui->label_8_emailofuser->show();
            ui->label_7_nameuser->show();

            ui->label_3_user_name->setText(tmp->getData().getName()+" "+tmp->getData().getFamily());
            ui->label_9_useremail->setText(tmp->getData().getEmail());
            ui->label_11_userPhon->setText(tmp->getData().getPhone());

            break;
        }
    }

    ui->label_3_user_name->setText("");
    ui->label_9_useremail->setText("");
    ui->label_11_userPhon->setText("");

    ui->label_10_phonuser->hide();
    ui->label_8_emailofuser->hide();
    ui->label_7_nameuser->hide();
    if(ui->lineEdit_id_loaner->text()=="")
    {
        ui->listWidget_id->hide();

        ui->label_3_user_name->setText("");
        ui->label_9_useremail->setText("");
        ui->label_11_userPhon->setText("");

        ui->label_10_phonuser->hide();
        ui->label_8_emailofuser->hide();
        ui->label_7_nameuser->hide();
    }
    else
    {
        ui->listWidget_id->show();
        for(int i=0;i<ui->listWidget_id->model()->rowCount();i++)
        {
            if(ui->listWidget_id->item(i)->isHidden())
            {
                ui->listWidget_id->item(i)->setHidden(false);
            }
        }

        int number;
        number=0;
        for(karbar_node* tmp=checkUserInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
            if(barresinationalcodeandpas(tmp->getData().getNational_code(),ui->lineEdit_id_loaner->text())==0)
            {
                ui->listWidget_id->item(number)->setHidden(true);
            }
            number++;
        }
        connect(ui->listWidget_id,SIGNAL(currentRowChanged(int)),this,SLOT(searchItem_user(int)));
    }
}

void loan_book_by_manager::searchExplor_code_book(QString _code)
{
    if(ui->lineEdit_2_codeofbook->text()=="")
    {
        ui->listWidget_codeBook->hide();
        ui->label_4_bookName->setText("");
        ui->label_4_bookName->setText("");
        ui->label_3_booSubject->setText("");
        ui->label_3_bookwriter->setText("");
        ui->label_4_booktrnaslate->setText("");
        ui->label_5_bookentesh->setText("");

        ui->label_4_nameofbook->hide();
        ui->label_4_subjectOfbook->hide();
        ui->label_6_enteshbook->hide();
        ui->label_5_writerOfbook->hide();
        ui->label_3_transelBook->hide();
    }
    else
    {
        ui->listWidget_codeBook->show();
        for(int i=0;i<ui->listWidget_codeBook->model()->rowCount();i++)
        {
            if(ui->listWidget_codeBook->item(i)->isHidden())
            {
                ui->listWidget_codeBook->item(i)->setHidden(false);
            }
        }

        int number;
        number=0;
        for(book_node* tmp=checkBookInformation();tmp!=nullptr;tmp=tmp->getNext())
        {
            if(barresinationalcodeandpas(tmp->getData().getCode(),ui->lineEdit_2_codeofbook->text())==0)
            {
                ui->listWidget_codeBook->item(number)->setHidden(true);
            }
            number++;
        }
        connect(ui->listWidget_codeBook,SIGNAL(currentRowChanged(int)),this,SLOT(searchItem_book(int)));
    }
}

void loan_book_by_manager::searchItem_book(int k)
{
    QString s=ui->listWidget_codeBook->item(k)->text();
    ui->lineEdit_2_codeofbook->setText(s);
    for(book_node* tmp=checkBookInformation();tmp!=nullptr;tmp=tmp->getNext())
    {
        if(tmp->getData().getCode()==ui->lineEdit_2_codeofbook->text())
        {
            ui->label_4_nameofbook->show();
            ui->label_4_subjectOfbook->show();
            ui->label_6_enteshbook->show();
            ui->label_5_writerOfbook->show();
            ui->label_3_transelBook->show();

            ui->label_4_bookName->setText(tmp->getData().getName());
            ui->label_3_booSubject->setText(tmp->getData().getSubject());
            ui->label_3_bookwriter->setText(tmp->getData().getAuthor().getName()+" "+tmp->getData().getAuthor().getFamily());
            ui->label_4_booktrnaslate->setText(tmp->getData().getTranslator().getName()+" "+tmp->getData().getTranslator().getFamily());
            ui->label_5_bookentesh->setText(tmp->getData().getEntesharatr());

            break;
        }
    }
}





void loan_book_by_manager::on_loan_book_by_manager_accepted(){} //alaki
