/********************************************************************************
** Form generated from reading UI file 'end.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_END_H
#define UI_END_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_End
{
public:
    QWidget *centralwidget;
    QLabel *label;

    void setupUi(QMainWindow *End)
    {
        if (End->objectName().isEmpty())
            End->setObjectName("End");
        End->resize(800, 600);
        centralwidget = new QWidget(End);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1000, 800));
        End->setCentralWidget(centralwidget);

        retranslateUi(End);

        QMetaObject::connectSlotsByName(End);
    } // setupUi

    void retranslateUi(QMainWindow *End)
    {
        End->setWindowTitle(QCoreApplication::translate("End", "MainWindow", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class End: public Ui_End {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_END_H
