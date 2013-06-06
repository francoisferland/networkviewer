/********************************************************************************
** Form generated from reading UI file 'ModuleConfigurationView.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULECONFIGURATIONVIEW_H
#define UI_MODULECONFIGURATIONVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuleConfigurationView
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_Activate;
    QToolButton *toolButton_Deactivate;
    QToolButton *toolButton_NewVariable;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_LoadConf;
    QToolButton *toolButton_SaveConf;

    void setupUi(QWidget *ModuleConfigurationView)
    {
        if (ModuleConfigurationView->objectName().isEmpty())
            ModuleConfigurationView->setObjectName(QStringLiteral("ModuleConfigurationView"));
        ModuleConfigurationView->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModuleConfigurationView->sizePolicy().hasHeightForWidth());
        ModuleConfigurationView->setSizePolicy(sizePolicy);
        ModuleConfigurationView->setMinimumSize(QSize(320, 240));
        ModuleConfigurationView->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(ModuleConfigurationView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(ModuleConfigurationView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_Activate = new QToolButton(groupBox);
        toolButton_Activate->setObjectName(QStringLiteral("toolButton_Activate"));

        horizontalLayout->addWidget(toolButton_Activate);

        toolButton_Deactivate = new QToolButton(groupBox);
        toolButton_Deactivate->setObjectName(QStringLiteral("toolButton_Deactivate"));

        horizontalLayout->addWidget(toolButton_Deactivate);

        toolButton_NewVariable = new QToolButton(groupBox);
        toolButton_NewVariable->setObjectName(QStringLiteral("toolButton_NewVariable"));
        toolButton_NewVariable->setEnabled(true);

        horizontalLayout->addWidget(toolButton_NewVariable);

        horizontalSpacer = new QSpacerItem(731, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_LoadConf = new QToolButton(groupBox);
        toolButton_LoadConf->setObjectName(QStringLiteral("toolButton_LoadConf"));
        toolButton_LoadConf->setEnabled(true);

        horizontalLayout->addWidget(toolButton_LoadConf);

        toolButton_SaveConf = new QToolButton(groupBox);
        toolButton_SaveConf->setObjectName(QStringLiteral("toolButton_SaveConf"));
        toolButton_SaveConf->setEnabled(true);

        horizontalLayout->addWidget(toolButton_SaveConf);


        verticalLayout->addWidget(groupBox);


        retranslateUi(ModuleConfigurationView);

        QMetaObject::connectSlotsByName(ModuleConfigurationView);
    } // setupUi

    void retranslateUi(QWidget *ModuleConfigurationView)
    {
        ModuleConfigurationView->setWindowTitle(QApplication::translate("ModuleConfigurationView", "Form", 0));
        groupBox->setTitle(QApplication::translate("ModuleConfigurationView", "Tools", 0));
        toolButton_Activate->setText(QApplication::translate("ModuleConfigurationView", "Activate All", 0));
        toolButton_Deactivate->setText(QApplication::translate("ModuleConfigurationView", "Deactivate All", 0));
        toolButton_NewVariable->setText(QApplication::translate("ModuleConfigurationView", "New Variable", 0));
        toolButton_LoadConf->setText(QApplication::translate("ModuleConfigurationView", "Load Conf.", 0));
        toolButton_SaveConf->setText(QApplication::translate("ModuleConfigurationView", "Save Conf.", 0));
    } // retranslateUi

};

namespace Ui {
    class ModuleConfigurationView: public Ui_ModuleConfigurationView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULECONFIGURATIONVIEW_H
