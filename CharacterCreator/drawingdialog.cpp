#include "drawingdialog.h"
#include "bodypart.h"

#include <QColorDialog>


DrawingDialog::DrawingDialog(QPixmap& pixels, BodyParts part)
{
    ui = new Ui::DrawingDialog();
    scene = new QGraphicsScene();
    ui->setupUi(this);

    QPalette palette = ui->ColorPickerButton->palette();
    palette.setColor(QPalette::Button, pencil_color);
    ui->ColorPickerButton->setPalette(palette);

    ui->PenWidthSlider->setValue(pencil_width);
    ui->spinBox->setValue(pencil_width);

    scene->addItem(new BodyPart(pixels, part, this));

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-700, -700, 1400, 1400);
    scene->setBackgroundBrush(QBrush(QColor(200, 200, 200)));
}


DrawingDialog::~DrawingDialog()
{
    delete scene;
    delete ui;
}


void DrawingDialog::on_PenWidthSlider_valueChanged(int value)
{
    pencil_width = value;

    if (ui->spinBox->value() != value)
    {
        ui->spinBox->setValue(value);
    }
}


void DrawingDialog::on_spinBox_valueChanged(int value)
{
    pencil_width = value;

    if (ui->PenWidthSlider->value() != value)
    {
        ui->PenWidthSlider->setValue(value);
    }
}


void DrawingDialog::on_ColorPickerButton_pressed()
{
    pencil_color = QColorDialog::getColor(pencil_color);

    QPalette palette = ui->ColorPickerButton->palette();
    palette.setColor(QPalette::Button, pencil_color);
    ui->ColorPickerButton->setPalette(palette);
}


void DrawingDialog::on_PencilButton_pressed()
{
    active_tool = Tool::Pencil;
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
}


void DrawingDialog::on_EraserButton_pressed()
{
    active_tool = Tool::Eraser;
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
}


void DrawingDialog::on_DraggerButton_pressed()
{
    active_tool = Tool::Dragger;
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
}


void DrawingDialog::on_ZoomOutButton_pressed()
{
    if (zoom_index > -10)
    {
        --zoom_index;
        ui->graphicsView->scale(1.0 / zoom_factor, 1.0 / zoom_factor);
    }
}


void DrawingDialog::on_ZoomInButton_pressed()
{
    if (zoom_index < 10)
    {
        ++zoom_index;
        ui->graphicsView->scale(zoom_factor, zoom_factor);
    }
}
