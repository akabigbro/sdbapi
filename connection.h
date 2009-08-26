#ifndef CONNECTION_H
#define CONNECTION_H

#include "environment.h"

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

            void Connect(SQLCHAR * server, SQLCHAR * user, SQLCHAR * password) throw(SQLRETURN&);
            void OutputError(void);
    };

};

#endif//CONNECTION_H
