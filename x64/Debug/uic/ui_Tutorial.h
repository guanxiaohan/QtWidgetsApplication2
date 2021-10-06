/********************************************************************************
** Form generated from reading UI file 'Tutorial.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL_H
#define UI_TUTORIAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tutorial
{
public:
    QAction *actionNew;
    QAction *actionNew_project;
    QAction *actionNew_window;
    QAction *actionOpen_file;
    QAction *actionOpen_project;
    QAction *actionSave;
    QAction *actionSave_file_as;
    QAction *actionSave_folder;
    QAction *actionSave_folder_as;
    QAction *actionClose_file;
    QAction *actionClose_folder;
    QAction *actionClose_window;
    QAction *actionQuit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFont;
    QAction *actionSettings;
    QAction *actionPrint;
    QAction *actionSettings_2;
    QAction *actionQuit_2;
    QAction *actionNew_command;
    QAction *actionProject_Viewer;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *CmdTabWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menuViews;
    QStatusBar *statusBar;
    QDockWidget *ProjectViewer;
    QWidget *dockWidgetContents_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *actionProject_options;
    QToolButton *actionProject_delete;
    QToolButton *actionProject_new;
    QToolButton *openProjectFileButton;
    QListWidget *projectListWidget;

    void setupUi(QMainWindow *Tutorial)
    {
        if (Tutorial->objectName().isEmpty())
            Tutorial->setObjectName(QString::fromUtf8("Tutorial"));
        Tutorial->resize(793, 428);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/Lenovo/.designer/backup/bitmap1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        Tutorial->setWindowIcon(icon);
        actionNew = new QAction(Tutorial);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew_project = new QAction(Tutorial);
        actionNew_project->setObjectName(QString::fromUtf8("actionNew_project"));
        actionNew_window = new QAction(Tutorial);
        actionNew_window->setObjectName(QString::fromUtf8("actionNew_window"));
        actionOpen_file = new QAction(Tutorial);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        actionOpen_project = new QAction(Tutorial);
        actionOpen_project->setObjectName(QString::fromUtf8("actionOpen_project"));
        actionSave = new QAction(Tutorial);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_file_as = new QAction(Tutorial);
        actionSave_file_as->setObjectName(QString::fromUtf8("actionSave_file_as"));
        actionSave_folder = new QAction(Tutorial);
        actionSave_folder->setObjectName(QString::fromUtf8("actionSave_folder"));
        actionSave_folder_as = new QAction(Tutorial);
        actionSave_folder_as->setObjectName(QString::fromUtf8("actionSave_folder_as"));
        actionClose_file = new QAction(Tutorial);
        actionClose_file->setObjectName(QString::fromUtf8("actionClose_file"));
        actionClose_folder = new QAction(Tutorial);
        actionClose_folder->setObjectName(QString::fromUtf8("actionClose_folder"));
        actionClose_window = new QAction(Tutorial);
        actionClose_window->setObjectName(QString::fromUtf8("actionClose_window"));
        actionQuit = new QAction(Tutorial);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionUndo = new QAction(Tutorial);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(Tutorial);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionCut = new QAction(Tutorial);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(Tutorial);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(Tutorial);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionFont = new QAction(Tutorial);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionSettings = new QAction(Tutorial);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionPrint = new QAction(Tutorial);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionSettings_2 = new QAction(Tutorial);
        actionSettings_2->setObjectName(QString::fromUtf8("actionSettings_2"));
        actionQuit_2 = new QAction(Tutorial);
        actionQuit_2->setObjectName(QString::fromUtf8("actionQuit_2"));
        actionNew_command = new QAction(Tutorial);
        actionNew_command->setObjectName(QString::fromUtf8("actionNew_command"));
        actionProject_Viewer = new QAction(Tutorial);
        actionProject_Viewer->setObjectName(QString::fromUtf8("actionProject_Viewer"));
        centralWidget = new QWidget(Tutorial);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 791, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        CmdTabWidget = new QTabWidget(gridLayoutWidget);
        CmdTabWidget->setObjectName(QString::fromUtf8("CmdTabWidget"));
        CmdTabWidget->setTabPosition(QTabWidget::South);
        CmdTabWidget->setTabShape(QTabWidget::Triangular);
        CmdTabWidget->setTabsClosable(true);
        CmdTabWidget->setMovable(true);
        CmdTabWidget->setTabBarAutoHide(false);

        gridLayout->addWidget(CmdTabWidget, 2, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        toolButton = new QToolButton(gridLayoutWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setTabsClosable(true);

        gridLayout->addWidget(tabWidget, 1, 0, 1, 3);

        Tutorial->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 793, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuViews = new QMenu(menuBar);
        menuViews->setObjectName(QString::fromUtf8("menuViews"));
        Tutorial->setMenuBar(menuBar);
        statusBar = new QStatusBar(Tutorial);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial->setStatusBar(statusBar);
        ProjectViewer = new QDockWidget(Tutorial);
        ProjectViewer->setObjectName(QString::fromUtf8("ProjectViewer"));
        ProjectViewer->setFloating(false);
        ProjectViewer->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayoutWidget_2 = new QWidget(dockWidgetContents_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(-1, -1, 235, 351));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        actionProject_options = new QPushButton(gridLayoutWidget_2);
        actionProject_options->setObjectName(QString::fromUtf8("actionProject_options"));

        gridLayout_2->addWidget(actionProject_options, 0, 3, 1, 1);

        actionProject_delete = new QToolButton(gridLayoutWidget_2);
        actionProject_delete->setObjectName(QString::fromUtf8("actionProject_delete"));

        gridLayout_2->addWidget(actionProject_delete, 0, 0, 1, 1);

        actionProject_new = new QToolButton(gridLayoutWidget_2);
        actionProject_new->setObjectName(QString::fromUtf8("actionProject_new"));

        gridLayout_2->addWidget(actionProject_new, 0, 1, 1, 1);

        openProjectFileButton = new QToolButton(gridLayoutWidget_2);
        openProjectFileButton->setObjectName(QString::fromUtf8("openProjectFileButton"));

        gridLayout_2->addWidget(openProjectFileButton, 0, 2, 1, 1);

        projectListWidget = new QListWidget(gridLayoutWidget_2);
        projectListWidget->setObjectName(QString::fromUtf8("projectListWidget"));

        gridLayout_2->addWidget(projectListWidget, 1, 0, 1, 4);

        ProjectViewer->setWidget(dockWidgetContents_2);
        Tutorial->addDockWidget(Qt::RightDockWidgetArea, ProjectViewer);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuViews->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionNew_project);
        menu_File->addAction(actionNew_window);
        menu_File->addAction(actionNew_command);
        menu_File->addSeparator();
        menu_File->addAction(actionOpen_file);
        menu_File->addAction(actionOpen_project);
        menu_File->addSeparator();
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSave_file_as);
        menu_File->addAction(actionSave_folder);
        menu_File->addAction(actionSave_folder_as);
        menu_File->addSeparator();
        menu_File->addAction(actionClose_file);
        menu_File->addAction(actionClose_folder);
        menu_File->addAction(actionClose_window);
        menu_File->addSeparator();
        menu_File->addAction(actionPrint);
        menu_File->addAction(actionSettings_2);
        menu_File->addAction(actionQuit_2);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFont);
        menuViews->addAction(actionProject_Viewer);

        retranslateUi(Tutorial);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Tutorial);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial)
    {
        Tutorial->setWindowTitle(QCoreApplication::translate("Tutorial", "Tutorial", nullptr));
        actionNew->setText(QCoreApplication::translate("Tutorial", "New file", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+N, Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_project->setText(QCoreApplication::translate("Tutorial", "New project", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_project->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+N, Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_window->setText(QCoreApplication::translate("Tutorial", "New window", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("Tutorial", "Open file...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_file->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+O, Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_project->setText(QCoreApplication::translate("Tutorial", "Open project", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_project->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+O, Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("Tutorial", "Save file", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_file_as->setText(QCoreApplication::translate("Tutorial", "Save file as...", nullptr));
        actionSave_folder->setText(QCoreApplication::translate("Tutorial", "Save folder", nullptr));
        actionSave_folder_as->setText(QCoreApplication::translate("Tutorial", "Save folder as...", nullptr));
        actionClose_file->setText(QCoreApplication::translate("Tutorial", "Close file", nullptr));
        actionClose_folder->setText(QCoreApplication::translate("Tutorial", "Close project", nullptr));
        actionClose_window->setText(QCoreApplication::translate("Tutorial", "Close window", nullptr));
        actionQuit->setText(QCoreApplication::translate("Tutorial", "Quit", nullptr));
        actionUndo->setText(QCoreApplication::translate("Tutorial", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("Tutorial", "Redo", nullptr));
        actionCut->setText(QCoreApplication::translate("Tutorial", "Cut", nullptr));
        actionCopy->setText(QCoreApplication::translate("Tutorial", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("Tutorial", "Paste", nullptr));
        actionFont->setText(QCoreApplication::translate("Tutorial", "Font...", nullptr));
        actionSettings->setText(QCoreApplication::translate("Tutorial", "Settings", nullptr));
        actionPrint->setText(QCoreApplication::translate("Tutorial", "Print...", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSettings_2->setText(QCoreApplication::translate("Tutorial", "Settings...", nullptr));
        actionQuit_2->setText(QCoreApplication::translate("Tutorial", "Quit", nullptr));
        actionNew_command->setText(QCoreApplication::translate("Tutorial", "New command", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_command->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+N, Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionProject_Viewer->setText(QCoreApplication::translate("Tutorial", "Project Viewer", nullptr));
#if QT_CONFIG(shortcut)
        actionProject_Viewer->setShortcut(QCoreApplication::translate("Tutorial", "Ctrl+0, Ctrl+Alt+Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        toolButton->setText(QCoreApplication::translate("Tutorial", "...", nullptr));
        menu_File->setTitle(QCoreApplication::translate("Tutorial", "&File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Tutorial", "Edit", nullptr));
        menuViews->setTitle(QCoreApplication::translate("Tutorial", "Views", nullptr));
        ProjectViewer->setWindowTitle(QCoreApplication::translate("Tutorial", "Project Viewer", nullptr));
        actionProject_options->setText(QCoreApplication::translate("Tutorial", "Options...", nullptr));
        actionProject_delete->setText(QCoreApplication::translate("Tutorial", "Delete", nullptr));
        actionProject_new->setText(QCoreApplication::translate("Tutorial", "New", nullptr));
        openProjectFileButton->setText(QCoreApplication::translate("Tutorial", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial: public Ui_Tutorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
