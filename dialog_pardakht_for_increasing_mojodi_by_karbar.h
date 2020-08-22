#ifndef DIALOG_PARDAKHT_FOR_INCREASING_MOJODI_BY_KARBAR_H
#define DIALOG_PARDAKHT_FOR_INCREASING_MOJODI_BY_KARBAR_H

#include <QDialog>

namespace Ui {
class Dialog_pardakht_for_increasing_mojodi_by_karbar;
}
#include<QTimer>
class Dialog_pardakht_for_increasing_mojodi_by_karbar : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_pardakht_for_increasing_mojodi_by_karbar(QString,QWidget *parent = nullptr);
    ~Dialog_pardakht_for_increasing_mojodi_by_karbar();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
    void checkedProgressBar();

private:
    Ui::Dialog_pardakht_for_increasing_mojodi_by_karbar *ui;
    QString Id_Loginer;
    QTimer* _tm;

};

#endif // DIALOG_PARDAKHT_FOR_INCREASING_MOJODI_BY_KARBAR_H
