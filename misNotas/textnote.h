#ifndef TEXTNOTE_H
#define TEXTNOTE_H

#include <note.h>

class TextNote : virtual public Note
{
private:
    QString text;
public:

    void set_text(QString &s)
    {
        text = s;
    }

    TextNote(QString &title_) : Note("Text", title_)
    {
        //title = title_;
    }

    QString get_text()
    {
        return text;
    }

    TextNote(int id_, QString &title_, Date cr_date, Date ed_date, QStringList &tags_, QString &data_file_path)
        : Note("Text", title_)
    {
        created_date = cr_date;
        editing_date = ed_date;
        tags = tags_;
        data_file = data_file_path;
        id = id_;
    }

    void save_into_file() override
    {
        QFile file(data_file);
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            out << text;
        }
        file.close();
    }

    void load_data_from_file(QString &file_path) override // think about it
    {
        data_file = file_path;
        text = "";
        QFile file(data_file);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            QString line = in.readLine();
            while (!line.isEmpty())
            {
                text += line;
                line = in.readLine();
            }
            file.close();
        }
    }

};

#endif // TEXTNOTE_H
