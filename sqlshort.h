#ifndef SQLSHORT_H
#define SQLSHORT_H

#include "field.h"

namespace DB
{

    class SqlShort : public Field
    {
        private:
            short int value;
        protected:
            void setShortInt(short int data);
        public:
            SqlShort(short int value = 0);
            ~SqlShort(void);

            short int getValue(void);
    };

};

#endif//SQLSHORT_H
