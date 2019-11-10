/********************************************************************************
** Form generated from reading UI file 'drawingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWINGDIALOG_H
#define UI_DRAWINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QToolButton *ZoomInButton;
    QToolButton *ZoomOutButton;
    QSpacerItem *verticalSpacer_2;
    QToolButton *DraggerButton;
    QToolButton *EraserButton;
    QToolButton *PencilButton;
    QSpacerItem *verticalSpacer_3;
    QToolButton *ColorPickerButton;
    QSpacerItem *verticalSpacer_4;
    QSlider *PenWidthSlider;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *graphicsView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DrawingDialog)
    {
        if (DrawingDialog->objectName().isEmpty())
            DrawingDialog->setObjectName(QString::fromUtf8("DrawingDialog"));
        DrawingDialog->resize(960, 720);
        verticalLayout = new QVBoxLayout(DrawingDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, -1);
        widget = new QWidget(DrawingDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(20, 0));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        ZoomInButton = new QToolButton(widget_6);
        ZoomInButton->setObjectName(QString::fromUtf8("ZoomInButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        ZoomInButton->setIcon(icon);
        ZoomInButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(ZoomInButton);

        ZoomOutButton = new QToolButton(widget_6);
        ZoomOutButton->setObjectName(QString::fromUtf8("ZoomOutButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        ZoomOutButton->setIcon(icon1);
        ZoomOutButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(ZoomOutButton);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_2);

        DraggerButton = new QToolButton(widget_6);
        DraggerButton->setObjectName(QString::fromUtf8("DraggerButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/drag.png"), QSize(), QIcon::Normal, QIcon::Off);
        DraggerButton->setIcon(icon2);
        DraggerButton->setIconSize(QSize(40, 40));
        DraggerButton->setCheckable(true);
        DraggerButton->setAutoExclusive(true);

        verticalLayout_3->addWidget(DraggerButton);

        EraserButton = new QToolButton(widget_6);
        EraserButton->setObjectName(QString::fromUtf8("EraserButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        EraserButton->setIcon(icon3);
        EraserButton->setIconSize(QSize(40, 40));
        EraserButton->setCheckable(true);
        EraserButton->setAutoRepeat(false);
        EraserButton->setAutoExclusive(true);

        verticalLayout_3->addWidget(EraserButton);

        PencilButton = new QToolButton(widget_6);
        PencilButton->setObjectName(QString::fromUtf8("PencilButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/crayon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PencilButton->setIcon(icon4);
        PencilButton->setIconSize(QSize(40, 40));
        PencilButton->setCheckable(true);
        PencilButton->setChecked(true);
        PencilButton->setAutoExclusive(true);

        verticalLayout_3->addWidget(PencilButton);

        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_3);

        ColorPickerButton = new QToolButton(widget_6);
        ColorPickerButton->setObjectName(QString::fromUtf8("ColorPickerButton"));
        ColorPickerButton->setAutoFillBackground(true);
        ColorPickerButton->setStyleSheet(QString::fromUtf8(""));
        ColorPickerButton->setIconSize(QSize(40, 40));
#ifndef QT_NO_SHORTCUT
        ColorPickerButton->setShortcut(QString::fromUtf8(""));
#endif // QT_NO_SHORTCUT
        ColorPickerButton->setCheckable(true);
        ColorPickerButton->setChecked(true);

        verticalLayout_3->addWidget(ColorPickerButton);

        verticalSpacer_4 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        PenWidthSlider = new QSlider(widget_6);
        PenWidthSlider->setObjectName(QString::fromUtf8("PenWidthSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PenWidthSlider->sizePolicy().hasHeightForWidth());
        PenWidthSlider->setSizePolicy(sizePolicy1);
        PenWidthSlider->setMinimumSize(QSize(0, 120));
        PenWidthSlider->setMaximumSize(QSize(200, 10000));
        PenWidthSlider->setMinimum(1);
        PenWidthSlider->setMaximum(100);
        PenWidthSlider->setPageStep(1);
        PenWidthSlider->setSliderPosition(1);
        PenWidthSlider->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(PenWidthSlider);

        spinBox = new QSpinBox(widget_6);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFrame(false);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMinimum(1);
        spinBox->setMaximum(10000);

        verticalLayout_3->addWidget(spinBox);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);


        horizontalLayout_2->addWidget(widget_6);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(widget_2);

        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setAcceptDrops(false);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSceneRect(QRectF(-700, -700, 1400, 1400));

        horizontalLayout->addWidget(graphicsView);


        verticalLayout->addWidget(widget);

        buttonBox = new QDialogButtonBox(DrawingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DrawingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DrawingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DrawingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DrawingDialog);
    } // setupUi

    void retranslateUi(QDialog *DrawingDialog)
    {
        DrawingDialog->setWindowTitle(QApplication::translate("DrawingDialog", "Editor", nullptr));
        ZoomInButton->setText(QApplication::translate("DrawingDialog", "...", nullptr));
        ZoomOutButton->setText(QApplication::translate("DrawingDialog", "...", nullptr));
        DraggerButton->setText(QApplication::translate("DrawingDialog", "...", nullptr));
        EraserButton->setText(QApplication::translate("DrawingDialog", "...", nullptr));
        PencilButton->setText(QApplication::translate("DrawingDialog", "...", nullptr));
        ColorPickerButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DrawingDialog: public Ui_DrawingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGDIALOG_H
