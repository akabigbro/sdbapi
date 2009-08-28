#include "dbinfo.h"

using namespace DB;

bool DBInfo::CheckReturn(SQLSMALLINT type, SQLHANDLE & handle, SQLRETURN result)
{
    bool check = true;

    switch (result)
    {
        case SQL_SUCCESS:
            check = true;
            break;
        case SQL_SUCCESS_WITH_INFO:
            Output(type, handle);
            check = true;
            break;
        case SQL_STILL_EXECUTING:
            std::cout << "still executing" << std::endl;
            break;
        case SQL_ERROR:
            Output(type, handle);
            check = false;
            break;
        case SQL_INVALID_HANDLE:
            std::cerr << "invalid handle" << std::endl;
            check = false;
            break;
    }

    return check;
}

void DBInfo::Output(SQLSMALLINT type, SQLHANDLE & handle)
{
    SQLINTEGER index = 0;
    SQLINTEGER native;
    SQLCHAR state[7];
    SQLCHAR text[256];
    SQLSMALLINT len;
    SQLRETURN result;

    do
    {
        result = SQLGetDiagRec(type, handle, ++index, state, &native, text, sizeof(text), &len);

        if (SQL_SUCCEEDED(result))
        {
            std::cerr << state << ":" << index << ":" << native << ":" << text << std::endl;
        }
    }
    while (SQL_SUCCESS == result);
}
