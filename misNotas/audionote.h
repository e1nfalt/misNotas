#ifndef AUDIONOTE_H
#define AUDIONOTE_H

#include <note.h>

class AudioNote : public Note
{
private:
    QByteArray data;
public:

    AudioNote(QString, QString &, Date, Date, QStringList &, QString &);
    virtual void save_into_file() override;
    virtual void load_data_from_file(QString &file_name) override;
    QByteArray& get_data();
};
#endif // AUDIONOTE_H
