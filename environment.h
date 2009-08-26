#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "error.h"

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

            virtual void OutputError(void);
    };

};

#endif//ENVIRONMENT_H
