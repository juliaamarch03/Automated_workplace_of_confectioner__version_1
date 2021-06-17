#include "dailyreport.h"
#include "ui_dailyreport.h"

DailyReport::DailyReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailyReport)
{
    ui->setupUi(this);
    //Тінь фрейму
    QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
    shadow_effect1->setOffset(0, 0);
    shadow_effect1->setColor(QColor(38, 78, 119, 127));
    shadow_effect1->setBlurRadius(22);
    ui->frame->setGraphicsEffect(shadow_effect1);

    //Таблиця продукція
    const QStringList titles1{"№","Продукція","К-сть(кг)","Дата","Зміна"};
    ui->tableWidgetCakes->setColumnCount(titles1.size());
    ui->tableWidgetCakes->setHorizontalHeaderLabels(titles1);
    ui->spinBoxIdC->setMinimum(0);
    ui->spinBoxIdC->setMaximum(INT_MAX);
    ui->doubleSpinBoxQC->setMinimum(0.0);
    ui->doubleSpinBoxQC->setMaximum(999999999.0);
    ui->tableWidgetCakes->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidgetCakes->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);

    //Таблиця сировина
    const QStringList titles2{"№","Сировина","К-сть(кг)","Дата","Зміна"};
    ui->tableWidget_Raw->setColumnCount(titles2.size());
    ui->tableWidget_Raw->setHorizontalHeaderLabels(titles2);
    ui->spinBoxIdR->setMinimum(0);
    ui->spinBoxIdR->setMaximum(INT_MAX);
    ui->doubleSpinBoxQR->setMinimum(0.0);
    ui->doubleSpinBoxQR->setMaximum(999999999.0);
    ui->tableWidget_Raw->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_Raw->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);

    //Таблиця збут
    const QStringList titles3{"№","Магазини","Продукція","К-сть(кг)","Дата","Зміна"};
    ui->tableWidget_Shops->setColumnCount(titles3.size());
    ui->tableWidget_Shops->setHorizontalHeaderLabels(titles3);
    ui->spinBoxIdS->setMinimum(0);
    ui->spinBoxIdS->setMaximum(INT_MAX);
    ui->doubleSpinBoxQS->setMinimum(0.0);
    ui->doubleSpinBoxQS->setMaximum(999999999.0);
    ui->tableWidget_Shops->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_Shops->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget_Shops->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);

    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery* query1 = new QSqlQuery(conn.db);
    query1->prepare("SELECT Продукція FROM cakes");
    query1->exec();
    modal1->setQuery(*query1);
    ui->comboBoxCakes->setModel(modal1);
    ui->comboBoxCakes2->setModel(modal1);
    conn.closeDB();

    conn.connectToDB();
    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* query2 = new QSqlQuery(conn.db);
    query2->prepare("SELECT Сировина FROM raw");
    query2->exec();
    modal2->setQuery(*query2);
    ui->comboBoxRaw->setModel(modal2);
    conn.closeDB();

    conn.connectToDB();
    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QSqlQuery* query3 = new QSqlQuery(conn.db);
    query3->prepare("SELECT Магазини FROM shops");
    query3->exec();
    modal3->setQuery(*query3);
    ui->comboBoxShops->setModel(modal3);
    conn.closeDB();

    conn.connectToDB();
    QSqlQueryModel * modal4 = new QSqlQueryModel();
    QSqlQuery* query4 = new QSqlQuery(conn.db);
    query4->prepare("SELECT FullName FROM employees_info");
    query4->exec();
    modal4->setQuery(*query4);
    ui->comboBoxEmp1->setModel(modal4);
    ui->comboBoxEmp2->setModel(modal4);
    ui->comboBoxEmp3->setModel(modal4);
    conn.closeDB();
}

DailyReport::~DailyReport()
{
    delete ui;
}

void DailyReport::on_pushButton_clicked()
{
    GeneralWindow gw;
    this->close();
    gw.setModal(true);
    gw.exec();
}


void DailyReport::on_pushButton_AddCake_clicked()
{
    const QString id = QString::number(ui->spinBoxIdC->value());
    const QString production = ui->comboBoxCakes->currentText();
    const QString quantity = QString::number(ui->doubleSpinBoxQC->value());
    const QString date = ui->dateEditDateC->text();
    const QString employee = ui->comboBoxEmp1->currentText();

    const int rowCount = ui->tableWidgetCakes->rowCount();
    ui->tableWidgetCakes->insertRow(rowCount);
    ui->tableWidgetCakes->setItem(rowCount,IdC,new QTableWidgetItem(id));
    ui->tableWidgetCakes->setItem(rowCount,NameC,new QTableWidgetItem(production));
    ui->tableWidgetCakes->setItem(rowCount,QuantityC,new QTableWidgetItem(quantity));
    ui->tableWidgetCakes->setItem(rowCount,DateC,new QTableWidgetItem(date));
    ui->tableWidgetCakes->setItem(rowCount,NameEmpC,new QTableWidgetItem(employee));

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("insert into made_production (Number,Продукція,Кількість,Дата,Зміна) values ('"+id+"','"+production+"','"+quantity+"','"+date+"','"+employee+"')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Добавлено"),tr("Успішно добавлено в базу даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час додавання даних в базу даних виникла помилка"));
    }

    ui->spinBoxIdC->clear();
    ui->doubleSpinBoxQC->clear();
    ui->dateEditDateC->clear();
    ui->spinBoxIdC->setFocus();
}


