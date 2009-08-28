#ifndef TIME_H
#define TIME_H

#include "field.h"

namespace DB
{

    class Time : public Field
    {
        private:
            struct tm value;
        protected:
            void setDateTime(struct tm * data);
        public:
            Time(struct tm * value);
            ~Time(void);

            struct tm * getValue(void);
    };

};

#endif//TIME_H
