#include "videonote.h"

VideoNote::VideoNote(QString& id_, QString& title_, Date cr_date, Date ed_date, QStringList& tags_, QString& data_file_path)
    : Note("Video", title_)
{
    created_date = cr_date;
    editing_date = ed_date;
    tags = tags_;
    data_file = data_file_path;
    id = id_;
    load_data_from_file(data_file);
}

void VideoNote::save_into_file()
{
    QFile file(data_file);
    if (file.open(QIODevice::WriteOnly))
    {
        file.resize(0);
        file.write(data);
    }
    editing_date.update_date();
}

void VideoNote::load_data_from_file(QString& file_path)
{
    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly))
    {
        data = file.readAll();
        file.close();
    }
}
