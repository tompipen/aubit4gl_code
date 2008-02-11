#include "a4gl_libaubit4gl.h"

void LEXLIB_A4GL_initlex(void) {
//
}


int LEXLIB_A4GL_write_generated_code(module_definition *module ){
	char *outn="module.out";
	
	return A4GL_write_data_to_file("module_definition",module,module->module_name);
}
