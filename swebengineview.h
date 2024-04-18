#ifndef SWEBENGINEVIEW_H
#define SWEBENGINEVIEW_H

#include <QWidget>
#include <QWebEngineView>
#include <QStack>

class SWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    explicit SWebEngineView(QWidget *parent = 0);
    QStack<QUrl> *stk;
protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);

signals:
    void newweb();

};

#endif // SWEBENGINEVIEW_H
