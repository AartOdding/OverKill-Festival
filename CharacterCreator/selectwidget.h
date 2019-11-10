#pragma once


#include <QWidget>

#include "bodypart.h"
#include "imagemanager.h"


class SelectWidget : public QWidget
{
    Q_OBJECT

public:

    explicit SelectWidget(QWidget *parent = nullptr);

    void setup(BodyParts bodyPart);

signals:

    void selectionMade(ListImage* selection);

protected:

    void mousePressEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

private:

    void setHeight();

    int numRows = 0;
    int numColumns = 3;
    int lastUsedWidth = 0;

    int selectedImage = -1;

    int imageSize = 0;

    BodyParts bodyPart;

    std::vector<ListImage> * images;

};
