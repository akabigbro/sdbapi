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
            SQLHDBC handle;
        protected:
            SQLHDBC & getConnectionHandle(void);
        public:
            Connection(void) throw(SQLRETURN&);
            ~Connection(void);

            void Connect(const char * server, const char * user, const char * password) throw(SQLRETURN&);
            Result * Execute(const char * query) throw(SQLRETURN&);
    };

};

#endif//CONNECTION_H
