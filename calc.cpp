#include "calc.h"
double first;
QString flag;
QString legacy_flag;

Calc::Calc(QWidget *parent)
    : QDialog(parent)
{
    gridLayout = new QGridLayout(this);

    display = new QLineEdit(this);
    display->setFixedHeight(50);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);

    gridLayout->addWidget(display, 0, 0, 1, 5);

    createButtons();
    setLayout(gridLayout);

    setWindowTitle("4x5 Button Grid");
    resize(250, 400);
}

Calc::~Calc() {

}

void Calc::createButtons() {
    QStringList buttonLabels = {"1", "2", "3", "4", "5",
                                "6", "7", "8", "9", "0",
                                "+", "-", "*", "/", "=",
                                "AC", "<[x]", "%", ".", "+/-" };

    int pos = 0;
    for (int row = 1; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            QPushButton *button = new QPushButton(buttonLabels[pos], this);
            button->setFixedSize(50, 50);
            gridLayout->addWidget(button, row, col);
            QStringList operations = {"+", "-", "*", "/"};
            if (operations.contains(buttonLabels[pos])){
                connect(button, &QPushButton::clicked, this, [this, button]() {operationClicked(button->text());});
            } else if (buttonLabels[pos] == "=") {
                connect(button, &QPushButton::clicked, this, &Calc::solveClicked);
            } else {
                connect(button, &QPushButton::clicked, this, [this, button]() {buttonClicked(button->text());});
            }
            pos++;
        }
    }
}

void Calc::buttonClicked(const QString &buttonText){
    QStringList nums = {"1", "2", "3", "4", "5",
                                "6", "7", "8", "9", "0"};
    if (nums.contains(buttonText)){
        double numbers;
        QString str_numbers;
        numbers = (display->text() + buttonText).toDouble();
        str_numbers = QString::number(numbers, 'g', 15);
        display->setText(str_numbers);
    }
    else if (buttonText == "AC"){
        display->setText("");
        flag = "";
    } else if ((buttonText == "<[x]")){
        display->setText((display->text()).left((display->text()).length() - 1));
    } else if ((buttonText == "+/-")){
        double numbers;
        QString str_numbers;
        numbers = ((display->text()).toDouble()) * (-1);
        str_numbers = QString::number(numbers, 'g', 15);
        display->setText(str_numbers);
    } else if ((buttonText == "%")){
        double numbers;
        QString str_numbers;
        numbers = ((display->text()).toDouble()) * (0.01);
        str_numbers = QString::number(numbers, 'g', 15);
        display->setText(str_numbers);
    } else if ((buttonText == ".")){
        if (!(display->text().contains("."))){
            QString a = display->text() + buttonText;
            display->setText(a);
            }
    }
}

void Calc::operationClicked(const QString &buttonText){

    if ((display->text()) != "" && flag == ""){
        flag = buttonText;
        first = (display->text()).toDouble();
        display->setText("");
    } else if ((display->text()) == "" && flag != ""){
        flag = buttonText;
        display->setText("");
        std::cout << "1" << std::endl;
    }


}

void Calc::solveClicked(){
    double disp_number, second;
    QString str_numbers;
    second = display->text().toDouble();
    if (flag == "+") {
        disp_number = first + second;
        str_numbers = QString::number(disp_number, 'g', 15);
        display->setText(str_numbers);
    } else if (flag == "-") {
        disp_number = first - second;
        str_numbers = QString::number(disp_number, 'g', 15);
        display->setText(str_numbers);
    } else if (flag == "/") {
        disp_number = first / second;
        if (second == 0){
            display->setText("0");
        } else {
            str_numbers = QString::number(disp_number, 'g', 15);
            display->setText(str_numbers);}
    }else if (flag == "*") {
        disp_number = first * second;
        str_numbers = QString::number(disp_number, 'g', 15);
        display->setText(str_numbers);}
    flag = "";
    }
