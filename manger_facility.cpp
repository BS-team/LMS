#include "manger_facility.h"
#include "ui_manger_facility.h"
#include"usersoptionformanger.h"
#include"mainwindow.h"
#include"bookoptionformanger.h"
#include"edit_profile_of_manager.h"
#include"edit_profile_of_manager.h"
#include"manageroption_for_pass_gharz_book.h"
#include"checkifsefareshismorethat2daybookezafe.h"
#include"checkjarime.h"
manger_facility::manger_facility(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manger_facility)
{
    ui->setupUi(this);

    //setJarime();

    //setBookNumberWithDateOfsabtByUser();


    QPalette pal = palette();
    // set black background
    pal.setColor(QPalette::Background, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowTitle("Option For Manager");
}

manger_facility::~manger_facility()
{
    delete ui;
}

void manger_facility::on_pushButton_2_clicked()  //user for manager
{
    this->close();
    usersoptionformanger* usrpmng=new usersoptionformanger();
    usrpmng->show();

}

void manger_facility::on_pushButton_3_clicked() //back
{
    this->close();
    MainWindow * minv=new MainWindow();
    minv->show();
}

void manger_facility::on_pushButton_clicked()  //books for manager
{
    bookoptionformanger* usiption=new bookoptionformanger();
    this->close();
    usiption->show();
}

void manger_facility::on_pushButton_4_clicked()   //change moshakhasat
{
    this->close();
    edit_profile_of_manager* epom=new edit_profile_of_manager();
    epom->show();
}

void manger_facility::on_pushButton_5_clicked()  //pass
{
    this->close();
    manageroption_for_pass_gharz_book* mngfpsghrzbk=new manageroption_for_pass_gharz_book();
    mngfpsghrzbk->show();
}
