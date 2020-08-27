#ifndef MANGER_FACILITY_H
#define MANGER_FACILITY_H

#include <QDialog>

namespace Ui {
class manger_facility;
}

class manger_facility : public QDialog
{
    Q_OBJECT

public:
    explicit manger_facility(QWidget *parent = nullptr);
    ~manger_facility();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::manger_facility *ui;
};

#endif // MANGER_FACILITY_H
