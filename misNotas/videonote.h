#ifndef VIDEONOTE_HH
#define VIDEONOTE_HH

#include <note.h>

class VideoNote : public Note
{
public:
    VideoNote(int, QString &, Date, Date, QStringList &, QString &);

    void save_into_file();

    void load_data_from_file(QString &);
};

#endif // VIDEONOTE_HH
