#ifndef RESULT_H
#define RESULT_H

#include "statement.h"
#include "recordset.h"

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

            RecordSet * getRecordSet(void);
    };

};

#endif//RESULT_H
