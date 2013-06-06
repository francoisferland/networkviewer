/********************************************************************************
** Form generated from reading UI file 'ScopeView.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOPEVIEW_H
#define UI_SCOPEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScopeView
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *m_groupBox;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *m_playToolButton;
    QToolButton *m_pauseToolButton;
    QToolButton *m_saveToolButton;
    QToolButton *m_clearToolButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *m_bufferSizeSpinbox;
    QSplitter *splitter;
    QFrame *m_frame;

    void setupUi(QWidget *ScopeView)
    {
        if (ScopeView->objectName().isEmpty())
            ScopeView->setObjectName(QStringLiteral("ScopeView"));
        ScopeView->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScopeView->sizePolicy().hasHeightForWidth());
        ScopeView->setSizePolicy(sizePolicy);
        ScopeView->setMinimumSize(QSize(640, 480));
        verticalLayout = new QVBoxLayout(ScopeView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_groupBox = new QGroupBox(ScopeView);
        m_groupBox->setObjectName(QStringLiteral("m_groupBox"));
        m_groupBox->setEnabled(true);
        m_groupBox->setMinimumSize(QSize(0, 0));
        m_groupBox->setMaximumSize(QSize(16777215, 80));
        m_groupBox->setAutoFillBackground(false);
        m_groupBox->setFlat(false);
        m_groupBox->setCheckable(false);
        horizontalLayout_2 = new QHBoxLayout(m_groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_playToolButton = new QToolButton(m_groupBox);
        m_playToolButton->setObjectName(QStringLiteral("m_playToolButton"));
        m_playToolButton->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/playGreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_playToolButton->setIcon(icon);

        horizontalLayout_2->addWidget(m_playToolButton);

        m_pauseToolButton = new QToolButton(m_groupBox);
        m_pauseToolButton->setObjectName(QStringLiteral("m_pauseToolButton"));
        m_pauseToolButton->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/pauseGreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pauseToolButton->setIcon(icon1);

        horizontalLayout_2->addWidget(m_pauseToolButton);

        m_saveToolButton = new QToolButton(m_groupBox);
        m_saveToolButton->setObjectName(QStringLiteral("m_saveToolButton"));
        m_saveToolButton->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/Save-Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_saveToolButton->setIcon(icon2);

        horizontalLayout_2->addWidget(m_saveToolButton);

        m_clearToolButton = new QToolButton(m_groupBox);
        m_clearToolButton->setObjectName(QStringLiteral("m_clearToolButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_clearToolButton->setIcon(icon3);

        horizontalLayout_2->addWidget(m_clearToolButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(m_groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        m_bufferSizeSpinbox = new QSpinBox(m_groupBox);
        m_bufferSizeSpinbox->setObjectName(QStringLiteral("m_bufferSizeSpinbox"));
        m_bufferSizeSpinbox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_bufferSizeSpinbox->setMinimum(100);
        m_bufferSizeSpinbox->setMaximum(999999999);
        m_bufferSizeSpinbox->setSingleStep(100);
        m_bufferSizeSpinbox->setValue(500);

        horizontalLayout_2->addWidget(m_bufferSizeSpinbox);


        verticalLayout->addWidget(m_groupBox);

        splitter = new QSplitter(ScopeView);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        m_frame = new QFrame(splitter);
        m_frame->setObjectName(QStringLiteral("m_frame"));
        m_frame->setAcceptDrops(true);
        m_frame->setFrameShape(QFrame::StyledPanel);
        m_frame->setFrameShadow(QFrame::Raised);
        splitter->addWidget(m_frame);

        verticalLayout->addWidget(splitter);


        retranslateUi(ScopeView);

        QMetaObject::connectSlotsByName(ScopeView);
    } // setupUi

    void retranslateUi(QWidget *ScopeView)
    {
        ScopeView->setWindowTitle(QApplication::translate("ScopeView", "Scope", 0));
        m_groupBox->setTitle(QApplication::translate("ScopeView", "Tools", 0));
        m_playToolButton->setText(QApplication::translate("ScopeView", "...", 0));
        m_pauseToolButton->setText(QApplication::translate("ScopeView", "...", 0));
        m_saveToolButton->setText(QApplication::translate("ScopeView", "...", 0));
#ifndef QT_NO_TOOLTIP
        m_clearToolButton->setToolTip(QApplication::translate("ScopeView", "Clear Scope", 0));
#endif // QT_NO_TOOLTIP
        m_clearToolButton->setText(QApplication::translate("ScopeView", "C", 0));
        label->setText(QApplication::translate("ScopeView", "BufferSize", 0));
    } // retranslateUi

};

namespace Ui {
    class ScopeView: public Ui_ScopeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPEVIEW_H
