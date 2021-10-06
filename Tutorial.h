#pragma once

#include "ui_Tutorial.h"
#include "textPage.h"
#include "powerShell.h"
#include "Projecter.h"
#include "newFileDialog.h"
#include <qmainwindow.h>
#include <QList>
#include <QFile>
#include <qtextstream.h>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTreeWidgetItem>

namespace Ui {
	class Tutorial;
}

class Tutorial :public QMainWindow {
	Q_OBJECT

public:
	Tutorial(QMainWindow* parent = nullptr);
	~Tutorial();
	struct Tab {
		QString file;
		QString text;
		textPage* widget;
	};
	QList<textPage*> Tabs;
	QList<powerShell*> cmdTabs;
	bool projectOpened = false;
	void reflashProjectTreeWidget();

private:
	Ui::Tutorial* ui;
	textPage* currentTab;
	Projecter project;
	QList<QTreeWidgetItem*> ProjectFilesItem;
	

private slots:
	void newFile();
	void newCommand();
	void openFile(const QString dir = "");
	void openProject();
	void saveFile();
	void showCommand();
	void printCode();
	void projectFileOpened(QTreeWidgetItem* item, int column);
};