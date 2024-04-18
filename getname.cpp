#include "getname.h"
#include "ui_getname.h"

getname::getname(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getname)
{
    ui->setupUi(this);
}

getname::~getname()
{
    delete ui;
}

QString getname::get(){
    QString ret=ui->lineEdit->text();
    return ret;
}

void getname::on_pushButton_clicked()
{
    this->close();
}

