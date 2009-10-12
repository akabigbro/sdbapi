#include "result.h"

using namespace DB;

Result::Result(Statement * statement)
    : statement(statement)
{
}

Result::~Result(void)
{
    delete statement;
}

int Result::getRowCount(void) throw(SQLRETURN&)
{
    return statement->getRowCount();
}

int Result::getColumnCount(void) throw(SQLRETURN&)
{
    return statement->getColumnCount();
}

RecordSet * Result::getRecordSet(void)
{
    return new RecordSet(statement);
}
