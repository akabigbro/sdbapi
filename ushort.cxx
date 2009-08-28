#include "ushort.h"

using namespace DB;

void UShort::setUShortInt(unsigned short int data)
{
    value = data;
}

UShort::UShort(unsigned short int value)
    : Field(SQL_C_USHORT), value(value)
{
}

UShort::~UShort(void)
{
}

unsigned short int UShort::getValue(void)
{
    return value;
}
