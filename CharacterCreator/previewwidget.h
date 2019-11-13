#pragma once

#include <QWidget>

#include <unordered_map>

#include "bodypart.h"
#include "imagemanager.h"




class PreviewWidget : public QWidget
{
    Q_OBJECT

public:

    explicit PreviewWidget(QWidget *parent = nullptr);

    bool contains(BodyParts bodyPart) const;

    void paintEvent(QPaintEvent *event) override;

signals:

    void resetRequest();

public slots:

    void onBodyPartSelected(BodyParts bodyPart, ListImage* image);

    void reset();

    void randomize();

    void save();

    QString path(BodyParts bodyPart) const;

private:

    void draw(BodyParts bodyPart, int transX, int transY, float rotate = 0);

    std::unordered_map<BodyParts, ListImage*> character;


    QPainter painter{ this };
    bool changed = false;

};

