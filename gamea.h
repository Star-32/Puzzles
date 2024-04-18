#ifndef GAMEA_H
#define GAMEA_H

#include <QWidget>
#include <QTimer>
#include <QRandomGenerator>
#include <QLabel>
#include <QString>
#include "block.h"
#include "barrier.h"

class gamea : public QWidget
{
    Q_OBJECT
public:
    explicit gamea(QWidget *parent = nullptr);
    void drawblock();
    void drawback();
    void drawbarrier();
    bool hitside();
    void keypress(int key);
    Block nowblock;
    barrier nowbarrier;
    QTimer *timer;
    QRandomGenerator a;
    int count;

private slots:
    void timeoutslot();

signals:
    void gameover();

protected:
    void paintEvent(QPaintEvent *event);

public slots:
};

#endif // gamea_H
