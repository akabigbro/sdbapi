#include "connection.h"

using namespace DB;

SQLHDBC & Connection::getConnectionHandle(void)
{
    return handle;
}

Connection::Connection(void) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_DBC, getEnvironmentHandle(), &handle);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }
}

Connection::~Connection(void)
{
    SQLDisconnect(handle);
    SQLFreeHandle(SQL_HANDLE_DBC, handle);
}

void Connection::Connect(SQLCHAR * server, SQLCHAR * user, SQLCHAR * password) throw(SQLRETURN&)
{
    error = SQLConnect(handle, server, SQL_NTS, user, SQL_NTS, password, SQL_NTS);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }
}

void Connection::OutputError(void)
{
    Error::Output(SQL_HANDLE_DBC, handle);
}
