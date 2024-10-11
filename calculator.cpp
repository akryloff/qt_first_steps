#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}
