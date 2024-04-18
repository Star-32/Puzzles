#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include "qpainter.h"

mediaplayer::mediaplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mediaplayer)
{
    ui->setupUi(this);
    music = new QMediaPlayer(this);
    list = new QMediaPlaylist(this);
    list->setPlaybackMode(QMediaPlaylist::Random);
    list->addMedia(QUrl("qrc:/song/1"));
    list->addMedia(QUrl("qrc:/song/2"));
    list->addMedia(QUrl("qrc:/song/3"));
    list->addMedia(QUrl("qrc:/song/4"));
    list->addMedia(QUrl("qrc:/song/5"));
    list->addMedia(QUrl("qrc:/song/6"));
    list->addMedia(QUrl("qrc:/song/7"));
    list->addMedia(QUrl("qrc:/song/8"));
    list->shuffle();
    music->setPlaylist(list);
    music->setVolume(100);
}

mediaplayer::~mediaplayer()
{
    delete ui;
}

void mediaplayer::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QColor("black")); //设置画笔记颜色
    p.drawRect(0, 0, width() -1, height() -1); //绘制边框
}


void mediaplayer::on_pushButton_clicked()
{
    music->play();
}


void mediaplayer::on_pushButton_2_clicked()
{
    music->pause();
    emit(music_stop());
}


void mediaplayer::on_pushButton_3_clicked()
{
    int tot = list->mediaCount();
    int now = list->currentIndex();
    now++;
    if ( now > tot ) now = 0;
    list->setCurrentIndex(now);
    music->play();
}

