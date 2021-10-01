#pragma once
#include <QDir>
#include <QFile>
#include <QList>
#include <QFileInfo>
#include <QTextStream>

class Projecter:public QObject
{
private:
	QString ProjectName;
	QString ProjectType;
	QList<QString> ProjectFiles;
};

