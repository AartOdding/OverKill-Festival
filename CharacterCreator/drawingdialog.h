#pragma once

#include <memory>

#include <QColor>
#include <QDialog>
#include <QGraphicsScene>

#include "ui_drawingdialog.h"

#include "bodypart.h"



enum class Tool
{
    Pencil,
    Eraser,
    Dragger
};



class DrawingDialog : public QDialog
{
    Q_OBJECT

public:

    DrawingDialog(QPixmap& pixels, BodyParts part);

    ~DrawingDialog();

    Tool activeTool() const { return active_tool; }

    QColor pencilColor() const { return pencil_color; }

    int pencilWidth() const { return pencil_width; }

private slots:

    void on_PenWidthSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int value);

    void on_ColorPickerButton_pressed();

    void on_PencilButton_pressed();

    void on_EraserButton_pressed();

    void on_DraggerButton_pressed();

    void on_ZoomOutButton_pressed();

    void on_ZoomInButton_pressed();

private:

    Tool active_tool = Tool::Pencil;

    QColor pencil_color{ 170, 170, 255 };
    int pencil_width = 5;

    Ui::DrawingDialog* ui;

    QGraphicsScene * scene;

    int zoom_index = 0;
    double zoom_factor = 1.1;

};
