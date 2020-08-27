#ifndef DIALOG_MOSHAKHASATS_BY_MANAGER_H
#define DIALOG_MOSHAKHASATS_BY_MANAGER_H

#include <QDialog>
#include"dialog_password_by_manager.h"

namespace Ui {
class Dialog_moshakhasats_by_manager;
}

class Dialog_moshakhasats_by_manager : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog_moshakhasats_by_manager(QWidget *parent = nullptr);
    ~Dialog_moshakhasats_by_manager();

private slots:
    void on_pushButton_clicked();
    void on_back_clicked();

private:
    Ui::Dialog_moshakhasats_by_manager *ui;


signals:
    void send_pass_mosh(Dialog_moshakhasats_by_manager*,Dialog_password_by_manager*);

};

#endif // DIALOG_MOSHAKHASATS_BY_MANAGER_H
