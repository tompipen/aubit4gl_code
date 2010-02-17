/* 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"
#include "expr_munging.h"

int yylineno;
//module_definition this_module;

#define MAXFUNCTIONS 20000
char *whitelist[MAXFUNCTIONS];
int nwhitelist=0;

int added=0;



static void addToWhitelist(char *s) {
	whitelist[nwhitelist++]=strdup(s);
	added++;
	
}

static void addAllToWhitelist(module_definition *m) {
int b;
      for (b = 0; b < m->module_entries.module_entries_len; b++)
	{
	  switch (m->module_entries.module_entries_val[b]->met_type)
	    {
	    case E_MET_FUNCTION_DEFINITION:
		addToWhitelist(m->module_entries.module_entries_val[b]->module_entry_u.function_definition.funcname);
	      break;

	    case E_MET_REPORT_DEFINITION:
		addToWhitelist(m->module_entries.module_entries_val[b]->module_entry_u.report_definition.funcname);

	      break;

	    case E_MET_PDF_REPORT_DEFINITION:
		addToWhitelist(m->module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.funcname);
	      break;

		default: break;
	   }
        }

}

static int isOnWhiteList(char *s) {
int a;
for (a=0;a<nwhitelist;a++) {
	if (strcmp(whitelist[a],s)==0) return 1;
}
return 0;
}

static int isSystemFunc(char *funcname) {

// Dont return anything
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_add_keymap") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_closeiem") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_dump_screen") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_load_datatype") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_run_gui") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_set_page") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_show_help") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_dump_screen") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_fetchiem") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_curr_height") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_curr_width") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_user") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_libhelp_showhelp") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_openiem") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_random") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_read_pipe") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_set_color") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_setenv") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_scr_size") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getkey_wait") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_keysetlabel") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddeconnect") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddeexecute") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddefinish") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddefinishall") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddegeterror") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddepeek") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "ddepoke") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "err_print") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "err_quit") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "errorlog") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_setbuffer") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_setcurrline") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_setkeylabel") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_prtscr") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_set_arrline") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_set_scrline") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_setkeylabel") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_strtosend") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_winmessage") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_drawbox") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "set_count") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "showhelp") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "startlog") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_send_to_ui") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_settitle") == 0)
    return 1;

  if (A4GL_aubit_strcasecmp (funcname, "fgl_fglgui") == 0)
    return 2;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_winbutton") == 0)
    return 2;


// INTs
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_sendfile_to_ui") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "length") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "weekday") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "year") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "arr_count") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "arr_curr") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "day") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "length") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "month") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_winmessage") == 0)
    return 1; 

  if (A4GL_aubit_strcasecmp (funcname, "winexec") == 0)
    return 1;


  if (A4GL_aubit_strcasecmp (funcname, "mdy") == 0)
    return 1;

  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_info") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_page") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_ui_mode") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "arg_val") == 0)
    return 1;



  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_byte_as_str") == 0)
    return 1;



  if (A4GL_aubit_strcasecmp (funcname, "ascii") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "date") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "dbms_dialect") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "downshift") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "err_get") == 0)
    return 1;

  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_expand_env_vars_in_cmdline") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_buffertouched") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_compare") == 0)
    return 1;

  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_getbuffer") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_getfieldname") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getenv") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getkey") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_keyval") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_lastkey") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_round") == 0)
    return 1;


  if (A4GL_aubit_strcasecmp (funcname, "ord") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "num_args") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "scr_line") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "upshift") == 0)
    return 1;



  if (A4GL_aubit_strcasecmp (funcname, "abs") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (funcname, "sqrt") == 0)
    return 1;

	return 0;
}

static int chk_is_external(module_definition *m, char *fname) {
int b;

      if (isSystemFunc(fname)) {
		return 0;
	}

	if (isOnWhiteList(fname)) {
		return 0;
	}

      for (b = 0; b < m->module_entries.module_entries_len; b++)
	{
	  switch (m->module_entries.module_entries_val[b]->met_type)
	    {
	    case E_MET_MAIN_DEFINITION:
		if (strcasecmp(fname,"main")==0) return 0;

	      break;

	    case E_MET_FUNCTION_DEFINITION:
		if (strcasecmp(fname, m->module_entries.module_entries_val[b]->module_entry_u.function_definition.funcname)==0) return 0;

	      break;

	    case E_MET_REPORT_DEFINITION:
		if (strcasecmp(fname, m->module_entries.module_entries_val[b]->module_entry_u.report_definition.funcname)==0) return 0;

	      break;

	    case E_MET_PDF_REPORT_DEFINITION:
		if (strcasecmp(fname, m->module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.funcname)==0) return 0;
	      break;
		default: break;
	   }
        }

	printf("External function : %s\n",fname);
	return 1;

}

// Returns the number of external function calls...
static int
add_function (module_definition *m, int module_no, char *module, int line, char *fname, char forr, void *ptr,int isInLibrary,  s_call_list * call_list)
{
int a;
  struct s_expr_function_call *fcall;
int cnt=0;
  for (a = 0; a < call_list->calls_by_expr.calls_by_expr_len; a++)
    {
      switch (call_list->calls_by_expr.calls_by_expr_val[a]->expr_type)
        {
        case ET_EXPR_FCALL:
          fcall = call_list->calls_by_expr.calls_by_expr_val[a]->expr_str_u.expr_function_call;
          cnt+=chk_is_external (m,fcall->fname);
          break;

	default:
		printf("Unhandled call type\n");
		exit(2);
	}
    }

   return cnt;
}


static int all_internal_functions(module_definition *mods,int a) {
int b;
int bad=0;
      for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	{
	  switch (mods[a].module_entries.module_entries_val[b]->met_type)
	    {
	    case E_MET_MAIN_DEFINITION:
		return 0; // We dont want to include any "MAINs" in our library - regardless...

		/*
	      bad+=add_function (&mods[a], a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno,
			    "MAIN", 'F', &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition, mods[a].moduleIsInLibrary,
 				&mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.call_list
				);
		*/
	      break;

	    case E_MET_FUNCTION_DEFINITION:
	      bad+=add_function (&mods[a], a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.funcname,
			    'F', &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition, mods[a].moduleIsInLibrary,
 				&mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.call_list
				);
	      break;

	    case E_MET_REPORT_DEFINITION:
	      bad+=add_function (&mods[a], a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.funcname,
			    'R', &mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition, mods[a].moduleIsInLibrary,
 				&mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.call_list
		);
	      break;

	    case E_MET_PDF_REPORT_DEFINITION:
	      bad+=add_function (&mods[a], a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.funcname,
			    'P', &mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition, mods[a].moduleIsInLibrary,
 				&mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.call_list
				);
	      break;


	default: break;
	    }
        }

