#ifndef SQLDOUBLE_H
#define SQLDOUBLE_H

#include "sqlfield.h"

namespace DB
{

    class SqlDouble : public SqlField
    {
        private:
            double value;
        protected:
            void setDouble(double data);
        public:
            SqlDouble(double value = 0.0f);
            ~SqlDouble(void);

            double getValue(void);
    };

};
#endif//SQLDOUBLE_H
