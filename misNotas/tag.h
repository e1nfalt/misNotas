#ifndef TAG_H
#define TAG_H

#include <string>


class Tag
{
private:
    std::string name;
public:
    Tag(std::string str_) : name(str_) {}
};

#endif // TAG_H
