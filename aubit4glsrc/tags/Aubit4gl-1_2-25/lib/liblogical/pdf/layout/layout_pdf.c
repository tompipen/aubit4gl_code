#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "../common/common_pdf.h"
#include "../../common/a4gl_lle.h"
#include "../../layout_engine/API_layout.h"

//void msgbox(char *title,char *txt) ;

#define ENTRY_FOR_FONT 10
#define ENTRY_FOR_FONTSIZE 11
GtkWidget *table;
GtkWidget *labels[20];
GtkWidget *values[20];

static void clr_font(int rb,int entry) ;
static void save_font(char *buff, int size,int rb, int entry) ;
extern struct pdf_layout layout;
static int setup_font_display(int rb,int entry) ;
static int has_font_definition(int rb,int entry) ;

GtkWidget *paper_b[10];		// Assume no more than 10 papers anyway..

GtkWidget *FontWindow=0;
int current_rb;
int current_entry;

static int gtk_object_get_data_as_int(void *obj,char *name) {
        return (int)((long)gtk_object_get_data(obj,name));
}


static void
cp_boxes_to_data (void)
{
  int a;
  memset (layout.fontname, 0, 100);
  strcpy (layout.fontname, gtk_entry_get_text (GTK_ENTRY (values[0])));
  layout.fontname[100] = 0;

  layout.fontsize =
    gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (values[1]));
  //printf ("read fontsize as : %d\n", layout.fontsize);
  layout.leftmargin =
    gtk_spin_button_get_value_as_float (GTK_SPIN_BUTTON (values[2]));
  layout.topmargin =
    gtk_spin_button_get_value_as_float (GTK_SPIN_BUTTON (values[3]));

  memset (layout.img_src, 0, 255);
  strcpy (layout.img_src, gtk_entry_get_text (GTK_ENTRY (values[6])));
  layout.img_src[255] = 0;
  memset (layout.bluebar, 0, 255);
  strcpy (layout.bluebar, gtk_entry_get_text (GTK_ENTRY (values[9])));
  layout.bluebar[255] = 0;
  layout.img_x = gtk_spin_button_get_value_as_float (GTK_SPIN_BUTTON (values[7]));
  layout.img_y = gtk_spin_button_get_value_as_float (GTK_SPIN_BUTTON (values[8]));

  for (a = 0; a < 10; a++)
    {
      if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (paper_b[a])))
	{
	  layout.paper_type =
	    (int) gtk_object_get_data (GTK_OBJECT (paper_b[a]), "PAPER_TYPE");
	  break;
	}
    }
  if (gtk_toggle_button_get_active
      (gtk_object_get_data (GTK_OBJECT (values[5]), "RB1")))
    layout.paper_orient = PAPER_ORIENT_PORTRAIT;
  if (gtk_toggle_button_get_active
      (gtk_object_get_data (GTK_OBJECT (values[5]), "RB2")))
    layout.paper_orient = PAPER_ORIENT_LANDSCAPE;
  if (gtk_toggle_button_get_active
      (gtk_object_get_data (GTK_OBJECT (values[5]), "RB3")))
    layout.paper_orient = PAPER_ORIENT_AUTO;
}



static void
show_layout (void)
{
  int a;
  //printf ("Show layout\n");
  gtk_entry_set_text (GTK_ENTRY (values[0]), layout.fontname);
  //printf ("fontsize = %d\n", layout.fontsize);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (values[1]),
			     (gfloat) layout.fontsize);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (values[2]),
			     (gfloat) layout.leftmargin);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (values[3]),
			     (gfloat) layout.topmargin);

  //printf ("img src=%s x=%d y=%d\n", layout.img_src, layout.img_x, layout.img_y);

  gtk_entry_set_text (GTK_ENTRY (values[6]), layout.img_src);
  gtk_entry_set_text (GTK_ENTRY (values[9]), layout.bluebar);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (values[7]),
			     (gfloat) layout.img_x);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (values[8]),
			     (gfloat) layout.img_y);

  for (a = 0; a < 10; a++)
    {
      if (paper_b[a] == 0)
	break;
      if ((int) gtk_object_get_data (GTK_OBJECT (paper_b[a]), "PAPER_TYPE") ==
	  layout.paper_type)
	{
	  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (paper_b[a]), 1);
	  break;
	}
    }

  if (layout.paper_orient == PAPER_ORIENT_PORTRAIT)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
				  (gtk_object_get_data
				   (GTK_OBJECT (values[5]), "RB1")), 1);
  if (layout.paper_orient == PAPER_ORIENT_LANDSCAPE)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
				  (gtk_object_get_data
				   (GTK_OBJECT (values[5]), "RB2")), 1);
  if (layout.paper_orient == PAPER_ORIENT_AUTO)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON
				  (gtk_object_get_data
				   (GTK_OBJECT (values[5]), "RB3")), 1);

}

