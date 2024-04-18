#ifndef GAME1_H
#define GAME1_H

#include <QWidget>
#include <QKeyEvent>
#include "win.h"

namespace Ui {
class game1;
}

class game1 : public QWidget
{
    Q_OBJECT

public:
    explicit game1(QWidget *parent = nullptr);
    ~game1();

private:
    Ui::game1 *ui;
    int maximum;

signals:

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    //void paintEvent(QPaintEvent *ev);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void updatelabel();
};

#endif // GAME1_H
