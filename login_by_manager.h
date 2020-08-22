#ifndef LOGIN_BY_MANAGER_H
#define LOGIN_BY_MANAGER_H

#include <QDialog>
#include"manageroption_for_pass_gharz_book.h"
namespace Ui {
class login_by_manager;
}

class login_by_manager : public QDialog
{
    Q_OBJECT

public:
    explicit login_by_manager(QWidget *parent = nullptr);
    ~login_by_manager();
    Ui::login_by_manager* getUi();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::login_by_manager *ui;
    manageroption_for_pass_gharz_book* mng;

signals:
    void checkmanger(QString,QString,QString,/*QString,QString,*/login_by_manager*);
};

#endif // LOGIN_BY_MANAGER_H
