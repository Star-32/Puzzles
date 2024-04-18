#include "empty.h"
#include "ui_empty.h"

empty::empty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::empty)
{
    ui->setupUi(this);
    a.seed(time(0));
    QPixmap *pixmap;
    int tp = a.generate() % 5;
    switch(tp){
    case 0:
        pixmap= new QPixmap(":/tiger/tigerA");//加载图片
        break;
    case 1:
        pixmap= new QPixmap(":/tiger/tigerB");//加载图片
        break;
    case 2:
        pixmap= new QPixmap(":/tiger/tigerC");//加载图片
        break;
    case 3:
        pixmap= new QPixmap(":/tiger/tigerD");//加载图片
        break;
    case 4:
        pixmap= new QPixmap(":/tiger/tigerE");//加载图片
        break;
    }
    setWindowTitle("老虎咬人");
    QImage image = pixmap->toImage();
    int ht = image.height(), wd = image.width();
    setFixedSize(wd,ht);
    ui->label->setGeometry(0,0,wd,ht);
    ui->label->setScaledContents(true);//设置label全填效果
    ui->label->setPixmap(*pixmap);//把图片放到label中，其他控件加载图片思路一样的
}

empty::~empty()
{
    delete ui;
}
