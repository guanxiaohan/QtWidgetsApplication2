#include "textPage.h"

textPage::textPage(QString Text,QString File, QWidget* parent)
	:QWidget(parent),
	ui(new Ui::textPage)
{
	ui->setupUi(this);
	setUp(Text,File);
	setLayout(ui->Layout);
	currentFile = File;
}

textPage::textPage(QWidget* parent)
	: QWidget(parent),
	ui(new Ui::textPage)
{
	ui->setupUi(this);
	setUp(tr("Untitled"),tr(""));
	setLayout(ui->Layout);
	currentFile = tr("");
}

textPage::~textPage()
{
	timer->stop();
	delete timer;
	delete ui;
}

void textPage::setUp(QString str,QString file)
{
	ui->fileLabel->setText(str);
	ui->textEdit->setText(file);
	timer->setInterval(5000);
	connect(timer, &QTimer::timeout, this, &textPage::colorText);
	connect(ui->textEdit, &QTextEdit::textChanged, this, &textPage::unSave);
	fileSaved = true;
	timer->start();
}

QString textPage::GetText() {
	return ui->textEdit->toPlainText();
}

QString textPage::GetFile()
{
	return ui->fileLabel->text();
}

void textPage::colorText()
{
	QString to_find_text = ui->textEdit->toPlainText();
	to_find_text.replace("\n","<pre>\n</pre>");

	to_find_text.replace("new", "<b>new</b>");
	ui->textEdit->setHtml(to_find_text);
	ui->textEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
}
