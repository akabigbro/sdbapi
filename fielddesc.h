#ifndef FIELDDESC_H
#define FIELDDESC_H

#include "field.h"

namespace DB
{
    class FieldDesc
    {
        private:
            SQLCHAR * name;
            SQLSMALLINT type;
            SQLULEN size;
            SQLSMALLINT decimal;
            SQLSMALLINT nullable;
        public:
            FieldDesc(SQLCHAR * name, SQLSMALLINT type, SQLULEN size, SQLSMALLINT decimal, SQLSMALLINT nullable);
            ~FieldDesc(void);

            SQLCHAR * getName(void);
            SQLSMALLINT getType(void);
            SQLULEN getSize(void);
            SQLSMALLINT getDecimal(void);
            SQLSMALLINT getNullable(void);
    };
};

#endif//FIELDDESC_H
