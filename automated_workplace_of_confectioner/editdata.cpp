#include "editdata.h"
#include "ui_editdata.h"
#include <QMessageBox>

EditData::EditData(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::EditData)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
    shadow_effect1->setOffset(0, 0);
    shadow_effect1->setColor(QColor(38, 78, 119, 127));
    shadow_effect1->setBlurRadius(22);
    ui->frame->setGraphicsEffect(shadow_effect1);


    //Підключаємо базу даних для таблиці Продукція
    Login conn;
    QSqlQueryModel * modal1=new QSqlQueryModel();
    conn.connectToDB();
    QSqlQuery* qry1 = new QSqlQuery(conn.db);
    qry1->prepare("SELECT Код,Продукція FROM cakes");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->table_cakes->setModel(modal1);
    ui->table_cakes->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);



    qDebug() << (modal1->rowCount());

    //Підключаємо базу даних для таблиці Сировина
    QSqlQueryModel * modal2=new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(conn.db);
    qry2->prepare("SELECT Код,Сировина FROM raw");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->table_raw->setModel(modal2);
    ui->table_raw->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    qDebug() << (modal2->rowCount());


    //Підключаємо базу даних для таблиці Магазини
    QSqlQueryModel * modal3=new QSqlQueryModel();
    QSqlQuery* qry3 = new QSqlQuery(conn.db);
    qry3->prepare("SELECT Код,Магазини FROM shops");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->table_shops->setModel(modal3);
    ui->table_shops->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    qDebug() << (modal3->rowCount());
    conn.closeDB();
}

EditData::~EditData()
{
    delete ui;
}

void EditData::on_BackToGeneralWindow_clicked()
{
    GeneralWindow gw;
    this->close();
    gw.setModal(true);
    gw.exec();
}


void EditData::on_del_cake_clicked()
{
    QString ncake,id;
    ncake = ui->lineEditCake->text();
    id = ui->lineEdit_IdCake->text();

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("Delete from cakes where Код='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Видалено"),tr("Успішно видалено з бази даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час видалення даних з бази даних виникла помилка"));
    }
}


void EditData::on_pushButton_AddCake_clicked()
{
    QString ncake,id;
    ncake = ui->lineEditCake->text();
    id = ui->lineEdit_IdCake->text();

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("insert into cakes (Код,Продукція) values ('"+id+"','"+ncake+"')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Добавлено"),tr("Успішно добавлено в базу даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час додавання даних в базу даних виникла помилка"));
    }
}


void EditData::on_update_data_cake_clicked()
{
    QString ncake,id;
    ncake = ui->lineEditCake->text();
    id = ui->lineEdit_IdCake->text();
    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("update cakes set Продукція='"+ncake+"' where Код='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Змінено"),tr("Успішно змінено дані"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час зміни даних в базі даних виникла помилка"));
    }
}


void EditData::on_del_raw_clicked()
{
    QString nraw,id;
    nraw = ui->lineEditRaw->text();
    id = ui->lineEdit_IdRaw->text();

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("Delete from raw where Код='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Видалено"),tr("Успішно видалено з бази даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час видалення даних з бази даних виникла помилка"));
    }
}


void EditData::on_del_shop_clicked()
{
    QString nshop,id;
    nshop = ui->lineEditShop->text();
    id = ui->lineEdit_IdShop->text();

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("Delete from shops where Код='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Видалено"),tr("Успішно видалено з бази даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час видалення даних з бази даних виникла помилка"));
    }
}


void EditData::on_update_data_raw_clicked()
{
    QString nraw,id;
    nraw = ui->lineEditRaw->text();
    id = ui->lineEdit_IdRaw->text();
    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("update raw set Сировина='"+nraw+"' where Код='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Змінено"),tr("Успішно змінено дані"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час зміни даних в базі даних виникла помилка"));
    }
}


void EditData::on_update_data_shop_clicked()
{
    QString nshop,id;
    nshop = ui->lineEditShop->text();
    id = ui->lineEdit_IdShop->text();
    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("update shops set Магазини='"+nshop+"' where Код='"+id+"'");

    if(qry.exec()){
        QMessageBox::information(this,tr("Змінено"),tr("Успішно змінено дані"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час зміни даних в базі даних виникла помилка"));
    }
}


void EditData::on_add_raw_clicked()
{
    QString nraw,id;
    nraw = ui->lineEditRaw->text();
    id = ui->lineEdit_IdRaw->text();

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("insert into raw (Код,Сировина) values ('"+id+"','"+nraw+"')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Добавлено"),tr("Успішно добавлено в базу даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час додавання даних в базу даних виникла помилка"));
    }
}


void EditData::on_add_shop_clicked()
{
    QString nshop,id;
    nshop = ui->lineEditShop->text();
    id = ui->lineEdit_IdShop->text();

    Login conn;
    conn.connectToDB();
    QSqlQuery qry;
    qry.prepare("insert into shops (Код,Магазини) values ('"+id+"','"+nshop+"')");

    if(qry.exec()){
        QMessageBox::information(this,tr("Добавлено"),tr("Успішно добавлено в базу даних"));
        conn.closeDB();
    }else{
        QMessageBox::critical(this,tr("Помилка"),tr("Під час додавання даних в базу даних виникла помилка"));
    }
}

