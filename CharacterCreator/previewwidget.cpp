#include "previewwidget.h"
#include "mainwindow.h"

#include <iostream>
#include <QXmlStreamWriter>


PreviewWidget::PreviewWidget(QWidget *parent)
    : QWidget(parent)
{
    // background: transparent;
    // setStyleSheet("background-color: rgba( 255, 255, 255, 0% );" );
    setStyleSheet("background: transparent;");
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
    if (contains(BodyParts::Head))         draw(BodyParts::Head,          0,   -230);
    if (contains(BodyParts::ArmLeft))      draw(BodyParts::ArmLeft,       160, -110);
    if (contains(BodyParts::ArmRight))     draw(BodyParts::ArmRight,     -160, -110);
    if (contains(BodyParts::ForeArmLeft))  draw(BodyParts::ForeArmLeft,   320, -110);
    if (contains(BodyParts::ForeArmRight)) draw(BodyParts::ForeArmRight, -320, -110);
    if (contains(BodyParts::HandLeft))     draw(BodyParts::HandLeft,      420, -110);
    if (contains(BodyParts::HandRight))    draw(BodyParts::HandRight,    -420, -110);
    if (contains(BodyParts::ThighLeft))    draw(BodyParts::ThighLeft,     50,   270);
    if (contains(BodyParts::ThighRight))   draw(BodyParts::ThighRight,   -50,   270);
    if (contains(BodyParts::ShinLeft))     draw(BodyParts::ShinLeft,      50,   460);
    if (contains(BodyParts::ShinRight))    draw(BodyParts::ShinRight,    -50,   460);

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

        QString id = generateRandomId();

        QDir newDir = characterDirectory;
        newDir.mkdir(id);
        newDir.cd(id);

        if (contains(BodyParts::Head)) character[BodyParts::Head]->image.save(newDir.path() + "/head.png");
        if (contains(BodyParts::Chest)) character[BodyParts::Chest]->image.save(newDir.path() + "/chest.png");
        if (contains(BodyParts::ArmLeft)) character[BodyParts::ArmLeft]->image.save(newDir.path() + "/arm_left.png");
        if (contains(BodyParts::ArmRight)) character[BodyParts::ArmRight]->image.save(newDir.path() + "/arm_right.png");
        if (contains(BodyParts::ForeArmLeft)) character[BodyParts::ForeArmLeft]->image.save(newDir.path() + "/forearm_left.png");
        if (contains(BodyParts::ForeArmRight)) character[BodyParts::ForeArmRight]->image.save(newDir.path() + "/forearm_right.png");
        if (contains(BodyParts::HandLeft)) character[BodyParts::HandLeft]->image.save(newDir.path() + "/hand_left.png");
        if (contains(BodyParts::HandRight)) character[BodyParts::HandRight]->image.save(newDir.path() + "/hand_right.png");
        if (contains(BodyParts::ThighLeft)) character[BodyParts::ThighLeft]->image.save(newDir.path() + "/thigh_left.png");
        if (contains(BodyParts::ThighRight)) character[BodyParts::ThighRight]->image.save(newDir.path() + "/thigh_right.png");
        if (contains(BodyParts::ShinLeft)) character[BodyParts::ShinLeft]->image.save(newDir.path() + "/shin_left.png");
        if (contains(BodyParts::ShinRight)) character[BodyParts::ShinRight]->image.save(newDir.path() + "/shin_right.png");

        //QFile file{ characterDirectory.path() + "/" + id + ".xml" };
        /*
        file.open(QFile::WriteOnly);

        QXmlStreamWriter xml{ &file };

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

        file.close();
        //std::cout << output.toStdString() << std::endl;
        */

        QPixmap pixmap(this->size());
        pixmap.fill(Qt::transparent);
        this->render(&pixmap);
        pixmap.save(characterDirectory.path() + "/" + id + ".png");

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
