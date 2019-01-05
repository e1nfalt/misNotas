#ifndef NOTE_H
#define NOTE_H

#include <date.h>
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

#endif // NOTE_H
