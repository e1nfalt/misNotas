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
    Date created_date, editing_date;
    std::vector<Tag> tags;
    std::string way_to_file;
public:

    Note(std::string title_)
    {
        title = title_;
        created_date = editing_date = created_date.get_current_date();
    }

    std::string get_title() { return title; }

    void set_title(std::string str_) { title = str_; }

    void update_editing_date(Date new_date) { editing_date = new_date; }

    //virtual void content() = 0;
    virtual ~Note();
    virtual void save_into_file() = 0;

    virtual std::vector<Note> load_from_file(std::string &file_path)
    {
        freopen(file_path.c_str(), "r", stdin);
        int num;
        std::cin >> num;
        for (int i = 0; i < num; i++)
        {

        }
    }
};


class TextNote : virtual public Note
{
private:
    static int text_note_num;
public:

    TextNote(std::string title_) : Note(title_)
    {
        title = title_;
        created_date = editing_date = created_date.get_current_date();
    }

    void save_into_file()
    {
        freopen("notes.txt", "r", stdin);
        std::cout << title << std::endl;
        std::cout << created_date << std::endl;
        std::cout << editing_date << std::endl;
        std::cout << way_to_file << std::endl;
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
