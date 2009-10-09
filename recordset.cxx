#include "recordset.h"

using namespace DB;

RecordSet::RecordSet(RecordSet & recordSet)
    : statement(recordSet.statement)
{
}

RecordSet::RecordSet(Statement * statement)
    : statement(statement)
{
}

RecordSet::~RecordSet(void)
{
}

RecordSet RecordSet::operator=(RecordSet & rs)
{
    statement = rs.statement;
}

bool RecordSet::Next(void) throw(SQLRETURN&)
{
    bool more = statement->MoreResults();

    if (more)
    {
        statement->MoveCursor(SQL_FETCH_NEXT);
    }

    return more;
}

bool RecordSet::Prior(void) throw(SQLRETURN&)
{
    statement->MoveCursor(SQL_FETCH_PRIOR);
}

bool RecordSet::First(void) throw(SQLRETURN&)
{
    statement->MoveCursor(SQL_FETCH_FIRST);
}

bool RecordSet::Last(void) throw(SQLRETURN&)
{
    statement->MoveCursor(SQL_FETCH_LAST);
}

std::map<std::string, std::string> RecordSet::getCurrent(void) throw(SQLRETURN&)
{
    std::map<std::string, std::string> record;

    for (int index = 1; index <= statement->getColumnCount(); index++)
    {
        record[statement->getColumnName(index)] = statement->getString(index);
    }

    return record;
}
