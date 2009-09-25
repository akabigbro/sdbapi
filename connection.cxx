#include "connection.h"

using namespace DB;

Connection::Connection(void) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_DBC, getEnvironmentHandle(), &hdbc);

    if (!DBInfo::CheckReturn(SQL_HANDLE_DBC, hdbc, error))
    {
        throw error;
    }
}

Connection::~Connection(void)
{
    SQLDisconnect(hdbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
}

void Connection::Connect(std::string server, std::string user, std::string password) throw(SQLRETURN&)
{
    error = SQLConnect(hdbc, (SQLCHAR *) server.c_str(), SQL_NTS, (SQLCHAR *) user.c_str(), SQL_NTS, (SQLCHAR *) password.c_str(), SQL_NTS);

    if (!DBInfo::CheckReturn(SQL_HANDLE_DBC, hdbc, error))
    {
        throw error;
    }
}

Result * Connection::Execute(std::string query) throw(SQLRETURN&)
{
    Statement * statement = NULL;

    try
    {
        statement = new Statement(hdbc);
        statement->Execute(query);
    }
    catch (int & ex)
    {
        if (NULL != statement)
        {
            delete statement;
        }
        throw ex;
    }

    return new Result(statement);
}
