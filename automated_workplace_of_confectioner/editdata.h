#ifndef EDITDATA_H
#define EDITDATA_H
#include <QWidget>
#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "login.h"
#include "generalwindow.h"

namespace Ui {
class EditData;
}

class EditData : public QDialog
{
    Q_OBJECT

public:
    explicit EditData(QDialog *parent = nullptr);
    ~EditData();

private:
    Ui::EditData *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
signals:
    void firstWindow();
private slots:
    void on_BackToGeneralWindow_clicked();
    void on_del_cake_clicked();
    void on_pushButton_AddCake_clicked();
    void on_update_data_cake_clicked();
    void on_del_raw_clicked();
    void on_del_shop_clicked();
    void on_update_data_raw_clicked();
    void on_update_data_shop_clicked();
    void on_add_raw_clicked();
    void on_add_shop_clicked();
};

#endif // EDITDATA_H
