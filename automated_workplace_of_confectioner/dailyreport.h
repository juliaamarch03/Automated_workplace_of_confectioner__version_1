#ifndef DAILYREPORT_H
#define DAILYREPORT_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include "generalwindow.h"
#include "login.h"

namespace Ui {
class DailyReport;
}

class DailyReport : public QDialog
{
    Q_OBJECT

public:
    explicit DailyReport(QWidget *parent = nullptr);
    ~DailyReport();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_AddCake_clicked();
    void on_pushButton_DelCake_clicked();
    void on_pushButton_AddRaw_clicked();
    void on_pushButton_DelRaw_clicked();
    void on_pushButton_AddShop_clicked();
    void on_pushButton_DelShop_clicked();

private:
    Ui::DailyReport *ui;
    enum{
        IdC,
        NameC,
        QuantityC,
        DateC,
        NameEmpC
    };
};

#endif // DAILYREPORT_H
