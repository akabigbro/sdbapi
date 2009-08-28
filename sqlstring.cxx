#include "sqlstring.h"

using namespace DB;

void SqlString::setString(const char * data)
{
    if (NULL != data)
    {
        value = data;
    }
}

SqlString::SqlString(const char * value)
    : SqlField(SQL_C_CHAR), value(value)
{
}

SqlString::~SqlString(void)
{
}

std::string SqlString::getValue(void)
{
    return value;
}
