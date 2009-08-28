#include "integer.h"

using namespace DB;

void Integer::setLongInt(long int data)
{
    value = data;
}

Integer::Integer(long int value)
    : Field(SQL_C_SLONG), value(value)
{
}

Integer::~Integer(void)
{
}

long int Integer::getValue(void)
{
    return value;
}
