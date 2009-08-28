#include "sqlushort.h"

using namespace DB;

void SqlUShort::setUShortInt(unsigned short int data)
{
    value = data;
}

SqlUShort::SqlUShort(unsigned short int value)
    : Field(SQL_C_USHORT), value(value)
{
}

SqlUShort::~SqlUShort(void)
{
}

unsigned short int SqlUShort::getValue(void)
{
    return value;
}
