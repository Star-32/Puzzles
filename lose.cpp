#include "lose.h"
#include "ui_lose.h"

lose::lose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lose)
{
    ui->setupUi(this);
}

lose::~lose()
{
    delete ui;
}
