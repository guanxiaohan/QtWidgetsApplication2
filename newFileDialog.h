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
	NewFileDialog(QString& result, QList<QString> options, QWidget* parent = Q_NULLPTR);
	~NewFileDialog();
	static QList<QString> getNewFile(QList<QString> options);
	QString Result;

private:
	Ui::NewFileDialog *ui;

private slots:
	void Confirm();
	void Cancel();
	void SetDir();
};
