#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "../../common/a4gl_lle.h"
#include "../../layout_engine/API_layout.h"

void msgbox(char *title,char *txt) ;

void LR_default_file(void *report,void *rbx,int rbs) {
	msgbox("Cannot create default","There are no configurable options to create a default file for!");
}


void LR_preview_file(void *report) {
	msgbox("Cannot Preview","Use the report viewer as a preview");
}


void LR_show_layout_rest(void *report, void *sb,void *rbx,int rbs) {
	gtk_container_add(sb,gtk_label_new("No configurable options"));
}


void LR_setup_entry(void *report, int b,int e, void *evt, void *label) {
	//
}


void LR_setup_block(void *report, int b, void *evt, void *label) {
	//
}

int LR_save_file(void *report, FILE *fin,void *rbx, int rbs) {
	// We don't need to add anything to the output file
	return 1;
}

int LR_load_file(void *report, FILE *fin,void *rbx, int rbs) {
	// We don't need to add anything to the output file
	return 1;
}


