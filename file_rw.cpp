#include "file_rw.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"



file_rw::file_rw()
{

}

void file_rw::init_db2()
{
    QFile f("check.txt");
    QSqlQuery query;
    if(!query.prepare("INSERT INTO schedule(week,monday,tuesday,wednesday,thursday,friday,saturday)"
              "VALUES(:week,:monday,:tuesday,:wednesday,:thursday,:friday,:saturday)"));
    for(int w = 0;w<53;w++){
    query.bindValue(":week",w);
    query.bindValue(":monday", emp_str());
    query.bindValue(":tuesday", emp_str());
    query.bindValue(":wednesday", emp_str());
    query.bindValue(":thursday", emp_str());
    query.bindValue(":friday", emp_str());
    query.bindValue(":saturday", emp_str());
    query.exec();
    }
}

void file_rw::init_db1()
{
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS schedule(week  INT,monday TEXT,tuesday TEXT,wednesday TEXT,"
                   "thursday TEXT,friday TEXT,saturday TEXT);")) qDebug()<<query.lastError().text() ;

}

void file_rw::update_table(QString sch[7][4], int day, int week_num)
{
    QSqlQuery query;
    QString str, request;
    char *ch;
    for(int col=0; col<4; col++){
        for(int row = 0; row<7; row ++){
            str.append(sch[row][col]);
            if(row<6)str.append("|");
        }
       if(col<3)str.append("▼");
    }
    QByteArray bb = str.toUtf8();
    ch = bb.data();

    if(day==1){
        query.prepare(QString("UPDATE schedule SET monday = :monday WHERE week = :week "));
        query.bindValue(":monday", str);
        query.bindValue(":week", week_num);
        query.exec();
       }
   if(day==2){
        query.prepare(QString("UPDATE schedule SET tuesday = :tuesday WHERE week = :week "));
        query.bindValue(":tuesday", str);
        query.bindValue(":week", week_num);
        query.exec();
      }
    if(day==3)
       {
        query.prepare(QString("UPDATE schedule SET wednesday = :wednesday WHERE week = :week "));
        query.bindValue(":wednesday", str);
        query.bindValue(":week", week_num);
        query.exec();

       }
    if (day==4)
       {
        query.prepare(QString("UPDATE schedule SET thursday = :thursday WHERE week = :week "));
        query.bindValue(":thursday", str);
        query.bindValue(":week", week_num);
        query.exec();

       }
   if(day==5)
       {
        query.prepare(QString("UPDATE schedule SET friday = :friday WHERE week = :week "));
        query.bindValue(":friday", str);
        query.bindValue(":week", week_num);
        query.exec();
       }
    if(day==6)
        {
        query.prepare(QString("UPDATE schedule SET saturday = :saturday WHERE week = :week "));
        query.bindValue(":saturday", str);
        query.bindValue(":week", week_num);
        query.exec();
    }
}

QString file_rw::read_file(int day,int week_num)
{
    QString s1,s2,s3,s4,s5,s6;
    QSqlQuery query;
    int i = 1;

        query.prepare("SELECT monday,tuesday,wednesday,thursday,friday,saturday FROM schedule WHERE week = :week");
        query.bindValue(":week", week_num);
        query.exec();
        query.next();

        if(day==1) {
            s1 = query.value(0).toString();


            return s1;

        }
        if(day==2){
            s2 = query.value(1).toString();
            return s2;
        }
        if(day==3){
            s3 = query.value(2).toString();
            return s3;
        }
        if(day==4){
            s4 = query.value(3).toString();
            return s4;
        }
        if(day==5){
            s5 = query.value(4).toString();
            return s5;
        }
        if(day==6){
            s6 = query.value(5).toString();
            return s6;
        }
}

QString file_rw::emp_str()
{
    QString str = "";
    for(int col=0; col<4; col++){
        for(int row = 0; row<7; row ++){
           if(row<6) str = str + "|";
        }
       if(col<3) str = str + "▼";
    }
    return str;
}




