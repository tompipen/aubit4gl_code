
#include "a4gl_4glc_int.h"
extern int compiling_system_4gl ;


void
A4GL_set_pragma (module_definition * this_module, enum e_pragmas pragma_type, char *str_value, char *str_value2,int set_from_globals)
{
  char buff[3000];
  int count;

// 
//  Dont forget to edit "read_glob" in globals.c if we add any more...
//

  switch (pragma_type)
    {

    case E_PRAGMA_SYSTEM_4GL:
      compiling_system_4gl = 1;
      count = 0;
      break;
    case E_PRAGMA_SQL_FEATURE:
      add_feature (upshift (str_value));
      count = 1;
      break;
    case E_PRAGMA_EMULATE_INSERT_CURSOR_FOR:
      emulate_insert (this_module, str_value);
      count = 1;
      break;
    case E_PRAGMA_COLUMN_IS_SERIAL:
      add_serial_column (str_value, str_value2);
      count = 2;
      break;
    case E_PRAGMA_REPLACE_STRING:
      add_replace (str_value, str_value2);
      count = 2;
      break;
    case E_PRAGMA_STOP_REPLACE_STRING:
      drop_replace (str_value);
      count = 1;
      break;
    case E_PRAGMA_IGNORE_FUNCTION:
      A4GL_add_pointer (str_value, FUNCTION_IGNORE, (void *) 1);
      count = 1;
      break;
    case E_PRAGMA_FORCE_UI:
      set_force_ui (A4GL_strip_quotes (str_value));
      count = 1;
      break;
    case E_PRAGMA_DEBUG_FILE:
      set_debug_filename (A4GL_strip_quotes (str_value));
      count = 1;
      break;
    case E_PRAGMA_NOSQLCLOBBER:
      A4GL_setenv ("A4GL_NOSQLCLOBBER", "Y", 1);
      count = 0;
      break;
    case E_PRAGMA_NOCLOBBER:
      A4GL_setenv ("A4GL_NOCLOBBER", "Y", 1);
      count = 0;
      break;
    case E_PRAGMA_ALWAYSSQLCLOBBER:
      A4GL_setenv ("A4GL_NOSQLCLOBBER", "N", 1);
      count = 0;
      break;
    case E_PRAGMA_ALWAYSCLOBBER:
      A4GL_setenv ("A4GL_NOCLOBBER", "N", 1);
      count = 0;
      break;
    case E_PRAGMA_LINTMODULEISLIBRARY:
      setIsLibraryModule (1);
      count = 0;
      break;
    case E_PRAGMA_SET_POSTGRESQL_SEARCH_PATH:
      sprintf (buff, "set search_path to %s", A4GL_strip_quotes (str_value));
      A4GL_add_prepare ("A4GLssp", (void *) A4GL_prepare_select (0, 0, 0, 0, buff, "compiler", 2, 1, 1));
      A4GL_execute_sql ("A4GLssp", 0, 0);
      A4GLSQL_set_sqlca_sqlcode (0);
      count = 1;
      break;
    }


if (!set_from_globals) {
this_module->pragmas.pragmas_len++;
this_module->pragmas.pragmas_val=realloc(this_module->pragmas.pragmas_val, sizeof(this_module->pragmas.pragmas_val[0])*this_module->pragmas.pragmas_len);
this_module->pragmas.pragmas_val[this_module->pragmas.pragmas_len-1].pragma_type=pragma_type;

switch (count) {
	case 0:
		break;
	case 1: 	
		this_module->pragmas.pragmas_val[this_module->pragmas.pragmas_len-1].u_pragmas_u.string_value=strdup(str_value);
		break;
	case 2: 	
		this_module->pragmas.pragmas_val[this_module->pragmas.pragmas_len-1].u_pragmas_u.two_string_value.string1=strdup(str_value);
		this_module->pragmas.pragmas_val[this_module->pragmas.pragmas_len-1].u_pragmas_u.two_string_value.string1=strdup(str_value2);
		break;
}
}
}



