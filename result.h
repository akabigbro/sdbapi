#ifndef RESULT_H
#define RESULT_H

#include "dbinfo.h"

namespace DB
{

    class Result
    {
        private:
            SQLRETURN error;
            SQLHSTMT handle;
        protected:
            SQLHSTMT & getStatementHandle(void);
        public:
            Result(SQLHSTMT handle);
            ~Result(void);

            int getRowCount(void) throw(SQLRETURN&);
            int getColumnCount(void) throw(SQLRETURN&);
    };

};

#endif//RESULT_H
