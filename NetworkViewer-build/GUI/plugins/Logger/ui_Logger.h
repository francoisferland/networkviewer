/********************************************************************************
** Form generated from reading UI file 'Logger.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGER_H
#define UI_LOGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logger
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    QLabel *label;

    void setupUi(QWidget *Logger)
    {
        if (Logger->objectName().isEmpty())
            Logger->setObjectName(QStringLiteral("Logger"));
        Logger->resize(1031, 578);
        Logger->setMinimumSize(QSize(640, 480));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        Logger->setFont(font);
        Logger->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(Logger);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Save = new QPushButton(Logger);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_Save->setFont(font1);

        horizontalLayout->addWidget(pushButton_Save);

        pushButton_Clear = new QPushButton(Logger);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setFont(font1);

        horizontalLayout->addWidget(pushButton_Clear);

        pushButton_Start = new QPushButton(Logger);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setFont(font1);

        horizontalLayout->addWidget(pushButton_Start);

        pushButton_Stop = new QPushButton(Logger);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setFont(font1);

        horizontalLayout->addWidget(pushButton_Stop);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(Logger);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        verticalLayout->addWidget(label);


        retranslateUi(Logger);

        QMetaObject::connectSlotsByName(Logger);
    } // setupUi

    void retranslateUi(QWidget *Logger)
    {
        Logger->setWindowTitle(QApplication::translate("Logger", "SamplePlugin", 0));
        pushButton_Save->setText(QApplication::translate("Logger", "Save CSV", 0));
        pushButton_Clear->setText(QApplication::translate("Logger", "Clear", 0));
        pushButton_Start->setText(QApplication::translate("Logger", "Start", 0));
        pushButton_Stop->setText(QApplication::translate("Logger", "Stop", 0));
        label->setText(QApplication::translate("Logger", "Status here...", 0));
    } // retranslateUi

};

namespace Ui {
    class Logger: public Ui_Logger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGER_H
