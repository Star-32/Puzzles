#include "enteranswer.h"
#include "ui_enteranswer.h"

EnterAnswer::EnterAnswer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterAnswer)
{
    ui->setupUi(this);
    setWindowTitle("输入答案");
}

EnterAnswer::~EnterAnswer()
{
    delete ui;
}

QString EnterAnswer::getans(){
    QString Answer1 = ui->lineEdit->text();
    return Answer1;
}


