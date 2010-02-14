#include "recordset.h"

using namespace DB;

RecordSet::RecordSet(Statement * statement)
    : statement(statement)
{
}

RecordSet::~RecordSet(void)
{
}

bool RecordSet::Fetch(void) throw(SQLRETURN&)
{
    return statement->Fetch();
}

bool RecordSet::Next(void) throw(SQLRETURN&)
{
    return statement->MoveCursor(SQL_FETCH_NEXT);
}

bool RecordSet::Prior(void) throw(SQLRETURN&)
{
    return statement->MoveCursor(SQL_FETCH_PRIOR);
}

bool RecordSet::First(void) throw(SQLRETURN&)
{
    return statement->MoveCursor(SQL_FETCH_FIRST);
}

bool RecordSet::Last(void) throw(SQLRETURN&)
{
    return statement->MoveCursor(SQL_FETCH_LAST);
}

bool RecordSet::More(void) throw(SQLRETURN&)
{
    return statement->MoreResults();
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
