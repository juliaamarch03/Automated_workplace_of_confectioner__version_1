#include "report.h"
#include "ui_report.h"

Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}

Report::~Report()
{
    delete ui;
}

void Report::on_BackToGeneralWindow_clicked()
{
    GeneralWindow gw;
    this->close();
    gw.setModal(true);
    gw.exec();
}

