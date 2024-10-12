#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

namespace Ui {
class Calculator;
}

class Calculator : public QDialog
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void digits();
    void on_pushButton_dot_clicked();
    void operations();
    void math_operations();
    void on_pushButton_calc_clicked();
};

#endif // CALCULATOR_H
