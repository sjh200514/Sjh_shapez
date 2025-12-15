/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QWidget *centralwidget;
    QPushButton *btn_start;
    QPushButton *btn_continue;
    QLabel *label;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName("MainScene");
        MainScene->resize(1440, 800);
        centralwidget = new QWidget(MainScene);
        centralwidget->setObjectName("centralwidget");
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName("btn_start");
        btn_start->setGeometry(QRect(360, 430, 281, 101));
        QFont font;
        font.setPointSize(20);
        btn_start->setFont(font);
        btn_start->setIconSize(QSize(24, 24));
        btn_continue = new QPushButton(centralwidget);
        btn_continue->setObjectName("btn_continue");
        btn_continue->setGeometry(QRect(360, 590, 281, 101));
        btn_continue->setFont(font);
        btn_continue->setIconSize(QSize(24, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 190, 811, 171));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/logo.png")));
        MainScene->setCentralWidget(centralwidget);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QCoreApplication::translate("MainScene", "MainScene", nullptr));
        btn_start->setText(QCoreApplication::translate("MainScene", "\346\226\260\346\270\270\346\210\217", nullptr));
        btn_continue->setText(QCoreApplication::translate("MainScene", "\350\257\273\345\217\226\345\255\230\346\241\243", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
