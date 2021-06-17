#include "login.h"
#include "ui_login.h"
#define Path_to_DB "C:/Users/Admin/Documents/TermPaperTEST/build-automated_workplace_of_confectioner-Desktop_Qt_5_15_0_MSVC2019_64bit-Debug/awoc.db"

Login::Login(QDialog *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    //Підключаємо базу даних
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile()){
        if(connectToDB()){
            qDebug("Connected to Database File :)");
        }else{
            qDebug("Failed to open the database");
        }
    }

    //Тінь фрейму
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    shadow_effect->setBlurRadius(22);
    ui->frame->setGraphicsEffect(shadow_effect);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_SignIn_clicked()
{
    connectToDB();
    QString Username, Password;
    Username=ui->lineEdit_Username->text();
    Password=ui->lineEdit_Password->text();
    if(!db.isOpen()){
        qDebug("No connection to db :(");
        return;
    }
    QSqlQuery qry;

    if(qry.exec("SELECT Username, Password FROM employees_info WHERE Username=\'"+Username+"\' AND Password=\'"+Password+"\'")){
        if(qry.next()){
            closeDB();
            GeneralWindow gw;
            this->close();
            gw.setModal(true);
            gw.exec();

        }else{
            QMessageBox::warning(this, "Login", "Ім'я користувача або пароль неправильний");
        }
    }
}

bool Login::connectToDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path_to_DB);
    return db.open();
}

void Login::closeDB(){
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
}
