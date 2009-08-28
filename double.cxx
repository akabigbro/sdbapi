#include "double.h"

using namespace DB;

void Double::setDouble(double data)
{
    value = data;
}

Double::Double(double value)
    : Field(SQL_C_DOUBLE), value(value)
{
}

Double::~Double(void)
{
}

double Double::getValue(void)
{
    return value;
}
