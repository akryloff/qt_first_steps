#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>

#include "user_data.h"
#include "calc.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_button_clicked();
    void on_register_button_clicked();
signals:

    void open_calc();

private:
    void createui();

    QGridLayout *gridLayout;
    QWidget *centr;

    Calc *calc_window;
    QLineEdit *login_line;
    QLineEdit *pass_line;
    QPushButton *loginButton;
    QPushButton *registerButton;
};
#endif // MAINWINDOW_H
