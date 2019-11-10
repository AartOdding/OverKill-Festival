#include "imagemanager.h"
#include <QImageReader>



ImageManager * ImageManager::get()
{
    static ImageManager global_image_manager;
    return &global_image_manager;
}



std::vector<ListImage> * ImageManager::getList(BodyParts bodyPart)
{
    return &imageLists[bodyPart];
}



void ImageManager::addItem(const QDir& directory, BodyParts bodyPart, const QPixmap& pixels)
{
    imageLists[bodyPart].emplace_back();
    imageLists[bodyPart].back().directory = directory;
    imageLists[bodyPart].back().image = pixels;// pixels.scaled(256, 256);
}



void ImageManager::addItem(const QDir& directory, BodyParts bodyPart)
{
    QImageReader imgReader{ directory.path() };
    //imgReader.setScaledSize(QSize{ 256, 256 });

    imageLists[bodyPart].emplace_back();
    imageLists[bodyPart].back().directory = directory;
    imageLists[bodyPart].back().image = QPixmap::fromImageReader(&imgReader);
}
