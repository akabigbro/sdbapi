#include "environment.h"

using namespace DB;

SQLHENV & Environment::getEnvironmentHandle(void)
{
    return henv;
}

Environment::Environment(void) throw(SQLRETURN&)
{
    // get odbc environment henv
    error = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

    if (!DBInfo::CheckReturn(SQL_HANDLE_ENV, henv, error))
    {
        throw error;
    }

    // set the environment to ODBCv3
    error = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

    if (!DBInfo::CheckReturn(SQL_HANDLE_ENV, henv, error))
    {
        throw error;
    }
}

Environment::~Environment(void)
{
    SQLFreeHandle(SQL_HANDLE_ENV, henv);
}
