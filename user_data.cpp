#include "user_data.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>



QString filePath = "users.csv";
QList<QList<QString>> login_data = readuserdata(filePath);

QList<QList<QString>> readuserdata(const QString& filePath) {
    QList<QList<QString>> data;

    QFile file(filePath);


    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Файл не открыт:" << filePath;
            return data;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(",");
        data.append(row);
    }

    file.close();
    return data;
}
void writeuserdata(const QString& filePath, const QList<QList<QString>>& data) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Файл для записи не открыт:" << filePath;
        return;
    }

    QTextStream out(&file);

    for (const QList<QString>& row : data) {
        out << row.join(",") << "\n";
    }

    file.close();
}
