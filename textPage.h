#pragma once

#include <QWidget>
#include "ui_textPage.h"

namespace Ui {
	class textPage;
}

class textPage : public QWidget
{
	Q_OBJECT

public:
	textPage(QString,QString,QWidget *parent = Q_NULLPTR);
	textPage(QWidget* parent = Q_NULLPTR);
	~textPage();
	void setUp(QString str,QString file);
	QString GetText();
	QString GetFile();
	bool fileSaved = true;
	
private:
	Ui::textPage * ui;
	QString currentFile;
	void unSave() { fileSaved = false; };
};
