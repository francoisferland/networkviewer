/********************************************************************************
** Form generated from reading UI file 'dsPICBootloader.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSPICBOOTLOADER_H
#define UI_DSPICBOOTLOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dsPICBootloader
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QComboBox *m_moduleSelectionCombo;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_filenameLineEdit;
    QLabel *label_2;
    QLineEdit *m_sizeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_loadHEXButton;
    QPushButton *m_uploadButton;
    QPushButton *m_stopButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *m_moduleIDLabel;
    QPushButton *m_changeModuleIDButton;
    QLabel *m_projectIDLabel;
    QLabel *label_3;
    QPushButton *m_changeProjectIDButton;
    QLabel *label_6;
    QLabel *m_codeVersionLabel;
    QPushButton *m_changeCodeVersionButton;
    QLabel *label_5;
    QLabel *m_tableVersionLabel;
    QLabel *m_deviceIDLabel;
    QLabel *label_8;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *m_textEdit;
    QProgressBar *m_progressBar;

    void setupUi(QWidget *dsPICBootloader)
    {
        if (dsPICBootloader->objectName().isEmpty())
            dsPICBootloader->setObjectName(QStringLiteral("dsPICBootloader"));
        dsPICBootloader->resize(640, 574);
        dsPICBootloader->setMinimumSize(QSize(640, 480));
        verticalLayout_2 = new QVBoxLayout(dsPICBootloader);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(dsPICBootloader);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_moduleSelectionCombo = new QComboBox(groupBox);
        m_moduleSelectionCombo->setObjectName(QStringLiteral("m_moduleSelectionCombo"));

        verticalLayout->addWidget(m_moduleSelectionCombo);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(dsPICBootloader);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_filenameLineEdit = new QLineEdit(groupBox_2);
        m_filenameLineEdit->setObjectName(QStringLiteral("m_filenameLineEdit"));
        m_filenameLineEdit->setReadOnly(true);

        gridLayout->addWidget(m_filenameLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_sizeLineEdit = new QLineEdit(groupBox_2);
        m_sizeLineEdit->setObjectName(QStringLiteral("m_sizeLineEdit"));
        m_sizeLineEdit->setReadOnly(true);

        gridLayout->addWidget(m_sizeLineEdit, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_loadHEXButton = new QPushButton(groupBox_2);
        m_loadHEXButton->setObjectName(QStringLiteral("m_loadHEXButton"));
        m_loadHEXButton->setEnabled(true);

        horizontalLayout_2->addWidget(m_loadHEXButton);

        m_uploadButton = new QPushButton(groupBox_2);
        m_uploadButton->setObjectName(QStringLiteral("m_uploadButton"));
        m_uploadButton->setEnabled(false);

        horizontalLayout_2->addWidget(m_uploadButton);

        m_stopButton = new QPushButton(groupBox_2);
        m_stopButton->setObjectName(QStringLiteral("m_stopButton"));
        m_stopButton->setEnabled(false);

        horizontalLayout_2->addWidget(m_stopButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(dsPICBootloader);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        m_moduleIDLabel = new QLabel(groupBox_3);
        m_moduleIDLabel->setObjectName(QStringLiteral("m_moduleIDLabel"));

        gridLayout_2->addWidget(m_moduleIDLabel, 0, 1, 1, 1);

        m_changeModuleIDButton = new QPushButton(groupBox_3);
        m_changeModuleIDButton->setObjectName(QStringLiteral("m_changeModuleIDButton"));

        gridLayout_2->addWidget(m_changeModuleIDButton, 0, 2, 1, 1);

        m_projectIDLabel = new QLabel(groupBox_3);
        m_projectIDLabel->setObjectName(QStringLiteral("m_projectIDLabel"));

        gridLayout_2->addWidget(m_projectIDLabel, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        m_changeProjectIDButton = new QPushButton(groupBox_3);
        m_changeProjectIDButton->setObjectName(QStringLiteral("m_changeProjectIDButton"));
        m_changeProjectIDButton->setEnabled(false);

        gridLayout_2->addWidget(m_changeProjectIDButton, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        m_codeVersionLabel = new QLabel(groupBox_3);
        m_codeVersionLabel->setObjectName(QStringLiteral("m_codeVersionLabel"));

        gridLayout_2->addWidget(m_codeVersionLabel, 2, 1, 1, 1);

        m_changeCodeVersionButton = new QPushButton(groupBox_3);
        m_changeCodeVersionButton->setObjectName(QStringLiteral("m_changeCodeVersionButton"));
        m_changeCodeVersionButton->setEnabled(false);

        gridLayout_2->addWidget(m_changeCodeVersionButton, 2, 2, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        m_tableVersionLabel = new QLabel(groupBox_3);
        m_tableVersionLabel->setObjectName(QStringLiteral("m_tableVersionLabel"));

        gridLayout_2->addWidget(m_tableVersionLabel, 4, 1, 1, 1);

        m_deviceIDLabel = new QLabel(groupBox_3);
        m_deviceIDLabel->setObjectName(QStringLiteral("m_deviceIDLabel"));

        gridLayout_2->addWidget(m_deviceIDLabel, 6, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 6, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(dsPICBootloader);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 50));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        m_textEdit = new QTextEdit(groupBox_4);
        m_textEdit->setObjectName(QStringLiteral("m_textEdit"));

        verticalLayout_3->addWidget(m_textEdit);


        verticalLayout_2->addWidget(groupBox_4);

        m_progressBar = new QProgressBar(dsPICBootloader);
        m_progressBar->setObjectName(QStringLiteral("m_progressBar"));
        m_progressBar->setValue(0);

        verticalLayout_2->addWidget(m_progressBar);


        retranslateUi(dsPICBootloader);

        QMetaObject::connectSlotsByName(dsPICBootloader);
    } // setupUi

    void retranslateUi(QWidget *dsPICBootloader)
    {
        dsPICBootloader->setWindowTitle(QApplication::translate("dsPICBootloader", "Form", 0));
        groupBox->setTitle(QApplication::translate("dsPICBootloader", "Module Selection", 0));
        groupBox_2->setTitle(QApplication::translate("dsPICBootloader", "Programming", 0));
        label->setText(QApplication::translate("dsPICBootloader", "Filename : ", 0));
        label_2->setText(QApplication::translate("dsPICBootloader", "Size", 0));
        m_loadHEXButton->setText(QApplication::translate("dsPICBootloader", "Load HEX", 0));
        m_uploadButton->setText(QApplication::translate("dsPICBootloader", "UPLOAD", 0));
        m_stopButton->setText(QApplication::translate("dsPICBootloader", "STOP", 0));
        groupBox_3->setTitle(QApplication::translate("dsPICBootloader", "BootConfig", 0));
        label_4->setText(QApplication::translate("dsPICBootloader", "Module ID", 0));
        m_moduleIDLabel->setText(QApplication::translate("dsPICBootloader", "0", 0));
        m_changeModuleIDButton->setText(QApplication::translate("dsPICBootloader", "Change Module ID", 0));
        m_projectIDLabel->setText(QApplication::translate("dsPICBootloader", "0", 0));
        label_3->setText(QApplication::translate("dsPICBootloader", "Project ID", 0));
        m_changeProjectIDButton->setText(QApplication::translate("dsPICBootloader", "Change Project ID", 0));
        label_6->setText(QApplication::translate("dsPICBootloader", "Code Version", 0));
        m_codeVersionLabel->setText(QApplication::translate("dsPICBootloader", "0", 0));
        m_changeCodeVersionButton->setText(QApplication::translate("dsPICBootloader", "Change Code Version", 0));
        label_5->setText(QApplication::translate("dsPICBootloader", "Table Version", 0));
        m_tableVersionLabel->setText(QApplication::translate("dsPICBootloader", "0", 0));
        m_deviceIDLabel->setText(QApplication::translate("dsPICBootloader", "0", 0));
        label_8->setText(QApplication::translate("dsPICBootloader", "Device ID", 0));
        groupBox_4->setTitle(QApplication::translate("dsPICBootloader", "Messages", 0));
    } // retranslateUi

};

namespace Ui {
    class dsPICBootloader: public Ui_dsPICBootloader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSPICBOOTLOADER_H
