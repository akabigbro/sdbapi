#include "connection.h"

using namespace DB;

SQLHDBC & Connection::getConnectionHandle(void)
{
    return handle;
}

Connection::Connection(void) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_DBC, getEnvironmentHandle(), &handle);

    if (!DBInfo::CheckReturn(SQL_HANDLE_DBC, handle, error))
    {
        throw error;
    }
}

Connection::~Connection(void)
{
    SQLDisconnect(handle);
    SQLFreeHandle(SQL_HANDLE_DBC, handle);
}

void Connection::Connect(const char * server, const char * user, const char * password) throw(SQLRETURN&)
{
    error = SQLConnect(handle, (SQLCHAR *) server, SQL_NTS, (SQLCHAR *) user, SQL_NTS, (SQLCHAR *) password, SQL_NTS);

    if (!DBInfo::CheckReturn(SQL_HANDLE_DBC, handle, error))
    {
        throw error;
    }
}

Result * Connection::Execute(const char * query) throw(SQLRETURN&)
{
    SQLHSTMT statement;

    error = SQLAllocHandle(SQL_HANDLE_STMT, handle, &statement);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, statement, error))
    {
        throw error;
    }

    error = SQLExecDirect(statement, (SQLCHAR *)query, SQL_NTS);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, statement, error))
    {
        throw error;
    }

    return new Result(statement);
}