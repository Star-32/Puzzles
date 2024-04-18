#ifndef GAMEAREA_H
#define GAMEAREA_H

#include "block.h"
#include <QObject>
#include <QWidget>
#include "QPainter"

class gamearea : public QWidget
{
    Q_OBJECT
public:
    explicit gamearea(QWidget *parent = nullptr);

    void drawblock();
    bool hitside();
    void keypress(int key);

private:
    Block nowblock;

protected:
    void paintevent(QPaintEvent *);
};

#endif // GAMEAREA_H
