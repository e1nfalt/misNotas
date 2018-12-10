#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int year, month, day;
public:
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

    int get_year() { return year; }
    int get_month() { return month; }
    int get_day() { return day; }
};

#endif // DATE_H
