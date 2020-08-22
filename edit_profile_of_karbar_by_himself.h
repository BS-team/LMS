#ifndef EDIT_PROFILE_OF_KARBAR_BY_HIMSELF_H
#define EDIT_PROFILE_OF_KARBAR_BY_HIMSELF_H

#include <QDialog>

namespace Ui {
class edit_profile_of_karbar_by_himself;
}

class edit_profile_of_karbar_by_himself : public QDialog
{
    Q_OBJECT

public:
    explicit edit_profile_of_karbar_by_himself(QString s,QWidget *parent = nullptr);
    ~edit_profile_of_karbar_by_himself();
    Ui::edit_profile_of_karbar_by_himself* getUi();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::edit_profile_of_karbar_by_himself *ui;
    QString id_Loginer;
public slots:
    void changemoshkarbar(int);

};

#endif // EDIT_PROFILE_OF_KARBAR_BY_HIMSELF_H
