#ifndef BARRIER_H
#define BARRIER_H

#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QRandomGenerator>
#include "qpainter.h"
#include "qvector.h"
#include "qpoint.h"


class barrierData;

class barrier
{
public:
    barrier();
    barrier(const barrier &);
    barrier &operator=(const barrier &);
    ~barrier();
    void Initbarrier();
    void Move(int x,int y);
    void Draw(QPainter &painter,int stx,int sty,int h,int l);

public:
    QVector<QPoint> points;
    QPoint pos;
    QRandomGenerator a;

private:
    QSharedDataPointer<barrierData> data;
};

#endif // BARRIER_H
