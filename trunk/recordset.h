#ifndef RECORDSET_H
#define RECORDSET_H

#include "statement.h"

namespace DB
{

    class RecordSet
    {
        private:
            SQLRETURN error;
            Statement * statement;
        public:
            RecordSet(Statement * statement);
            ~RecordSet(void);

            void Next(void) throw(SQLRETURN&);
            void Prior(void) throw(SQLRETURN&);
            void First(void) throw(SQLRETURN&);
            void Last(void) throw(SQLRETURN&);
            void Absolute(int index) throw(SQLRETURN&);
            void Relative(int offset) throw(SQLRETURN&);
    };

};

#endif//RECORDSET_H
