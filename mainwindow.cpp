#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QWidget *centr = new QWidget(this);
    gridLayout = new QGridLayout(this);

    loginButton = new QPushButton("Войти",this);
    registerButton = new QPushButton("Регистрация",this);

    login_line = new QLineEdit(this);

    pass_line = new QLineEdit(this);

    connect(loginButton, &QPushButton::clicked, this, &MainWindow::on_login_button_clicked);
    connect(registerButton, &QPushButton::clicked, this, &MainWindow::on_register_button_clicked);

    gridLayout->addWidget(new QLabel("Логин:"), 0, 0);
    gridLayout->addWidget(login_line, 0, 1);

    gridLayout->addWidget(new QLabel("Пароль:"), 1, 0);
    gridLayout->addWidget(pass_line, 1, 1);

    gridLayout->addWidget(loginButton, 2, 0);
    gridLayout->addWidget(registerButton, 2, 1);

    centr->setLayout(gridLayout);
    setCentralWidget(centr);
    resize(400, 300);




}
MainWindow::~MainWindow() {
    writeuserdata(filePath,login_data);}

void createui(){

}



void showMessageBox(QString Title, QString Text) {
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
    QString login = login_line->text();
    QString pass = pass_line->text();

    if (login_data.contains({login,pass})) {
        showMessageBox("success", "успешно");
        emit open_calc();
        hide();
    } else {
        showMessageBox("error", "неправильный логин или пароль. зарегистрируйтесь, если еще не сделали этого");
    }
}


void MainWindow::on_register_button_clicked()
{
    QString login = login_line->text();
    QString pass = pass_line->text();
    if (login_data.contains({login,pass})) {
        showMessageBox("already registered", "Вы уже зарегистрированы!");
    } else {
        showMessageBox("register", "Вы успешно зарегистрированы!");
        login_data.append({login,pass});
        writeuserdata(filePath,login_data);
    }
}


