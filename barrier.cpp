#include "barrier.h"

class barrierData : public QSharedData
{
public:

};

barrier::barrier() : data(new barrierData)
{
    Initbarrier();
}

barrier::barrier(const barrier &rhs)
    : data{rhs.data}
{

}

barrier &barrier::operator=(const barrier &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

barrier::~barrier()
{

}

void barrier::Initbarrier(){
    a.seed(time(0));
    points.clear();
    int x = a.generate() % 13 + 1, y = a.generate() % 18 + 1;
    pos=QPoint(x,y);
    points.push_back(pos);
}

void barrier::Move(int x,int y){
    for(int i=0;i<points.size();i++){
        int tx=points[i].x()+x,ty=points[i].y()+y;
        points[i].setX(tx),points[i].setY(ty);
    }
    pos=pos+QPoint(x,y);
}

void barrier::Draw(QPainter &painter,int stx,int sty,int h,int l){
    for(int i=0;i<points.size();i++){
        QPoint now=points[i];
        painter.drawRect(QRect(stx+now.x()*h,sty+now.y()*l,h,l));
    }
}
