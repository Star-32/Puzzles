#ifndef noipkwants_H
#define noipkwants_H

#include <QWidget>
#include "gamewin.h"

namespace Ui {
class noipkwants;
}

class noipkwants : public QWidget
{
    Q_OBJECT

public:
    explicit noipkwants(QWidget *parent = nullptr);
    ~noipkwants();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::noipkwants *ui;
    QTimer *timer;
};

#endif // noipkwants_H
