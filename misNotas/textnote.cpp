#include "textnote.h"

void TextNote::set_text(QString& s)
{
    text = s;
}

TextNote::TextNote(QString& title_)
    : Note("Text", title_) {}

QString TextNote::get_text()
{
    return text;
}

TextNote::TextNote(QString &id_, QString& title_, Date cr_date, Date ed_date, QStringList& tags_, QString& data_file_path)
    : Note("Text", title_)
{
    created_date = cr_date;
    editing_date = ed_date;
    tags = tags_;
    data_file = data_file_path;
    id = id_;
    load_data_from_file(data_file);
}

void TextNote::save_into_file()
{
    QFile file(data_file);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << text;
        editing_date.update_date();
    }
    file.close();
}

void TextNote::load_data_from_file(QString& file_path)
{
    text = "";
    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isEmpty()) {
            text += line;
            line = in.readLine();
        }
        file.close();
    }
}
