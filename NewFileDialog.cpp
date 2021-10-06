#include "NewFileDialog.h"
#include "ui_NewFileDialog.h"

NewFileDialog::NewFileDialog(QList<QString> options, QWidget *parent)
	: QDialog(parent), ui(new Ui::NewFileDialog())
{
	ui->setupUi(this);
	setLayout(ui->gridLayout);

	connect(ui->confirmButton, &QPushButton::clicked, this, &NewFileDialog::accept);
	connect(ui->cancelButton, &QPushButton::clicked, this, &NewFileDialog::done);
	connect(ui->setDirButton, &QPushButton::clicked, this, &NewFileDialog::SetDir);

	for (auto i : options) {
		ui->listWidget->addItem(i);
	}
}

NewFileDialog::~NewFileDialog()
{
	delete ui;
}

int NewFileDialog::Confirm() 
{
	if (ui->listWidget->currentItem() != nullptr &&
		!ui->fileNameLineEdit->text().isEmpty() &&
		!ui->dirLineEdit->text().isEmpty()) 
	{
		if (QDir(ui->dirLineEdit->text()).exists()) {
			Result =
				QString::number(ui->listWidget->currentRow()) +
				";;" +
				ui->dirLineEdit->text() + 
				";;" +
				ui->fileNameLineEdit->text();
			return 1;
		}
		else {
			QMessageBox::information(this, "Information", "File dir is not exist.");
		}
	}
	else {
		QMessageBox::information(this, "Information", "You didn't enter all the informations of file.");
	}
	return 0;
}

void NewFileDialog::accept()
{
	if (Confirm() == 1) {
		QDialog::accept();
	};
}

void NewFileDialog::done()
{
	Cancel();
	QDialog::reject();
}

void NewFileDialog::Cancel()
{
	Result = "";
}

void NewFileDialog::SetDir() 
{
	ui->dirLineEdit->setText(QFileDialog::getExistingDirectory(this, "File in:"));
}