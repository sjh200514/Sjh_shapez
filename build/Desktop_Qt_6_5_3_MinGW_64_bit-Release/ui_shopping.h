/********************************************************************************
** Form generated from reading UI file 'shopping.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPING_H
#define UI_SHOPPING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shopping
{
public:
    QWidget *centralwidget;
    QLabel *label_shoptitle;
    QLabel *label_money;
    QPushButton *btn_back;
    QPushButton *btn_select1;
    QPushButton *btn_select2;
    QPushButton *btn_select3;
    QLabel *label_message;

    void setupUi(QMainWindow *Shopping)
    {
        if (Shopping->objectName().isEmpty())
            Shopping->setObjectName("Shopping");
        Shopping->resize(1000, 800);
        centralwidget = new QWidget(Shopping);
        centralwidget->setObjectName("centralwidget");
        label_shoptitle = new QLabel(centralwidget);
        label_shoptitle->setObjectName("label_shoptitle");
        label_shoptitle->setGeometry(QRect(440, 70, 211, 81));
        QFont font;
        font.setPointSize(50);
        label_shoptitle->setFont(font);
        label_money = new QLabel(centralwidget);
        label_money->setObjectName("label_money");
        label_money->setGeometry(QRect(20, 200, 311, 61));
        QFont font1;
        font1.setPointSize(40);
        label_money->setFont(font1);
        btn_back = new QPushButton(centralwidget);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(10, 670, 120, 120));
        btn_back->setIconSize(QSize(100, 100));
        btn_select1 = new QPushButton(centralwidget);
        btn_select1->setObjectName("btn_select1");
        btn_select1->setGeometry(QRect(90, 370, 200, 200));
        btn_select2 = new QPushButton(centralwidget);
        btn_select2->setObjectName("btn_select2");
        btn_select2->setGeometry(QRect(420, 370, 200, 200));
        btn_select3 = new QPushButton(centralwidget);
        btn_select3->setObjectName("btn_select3");
        btn_select3->setGeometry(QRect(730, 370, 200, 200));
        label_message = new QLabel(centralwidget);
        label_message->setObjectName("label_message");
        label_message->setGeometry(QRect(280, 680, 631, 101));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setUnderline(false);
        label_message->setFont(font2);
        Shopping->setCentralWidget(centralwidget);

        retranslateUi(Shopping);

        QMetaObject::connectSlotsByName(Shopping);
    } // setupUi

    void retranslateUi(QMainWindow *Shopping)
    {
        Shopping->setWindowTitle(QCoreApplication::translate("Shopping", "MainWindow", nullptr));
        label_shoptitle->setText(QCoreApplication::translate("Shopping", "\345\225\206\345\272\227", nullptr));
        label_money->setText(QCoreApplication::translate("Shopping", "TextLabel", nullptr));
        btn_back->setText(QString());
        btn_select1->setText(QString());
        btn_select2->setText(QString());
        btn_select3->setText(QString());
        label_message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Shopping: public Ui_Shopping {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPING_H
