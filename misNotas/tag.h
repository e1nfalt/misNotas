#ifndef TAG_H
#define TAG_H

#include <string>
#include <QString>


class Tag
{
private:
    QString name;
public:
    Tag(QString str_) : name(str_) {}
};

#endif // TAG_H
