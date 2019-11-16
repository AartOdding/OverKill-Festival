#pragma once

#include <list>
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


    std::vector<std::unique_ptr<ListImage>> * getList(BodyParts bodyPart);


    // will load the data from memory
    ListImage * addItem(const QDir& directory, BodyParts bodyPart, const QPixmap& pixels);

    // will load the data from disk.
    ListImage * addItem(const QDir& directory, BodyParts bodyPart);

    void loadTemplates(const QDir& directory);

    const QPixmap * getTemplate(BodyParts bodyPart) const;

private:

    std::unordered_map<BodyParts, std::vector<std::unique_ptr<ListImage>> > imageLists;

    std::unordered_map<BodyParts, QPixmap> bodyPartTemplates;

    QPixmap noTemplate{ 1024, 1024 };

};
