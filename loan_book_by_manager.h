#ifndef LOAN_BOOK_BY_MANAGER_H
#define LOAN_BOOK_BY_MANAGER_H

#include <QDialog>
#include"manageroption_for_pass_gharz_book.h"

namespace Ui {
class loan_book_by_manager;
}

class loan_book_by_manager : public QDialog
{
    Q_OBJECT

public:
    explicit loan_book_by_manager(QWidget *parent = nullptr);
    ~loan_book_by_manager();

private slots:
    void on_loan_book_by_manager_accepted();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();
    void searchItem_user(int);
    void searchExplor_id_loaner(QString);

    void searchExplor_code_book(QString);
    void searchItem_book(int);

private:
    Ui::loan_book_by_manager *ui;
};

#endif // LOAN_BOOK_BY_MANAGER_H
