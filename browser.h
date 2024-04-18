#ifndef BROWSER_H
#define BROWSER_H

#include <QWidget>
#include <QWebEngineView>
#include <QStackedLayout>
#include <QTimer>
#include "swebengineview.h"

namespace Ui {
class browser;
}

class browser : public QWidget
{
    Q_OBJECT

public:
    explicit browser(QWidget *parent = nullptr);
    ~browser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_3_clicked();

    void updateurl();

    //void timeoutslots();

private:
    Ui::browser *ui;
    SWebEngineView *myweb;
    QTimer *timer;
};

#endif // BROWSER_H
