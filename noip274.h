#ifndef noip274_H
#define noip274_H

#include <QWidget>
#include <QTextToSpeech>
#include "gamewin.h"

namespace Ui {
class noip274;
}

class noip274 : public QWidget
{
    Q_OBJECT

public:
    explicit noip274(QWidget *parent = nullptr);
    ~noip274();

private slots:
    void timeoutslots();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::noip274 *ui;
    QTimer *timer;
};

#endif // noip274_H
