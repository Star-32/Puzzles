#ifndef csp274_H
#define csp274_H

#include <QWidget>
#include <QTextToSpeech>
#include "gamewin.h"

namespace Ui {
class csp274;
}

class csp274 : public QWidget
{
    Q_OBJECT

public:
    explicit csp274(QWidget *parent = nullptr);
    ~csp274();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::csp274 *ui;
    QTimer *timer;
};

#endif // csp274_H
