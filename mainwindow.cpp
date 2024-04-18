#include "mainwindow.h"
#include "enteranswer.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("229解密游戏");
    stringlistmodel=new QStringListModel(ui->listView);
    reader = new QTextToSpeech;
    ui->listView->setModel(stringlistmodel);
    qsrand(time(0));srand(time(0));
    game[1].rand_or_not = game[2].rand_or_not = game[3].rand_or_not = 1;
    stringlistmodel->setStringList(QStringList()<<"赵悦岑"<<"周与锋"<<"王睿嘉");
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::on_actionNew_triggered);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::on_actionOpen_triggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::on_actionSave_triggered);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::on_actionCopy_triggered);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::on_actionPaste_triggered);
    connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::on_actionRedo_triggered);
    connect(ui->actionUndo, &QAction::triggered, this, &MainWindow::on_actionUndo_triggered);
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::on_actionCut_triggered);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::on_actionQuit_triggered);
    connect(ui->widget, SIGNAL(music_stop()),this, SLOT(musicstop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    EnterAnswer ans;Win win;lose lose;
    ans.exec();
    QString Read=ans.getans();
    if(Read=="22")win.exec();
    else lose.exec();
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","Cannot open file: "+file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","Cannot save file: "+file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();


}

/*void MainWindow::on_actionPrint_triggered()
{
    //    QPrinter printer;
    //    printer.setPrinterName("Printer Name");
    //    QPrintDialog pDialog(&printer,this);
    //    if (pDialog.exec()==QDialog::Rejected){
    //        QMessageBox::warning(this,"warning","Cannot access printer");
    //        return;
    //    }
    //    ui->textEdit->print(&printer);
}
*/
void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_pushButton_2_clicked()
{
    getname name;
    name.exec();
    QString read=name.get();
    if(read.isEmpty())return;
    int row=stringlistmodel->rowCount();
    stringlistmodel->insertRow(row);
    QModelIndex index=stringlistmodel->index(row);
    stringlistmodel->setData(index,read);
    ui->listView->setCurrentIndex(index);
}


void MainWindow::on_pushButton_3_clicked()
{
    int row=ui->listView->currentIndex().row();
    if(row==-1){
        return;
    }
    stringlistmodel->removeRow(row);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Up){
        Win *a=new Win;
        a->show();
        return;
    }
    //ui->widget->keypress(e->key());
    QMainWindow::keyPressEvent(e);
}

void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
    if(arg1=="随机")game[1].player = qrand() % 3, game[1].rand_or_not = 1;
    else if(arg1=="苏师傅")game[1].player = 0, game[1].rand_or_not = 0;
    else if(arg1=="酥师傅")game[1].player = 1, game[1].rand_or_not = 0;
    else if(arg1=="颜黎")game[1].player = 2, game[1].rand_or_not = 0;
}


void MainWindow::on_comboBox_2_textActivated(const QString &arg1)
{
    if(arg1=="随机")game[2].player = qrand() % 3, game[2].rand_or_not = 1;
    else if(arg1=="苏师傅")game[2].player = 0, game[2].rand_or_not = 0;
    else if(arg1=="酥师傅")game[2].player = 1, game[2].rand_or_not = 0;
    else if(arg1=="颜黎")game[2].player = 2, game[2].rand_or_not = 0;
}


void MainWindow::on_comboBox_3_textActivated(const QString &arg1)
{
    if(arg1=="随机")game[3].player = rand() % 3, game[3].rand_or_not = 1;
    else if(arg1=="苏师傅")game[3].player = 0, game[3].rand_or_not = 0;
    else if(arg1=="酥师傅")game[3].player = 1, game[3].rand_or_not = 0;
    else if(arg1=="颜黎")game[3].player = 2, game[3].rand_or_not = 0;
}


void MainWindow::on_pushButton_4_clicked()
{
    int map = rand() % 3;
    if(map==2){
        if(game[3].rand_or_not)game[3].player = rand() % 3;
        if(game[3].player==0){
            cspkwants *csp=new cspkwants;
            csp->show();
        }
        if(game[3].player==1){
            csp274 *csp=new csp274;
            csp->show();
        }
        if(game[3].player==2){
            cspyl *csp=new cspyl;
            csp->show();
        }
    }
    if(map==1){
        if(game[2].rand_or_not)game[2].player = rand() % 3;
        if(game[2].player==0){
            noikwants *csp=new noikwants;
            csp->show();
        }
        if(game[2].player==1){
            noi274 *noi2 = new noi274;
            noi2->show();
        }
        if(game[2].player==2){
            noiyl *csp=new noiyl;
            csp->show();
        }
    }
    if(map==0){
        if(game[1].rand_or_not)game[1].player = rand() % 3;
        if(game[1].player==0){
            noipkwants *csp=new noipkwants;
            csp->show();
        }
        if(game[1].player==1){
            noip274 *csp=new noip274;
            csp->show();
        }
        if(game[1].player==2){
            noipyl *csp=new noipyl;
            csp->show();
        }
    }
}

void MainWindow::on_action_triggered()
{
    game1 *newgame = new game1;
    newgame->show();
}


void MainWindow::on_actiontiger_triggered()
{
    empty *newwindow = new empty;
    newwindow->show();
}


void MainWindow::on_actionbrowser_triggered()
{
    browser *newweb = new browser;
    newweb->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    QString str = ui->textEdit->toPlainText();
    reader->say(str);
}

void MainWindow::musicstop(){
    reader->stop();
}
