#ifndef USHORT_H
#define USHORT_H

#include "field.h"

namespace DB
{

    class UShort : public Field
    {
        private:
            unsigned short int value;
        protected:
            void setUShortInt(unsigned short int value);
        public:
            UShort(unsigned short int value = 0);
            ~UShort(void);

            unsigned short int getValue(void);
    };

};

#endif//USHORT_H
