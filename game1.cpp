#include "game1.h"
#include "ui_game1.h"

game1::game1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game1)
{
    ui->setupUi(this);
    ui->widget->setFocusPolicy(Qt::NoFocus);
    setMinimumSize(15*40, 20*40);
    setWindowTitle("俄罗斯游戏");
    ui->label->setText("新游戏");
    QPixmap bgImage = QPixmap(":/tiger/tigerA");
    QLabel *bk = new QLabel(this);
    bk->lower();
    bk->setStyleSheet("background-color:black");
    bk->setAlignment(Qt::AlignCenter);
    bk->setPixmap(bgImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->label->setWordWrap(1);
    maximum = 0;
    connect(ui->widget,SIGNAL(gameover()),this,SLOT(updatelabel()));
}

game1::~game1()
{
    delete ui;
}

void game1::keyPressEvent(QKeyEvent *e){
    ui->widget->keypress(e->key());
    QWidget::keyPressEvent(e);
}

void game1::on_pushButton_clicked()
{
    ui->widget->timer->stop();
    ui->widget->nowblock.Initblock();
    ui->widget->count = 0;
}


void game1::on_pushButton_2_clicked()
{
    ui->widget->count = 0;
    ui->widget->timer->start(100);
}

void game1::updatelabel(){
    maximum = qMax(maximum,ui->widget->count);
    QString str = "你坚持了 " + QString::number(ui->widget->count) + " 轮，最好成绩 " + QString::number(maximum) + " 轮。";
    ui->label->setText(str);
}

/*void game1::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/tiger/tigerC"),QRect());
}*/
