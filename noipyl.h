#ifndef noipyl_H
#define noipyl_H

#include <QWidget>
#include "gamelose.h"

namespace Ui {
class noipyl;
}

class noipyl : public QWidget
{
    Q_OBJECT

public:
    explicit noipyl(QWidget *parent = nullptr);
    ~noipyl();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::noipyl *ui;
    QTimer *timer;
};

#endif // noipyl_H
