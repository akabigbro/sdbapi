#include "fielddesc.h"

using namespace DB;

FieldDesc::FieldDesc(SQLCHAR * name, SQLSMALLINT type, SQLULEN size, SQLSMALLINT decimal, SQLSMALLINT nullable)
    : name(name), type(type)
