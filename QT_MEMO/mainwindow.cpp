#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , wd(new widget())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete wd;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentIndex()==0)
    {
        ui->lineEdit->clear();
        return;
    }
    else
    {
        ui->lineEdit->setText(arg1);
    }
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0)
    {
        return;
    }
    else
    {
        wd->restring();
        wd->show();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(ui->comboBox->currentIndex()==0)
    {
        return;
    }
    else
    {
        wd->i=index;
    }
}

