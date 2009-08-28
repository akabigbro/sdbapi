#include "time.h"
#include <string.h>

using namespace DB;

void Time::setDateTime(struct tm * data)
{
    value.tm_hour = data->tm_hour;
    value.tm_min = data->tm_min;
    value.tm_sec = data->tm_sec;
}

Time::Time(struct tm * value)
    : Field(SQL_C_TYPE_TIME)
{
    memset(value, 0, sizeof(value));

    this->value.tm_hour = value->tm_hour;
    this->value.tm_min = value->tm_min;
    this->value.tm_sec = value->tm_sec;
}

Time::~Time(void)
{
}

struct tm * Time::getValue(void)
{
    return &value;
}
