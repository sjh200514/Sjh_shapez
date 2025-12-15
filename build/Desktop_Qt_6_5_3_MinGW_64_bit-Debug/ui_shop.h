/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shop
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *Shop)
    {
        if (Shop->objectName().isEmpty())
            Shop->setObjectName("Shop");
        Shop->resize(800, 600);
        centralwidget = new QWidget(Shop);
        centralwidget->setObjectName("centralwidget");
        Shop->setCentralWidget(centralwidget);

        retranslateUi(Shop);

        QMetaObject::connectSlotsByName(Shop);
    } // setupUi

    void retranslateUi(QMainWindow *Shop)
    {
        Shop->setWindowTitle(QCoreApplication::translate("Shop", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shop: public Ui_Shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
