#include "recordset.h"

using namespace DB;

RecordSet::RecordSet(Statement * statement)
    : statement(statement)
{
}

RecordSet::~RecordSet(void)
{
}

void Next(void) throw(SQLRETURN&)
{
}

void Prior(void) throw(SQLRETURN&)
{
}

void First(void) throw(SQLRETURN&)
{
}

void Last(void) throw(SQLRETURN&)
{
}

void Absolute(int index) throw(SQLRETURN&)
{
}

void Relative(int offset) throw(SQLRETURN&)
{
}
