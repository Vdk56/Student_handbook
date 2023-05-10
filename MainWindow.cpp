#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file_rw.h"

#include <QPainter>

file_rw dbd;

QString mon[7][4],tues[7][4],wed[7][4],thur[7][4],fri[7][4],sut[7][4];



int week_num = 1;
int last_week;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->YearLabel->setText("2022");
    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./schedule.db");
    if (!db.open()) qDebug()<<db.lastError().text();
    dbd.init_db1();
     QFile f ("check.txt");
    if(!f.exists())
    {



        dbd.init_db2();

        f.open(QIODevice::WriteOnly);
        f.write("1");
        f.close();

    }

    else{
        QFile f ("check.txt");
        f.open(QIODevice::ReadOnly);
        last_week=f.readLine().toInt();
        fill_tables(last_week);
        f.close();
    }
    init_date(week_num);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_date(int week)
{
    QDate date;
    int day_to_add = 0;
    QStringList temp_date;
    QString mon,tues,wed,thur,fri,sat;
    date.setDate(2022,8,29);
    day_to_add =day_to_add + ((week-1)*7);

    mon = date.addDays(day_to_add).toString();
    temp_date = mon.split(" ");
    mon = temp_date[2];
    mon.append(" " + temp_date[1]);
    ui->pon->setText(mon);

    tues = date.addDays(day_to_add+1).toString();
    temp_date = tues.split(" ");
    tues = temp_date[2];
    tues.append(" " + temp_date[1]);
    ui->vtor->setText(tues);

    wed = date.addDays(day_to_add+2).toString();
    temp_date = wed.split(" ");
    wed = temp_date[2];
    wed.append(" " + temp_date[1]);
    ui->sred->setText(wed);

    thur = date.addDays(day_to_add+2).toString();
    temp_date = thur.split(" ");
    thur = temp_date[2];
    thur.append(" " + temp_date[1]);
    ui->chet->setText(thur);

    fri = date.addDays(day_to_add+2).toString();
    temp_date = fri.split(" ");
    fri = temp_date[2];
    fri.append(" " + temp_date[1]);
    ui->pyat->setText(fri);

    sat = date.addDays(day_to_add+2).toString();
    temp_date = sat.split(" ");
    sat = temp_date[2];
    sat.append(" " + temp_date[1]);
    ui->sub->setText(sat);











}

void MainWindow::closeDB()
{

}

void MainWindow::fill_day_table(bool code,int day, int week)
{
    QString str,str_temp;
    QStringList list,temp_list;
    QString s[7][4];
    if(!code){
        str = dbd.read_file(day,week);
        list = str.split("▼");

        for (int i = 0;i<4;i++)
        {
            str_temp = list[i];
            for (int j = 0;j<7;j++)
            {
            temp_list = str_temp.split("|");

            s[j][i] = temp_list[j];
            }
        }
    }
    else
    {
        str = dbd.read_file(day,week);
        list = str.split("▼");
        for (int i = 0;i<1;i++)
        {
            str_temp = list[i];
            for (int j = 0;j<7;j++)
            {
            temp_list = str_temp.split("|");
            s[j][i] = temp_list[j];
            }
        }
        code = 0;
     }
     set_item_text(s,day);
}

