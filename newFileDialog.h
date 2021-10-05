#pragma once

#include <QDialog>
#include <QList>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <Qt>

namespace Ui { class NewFileDialog; };

class NewFileDialog : public QDialog
{
	Q_OBJECT

public:
	NewFileDialog(QList<QString> options, QWidget* parent = Q_NULLPTR);
	~NewFileDialog();
	inline QString getResult() { return Result; };

private:
	Ui::NewFileDialog *ui;
	QString Result;
	void accept();
	void done();
	int Confirm();
	void Cancel();

private slots:
	void SetDir();
	
};
