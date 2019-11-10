#pragma once

#include <memory>

#include <QDir>
#include <QMainWindow>

#include "ui_mainwindow.h"



extern QDir workingDirectory;
extern QDir bodyPartsDirectory;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();

    ~MainWindow();


public slots:

    void select_working_directory();

    void load_working_directory();


    void body_part_clicked();

    void finish_and_save_clicked();


private:

    std::unique_ptr<Ui::MainWindow> ui;

};

