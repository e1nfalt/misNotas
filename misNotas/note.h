#ifndef NOTE_H
#define NOTE_H

#include <date.h>
#include <tag.h>
#include <string>
#include <vector>


class Note
{
private:
    std::string title;
    Date created_date, editing_date;
    std::vector<Tag> tags;
public:
    std::string get_title() { return title; }

    void set_title(std::string str_) { title = str_; }

    void update_editing_date(Date new_date) { editing_date = new_date; }

    virtual void content() = 0;
    virtual ~Note();
};


class TextNote : public Note
{

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

#endif // NOTE_H
