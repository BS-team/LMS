#include "about_us.h"
#include "ui_about_us.h"
#include"mainwindow.h"

About_us::About_us(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_us)
{
    ui->setupUi(this);

    QPixmap pix("E:/LastOne/ProjectOfTerm2/erfanN.jpg");
    ui->label->setPixmap(pix);
    QPixmap pix1("E:/LastOne/ProjectOfTerm2/aliP.jpg");
    ui->label_3->setPixmap(pix1);

    QPixmap pix2("E:/LastOne/ProjectOfTerm2/mohamadM.jpg");
    ui->label_4->setPixmap(pix2);


    QPalette pal = palette();
    // set black background
    pal.setColor(QPalette::Background, Qt::blue);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowTitle("درباره ما");

    //ui->back->setStyleSheet("background-color: yellow");
    ui->back->setStyleSheet(QString::fromUtf8("QPushButton{"
    "padding: -6px;"
    //   "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
       //                                                                                "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
        //                                                                                "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
    //"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.977528 rgba(60, 60, 60, 255), stop:1 rgba(0, 0, 0, 0));"
   // "background-color: lightgray;"
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
}

About_us::~About_us()
{
    delete ui;
}

void About_us::on_back_clicked()
{
    this->close();
    MainWindow* mnw=new MainWindow();
    mnw->show();
}
