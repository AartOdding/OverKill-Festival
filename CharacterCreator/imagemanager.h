#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include <QDir>
#include <QListWidgetItem>
#include <QTableWidgetItem>

#include <bodypart.h>



struct ListImage
{
    QDir directory;
    QPixmap image;
};



class ImageManager
{

public:

    static ImageManager * get();


    std::vector<ListImage> * getList(BodyParts bodyPart);


    // will load the data from memory
    void addItem(const QDir& directory, BodyParts bodyPart, const QPixmap& pixels);

    // will load the data from disk.
    void addItem(const QDir& directory, BodyParts bodyPart);


private:

    std::unordered_map<BodyParts, std::vector<ListImage>> imageLists;

};
