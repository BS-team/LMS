#ifndef EDIT_PROFILE_OF_MANAGER_H
#define EDIT_PROFILE_OF_MANAGER_H

#include <QDialog>

namespace Ui {
class edit_profile_of_manager;
}

class edit_profile_of_manager : public QDialog
{
    Q_OBJECT

public:
    explicit edit_profile_of_manager(QWidget *parent = nullptr);
    ~edit_profile_of_manager();
    Ui::edit_profile_of_manager* getUi();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::edit_profile_of_manager *ui;

public slots:
    void changemoshmanager(int);
};

#endif // EDIT_PROFILE_OF_MANAGER_H
