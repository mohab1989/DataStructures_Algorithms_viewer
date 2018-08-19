#ifndef CREATE_DSA_H
#define CREATE_DSA_H

#include <QDialog>

namespace Ui {
class Create_DSA;
}

class Create_DSA : public QDialog
{
    Q_OBJECT

public:
    explicit Create_DSA(QWidget *parent = 0);
    ~Create_DSA();

private:
    Ui::Create_DSA *ui;
};

#endif // CREATE_DSA_H
