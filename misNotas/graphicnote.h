#ifndef GRAPHICNOTE_H
#define GRAPHICNOTE_H

#include <QImage>
#include <note.h>

class GraphicNote : public Note {
private:
    QImage image;

public:
    GraphicNote(QString&, QString&, Date, Date, QStringList&, QString&);
    void update_image(QImage&);
    QImage get_image();
    virtual void save_into_file() override;
    virtual void load_data_from_file(QString&) override;
};

#endif // GRAPHICNOTE_H
