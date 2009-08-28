#include "result.h"

using namespace DB;

SQLHSTMT & Result::getStatementHandle(void)
{
    return handle;
}

Result::Result(SQLHSTMT handle)
    : handle(handle)
{
}

Result::~Result(void)
{
    SQLFreeHandle(SQL_HANDLE_STMT, handle);
}

int Result::getRowCount(void) throw(SQLRETURN&)
{
    SQLINTEGER count;

    error = SQLRowCount(handle, &count);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, handle, error))
    {
        throw error;
    }

    return count;
}

int Result::getColumnCount(void) throw(SQLRETURN&)
{
    SQLSMALLINT count;

    error = SQLNumResultCols(handle, &count);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, handle, error))
    {
        throw error;
    }

    return count;
}
