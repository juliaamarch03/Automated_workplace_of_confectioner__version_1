#include "dailywork.h"
#include "ui_dailywork.h"

DailyWork::DailyWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailyWork)
{
    ui->setupUi(this);
}

DailyWork::~DailyWork()
{
    delete ui;
}

void DailyWork::on_BackToGeneralWindow_clicked()
{
    GeneralWindow gw;
    this->close();
    gw.setModal(true);
    gw.exec();
}

