
#include "a4gl_4glc_int.h"
#include "variables.h"
#include <ctype.h>
#include "field_handling.h"
#include "parsehelp.h"
#include "a4gl_expr.h"

//#include "fgl.xs.h"
//#include <errno.h>


int yylineno=0;



main(int argc,char *argv[]) {
int ok;
	struct module_definition m;
	if (argc!=2) {
		int a;
		printf("Usage : reload <xmlfile>\n");
		printf("Got argc=%d\n",argc);
		for (a=0;a<argc;a++) {
			printf("Argv[%d]=%s\n", a,argv[a]);
		}
		exit(2);
	}

	ok=A4GL_read_data_from_file("module_definition",&m,argv[1]);
	if (ok)  {
		process_module(&m);
		exit(0);
	} else {
		printf("Failed to load file\n",ok);
		exit(11);
	}
exit(0);
}


int process_module (module_definition *loaded_module_definition) {
        int a;
	/*
        printf("Dbname :%s\n", loaded_module_definition->mod_dbname);
        printf("%d module variables\n", loaded_module_definition->module_variables.variables.variables_len);
	
       	printf("%d imported global variables\n", loaded_module_definition->imported_global_variables.variables.variables_len);
       	printf("%d exported global variables\n", loaded_module_definition->exported_global_variables.variables.variables_len);

	if (loaded_module_definition->global_files) {
        	for (a=0;a< loaded_module_definition->global_files->str_list_entry.str_list_entry_len;a++) {
                	printf("Global files %s\n",loaded_module_definition->global_files->str_list_entry.str_list_entry_val[a]);
        	}
	}
	*/

        for (a=0;a<loaded_module_definition->comment_list.comment_list_len;a++) {
                        loaded_module_definition->comment_list.comment_list_val[a].printed=0;
        }

        A4GL_write_generated_code(loaded_module_definition);

        return 1;
}


void A4GL_warn(char *s) {
	A4GL_debug("WARNING : %s\n",s);
}

void a4gl_yyerror(char *s) {
	printf("%s\n",s);
	exit(2);
}



int input_str(char *rn,char **r,int isptr,int arr) {
        return input_string(rn,r,isptr,arr);
}



int output_str(char *n, char *r,int isptr,int arr) {
        if (r==0) r="";
        return output_string(n,r,isptr,arr);
}


void set_yytext(char *s) {
//
}
