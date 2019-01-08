#ifndef VIDEONOTE_HH
#define VIDEONOTE_HH

#include <note.h>

class VideoNote : public Note {
private:
    QByteArray data;

public:
    VideoNote(QString&, QString&, Date, Date, QStringList&, QString&);
    void save_into_file();
    void load_data_from_file(QString&);
};

#endif // VIDEONOTE_HH