if (bad) {
	printf("%d external functions \n",bad);
	return 0;
}
return 1;
}

static void mklib_program(module_definition *m,int a) {
int n;
int *processed;
processed=malloc(sizeof(int)*a);

        for (n=0;n<a;n++) {
		processed[n]=0;
	}

	printf("Processing %d modules\n",a);

	while (1) {
		added=0;
		for (n=0;n<a;n++) {
			if (processed[n]==1) continue ; /* Already safe */

			if (all_internal_functions(m,n)) {
				processed[n]=1;
				printf("Safe to put into library : %s\n",m[n].module_name);
				addAllToWhitelist(&m[n]);
			}
		}
		if (!added) break; // No more added - so we're done...
	}

	for (n=0;n<a;n++) {
		if (processed[n]) {
			printf(":%s\n",m[n].module_name);
		}
	}
}


int
main (int argc, char *argv[])
{
  module_definition *m;
  int a=0;
  int b;

  A4GL_build_user_resources ();

  //ignore_user_function(NULL);
  m = malloc (sizeof (struct module_definition) * (argc ));


  for (b=1;b<argc;b++) {
	char buff[2000];
      sprintf (buff, "%s", argv[b]);
      if (strstr (buff, ".dat") != 0)
	{
	  char *p;
	  p = strstr (buff, ".dat");
	  *p = 0;
	}
      printf ("Loading %s : ", buff);
      fflush (stdout);
      if (read_module_definition (&m[a++], buff))
	{
	  printf ("OK...%s\n", argv[b]);
	}
      else
	{
	  printf ("- Failed to load %s\n", argv[b]);
	  exit (1);
	}
    }

  mklib_program (m, a);
  return 0;
}





