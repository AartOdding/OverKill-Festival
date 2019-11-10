#include "bodypart.h"
#include "drawingdialog.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>



BodyPart::BodyPart(QPixmap& pix, BodyParts part_, DrawingDialog * drawer)
    : pixels(pix), bodyPart(part_), drawingDialog(drawer)
{
    bg.fill();
    pixels.fill(QColor(255, 255, 255, 0));
    setPos(-512, -512);
}


QRectF BodyPart::boundingRect() const
{
    return { 0, 0, 1024, 1024 };
}

/*
void Limb::save_to(const QDir &directory)
{
    pixels.save(directory.absolutePath() + "/" + QString(limb_id.c_str()) + ".png");
}*/


void BodyPart::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, 1024, 1024, bg);
    painter->drawPixmap(0, 0, 1024, 1024, pixels);
}


void BodyPart::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::MidButton || drawingDialog->activeTool() == Tool::Dragger)
    {
        event->ignore();
    }
    else if (event->button() == Qt::LeftButton)
    {
        painter.begin(&pixels);

        QPen pen;
        pen.setCapStyle(Qt::RoundCap);

        pen.setColor(drawingDialog->pencilColor());

        if (drawingDialog->activeTool() == Tool::Pencil)
        {
            pen.setWidth(drawingDialog->pencilWidth());
            painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        }
        else if (drawingDialog->activeTool() == Tool::Eraser)
        {
            pen.setWidth(drawingDialog->pencilWidth() * 2);
            painter.setCompositionMode(QPainter::CompositionMode_Clear);
        }

        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawPoint(event->pos());
        painter.end();

        update();
    }
}


void BodyPart::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::MidButton || drawingDialog->activeTool() == Tool::Dragger)
    {
        event->ignore();
    }
    else if (event->buttons() & Qt::LeftButton)
    {
        painter.begin(&pixels);

        QPen pen;
        pen.setCapStyle(Qt::RoundCap);
        pen.setColor(drawingDialog->pencilColor());

        if (drawingDialog->activeTool() == Tool::Pencil)
        {
            pen.setWidth(drawingDialog->pencilWidth());
            painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        }
        else if (drawingDialog->activeTool() == Tool::Eraser)
        {
            pen.setWidth(drawingDialog->pencilWidth() * 2);
            painter.setCompositionMode(QPainter::CompositionMode_Clear);
        }

        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawLine(event->lastPos(), event->pos());
        painter.end();

        update();
    }
}


void BodyPart::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}
