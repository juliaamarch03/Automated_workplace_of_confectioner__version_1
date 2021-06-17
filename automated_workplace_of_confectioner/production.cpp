#include "production.h"
#include "ui_production.h"

Production::Production(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Production)
{
    ui->setupUi(this);
}

Production::~Production()
{
    delete ui;
}

void Production::on_pushButton_Add_clicked()
{
    QString id;
}


void Production::on_pushButton_Del_clicked()
{

}


void Production::on_pushButton_Print_clicked()
{

}

