#ifndef DIALOG_PASWORD_H
#define DIALOG_PASWORD_H

#include <QDialog>

namespace Ui {
class Dialog_pasword;
}

class Dialog_pasword : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog_pasword(QWidget *parent = nullptr);
    ~Dialog_pasword();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pass_line_cursorPositionChanged(int arg1, int arg2);

    void on_show1_pressed();

signals:
    void pass(QString);

public:
    Ui::Dialog_pasword *ui;

public slots:
    void showpassword(int);
    void showrepetofpassword(int);
};

#endif // DIALOG_PASWORD_H
