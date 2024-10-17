#ifndef USER_DATA_H
#define USER_DATA_H

#include <iostream>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QString>
#include <QDebug>

extern QString filePath;
extern QList<QList<QString>> login_data;

QList<QList<QString>> readuserdata(const QString& filePath);
void writeuserdata(const QString& filePath, const QList<QList<QString>>& data);

#endif //USER_DATA_H
