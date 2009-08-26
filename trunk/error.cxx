#include "error.h"

using namespace DB;

void Error::Output(SQLSMALLINT type, SQLHANDLE & handle)
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
            fprintf(stderr, "%s:%ld:%ld:%s\n", state, index, native, text);
        }
    }
    while (SQL_SUCCESS == result);
}
