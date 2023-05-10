#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

#include <QString>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDate>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_date(int week);
    void closeDB();
    void fill_tables(int w);
    void fill_day_table(bool code,int day,int week);
    void set_item_text(QString text[7][4],int day);


private:
    Ui::MainWindow *ui;

private slots:
    void paintEvent (QPaintEvent *event);
    void on_mon_1_cellChanged(int row, int column);
    void on_tues_1_cellChanged(int row, int column);
    void on_wed_1_cellChanged(int row, int column);
    void on_thur_1_cellChanged(int row, int column);
    void on_fri_1_cellChanged(int row, int column);
    void on_sut_1_cellChanged(int row, int column);

    void on_week_back_clicked();
    void on_week_for_clicked();

    void on_last_sch_copy_clicked();
};
#endif // MAINWINDOW_H