void MainWindow::set_item_text(QString text[7][4], int day)
{
   QString str_temp,qqq;
   if(day==1){
                ui->mon_1->setRowCount(7);
                ui->mon_1->setColumnCount(4);
                ui->mon_1->verticalHeader()->hide();
                ui->mon_1->horizontalHeader()->hide();
                ui->mon_1->setColumnWidth(0,210);
                ui->mon_1->setColumnWidth(1,400);
                ui->mon_1->setColumnWidth(2,50);
                ui->mon_1->setColumnWidth(3,198);

             for(int col=0; col<4; col++){
                 for(int row = 0; row<7; row ++){
                     str_temp = text[row][col];
                     ui->mon_1->setItem(row,col,new QTableWidgetItem(str_temp));
                 }
             }

   }

    if(day==2){
        ui->tues_1->setRowCount(7);
        ui->tues_1->setColumnCount(4);
        ui->tues_1->horizontalHeader()->hide();
        ui->tues_1->verticalHeader()->hide();
        ui->tues_1->setColumnWidth(0,210);
        ui->tues_1->setColumnWidth(1,400);
        ui->tues_1->setColumnWidth(2,50);
        ui->tues_1->setColumnWidth(3,198);
        for(int col=0; col<4; col++){
            for(int row = 0; row<7
                ; row ++){
                ui->tues_1->setItem(row,col,new QTableWidgetItem(0));
            }
        }

        for(int col=0; col<4; col++){
            for(int row = 0; row<7; row ++){
                str_temp = text[row][col];
                ui->tues_1->setItem(row,col,new QTableWidgetItem(str_temp));
            }
        }
    }

    if(day==3){
        ui->wed_1->setRowCount(7);
        ui->wed_1->setColumnCount(4);
        ui->wed_1->horizontalHeader()->hide();
        ui->wed_1->verticalHeader()->hide();
        ui->wed_1->setColumnWidth(0,210);
        ui->wed_1->setColumnWidth(1,400);
        ui->wed_1->setColumnWidth(2,50);
        ui->wed_1->setColumnWidth(3,198);
        for(int col=0; col<4; col++){
            for(int row = 0; row<7
                ; row ++){
                ui->wed_1->setItem(row,col,new QTableWidgetItem(0));
            }
        }
        for(int col=0; col<4; col++){
            for(int row = 0; row<7; row ++){
                str_temp = text[row][col];
                ui->wed_1->setItem(row,col,new QTableWidgetItem(str_temp));
            }
        }
     }

     if(day==4){
         ui->thur_1->setRowCount(7);
         ui->thur_1->setColumnCount(4);
         ui->thur_1->horizontalHeader()->hide();
         ui->thur_1->verticalHeader()->hide();
         ui->thur_1->setColumnWidth(0,210);
         ui->thur_1->setColumnWidth(1,400);
         ui->thur_1->setColumnWidth(2,50);
         ui->thur_1->setColumnWidth(3,198);
         for(int col=0; col<4; col++){
             for(int row = 0; row<7
                 ; row ++){
                 ui->thur_1->setItem(row,col,new QTableWidgetItem(0));
             }
         }
         for(int col=0; col<4; col++){
             for(int row = 0; row<7; row ++){
                 str_temp = text[row][col];
                 ui->thur_1->setItem(row,col,new QTableWidgetItem(str_temp));
             }
         }
      }

     if(day==5){
         ui->fri_1->setRowCount(7);
         ui->fri_1->setColumnCount(4);
         ui->fri_1->horizontalHeader()->hide();
         ui->fri_1->verticalHeader()->hide();
         ui->fri_1->setColumnWidth(0,210);
         ui->fri_1->setColumnWidth(1,400);
         ui->fri_1->setColumnWidth(2,50);
         ui->fri_1->setColumnWidth(3,198);
         for(int col=0; col<4; col++){
             for(int row = 0; row<7
                 ; row ++){
                 ui->fri_1->setItem(row,col,new QTableWidgetItem(0));
             }
         }
         for(int col=0; col<4; col++){
             for(int row = 0; row<7; row ++){
                 str_temp = text[row][col];
                 ui->fri_1->setItem(row,col,new QTableWidgetItem(str_temp));
             }
         }
      }

      if(day==6){
          ui->sut_1->setRowCount(7);
          ui->sut_1->setColumnCount(4);
          ui->sut_1->horizontalHeader()->hide();
          ui->sut_1->verticalHeader()->hide();
          ui->sut_1->setColumnWidth(0,210);
          ui->sut_1->setColumnWidth(1,400);
          ui->sut_1->setColumnWidth(2,50);
          ui->sut_1->setColumnWidth(3,198);
          for(int col=0; col<4; col++){
              for(int row = 0; row<7
                  ; row ++){
                  ui->sut_1->setItem(row,col,new QTableWidgetItem(0));
              }
          }
          for(int col=0; col<4; col++){
              for(int row = 0; row<7; row ++){
                  str_temp = text[row][col];
                  ui->sut_1->setItem(row,col,new QTableWidgetItem(str_temp));
              }
          }
       }


}

void MainWindow::fill_tables(int w)
{


      week_num = w;
      ui->week->setText(QString::number(week_num));
      for (int i = 1;i<7;i++)
      {
        fill_day_table(0,i,week_num);
      }


}

void MainWindow::paintEvent(QPaintEvent *event)
{





}

void MainWindow::on_mon_1_cellChanged(int row, int column)
{
    QString str;
    file_rw  dbd;
    str = ui->mon_1->item(row, column)->text();
    mon [row][column] = str;
    dbd.update_table(mon,1,week_num);

}

void MainWindow::on_tues_1_cellChanged(int row, int column)
{
    QString str;
    file_rw  dbd;
    str = ui->tues_1->item(row, column)->text();
    tues [row][column] = str;
    dbd.update_table(tues,2,week_num);
}

void MainWindow::on_thur_1_cellChanged(int row, int column)
{
    QString str;
    file_rw  dbd;
    str = ui->thur_1->item(row, column)->text();
    thur [row][column] = str;
    dbd.update_table(thur,4,week_num);
}

void MainWindow::on_fri_1_cellChanged(int row, int column)
{
    QString str;
    file_rw  dbd;
    str = ui->fri_1->item(row, column)->text();
    fri [row][column] = str;
    dbd.update_table(fri,5,week_num);

}

void MainWindow::on_sut_1_cellChanged(int row, int column)
{
    QString str;
    file_rw  dbd;
    str = ui->sut_1->item(row, column)->text();
    sut [row][column] = str;
    dbd.update_table(sut,6,week_num);
}

void MainWindow::on_wed_1_cellChanged(int row, int column)
{
    QString str;
    file_rw  dbd;
    str = ui->wed_1->item(row, column)->text();
    wed [row][column] = str;
    dbd.update_table(wed,3,week_num);
}

void MainWindow::on_week_back_clicked()
{
    QFile f ("check.txt");
    QString str;
    char *ch;
    if(week_num>1) week_num = week_num - 1;
    if(week_num<=1) week_num = 1;
    if(week_num>18) ui->YearLabel->setText("2023");
    else ui->YearLabel->setText("2022");
    str = QString::number(week_num);
    last_week = week_num;
    f.open(QIODevice::WriteOnly);
    QByteArray bb = str.toUtf8();
    ch = bb.data();
    f.write(ch);
    fill_tables(week_num);
    init_date(week_num);
    ui->week->setText(str);

}

void MainWindow::on_week_for_clicked()
{
    QFile f ("check.txt");
    QString str;
    char *ch;
    if(week_num<52) week_num = week_num + 1;
    if(week_num>=52) week_num = 52;
    if(week_num>18) ui->YearLabel->setText("2023");
    else ui->YearLabel->setText("2022");
    str = QString::number(week_num);
    last_week = week_num;
    f.open(QIODevice::WriteOnly);
    QByteArray bb = str.toUtf8();
    ch = bb.data();
    f.write(ch);
    fill_tables(week_num);
    init_date(week_num);
    ui->week->setText(str);
}

void MainWindow::on_last_sch_copy_clicked()
{
  int i = ui->spinBox->value();
  for (int j =1;j<7;j++) {
    fill_day_table(1,j,i);
  }

}
