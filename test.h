#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QWidget>

class test : public QWidget
{
    Q_OBJECT
public:
    explicit test(QWidget *parent = nullptr);

signals:

};

#endif // TEST_H
