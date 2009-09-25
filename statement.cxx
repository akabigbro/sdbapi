#include "statement.h"

using namespace DB;

Statement::Statement(SQLHDBC hdbc) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }
}

Statement::~Statement(void)
{
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
}

void Statement::Execute(std::string query) throw(SQLRETURN&)
{
    error = SQLExecDirect(hstmt, (SQLCHAR *)query.c_str(), SQL_NTS);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }
}

int Statement::getRowCount(void) throw(SQLRETURN&)
{
    SQLINTEGER count;

    error = SQLRowCount(hstmt, &count);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    return count;
}

int Statement::getColumnCount(void) throw(SQLRETURN&)
{
    SQLSMALLINT count;

    error = SQLNumResultCols(hstmt, &count);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    return count;
}
