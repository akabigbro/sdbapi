#ifndef STATEMENT_H
#define STATEMENT_H

#include "dbinfo.h"
#include "columndesc.h"

namespace DB
{

    class Statement
    {
        protected:
            SQLRETURN error;
            SQLHSTMT hstmt;
            ColumnDesc desc;

            ColumnDesc & getColumnDesc(SQLSMALLINT column) throw(SQLRETURN&);
        public:
            Statement(Statement & statement);
            Statement(SQLHDBC hdbc) throw(SQLRETURN&);
            ~Statement(void);
    
            bool MoreResults(void) throw(SQLRETURN&);
            void MoveCursor(SQLSMALLINT orientation, SQLLEN offset = 0) throw(SQLRETURN&);
            void Execute(std::string query) throw(SQLRETURN&);
            int getRowCount(void) throw(SQLRETURN&);
            int getColumnCount(void) throw(SQLRETURN&);
            std::string getColumnName(int column) throw(SQLRETURN&);
            std::string getString(int column) throw(SQLRETURN&);
    };

};

#endif//STATEMENT_H
