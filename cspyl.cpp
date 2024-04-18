#include "cspyl.h"
#include "ui_cspyl.h"
#include <QTimer>
#include <QCloseEvent>

cspyl::cspyl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cspyl)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
}

cspyl::~cspyl()
{
    delete ui;
}

void cspyl::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamewin *game=new gamewin;
        game->show();
    }

}

void cspyl::timeoutslots(){
    int index = ui->progressBar->value();
    index++;
    if (index > 100)
    {
        timer->stop();
        this->close();
        return;
    }
    ui->progressBar->setValue(index);
}
