#include "noikwants.h"
#include "ui_noikwants.h"
#include <QTimer>
#include <QCloseEvent>

noikwants::noikwants(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::noikwants)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
}

noikwants::~noikwants()
{
    delete ui;
}

void noikwants::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamewin *game=new gamewin;
        game->show();
    }

}

void noikwants::timeoutslots(){
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
