#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <note.h>
#include <QImage>

class GraphicNote : public Note
{
private:
    QImage image;
public:

    GraphicNote(int, QString &, Date, Date, QStringList &, QString &);

    void update_image(QImage &);

    QImage get_image();

    void save_into_file() override;

    void load_data_from_file(QString &) override;
};

#endif // GRAPHICNOTE_H
