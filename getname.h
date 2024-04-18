#ifndef GETNAME_H
#define GETNAME_H
#include <QString>
#include <QDialog>

namespace Ui {
class getname;
}

class getname : public QDialog
{
    Q_OBJECT

public:
    explicit getname(QWidget *parent = nullptr);
    ~getname();
    QString get();

private slots:
    void on_pushButton_clicked();

private:
    Ui::getname *ui;
};

#endif // GETNAME_H
