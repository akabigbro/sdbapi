#ifndef STATEMENT_H
#define STATEMENT_H

#include "connection.h"

namespace DB
{

    class Statement
    {
        private:
            SQLRETURN error;
            SQLHSTMT handle;

            void Initialize(SQLHDBC & connection) throw(SQLRETURN&);
        protected:
            SQLHSTMT & getStatementHandle(void);
        public:
            ~Statement(void);

            int Execute(SQLCHAR * statement) throw(SQLRETURN&);
            int getRowCount(void) throw(SQLRETURN&);

            friend class Connection;
    };

};

#endif//STATEMENT_H