void
LR_default_file (void *report, void *rbx, int rbs)
{
  //printf ("Loading file\n");
  pdf_default_file ();
  //printf ("sl2\n");
  show_layout ();
}


void
LR_preview_file (void *report)
{
  msgbox ("Cannot Preview", "Use the report viewer as a preview");
}

static gboolean  fontchange_focus   (GtkWidget     *widget, GdkEventFocus *event, gpointer       user_data)  {
	char buff[200];
	int size;
	strcpy(buff, gtk_entry_get_text(GTK_ENTRY(values[ENTRY_FOR_FONT])));
	size=atoi(gtk_entry_get_text(GTK_ENTRY(values[ENTRY_FOR_FONTSIZE])));
	A4GL_trim(buff);
	if (size && strlen(buff)) {
		save_font(buff,size,current_rb, current_entry);
	} else {
		clr_font(current_rb, current_entry);
	}

return FALSE;
}

static  gboolean      fontchange_keyboard                      (GtkWidget   *widget, GdkEventKey *event, gpointer     user_data)  {
	char buff[200];
	int size;
	strcpy(buff, gtk_entry_get_text(GTK_ENTRY(values[ENTRY_FOR_FONT])));
	size=atoi(gtk_entry_get_text(GTK_ENTRY(values[ENTRY_FOR_FONTSIZE])));
	A4GL_trim(buff);
	if (size && strlen(buff)) {
		save_font(buff,size,current_rb, current_entry);
	} else {
		clr_font(current_rb, current_entry);
	}
return 0;
}

