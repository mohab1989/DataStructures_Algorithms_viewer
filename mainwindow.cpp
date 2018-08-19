#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<LinkedList/linked_list.h>
void MainWindow::set_dropdown_values(QString db_column,QString db_table)
{
    ui->label_connection_status->clear();
    //QSqlDatabase db = QSqlDatabase::addDatabase("QODBC") ;
    db = QSqlDatabase::addDatabase("QSQLITE") ;
    //QString dsn = QString("Data Source=MOHAB;Initial Catalog=SA_Visualizer;Integrated Security=True");
    QString dsn = QString("G:/Projects/QtProjects/DSA_Visualizer/SQLite/DSA_Visualizer.db");
    db.setDatabaseName(dsn);
    QString connection_status;
    if(db.open())
    {
       connection_status="opened!\n";
       //db.close();
    }
    else
    {
       connection_status="Error "+db.lastError().text();
    }

   QSqlQuery query(db);
   //QString connection_status;
   ui->comboBox_DSA_2->clear();

   if(query.exec("select "+db_column+" from "+db_table))
   {
       connection_status +="query excution successful\n";
   }
   else
   {
       connection_status +="query excution failed\n";
   }

   while (query.next())
   {
       QString Data_Structures = query.value(0).toString();
       ui->comboBox_DSA_2->addItem(Data_Structures);
   }
   ui->label_connection_status->setText(connection_status);
   db.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList sequence = QStringList()<<tr("Algorithms")<<tr("Data Structures");
    ui->comboBox_DSA->addItems(sequence);
}

MainWindow::~MainWindow()
{
    //db.close();
    delete ui;
}

void MainWindow::on_comboBox_DSA_currentIndexChanged(int index)
{
   QString db_column , db_table;
   switch (index)
   {
       case 0:
        db_table = "Algorithms";
        db_column = "A_Name";
        break;
       case 1:
        db_table = "Data_Structures";
        db_column = "DS_Name";
        break;
       default:
        break;
   }
   set_dropdown_values(db_column,db_table);
}

void MainWindow::on_comboBox_DSA_2_currentIndexChanged(const QString &select_DSA)
{
    ui->DSA_label->setText(select_DSA);
    ui->Create_pushButton->setText("Create " + select_DSA);
}
