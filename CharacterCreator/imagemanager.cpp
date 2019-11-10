#include "imagemanager.h"
#include <QImageReader>



ImageManager * ImageManager::get()
{
    static ImageManager global_image_manager;
    return &global_image_manager;
}



std::vector<std::unique_ptr<ListImage>> * ImageManager::getList(BodyParts bodyPart)
{
    return &imageLists[bodyPart];
}



ListImage * ImageManager::addItem(const QDir& directory, BodyParts bodyPart, const QPixmap& pixels)
{
    auto img = new ListImage();
    img->directory = directory;
    img->image = pixels;
    imageLists[bodyPart].emplace_back(img);
    return img;/*
    imageLists[bodyPart].emplace_back();
    imageLists[bodyPart].back().directory = directory;
    imageLists[bodyPart].back().image = pixels;// pixels.scaled(256, 256);
    return &imageLists[bodyPart].back();*/
}



ListImage * ImageManager::addItem(const QDir& directory, BodyParts bodyPart)
{
    QImageReader imgReader{ directory.path() };
    //imgReader.setScaledSize(QSize{ 256, 256 });

    auto img = new ListImage();
    img->directory = directory;
    img->image = QPixmap::fromImageReader(&imgReader);
    imageLists[bodyPart].emplace_back(img);
    return img;
    /*
    imageLists[bodyPart].emplace_back();
    imageLists[bodyPart].back().directory = directory;
    imageLists[bodyPart].back().image = QPixmap::fromImageReader(&imgReader);
    return &imageLists[bodyPart].back();*/
}
