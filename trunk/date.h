#ifndef DATE_H
#define DATE_H

#include "field.h"

namespace DB
{

    class Date : public Field
    {
        private:
            struct tm value;
        protected:
            void setDateTime(struct tm * data);
        public:
            Date(struct tm * value);
            ~Date(void);

            struct tm * getValue(void);
    };

};

#endif//DATE_H
