#ifndef ENTERANSWER_H
#define ENTERANSWER_H
#include <QDialog>
#include <QString>

namespace Ui {
class EnterAnswer;
}

class EnterAnswer : public QDialog
{
    Q_OBJECT

public:
    explicit EnterAnswer(QWidget *parent = nullptr);
    ~EnterAnswer();
    QString getans();

private slots:

private:
    Ui::EnterAnswer *ui;
};

#endif // ENTERANSWER_H
