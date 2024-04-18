#include "noiyl.h"
#include "ui_noiyl.h"
#include <QTimer>
#include <QCloseEvent>

noiyl::noiyl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::noiyl)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
}

noiyl::~noiyl()
{
    delete ui;
}

void noiyl::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamewin *game=new gamewin;
        game->show();
    }

}

void noiyl::timeoutslots(){
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
