#include "swebengineview.h"
SWebEngineView::SWebEngineView(QWidget *parent) : QWebEngineView(parent)
{
    stk = new QStack<QUrl>;
}
QWebEngineView *SWebEngineView::createWindow(QWebEnginePage::WebWindowType type)
{
    Q_UNUSED(type);
    return this;
}
