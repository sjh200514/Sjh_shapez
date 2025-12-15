/********************************************************************************
** Form generated from reading UI file 'shengji.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHENGJI_H
#define UI_SHENGJI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shengji
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *Shengji)
    {
        if (Shengji->objectName().isEmpty())
            Shengji->setObjectName("Shengji");
        Shengji->resize(800, 600);
        centralwidget = new QWidget(Shengji);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 40, 581, 91));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 250, 150, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/miner.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(120, 120));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(320, 250, 150, 150));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/cutter.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(120, 120));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(590, 250, 150, 150));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/belt.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(120, 120));
        Shengji->setCentralWidget(centralwidget);

        retranslateUi(Shengji);

        QMetaObject::connectSlotsByName(Shengji);
    } // setupUi

    void retranslateUi(QMainWindow *Shengji)
    {
        Shengji->setWindowTitle(QCoreApplication::translate("Shengji", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Shengji", "\350\257\267\351\200\211\346\213\251\344\270\200\344\270\252\350\256\276\345\244\207\350\277\233\350\241\214\345\215\207\347\272\247", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Shengji: public Ui_Shengji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHENGJI_H
