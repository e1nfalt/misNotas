#include "videonote.h"

VideoNote::VideoNote(int id_, QString &title_, Date cr_date, Date ed_date, QStringList &tags_, QString &data_file_path)
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

}

void VideoNote::load_data_from_file(QString &file_path)
{

}
