/********************************************************************************
** Form generated from reading UI file 'editdata.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDATA_H
#define UI_EDITDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditData
{
public:
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *table_cakes;
    QWidget *tab_2;
    QTableView *table_raw;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *tab_3;
    QTableView *table_shops;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *EditData)
    {
        if (EditData->objectName().isEmpty())
            EditData->setObjectName(QString::fromUtf8("EditData"));
        EditData->resize(1985, 1044);
        EditData->setStyleSheet(QString::fromUtf8("*{\n"
"	\n"
"	background-color: rgb(214, 182, 187);\n"
"	font-family: Roboto;\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QFrame{\n"
"	background-color: #FCFCFC;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
""));
        frame = new QFrame(EditData);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(60, 50, 1601, 761));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 1381, 741));
        tabWidget->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(244, 231, 231);\n"
"}\n"
"\n"
"QWidget::tab{\n"
"	height: 60px;\n"
"	width: 455px;\n"
"	color: #575757;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::South);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(920, 60, 251, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(920, 170, 251, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        table_cakes = new QTableView(tab);
        table_cakes->setObjectName(QString::fromUtf8("table_cakes"));
        table_cakes->setGeometry(QRect(130, 130, 541, 361));
        table_cakes->setStyleSheet(QString::fromUtf8("background-color: #FCFCFC;"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        table_raw = new QTableView(tab_2);
        table_raw->setObjectName(QString::fromUtf8("table_raw"));
        table_raw->setGeometry(QRect(110, 70, 591, 501));
        table_raw->setStyleSheet(QString::fromUtf8("background-color: #FCFCFC;"));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(830, 70, 251, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(830, 180, 281, 71));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        table_shops = new QTableView(tab_3);
        table_shops->setObjectName(QString::fromUtf8("table_shops"));
        table_shops->setGeometry(QRect(230, 110, 391, 321));
        table_shops->setStyleSheet(QString::fromUtf8("background-color: #FCFCFC;"));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(920, 120, 251, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(920, 250, 261, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}"));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(EditData);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditData);
    } // setupUi

    void retranslateUi(QWidget *EditData)
    {
        EditData->setWindowTitle(QCoreApplication::translate("EditData", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("EditData", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EditData", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("EditData", "\320\222\320\270\320\277\321\226\321\207\320\272\320\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EditData", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("EditData", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("EditData", "\320\241\320\270\321\200\320\276\320\262\320\270\320\275\320\260", nullptr));
        pushButton_5->setText(QCoreApplication::translate("EditData", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("EditData", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\267\320\260\320\277\320\270\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("EditData", "\320\234\320\260\320\263\320\260\320\267\320\270\320\275\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditData: public Ui_EditData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDATA_H
