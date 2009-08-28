#include "sqlinteger.h"

using namespace DB;

void SqlInteger::setLongInt(long int data)
{
    value = data;
}

SqlInteger::SqlInteger(long int value)
    : Field(SQL_C_SLONG), value(value)
{
}

SqlInteger::~SqlInteger(void)
{
}

long int SqlInteger::getValue(void)
{
    return value;
}
