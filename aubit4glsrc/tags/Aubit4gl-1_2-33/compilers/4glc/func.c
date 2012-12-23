#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"
#include "expr_munging.h"
#include "a4gl_API_sqlparsecmd.h"



int yylineno;
FILE *lintfile;
int nmods;
module_definition *m;


static char *decode_dtype(int n) {
static char buff[300];
switch (n&DTYPE_MASK) {
	case DTYPE_SERIAL: 	return "[INTEGER] ";
	case DTYPE_INT: 		return "[INTEGER] ";
	case DTYPE_SMINT: 	return "[INTEGER] ";
	case DTYPE_SMFLOAT: 	return "[FLOAT] ";
	case DTYPE_FLOAT: 	return "[FLOAT] ";
	case DTYPE_DECIMAL: 	return "[INTEGER] ";
	case DTYPE_MONEY: 	return "[INTEGER] ";
	case DTYPE_CHAR: 	return "[STRING] ";
	case DTYPE_VCHAR: 	return "[VARCHAR] ";
	case 90: 	return "[TRUE/FALSE] ";
}
sprintf(buff,"[%d] ",n);
return buff;
return "";
}
static int look_for_func(char *s) {
int modno;
int funcno;
int printed=0;
struct s_function_definition  *fdef;
int a;
    struct s_commands *func_cmds;
for (modno=0;modno<nmods;modno++) {
	for (funcno=0;funcno<m[modno].module_entries.module_entries_len;funcno++) {
    switch (m[modno].module_entries.module_entries_val[funcno]->met_type)
       {
       case E_MET_MAIN_DEFINITION:
				continue;

       case E_MET_FUNCTION_DEFINITION:
			fdef=&m[modno].module_entries.module_entries_val[funcno]->module_entry_u.function_definition;
			if (strcasecmp(fdef->funcname,s)!=0) continue;
			// Found it..

printf("#==========================================================================\n");
printf("# Function Name : %s\n", fdef->funcname);
printf("#\n");
if (fdef->expanded_parameters) {
printed=0;
printf("# Input Parameter(s):\n");


    func_cmds = linearise_commands (0, 0);
    linearise_commands (func_cmds, fdef->func_commands);


for (a=0;a<fdef->expanded_parameters->list.list_len;a++) {
	//char buff[2000];
	int dtype;
	dtype=expr_datatype("x",0,fdef->expanded_parameters->list.list_val[a])&DTYPE_MASK;


	printf("#    Name       : %s%s\n", decode_dtype(dtype), expr_as_string_when_possible(fdef->expanded_parameters->list.list_val[a]));
	printf("#    Description:\n");
	printed++;
}
	if (!printed) {
			printf("#           None\n");
	}
}
printf("#\n");
printed=0;
printf("# Output Parameter(s)\n");
for (a=0;a<func_cmds->cmds.cmds_len;a++) {
	if (func_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_RETURN_CMD) {
		int o;
			struct struct_return_cmd* r;
			r=&func_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.return_cmd;
			if (r->retvals==0) break;
			if (r->retvals->list.list_len==0) break;

			for (o=0;o<r->retvals->list.list_len;o++) {
					int dtype;
					dtype=expr_datatype("x",0,r->retvals->list.list_val[o])&DTYPE_MASK;

				printed++;
				printf("#    Name       : %s%s\n",decode_dtype(dtype),expr_as_string_when_possible(r->retvals->list.list_val[o]));
				printf("#    Description: \n");
			}
				// Only print the results of the first RETURN command...
			break;
	}
}
if (!printed) {
			printf("#           None\n");
}
printf("#\n");
printf("# Description   :\n");
printf("#==========================================================================\n");

         break;


		default:
				break;
		}
	}
}
return 0;
}

int
main (int argc, char *argv[])
{
  int a;
  int ok=0;
  char *funcname=0;
  A4GL_build_user_resources ();
  nmods=0;
  m = malloc (sizeof (struct module_definition) * (argc - 1));

  for (a=1;a<argc;a++) {
  		char buff[2000];
      sprintf (buff, "%s", argv[a]);
      if (strstr (buff, ".dat") != 0) {
	  			char *p;
	  			p = strstr (buff, ".dat");
	  			*p = 0;
		}
      //printf ("Loading %s\n", buff);
      //fflush (stdout);

      if (read_module_definition (&m[nmods], buff)) {
				ok++;
	  			//printf ("OK...%s\n", argv[b]);
				nmods++;
				//printf("OK\n");
		} else {
				if (funcname==0) {
					//printf("Set funcname to %s\n", argv[a]);
					funcname=argv[a];
				} else {
						printf("%s\n",buff);
						fprintf(stderr,"Invalid parameters or modules failed to load\n");
						exit(2);
				}


		}
  }

  if (funcname) {
		look_for_func(funcname);
	}
  return 0;
}





char *dtype_as_string(int n) {
return "x";
}


expr_str *
get_cached_expr_datatype (int n) {
A4GL_assertion(1,"Failed");

return 0;
}

int find_function_single_rtype(char *funcname,char *module,int lineno) {
return 0;
}

void A4GL_lint(char *module_in, int lintline, char *code, char *type, char *extra) {

}
