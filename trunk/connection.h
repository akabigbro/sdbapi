#ifndef CONNECTION_H
#define CONNECTION_H

#include "environment.h"
#include "result.h"

namespace DB
{

    class Connection : public Environment
    {
        private:
            SQLRETURN error;
            SQLHDBC hdbc;
        public:
            Connection(void) throw(SQLRETURN&);
            ~Connection(void);

            void Connect(std::string server, std::string user, std::string password) throw(SQLRETURN&);
            Result * Execute(std::string query) throw(SQLRETURN&);
    };

};

#endif//CONNECTION_H
