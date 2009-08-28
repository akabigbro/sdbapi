#ifndef SHORT_H
#define SHORT_H

#include "field.h"

namespace DB
{

    class Short : public Field
    {
        private:
            short int value;
        protected:
            void setShortInt(short int data);
        public:
            Short(short int value = 0);
            ~Short(void);

            short int getValue(void);
    };

};

#endif//SHORT_H
