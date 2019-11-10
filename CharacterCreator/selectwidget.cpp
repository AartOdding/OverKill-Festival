#include "selectwidget.h"
#include <iostream>
#include <QPainter>
#include <QMouseEvent>


SelectWidget::SelectWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumHeight(8000);
}


void SelectWidget::setup(BodyParts part)
{
    bodyPart = part;
    images = ImageManager::get()->getList(part);
    numRows = static_cast<int>(images->size()) / numColumns + 1;
    setHeight();
}


void SelectWidget::resizeEvent(QResizeEvent *)
{
    setHeight();
}


void SelectWidget::setHeight()
{
    if (width() != lastUsedWidth)
    {
        lastUsedWidth = width();

        int usableWidth = width() - (numColumns + 1) * 10;
        imageSize = usableWidth / numColumns;

        setMinimumHeight(numRows * imageSize + numRows * 10 + 50);
    }
}


void SelectWidget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x() / (imageSize + 10);
    int y = event->y() / (imageSize + 10);
    int index = y * numColumns + x;

    if (index < images->size())
    {
        selectedImage = index;
        emit selectionMade(&images->at(index));
        repaint();
    }
}


void SelectWidget::paintEvent(QPaintEvent *)
{
    QPainter painter{ this };

    painter.setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < images->size(); ++i)
    {
        if (i == selectedImage)
        {
            QBrush brush{ QColor(65,105,225) };
            QPen pen{ brush, 2 };
            painter.setPen(pen);
        }
        else
        {
            QBrush brush{ QColor(200, 200, 200) };
            QPen pen{ brush, 1 };
            painter.setPen(pen);
        }

        int x = i % numColumns;
        int y = i / numColumns;

        QRectF target = QRectF(x * (imageSize + 10) + 10, y * (imageSize + 10) + 10, imageSize, imageSize);
        QRectF source = QRectF(255, 255, 512, 512);

        painter.drawPixmap(target, images->at(i).image, source);
        painter.drawRoundedRect(target, 4, 4);
    }
}
