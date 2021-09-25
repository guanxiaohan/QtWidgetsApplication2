#pragma once
//ssssss
#include <QWidget>
namespace Ui {
	class startWizard; 
};

class startWizard : public QWidget
{
	Q_OBJECT

public:
	startWizard(QWidget *parent = Q_NULLPTR);
	~startWizard();

private:
	Ui::startWizard *ui;
};
