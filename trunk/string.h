#ifndef STRING_H
#define STRING_H

#include <string>
#include "field.h"

namespace DB
{

    class String : public Field
    {
        private:
            std::string value;
        protected:
            void setString(const char * data);
        public:
            String(const char * value = "");
            ~String(void);

            std::string getValue(void);
    };

};

#endif//STRING_H
