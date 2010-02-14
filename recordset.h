#ifndef RECORDSET_H
#define RECORDSET_H

#include <map>
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

            bool Fetch(void) throw(SQLRETURN&);
            bool Next(void) throw(SQLRETURN&);
            bool Prior(void) throw(SQLRETURN&);
            bool First(void) throw(SQLRETURN&);
            bool Last(void) throw(SQLRETURN&);
            bool More(void) throw(SQLRETURN&);

            std::map<std::string, std::string> getCurrent(void) throw(SQLRETURN&);
    };

};

#endif//RECORDSET_H
