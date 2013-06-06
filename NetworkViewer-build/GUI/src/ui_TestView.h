/********************************************************************************
** Form generated from reading UI file 'TestView.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTVIEW_H
#define UI_TESTVIEW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestView
{
public:
    QDialogButtonBox *buttonBox;
    QGraphicsView *armImage;
    QLabel *label;

    void setupUi(QWidget *TestView)
    {
        if (TestView->objectName().isEmpty())
            TestView->setObjectName(QStringLiteral("TestView"));
        TestView->resize(670, 502);
        TestView->setMinimumSize(QSize(200, 200));
        TestView->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox = new QDialogButtonBox(TestView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(350, 430, 156, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        armImage = new QGraphicsView(TestView);
        armImage->setObjectName(QStringLiteral("armImage"));
        armImage->setGeometry(QRect(10, 20, 256, 192));
        label = new QLabel(TestView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 240, 46, 14));

        retranslateUi(TestView);

        QMetaObject::connectSlotsByName(TestView);
    } // setupUi

    void retranslateUi(QWidget *TestView)
    {
        TestView->setWindowTitle(QApplication::translate("TestView", "TestView", 0));
        label->setText(QApplication::translate("TestView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TestView: public Ui_TestView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTVIEW_H
