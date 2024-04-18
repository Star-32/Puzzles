#include "gamea.h"
#include "ui_gamea.h"
#include <QKeyEvent>
#include <qpainter.h>

#define RECT_WIDTH        40   //每个小格子40个像素宽
#define RECT_HEIGHT        40   //每个小格子40个像素高

gamea::gamea(QWidget *parent) : QWidget(parent)
{
    a.seed(time(0));
    setMinimumSize(15*RECT_WIDTH, 20*RECT_HEIGHT);
    QWidget::update();
    timer = new QTimer(this);
    //连接信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslot()));
}

void gamea::paintEvent(QPaintEvent *event){

    drawback();
    drawblock();
    drawbarrier();
    update();
    /*
    // 创建 QPainter 对象，并指定绘图设备为当前窗口
    QPainter painter(this);

    // 设置绘图属性，如画笔颜色、画刷颜色等
    painter.setPen(Qt::red);
    painter.setBrush(Qt::yellow);

    // 绘制一个矩形
    painter.drawRect(10,10,20,20);
*/
/*
    Q_UNUSED(event);
    //绘图前准备画笔、画刷
    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
    pen.setColor(QColor(255,0,0,255));
    QBrush brush;   //画刷。填充几何图形的调色板，由颜色和填充风格组成
    brush.setColor(QColor(0,255,0,120));
    brush.setStyle(Qt::SolidPattern);
    QPainter painter(this);   //可在QPaintDevice上绘制各种图形。QPaintDevice有之类QWidget、QImage、QOpenGLPaintDevice等
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawLine(QPoint(0,0),QPoint(this->rect().width()-50,0));   //QPainter绘制直线
    painter.drawRect(50,50,200,100);
*/
}

void gamea::drawblock(){
    QPainter painter(this);
    painter.setBrush(QColor("#FFDEAD"));
    painter.setPen(QPen(QColor(Qt::black),1));
    nowblock.Draw(painter,0,0,RECT_WIDTH,RECT_HEIGHT);
}

void gamea::drawbarrier(){
    QPainter painter(this);
    painter.setBrush(QColor("#FFDEAD"));
    painter.setPen(QPen(QColor(Qt::black),1));
    nowbarrier.Draw(painter,0,0,RECT_WIDTH,RECT_HEIGHT);
}


void gamea::drawback(){
    QPainter painter(this);
    painter.setPen(QPen(QColor(Qt::black),5));
    QBrush brush;
    brush.setColor(QColor(255,255,255,155));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(40,40,13*RECT_WIDTH, 18*RECT_HEIGHT);
}

bool gamea::hitside(){
    for(int i=0;i<nowblock.points.size();i++){
        QPoint now=nowblock.points[i];
        if(now.x()<=0||now.x()>=14)return 1;
        if(now.y()<=0||now.y()>=19)return 1;
        if(now==nowbarrier.points[0])return 1;
    }
    return 0;
}

void gamea::keypress(int k){
    int x=0,y=0;
    switch(k){
    case Qt::Key_4:
        x=-1;
        break;
    case Qt::Key_6:
        x=1;
        break;
    case Qt::Key_8:
        y=-1;
        break;
    case Qt::Key_2:
        y=1;
        break;
    }
    nowblock.Move(x,y);
    if(hitside()){
        nowblock.Move(-x,-y);
        timer->stop();
        emit(gameover());
    }
}

void gamea::timeoutslot(){
    int c=a.generate()%4;count++;
    nowbarrier.Initbarrier();
    switch(c){
    case 0:
        keypress(Qt::Key_4);
        break;
    case 1:
        keypress(Qt::Key_6);
        break;
    case 2:
        keypress(Qt::Key_2);
        break;
    case 3:
        keypress(Qt::Key_8);
        break;
    }
}
