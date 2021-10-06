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
#include <qtimer.h>
#include <qrgb.h>
#include <qbrush.h>
#include <qcolor.h>

namespace Ui {
	class textPage;
}

class textPage : public QWidget
{
	Q_OBJECT

public:
    enum formats {
        None, Cpp, Python, Java, CSharp, VB, Html, Css, Javascript, Json, Sql
    };
	textPage(QString,QString,formats,QWidget *parent = Q_NULLPTR);
	textPage(QWidget* parent = Q_NULLPTR);
	~textPage();
    void setUp(QString str, QString file, formats format);
	QString GetText();
	QString GetFile();
    void setFile(QString);
	bool fileSaved = true;
	Ui::textPage* ui;
	QTimer* timer = new QTimer();
    QString currentFile;
    formats Format;
	
private:
	void unSave() { fileSaved = false; };
};

class Highlighter:public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument* parent = 0);
    void setLangFormat(textPage::formats);

protected:
    virtual void highlightBlock(const QString& text);

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
    QTextCharFormat definerFormat;
    QTextCharFormat filesFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};