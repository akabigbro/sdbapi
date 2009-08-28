#ifndef SQLINTEGER_H
#define SQLINTEGER_H

#include "field.h"

namespace DB
{
    
    class SqlInteger : public Field
    {
        private:
            long int value;
        protected:
            void setLongInt(long int data);
        public:
            SqlInteger(long int value = 0);
            ~SqlInteger(void);

            long int getValue(void);
    };

};

#endif//SQLINTEGER_H
