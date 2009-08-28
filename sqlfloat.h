#ifndef SQLFLOAT_H
#define SQLFLOAT_H

#include "sqlfield.h"

namespace DB
{

    class SqlFloat : public SqlField
    {
        private:
            float value;
        protected:
            void setFloat(float data);
        public:
            SqlFloat(float value = 0.0f);
            ~SqlFloat(void);

            float getValue(void);
    };

};

#endif//SQLFLOAT_H
