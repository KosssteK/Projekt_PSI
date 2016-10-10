/********************************************************************************
** Form generated from reading UI file 'qt.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_H
#define UI_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QTClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;

    void setupUi(QDialog *QTClass)
    {
        if (QTClass->objectName().isEmpty())
            QTClass->setObjectName(QStringLiteral("QTClass"));
        QTClass->resize(438, 308);
        pushButton = new QPushButton(QTClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 71, 71));
        pushButton_2 = new QPushButton(QTClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 30, 71, 71));
        pushButton_3 = new QPushButton(QTClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 30, 71, 71));
        pushButton_4 = new QPushButton(QTClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 120, 71, 71));
        pushButton_5 = new QPushButton(QTClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 120, 71, 71));
        pushButton_6 = new QPushButton(QTClass);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(200, 120, 71, 71));
        pushButton_7 = new QPushButton(QTClass);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 210, 71, 71));
        pushButton_8 = new QPushButton(QTClass);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(110, 210, 71, 71));
        pushButton_9 = new QPushButton(QTClass);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(200, 210, 71, 71));
        graphicsView = new QGraphicsView(QTClass);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(340, 40, 51, 51));
        pushButton_10 = new QPushButton(QTClass);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(330, 100, 75, 23));
        pushButton_11 = new QPushButton(QTClass);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(330, 140, 75, 23));
        pushButton_12 = new QPushButton(QTClass);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(330, 180, 75, 23));
        pushButton_13 = new QPushButton(QTClass);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(330, 240, 75, 23));
        pushButton_13->setMouseTracking(false);

        retranslateUi(QTClass);

        QMetaObject::connectSlotsByName(QTClass);
    } // setupUi

    void retranslateUi(QDialog *QTClass)
    {
        QTClass->setWindowTitle(QApplication::translate("QTClass", "QT", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("QTClass", "-", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("QTClass", "Test", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("QTClass", "Wyslij", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("QTClass", "Wyczysc", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("QTClass", "Wyjdz", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QTClass: public Ui_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_H
