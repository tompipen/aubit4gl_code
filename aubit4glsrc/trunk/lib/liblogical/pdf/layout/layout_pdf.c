#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "../../common/a4gl_lle.h"

void msgbox(char *title,char *txt) ;

void LR_default_file() {
	msgbox("Cannot create default","There are no configurable options to create a default file for!");
}


void LR_preview_file() {
	msgbox("Cannot Preview","Use the report viewer as a preview");
}


void LR_show_layout_rest(void *sb) {
	gtk_container_add(sb,gtk_label_new("No configurable options"));
}


void LR_setup_entry(int b,int e, void *evt, void *label) {
	//
}


void LR_setup_block(int b, void *evt, void *label) {
	//
}

int LR_save_file(FILE *fin) {
	// We don't need to add anything to the output file
	return 1;
}

int LR_load_file(FILE *fin) {
	// We don't need to add anything to the output file
	return 1;
}


