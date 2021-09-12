#pragma once

#include <QWidget>
#include "ui_textPage.h"
#include <qtextdocument.h>
#include <QTextCursor>
#include <QTextCharFormat>
#include <qmessagebox.h>
#include <qsyntaxhighlighter.h>
#include <qvector.h>
#include <qregularexpression.h>
#include <qstringliteral.h>
#include <qstringlist.h>
#include <QTimer>

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
	Ui::textPage* ui;
	void colorText();
	QTimer* timer = new QTimer();
	
private:
	QString currentFile;
	void unSave() { fileSaved = false; };
};
