#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <note.h>

class GraphicNote : public Note
{
public:

    GraphicNote(int, QString &, Date, Date, QStringList &, QString &);

    void save_into_file() override;

    void load_data_from_file(QString &) override;
};

#endif // GRAPHICNOTE_H