void
LR_show_layout_rest (void *report, void *sb, void *vrbx, int rbs)
{
  GtkWidget *lab;
GtkWidget *panel;
GtkWidget *ptable;
  GtkAdjustment *adj;
  GtkWidget *hbox;
  GtkWidget *last;
  GtkSpinButton *b;
  //GtkWidget *scroll;
  int paper_types[] = {
    PAPER_TYPE_A4,
    PAPER_TYPE_LETTER
  };
  char *papers[] = {
    "A4",
    "Letter",
    //"A3",
    //"A5",
    "Legal",
    "Ledger",
    0
  };
  int npaper;
  int cnt;



  table = gtk_table_new (13, 3, 0);

  gtk_container_add (sb, table);

  lab = gtk_label_new ("  Font");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 0, 1);
  labels[0] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);

  lab = gtk_label_new ("  Font Size");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 1, 2);
  labels[1] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);

  lab = gtk_label_new ("  Left Margin");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 2, 3);
  labels[2] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  lab = gtk_label_new ("Inches");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 2, 3, 2, 3);
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  lab = gtk_label_new ("  Top Margin");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 3, 4);
  labels[3] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  lab = gtk_label_new ("Inches");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 2, 3, 3, 4);
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  lab = gtk_label_new ("  Paper Size");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 4, 5);
  labels[4] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  lab = gtk_label_new ("  Paper Orient");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 5, 6);
  labels[5] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);

  lab = gtk_label_new ("  Background Image");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 7, 8);
  labels[6] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);

  lab = gtk_label_new ("  Img X");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 8, 9);
  labels[7] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);


  lab = gtk_label_new ("  Img Y");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 9, 10);
  labels[8] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);

  lab = gtk_label_new ("  Bluebar (r,g,b,style or #xxxxxx,style)");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 1, 11, 12);
  labels[9] = lab;
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);



  lab =
    gtk_label_new
    ("\n   There is no Right margin or bottom margin. You will need to\n"
       "   ensure that FONTSIZE is correctly set up in order to make\n"
       "   sure that all data will fit on the page\n");
  gtk_table_attach_defaults (GTK_TABLE (table), lab, 0, 3, 6, 7);
  gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.0f);


  values[0] = gtk_entry_new ();
  gtk_table_attach_defaults (GTK_TABLE (table), values[0], 1, 2, 0, 1);

  adj = (GtkAdjustment *) gtk_adjustment_new (8.0, 1.0, 64.0, 1.0, 1.0, 1.0);
  values[1] = gtk_spin_button_new (adj, 1.0, 0);
  gtk_table_attach_defaults (GTK_TABLE (table), values[1], 1, 2, 1, 2);

  adj = (GtkAdjustment *) gtk_adjustment_new (0.0, 0.0, 10.0, 0.05, 0.5, 0.5);
  values[2] = gtk_spin_button_new (adj, 1.0, 2);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (values[2]), 1);
  b = (GtkSpinButton *) values[2];

  gtk_table_attach_defaults (GTK_TABLE (table), values[2], 1, 2, 2, 3);

  adj = (GtkAdjustment *) gtk_adjustment_new (0.0, 0.0, 10.0, 0.05, 0.5, 0.5);
  values[3] = gtk_spin_button_new (adj, 1.0, 2);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (values[3]), 1);

  gtk_table_attach_defaults (GTK_TABLE (table), values[3], 1, 2, 3, 4);

  last = 0;
  hbox = gtk_hbox_new (TRUE, 3);
  last =
    gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (last),
						 "Portrait");
  gtk_object_set_data (GTK_OBJECT (hbox), "RB1", last);
  gtk_box_pack_start (GTK_BOX (hbox), last, TRUE, TRUE, 2);
  last =
    gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (last),
						 "Landscape");
  gtk_object_set_data (GTK_OBJECT (hbox), "RB2", last);
  gtk_box_pack_start (GTK_BOX (hbox), last, TRUE, TRUE, 2);
  last =
    gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (last),
						 "Auto");
  gtk_object_set_data (GTK_OBJECT (hbox), "RB3", last);
  gtk_box_pack_start (GTK_BOX (hbox), last, TRUE, TRUE, 2);
  values[5] = hbox;
  gtk_table_attach_defaults (GTK_TABLE (table), values[5], 1, 2, 5, 6);

  values[6] = gtk_entry_new ();
  gtk_table_attach_defaults (GTK_TABLE (table), values[6], 1, 2, 7, 8);
  adj = (GtkAdjustment *) gtk_adjustment_new (0.0, 1.0, 640.0, 1.0, 10.0, 10.0);
  values[7] = gtk_spin_button_new (adj, 1.0, 0);
  gtk_table_attach_defaults (GTK_TABLE (table), values[7], 1, 2, 8, 9);

  adj = (GtkAdjustment *) gtk_adjustment_new (0.0, 1.0, 640.0, 1.0, 10.0, 10.0);
  values[8] = gtk_spin_button_new (adj, 1.0, 0);
  gtk_table_attach_defaults (GTK_TABLE (table), values[8], 1, 2, 9, 10);

  values[9] = gtk_entry_new ();
  gtk_table_attach_defaults (GTK_TABLE (table), values[9], 1, 2, 11, 12);

  last = 0;

  for (cnt = 0; cnt < 10; cnt++)
    {
      paper_b[cnt] = 0;
    }
  for (cnt = 0; papers[cnt]; cnt++)
    {
      last =
	gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (last),
						     papers[cnt]);
      paper_b[cnt] = last;
      gtk_object_set_data (GTK_OBJECT (paper_b[cnt]), "PAPER_TYPE",
			   (void *) paper_types[cnt]);
    }
  npaper = cnt - 1;

  hbox = gtk_hbox_new (TRUE, cnt);
  for (cnt = 0; cnt <= npaper; cnt++)
    {
      //printf ("ADD");
      gtk_box_pack_start (GTK_BOX (hbox), paper_b[cnt], TRUE, TRUE, 2);
    }
  gtk_widget_show_all (hbox);
  values[4] = hbox;

  gtk_table_attach_defaults (GTK_TABLE (table), values[4], 1, 2, 4, 5);

  	panel=gtk_frame_new("Cell Fonts");
  	ptable = gtk_table_new (2, 2, 1);
  	gtk_table_attach_defaults (GTK_TABLE (table), panel, 0, 2, 12, 13);
	lab=gtk_label_new("Font"); gtk_widget_show(lab);
	gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  	gtk_table_attach_defaults (GTK_TABLE (ptable), lab, 0, 1, 0, 1);
	lab=gtk_label_new("FontSize"); gtk_widget_show(lab);
	gtk_misc_set_alignment (GTK_MISC (lab), 0.0f, 0.5f);
  	gtk_table_attach_defaults (GTK_TABLE (ptable), lab, 0, 1, 1, 2);
	gtk_container_add(GTK_CONTAINER(panel),ptable);

  	values[ENTRY_FOR_FONT] = gtk_entry_new ();
  	gtk_table_attach_defaults (GTK_TABLE (ptable), values[10], 1, 2, 0, 1);
  	values[ENTRY_FOR_FONTSIZE] = gtk_entry_new ();
  	gtk_table_attach_defaults (GTK_TABLE (ptable), values[11], 1, 2, 1, 2);
	g_signal_connect(values[ENTRY_FOR_FONT],"key-release-event",GTK_SIGNAL_FUNC(fontchange_keyboard),0);
	g_signal_connect(values[ENTRY_FOR_FONTSIZE],"key-release-event",GTK_SIGNAL_FUNC(fontchange_keyboard),0);
	g_signal_connect(values[ENTRY_FOR_FONT],"focus-out-event",GTK_SIGNAL_FUNC(fontchange_focus),0);
	g_signal_connect(values[ENTRY_FOR_FONTSIZE],"focus-out-event",GTK_SIGNAL_FUNC(fontchange_focus),0);

  	gtk_widget_show_all (table);
  	gtk_widget_show_all (ptable);
  	LR_default_file (report, vrbx, rbs);
  	show_layout ();
}


