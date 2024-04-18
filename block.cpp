#include "block.h"

class BlockData : public QSharedData
{
public:

};

Block::Block() : data(new BlockData)
{
    Initblock();
}

Block::Block(const Block &rhs)
    : data{rhs.data}
{

}

Block &Block::operator=(const Block &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Block::~Block()
{

}

void Block::Initblock(){
    points.clear();
    pos=QPoint(6,9);
    points.push_back(pos+QPoint(1,0));
    points.push_back(pos+QPoint(1,1));
    points.push_back(pos+QPoint(1,2));
    points.push_back(pos+QPoint(2,2));
}

void Block::Move(int x,int y){
    for(int i=0;i<points.size();i++){
        int tx=points[i].x()+x,ty=points[i].y()+y;
        points[i].setX(tx),points[i].setY(ty);
    }
    pos=pos+QPoint(x,y);
}

void Block::Draw(QPainter &painter,int stx,int sty,int h,int l){
    for(int i=0;i<points.size();i++){
        QPoint now=points[i];
        painter.drawRect(QRect(stx+now.x()*h,sty+now.y()*l,h,l));
    }
}
