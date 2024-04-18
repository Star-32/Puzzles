#include "browser.h"
#include "ui_browser.h"

browser::browser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::browser)
{
    ui->setupUi(this);
    myweb = new SWebEngineView(this);
    ui->horizontalLayout->addWidget(ui->pushButton_3);
    ui->horizontalLayout->addWidget(ui->lineEdit);
    //ui->horizontalLayout->addWidget(ui->pushButton);
    ui->pushButton->hide();
    ui->horizontalLayout->addWidget(ui->pushButton_2);
    ui->verticalLayout->addWidget(myweb);
    ui->verticalLayout->addLayout(ui->horizontalLayout);
    myweb->load(QUrl("http://star-32.github.io"));
    //timer = new QTimer;
    //timer->start(100);
    connect(myweb,SIGNAL(urlChanged(QUrl)),this,SLOT(updateurl()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslot()));
}

browser::~browser()
{
    delete ui;
}

void browser::on_pushButton_clicked()
{
    QString url = ui->lineEdit->text();
    if(!url.isEmpty()){
        myweb->load(url);
    }
}

void browser::on_pushButton_2_clicked()
{
    myweb->reload();
}


void browser::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}


void browser::on_pushButton_3_clicked()
{
    if(myweb->stk->size() < 2) return;
    myweb->stk->pop();
    myweb->load(myweb->stk->top());
}

void browser::updateurl()
{
    ui->lineEdit->setText(myweb->url().toString());
    if(myweb->stk->empty() || myweb->stk->top() != myweb->url())
        myweb->stk->push(myweb->url());
}

/*void browser::timeoutslots()
{
    QUrl now = myweb->url();
    if(myweb->stk->empty() || now != myweb->stk->top()){
        myweb->stk->push(now);
    }
}*/
