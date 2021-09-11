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
	delete ui;
}

void textPage::setUp(QString str,QString file)
{
	ui->fileLabel->setText(str);
	ui->textEdit->setText(file);
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
