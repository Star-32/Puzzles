#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTime>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QLineEdit>
#include <QTextCodec>
#include <QTextToSpeech>
#include <QDebug>
#include <QVBoxLayout>
#include <QString>
#include <QListView>
#include <QtGlobal>
#include <QStringListModel>
#include "enteranswer.h"
#include "win.h"
#include "lose.h"
#include "getname.h"
#include "cspkwants.h"
#include "gamewin.h"
#include "csp274.h"
#include "cspyl.h"
#include "noipkwants.h"
#include "noip274.h"
#include "noipyl.h"
#include "noikwants.h"
#include "noi274.h"
#include "noiyl.h"
#include "gamea.h"
#include "game1.h"
#include "empty.h"
#include "browser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionQuit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    class OIgame{
    public:
        int player;
        bool rand_or_not;
    }game[5];


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_textActivated(const QString &arg1);

    void on_comboBox_2_textActivated(const QString &arg1);

    void on_comboBox_3_textActivated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_action_triggered();

    void on_actiontiger_triggered();

    void on_actionbrowser_triggered();

    void on_pushButton_5_clicked();

    void musicstop();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
    QListView *listview;
    QStringListModel *stringlistmodel;
    QTextToSpeech *reader;

signals:

protected:
    virtual void keyPressEvent(QKeyEvent *e);


};
#endif // MAINWINDOW_H
