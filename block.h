#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include "qpainter.h"
#include "qvector.h"
#include "qpoint.h"


class BlockData;

class Block
{
public:
    Block();
    Block(const Block &);
    Block &operator=(const Block &);
    ~Block();
    void Initblock();
    void Move(int x,int y);
    void Draw(QPainter &painter,int stx,int sty,int h,int l);

public:
    QVector<QPoint> points;
    QPoint pos;

private:
    QSharedDataPointer<BlockData> data;
};

#endif // BLOCK_H
