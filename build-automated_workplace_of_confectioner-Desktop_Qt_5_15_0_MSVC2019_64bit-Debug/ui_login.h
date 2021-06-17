/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_SignIn;
    QLineEdit *lineEdit_Username;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_SignIn;
    QLabel *label_Username;
    QLabel *label_Password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(1918, 1007);
        Login->setMinimumSize(QSize(1918, 1007));
        Login->setMaximumSize(QSize(1918, 1007));
        Login->setStyleSheet(QString::fromUtf8("*{\n"
"	\n"
"	background-color: rgb(214, 182, 187);\n"
"	font-family: Roboto;\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QFrame{\n"
"	background-color: #FCFCFC;;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QLineEdit{\n"
"	background: #E7E7E7;\n"
"	border-radius: 15px;\n"
"	color: #575757;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(560, 110, 771, 651));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_SignIn = new QLabel(frame);
        label_SignIn->setObjectName(QString::fromUtf8("label_SignIn"));
        label_SignIn->setGeometry(QRect(330, 50, 161, 61));
        label_SignIn->setStyleSheet(QString::fromUtf8("color: #575757;"));
        lineEdit_Username = new QLineEdit(frame);
        lineEdit_Username->setObjectName(QString::fromUtf8("lineEdit_Username"));
        lineEdit_Username->setGeometry(QRect(200, 200, 371, 61));
        lineEdit_Password = new QLineEdit(frame);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(200, 360, 371, 61));
        lineEdit_Password->setEchoMode(QLineEdit::Password);
        pushButton_SignIn = new QPushButton(frame);
        pushButton_SignIn->setObjectName(QString::fromUtf8("pushButton_SignIn"));
        pushButton_SignIn->setGeometry(QRect(240, 520, 271, 61));
        label_Username = new QLabel(frame);
        label_Username->setObjectName(QString::fromUtf8("label_Username"));
        label_Username->setGeometry(QRect(200, 150, 341, 41));
        label_Username->setStyleSheet(QString::fromUtf8("color: #575757;"));
        label_Password = new QLabel(frame);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(210, 310, 141, 41));
        label_Password->setStyleSheet(QString::fromUtf8("color: #575757;"));
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1918, 34));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        label_SignIn->setText(QCoreApplication::translate("Login", "\320\243\320\262\321\226\320\271\321\202\320\270", nullptr));
        lineEdit_Username->setInputMask(QString());
        lineEdit_Username->setText(QString());
        lineEdit_Password->setText(QString());
        pushButton_SignIn->setText(QCoreApplication::translate("Login", "\320\243\320\262\321\226\320\271\321\202\320\270", nullptr));
        label_Username->setText(QCoreApplication::translate("Login", "\320\206\320\274'\321\217 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207\320\260", nullptr));
        label_Password->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
