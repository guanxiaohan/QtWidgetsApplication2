#pragma once

#include <QDockWidget>
namespace Ui {
	class powerShell;
};

class powerShell : public QDockWidget
{
	Q_OBJECT

public:
	powerShell(QWidget *parent = Q_NULLPTR);
	~powerShell();

private:
	Ui::powerShell *ui;
};
