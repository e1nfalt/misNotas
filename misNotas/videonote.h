#ifndef VIDEONOTE_HH
#define VIDEONOTE_HH

#include <note.h>

class VideoNote : public Note
{
public:
    VideoNote(int id_, QString title_, Date cr_date, Date ed_date, QStringList tags_, QString data_file_path)
        : Note("Video", title_)
    {
        created_date = cr_date;
        editing_date = ed_date;
        tags = tags_;
        data_file = data_file_path;
        id = id_;
    }

    void save_into_file() override
    {

    }

    void load_data_from_file(QString &file_path) override // think about it
    {

    }
};

#endif // VIDEONOTE_HH
