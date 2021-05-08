#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GoodStock.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDialog(){
    char *pStrROE = GetROESearchString();
    if(pStrROE != 0){
        ui->textEdit_ROE->insertPlainText(pStrROE);
        free(pStrROE);
    }
}
