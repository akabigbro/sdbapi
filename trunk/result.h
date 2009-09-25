#ifndef RESULT_H
#define RESULT_H

#include "statement.h"

namespace DB
{

    class Result
    {
        private:
            SQLRETURN error;
            Statement * statement;
        public:
            Result(Statement * statement);
            ~Result(void);

            int getRowCount(void) throw(SQLRETURN&);
            int getColumnCount(void) throw(SQLRETURN&);
    };

};

#endif//RESULT_H
