#ifndef COLUMNDESC_H
#define COLUMNDESC_H

#include "dbinfo.h"

#ifndef MAX_NAME_SIZE
#define MAX_NAME_SIZE 128
#endif//MAX_NAME_SIZE

namespace DB
{

    class ColumnDesc
    {
        public:
            char name[MAX_NAME_SIZE];
            SQLSMALLINT nameLength;
            SQLSMALLINT dataType;
            SQLULEN columnSize;
            SQLSMALLINT decimalDigits;
            SQLSMALLINT nullable;
    };

};

#endif//COLUMNDESC_H
