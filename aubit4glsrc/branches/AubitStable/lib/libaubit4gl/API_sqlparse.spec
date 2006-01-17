LIBRARY SQLPARSE
VARIABLE A4GL_SQLDIALECT
LIB_PREFIX A4GLPARSE_

#ifdef DEBUG_SPEC
#undef DEBUG_SPEC
#endif
A4GLSQLCV_convert_sql_ml   char* target_dialect  char* sql char* module int ln -> char*
A4GLSQLCV_convert_file  char* target_dialect  char* sql -> char*
