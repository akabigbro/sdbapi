#ifndef SQLTIME_H
#define SQLTIME_H

#include "field.h"
#include <time.h>

namespace DB
{

    class SqlTime : public Field
    {
        private:
            struct tm value;
        protected:
            void setDateTime(struct tm * data);
        public:
            SqlTime(struct tm * value);
            ~SqlTime(void);

            struct tm * getValue(void);
    };

};

#endif//SQLTIME_H
