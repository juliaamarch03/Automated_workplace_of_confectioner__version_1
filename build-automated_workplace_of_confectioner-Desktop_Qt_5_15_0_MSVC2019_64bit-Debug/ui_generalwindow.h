/********************************************************************************
** Form generated from reading UI file 'generalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALWINDOW_H
#define UI_GENERALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralWindow
{
public:
    QFrame *frame2;
    QPushButton *AddReport;
    QPushButton *EditData;
    QPushButton *AddDailyWork;
    QFrame *frame1;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QFrame *frame3;

    void setupUi(QWidget *GeneralWindow)
    {
        if (GeneralWindow->objectName().isEmpty())
            GeneralWindow->setObjectName(QString::fromUtf8("GeneralWindow"));
        GeneralWindow->resize(1639, 1297);
        GeneralWindow->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(214, 182, 187);\n"
"	font-family: Roboto;\n"
"	font-size: 24px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QFrame{\n"
"	background-color: rgb(244, 231, 231);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	\n"
"	background-color: rgb(128, 66, 77);\n"
"	color: #FBFBFB;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QTabWidget{\n"
"	background-color: #FBFBFB;\n"
"}"));
        frame2 = new QFrame(GeneralWindow);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        frame2->setGeometry(QRect(1090, 130, 421, 421));
        frame2->setFrameShape(QFrame::StyledPanel);
        frame2->setFrameShadow(QFrame::Raised);
        AddReport = new QPushButton(frame2);
        AddReport->setObjectName(QString::fromUtf8("AddReport"));
        AddReport->setGeometry(QRect(40, 90, 331, 71));
        EditData = new QPushButton(frame2);
        EditData->setObjectName(QString::fromUtf8("EditData"));
        EditData->setGeometry(QRect(40, 250, 331, 71));
        AddDailyWork = new QPushButton(frame2);
        AddDailyWork->setObjectName(QString::fromUtf8("AddDailyWork"));
        AddDailyWork->setGeometry(QRect(40, 170, 331, 71));
        frame1 = new QFrame(GeneralWindow);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setGeometry(QRect(180, 620, 1331, 601));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame1);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(130, 90, 1101, 411));
        tabWidget->setStyleSheet(QString::fromUtf8("*{\n"
"background-color: rgb(251, 251, 251);\n"
"}\n"
"\n"
"QWidget::tab{\n"
"	height: 60px;\n"
"	width: 455px;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        frame3 = new QFrame(GeneralWindow);
        frame3->setObjectName(QString::fromUtf8("frame3"));
        frame3->setGeometry(QRect(179, 130, 881, 421));
        frame3->setFrameShape(QFrame::StyledPanel);
        frame3->setFrameShadow(QFrame::Raised);

        retranslateUi(GeneralWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GeneralWindow);
    } // setupUi

    void retranslateUi(QWidget *GeneralWindow)
    {
        GeneralWindow->setWindowTitle(QCoreApplication::translate("GeneralWindow", "Form", nullptr));
        AddReport->setText(QCoreApplication::translate("GeneralWindow", "\320\227\320\262\321\226\321\202", nullptr));
        EditData->setText(QCoreApplication::translate("GeneralWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \320\264\320\260\320\275\321\226", nullptr));
        AddDailyWork->setText(QCoreApplication::translate("GeneralWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\262\320\270\320\277\320\265\321\207\320\265\320\275\321\226 \321\202\320\276\321\200\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("GeneralWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("GeneralWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralWindow: public Ui_GeneralWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALWINDOW_H
