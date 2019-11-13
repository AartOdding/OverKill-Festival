#include "previewwidget.h"
#include "mainwindow.h"

#include <iostream>
#include <QXmlStreamWriter>


PreviewWidget::PreviewWidget(QWidget *parent)
    : QWidget(parent)
{

}


void PreviewWidget::onBodyPartSelected(BodyParts bodyPart, ListImage* image)
{
    if (!contains(bodyPart) || character[bodyPart] != image)
    {
        character[bodyPart] = image;
        repaint();
        changed = true;
    }
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
    if (!character.empty())
    {
        character.clear();
        repaint();
        changed = false; // cannot save empty character.
    }
}


void PreviewWidget::save()
{
    if (changed)
    {
        changed = false;

        QString output;
        QString id = generateRandomId();
        QXmlStreamWriter xml{ &output };

        xml.setAutoFormatting(true);
        xml.writeStartDocument();
        xml.writeStartElement("character");
        xml.writeAttribute("id", id);

        // easier to hardcode, so we always have the same order.
        if (contains(BodyParts::Head))         xml.writeTextElement("head",          path(BodyParts::Head));
        if (contains(BodyParts::Chest))        xml.writeTextElement("chest",         path(BodyParts::Chest));
        if (contains(BodyParts::ArmLeft))      xml.writeTextElement("arm_left",      path(BodyParts::ArmLeft));
        if (contains(BodyParts::ArmRight))     xml.writeTextElement("arm_right",     path(BodyParts::ArmRight));
        if (contains(BodyParts::ForeArmLeft))  xml.writeTextElement("forearm_left",  path(BodyParts::ForeArmLeft));
        if (contains(BodyParts::ForeArmRight)) xml.writeTextElement("forearm_right", path(BodyParts::ForeArmRight));
        if (contains(BodyParts::HandLeft))     xml.writeTextElement("hand_left",     path(BodyParts::HandLeft));
        if (contains(BodyParts::HandRight))    xml.writeTextElement("hand_right",    path(BodyParts::HandRight));
        if (contains(BodyParts::ThighLeft))    xml.writeTextElement("thigh_left",    path(BodyParts::ThighLeft));
        if (contains(BodyParts::ThighRight))   xml.writeTextElement("thigh_right",   path(BodyParts::ThighRight));
        if (contains(BodyParts::ShinLeft))     xml.writeTextElement("shin_left",     path(BodyParts::ShinLeft));
        if (contains(BodyParts::ShinRight))    xml.writeTextElement("shin_right",    path(BodyParts::ShinRight));

        xml.writeEndElement();
        xml.writeEndDocument();

        std::cout << output.toStdString() << std::endl;

        emit resetRequest();
    }
}


QString PreviewWidget::path(BodyParts bodyPart) const
{
    return workingDirectory.relativeFilePath(character.at(bodyPart)->directory.path());
}


void PreviewWidget::randomize()
{
    for (const auto& name : bodyPartNames)
    {
        auto bodyPart = bodyPartFromName(name);
        auto choices = ImageManager::get()->getList(bodyPart);

        if (choices->size() == 1)
        {
            onBodyPartSelected(bodyPart, choices->at(0).get());
        }
        else if (!choices->empty())
        {
            int randomIndex = QRandomGenerator::global()->bounded(0, choices->size());
            onBodyPartSelected(bodyPart, choices->at(randomIndex).get());
        }

    }
}
