#ifndef SQLUSHORT_H
#define SQLUSHORT_H

#include "sqlfield.h"

namespace DB
{

    class SqlUShort : public SqlField
    {
        private:
            unsigned short int value;
        protected:
            void setUShortInt(unsigned short int value);
        public:
            SqlUShort(unsigned short int value = 0);
            ~SqlUShort(void);

            unsigned short int getValue(void);
    };

};

#endif//SQLUSHORT_H
