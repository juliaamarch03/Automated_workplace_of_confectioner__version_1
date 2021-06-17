#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QFileInfo>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include "editdata.h"
#include "generalwindow.h"
#include "production.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QDialog *parent = nullptr);
    ~Login();
    QSqlDatabase db;
    bool connectToDB();
    void closeDB();
private slots:
    void on_pushButton_SignIn_clicked();
signals:
    void firstWindow();
private:
    Ui::Login *ui;
};
#endif // LOGIN_H
