#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

class Calc : public QDialog
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = nullptr);
    ~Calc();

private:
    QGridLayout *gridLayout;
    QLineEdit *display;
    void createButtons();

private slots:
    void buttonClicked(const QString &buttonText);
    void solveClicked();
    void operationClicked(const QString &buttonText);};


#endif // CALC_H
