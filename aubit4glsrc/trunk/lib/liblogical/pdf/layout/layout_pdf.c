#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "../common/common_pdf.h"
#include "../../common/a4gl_lle.h"
#include "../../layout_engine/API_layout.h"

void msgbox(char *title,char *txt) ;

GtkWidget *table;
GtkWidget *labels[10];
GtkWidget *values[10];

extern struct pdf_layout layout;

GtkWidget *paper_b[10]; // Assume no more than 10 papers anyway..

static void cp_boxes_to_data() {
	int a;
	memset(layout.fontname,0,100);
	strcpy(layout.fontname,gtk_entry_get_text(GTK_ENTRY(values[0])));
	layout.fontname[100]=0;

	layout.fontsize=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(values[1]));
	layout.leftmargin=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(values[2]));
	layout.topmargin=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(values[3]));

	for (a=0;a<10;a++) {
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(paper_b[a]))) {
			layout.paper_type=(int)gtk_object_get_data(GTK_OBJECT(paper_b[a]),"PAPER_TYPE");
			break;
		}
	}
	if (gtk_toggle_button_get_active(gtk_object_get_data(GTK_OBJECT(values[5]),"RB1"))) layout.paper_orient=PAPER_ORIENT_PORTRAIT;
	if (gtk_toggle_button_get_active(gtk_object_get_data(GTK_OBJECT(values[5]),"RB2"))) layout.paper_orient=PAPER_ORIENT_LANDSCAPE;
	if (gtk_toggle_button_get_active(gtk_object_get_data(GTK_OBJECT(values[5]),"RB3"))) layout.paper_orient=PAPER_ORIENT_AUTO;
}



static void show_layout () {
	int a;
	gtk_entry_set_text(GTK_ENTRY(values[0]),layout.fontname);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(values[1]),(gfloat)layout.fontsize);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(values[2]),(gfloat)layout.leftmargin);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(values[3]),(gfloat)layout.topmargin);

	for (a=0;a<10;a++) {
		if (paper_b[a]==0) break;
		if ((int)gtk_object_get_data(GTK_OBJECT(paper_b[a]),"PAPER_TYPE")==layout.paper_type) {
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(paper_b[a]),1);
			break;
		}
	}

	if (layout.paper_orient==PAPER_ORIENT_PORTRAIT) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gtk_object_get_data(GTK_OBJECT(values[5]),"RB1")),1);
	if (layout.paper_orient==PAPER_ORIENT_LANDSCAPE) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gtk_object_get_data(GTK_OBJECT(values[5]),"RB2")),1);
	if (layout.paper_orient==PAPER_ORIENT_AUTO) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gtk_object_get_data(GTK_OBJECT(values[5]),"RB3")),1);
	
}

void LR_default_file(void *report) {
	pdf_default_file();
	show_layout();
}


void LR_preview_file(void *report) {
	msgbox("Cannot Preview","Use the report viewer as a preview");
}


