#ifndef SQLSTRING_H
#define SQLSTRING_H

#include <string>
#include "field.h"

namespace DB
{

    class SqlString : public Field
    {
        private:
            std::string value;
        protected:
            void setString(const char * data);
        public:
            SqlString(const char * value = "");
            ~SqlString(void);

            std::string getValue(void);
    };

};

#endif//SQLSTRING_H
