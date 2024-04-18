#ifndef CSPKWANTS_H
#define CSPKWANTS_H

#include <QWidget>
#include "gamewin.h"

namespace Ui {
class cspkwants;
}

class cspkwants : public QWidget
{
    Q_OBJECT

public:
    explicit cspkwants(QWidget *parent = nullptr);
    ~cspkwants();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::cspkwants *ui;
    QTimer *timer;
};

#endif // CSPKWANTS_H
