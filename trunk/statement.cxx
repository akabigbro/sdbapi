#include "statement.h"

using namespace DB;

void Statement::Initialize(SQLHDBC & connection) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_STMT, connection, &handle);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }
}

SQLHSTMT & Statement::getStatementHandle(void)
{
    return handle;
}

Statement::~Statement(void)
{
    SQLFreeHandle(SQL_HANDLE_STMT, handle);
}

int Statement::Execute(SQLCHAR * statement) throw(SQLRETURN&)
{
    error = SQLExecDirect(handle, statement, SQL_NTS);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }

    return getRowCount();
}

int Statement::getRowCount(void) throw(SQLRETURN&)
{
    SQLLEN rows;
    error = SQLRowCount(handle, &rows);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }

    return rows;
}
