#pragma once

#include <memory>
#include <QDialog>
#include "ui_selectiondialog.h"
#include "bodypart.h"



class SelectionDialog : public QDialog
{
    Q_OBJECT

public:

    SelectionDialog(ListImage*& result, BodyParts bodyPart);

    ~SelectionDialog();

    static QString generateRandomId();


private slots:

    void on_selection_made(ListImage* image);

    void on_newButton_pressed();

    void on_editButton_pressed();


private:

    ListImage*& result;

    BodyParts bodyPart;

    std::unique_ptr<Ui::SelectionDialog> ui;

};
