#ifndef DIALOG_PARDAKHT_FOR_TAMDID_EXIT_H
#define DIALOG_PARDAKHT_FOR_TAMDID_EXIT_H

#include <QDialog>

namespace Ui {
class dialog_pardakht_for_tamdid_exit;
}
#include"hesab_node.h"
class dialog_pardakht_for_tamdid_exit : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_pardakht_for_tamdid_exit(QString,QWidget *parent = nullptr);
    ~dialog_pardakht_for_tamdid_exit();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_pushButton_back_clicked();
    void on_pushButton_finish_clicked();

private:
    Ui::dialog_pardakht_for_tamdid_exit *ui;
    QString id_loginer;
public slots:
    void changeInfile(hesab_node*);
};

#endif // DIALOG_PARDAKHT_FOR_TAMDID_EXIT_H
