#ifndef LOGIN_BY_PASSWORD_H
#define LOGIN_BY_PASSWORD_H

#include <QDialog>

namespace Ui {
class login_by_password;
}
#include"smtp.h"

class login_by_password : public QDialog
{
    Q_OBJECT
public:
    explicit login_by_password(QWidget *parent = nullptr);
    ~login_by_password();
    Ui::login_by_password* getUi();
signals:
    void loginByPass(login_by_password*);
private:
    Ui::login_by_password *ui;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void SHowpassword(int bl);
    void on_pushButton_clicked();
    //void sendMail();
    void mailSent(QString);
};

#endif // LOGIN_BY_PASSWORD_H
