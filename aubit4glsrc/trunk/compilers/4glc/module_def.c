


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"


int write_module_definition(struct module_definition *s,char *filename) {
	A4GL_write_data_to_file("module_definition", s,filename);
}

int read_module_definition(struct module_definition *s,char *filename) {
	return A4GL_read_data_from_file("module_definition",s,filename);
}

