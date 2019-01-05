#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <note.h>

class GraphicNote : public Note
{
public:

    GraphicNote(int id_, QString title_, Date cr_date, Date ed_date, QStringList tags_, QString data_file_path)
        : Note("Graphic", title_)
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

#endif // GRAPHICNOTE_H