void LR_show_layout_rest(void *report, void *sb) {
	GtkWidget *lab;
	GtkAdjustment *adj;
	GtkWidget *hbox;
	GtkWidget *last;
	GtkSpinButton *b;
	GtkWidget *scroll;
	int paper_types[]={
		PAPER_TYPE_A4,
		PAPER_TYPE_LETTER
	};
	char *papers[]={
		"A4",
		"Letter",
		//"A3",
		//"A5",
		//"Legal",
		//"Ledger",
		0};
	int npaper;
	int cnt;



	table=gtk_table_new(7,3,0);

	gtk_container_add(sb,table);

	lab=gtk_label_new("Font");        gtk_table_attach_defaults(GTK_TABLE(table),lab,0,1,0,1); labels[0]=lab; gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
	lab=gtk_label_new("Font Size");   gtk_table_attach_defaults(GTK_TABLE(table),lab,0,1,1,2); labels[1]=lab; gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
	lab=gtk_label_new("Left Margin"); gtk_table_attach_defaults(GTK_TABLE(table),lab,0,1,2,3); labels[2]=lab; gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
		lab=gtk_label_new("Inches"); gtk_table_attach_defaults(GTK_TABLE(table),lab,2,3,2,3); gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
	lab=gtk_label_new("Top Margin");  gtk_table_attach_defaults(GTK_TABLE(table),lab,0,1,3,4); labels[3]=lab; gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
		lab=gtk_label_new("Inches");  gtk_table_attach_defaults(GTK_TABLE(table),lab,2,3,3,4); gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
	lab=gtk_label_new("Paper Size");  gtk_table_attach_defaults(GTK_TABLE(table),lab,0,1,4,5); labels[4]=lab; gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);
	lab=gtk_label_new("Paper Orient");gtk_table_attach_defaults(GTK_TABLE(table),lab,0,1,5,6); labels[5]=lab; gtk_misc_set_alignment(GTK_MISC(lab), 0.1f, 0.5f);

	lab=gtk_label_new("\nThere is no Right margin or bottom margin\nYou will need to ensure that FONTSIZE\nis correctly set up in order to make sure that all\ndata will fit on the page");  gtk_table_attach_defaults(GTK_TABLE(table),lab,0,3,6,7); 
	gtk_misc_set_alignment(GTK_MISC(lab), 0.0f, 0.0f);


	values[0]=gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table),values[0],1,2,0,1); 

	adj=(GtkAdjustment *)gtk_adjustment_new(8.0, 1.0, 64.0, 1.0, 1.0, 1.0);
	values[1]=gtk_spin_button_new(adj,1.0,0); 
	gtk_table_attach_defaults(GTK_TABLE(table),values[1],1,2,1,2); 

	adj=(GtkAdjustment *)gtk_adjustment_new(0.0, 0.0, 10.0, 0.05, 0.5, 0.5);
	values[2]=gtk_spin_button_new(adj,1.0,2); 
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(values[2]),1);
	b=(GtkSpinButton *)values[2];
	
	gtk_table_attach_defaults(GTK_TABLE(table),values[2],1,2,2,3); 

	adj=(GtkAdjustment *)gtk_adjustment_new(0.0, 0.0, 10.0, 0.05, 0.5, 0.5);
	values[3]=gtk_spin_button_new(adj,1.0,2);
	gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(values[3]),1);

	gtk_table_attach_defaults(GTK_TABLE(table),values[3],1,2,3,4); 

	last=0;
	hbox=gtk_hbox_new(TRUE,3);
	last=gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(last), "Portrait");
	gtk_object_set_data(GTK_OBJECT(hbox),"RB1",last); gtk_box_pack_start(GTK_BOX(hbox),last,TRUE,TRUE,2);
	last=gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(last), "Landscape");
	gtk_object_set_data(GTK_OBJECT(hbox),"RB2",last); gtk_box_pack_start(GTK_BOX(hbox),last,TRUE,TRUE,2);
	last=gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(last), "Auto");
	gtk_object_set_data(GTK_OBJECT(hbox),"RB3",last); gtk_box_pack_start(GTK_BOX(hbox),last,TRUE,TRUE,2);
	values[5]=hbox;
	gtk_table_attach_defaults(GTK_TABLE(table),values[5],1,2,5,6); 
	
	last=0;

        for (cnt=0;cnt<10;cnt++) {paper_b[cnt]=0;}
	for (cnt=0;papers[cnt];cnt++) {
		last=gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(last), papers[cnt]);
		paper_b[cnt]=last;
		gtk_object_set_data(GTK_OBJECT(paper_b[cnt]),"PAPER_TYPE",(void *)paper_types[cnt]);
	}
	npaper=cnt-1;

	hbox=gtk_hbox_new(TRUE,cnt);
	for (cnt=0;cnt<=npaper;cnt++) {
		printf("ADD");
		gtk_box_pack_start(GTK_BOX(hbox),paper_b[cnt],TRUE,TRUE,2);
	}
	gtk_widget_show_all(hbox);
	values[4]=hbox;
	gtk_table_attach_defaults(GTK_TABLE(table),values[4],1,2,4,5); 
	gtk_widget_show_all(table);
	LR_default_file(report);
	show_layout();
}


void LR_setup_entry(void *report, int b,int e, void *evt, void *label) {
	//
}


void LR_setup_block(void *report, int b, void *evt, void *label) {
	//
}

int LR_save_file(void *report, FILE *fin) {
	cp_boxes_to_data();
	return pdf_save_file(fin);
}

int LR_load_file(void *report, FILE *fin) {
	return pdf_load_file(fin);
	show_layout();
}


