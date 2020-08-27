#include "dialog_moshakhasats_books_by_manager.h"
#include "ui_dialog_moshakhasats_books_by_manager.h"
#include"manger_facility.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include"book_node.h"
#include"functionToExplorebooks.h"
#include"bookoptionformanger.h"
#include"checkpersianstring.h"
Dialog_moshakhasats_books_by_manager::Dialog_moshakhasats_books_by_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_moshakhasats_books_by_manager)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/erfan/Documents/ProjectOfTerm2/dialogmoshatbookmodir.jpeg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



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
    //"border-radius: 30px;"
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
    //"border-radius: 30px;"
    "}"));

    this->setWindowTitle("ثبت کتاب جدید");
}

Dialog_moshakhasats_books_by_manager::~Dialog_moshakhasats_books_by_manager()
{
    delete ui;
}

void Dialog_moshakhasats_books_by_manager::on_pushButton_clicked() //next
{
    if(ui->name->text()=="")
    {
        QMessageBox::information(this,"خظا","فیلد نام کتاب را پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->name->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد نام کتاب را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->subject->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد موضوع کتاب را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->entesharat->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد انتشارات کتاب را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->write_last->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد نام خانوادگی نویسنده را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->write_name->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد اسم نویسنده را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->write_national->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد ملیت نویسنده را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->translat_name->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد نام مترجم را به درستی پر کنید",QMessageBox::Ok);
    }
    else if(checkPersianStrings(ui->translat_family->text())==0)
    {
        QMessageBox::information(this,"خظا","فیلد نام خانوادگی مترجم را به درستی پر کنید",QMessageBox::Ok);
    }

    else if(ui->number->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد تعداد کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->subject->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد موضوع کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text().count()!=10 )
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[0]>57 || ui->ehdakonande->text()[0]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[1]>57 || ui->ehdakonande->text()[1]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[2]>57 || ui->ehdakonande->text()[2]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[3]>57 || ui->ehdakonande->text()[3]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[4]>57 || ui->ehdakonande->text()[4]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[5]>57 || ui->ehdakonande->text()[5]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[6]>57 || ui->ehdakonande->text()[6]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[7]>57 || ui->ehdakonande->text()[7]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[8]>57 || ui->ehdakonande->text()[8]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->ehdakonande->text()[9]>57 || ui->ehdakonande->text()[9]<48)
    {
        QMessageBox::information(this,"خطا","فیلد شماره ملی اهداگر کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->entesharat->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد انتشارات کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->write_name->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد نام نویسنده کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->write_last->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد نام خانوادگی کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->write_national->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد ملیت نویسنده کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->translat_name->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد اسم مترجم کتاب را پرکنید",QMessageBox::Ok);
    }
    else if(ui->translat_family->text()=="")
    {
        QMessageBox::information(this,"خطا","فیلد نام خانوادگی مترجم کتاب را پرکنید",QMessageBox::Ok);
    }
    else
    {
        time_t now;
        time(&now);
        struct tm* local=localtime(&now);


        srand(time(0));
        QString _code;
        while(1)
        {
            QString s;
            int a=0;
            int b;
            int sss=0;
            for(int i=0;i<3;i+=1)
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
            b=rand()%26;
            char c;
            if(b==0)
                c='z';
            else
            {
                c=(char)(b+96);
            }

            b=rand()%26;
            char c1;
            if(b==0)
                c1='z';
            else
            {
                c1=(char)(b+96);
            }
            _code=c+s+c1;
            int k=0;
            for(book_node* tmp=checkBookInformation();tmp!=nullptr;tmp=tmp->getNext())
            {
                if(tmp->getData().getCode()==_code)
                {
                    k=1;
                    break;
                }
            }
            if(k==0)
                break;
        }

        QFile file("C:/Users/erfan/Documents/ProjectOfTerm2/booksInformations.txt");
        file.open(QIODevice::Append);
        QTextStream stream(&file);
        stream.setCodec("UTF-8");

        stream
        <<ui->name->text()<<"\t"
        <<ui->subject->text()<<"\t"
        <<ui->entesharat->text()<<"\t"
        <<_code<<"\t"
        <<ui->ehdakonande->text()<<"\t"
        <<ui->number->text()<<"\t"
        <<ui->write_name->text()<<"\t"
        <<ui->write_last->text()<<"\t"
        <<ui->write_national->text()<<"\t"
        <<ui->translat_name->text()<<"\t"
        <<ui->translat_family->text()<<"\t"
        <<local->tm_mday<<"\t"
        <<local->tm_mon+1<<"\t"
        <<(local->tm_year+1900)<<"\n";
        file.close();

        QMessageBox::information(this,"موفقیت امیز","این کتاب با کد   "+_code+"   ثبت شده است",QMessageBox::Ok);
        this->close();
        bookoptionformanger* bkoption=new bookoptionformanger();
        bkoption->show();
    }
}

void Dialog_moshakhasats_books_by_manager::on_pushButton_2_clicked()
{
    this->close();
    bookoptionformanger* mngdf=new bookoptionformanger();
    mngdf->show();
}
