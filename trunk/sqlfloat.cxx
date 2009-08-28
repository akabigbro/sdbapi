#include "sqlfloat.h"

using namespace DB;

void SqlFloat::setFloat(float data)
{
    value = data;
}

SqlFloat::SqlFloat(float value)
    : Field(SQL_C_FLOAT), value(value)
{
}

SqlFloat::~SqlFloat(void)
{
}

float SqlFloat::getValue(void)
{
    return value;
}