void DailyReport::on_pushButton_DelCake_clicked()
{
    const QString id = QString::number(ui->spinBoxIdC->value());
    ui->tableWidgetCakes->removeRow(ui->tableWidgetCakes->currentRow());
    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("Delete from made_production where Number='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Видалено"),tr("Успішно видалено з бази даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час видалення даних з бази даних виникла помилка"));
    }
}


void DailyReport::on_pushButton_AddRaw_clicked()
{
    const QString id = QString::number(ui->spinBoxIdR->value());
    const QString raw = ui->comboBoxRaw->currentText();
    const QString quantity = QString::number(ui->doubleSpinBoxQR->value());
    const QString date = ui->dateEditDateR->text();
    const QString employee = ui->comboBoxEmp2->currentText();

    const int rowCount = ui->tableWidget_Raw->rowCount();
    ui->tableWidget_Raw->insertRow(rowCount);
    ui->tableWidget_Raw->setItem(rowCount,IdC,new QTableWidgetItem(id));
    ui->tableWidget_Raw->setItem(rowCount,NameC,new QTableWidgetItem(raw));
    ui->tableWidget_Raw->setItem(rowCount,QuantityC,new QTableWidgetItem(quantity));
    ui->tableWidget_Raw->setItem(rowCount,DateC,new QTableWidgetItem(date));
    ui->tableWidget_Raw->setItem(rowCount,NameEmpC,new QTableWidgetItem(employee));

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("insert into used_raw (Number,Сировина,Кількість,Дата,Зміна) values ('"+id+"','"+raw+"','"+quantity+"','"+date+"','"+employee+"')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Добавлено"),tr("Успішно добавлено в базу даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час додавання даних в базу даних виникла помилка"));
    }

    ui->spinBoxIdR->clear();
    ui->doubleSpinBoxQR->clear();
    ui->dateEditDateR->clear();
    ui->spinBoxIdR->setFocus();
}


void DailyReport::on_pushButton_DelRaw_clicked()
{
    const QString id = QString::number(ui->spinBoxIdR->value());
    ui->tableWidget_Raw->removeRow(ui->tableWidget_Raw->currentRow());
    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("Delete from used_raw where Number='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Видалено"),tr("Успішно видалено з бази даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час видалення даних з бази даних виникла помилка"));
    }
}


void DailyReport::on_pushButton_AddShop_clicked()
{
    const QString id = QString::number(ui->spinBoxIdS->value());
    const QString shop = ui->comboBoxShops->currentText();
    const QString production = ui->comboBoxCakes2->currentText();
    const QString quantity = QString::number(ui->doubleSpinBoxQS->value());
    const QString date = ui->dateEditDateS->text();
    const QString employee = ui->comboBoxEmp3->currentText();

    const int rowCount = ui->tableWidget_Shops->rowCount();
    ui->tableWidget_Shops->insertRow(rowCount);
    ui->tableWidget_Shops->setItem(rowCount,IdC,new QTableWidgetItem(id));
    ui->tableWidget_Shops->setItem(rowCount,NameC,new QTableWidgetItem(shop));
    ui->tableWidget_Shops->setItem(rowCount,NameC,new QTableWidgetItem(production));
    ui->tableWidget_Shops->setItem(rowCount,QuantityC,new QTableWidgetItem(quantity));
    ui->tableWidget_Shops->setItem(rowCount,DateC,new QTableWidgetItem(date));
    ui->tableWidget_Shops->setItem(rowCount,NameEmpC,new QTableWidgetItem(employee));

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("insert into send_to_shops (Number,Магазин,Продукція,Кількість,Дата,Зміна) values ('"+id+"','"+shop+"','"+production+"','"+quantity+"','"+date+"','"+employee+"')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Добавлено"),tr("Успішно добавлено в базу даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час додавання даних в базу даних виникла помилка"));
    }

    ui->spinBoxIdS->clear();
    ui->doubleSpinBoxQS->clear();
    ui->dateEditDateS->clear();
    ui->spinBoxIdS->setFocus();
}


void DailyReport::on_pushButton_DelShop_clicked()
{
    const QString id = QString::number(ui->spinBoxIdS->value());
    ui->tableWidget_Shops->removeRow(ui->tableWidget_Shops->currentRow());
    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("Delete from send_to_shops where Number='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Видалено"),tr("Успішно видалено з бази даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час видалення даних з бази даних виникла помилка"));
    }
}
