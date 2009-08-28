#include "float.h"

using namespace DB;

void Float::setFloat(float data)
{
    value = data;
}

Float::Float(float value)
    : Field(SQL_C_FLOAT), value(value)
{
}

Float::~Float(void)
{
}

float Float::getValue(void)
{
    return value;
}
