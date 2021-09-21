#pragma once

#include <QWidget>
#include <QProcess>
#include <QPushButton>

namespace Ui {
	class powerShell;
};

class powerShell : public QWidget
{
	Q_OBJECT

public:
	powerShell(QWidget *parent = Q_NULLPTR);
	~powerShell();

private:
	Ui::powerShell *ui;
	QProcess mProcess;

private slots:
	void slot_readdata();
	void slot_cmderror();
	void slot_cmdfinished();
	void on_lineEdit_editingFinished();
};
