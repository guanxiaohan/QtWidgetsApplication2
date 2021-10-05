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
	NewFileDialog(QString result, QList<QString> options, QWidget* parent = Q_NULLPTR);
	~NewFileDialog();
	static QString getNewFile(QList<QString> options);
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
