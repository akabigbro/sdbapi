#include "sqldouble.h"

using namespace DB;

void SqlDouble::setDouble(double data)
{
    value = data;
}

SqlDouble::SqlDouble(double value)
    : Field(SQL_C_DOUBLE), value(value)
{
}

SqlDouble::~SqlDouble(void)
{
}

double SqlDouble::getValue(void)
{
    return value;
}
