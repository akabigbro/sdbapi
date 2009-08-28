#include "short.h"

using namespace DB;

void Short::setShortInt(short int data)
{
    value = data;
}

Short::Short(short int value)
    : Field(SQL_C_SSHORT), value(value)
{
}

Short::~Short(void)
{
}

short int Short::getValue(void)
{
    return value;
}
