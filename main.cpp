#include "mainwindow.h"
#include "calc.h"
#include "user_data.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    Calc c;
    QObject::connect(&w, &MainWindow::open_calc, &c, [&c](){c.show();});
    w.show();
    return a.exec();
}
