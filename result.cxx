#include "result.h"

using namespace DB;

Result::Result(Statement * statement)
    : statement(statement)
{
}

Result::~Result(void)
{
}

int Result::getRowCount(void) throw(SQLRETURN&)
{
    return Statement->getRowCount();
}

int Result::getColumnCount(void) throw(SQLRETURN&)
{
    return Statement->getColumnCount();
}
