#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QDir>
#include <iostream>
#include <filesystem>
#include "user_data.h"
#include <QDebug>
#include "calc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_login_button_clicked();
    void on_register_button_clicked();
signals:

    void open_calc();

private:
    Ui::MainWindow *ui;
    Calc *calc_window;
};
#endif // MAINWINDOW_H
