#ifndef TEXTNOTE_H
#define TEXTNOTE_H

#include <note.h>

class TextNote : virtual public Note
{
private:
    QString text;
public:

    void set_text(QString &);

    TextNote(QString &);

    QString get_text();

    TextNote(QString&, QString &, Date, Date, QStringList &, QString &);

    virtual void save_into_file() override;

    virtual void load_data_from_file(QString &file_path) override;

};

#endif // TEXTNOTE_H
