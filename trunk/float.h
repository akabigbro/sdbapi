#ifndef FLOAT_H
#define FLOAT_H

#include "field.h"

namespace DB
{

    class Float : public Field
    {
        private:
            float value;
        protected:
            void setFloat(float data);
        public:
            Float(float value = 0.0f);
            ~Float(void);

            float getValue(void);
    };

};

#endif//FLOAT_H
