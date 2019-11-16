#include "mainwindow.h"
#include "selectiondialog.h"
#include "bodypart.h"

#include <QtMath>
#include <QString>
#include <QToolButton>
#include <QPushButton>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QColorDialog>
#include <QTimer>

#include <iostream>

#include "imagemanager.h"
#include "previewwidget.h"


QDir workingDirectory;
QDir bodyPartsDirectory;
QDir characterDirectory;
QDir templateDirectory;


MainWindow::MainWindow()
{
    ui = std::make_unique<Ui::MainWindow>();
    ui->setupUi(this);

    defaultPalette = ui->chest->palette();
    selectedPalette = defaultPalette;
    selectedPalette.setColor(QPalette::Button, QColor(150, 255, 150, 150));

    connect(this, &MainWindow::bodyPartSelected, ui->previewWidget, &PreviewWidget::onBodyPartSelected);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset_clicked);
    connect(ui->randomizeButton, &QPushButton::clicked, this, &MainWindow::randomize_clicked);
    connect(ui->saveButton, &QPushButton::clicked, ui->previewWidget, &PreviewWidget::save);
    connect(ui->previewWidget, &PreviewWidget::resetRequest, this, &MainWindow::reset_clicked);

    QTimer::singleShot(500, std::bind(&MainWindow::select_working_directory, this));
}


void MainWindow::select_working_directory()
{
    QMessageBox msg;
    msg.setText("Please select the working directory to store and load characters.");
    msg.exec();

    while (true)
    {
        auto directory = QDir(QFileDialog::getExistingDirectory());
        auto directory_info = QFileInfo(directory.path());

        if (directory.exists() && directory_info.isReadable() && directory_info.isWritable())
        {
            load_working_directory(directory);
            return;
        }

        QMessageBox msg;
        msg.setText("Please select a directory with read write access.");
        msg.exec();
    }
}



void MainWindow::load_working_directory(const QDir& directory)
{
    workingDirectory = directory;
    bodyPartsDirectory = directory;
    characterDirectory = directory;
    templateDirectory = directory;

    if (!bodyPartsDirectory.cd("body_parts"))
    {
        bodyPartsDirectory.mkdir("body_parts");
        bodyPartsDirectory.cd("body_parts");
    }

    if (!characterDirectory.cd("Characters"))
    {
        characterDirectory.mkdir("Characters");
        characterDirectory.cd("Characters");
    }

    if (!templateDirectory.cd("drawing_templates"))
    {
        characterDirectory.mkdir("drawing_templates");
        characterDirectory.cd("drawing_templates");
    }

    if (!templateDirectory.cd("template"))
    {
        characterDirectory.mkdir("template");
        characterDirectory.cd("template");
    }

    ImageManager::get()->loadTemplates(templateDirectory);

    for (const auto& name : bodyPartNames)
    {
        auto subDirectory = bodyPartsDirectory;

        if (!subDirectory.cd(name))
        {
            subDirectory.mkdir(name);
            subDirectory.cd(name);
        }

        subDirectory.setNameFilters({ "*.png" });
        auto entries = subDirectory.entryList();

        for (const auto& entry : entries)
        {
            auto path = subDirectory.path() + "/" + entry;
            ImageManager::get()->addItem(QDir(path), bodyPartFromName(name));
        }
    }
}


void MainWindow::body_part_clicked()
{
    auto button = dynamic_cast<QPushButton*>(sender());
    auto bodyPart = bodyPartFromName(button->objectName());

    if (button)
    {
        ListImage * result = nullptr;
        SelectionDialog dialog{ result, bodyPart };

        auto success = dialog.exec();

        if (success && result)
        {
            button->setPalette(selectedPalette);
            emit bodyPartSelected(bodyPart, result);
        }
    }
}


void MainWindow::randomize_clicked()
{
    auto pvw = ui->previewWidget;

    pvw->randomize();

    ui->head->setPalette(pvw->contains(BodyParts::Head) ? selectedPalette : defaultPalette);
    ui->chest->setPalette(pvw->contains(BodyParts::Chest) ? selectedPalette : defaultPalette);
    ui->arm_left->setPalette(pvw->contains(BodyParts::ArmLeft) ? selectedPalette : defaultPalette);
    ui->arm_right->setPalette(pvw->contains(BodyParts::ArmRight) ? selectedPalette : defaultPalette);
    ui->forearm_left->setPalette(pvw->contains(BodyParts::ForeArmLeft) ? selectedPalette : defaultPalette);
    ui->forearm_right->setPalette(pvw->contains(BodyParts::ForeArmRight) ? selectedPalette : defaultPalette);
    ui->hand_left->setPalette(pvw->contains(BodyParts::HandLeft) ? selectedPalette : defaultPalette);
    ui->hand_right->setPalette(pvw->contains(BodyParts::HandRight) ? selectedPalette : defaultPalette);
    ui->thigh_left->setPalette(pvw->contains(BodyParts::ThighLeft) ? selectedPalette : defaultPalette);
    ui->thigh_right->setPalette(pvw->contains(BodyParts::ThighRight) ? selectedPalette : defaultPalette);
    ui->shin_left->setPalette(pvw->contains(BodyParts::ShinLeft) ? selectedPalette : defaultPalette);
    ui->shin_right->setPalette(pvw->contains(BodyParts::ShinRight) ? selectedPalette : defaultPalette);
}


void MainWindow::reset_clicked()
{
    ui->previewWidget->reset();

    ui->head->setPalette(defaultPalette);
    ui->chest->setPalette(defaultPalette);
    ui->arm_left->setPalette(defaultPalette);
    ui->arm_right->setPalette(defaultPalette);
    ui->forearm_left->setPalette(defaultPalette);
    ui->forearm_right->setPalette(defaultPalette);
    ui->hand_left->setPalette(defaultPalette);
    ui->hand_right->setPalette(defaultPalette);
    ui->thigh_left->setPalette(defaultPalette);
    ui->thigh_right->setPalette(defaultPalette);
    ui->shin_left->setPalette(defaultPalette);
    ui->shin_right->setPalette(defaultPalette);
}
