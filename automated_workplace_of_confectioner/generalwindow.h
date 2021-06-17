#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QFileInfo>
#include "editdata.h"
#include "login.h"
#include "dailyreport.h"

namespace Ui {
class GeneralWindow;
}

class GeneralWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralWindow(QDialog *parent = nullptr);
    ~GeneralWindow();
signals:
    void firstWindow();
private slots:
    void on_EditData_clicked();
    void on_LogOut_clicked();
    void on_AddDailyWork_clicked();
    void on_pushButtonFindEmp1_clicked();

    void on_pushButtonFindDate1_clicked();

    void on_pushButtonFindEmp2_clicked();

    void on_pushButtonFindDate2_clicked();

    void on_pushButtonFindEmp3_clicked();

    void on_pushButtonFindDate3_clicked();

private:
    Ui::GeneralWindow *ui;
};

#endif // GENERALWINDOW_H
