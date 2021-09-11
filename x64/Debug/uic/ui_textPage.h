/********************************************************************************
** Form generated from reading UI file 'textPage.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/
////
#ifndef UI_TEXTPAGE_H
#define UI_TEXTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textPage
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *Layout;
    QLabel *RCLabel;
    QLabel *fileLabel;
    QTextEdit *textEdit;

    void setupUi(QWidget *textPage)
    {
        if (textPage->objectName().isEmpty())
            textPage->setObjectName(QString::fromUtf8("textPage"));
        textPage->resize(400, 300);
        gridLayoutWidget = new QWidget(textPage);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 401, 301));
        Layout = new QGridLayout(gridLayoutWidget);
        Layout->setSpacing(6);
        Layout->setContentsMargins(11, 11, 11, 11);
        Layout->setObjectName(QString::fromUtf8("Layout"));
        Layout->setContentsMargins(3, 3, 3, 3);
        RCLabel = new QLabel(gridLayoutWidget);
        RCLabel->setObjectName(QString::fromUtf8("RCLabel"));
        RCLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Layout->addWidget(RCLabel, 1, 1, 1, 1);

        fileLabel = new QLabel(gridLayoutWidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        fileLabel->setMinimumSize(QSize(300, 0));

        Layout->addWidget(fileLabel, 1, 0, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        Layout->addWidget(textEdit, 0, 0, 1, 2);


        retranslateUi(textPage);

        QMetaObject::connectSlotsByName(textPage);
    } // setupUi

    void retranslateUi(QWidget *textPage)
    {
        textPage->setWindowTitle(QCoreApplication::translate("textPage", "textPage", nullptr));
        RCLabel->setText(QCoreApplication::translate("textPage", "*,*", nullptr));
        fileLabel->setText(QCoreApplication::translate("textPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textPage: public Ui_textPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTPAGE_H
