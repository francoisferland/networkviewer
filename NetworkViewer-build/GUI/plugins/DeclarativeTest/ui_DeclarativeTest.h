/********************************************************************************
** Form generated from reading UI file 'DeclarativeTest.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECLARATIVETEST_H
#define UI_DECLARATIVETEST_H

#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeclarativeTest
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_loadButton;
    QDeclarativeView *m_declarativeView;

    void setupUi(QWidget *DeclarativeTest)
    {
        if (DeclarativeTest->objectName().isEmpty())
            DeclarativeTest->setObjectName(QStringLiteral("DeclarativeTest"));
        DeclarativeTest->resize(985, 585);
        DeclarativeTest->setMinimumSize(QSize(640, 480));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        DeclarativeTest->setFont(font);
        DeclarativeTest->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(DeclarativeTest);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_loadButton = new QPushButton(DeclarativeTest);
        m_loadButton->setObjectName(QStringLiteral("m_loadButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_loadButton->sizePolicy().hasHeightForWidth());
        m_loadButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(m_loadButton);


        verticalLayout->addLayout(horizontalLayout);

        m_declarativeView = new QDeclarativeView(DeclarativeTest);
        m_declarativeView->setObjectName(QStringLiteral("m_declarativeView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_declarativeView->sizePolicy().hasHeightForWidth());
        m_declarativeView->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(m_declarativeView);


        retranslateUi(DeclarativeTest);

        QMetaObject::connectSlotsByName(DeclarativeTest);
    } // setupUi

    void retranslateUi(QWidget *DeclarativeTest)
    {
        DeclarativeTest->setWindowTitle(QApplication::translate("DeclarativeTest", "SamplePlugin", 0));
        m_loadButton->setText(QApplication::translate("DeclarativeTest", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class DeclarativeTest: public Ui_DeclarativeTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECLARATIVETEST_H
