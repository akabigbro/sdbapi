#include "field.h"

using namespace DB;

void Field::setType(int type)
{
    this->type = type;
}

void Field::setString(const char * data)
{
}

void Field::setShortInt(short int data)
{
}

void Field::setUShortInt(unsigned short int data)
{
}

void Field::setLongInt(long int data)
{
}

void Field::setFloat(float data)
{
}

void Field::setDouble(double data)
{
}

void Field::setBinary(unsigned char * data)
{
}

void Field::setDateTime(struct tm * data)
{
}

Field::Field(int type)
    : type(type)
{
}

Field::~Field(void)
{
}

void Field::setValue(SQLCHAR * data)
{
    setString((char *) data);
}

void Field::setValue(SQLSMALLINT data)
{
    setShortInt((short int) data);
}

void Field::setValue(SQLUSMALLINT data)
{
    setUShortInt((unsigned short int) data);
}

void Field::setValue(SQLINTEGER data)
{
    setLongInt((long int) data);
}

void Field::setValue(SQLREAL data)
{
    setFloat((float) data);
}

void Field::setValue(SQLDOUBLE data)
{
    setDouble((double) data);
}

void Field::setValue(SQL_DATE_STRUCT * data)
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

void Field::setValue(SQL_TIME_STRUCT * data)
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
