#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    writeuserdata(filePath,login_data);
    delete ui;
}

void showCustomMessageBox(QString Title, QString Text) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(Title);
    msgBox.setText(Text);

    QPushButton *customButton = msgBox.addButton("Ok", QMessageBox::AcceptRole);

    msgBox.exec();

    if (msgBox.clickedButton() == customButton) {
        msgBox.close();
    }
}

void MainWindow::on_login_button_clicked()
{
    QString login = ui->login_line->text();
    QString pass = ui->pass_line->text();

    if (login_data.contains({login,pass})) {
        showCustomMessageBox("success", "успешно");
        calc_window = new Calculator(this);
        calc_window->show();
    } else {
        showCustomMessageBox("error", "неправильный логин или пароль. зарегистрируйтесь, если еще не сделали этого");
    }
}


void MainWindow::on_register_button_clicked()
{
    QString login = ui->login_line->text();
    QString pass = ui->pass_line->text();
    if (login_data.contains({login,pass})) {
        showCustomMessageBox("already registered", "Вы уже зарегистрированы!");
    } else {
        showCustomMessageBox("register", "Вы успешно зарегистрированы!");
        login_data.append({login,pass});
        writeuserdata(filePath,login_data);
    }
}


