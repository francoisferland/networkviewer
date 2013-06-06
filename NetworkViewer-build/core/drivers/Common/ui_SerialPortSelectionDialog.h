/********************************************************************************
** Form generated from reading UI file 'SerialPortSelectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSELECTIONDIALOG_H
#define UI_SERIALPORTSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SerialPortSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *m_portComboBox;
    QComboBox *m_baudComboBox;
    QCheckBox *m_debugCheckbox;
    QLabel *m_label;
    QSpinBox *m_delaySpinBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *m_textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SerialPortSelectionDialog)
    {
        if (SerialPortSelectionDialog->objectName().isEmpty())
            SerialPortSelectionDialog->setObjectName(QStringLiteral("SerialPortSelectionDialog"));
        SerialPortSelectionDialog->resize(727, 454);
        verticalLayout = new QVBoxLayout(SerialPortSelectionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(SerialPortSelectionDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_portComboBox = new QComboBox(groupBox);
        m_portComboBox->setObjectName(QStringLiteral("m_portComboBox"));

        gridLayout->addWidget(m_portComboBox, 0, 0, 1, 1);

        m_baudComboBox = new QComboBox(groupBox);
        m_baudComboBox->setObjectName(QStringLiteral("m_baudComboBox"));

        gridLayout->addWidget(m_baudComboBox, 0, 2, 1, 1);

        m_debugCheckbox = new QCheckBox(groupBox);
        m_debugCheckbox->setObjectName(QStringLiteral("m_debugCheckbox"));

        gridLayout->addWidget(m_debugCheckbox, 1, 0, 1, 1);

        m_label = new QLabel(groupBox);
        m_label->setObjectName(QStringLiteral("m_label"));
        m_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(m_label, 2, 0, 1, 1);

        m_delaySpinBox = new QSpinBox(groupBox);
        m_delaySpinBox->setObjectName(QStringLiteral("m_delaySpinBox"));
        m_delaySpinBox->setValue(5);

        gridLayout->addWidget(m_delaySpinBox, 2, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SerialPortSelectionDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_textEdit = new QTextEdit(groupBox_2);
        m_textEdit->setObjectName(QStringLiteral("m_textEdit"));

        horizontalLayout_2->addWidget(m_textEdit);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(SerialPortSelectionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SerialPortSelectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SerialPortSelectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SerialPortSelectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SerialPortSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *SerialPortSelectionDialog)
    {
        SerialPortSelectionDialog->setWindowTitle(QApplication::translate("SerialPortSelectionDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("SerialPortSelectionDialog", "Port Configuration", 0));
        m_baudComboBox->clear();
        m_baudComboBox->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSelectionDialog", "50", 0)
         << QApplication::translate("SerialPortSelectionDialog", "75", 0)
         << QApplication::translate("SerialPortSelectionDialog", "110", 0)
         << QApplication::translate("SerialPortSelectionDialog", "134", 0)
         << QApplication::translate("SerialPortSelectionDialog", "150", 0)
         << QApplication::translate("SerialPortSelectionDialog", "200", 0)
         << QApplication::translate("SerialPortSelectionDialog", "300", 0)
         << QApplication::translate("SerialPortSelectionDialog", "600", 0)
         << QApplication::translate("SerialPortSelectionDialog", "1200", 0)
         << QApplication::translate("SerialPortSelectionDialog", "1800", 0)
         << QApplication::translate("SerialPortSelectionDialog", "2400", 0)
         << QApplication::translate("SerialPortSelectionDialog", "4800", 0)
         << QApplication::translate("SerialPortSelectionDialog", "9600", 0)
         << QApplication::translate("SerialPortSelectionDialog", "14400", 0)
         << QApplication::translate("SerialPortSelectionDialog", "19200", 0)
         << QApplication::translate("SerialPortSelectionDialog", "38400", 0)
         << QApplication::translate("SerialPortSelectionDialog", "56000", 0)
         << QApplication::translate("SerialPortSelectionDialog", "57600", 0)
         << QApplication::translate("SerialPortSelectionDialog", "76800", 0)
         << QApplication::translate("SerialPortSelectionDialog", "115200", 0)
         << QApplication::translate("SerialPortSelectionDialog", "128000", 0)
         << QApplication::translate("SerialPortSelectionDialog", "256000", 0)
         << QApplication::translate("SerialPortSelectionDialog", "500000", 0)
         << QApplication::translate("SerialPortSelectionDialog", "1000000", 0)
        );
        m_debugCheckbox->setText(QApplication::translate("SerialPortSelectionDialog", "Debug", 0));
        m_label->setText(QApplication::translate("SerialPortSelectionDialog", "Delay", 0));
        groupBox_2->setTitle(QApplication::translate("SerialPortSelectionDialog", "Port Information", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPortSelectionDialog: public Ui_SerialPortSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSELECTIONDIALOG_H
