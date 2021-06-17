#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <QWidget>

namespace Ui {
class Production;
}

class Production : public QWidget
{
    Q_OBJECT

public:
    explicit Production(QWidget *parent = nullptr);
    ~Production();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Del_clicked();

    void on_pushButton_Print_clicked();

private:
    Ui::Production *ui;
};

#endif // PRODUCTION_H
