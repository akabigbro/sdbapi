#include "string.h"

using namespace DB;

void String::setString(const char * data)
{
    if (NULL != data)
    {
        value = data;
    }
}

String::String(const char * value)
    : Field(SQL_C_CHAR), value(value)
{
}

String::~String(void)
{
}

std::string String::getValue(void)
{
    return value;
}
