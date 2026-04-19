#include "widget.h"
#include "ui_widget.h"


widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
}

widget::~widget()
{
    delete ui;
}

void widget::on_pushButton_clicked()
{
    ui->pushButton->setFocus();
    str[i]=ui->textEdit->toPlainText();
    ui->textEdit->setReadOnly(true);

}

void widget::restring()
{
    ui->textEdit->setPlainText(str[i]);
    ui->textEdit->setReadOnly(false);
}

void widget::on_pushButton_2_clicked()
{
    ui->pushButton_2->setFocus();
    ui->textEdit->setReadOnly(false);
}


void widget::on_pushButton_3_clicked()
{
    ui->pushButton_3->setFocus();
    this->hide();
}




