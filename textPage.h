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
	QTimer* timer = new QTimer();
	
private:
	QString currentFile;
	void unSave() { fileSaved = false; };
};

class IntelliSence:public QSyntaxHighlighter
{
    Q_OBJECT

public:
    IntelliSence(QTextDocument * parent = 0);

protected:
    void IntelliSenceBlock(const QString& text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};