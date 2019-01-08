#include "note.h"

Note::Note(QString& type_, QString& title_, Date& created_date_, Date& editing_date_)
    : type(type_)
    , title(title_)
    , created_date(created_date_)
    , editing_date(editing_date_)
{
}

Note::Note(const char* type_, QString& title_)
    : type(type_)
    , title(title_)
{
}

QString Note::get_title() { return title; }

QString Note::get_type() { return type; }

Date Note::get_cr_date() { return created_date; }

Date Note::get_ed_date() { return editing_date; }

QString Note::get_id() { return id; }

QString Note::get_tags()
{
    QString s = "";
    for (auto i : tags)
        s += i + "@";
    return s;
}

QString Note::get_file_path() { return data_file; }

void Note::set_title(QString& str_) { title = str_; }

void Note::update_editing_date(Date& new_date) { editing_date = new_date; }

QString Note::get_editing_date() { return editing_date.get_date_in_QString_format(); }

QString Note::get_created_date() { return created_date.get_date_in_QString_format(); }

Note::~Note() {}
