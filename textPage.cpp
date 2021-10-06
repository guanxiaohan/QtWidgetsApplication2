#include "textPage.h"

textPage::textPage(QString Text,QString File, formats format,QWidget* parent)
	:QWidget(parent),
	ui(new Ui::textPage)
{
	ui->setupUi(this);
	setUp(Text,File,format);
	setLayout(ui->Layout);
	currentFile = Text;
	Format = format;
}

textPage::textPage(QWidget* parent)
	: QWidget(parent),
	ui(new Ui::textPage)
{
	ui->setupUi(this);
	setUp(tr("Untitled"),tr(""),None);
	setLayout(ui->Layout);
	currentFile = tr("");
	Format = None;
}

textPage::~textPage()
{
	timer->stop();
	delete timer;
	delete ui;
}

void textPage::setUp(QString str,QString file,formats format)
{
	ui->fileLabel->setText(str);
	ui->textEdit->setText(file);
	ui->textEdit->setFont(QFont("宋体",10));
	ui->textEdit->setTabStopDistance(4);
	auto highlighter = new Highlighter(ui->textEdit->document());
	highlighter->setLangFormat(format);
	connect(ui->textEdit, &QTextEdit::textChanged, this, &textPage::unSave);
	fileSaved = true;
}

QString textPage::GetText() {
	return ui->textEdit->toPlainText();
}

QString textPage::GetFile()
{
	return ui->fileLabel->text();
}

void textPage::setFile(QString str)
{
	ui->fileLabel->setText(str);
}

Highlighter::Highlighter(QTextDocument* parent)
	: QSyntaxHighlighter(parent)
{
	
}

void Highlighter::setLangFormat(textPage::formats format)
{
	if (format == textPage::Cpp) {
		HighlightingRule rule;

		keywordFormat.setForeground(QBrush(QColor(qRgb(0, 150, 255))));
		const QString keywordPatterns[] = {
			QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
			QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
			QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"), QStringLiteral("\\bint\\b"),
			QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
			QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
			QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
			QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),QStringLiteral("\\boverride\\b"),
			QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"),
			QStringLiteral("\\bunion\\b"), QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"),
			QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bbool\\b"),
			QStringLiteral("\\breturn\\b"),QStringLiteral("\\bnew\\b"),QStringLiteral("\\bauto\\b"),
			QStringLiteral("\\bdelete\\b")
		};
		for (const QString& keywordPattern : keywordPatterns) {
			rule.pattern = QRegularExpression(keywordPattern);
			rule.format = keywordFormat;
			highlightingRules.append(rule);
		}

		filesFormat.setForeground(QBrush(QColor(qRgb(255, 200, 0))));
		rule.pattern = QRegularExpression("(?<=#include)[ ]+<.*>");
		rule.format = filesFormat;
		highlightingRules.append(rule);

		definerFormat.setForeground(QBrush(QColor(qRgb(120, 120, 120))));
		const QString definerPatterns[] = {
			"#[^ ]*"
		};
		for (const QString& definerPattern : definerPatterns) {
			rule.pattern = QRegularExpression(definerPattern);
			rule.format = definerFormat;
			highlightingRules.append(rule);
		}

		classFormat.setForeground(QBrush(QColor(qRgb(0, 100, 255))));
		rule.pattern = QRegularExpression(QStringLiteral("(?<=class )[A-Za-z0-9_]+"));
		rule.format = classFormat;
		highlightingRules.append(rule);

		functionFormat.setForeground(QBrush(QColor(qRgb(255, 200, 100))));
		rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
		rule.format = functionFormat;
		highlightingRules.append(rule);

		singleLineCommentFormat.setForeground(QBrush(QColor(qRgb(0, 200, 0))));
		rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
		rule.format = singleLineCommentFormat;
		highlightingRules.append(rule);

		multiLineCommentFormat.setForeground(QBrush(QColor(qRgb(0, 200, 0))));

		commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
		commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
	}
}

void Highlighter::highlightBlock(const QString& text)
{
	for (const HighlightingRule& rule : qAsConst(highlightingRules)) {
		QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
		while (matchIterator.hasNext()) {
			QRegularExpressionMatch match = matchIterator.next();
			setFormat(match.capturedStart(), match.capturedLength(), rule.format);
		}
	}
	setCurrentBlockState(0);
	int startIndex = 0;
	if (previousBlockState() != 1)
		startIndex = text.indexOf(commentStartExpression);
	while (startIndex >= 0) {
		QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
		int endIndex = match.capturedStart();
		int commentLength = 0;
		if (endIndex == -1) {
			setCurrentBlockState(1);
			commentLength = text.length() - startIndex;
		}
		else {
			commentLength = endIndex - startIndex
				+ match.capturedLength();
		}
		setFormat(startIndex, commentLength, multiLineCommentFormat);
		startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
	}
}
