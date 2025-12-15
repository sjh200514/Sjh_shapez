/********************************************************************************
** Form generated from reading UI file 'gamescene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENE_H
#define UI_GAMESCENE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameScene
{
public:
    QWidget *centralwidget;
    QPushButton *btn_shop;
    QPushButton *btn_miner;
    QPushButton *btn_trash;
    QPushButton *btn_belt;
    QPushButton *btn_cutter;
    QPushButton *btn_save;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_money;
    QLabel *label_yuan;
    QLabel *label_fang;
    QLabel *label_rect;
    QLabel *label;
    QPushButton *btn_gold;

    void setupUi(QMainWindow *GameScene)
    {
        if (GameScene->objectName().isEmpty())
            GameScene->setObjectName("GameScene");
        GameScene->resize(1000, 803);
        centralwidget = new QWidget(GameScene);
        centralwidget->setObjectName("centralwidget");
        btn_shop = new QPushButton(centralwidget);
        btn_shop->setObjectName("btn_shop");
        btn_shop->setGeometry(QRect(20, 720, 90, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/shop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_shop->setIcon(icon);
        btn_shop->setIconSize(QSize(50, 50));
        btn_miner = new QPushButton(centralwidget);
        btn_miner->setObjectName("btn_miner");
        btn_miner->setGeometry(QRect(200, 720, 90, 70));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/miner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_miner->setIcon(icon1);
        btn_miner->setIconSize(QSize(50, 50));
        btn_trash = new QPushButton(centralwidget);
        btn_trash->setObjectName("btn_trash");
        btn_trash->setGeometry(QRect(380, 720, 90, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_trash->setIcon(icon2);
        btn_trash->setIconSize(QSize(50, 50));
        btn_belt = new QPushButton(centralwidget);
        btn_belt->setObjectName("btn_belt");
        btn_belt->setGeometry(QRect(550, 720, 90, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/belt.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_belt->setIcon(icon3);
        btn_belt->setIconSize(QSize(50, 50));
        btn_cutter = new QPushButton(centralwidget);
        btn_cutter->setObjectName("btn_cutter");
        btn_cutter->setGeometry(QRect(720, 720, 90, 70));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/cutter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_cutter->setIcon(icon4);
        btn_cutter->setIconSize(QSize(50, 50));
        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(890, 30, 91, 71));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_save->setIcon(icon5);
        btn_save->setIconSize(QSize(50, 50));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(11, -2, 851, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_money = new QLabel(layoutWidget);
        label_money->setObjectName("label_money");
        QFont font;
        font.setPointSize(20);
        label_money->setFont(font);

        verticalLayout->addWidget(label_money);

        label_yuan = new QLabel(layoutWidget);
        label_yuan->setObjectName("label_yuan");
        label_yuan->setFont(font);

        verticalLayout->addWidget(label_yuan);

        label_fang = new QLabel(layoutWidget);
        label_fang->setObjectName("label_fang");
        label_fang->setFont(font);

        verticalLayout->addWidget(label_fang);

        label_rect = new QLabel(layoutWidget);
        label_rect->setObjectName("label_rect");
        label_rect->setFont(font);

        verticalLayout->addWidget(label_rect);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        verticalLayout->addWidget(label);

        btn_gold = new QPushButton(centralwidget);
        btn_gold->setObjectName("btn_gold");
        btn_gold->setGeometry(QRect(890, 720, 90, 70));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/gold.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_gold->setIcon(icon6);
        btn_gold->setIconSize(QSize(60, 60));
        GameScene->setCentralWidget(centralwidget);

        retranslateUi(GameScene);

        QMetaObject::connectSlotsByName(GameScene);
    } // setupUi

    void retranslateUi(QMainWindow *GameScene)
    {
        GameScene->setWindowTitle(QCoreApplication::translate("GameScene", "MainWindow", nullptr));
        btn_shop->setText(QString());
        btn_miner->setText(QString());
        btn_trash->setText(QString());
        btn_belt->setText(QString());
        btn_cutter->setText(QString());
        btn_save->setText(QString());
        label_money->setText(QCoreApplication::translate("GameScene", "TextLabel", nullptr));
        label_yuan->setText(QCoreApplication::translate("GameScene", "TextLabel", nullptr));
        label_fang->setText(QCoreApplication::translate("GameScene", "TextLabel", nullptr));
        label_rect->setText(QCoreApplication::translate("GameScene", "TextLabel", nullptr));
        label->setText(QString());
        btn_gold->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameScene: public Ui_GameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENE_H
