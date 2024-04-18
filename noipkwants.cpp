#include "noipkwants.h"
#include "ui_noipkwants.h"
#include <QTimer>
#include <QCloseEvent>

noipkwants::noipkwants(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::noipkwants)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
}

noipkwants::~noipkwants()
{
    delete ui;
}

void noipkwants::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamewin *game=new gamewin;
        game->show();
    }

}

void noipkwants::timeoutslots(){
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
