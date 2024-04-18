#ifndef noiyl_H
#define noiyl_H

#include <QWidget>
#include "gamewin.h"

namespace Ui {
class noiyl;
}

class noiyl : public QWidget
{
    Q_OBJECT

public:
    explicit noiyl(QWidget *parent = nullptr);
    ~noiyl();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::noiyl *ui;
    QTimer *timer;
};

#endif // noiyl_H
