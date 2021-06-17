#ifndef DAILYWORK_H
#define DAILYWORK_H

#include <QDialog>
#include "generalwindow.h"

namespace Ui {
class DailyWork;
}

class DailyWork : public QDialog
{
    Q_OBJECT

public:
    explicit DailyWork(QWidget *parent = nullptr);
    ~DailyWork();

private slots:
    void on_BackToGeneralWindow_clicked();

private:
    Ui::DailyWork *ui;
};

#endif // DAILYWORK_H
