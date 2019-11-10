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



QDir workingDirectory;
QDir bodyPartsDirectory;


MainWindow::MainWindow()
{
    ui = std::make_unique<Ui::MainWindow>();
    ui->setupUi(this);
    QTimer::singleShot(500, std::bind(&MainWindow::select_working_directory, this));
/*
    ui->observer_view->setScene(scene);
    ui->observer_view->setInteractive(false);
    ui->observer_view->scale(0.3, 0.3);
    ui->observer_view->setAlignment(Qt::AlignCenter);
    ui->observer_view->setDragMode(QGraphicsView::ScrollHandDrag);
*/
    /*
    limbs["head"] = new Limb("head");
    limbs["chest"] = new Limb("chest");
    limbs["arm_left"] = new Limb("arm_left");
    limbs["arm_right"] = new Limb("arm_right");
    limbs["forearm_left"] = new Limb("forearm_left");
    limbs["forearm_right"] = new Limb("forearm_right");
    limbs["hand_left"] = new Limb("hand_left");
    limbs["hand_right"] = new Limb("hand_right");
    limbs["thigh_left"] = new Limb("thigh_left");
    limbs["thigh_right"] = new Limb("thigh_right");
    limbs["shin_left"] = new Limb("shin_left");
    limbs["shin_right"] = new Limb("shin_right");

    for (auto& [k, v] : limbs)
    {
        //scene->addItem(v);
    }
*/
    /*
    // Chest stays in place
    limbs["head"]->setY(-300);

    limbs["arm_left"]->setPos(160, -160);
    limbs["arm_right"]->setPos(-160, -160);
    limbs["forearm_left"]->setPos(320, -160);
    limbs["forearm_right"]->setPos(-320, -160);

    limbs["hand_left"]->setPos(420, -160);
    limbs["hand_right"]->setPos(-420, -160);

    limbs["thigh_left"]->setPos(60, 270);
    limbs["thigh_right"]->setPos(-60, 270);

    limbs["shin_left"]->setPos(60, 460);
    limbs["shin_right"]->setPos(-60, 460);

    //selected_tool = ui->draw_tool;
    selected_body_part = ui->chest;

    color = QColor(0, 0, 0);
    mirroring = false;
    //pen_width = ui->pen_width->value();
    tool = Tool::Pen;
    */
    //scene->setSceneRect(scene->sceneRect().marginsAdded({10, 10, 10, 10}));
}


MainWindow::~MainWindow()
{
    //delete ui;
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
            std::cout << "Changed output directory to: " << directory.path().toStdString() << "\n";
            workingDirectory = directory;

            load_working_directory();
            return;
        }

        QMessageBox msg;
        msg.setText("Please select a directory with read write access.");
        msg.exec();
    }
}



void MainWindow::load_working_directory()
{
    auto directory = workingDirectory;

    if (!directory.cd("body_parts"))
    {
        directory.mkdir("body_parts");
        directory.cd("body_parts");
    }

    bodyPartsDirectory = directory;

    for (const auto& name : bodyPartNames)
    {
        auto subDirectory = directory;

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
            std::cout << path.toStdString() << "\n";
        }
    }
}


void MainWindow::finish_and_save_clicked()
{
    auto author = ui->field_author->text().simplified().replace( " ", "" );
    auto character = ui->field_name->text().simplified().replace( " ", "" );
    auto folder = author + "-" + character;

    if (workingDirectory.mkdir(folder))
    {
        if (author.size() > 0 && character.size() > 0)
        {
            auto dir = workingDirectory;
            dir.cd(folder);
            std::cout << "saved at: " << dir.absolutePath().toStdString() << "\n";


            return;
        }
    }

    QMessageBox msg;
    msg.setText("Please fill in you and your character's names!");
    msg.exec();
}


void MainWindow::body_part_clicked()
{
    auto button = dynamic_cast<QPushButton*>(sender());

    if (button)
    {
        ListImage * result = nullptr;
        SelectionDialog dialog{ result, bodyPartFromName(button->objectName()) };

        auto success = dialog.exec();

        if (success && result)
        {
            std::cout << "limb was selected" << std::endl;
        }
    }
}
