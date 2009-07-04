#include "a4gl_libaubit4gl_int.h"

struct ui_interface_data {
	int n;
};


static int ui_interface_loadtoolbar(int *objectID, int nparam) {
	char *a;
	char buff[2000];
	if (nparam!=1) {
		return 0;
	}


	a=A4GL_char_pop();
	A4GL_trim(a);
	sprintf(buff,"%s.4tb",a);
	A4GL_push_char(buff);
	aclfgl_aclfgl_send_to_ui(1);
	free(a);
	return 0;
}

static int ui_interface_loadactiondefauts(int *objectID, int nparam) {
	char *a;
	char buff[2000];
	if (nparam!=1) {
		return 0;
	}


	a=A4GL_char_pop();
	A4GL_trim(a);
	sprintf(buff,"%s.4ad",a);
	A4GL_push_char(buff);
	aclfgl_aclfgl_send_to_ui(1);
	free(a);
	
	return 0;
}

static int ui_interface_loadstyles(int *objectID, int nparam) {
	char *a;
	char buff[2000];
	if (nparam!=1) {
		return 0;
	}


	a=A4GL_char_pop();
	A4GL_trim(a);
	sprintf(buff,"%s.4st",a);
	A4GL_push_char(buff);
	aclfgl_aclfgl_send_to_ui(1);
	free(a);
	
	return 0;
}

static int ui_interface_frontcall(int *objectID, int nparam) {
	struct BINDING *obind;
	int no;
	struct BINDING *ibind;
	int ni;
	char *name;
	char *module;

	if (!A4GL_pop_binding_from_stack(&obind,&no,'o')) { // Its an output binding when reading...
                A4GL_push_int(0);
                return 1;
        }
	if (!A4GL_pop_binding_from_stack(&ibind,&ni,'i')) { // Its an output binding when reading...
                A4GL_push_int(0);
                return 1;
        }

	name=A4GL_char_pop();
	module=A4GL_char_pop();
	A4GL_ui_frontcall(module,name, ibind,ni,obind,no);

	return 0;
}

static int ui_interface_refresh(int *objectID,int nparam) {
	A4GL_ui_frontcall("INTERNAL","ui.interface.refresh", 0,0,0,0);
	
	return 0;
}

static int ui_interface_settext(int *objectID,int nparam) {
char *text;
        struct BINDING ibind[]= {
                {NULL,0,500,0,0,0}
        };
	text=A4GL_char_pop();
	A4GL_trim(text);
	ibind[0].size=strlen(text);
	ibind[0].ptr=text;

	A4GL_ui_frontcall("INTERNAL","ui.interface.settext", ibind,1,0,0);
	
	return 0;
}

void add_ui_interface_support(void) {
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.interface.loadtoolbar", (void *) ui_interface_loadtoolbar);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.interface.loadactiondefauts", (void *) ui_interface_loadactiondefauts);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.interface.loadstyles", (void *) ui_interface_loadstyles);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.interface.frontcall", (void *) ui_interface_frontcall);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.interface.refresh", (void *) ui_interface_refresh);
	A4GL_add_datatype_function_i (DTYPE_OBJECT, ":ui.interface.settext", (void *) ui_interface_settext);
		//ui.interface.getrootnode
}
