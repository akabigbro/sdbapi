#ifndef SQLDATE_H
#define SQLDATE_H

#include "sqlfield.h"
#include <time.h>

namespace DB
{

    class SqlDate : public SqlField
    {
        private:
            struct tm value;
        protected:
            void setDateTime(struct tm * data);
        public:
            SqlDate(struct tm * value);
            ~SqlDate(void);

            struct tm * getValue(void);
    };

};

#endif//SQLDATE_H
