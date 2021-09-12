#pragma once

#include "ui_Tutorial.h"
#include "textPage.h"
#include <qmainwindow.h>
#include <QList>
#include <QFile>
#include <qtextstream.h>

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

private:
	Ui::Tutorial* ui;
	textPage* currentTab;

private slots:
	void newFile();
	void openFile();
};