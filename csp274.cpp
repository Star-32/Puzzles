#include "csp274.h"
#include "ui_csp274.h"
#include <QTimer>
#include <QCloseEvent>

csp274::csp274(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::csp274)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));
    timer->start(50);
    QTextToSpeech *reader = new QTextToSpeech;
    QVector<QVoice> voice = reader->availableVoices();
    reader->setVoice(voice.at(0));
    reader->say("赵悦岑");

}

csp274::~csp274()
{
    delete ui;
}

void csp274::closeEvent(QCloseEvent *event)
{
    event->accept();timer->stop();
    if(ui->progressBar->value()>=100){
        gamewin *game=new gamewin;
        game->show();
    }
}

void csp274::timeoutslots(){
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
