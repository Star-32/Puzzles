#include "noipyl.h"
#include "ui_noipyl.h"
#include <QTimer>
#include <QCloseEvent>

noipyl::noipyl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::noipyl)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
}

noipyl::~noipyl()
{
    delete ui;
}

void noipyl::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamelose *game=new gamelose;
        game->show();
    }

}

void noipyl::timeoutslots(){
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
