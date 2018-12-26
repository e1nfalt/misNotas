#ifndef NOTE_H
#define NOTE_H

#include <date.h>
#include <tag.h>
#include <string>
#include <vector>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QStringList>


class Note
{
protected:
    QString type;
    QString title;
    Date created_date;
    Date editing_date;
    QStringList tags;
    QString data_file;
    int id;
public:

    Note(QString type_, QString title_, Date created_date_, Date editing_date_) : type(type_), title(title_),
        created_date(created_date_), editing_date(editing_date_) {}

    Note(QString type_, QString title_) : type(type_), title(title_) {}

    QString get_title() { return title; }

    QString get_type() { return type; }

    Date get_cr_date() { return created_date; }

    Date get_ed_date() { return editing_date; }

    int get_id() { return id; }

    QString get_tags()
    {
        QString s = "";
        for (auto i : tags)
            s += i + "@";
        return s.mid(0, s.length() - 2);
    }

    QString get_file_path() { return data_file; }

    void set_title(QString str_) { title = str_; }

    void update_editing_date(Date new_date) { editing_date = new_date; }

    QString get_editing_date()
    {
        return editing_date.get_date_in_QString_format();
    }

    QString get_created_date()
    {
        return created_date.get_date_in_QString_format();
    }

    virtual ~Note() {}
    virtual void save_into_file() = 0;

    virtual void load_data_from_file(QString &) = 0;

};


class TextNote : virtual public Note
{
private:
    //static int text_note_num;
    QString text;
public:

    TextNote(QString title_) : Note("Text", title_)
    {
        title = title_;
    }

    TextNote(int id_, QString title_, Date cr_date, Date ed_date, QStringList tags_, QString data_file_path)
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
        }
    }

};


class GraphicNote : public Note
{

};


class AudioNote : public Note
{

};


class VideoNote : public Note
{

};


std::vector<Note*> get_notes()
{
    std::vector<Note*> notes;
    std::vector<std::pair<QString, QString> > ar;
    QFile file("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        QString s = in.readLine();
        while (!s.isEmpty())
        {
            if (s.endsWith("\n"))
                s.remove(s.size() - 1, 1);
            int id = s.toInt();
            QString type = in.readLine();
            QString title = in.readLine();
            QString cr_date = in.readLine();
            QString ed_date = in.readLine();
            QStringList tags_list = in.readLine().split("@");
            QString data_file_path = in.readLine();
            if (type == "Text")
            {
                notes.push_back(new TextNote(id, title, cr_date, ed_date, tags_list, data_file_path));
            }
            else if (type == "Graphic")
            {

            }
            else if (type == "Audio")
            {

            }
            else if (type == "Video")
            {

            }
            s = in.readLine();
        }

    }
    file.close();
    return notes;
}


void write_note_list(std::vector<Note*> &notes)
{
    QFile file("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
    if (file.open(QIODevice::WriteOnly))
    {
        for (auto i : notes)
        {
            QTextStream out(&file);
            //Date t1 = i->get_created_date()
            out << i->get_type() << "\n" << i->get_title() << "\n" << i->get_created_date()
                << "\n" << i->get_editing_date() << "\n" << i->get_tags() << "\n"
                << i->get_file_path() << "\n";
        }
        file.close();
    }
}


std::vector<Note*> notes;
#endif // NOTE_H
