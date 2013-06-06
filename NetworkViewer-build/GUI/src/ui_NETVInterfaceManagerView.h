/********************************************************************************
** Form generated from reading UI file 'NETVInterfaceManagerView.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETVINTERFACEMANAGERVIEW_H
#define UI_NETVINTERFACEMANAGERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NETVInterfaceManagerView
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *m_listWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_addButton;
    QPushButton *m_removeButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NETVInterfaceManagerView)
    {
        if (NETVInterfaceManagerView->objectName().isEmpty())
            NETVInterfaceManagerView->setObjectName(QStringLiteral("NETVInterfaceManagerView"));
        NETVInterfaceManagerView->resize(640, 480);
        verticalLayout_2 = new QVBoxLayout(NETVInterfaceManagerView);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(NETVInterfaceManagerView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_listWidget = new QListWidget(groupBox);
        m_listWidget->setObjectName(QStringLiteral("m_listWidget"));

        verticalLayout->addWidget(m_listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_addButton = new QPushButton(groupBox);
        m_addButton->setObjectName(QStringLiteral("m_addButton"));

        horizontalLayout->addWidget(m_addButton);

        m_removeButton = new QPushButton(groupBox);
        m_removeButton->setObjectName(QStringLiteral("m_removeButton"));

        horizontalLayout->addWidget(m_removeButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(NETVInterfaceManagerView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(NETVInterfaceManagerView);
        QObject::connect(buttonBox, SIGNAL(accepted()), NETVInterfaceManagerView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NETVInterfaceManagerView, SLOT(reject()));

        QMetaObject::connectSlotsByName(NETVInterfaceManagerView);
    } // setupUi

    void retranslateUi(QDialog *NETVInterfaceManagerView)
    {
        NETVInterfaceManagerView->setWindowTitle(QApplication::translate("NETVInterfaceManagerView", "NetworkViewer - Interface Manager", 0));
        groupBox->setTitle(QApplication::translate("NETVInterfaceManagerView", "Interfaces", 0));
        m_addButton->setText(QApplication::translate("NETVInterfaceManagerView", "Add", 0));
        m_removeButton->setText(QApplication::translate("NETVInterfaceManagerView", "Remove", 0));
    } // retranslateUi

};

namespace Ui {
    class NETVInterfaceManagerView: public Ui_NETVInterfaceManagerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETVINTERFACEMANAGERVIEW_H
