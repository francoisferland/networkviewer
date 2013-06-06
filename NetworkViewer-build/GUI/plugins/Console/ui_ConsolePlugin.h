/********************************************************************************
** Form generated from reading UI file 'ConsolePlugin.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEPLUGIN_H
#define UI_CONSOLEPLUGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsolePlugin
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_clearButton;
    QPushButton *m_saveButton;
    QTabWidget *m_tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *m_globalTextEdit;

    void setupUi(QWidget *ConsolePlugin)
    {
        if (ConsolePlugin->objectName().isEmpty())
            ConsolePlugin->setObjectName(QStringLiteral("ConsolePlugin"));
        ConsolePlugin->resize(640, 480);
        ConsolePlugin->setMinimumSize(QSize(320, 240));
        verticalLayout = new QVBoxLayout(ConsolePlugin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_clearButton = new QPushButton(ConsolePlugin);
        m_clearButton->setObjectName(QStringLiteral("m_clearButton"));

        horizontalLayout->addWidget(m_clearButton);

        m_saveButton = new QPushButton(ConsolePlugin);
        m_saveButton->setObjectName(QStringLiteral("m_saveButton"));

        horizontalLayout->addWidget(m_saveButton);


        verticalLayout->addLayout(horizontalLayout);

        m_tabWidget = new QTabWidget(ConsolePlugin);
        m_tabWidget->setObjectName(QStringLiteral("m_tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_globalTextEdit = new QTextEdit(tab);
        m_globalTextEdit->setObjectName(QStringLiteral("m_globalTextEdit"));

        verticalLayout_2->addWidget(m_globalTextEdit);

        m_tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(m_tabWidget);


        retranslateUi(ConsolePlugin);

        m_tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConsolePlugin);
    } // setupUi

    void retranslateUi(QWidget *ConsolePlugin)
    {
        ConsolePlugin->setWindowTitle(QApplication::translate("ConsolePlugin", "Form", 0));
        m_clearButton->setText(QApplication::translate("ConsolePlugin", "Clear", 0));
        m_saveButton->setText(QApplication::translate("ConsolePlugin", "Save", 0));
        m_globalTextEdit->setHtml(QApplication::translate("ConsolePlugin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Main Console!</span></p></body></html>", 0));
        m_tabWidget->setTabText(m_tabWidget->indexOf(tab), QApplication::translate("ConsolePlugin", "Global", 0));
    } // retranslateUi

};

namespace Ui {
    class ConsolePlugin: public Ui_ConsolePlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEPLUGIN_H
