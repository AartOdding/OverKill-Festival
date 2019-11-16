#pragma once

#include <memory>

#include <QDir>
#include <QMainWindow>

#include "ui_mainwindow.h"
#include "bodypart.h"
#include "imagemanager.h"


extern QDir workingDirectory;
extern QDir bodyPartsDirectory;
extern QDir characterDirectory;
extern QDir templateDirectory;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();


public slots:

    void select_working_directory();

    void load_working_directory(const QDir& directory);


    void body_part_clicked();

    void randomize_clicked();

    void reset_clicked();

signals:

    void bodyPartSelected(BodyParts bodyPart, ListImage* image);

private:

    QPalette defaultPalette;
    QPalette selectedPalette;

    std::unique_ptr<Ui::MainWindow> ui;

};

