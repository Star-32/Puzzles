#ifndef noikwants_H
#define noikwants_H

#include <QWidget>
#include "gamewin.h"

namespace Ui {
class noikwants;
}

class noikwants : public QWidget
{
    Q_OBJECT

public:
    explicit noikwants(QWidget *parent = nullptr);
    ~noikwants();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::noikwants *ui;
    QTimer *timer;
};

#endif // noikwants_H
