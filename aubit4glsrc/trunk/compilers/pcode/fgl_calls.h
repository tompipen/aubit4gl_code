#include "a4gl_incl_4glhdr.h"
extern long int_flag;
extern long quit_flag;
extern long a4gl_status;
extern struct
{
  long sqlcode;
  char sqlerrm[72 + 1];
  char sqlerrp[8 + 1];
  long sqlerrd[6];
  char sqlawarn[8 + 1];
  char sqlstate[9 + 1];
}
a4gl_sqlca;
extern char user[8 + 1];
extern long pageno;
extern long lineno;
//extern long today;
extern long usrtime;
extern long curr_hwnd;
extern long curr_form;
extern char err_file_name[32 + 1];
extern long err_file_no;
extern char curr_file_name[32 + 1];
extern long curr_line_no;
extern long err_status;
extern long aiplib_status;



struct call_funcs system_funcs[]={
	{ &A4GLSQL_set_status,			"A4GLSQL_set_status",			"044"},
	{ &A4GLSTK_initFunctionCallStack,	"A4GLSTK_initFunctionCallStack",	"0"},
	{ &A4GLSTK_pushFunction,		"A4GLSTK_pushFunction",			"0444"},
	{ &A4GLSTK_popFunction,			"A4GLSTK_popFunction",			"0"},
	{ &A4GLSTK_setCurrentLine,		"A4GLSTK_setCurrentLine",		"044"},
	{ &A4GL_add_menu_option,		"A4GL_add_menu_option",			"0444444"},
	{ &A4GL_chk_err,			"A4GL_chk_err",				"044"},
	{ &A4GL_cr_window,			"A4GL_cr_window",			"44444444444"},
	{ &A4GL_cr_window_form,			"A4GL_cr_window_form",			"44444444444"},
	{ &A4GL_disp_fields,			"A4GL_disp_fields",			"044V"},
	{ &A4GL_disp_h_menu,			"A4GL_disp_h_menu",			"44"},
	{ &A4GL_display_at,			"A4GL_display_at",			"044"},
	{ &A4GL_display_error,			"A4GL_display_error",			"044"},
	{ &A4GL_fgl_end_4gl_0,			"A4GL_fgl_end_4gl_0",			"0"},
	{ &A4GL_fgl_start,			"A4GL_fgl_start",			"044"},
	{ &A4GL_finish_create_menu,		"A4GL_finish_create_menu",		"04"},
	{ &A4GL_free_menu,			"A4GL_free_menu",			"44"},
	{ &A4GL_pop_args,			"A4GL_pop_args",			"04"},
	{ &A4GL_pop_params,			"A4GL_pop_params",			"044"},
	{ &A4GL_pop_var,			"A4GL_pop_var",				"444"},
	{ &A4GL_pop_var2,			"A4GL_pop_var2",			"4444"},
	{ &A4GL_push_char,			"A4GL_push_char",			"04"},
	{ &A4GL_push_int,			"A4GL_push_int",			"02"},
	{ &A4GL_push_long,			"A4GL_push_long",			"04"},
	{ &A4GL_push_variable,			"A4GL_push_variable",			"044"},
	{ &A4GL_pushop,				"A4GL_pushop",				"04"},
	{ &A4GL_remove_window,			"A4GL_remove_window",			"04"},
	{ &A4GL_set_help_file,			"A4GL_set_help_file",			"04"},
	{ &A4GL_set_option_value,		"A4GL_set_option_value",		"014"},
	{ &A4GL_sleep_i,			"A4GL_sleep_i",				"0"},
	{ &A4GL_start_prompt,			"A4GL_start_prompt",			"444444"},
	{ &aclfgli_clr_err_flg,			"aclfgli_clr_err_flg",			"0"},
	{ &aclfgli_get_err_flg,			"aclfgli_get_err_flg",			"4"},


	{ &printf,				"printf",				0},  // Just for testing
{0,0,0} 
};


void init_calls(int argc,char *argv[]) {
   A4GL_fgl_start(argc,argv);
}


void *resolve_externs(char *name) {
	      if (strcmp (name, "a4gl_sqlca") == 0) { return &a4gl_sqlca; }
	      if (strcmp (name, "int_flag") == 0) { return &int_flag; }
	      if (strcmp (name, "quit_flag") == 0) { return &quit_flag; }
	      if (strcmp (name, "a4gl_status") == 0) { return &a4gl_status; }
	      if (strcmp (name, "today") == 0) { return 0; }
	      if (strcmp (name, "user") == 0) { return 0; }
	      if (strcmp (name, "pageno") == 0) { return 0; }
	      if (strcmp (name,"lineno") == 0) { return 0; }
	      if (strcmp (name, "usrtime") == 0) { return 0; }
	      if (strcmp (name, "curr_hwnd") == 0) { return 0; }
	      if (strcmp (name, "curr_form") == 0) { return 0; }
	      if (strcmp (name, "err_file_name") == 0) { return 0; }
	      if (strcmp (name, "err_file_no") == 0) { return 0; }
	      if (strcmp (name, "curr_file_name") == 0) { return 0; }
	      if (strcmp (name, "curr_line_no") == 0) { return 0; }
	      if (strcmp (name, "err_status") == 0) { return 0; }
	      if (strcmp (name, "aiplib_status") == 0) { return 0; }
	return -1;
}
