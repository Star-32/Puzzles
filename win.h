#ifndef WIN_H
#define WIN_H

#include <QDialog>

namespace Ui {
class Win;
}

class Win : public QDialog
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = nullptr);
    ~Win();

private:
    Ui::Win *ui;
};

#endif // WIN_H
