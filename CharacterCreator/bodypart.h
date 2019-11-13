#pragma once

#include <array>

#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QRandomGenerator>


class DrawingDialog;


enum class BodyParts
{
    Head         = 0,
    Chest        = 1,
    ArmLeft      = 2,
    ArmRight     = 3,
    ForeArmLeft  = 4,
    ForeArmRight = 5,
    HandLeft     = 6,
    HandRight    = 7,
    ThighLeft    = 8,
    ThighRight   = 9,
    ShinLeft     = 10,
    ShinRight    = 11
};


const std::array<QString, 12> bodyPartNames
{
    "head",
    "chest",
    "arm_left",
    "arm_right",
    "forearm_left",
    "forearm_right",
    "hand_left",
    "hand_right",
    "thigh_left",
    "thigh_right",
    "shin_left",
    "shin_right"
};


inline QString bodyPartName(BodyParts limbType)
{
    return bodyPartNames[static_cast<size_t>(limbType)];
}


inline BodyParts bodyPartFromName(const QString& name)
{
    auto pos = std::distance(bodyPartNames.begin(), std::find(bodyPartNames.begin(), bodyPartNames.end(), name));
    return static_cast<BodyParts>(pos);
}



inline QString generateRandomId()
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



class BodyPart : public QGraphicsItem
{
public:

    BodyPart(QPixmap& pixels, BodyParts part, DrawingDialog * drawingDialog);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


protected:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:

    QPixmap bg{ 1024, 1024 };
    QPixmap& pixels;

    QPainter painter;

    BodyParts bodyPart;

    DrawingDialog * drawingDialog;

};

