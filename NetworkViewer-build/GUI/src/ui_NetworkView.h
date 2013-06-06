/********************************************************************************
** Form generated from reading UI file 'NetworkView.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKVIEW_H
#define UI_NETWORKVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkView
{
public:
    QAction *actionInteractive_Arm;
    QAction *actionDevice_Selection;
    QAction *actionTile_Windows;
    QAction *actionClose_All_Windows;
    QAction *actionCascade_Windows;
    QAction *actionQuit;
    QAction *actionPreferences;
    QAction *actionDisable_All_Variables;
    QAction *actionEnable_All_Variables;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QMdiArea *m_mdiArea;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuPlugin;
    QMenu *menuWindow;
    QMenu *menuTools;
    QStatusBar *statusbar;
    QDockWidget *m_debugDockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout;
    QTextEdit *m_textEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QToolButton *saveToolButton;
    QToolButton *clearToolButton;
    QSpacerItem *verticalSpacer;
    QDockWidget *m_moduleDockWidget;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *m_moduleGraphicsView;

    void setupUi(QMainWindow *NetworkView)
    {
        if (NetworkView->objectName().isEmpty())
            NetworkView->setObjectName(QStringLiteral("NetworkView"));
        NetworkView->resize(1143, 854);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NetworkView->sizePolicy().hasHeightForWidth());
        NetworkView->setSizePolicy(sizePolicy);
        actionInteractive_Arm = new QAction(NetworkView);
        actionInteractive_Arm->setObjectName(QStringLiteral("actionInteractive_Arm"));
        actionInteractive_Arm->setCheckable(true);
        actionDevice_Selection = new QAction(NetworkView);
        actionDevice_Selection->setObjectName(QStringLiteral("actionDevice_Selection"));
        actionTile_Windows = new QAction(NetworkView);
        actionTile_Windows->setObjectName(QStringLiteral("actionTile_Windows"));
        actionClose_All_Windows = new QAction(NetworkView);
        actionClose_All_Windows->setObjectName(QStringLiteral("actionClose_All_Windows"));
        actionCascade_Windows = new QAction(NetworkView);
        actionCascade_Windows->setObjectName(QStringLiteral("actionCascade_Windows"));
        actionQuit = new QAction(NetworkView);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionPreferences = new QAction(NetworkView);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionDisable_All_Variables = new QAction(NetworkView);
        actionDisable_All_Variables->setObjectName(QStringLiteral("actionDisable_All_Variables"));
        actionEnable_All_Variables = new QAction(NetworkView);
        actionEnable_All_Variables->setObjectName(QStringLiteral("actionEnable_All_Variables"));
        actionAbout = new QAction(NetworkView);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralwidget = new QWidget(NetworkView);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_mdiArea = new QMdiArea(centralwidget);
        m_mdiArea->setObjectName(QStringLiteral("m_mdiArea"));
        m_mdiArea->setEnabled(true);
        m_mdiArea->setViewMode(QMdiArea::SubWindowView);
        m_mdiArea->setDocumentMode(false);
        m_mdiArea->setTabPosition(QTabWidget::West);

        verticalLayout_2->addWidget(m_mdiArea);

        NetworkView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NetworkView);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1143, 22));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuPlugin = new QMenu(menubar);
        menuPlugin->setObjectName(QStringLiteral("menuPlugin"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        NetworkView->setMenuBar(menubar);
        statusbar = new QStatusBar(NetworkView);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        NetworkView->setStatusBar(statusbar);
        m_debugDockWidget = new QDockWidget(NetworkView);
        m_debugDockWidget->setObjectName(QStringLiteral("m_debugDockWidget"));
        sizePolicy.setHeightForWidth(m_debugDockWidget->sizePolicy().hasHeightForWidth());
        m_debugDockWidget->setSizePolicy(sizePolicy);
        m_debugDockWidget->setMinimumSize(QSize(402, 0));
        m_debugDockWidget->setMaximumSize(QSize(524287, 524287));
        m_debugDockWidget->setFloating(false);
        m_debugDockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        m_debugDockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_textEdit = new QTextEdit(dockWidgetContents);
        m_textEdit->setObjectName(QStringLiteral("m_textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_textEdit->sizePolicy().hasHeightForWidth());
        m_textEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(m_textEdit);

        groupBox = new QGroupBox(dockWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        saveToolButton = new QToolButton(groupBox);
        saveToolButton->setObjectName(QStringLiteral("saveToolButton"));
        saveToolButton->setMinimumSize(QSize(50, 25));

        verticalLayout->addWidget(saveToolButton);

        clearToolButton = new QToolButton(groupBox);
        clearToolButton->setObjectName(QStringLiteral("clearToolButton"));
        clearToolButton->setMinimumSize(QSize(50, 25));

        verticalLayout->addWidget(clearToolButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox);

        m_debugDockWidget->setWidget(dockWidgetContents);
        NetworkView->addDockWidget(static_cast<Qt::DockWidgetArea>(4), m_debugDockWidget);
        m_moduleDockWidget = new QDockWidget(NetworkView);
        m_moduleDockWidget->setObjectName(QStringLiteral("m_moduleDockWidget"));
        m_moduleDockWidget->setMinimumSize(QSize(306, 0));
        m_moduleDockWidget->setMaximumSize(QSize(524287, 524287));
        m_moduleDockWidget->setFloating(false);
        m_moduleDockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        m_moduleGraphicsView = new QGraphicsView(dockWidgetContents_4);
        m_moduleGraphicsView->setObjectName(QStringLiteral("m_moduleGraphicsView"));
        sizePolicy1.setHeightForWidth(m_moduleGraphicsView->sizePolicy().hasHeightForWidth());
        m_moduleGraphicsView->setSizePolicy(sizePolicy1);
        m_moduleGraphicsView->setMinimumSize(QSize(0, 0));
        m_moduleGraphicsView->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(m_moduleGraphicsView);

        m_moduleDockWidget->setWidget(dockWidgetContents_4);
        NetworkView->addDockWidget(static_cast<Qt::DockWidgetArea>(4), m_moduleDockWidget);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuPlugin->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menu_File->addAction(actionDevice_Selection);
        menu_File->addSeparator();
        menu_File->addAction(actionPreferences);
        menu_File->addAction(actionAbout);
        menu_File->addSeparator();
        menu_File->addAction(actionQuit);
        menuWindow->addAction(actionTile_Windows);
        menuWindow->addAction(actionCascade_Windows);
        menuWindow->addAction(actionClose_All_Windows);
        menuWindow->addSeparator();
        menuTools->addAction(actionDisable_All_Variables);
        menuTools->addAction(actionEnable_All_Variables);

        retranslateUi(NetworkView);

        QMetaObject::connectSlotsByName(NetworkView);
    } // setupUi

    void retranslateUi(QMainWindow *NetworkView)
    {
        NetworkView->setWindowTitle(QApplication::translate("NetworkView", "NetViewer", 0));
        actionInteractive_Arm->setText(QApplication::translate("NetworkView", "Interactive Arm", 0));
        actionDevice_Selection->setText(QApplication::translate("NetworkView", "Device Selection", 0));
        actionTile_Windows->setText(QApplication::translate("NetworkView", "Tile Windows", 0));
        actionClose_All_Windows->setText(QApplication::translate("NetworkView", "Close All Windows", 0));
        actionCascade_Windows->setText(QApplication::translate("NetworkView", "Cascade Windows", 0));
        actionQuit->setText(QApplication::translate("NetworkView", "Quit", 0));
        actionPreferences->setText(QApplication::translate("NetworkView", "Preferences", 0));
        actionDisable_All_Variables->setText(QApplication::translate("NetworkView", "Disable all variables", 0));
        actionEnable_All_Variables->setText(QApplication::translate("NetworkView", "Enable all variables", 0));
        actionAbout->setText(QApplication::translate("NetworkView", "About", 0));
        menu_File->setTitle(QApplication::translate("NetworkView", "&NetworkViewer", 0));
        menuPlugin->setTitle(QApplication::translate("NetworkView", "Plugin", 0));
        menuWindow->setTitle(QApplication::translate("NetworkView", "Window", 0));
        menuTools->setTitle(QApplication::translate("NetworkView", "Tools", 0));
        m_debugDockWidget->setWindowTitle(QApplication::translate("NetworkView", "Debug Console", 0));
        groupBox->setTitle(QApplication::translate("NetworkView", "Tools", 0));
        saveToolButton->setText(QApplication::translate("NetworkView", "Save", 0));
        clearToolButton->setText(QApplication::translate("NetworkView", "Clear", 0));
        m_moduleDockWidget->setWindowTitle(QApplication::translate("NetworkView", "Available Modules", 0));
    } // retranslateUi

};

namespace Ui {
    class NetworkView: public Ui_NetworkView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKVIEW_H
