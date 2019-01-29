#include "date.h"

Date::Date()
{
    QString str = get_current_date_in_QString();
    year = str.left(4);
    month = str.mid(5, 2);
    day = str.right(2);
}

Date::Date(QString& str)
{
    year = str.left(4);
    month = str.mid(5, 2);
    day = str.right(2);
}

bool Date::operator>(Date& date_)
{
    int tmp1 = get_date_in_int_format();
    int tmp2 = date_.get_date_in_int_format();
    return tmp1 > tmp2;
}

bool Date::operator<(Date& date_) { return !(*this > date_); }

bool Date::operator!=(Date& date_) { return !(*this == date_); }

bool Date::operator==(Date& date_)
{
    int tmp1 = get_date_in_int_format();
    int tmp2 = date_.get_date_in_int_format();
    return tmp1 == tmp2;
}

bool Date::operator<=(Date& date_)
{
    int tmp1 = get_date_in_int_format();
    int tmp2 = date_.get_date_in_int_format();
    return tmp1 <= tmp2;
}

bool Date::operator>=(Date& date_)
{
    int tmp1 = get_date_in_int_format();
    int tmp2 = date_.get_date_in_int_format();
    return tmp1 >= tmp2;
}

int Date::get_year() { return year.toInt(); }

int Date::get_month()
{
    QString res = month;
    if (res.at(0) == "0")
        res.remove(0, 1);
    return res.toInt();
}

int Date::get_day()
{
    QString res = day;
    if (res.at(0) == "0")
        res.remove(0, 1);
    return res.toInt();
}

QString Date::get_date_in_QString_format() { return year + "." + month + "." + day; }

int Date::get_date_in_int_format()
{
    return get_year() * 400 + get_month() * 32 + get_day();
}

QString Date::get_current_date_in_QString()
{
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    QString year = QString::number(timeinfo->tm_year + 1900);
    QString month;
    if (timeinfo->tm_mon + 1 < 10)
        month = "0" + QString::number(timeinfo->tm_mon + 1);
    else
        month = QString::number(timeinfo->tm_mon + 1);
    QString day;
    if (timeinfo->tm_mday < 10)
        day = "0" + QString::number(timeinfo->tm_mday);
    else
        day = QString::number(timeinfo->tm_mday);
    QString s = year + "." + month + "." + day;
    return s;
}

void Date::update_date()
{
    QString str = get_current_date_in_QString();
    year = str.left(4);
    month = str.mid(5, 2);
    day = str.right(2);
}
