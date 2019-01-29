#ifndef DATE_H
#define DATE_H

#include <QString>
#include <iostream>
#include <stdio.h>
#include <time.h>

class Date {
private:
    QString year, month, day;

public:
    Date();
    Date(QString&);
    bool operator>(Date&);
    bool operator<(Date&);
    bool operator!=(Date&);
    bool operator==(Date&);
    bool operator<=(Date&);
    bool operator>=(Date&);
    int get_year();
    int get_month();
    int get_day();
    QString get_date_in_QString_format();
    int get_date_in_int_format();
    static QString get_current_date_in_QString();
    void update_date();
};

#endif // DATE_H
