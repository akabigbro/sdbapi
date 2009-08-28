#include "connection.h"

using namespace DB;

SQLHDBC & Connection::getConnectionHandle(void)
{
    return handle;
}

Connection::Connection(void) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_DBC, getEnvironmentHandle(), &handle);

    if (SQL_SUCCEEDED(error))
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

    if (SQL_SUCCEEDED(error))
    {
        throw error;
    }
}

void Connection::OutputInfo(void)
{
    DBInfo::Output(SQL_HANDLE_DBC, handle);
}
