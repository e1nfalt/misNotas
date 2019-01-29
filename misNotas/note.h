#ifndef NOTE_H
#define NOTE_H

#include <QFile>
#include <QTextStream>
#include <date.h>
#include <vector>

class Note {
protected:
    QString type;
    QString title;
    Date created_date;
    Date editing_date;
    QStringList tags;
    QString data_file;
    QString id;

public:
    Note(const char*, QString&);
    QString get_title();
    QString get_type();
    Date get_cr_date();
    Date get_ed_date();
    QString get_id();
    QString get_tags();
    QString get_file_path();
    void set_title(QString&);
    void update_editing_date(Date&);
    QString get_editing_date();
    QString get_created_date();
    virtual ~Note();
    virtual void save_into_file() = 0;
    virtual void load_data_from_file(QString&) = 0;
};

#endif // NOTE_H
