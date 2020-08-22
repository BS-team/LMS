#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <QDialog>

namespace Ui {
class About_us;
}

class About_us : public QDialog
{
    Q_OBJECT

public:
    explicit About_us(QWidget *parent = nullptr);
    ~About_us();

private slots:
    void on_back_clicked();

private:
    Ui::About_us *ui;
};

#endif // ABOUT_US_H
