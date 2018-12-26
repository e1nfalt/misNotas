#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <QString>


class Date
{
private:
    int year, month, day;
public:

    Date()
    {
        //*this = this->get_current_date();
    }

    Date(QString &str)
    {
        year = (str.left(4)).toInt();
        month = (str.mid(6, 2)).toInt();
        day = (str.right(2)).toInt();
    }

    Date(int year_, int month_, int day_) : year(year_), month(month_), day(day_){}

    Date(Date const &date_)
    {
        year = date_.year;
        month = date_.month;
        day = date_.day;
    }

    bool operator>(Date date_)
    {
        int tmp1 = year * 13 + month * 32 + day;
        int tmp2 = date_.year * 13 + date_.month * 32 + date_.day;
        return tmp1 > tmp2;
    }

    bool operator<(Date date_)
    {
        int tmp1 = year * 13 + month * 32 + day;
        int tmp2 = date_.year * 13 + date_.month * 32 + date_.day;
        return tmp1 < tmp2;
    }

    bool operator!=(Date date_)
    {
        int tmp1 = year * 13 + month * 32 + day;
        int tmp2 = date_.year * 13 + date_.month * 32 + date_.day;
        return tmp1 != tmp2;
    }

    bool operator==(Date date_)
    {
        int tmp1 = year * 13 + month * 32 + day;
        int tmp2 = date_.year * 13 + date_.month * 32 + date_.day;
        return tmp1 == tmp2;
    }

    bool operator<=(Date date_)
    {
        int tmp1 = year * 13 + month * 32 + day;
        int tmp2 = date_.year * 13 + date_.month * 32 + date_.day;
        return tmp1 <= tmp2;
    }

    bool operator>=(Date date_)
    {
        int tmp1 = year * 13 + month * 32 + day;
        int tmp2 = date_.year * 13 + date_.month * 32 + date_.day;
        return tmp1 >= tmp2;
    }

    friend std::ostream& operator<<(std::ostream&, Date&);
    friend std::ostream& operator<<(std::ostream&, const Date&);

    QString get_year() { return QString::number(year); }
    QString get_month() { return QString::number(month); }
    QString get_day() { return QString::number(day); }

    QString get_date_in_QString_format()
    {
        //std::string x = std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day);
        return QString::fromStdString(std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day));
    }


    static QString get_current_date_in_QString()
    {
        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);
        QString s = QString::number(timeinfo->tm_year+1900) + "." + QString::number(timeinfo->tm_mon)
                + "." + QString::number(timeinfo->tm_mday);
        return s;
    }
};


#endif // DATE_H
