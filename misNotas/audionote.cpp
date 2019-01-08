#include "audionote.h"

AudioNote::AudioNote(QString& id_, QString& title_, Date cr_date, Date ed_date, QStringList& tags_, QString& data_file_path)
    : Note("Audio", title_)
{
    created_date = cr_date;
    editing_date = ed_date;
    tags = tags_;
    data_file = data_file_path;
    id = id_;
    load_data_from_file(data_file);
}

void AudioNote::save_into_file()
{
    QFile file(data_file);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(data);
        file.close();
        editing_date.update_date();
    }
}

void AudioNote::load_data_from_file(QString& file_name)
{
    data.clear();
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)) {
        data = file.readAll();
        file.close();
    }
}

QByteArray& AudioNote::get_data() { return data; }
