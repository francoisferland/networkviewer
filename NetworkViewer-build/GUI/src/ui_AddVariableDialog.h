/********************************************************************************
** Form generated from reading UI file 'AddVariableDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVARIABLEDIALOG_H
#define UI_ADDVARIABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddVariableDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_variableNameLineEdit;
    QLabel *label_2;
    QComboBox *m_variableTypeCombo;
    QLabel *label_4;
    QComboBox *m_variableMemoryTypeCombo;
    QTextEdit *m_variableDescriptionTextEdit;
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *m_variableOffsetSpinBox;

    void setupUi(QDialog *AddVariableDialog)
    {
        if (AddVariableDialog->objectName().isEmpty())
            AddVariableDialog->setObjectName(QStringLiteral("AddVariableDialog"));
        AddVariableDialog->resize(449, 300);
        gridLayout = new QGridLayout(AddVariableDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(AddVariableDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_variableNameLineEdit = new QLineEdit(AddVariableDialog);
        m_variableNameLineEdit->setObjectName(QStringLiteral("m_variableNameLineEdit"));

        gridLayout->addWidget(m_variableNameLineEdit, 0, 2, 1, 1);

        label_2 = new QLabel(AddVariableDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_variableTypeCombo = new QComboBox(AddVariableDialog);
        m_variableTypeCombo->setObjectName(QStringLiteral("m_variableTypeCombo"));

        gridLayout->addWidget(m_variableTypeCombo, 1, 2, 1, 1);

        label_4 = new QLabel(AddVariableDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        m_variableMemoryTypeCombo = new QComboBox(AddVariableDialog);
        m_variableMemoryTypeCombo->setObjectName(QStringLiteral("m_variableMemoryTypeCombo"));

        gridLayout->addWidget(m_variableMemoryTypeCombo, 3, 2, 1, 1);

        m_variableDescriptionTextEdit = new QTextEdit(AddVariableDialog);
        m_variableDescriptionTextEdit->setObjectName(QStringLiteral("m_variableDescriptionTextEdit"));

        gridLayout->addWidget(m_variableDescriptionTextEdit, 5, 1, 1, 2);

        buttonBox = new QDialogButtonBox(AddVariableDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 0, 1, 3);

        label_5 = new QLabel(AddVariableDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_3 = new QLabel(AddVariableDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        m_variableOffsetSpinBox = new QSpinBox(AddVariableDialog);
        m_variableOffsetSpinBox->setObjectName(QStringLiteral("m_variableOffsetSpinBox"));
        m_variableOffsetSpinBox->setMaximum(256);

        gridLayout->addWidget(m_variableOffsetSpinBox, 4, 2, 1, 1);


        retranslateUi(AddVariableDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddVariableDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddVariableDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddVariableDialog);
    } // setupUi

    void retranslateUi(QDialog *AddVariableDialog)
    {
        AddVariableDialog->setWindowTitle(QApplication::translate("AddVariableDialog", "Dialog", 0));
        label->setText(QApplication::translate("AddVariableDialog", "Variable Name", 0));
        label_2->setText(QApplication::translate("AddVariableDialog", "Variable Value Type", 0));
        m_variableTypeCombo->clear();
        m_variableTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("AddVariableDialog", "double", 0)
         << QApplication::translate("AddVariableDialog", "float", 0)
         << QApplication::translate("AddVariableDialog", "sint32", 0)
         << QApplication::translate("AddVariableDialog", "uint32", 0)
         << QApplication::translate("AddVariableDialog", "sint16", 0)
         << QApplication::translate("AddVariableDialog", "uint16", 0)
         << QApplication::translate("AddVariableDialog", "sint8", 0)
         << QApplication::translate("AddVariableDialog", "uint8", 0)
         << QApplication::translate("AddVariableDialog", "bytearray8", 0)
        );
        label_4->setText(QApplication::translate("AddVariableDialog", "Variable Memory Type", 0));
        m_variableMemoryTypeCombo->clear();
        m_variableMemoryTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("AddVariableDialog", "RAM", 0)
         << QApplication::translate("AddVariableDialog", "EEPROM", 0)
        );
        label_5->setText(QApplication::translate("AddVariableDialog", "Variable Description", 0));
        label_3->setText(QApplication::translate("AddVariableDialog", "Variable Memory Offset", 0));
    } // retranslateUi

};

namespace Ui {
    class AddVariableDialog: public Ui_AddVariableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVARIABLEDIALOG_H
