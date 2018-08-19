#include "create_dsa.h"
#include "ui_create_dsa.h"

Create_DSA::Create_DSA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_DSA)
{
    ui->setupUi(this);
}

Create_DSA::~Create_DSA()
{
    delete ui;
}
