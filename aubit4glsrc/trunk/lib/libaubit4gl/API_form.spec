*
* API specs for FORM library interface - used by dlmagic script
* to create API_form.c (try "make API_form.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY FORM
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_FORMTYPE
*
* Function calls definitions:
* func-name param-type param-name ... -> returns"
*
//struct s_form_dets *
//read_form (char *fname, char *formname)
*read_form char *fname,char *formname -> struct s_form_dets*
//void
//set_default_form (struct s_form_attr *form)
*set_default_form struct s_form_attr *form -> void
//char *
//find_attribute (struct s_form_dets *f, int field_no)
*find_attribute s_form_dets *f,int field_no -> char*







