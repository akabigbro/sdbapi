#include "sqldate.h"
#include <string.h>

using namespace DB;

void SqlDate::setDateTime(struct tm * data)
{
    value.tm_year = data->tm_year;
    value.tm_mon = data->tm_mon;
    value.tm_mday = data->tm_mday;
}

SqlDate::SqlDate(struct tm * value)
    : Field(SQL_C_TYPE_DATE)
{
    memset(value, 0, sizeof(value));

    this->value.tm_year = value->tm_year;
    this->value.tm_mon = value->tm_mon;
    this->value.tm_mday = value->tm_mday;
}

SqlDate::~SqlDate(void)
{
}

struct tm * SqlDate::getValue(void)
{
    return &value;
}
