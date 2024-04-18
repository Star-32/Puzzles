#ifndef cspyl_H
#define cspyl_H

#include <QWidget>
#include "gamewin.h"

namespace Ui {
class cspyl;
}

class cspyl : public QWidget
{
    Q_OBJECT

public:
    explicit cspyl(QWidget *parent = nullptr);
    ~cspyl();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::cspyl *ui;
    QTimer *timer;
};

#endif // cspyl_H
