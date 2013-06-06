/********************************************************************************
** Form generated from reading UI file 'DeviceSelectorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESELECTORDIALOG_H
#define UI_DEVICESELECTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceSelectorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_Ethernet;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEditArgs;
    QPushButton *m_configureButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *m_updatePeriodSpinbox;
    QGroupBox *groupBox_Serial;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEditDoc;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DeviceSelectorDialog)
    {
        if (DeviceSelectorDialog->objectName().isEmpty())
            DeviceSelectorDialog->setObjectName(QStringLiteral("DeviceSelectorDialog"));
        DeviceSelectorDialog->resize(879, 576);
        verticalLayout = new QVBoxLayout(DeviceSelectorDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_Ethernet = new QGroupBox(DeviceSelectorDialog);
        groupBox_Ethernet->setObjectName(QStringLiteral("groupBox_Ethernet"));
        groupBox_Ethernet->setEnabled(true);
        horizontalLayout = new QHBoxLayout(groupBox_Ethernet);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(groupBox_Ethernet);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        lineEditArgs = new QLineEdit(groupBox_Ethernet);
        lineEditArgs->setObjectName(QStringLiteral("lineEditArgs"));

        horizontalLayout->addWidget(lineEditArgs);

        m_configureButton = new QPushButton(groupBox_Ethernet);
        m_configureButton->setObjectName(QStringLiteral("m_configureButton"));

        horizontalLayout->addWidget(m_configureButton);


        verticalLayout->addWidget(groupBox_Ethernet);

        groupBox = new QGroupBox(DeviceSelectorDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        m_updatePeriodSpinbox = new QSpinBox(groupBox);
        m_updatePeriodSpinbox->setObjectName(QStringLiteral("m_updatePeriodSpinbox"));
        m_updatePeriodSpinbox->setMinimum(1);
        m_updatePeriodSpinbox->setMaximum(1000);
        m_updatePeriodSpinbox->setValue(10);

        horizontalLayout_3->addWidget(m_updatePeriodSpinbox);


        verticalLayout->addWidget(groupBox);

        groupBox_Serial = new QGroupBox(DeviceSelectorDialog);
        groupBox_Serial->setObjectName(QStringLiteral("groupBox_Serial"));
        groupBox_Serial->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_Serial);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEditDoc = new QTextEdit(groupBox_Serial);
        textEditDoc->setObjectName(QStringLiteral("textEditDoc"));
        textEditDoc->setReadOnly(true);

        horizontalLayout_2->addWidget(textEditDoc);


        verticalLayout->addWidget(groupBox_Serial);

        buttonBox = new QDialogButtonBox(DeviceSelectorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DeviceSelectorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeviceSelectorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeviceSelectorDialog, SLOT(reject()));

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DeviceSelectorDialog);
    } // setupUi

    void retranslateUi(QDialog *DeviceSelectorDialog)
    {
        DeviceSelectorDialog->setWindowTitle(QApplication::translate("DeviceSelectorDialog", "Device Selector Dialog", 0));
        groupBox_Ethernet->setTitle(QApplication::translate("DeviceSelectorDialog", "Device Selection and Arguments", 0));
        m_configureButton->setText(QApplication::translate("DeviceSelectorDialog", "Configure", 0));
        groupBox->setTitle(QApplication::translate("DeviceSelectorDialog", "Scheduling", 0));
        label->setText(QApplication::translate("DeviceSelectorDialog", "Update Period (ms)", 0));
        groupBox_Serial->setTitle(QApplication::translate("DeviceSelectorDialog", "Device Documentation", 0));
    } // retranslateUi

};

namespace Ui {
    class DeviceSelectorDialog: public Ui_DeviceSelectorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESELECTORDIALOG_H
