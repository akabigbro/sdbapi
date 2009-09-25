#ifndef STATEMENT_H
#define STATEMENT_H

#include "dbinfo.h"

namespace DB
{

    class Statement
    {
        protected:
            SQLRETURN error;
            SQLHSTMT hstmt;
        public:
            Statement(SQLHDBC hdbc) throw(SQLRETURN&);
            ~Statement(void);
    
            void Execute(std::string query) throw(SQLRETURN&);
            int getRowCount(void) throw(SQLRETURN&);
            int getColumnCount(void) throw(SQLRETURN&);
    };

};

#endif//STATEMENT_H
