#include "calculator.h"
#include "ui_calculator.h"

double first;


Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Calculator)

{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(digits()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(digits()));

    connect(ui->pushButton_sign, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_AC, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_back, SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()),this,SLOT(math_operations()));


    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}
void Calculator::digits(){
    QPushButton *button = static_cast<QPushButton*>(QObject::sender());

    double numbers;
    QString str_numbers;

    numbers = (ui->result_disp->text() + button->text()).toDouble();
    str_numbers = QString::number(numbers, 'g', 15);


    ui->result_disp->setText(str_numbers);

}

void Calculator::on_pushButton_dot_clicked()
{
    if (!(ui->result_disp->text().contains('.')))
        ui->result_disp->setText(ui->result_disp->text() + ".");
}

void Calculator::operations(){
    QPushButton *button = static_cast<QPushButton*>(QObject::sender());

    double numbers;
    QString str_numbers;

    if (button->text() == "+/-"){
        numbers = (ui->result_disp->text()).toDouble();
        numbers = numbers * (-1);
        str_numbers = QString::number(numbers, 'g', 15);}
    else if (button->text() == "%"){
        numbers = (ui->result_disp->text()).toDouble();
        numbers = numbers * 0.01;
        str_numbers = QString::number(numbers, 'g', 15);}
    else if (button->text() == "AC"){
        numbers = 0;
        str_numbers = QString::number(numbers, 'g', 15);}
    else if (button->text() == "<[x]"){
        numbers = (ui->result_disp->text()).toDouble();
        str_numbers = QString::number(numbers, 'g', 15);}
        str_numbers.chop(1);

    ui->result_disp->setText(str_numbers);
}

void Calculator::math_operations(){
    QPushButton *button = static_cast<QPushButton*>(QObject::sender());
    first = (ui->result_disp->text()).toDouble();
    button->setChecked(true);
    ui->result_disp->setText("");
}

void Calculator::on_pushButton_calc_clicked(){
    double disp_number, second;
    QString str_numbers;

    second = ui->result_disp->text().toDouble();

    if (ui->pushButton_plus->isChecked()) {
        disp_number = first + second;
        str_numbers = QString::number(disp_number, 'g', 15);
        ui->result_disp->setText(str_numbers);

        ui->pushButton_plus->setChecked(false);
    }else if (ui->pushButton_min->isChecked()) {
        disp_number = first - second;
        str_numbers = QString::number(disp_number, 'g', 15);
        ui->result_disp->setText(str_numbers);
        ui->pushButton_min->setChecked(false);

    }else if (ui->pushButton_div->isChecked()) {
        disp_number = first / second;
        if (second == 0){
            ui->result_disp->setText("0");
        } else {
            str_numbers = QString::number(disp_number, 'g', 15);
            ui->result_disp->setText(str_numbers);
            ui->pushButton_div->setChecked(false);}

    }else if (ui->pushButton_mult->isChecked()) {
        disp_number = first * second;
        str_numbers = QString::number(disp_number, 'g', 15);
        ui->result_disp->setText(str_numbers);
        ui->pushButton_mult->setChecked(false);

    }



}

