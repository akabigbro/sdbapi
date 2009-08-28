#ifndef FIELD_H
#define FIELD_H

#include "dbinfo.h"

/*

Type identifier     ODBC typedef        C typedef
-------------------+-------------------+-----------------------
SQL_C_CHAR          SQLCHAR *           unsigned char *
SQL_C_SSHORT        SQLSMALLINT         short int
SQL_C_USHORT        SQLUSMALLINT        unsigned short int
SQL_C_SLONG         SQLINTEGER          long int
SQL_C_FLOAT         SQLREAL             float
SQL_C_DOUBLE        SQLDOUBLE,SQLFLOAT  double
SQL_C_BINARY        SQLCHAR *           unsigned char
SQL_C_TYPE_DATE     SQL_DATE_STRUCT     struct
                                        tagDATE_STRUCT {
                                            SQLSMALLINT year;
                                            SQLUSMALLINT month;
                                            SQLUSMALLINT day;
                                        } DATE_STRUCT;
SQL_C_TYPE_TIME     SQL_TIME_STRUCT     struct
                                        tagTIME_STRUCT {
                                            SQLUSMALLINT hour;
                                            SQLUSMALLINT minute;
                                            SQLUSMALLINT second;
                                        } TIME_STRUCT; 

*/

namespace DB
{

    class Field
    {
        private:
            int type;
        protected:
            void setType(int type);

            virtual void setString(const char * data);
            virtual void setShortInt(short int data);
            virtual void setUShortInt(unsigned short int data);
            virtual void setLongInt(long int data);
            virtual void setFloat(float data);
            virtual void setDouble(double data);
            virtual void setBinary(unsigned char * data);
            virtual void setDateTime(struct tm * data);
        public:
            Field(int type);
            virtual ~Field(void);

            void setValue(SQLCHAR * data);
            void setValue(SQLSMALLINT data);
            void setValue(SQLUSMALLINT data);
            void setValue(SQLINTEGER data);
            void setValue(SQLREAL data);
            void setValue(SQLDOUBLE data);
            void setValue(SQL_DATE_STRUCT * data);
            void setValue(SQL_TIME_STRUCT * data);
    };

};

#endif//FIELD_H
