/********************************************************************************
** Form generated from reading UI file 'ScopeVariableConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOPEVARIABLECONFIG_H
#define UI_SCOPEVARIABLECONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScopeVariableConfig
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_colorButton;
    QSpacerItem *horizontalSpacer;
    QLabel *m_label;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_removeButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScopeVariableConfig)
    {
        if (ScopeVariableConfig->objectName().isEmpty())
            ScopeVariableConfig->setObjectName(QStringLiteral("ScopeVariableConfig"));
        ScopeVariableConfig->resize(602, 294);
        verticalLayout = new QVBoxLayout(ScopeVariableConfig);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(ScopeVariableConfig);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_colorButton = new QPushButton(groupBox);
        m_colorButton->setObjectName(QStringLiteral("m_colorButton"));

        horizontalLayout_2->addWidget(m_colorButton);

        horizontalSpacer = new QSpacerItem(373, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_label = new QLabel(groupBox);
        m_label->setObjectName(QStringLiteral("m_label"));
        m_label->setMinimumSize(QSize(60, 0));
        m_label->setMaximumSize(QSize(60, 60));
        m_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(m_label);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ScopeVariableConfig);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_removeButton = new QPushButton(groupBox_2);
        m_removeButton->setObjectName(QStringLiteral("m_removeButton"));

        horizontalLayout->addWidget(m_removeButton);

        horizontalSpacer_2 = new QSpacerItem(451, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(ScopeVariableConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ScopeVariableConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), ScopeVariableConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ScopeVariableConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(ScopeVariableConfig);
    } // setupUi

    void retranslateUi(QDialog *ScopeVariableConfig)
    {
        ScopeVariableConfig->setWindowTitle(QApplication::translate("ScopeVariableConfig", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("ScopeVariableConfig", "Color", 0));
        m_colorButton->setText(QApplication::translate("ScopeVariableConfig", "Set Color", 0));
        m_label->setText(QApplication::translate("ScopeVariableConfig", "*", 0));
        groupBox_2->setTitle(QApplication::translate("ScopeVariableConfig", "Variable", 0));
        m_removeButton->setText(QApplication::translate("ScopeVariableConfig", "Remove", 0));
    } // retranslateUi

};

namespace Ui {
    class ScopeVariableConfig: public Ui_ScopeVariableConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPEVARIABLECONFIG_H