static gboolean btn_press (GtkButton* clicked, GdkEventButton *event, gpointer func_data)
{
int rb;
int entry;
char *s;
	//if (event->button!=3)  return;

	s=(char *)gtk_object_get_data_as_int(clicked ,"BLOCK_TXT");
	if (s) {
		rb=gtk_object_get_data_as_int(clicked     ,"BLOCK");
		entry=-1;
	} else {
		rb=gtk_object_get_data_as_int(clicked     ,"RB");
      		entry=gtk_object_get_data_as_int(clicked  ,"ENTRY");
	}
	setup_font_display(rb,entry);
	current_rb=rb;
	current_entry=entry;
	g_print ("button pressed: %p %d -> %d rb=%d entry=%d\n", event, GPOINTER_TO_INT (func_data), event->button,rb,entry);
return 0;
}


void
LR_setup_entry (void *report, int b, int e, void *evt, void *label)
{
  g_signal_connect (GTK_OBJECT (evt), "button-press-event", GTK_SIGNAL_FUNC (btn_press), evt);
}


void
LR_setup_block (void *report, int b, void *evt, void *label)
{
  //
  g_signal_connect (GTK_OBJECT (evt), "button-press-event", GTK_SIGNAL_FUNC (btn_press), evt);
}

int
LR_save_file (void *report, FILE * fin, void *rbx, int rbs)
{
  cp_boxes_to_data ();
  return pdf_save_file (fin);
}

int
LR_load_file (void *report, FILE * fin, void *rbx, int rbs)
{
  int n;
  n = pdf_load_file (fin);
  show_layout ();
  return n;
}


void
LR_setup_callback (void *p)
{
}


void save_font(char *buff, int size,int rb, int entry) {
int a;
	if (rb==0 && entry==0) return;
	//printf("SAVING : %s %d\n",buff,size);
	a=has_font_definition(rb,entry);
	if (a!=-1) {
		strcpy(layout.fonts[a].font,buff);
		layout.fonts[a].size=size;
	} else {
		layout.nfonts++;
		layout.fonts=realloc(layout.fonts, sizeof(layout.fonts[0])*layout.nfonts);
		a=layout.nfonts-1;
		strcpy(layout.fonts[a].font,buff);
		layout.fonts[a].size=size;
		layout.fonts[a].block=rb;
		layout.fonts[a].entry=entry;
	}
	//printf("SAVING @%d\n",a);
}



static void clr_font(int rb,int entry) {
int a;
struct fonts *p;
int b;
int c=0;
	if (rb==0 && entry==0) return;

	a=has_font_definition(rb,entry);
	if (a==-1) return; // nothing to clear!

	if (layout.nfonts==1) {
		layout.nfonts=0;
		layout.fonts=0;
		return;
	}


	// Lets remove our current entry from the list..
	p=malloc(sizeof(layout.fonts[0])*layout.nfonts);

	// Go through all the fonts..
	for (b=0;b<layout.nfonts;b++) {
		if (b==a) continue;
		memcpy(&p[c++],&layout.fonts[b],sizeof(layout.fonts[0]));
	}
	free(layout.fonts);
	layout.fonts=p;
	layout.nfonts--;

}

int setup_font_display(int rb,int entry) {
int a;
char buff[200];

a=has_font_definition(rb,entry);

	if (a==-1) {
		gtk_entry_set_text(GTK_ENTRY(values[ENTRY_FOR_FONT]),"");
		gtk_entry_set_text(GTK_ENTRY(values[ENTRY_FOR_FONTSIZE]),"");
		return 1;
	}
	gtk_entry_set_text(GTK_ENTRY(values[ENTRY_FOR_FONT]), layout.fonts[a].font);
	sprintf(buff,"%d", layout.fonts[a].size);
	gtk_entry_set_text(GTK_ENTRY(values[ENTRY_FOR_FONTSIZE]), buff);
return 1;
}

int has_font_definition(int rb,int entry) {
int a;
for (a=0;a<layout.nfonts;a++) {
	if (layout.fonts[a].entry==entry && layout.fonts[a].block==rb) return a;
}
return -1;
}
