#include "generalwindow.h"
#include "ui_generalwindow.h"

GeneralWindow::GeneralWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::GeneralWindow)
{
    ui->setupUi(this);

    //Тінь фрейму
    QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
    shadow_effect1->setOffset(0, 0);
    shadow_effect1->setColor(QColor(38, 78, 119, 127));
    shadow_effect1->setBlurRadius(22);
    ui->frame1->setGraphicsEffect(shadow_effect1);

    //Підключаємо базу даних для таблиці Виготовлена продукція
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.db);
    qry1->prepare("SELECT Продукція,Кількість,Дата,Зміна FROM made_production");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->tableViewCakes->setModel(modal1);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    conn.closeDB();

    //Підключаємо базу даних для таблиці Використана сировина
    conn.connectToDB();
    QSqlQueryModel * modal2=new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(conn.db);
    qry2->prepare("SELECT Сировина,Кількість,Дата,Зміна FROM used_raw");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->tableViewRaw->setModel(modal2);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    conn.closeDB();

    //Підключаємо базу даних для таблиці Відправлення на магазини
    conn.connectToDB();
    QSqlQueryModel * modal3=new QSqlQueryModel();
    QSqlQuery* qry3 = new QSqlQuery(conn.db);
    qry3->prepare("SELECT Магазин,Продукція,Кількість,Дата,Зміна FROM send_to_shops");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->tableView->setModel(modal3);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    conn.closeDB();

    conn.connectToDB();
    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* query5 = new QSqlQuery(conn.db);
    query5->prepare("SELECT FullName FROM employees_info");
    query5->exec();
    modal5->setQuery(*query5);
    ui->comboBoxEmp1->setModel(modal5);
    ui->comboBoxEmp2->setModel(modal5);
    ui->comboBoxEmp3->setModel(modal5);
    conn.closeDB();
}

GeneralWindow::~GeneralWindow()
{
    delete ui;
}

void GeneralWindow::on_EditData_clicked()
{
    EditData ed;
    this->close();
    ed.setModal(true);
    ed.exec();
}


void GeneralWindow::on_LogOut_clicked()
{
    Login l;
    this->close();
}

void GeneralWindow::on_AddDailyWork_clicked()
{
    DailyReport r;
    this->close();
    r.setModal(true);
    r.exec();
}


void GeneralWindow::on_pushButtonFindEmp1_clicked()
{
    const QString employee = ui->comboBoxEmp1->currentText();
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* query5 = new QSqlQuery(conn.db);
    query5->prepare("SELECT Продукція,Кількість,Дата,Зміна from made_production where Зміна='"+employee+"'");
    query5->exec();
    modal5->setQuery(*query5);
    ui->tableViewCakes->setModel(modal5);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    conn.closeDB();
}


void GeneralWindow::on_pushButtonFindDate1_clicked()
{
    const QString date = ui->dateEdit1->text();
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.db);
    qry1->prepare("SELECT Продукція,Кількість,Дата,Зміна from made_production where Дата='"+date+"'");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->tableViewCakes->setModel(modal1);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableViewCakes->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    conn.closeDB();
}


void GeneralWindow::on_pushButtonFindEmp2_clicked()
{
    const QString employee = ui->comboBoxEmp2->currentText();
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* query5 = new QSqlQuery(conn.db);
    query5->prepare("SELECT Сировина,Кількість,Дата,Зміна from used_raw where Зміна='"+employee+"'");
    query5->exec();
    modal5->setQuery(*query5);
    ui->tableViewRaw->setModel(modal5);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    conn.closeDB();
}


void GeneralWindow::on_pushButtonFindDate2_clicked()
{
    const QString date = ui->dateEdit2->text();
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.db);
    qry1->prepare("SELECT Сировина,Кількість,Дата,Зміна from used_raw where Дата='"+date+"'");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->tableViewRaw->setModel(modal1);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableViewRaw->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    conn.closeDB();
}


void GeneralWindow::on_pushButtonFindEmp3_clicked()
{
    const QString employee = ui->comboBoxEmp3->currentText();
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* query5 = new QSqlQuery(conn.db);
    query5->prepare("SELECT Магазин,Продукція,Кількість,Дата,Зміна FROM send_to_shops where Зміна='"+employee+"'");
    query5->exec();
    modal5->setQuery(*query5);
    ui->tableView->setModel(modal5);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    conn.closeDB();
}


void GeneralWindow::on_pushButtonFindDate3_clicked()
{
    const QString date = ui->dateEdit3->text();
    Login conn;
    conn.connectToDB();
    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.db);
    qry1->prepare("SELECT Магазин,Продукція,Кількість,Дата,Зміна FROM send_to_shops where Дата='"+date+"'");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->tableView->setModel(modal1);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    conn.closeDB();
}

