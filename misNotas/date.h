#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdio.h>
#include <time.h>


class Date
{
private:
    int year, month, day;
public:

    Date()
    {
        //*this = this->get_current_date();
    }

    Date(std::string str)
    {
        year = int(str[0] + str[1] + str[2] + str[3]);
        month = int(str[5] + str[6]);
        day = int(str[8] + str[9]);
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

    int get_year() { return year; }
    int get_month() { return month; }
    int get_day() { return day; }

    Date get_current_date()
    {
        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);
        return Date(timeinfo->tm_year+1900, timeinfo->tm_mon, timeinfo->tm_mday);
    }
};


std::ostream& operator<<(std::ostream& os, Date &date_)
{
    os << date_.year << "." << date_.month << "." << date_.day;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Date &date_)
{
    os << date_.year << "." << date_.month << "." << date_.day;
    return os;
}

#endif // DATE_H
