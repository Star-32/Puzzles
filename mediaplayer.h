#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class mediaplayer;
}

class mediaplayer : public QWidget
{
    Q_OBJECT

public:
    explicit mediaplayer(QWidget *parent = nullptr);
    ~mediaplayer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::mediaplayer *ui;
    QMediaPlayer *music;
    QMediaPlaylist *list;

signals:
    void music_stop();

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // MEDIAPLAYER_H
