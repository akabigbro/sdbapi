#ifndef DOUBLE_H
#define DOUBLE_H

#include "field.h"

namespace DB
{

    class Double : public Field
    {
        private:
            double value;
        protected:
            void setDouble(double data);
        public:
            Double(double value = 0.0f);
            ~Double(void);

            double getValue(void);
    };

};
#endif//DOUBLE_H
