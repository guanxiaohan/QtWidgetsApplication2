#include "NewFileDialog.h"
#include "ui_NewFileDialog.h"

NewFileDialog::NewFileDialog(QString& result, QList<QString> options, QWidget *parent)
	: QDialog(parent), Result(result)
{
	ui = new Ui::NewFileDialog();
	ui->setupUi(this);
	setLayout(ui->gridLayout);

	connect(ui->confirmButton, &QPushButton::clicked, this, &NewFileDialog::Confirm);
	connect(ui->cancelButton, &QPushButton::clicked, this, &NewFileDialog::Cancel);

	for (auto i : options) {
		ui->listWidget->addItem(i);
	}

	show();
}

NewFileDialog::~NewFileDialog()
{
	delete ui;
}

QList<QString> NewFileDialog::getNewFile(QList<QString> options)
{
	QString res;
	auto dialog = NewFileDialog(res, options);
	dialog.exec();

	if (!res.isEmpty()) {
		auto args = res.split("//");
		QList<QString> list;
		list.append(args[0]);
		list.append(args[1]);
		list.append(args[2]);
		return list;
	}
}

void NewFileDialog::Confirm() 
{
	if (ui->listWidget->currentItem() != nullptr &&
		!ui->fileNameLineEdit->text().isEmpty() &&
		!ui->dirLineEdit->text().isEmpty()) 
	{
		if (QDir(ui->dirLineEdit->text()).exists()) {
			Result =
				QString::number(ui->listWidget->currentRow()) +
				"//" +
				ui->fileNameLineEdit->text() +
				"//" +
				ui->dirLineEdit->text();
			setHidden(true);
		}
		else {
			QMessageBox::information(this, "Information", "File dir is not exist.");
		}
	}
	else {
		QMessageBox::information(this, "Information", "You didn't enter all the informations of file.");
	}
}

void NewFileDialog::Cancel()
{
	Result = "";
	setHidden(true);
}

void NewFileDialog::SetDir() 
{
	ui->dirLineEdit->setText(QFileDialog::getExistingDirectory(this, "File in:"));
}