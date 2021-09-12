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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tutorial
{
public:
    QAction *actionNew;
    QAction *actionNew_folder;
    QAction *actionNew_window;
    QAction *actionOpen_file;
    QAction *actionOpen_folder;
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
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial)
    {
        if (Tutorial->objectName().isEmpty())
            Tutorial->setObjectName(QString::fromUtf8("Tutorial"));
        Tutorial->resize(789, 425);
        QIcon icon;
        icon.addFile(QString::fromUtf8("bitmap1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        Tutorial->setWindowIcon(icon);
        Tutorial->setStyleSheet(QString::fromUtf8("background-color:#222222;"));
        actionNew = new QAction(Tutorial);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew_folder = new QAction(Tutorial);
        actionNew_folder->setObjectName(QString::fromUtf8("actionNew_folder"));
        actionNew_window = new QAction(Tutorial);
        actionNew_window->setObjectName(QString::fromUtf8("actionNew_window"));
        actionOpen_file = new QAction(Tutorial);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        actionOpen_folder = new QAction(Tutorial);
        actionOpen_folder->setObjectName(QString::fromUtf8("actionOpen_folder"));
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
        centralWidget = new QWidget(Tutorial);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 789, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        treeWidget = new QTreeWidget(gridLayoutWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMinimumSize(QSize(150, 0));
        treeWidget->setMaximumSize(QSize(300, 16777215));
        treeWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->setHeaderHidden(false);
        treeWidget->setColumnCount(1);
        treeWidget->header()->setVisible(true);

        gridLayout->addWidget(treeWidget, 1, 0, 3, 1);

        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setTabsClosable(true);

        gridLayout->addWidget(tabWidget, 1, 1, 1, 1);

        Tutorial->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 22));
        menuBar->setStyleSheet(QString::fromUtf8("background-color:rgb(61, 61, 61);color:white;"));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        Tutorial->setMenuBar(menuBar);
        statusBar = new QStatusBar(Tutorial);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("background-color:#0099FF"));
        Tutorial->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionNew_folder);
        menu_File->addAction(actionNew_window);
        menu_File->addSeparator();
        menu_File->addAction(actionOpen_file);
        menu_File->addAction(actionOpen_folder);
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

        retranslateUi(Tutorial);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Tutorial);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial)
    {
        Tutorial->setWindowTitle(QCoreApplication::translate("Tutorial", "Tutorial", nullptr));
        actionNew->setText(QCoreApplication::translate("Tutorial", "New file", nullptr));
        actionNew_folder->setText(QCoreApplication::translate("Tutorial", "New folder", nullptr));
        actionNew_window->setText(QCoreApplication::translate("Tutorial", "New window", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("Tutorial", "Open file...", nullptr));
        actionOpen_folder->setText(QCoreApplication::translate("Tutorial", "Open folder", nullptr));
        actionSave->setText(QCoreApplication::translate("Tutorial", "Save file", nullptr));
        actionSave_file_as->setText(QCoreApplication::translate("Tutorial", "Save file as...", nullptr));
        actionSave_folder->setText(QCoreApplication::translate("Tutorial", "Save folder", nullptr));
        actionSave_folder_as->setText(QCoreApplication::translate("Tutorial", "Save folder as...", nullptr));
        actionClose_file->setText(QCoreApplication::translate("Tutorial", "Close file", nullptr));
        actionClose_folder->setText(QCoreApplication::translate("Tutorial", "Close folder", nullptr));
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
        actionSettings_2->setText(QCoreApplication::translate("Tutorial", "Settings...", nullptr));
        actionQuit_2->setText(QCoreApplication::translate("Tutorial", "Quit", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Tutorial", "Folder", nullptr));
        menu_File->setTitle(QCoreApplication::translate("Tutorial", "&File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Tutorial", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial: public Ui_Tutorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
