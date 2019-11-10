/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *actionLoad_Project;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSettings;
    QAction *workingDirectoryAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFrame *bodypart_buttons;
    QPushButton *chest;
    QPushButton *thigh_left;
    QPushButton *shin_left;
    QPushButton *thigh_right;
    QPushButton *hand_left;
    QPushButton *arm_left;
    QPushButton *forearm_left;
    QPushButton *head;
    QPushButton *shin_right;
    QPushButton *forearm_right;
    QPushButton *arm_right;
    QPushButton *hand_right;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *field_name;
    QLabel *label_author;
    QLineEdit *field_author;
    QPushButton *submit_button;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1168, 637);
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        actionLoad_Project = new QAction(MainWindow);
        actionLoad_Project->setObjectName(QString::fromUtf8("actionLoad_Project"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        workingDirectoryAction = new QAction(MainWindow);
        workingDirectoryAction->setObjectName(QString::fromUtf8("workingDirectoryAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        bodypart_buttons = new QFrame(widget_2);
        bodypart_buttons->setObjectName(QString::fromUtf8("bodypart_buttons"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bodypart_buttons->sizePolicy().hasHeightForWidth());
        bodypart_buttons->setSizePolicy(sizePolicy);
        bodypart_buttons->setMinimumSize(QSize(520, 460));
        bodypart_buttons->setMaximumSize(QSize(520, 10000));
        bodypart_buttons->setFrameShape(QFrame::NoFrame);
        bodypart_buttons->setFrameShadow(QFrame::Raised);
        chest = new QPushButton(bodypart_buttons);
        chest->setObjectName(QString::fromUtf8("chest"));
        chest->setGeometry(QRect(200, 110, 91, 151));
        chest->setCheckable(false);
        chest->setChecked(false);
        chest->setAutoExclusive(false);
        thigh_left = new QPushButton(bodypart_buttons);
        thigh_left->setObjectName(QString::fromUtf8("thigh_left"));
        thigh_left->setGeometry(QRect(260, 270, 31, 81));
        thigh_left->setCheckable(false);
        thigh_left->setAutoExclusive(false);
        shin_left = new QPushButton(bodypart_buttons);
        shin_left->setObjectName(QString::fromUtf8("shin_left"));
        shin_left->setGeometry(QRect(260, 360, 31, 81));
        shin_left->setCheckable(false);
        shin_left->setAutoExclusive(false);
        thigh_right = new QPushButton(bodypart_buttons);
        thigh_right->setObjectName(QString::fromUtf8("thigh_right"));
        thigh_right->setGeometry(QRect(200, 270, 31, 81));
        thigh_right->setCheckable(false);
        thigh_right->setAutoExclusive(false);
        hand_left = new QPushButton(bodypart_buttons);
        hand_left->setObjectName(QString::fromUtf8("hand_left"));
        hand_left->setGeometry(QRect(440, 110, 31, 31));
        hand_left->setCheckable(false);
        hand_left->setAutoExclusive(false);
        arm_left = new QPushButton(bodypart_buttons);
        arm_left->setObjectName(QString::fromUtf8("arm_left"));
        arm_left->setGeometry(QRect(300, 110, 61, 31));
        arm_left->setCheckable(false);
        arm_left->setAutoExclusive(false);
        forearm_left = new QPushButton(bodypart_buttons);
        forearm_left->setObjectName(QString::fromUtf8("forearm_left"));
        forearm_left->setGeometry(QRect(370, 110, 61, 31));
        forearm_left->setCheckable(false);
        forearm_left->setAutoExclusive(false);
        head = new QPushButton(bodypart_buttons);
        head->setObjectName(QString::fromUtf8("head"));
        head->setGeometry(QRect(220, 30, 51, 61));
        head->setCheckable(false);
        head->setAutoExclusive(false);
        shin_right = new QPushButton(bodypart_buttons);
        shin_right->setObjectName(QString::fromUtf8("shin_right"));
        shin_right->setGeometry(QRect(200, 360, 31, 81));
        shin_right->setCheckable(false);
        shin_right->setAutoExclusive(false);
        forearm_right = new QPushButton(bodypart_buttons);
        forearm_right->setObjectName(QString::fromUtf8("forearm_right"));
        forearm_right->setGeometry(QRect(70, 110, 51, 31));
        forearm_right->setCheckable(false);
        forearm_right->setAutoExclusive(false);
        arm_right = new QPushButton(bodypart_buttons);
        arm_right->setObjectName(QString::fromUtf8("arm_right"));
        arm_right->setGeometry(QRect(130, 110, 61, 31));
        arm_right->setCheckable(false);
        arm_right->setAutoExclusive(false);
        hand_right = new QPushButton(bodypart_buttons);
        hand_right->setObjectName(QString::fromUtf8("hand_right"));
        hand_right->setGeometry(QRect(30, 110, 31, 31));
        hand_right->setCheckable(false);
        hand_right->setAutoExclusive(false);

        verticalLayout->addWidget(bodypart_buttons);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMaximumSize(QSize(440, 16777215));
        formLayout = new QFormLayout(widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_name = new QLabel(widget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_name);

        field_name = new QLineEdit(widget);
        field_name->setObjectName(QString::fromUtf8("field_name"));

        formLayout->setWidget(2, QFormLayout::FieldRole, field_name);

        label_author = new QLabel(widget);
        label_author->setObjectName(QString::fromUtf8("label_author"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_author);

        field_author = new QLineEdit(widget);
        field_author->setObjectName(QString::fromUtf8("field_author"));

        formLayout->setWidget(5, QFormLayout::FieldRole, field_author);

        submit_button = new QPushButton(widget);
        submit_button->setObjectName(QString::fromUtf8("submit_button"));

        formLayout->setWidget(6, QFormLayout::FieldRole, submit_button);


        verticalLayout->addWidget(widget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(widget_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(submit_button, SIGNAL(clicked()), MainWindow, SLOT(finish_and_save_clicked()));
        QObject::connect(chest, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(head, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(arm_left, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(forearm_left, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(hand_left, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(arm_right, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(forearm_right, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(hand_right, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(thigh_right, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(thigh_left, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(shin_right, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));
        QObject::connect(shin_left, SIGNAL(clicked()), MainWindow, SLOT(body_part_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Character Creation", nullptr));
        actionNew_Project->setText(QApplication::translate("MainWindow", "New Project", nullptr));
        actionLoad_Project->setText(QApplication::translate("MainWindow", "Open Project", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionClose->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        workingDirectoryAction->setText(QApplication::translate("MainWindow", "Working Directory", nullptr));
#ifndef QT_NO_TOOLTIP
        workingDirectoryAction->setToolTip(QApplication::translate("MainWindow", "Change the Working Directory", nullptr));
#endif // QT_NO_TOOLTIP
        chest->setText(QString());
        thigh_left->setText(QString());
        shin_left->setText(QString());
        thigh_right->setText(QString());
        hand_left->setText(QString());
        arm_left->setText(QString());
        forearm_left->setText(QString());
        head->setText(QString());
        shin_right->setText(QString());
        forearm_right->setText(QString());
        arm_right->setText(QString());
        hand_right->setText(QString());
        label_name->setText(QApplication::translate("MainWindow", "Character Name:", nullptr));
        label_author->setText(QApplication::translate("MainWindow", "Author Name:", nullptr));
        submit_button->setText(QApplication::translate("MainWindow", "Finish and save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
