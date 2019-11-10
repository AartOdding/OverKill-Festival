/********************************************************************************
** Form generated from reading UI file 'selectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIONDIALOG_H
#define UI_SELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "selectwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SelectionDialog
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    SelectWidget *selectWidget;
    QVBoxLayout *vboxLayout;
    QWidget *buttonBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *newButton;
    QPushButton *editButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelectionDialog)
    {
        if (SelectionDialog->objectName().isEmpty())
            SelectionDialog->setObjectName(QString::fromUtf8("SelectionDialog"));
        SelectionDialog->resize(501, 558);
        gridLayout = new QGridLayout(SelectionDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 4, 0, 2);
        scrollArea = new QScrollArea(SelectionDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        selectWidget = new SelectWidget();
        selectWidget->setObjectName(QString::fromUtf8("selectWidget"));
        selectWidget->setGeometry(QRect(0, 0, 487, 1500));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectWidget->sizePolicy().hasHeightForWidth());
        selectWidget->setSizePolicy(sizePolicy);
        selectWidget->setMinimumSize(QSize(450, 1500));
        vboxLayout = new QVBoxLayout(selectWidget);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(selectWidget);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        buttonBar = new QWidget(SelectionDialog);
        buttonBar->setObjectName(QString::fromUtf8("buttonBar"));
        horizontalLayout = new QHBoxLayout(buttonBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        newButton = new QPushButton(buttonBar);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        horizontalLayout->addWidget(newButton);

        editButton = new QPushButton(buttonBar);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout->addWidget(editButton);

        buttonBox = new QDialogButtonBox(buttonBar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addWidget(buttonBar, 1, 0, 1, 1);


        retranslateUi(SelectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectionDialog)
    {
        SelectionDialog->setWindowTitle(QApplication::translate("SelectionDialog", "Select", nullptr));
        newButton->setText(QApplication::translate("SelectionDialog", "New", nullptr));
        editButton->setText(QApplication::translate("SelectionDialog", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectionDialog: public Ui_SelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIONDIALOG_H
