#ifndef noi274_H
#define noi274_H

#include <QWidget>
#include <QTextToSpeech>
#include "gamewin.h"

namespace Ui {
class noi274;
}

class noi274 : public QWidget
{
    Q_OBJECT

public:
    explicit noi274(QWidget *parent = nullptr);
    gamewin *game;
    ~noi274();

private slots:
    void timeoutslots();

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Ui::noi274 *ui;
    QTimer *timer;
};

#endif // noi274_H
