#ifndef NOTE_H
#define NOTE_H

#include <date.h>
#include <tag.h>
#include <string>
#include <vector>
#include <iostream>


class Note
{
protected:
    std::string title;
    const Date created_date;
    Date editing_date;
    std::vector<Tag> tags;
public:

    Note(std::string title_, Date created_date_, Date editing_date_) : title(title_),
        created_date(created_date_), editing_date(editing_date_)
    {

    }

    Note(std::string title_) : title(title_)
    {

    }

    std::string get_title() { return title; }

    void set_title(std::string str_) { title = str_; }

    void update_editing_date(Date new_date) { editing_date = new_date; }

    virtual ~Note() {}
    virtual void save_into_file() = 0;

    //virtual Note* load_from_file(std::string &file_path) = 0;

    std::string get_editing_date()
    {
        std::string ans = std::to_string(editing_date.get_year()) + "." + std::to_string(editing_date.get_month()) + "."
                + std::to_string( editing_date.get_day());
        return ans;
    }
};


class TextNote : virtual public Note
{
private:
    static int text_note_num;
    std::string text_data;
public:

    TextNote(std::string title_) : Note(title_)
    {
        title = title_;
    }

    TextNote(std::string title_, Date created_date_, Date editing_date_, std::string text_data_) : Note(title_, created_date_, editing_date_)
    {
        //title = title_;
        text_data = text_data_;
    }

    void save_into_file()
    {
        freopen("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt", "r", stdin);
        std::cout << "Text" << std::endl;
        std::cout << title << std::endl;
        std::cout << created_date << std::endl;
        std::cout << editing_date << std::endl;
        std::cout << text_data << std::endl;
    }

    void update_text_data(std::string new_text_data)
    {
        text_data = new_text_data;
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

#endif // NOTE_H
