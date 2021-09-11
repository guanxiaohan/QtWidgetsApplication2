#pragma once

#include <QDialog>
#include "ui_newfiledialog.h"

namespace Ui {
	class newFileDialog;
}

class newFileDialog : public QDialog
{
	Q_OBJECT

public:
	newFileDialog(QWidget *parent = Q_NULLPTR);
	~newFileDialog();

private:
	Ui::newFileDialog *ui;

private slots:
	QString Entry();
};
