#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<create_dsa.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBox_DSA_currentIndexChanged(int index);

    void on_comboBox_DSA_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    void set_dropdown_values(QString db_column,QString db_table);
    Create_DSA * Create_ui;
};

#endif // MAINWINDOW_H
