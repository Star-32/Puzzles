#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QWidget>

namespace Ui {
class gamewin;
}

class gamewin : public QWidget
{
    Q_OBJECT

public:
    explicit gamewin(QWidget *parent = nullptr);
    ~gamewin();

private:
    Ui::gamewin *ui;
};

#endif // GAMEWIN_H
