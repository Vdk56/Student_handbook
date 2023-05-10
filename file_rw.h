#ifndef FILE_RW_H
#define FILE_RW_H
#include <QString>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include "mainwindow.h"
#include "ui_mainwindow.h"


class file_rw
{
public:
    file_rw();
    void init_db1();
    void init_db2();
    void update_table(QString sch[8][4],int day,int week_num);
    QString read_file(int day, int week_num);
    QString emp_str();

private:

    QSqlQueryModel *model;
    QSqlQuery *query;

};

#endif // FILE_RW_H
