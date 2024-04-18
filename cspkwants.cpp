#include "cspkwants.h"
#include "ui_cspkwants.h"
#include <QTimer>
#include <QCloseEvent>

cspkwants::cspkwants(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cspkwants)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
}

cspkwants::~cspkwants()
{
    delete ui;
}

void cspkwants::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamewin *game=new gamewin;
        game->show();
    }

}

void cspkwants::timeoutslots(){
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
