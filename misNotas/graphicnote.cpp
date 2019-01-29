#include "graphicnote.h"

GraphicNote::GraphicNote(QString& id_, QString& title_, Date cr_date, Date ed_date, QStringList& tags_, QString& data_file_path)
    : Note("Graphic", title_)
{
    created_date = cr_date;
    editing_date = ed_date;
    tags = tags_;
    data_file = data_file_path;
    id = id_;
    load_data_from_file(data_file);
}

void GraphicNote::save_into_file()
{
    QImage i = image.convertToFormat(QImage::Format_RGB32);
    i.save(data_file);
    editing_date.update_date();
}

void GraphicNote::load_data_from_file(QString& file_path)
{
    QImage loadedImage;
    if (!loadedImage.load(file_path))
    {
        image = loadedImage;
    }
}

void GraphicNote::update_image(QImage& new_image) { image = new_image; }

QImage GraphicNote::get_image() { return image; }
