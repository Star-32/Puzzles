#include "noi274.h"
#include "ui_noi274.h"
#include <QTimer>
#include <QCloseEvent>

noi274::noi274(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::noi274)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    game=new gamewin;
    QTextToSpeech *reader = new QTextToSpeech;
    QVector<QVoice> voice = reader->availableVoices();
    reader->setVoice(voice.at(0));
    reader->say("赵悦岑");

}

noi274::~noi274()
{
    delete ui;
}

void noi274::showEvent(QShowEvent *event){
    event->accept();
    timer->start(50);
}

void noi274::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        game->show();
    }

}

void noi274::timeoutslots(){
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
