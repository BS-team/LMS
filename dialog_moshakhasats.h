#ifndef DIALOG_MOSHAKHASATS_H
#define DIALOG_MOSHAKHASATS_H

#include <QDialog>
#include"login_page.h"
namespace Ui {
class Dialog_moshakhasats;
}

class Dialog_moshakhasats : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_moshakhasats(QWidget *parent = nullptr);
    ~Dialog_moshakhasats();
    Ui::Dialog_moshakhasats* getUi();

private slots:
    void on_pushButton_clicked();
    void on_back_clicked();

    void on_cancle_clicked();

private:
    Ui::Dialog_moshakhasats *ui;
};

#endif // DIALOG_MOSHAKHASATS_H
