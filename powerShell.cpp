#include "powerShell.h"
#include "ui_powerShell.h"

powerShell::powerShell(QWidget *parent)
	: QDockWidget(parent),
	ui(new Ui::powerShell)
{
	ui->setupUi(this);

	ui->textEdit->clear();
	QProcess PowerShell(this);
	PowerShell.setProgram("powershell");
	QStringList argument;
	argument << "/c" << ui->lineEdit->text();
	PowerShell.setArguments(argument);
	PowerShell.start();
	PowerShell.waitForStarted(); //等待程序启动
	PowerShell.waitForFinished();//等待程序关闭
	QString temp = QString::fromLocal8Bit(process.readAllStandardOutput()); //程序输出信息
	ui->textEdit->setText(temp);
}

powerShell::~powerShell()
{
	delete ui;
}
