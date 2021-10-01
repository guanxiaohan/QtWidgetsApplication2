#include "powerShell.h"
#include "ui_powerShell.h"

powerShell::powerShell(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::powerShell)
{
	ui->setupUi(this);

	ui->textEdit->clear();
	mProcess.setProcessChannelMode(QProcess::MergedChannels);

	//connect...
	connect(&mProcess, SIGNAL(readyRead()), this, SLOT(slot_readdata()));
	connect(&mProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(slot_readdata()));
	connect(&mProcess, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(slot_cmderror()));
	connect(&mProcess, SIGNAL(finished(int)), this, SLOT(slot_cmdfinished()));
	connect(ui->toolButton_4, &QPushButton::clicked, this, &powerShell::on_lineEdit_editingFinished);

	//异步启动
	setLayout(ui->gridLayout);
	mProcess.start("powershell");
	if (!mProcess.waitForStarted()) {
		qDebug() << "process error " << QString::fromLocal8Bit(mProcess.readAllStandardError());
	}
	else {
		qDebug() << "process read " << QString::fromLocal8Bit(mProcess.readAllStandardOutput());
	}

}

powerShell::~powerShell()
{
	delete ui;
}

void powerShell::slot_readdata() {

	QByteArray mreaddata = mProcess.readAll();
	ui->textEdit->setText(ui->textEdit->toPlainText() + QString::fromLocal8Bit(mreaddata));
	ui->textEdit->update();

	qDebug() << "Success to read:" << QString::fromLocal8Bit(mreaddata) << "\n";
}
void powerShell::slot_cmdfinished() {
	/* 接收数据 */
	int flag = mProcess.exitCode();

	/* 信息输出 */
	qDebug() << "Cmd finish:" << flag << "\n";
}

void powerShell::slot_cmderror() {
	int errorcode = mProcess.exitCode();

	QString error = mProcess.errorString();

	ui->textEdit->append(QString("Process error coed:%1").arg(errorcode));
	ui->textEdit->append(error);

	qDebug() << "Success to read cmderror:" << error << "\n";
}

void powerShell::on_lineEdit_editingFinished()
{
	qDebug() << "line edit" << ui->lineEdit->text();
	char* ch;
	QByteArray ba = (ui->lineEdit->text() + '\r' + '\n').toLatin1();
	ch = ba.data();
	mProcess.write(ch);
	mProcess.waitForBytesWritten(2000);
}
