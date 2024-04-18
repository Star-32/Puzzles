#include "gamelose.h"
#include "ui_gamelose.h"

gamelose::gamelose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamelose)
{
    ui->setupUi(this);
}

gamelose::~gamelose()
{
    delete ui;
}
