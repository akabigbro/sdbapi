#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "dbinfo.h"

namespace DB
{

    class Environment
    {
        private:
            SQLRETURN error;
            SQLHENV handle;
        protected:
            SQLHENV & getEnvironmentHandle(void);
        public:
            Environment(void) throw(SQLRETURN&);
            ~Environment(void);
    };

};

#endif//ENVIRONMENT_H
