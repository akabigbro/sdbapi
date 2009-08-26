#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

namespace DB
{

    class Error
    {
        public:
            static void Output(SQLSMALLINT type, SQLHANDLE & handle);
    };

};

#endif//ERROR_H
