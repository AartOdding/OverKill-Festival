#include "previewwidget.h"

#include <iostream>


PreviewWidget::PreviewWidget(QWidget *parent)
    : QWidget(parent)
{

}


void PreviewWidget::onBodyPartSelected(BodyParts bodyPart, ListImage* image)
{
    character[bodyPart] = image;
    repaint();
}


bool PreviewWidget::contains(BodyParts bodyPart) const
{
    return character.find(bodyPart) != character.end();
}


void PreviewWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this);

    if (contains(BodyParts::Chest))        draw(BodyParts::Chest,         0,    0);
    if (contains(BodyParts::Head))         draw(BodyParts::Head,          0,   -300);
    if (contains(BodyParts::ArmLeft))      draw(BodyParts::ArmLeft,       160, -160);
    if (contains(BodyParts::ArmRight))     draw(BodyParts::ArmRight,     -160, -160);
    if (contains(BodyParts::ForeArmLeft))  draw(BodyParts::ForeArmLeft,   320, -160);
    if (contains(BodyParts::ForeArmRight)) draw(BodyParts::ForeArmRight, -320, -160);
    if (contains(BodyParts::HandLeft))     draw(BodyParts::HandLeft,      420, -160);
    if (contains(BodyParts::HandRight))    draw(BodyParts::HandRight,    -420, -160);
    if (contains(BodyParts::ThighLeft))    draw(BodyParts::ThighLeft,     60,   270);
    if (contains(BodyParts::ThighRight))   draw(BodyParts::ThighRight,   -60,   270);
    if (contains(BodyParts::ShinLeft))     draw(BodyParts::ShinLeft,      60,   460);
    if (contains(BodyParts::ShinRight))    draw(BodyParts::ShinRight,    -60,   460);

    painter.end();
}


void PreviewWidget::draw(BodyParts bodyPart, int transX, int transY, float rotate)
{
    painter.resetTransform();

    painter.translate(width() / 2, height() / 2 - 50);
    painter.scale(0.5, 0.5);
    painter.translate(transX, transY);
    painter.rotate(rotate);

    painter.drawPixmap(-512, -512, character[bodyPart]->image);
}


void PreviewWidget::reset()
{
    character.clear();
    repaint();
}

void PreviewWidget::randomize()
{

}
