#ifndef GAMELOSE_H
#define GAMELOSE_H

#include <QWidget>

namespace Ui {
class gamelose;
}

class gamelose : public QWidget
{
    Q_OBJECT

public:
    explicit gamelose(QWidget *parent = nullptr);
    ~gamelose();

private:
    Ui::gamelose *ui;
};

#endif // GAMELOSE_H
