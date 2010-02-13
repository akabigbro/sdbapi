#include "statement.h"

using namespace DB;

ColumnDesc & Statement::getColumnDesc(SQLSMALLINT column) throw(SQLRETURN&)
{
    error = SQLDescribeCol(hstmt, column, (SQLCHAR *) desc.name, MAX_NAME_SIZE, &desc.nameLength, &desc.dataType, &desc.columnSize, &desc.decimalDigits, &desc.nullable);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    return desc;
}

Statement::Statement(Statement & statement)
    : hstmt(statement.hstmt)
{
}

Statement::Statement(SQLHDBC hdbc) throw(SQLRETURN&)
{
    error = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }
}

Statement::~Statement(void)
{
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
}

bool Statement::MoreResults(void) throw(SQLRETURN&)
{
    error = SQLMoreResults(hstmt);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    return (SQL_NO_DATA != error);
}

void Statement::MoveCursor(SQLSMALLINT orientation, SQLLEN offset) throw(SQLRETURN&)
{
    error = SQLFetchScroll(hstmt, orientation, offset);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }
}

void Statement::Execute(std::string query) throw(SQLRETURN&)
{
    error = SQLExecDirect(hstmt, (SQLCHAR *)query.c_str(), SQL_NTS);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }
}

int Statement::getRowCount(void) throw(SQLRETURN&)
{
    SQLLEN count;

    error = SQLRowCount(hstmt, &count);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    return count;
}

int Statement::getColumnCount(void) throw(SQLRETURN&)
{
    SQLSMALLINT count;

    error = SQLNumResultCols(hstmt, &count);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    return count;
}

std::string Statement::getColumnName(int column) throw(SQLRETURN&)
{
    return getColumnDesc(column).name;
}

std::string Statement::getString(int column) throw(SQLRETURN&)
{
    int size = getColumnDesc(column).columnSize;

    char data[size];
    for (int ch = 0; ch < size; ch++) data[ch] = 0;
    SQLLEN def;

    error = SQLGetData(hstmt, column, SQL_C_CHAR, &data, size, &def);

    if (!DBInfo::CheckReturn(SQL_HANDLE_STMT, hstmt, error))
    {
        throw error;
    }

    if (SQL_NULL_DATA == def)
    {
        return "<NULL>";
    }
    else
    {
        return data;
    }
}
