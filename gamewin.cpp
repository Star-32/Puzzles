#include "gamewin.h"
#include "ui_gamewin.h"

gamewin::gamewin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewin)
{
    ui->setupUi(this);
}

gamewin::~gamewin()
{
    delete ui;
}
