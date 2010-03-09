#include "fgl.xnew.h"
extern FILE *ofile;


int XMLWrite_variable_ptr(char *nm, variable_ptr p) {
	return XMLWrite_variable_std(nm, p);
}

int XMLWrite_command_ptr(char *nm, command_ptr p) {
	return XMLWrite_command_std(nm, p);
}

int XMLWrite_expr_str_ptr(char *nm, expr_str_ptr p) {
	return XMLWrite_expr_str_std(nm, p);
}

int XMLWrite_single_option_ptr(char *nm, single_option_ptr p) {
	return XMLWrite_single_option_std(nm, p);
}


int XMLWrite_report_format_section_entry_ptr(char *nm, report_format_section_entry_ptr p) {
	return XMLWrite_report_format_section_entry_std(nm, p);
}


int XMLWrite_when_ptr(char *nm, when_ptr p) {
	return XMLWrite_when_std(nm, p);
}
int XMLWrite_on_event_ptr(char *nm, on_event_ptr p) {
	return XMLWrite_on_event_std(nm, p);
}

int XMLWrite_cons_list_entry_ptr(char *nm, cons_list_entry_ptr p) {
	return XMLWrite_cons_list_entry_std(nm, p);
}
int XMLWrite_module_entry_ptr(char *nm, module_entry_ptr p) {
	return XMLWrite_module_entry_std(nm, p);
}

int XMLWrite_elements_ptr(char *nm, elements_ptr p) {
	return XMLWrite_s_select_list_item_std(nm,p);
}

/*
int XMLWrite_s_select_list_item_ptr(char *nm, struct s_select_list_item_ptr *p) {
	return XMLWrite_s_select_list_item_std(nm, *p);
}
int XMLWrite_s_table_list_element_ptr(char *nm, struct s_table_list_element_ptr *p) {
	return XMLWrite_s_table_list_element_std(nm, *p);
}
*/



int XMLWrite_int(char *nm, int *l) {
int i;
i=*l;
	 gzfprintf(ofile,"<int nm='%s' value='%d'/>\n", nm,i);
return 1;
}


int XMLWrite_long(char *nm, long *l) {
int i;
i=*l;
	 gzfprintf(ofile,"<long nm='%s' value='%d'/>\n", nm,i);
return 1;
}

int XMLWrite_str(char *nm, str *val) {
        gzfprintf(ofile,"<str nm='%s' value='%s'/>\n",nm,xml_encode(*val));
return 1;
}


