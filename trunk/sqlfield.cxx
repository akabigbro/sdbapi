#include "sqlfield.h"

using namespace DB;

void SqlField::setType(int type)
{
    this->type = type;
}

void SqlField::setString(const char * data)
{
}

void SqlField::setShortInt(short int data)
{
}

void SqlField::setUShortInt(unsigned short int data)
{
}

void SqlField::setLongInt(long int data)
{
}

void SqlField::setFloat(float data)
{
}

void SqlField::setDouble(double data)
{
}

void SqlField::setBinary(unsigned char * data)
{
}

void SqlField::setDateTime(struct tm * data)
{
}

SqlField::SqlField(int type)
    : type(type)
{
}

SqlField::~SqlField(void)
{
}

void SqlField::setValue(SQLCHAR * data)
{
    setString((char *) data);
}

void SqlField::setValue(SQLSMALLINT data)
{
    setShortInt((short int) data);
}

void SqlField::setValue(SQLUSMALLINT data)
{
    setUShortInt((unsigned short int) data);
}

void SqlField::setValue(SQLINTEGER data)
{
    setLongInt((long int) data);
}

void SqlField::setValue(SQLREAL data)
{
    setFloat((float) data);
}

void SqlField::setValue(SQLDOUBLE data)
{
    setDouble((double) data);
}

void SqlField::setValue(SQL_DATE_STRUCT * data)
{
    struct tm date;

    date.tm_year = data->year;
    date.tm_mon = data->month;
    date.tm_mday = data->day;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    if (-1 != mktime(&date))
    {
        setDateTime((struct tm *) &date);
    }
}

void SqlField::setValue(SQL_TIME_STRUCT * data)
{
    struct tm time;

    time.tm_year = 0;
    time.tm_mon = 0;
    time.tm_mday = 0;
    time.tm_hour = data->hour;
    time.tm_min = data->minute;
    time.tm_sec = data->second;
    time.tm_isdst = -1;

    if (-1 != mktime(&time))
    {
        setDateTime((struct tm *) &time);
    }
}
