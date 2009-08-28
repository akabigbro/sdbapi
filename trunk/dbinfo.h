#ifndef DBINFO_H
#define DBINFO_H

#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

namespace DB
{

    class DBInfo
    {
        public:
            static void Output(SQLSMALLINT type, SQLHANDLE & handle);
    };

};

#endif//DBINFO_H
