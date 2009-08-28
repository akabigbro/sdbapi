#include "sqlshort.h"

using namespace DB;

void SqlShort::setShortInt(short int data)
{
    value = data;
}

SqlShort::SqlShort(short int value)
    : Field(SQL_C_SSHORT), value(value)
{
}

SqlShort::~SqlShort(void)
{
}

short int SqlShort::getValue(void)
{
    return value;
}
