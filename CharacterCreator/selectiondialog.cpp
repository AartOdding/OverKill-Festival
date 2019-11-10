#include "selectiondialog.h"
#include "drawingdialog.h"
#include "mainwindow.h"
#include "imagemanager.h"

#include <iostream>
#include <functional>

#include <QRandomGenerator>


QString SelectionDialog::generateRandomId()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 16; // assuming you want random strings of 12 characters

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = QRandomGenerator::global()->bounded(0, possibleCharacters.size() - 1);
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}




//----------------------------------------------------------------------------------------------------------




SelectionDialog::SelectionDialog(ListImage*& r, BodyParts part)
    : result(r), bodyPart(part)
{
    ui = std::make_unique<Ui::SelectionDialog>();
    ui->setupUi(this);
    ui->selectWidget->setup(part);
    result = nullptr;
    connect(ui->selectWidget, &SelectWidget::selectionMade, this, &SelectionDialog::on_selection_made);
}


SelectionDialog::~SelectionDialog()
{

}


void SelectionDialog::on_selection_made(ListImage* image)
{
    result = image;
}


void SelectionDialog::on_newButton_pressed()
{
    QPixmap pixels{ 1024, 1024 };
    pixels.fill(QColor(255, 255, 255, 0));
    DrawingDialog drawing_dialog{ pixels, bodyPart };
    auto success = drawing_dialog.exec();

    if (success)
    {
        auto pathString = bodyPartsDirectory.path() + "/" + bodyPartName(bodyPart) + "/" + generateRandomId() + ".png";
        pixels.save(pathString);
        result = ImageManager::get()->addItem(QDir(pathString), bodyPart, pixels);

        std::cout << "Drawing saved as: " << pathString.toStdString() << "\n";
        accept();
    }
    else
    {
        std::cout << "Drawing canceled.\n";
    }
}


void SelectionDialog::on_editButton_pressed()
{
    if (ui->selectWidget->getSelectedImage())
    {
        QPixmap pixels = ui->selectWidget->getSelectedImage()->image.copy();
        DrawingDialog drawing_dialog{ pixels, bodyPart };

        auto success = drawing_dialog.exec();

        if (success)
        {
            auto pathString = bodyPartsDirectory.path() + "/" + bodyPartName(bodyPart) + "/" + generateRandomId() + ".png";
            pixels.save(pathString);
            result = ImageManager::get()->addItem(QDir(pathString), bodyPart, pixels);

            std::cout << "Drawing saved as: " << pathString.toStdString() << "\n";
            accept();
        }
        else
        {
            std::cout << "Drawing canceled.\n";
        }
    }
}
