#ifndef DIALOG_MOSHAKHASATS_BOOKS_BY_MANAGER_H
#define DIALOG_MOSHAKHASATS_BOOKS_BY_MANAGER_H

#include <QDialog>

namespace Ui {
class Dialog_moshakhasats_books_by_manager;
}

class Dialog_moshakhasats_books_by_manager : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_moshakhasats_books_by_manager(QWidget *parent = nullptr);
    ~Dialog_moshakhasats_books_by_manager();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_moshakhasats_books_by_manager *ui;
};

#endif // DIALOG_MOSHAKHASATS_BOOKS_BY_MANAGER_H
