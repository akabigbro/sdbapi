#ifndef INTEGER_H
#define INTEGER_H

#include "field.h"

namespace DB
{
    
    class Integer : public Field
    {
        private:
            long int value;
        protected:
            void setLongInt(long int data);
        public:
            Integer(long int value = 0);
            ~Integer(void);

            long int getValue(void);
    };

};

#endif//INTEGER_H
