#ifndef EMPTY_H
#define EMPTY_H

#include <QWidget>
#include <QRandomGenerator>
#include <QColor>

namespace Ui {
class empty;
}

class empty : public QWidget
{
    Q_OBJECT

public:
    explicit empty(QWidget *parent = nullptr);
    ~empty();

private:
    Ui::empty *ui;
    QRandomGenerator a;
};

#endif // EMPTY_H
