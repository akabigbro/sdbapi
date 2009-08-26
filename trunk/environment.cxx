#include "environment.h"

using namespace DB;

SQLHENV & Environment::getEnvironmentHandle(void)
{
    return handle;
}

Environment::Environment(void) throw(SQLRETURN&)
{
    // get odbc environment handle
    error = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &handle);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }

    // set the environment to ODBCv3
    error = SQLSetEnvAttr(handle, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

    if (SQL_SUCCESS != error && SQL_SUCCESS_WITH_INFO != error)
    {
        throw error;
    }
}

Environment::~Environment(void)
{
    SQLFreeHandle(SQL_HANDLE_ENV, handle);
}

void Environment::OutputError(void)
{
    Error::Output(SQL_HANDLE_ENV, handle);
}