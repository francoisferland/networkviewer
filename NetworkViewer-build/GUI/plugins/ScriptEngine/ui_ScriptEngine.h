/********************************************************************************
** Form generated from reading UI file 'ScriptEngine.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTENGINE_H
#define UI_SCRIPTENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptEngine
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *helpButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_loadButton;
    QPushButton *m_saveButton;
    QPushButton *m_runButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTextEdit *m_textEditScript;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *m_textEditMessages;

    void setupUi(QWidget *ScriptEngine)
    {
        if (ScriptEngine->objectName().isEmpty())
            ScriptEngine->setObjectName(QStringLiteral("ScriptEngine"));
        ScriptEngine->resize(985, 585);
        ScriptEngine->setMinimumSize(QSize(640, 480));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        ScriptEngine->setFont(font);
        ScriptEngine->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(ScriptEngine);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(ScriptEngine);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        helpButton = new QPushButton(layoutWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        QFont font1;
        font1.setPointSize(14);
        helpButton->setFont(font1);

        horizontalLayout_2->addWidget(helpButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        spinBox->setFont(font3);
        spinBox->setMinimum(0);
        spinBox->setMaximum(1000);
        spinBox->setValue(0);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        m_loadButton = new QPushButton(layoutWidget);
        m_loadButton->setObjectName(QStringLiteral("m_loadButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_loadButton->sizePolicy().hasHeightForWidth());
        m_loadButton->setSizePolicy(sizePolicy);
        m_loadButton->setFont(font1);

        horizontalLayout_2->addWidget(m_loadButton);

        m_saveButton = new QPushButton(layoutWidget);
        m_saveButton->setObjectName(QStringLiteral("m_saveButton"));
        m_saveButton->setFont(font1);

        horizontalLayout_2->addWidget(m_saveButton);

        m_runButton = new QPushButton(layoutWidget);
        m_runButton->setObjectName(QStringLiteral("m_runButton"));
        sizePolicy.setHeightForWidth(m_runButton->sizePolicy().hasHeightForWidth());
        m_runButton->setSizePolicy(sizePolicy);
        m_runButton->setFont(font1);

        horizontalLayout_2->addWidget(m_runButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_textEditScript = new QTextEdit(tab);
        m_textEditScript->setObjectName(QStringLiteral("m_textEditScript"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        m_textEditScript->setFont(font4);

        verticalLayout->addWidget(m_textEditScript);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        m_textEditMessages = new QTextEdit(tab_2);
        m_textEditMessages->setObjectName(QStringLiteral("m_textEditMessages"));
        m_textEditMessages->setFont(font4);

        verticalLayout_4->addWidget(m_textEditMessages);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        splitter->addWidget(layoutWidget);

        verticalLayout_3->addWidget(splitter);


        retranslateUi(ScriptEngine);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ScriptEngine);
    } // setupUi

    void retranslateUi(QWidget *ScriptEngine)
    {
        ScriptEngine->setWindowTitle(QApplication::translate("ScriptEngine", "SamplePlugin", 0));
        helpButton->setText(QApplication::translate("ScriptEngine", "Help", 0));
        label_3->setText(QApplication::translate("ScriptEngine", "Period(ms)", 0));
        m_loadButton->setText(QApplication::translate("ScriptEngine", "Load", 0));
        m_saveButton->setText(QApplication::translate("ScriptEngine", "Save", 0));
        m_runButton->setText(QApplication::translate("ScriptEngine", "RUN", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ScriptEngine", "Script", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ScriptEngine", "Output", 0));
    } // retranslateUi

};

namespace Ui {
    class ScriptEngine: public Ui_ScriptEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTENGINE_H
