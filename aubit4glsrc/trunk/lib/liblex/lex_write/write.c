#include "a4gl_libaubit4gl.h"
#include "a4gl_API_lex_lib.h"

void LEXLIB_A4GL_initlex(void) {
//
}


int LEXLIB_A4GL_write_generated_code(struct module_definition *module ){
	char *outn="module.out";
	A4GL_debug("Packer : %s\n",acl_getenv("A4GL_PACKER"));
	return A4GL_write_data_to_file("module_definition",module,module->module_name);
}
