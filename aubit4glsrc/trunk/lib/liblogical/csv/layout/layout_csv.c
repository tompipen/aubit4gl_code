#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "../../common/a4gl_lle.h"
#include "../common/csv_io.h"
#include "../../layout_engine/API_layout.h"

void msgbox (char *title, char *txt);

#define DRAG_TARGET_NAME_0 "ReportEntry"
#define DRAG_TARGET_INFO_0 0

#define DRAG_TARGET_NAME_1 "ReportBlock"
#define DRAG_TARGET_INFO_1 1
GtkTargetEntry target_entry[] = {
  {DRAG_TARGET_NAME_0, 0, DRAG_TARGET_INFO_0}
};

//int fake_clicked(int a,int b);

int (*fake_clicked_ptr)(int a,int b) =0;

GtkTargetEntry target_block[] = {
  {DRAG_TARGET_NAME_1, 0, DRAG_TARGET_INFO_1}
};

GtkTargetEntry target_all[] = {
  {DRAG_TARGET_NAME_0, 0, DRAG_TARGET_INFO_0}
  ,
  {DRAG_TARGET_NAME_1, 0, DRAG_TARGET_INFO_1}
};


GtkWidget *window;

struct r_report *rep;

#define XWIDTH 10
#define YHEIGHT 15

GtkWidget *create_block (int n,void *rbx, int rbs);

void do_data_get_from_layout (GtkWidget * widget, GdkDragContext * dc,
			      GtkSelectionData * selection_data, guint info,
			      guint t, gpointer data);


GtkWidget **block_tables = 0;
int nblock_tables = 0;

//extern int rbs;
//extern struct s_rbx *rbx;

char *style_cell =
  "style \"CELL\" {font_name=\"monospace 10\" bg[NORMAL] = \"#a0a0a0\"} widget \"*.CELL\" style \"CELL\"";
char *style_cell_disable =
  "style \"CELL_DISABLE\" {font_name=\"monospace 10\" bg[NORMAL] = \"#ffffff\"} widget \"*.CELL_DISABLE\" style \"CELL_DISABLE\"";
extern void edit_lle (void);
int remake_table_from_layout(struct csv_report_layout *in,void *rbx,int rbs) ;

/* ******************************************************************************** */

void
quit_program (void)
{
  gtk_main_quit ();
}

void
save_file (void)
{
  printf ("Save!\n");
}




/* ******************************************************************************** */

void LR_show_layout_rest (void *vreport, void* vvbox_in_sw,void *rbx, int rbs)
{
  /* create a new window */

  //char desc[255];
  //char buff[1024];

  //GtkItemFactory *ifac;
  //GtkAccelGroup *acc;
  //GtkWidget *menu_bar;
  //GtkWidget *vbox;
  //GtkWidget *sw;
  //GtkWidget *l;

GtkWidget *vbox_in_sw;
  int block;
vbox_in_sw=vvbox_in_sw;


  gtk_rc_parse_string (style_cell);
  gtk_rc_parse_string (style_cell_disable);

  for (block = 0; block < rbs; block++)
    {
      gtk_container_add (GTK_CONTAINER (vbox_in_sw), create_block (block,rbx,rbs));
    }
}


gint
grab_int_value (GtkSpinButton * a_spinner, gpointer user_data)
{
  return gtk_spin_button_get_value_as_int (a_spinner);
}

GtkWidget *
create_integer_spin_button (void)
{

  //GtkWidget *window, 
	GtkWidget *spinner;
  GtkAdjustment *spinner_adj;

  spinner_adj =
    (GtkAdjustment *) gtk_adjustment_new (1.0, 0.0, 20.0, 1.0, 5.0, 5.0);
  spinner = gtk_spin_button_new (spinner_adj, 1.0, 0);
  return spinner;
}


void LR_setup_callback(void *p) {
	fake_clicked_ptr=p;
}

void
do_drag_data_received (GtkWidget * widget, GdkDragContext * dc, gint x,
		       gint y, GtkSelectionData * selection_data, guint info,
		       guint t, gpointer data)
{
  int entry;
  int rb;
  int type;
  int orig;
  GtkWidget *label;

  printf ("DROP %p\n", data);

  if (selection_data == 0)
    return;
  printf ("Have selection");



  orig = (int) gtk_object_get_data (GTK_OBJECT (widget), "BLOCK");

  if (info == DRAG_TARGET_INFO_0)
    {
      gchar *new_text = selection_data->data;
      printf ("===> %s\n", new_text);
      sscanf (new_text, "%d %d %d", &rb, &entry, &type);

      if (orig != rb)
	{
	  printf
	    ("\n\n\n***WARNING : Copying data to a different block may cause unexpected results!\n\n\n");
	}
      label = gtk_object_get_data (GTK_OBJECT (widget), "LABEL");

      if (type == 0)
	{
	  char buff[255];
	  sprintf (buff, "%d/%d", rb, entry);
	  gtk_label_set_text (GTK_LABEL (label), buff);
	}

    }
  return;
}




void
make_dropable (GtkWidget * label, GtkWidget * evt)
{
  gtk_drag_dest_set (evt, GTK_DEST_DEFAULT_ALL, target_all,
		     sizeof (target_all) / sizeof (GtkTargetEntry),
		     GDK_ACTION_MOVE | GDK_ACTION_COPY);
  gtk_signal_connect (GTK_OBJECT (evt), "drag_data_received",
		      GTK_SIGNAL_FUNC (do_drag_data_received), label);
  gtk_signal_connect (GTK_OBJECT (label), "drag_data_received",
		      GTK_SIGNAL_FUNC (do_drag_data_received), label);
}


static gboolean
evt_clicked (GtkWidget * widget, GdkEventButton * event, gpointer user_data)
{
  GtkWidget *label;
  int rb;
  int entry;


  label = gtk_object_get_data (GTK_OBJECT (widget), "LABEL");
  if (label)
    {
      if (event->type == GDK_2BUTTON_PRESS)
	{
	  gtk_label_set_text (GTK_LABEL (label), "____");
	}
      else
	{
	  char *s;
	  s = (char *) gtk_label_get_text (GTK_LABEL (label));
	  if (strlen (s) && strcmp (s, "____") != 0)
	    {
	      printf ("s=%s\n", s);
	      rb = -1;
	      entry = -1;
	      sscanf (s, "%d/%d", &rb, &entry);
	      printf ("rb=%d entry=%d\n", rb, entry);
	      if (rb >= 0)
		{
		  fake_clicked_ptr (rb, entry);
		}
	    }
	}
    }
  return FALSE;
}

GtkWidget *
make_table (GtkWidget * table, int ncols, int nrows, int src_block)
{
  char buff[20];
//GtkWidget *table;
//int nrows=1;
//int ncols=10;
  int x, y;
  GtkWidget *label;
  GtkWidget *evt;
  int disable = 0;
  int onc;
  int onr;
  int mnc;
  int mnr;

  if (nrows < 1)
    {
      nrows = 1;
      disable = 1;
    }
  else
    {
      disable = 0;
    }

  if (ncols<=0) {
	ncols=10; // some nice default value..
  }

  if (table == 0)
    {
      table = gtk_table_new (1, nrows, ncols);
    }
  else
    {
      gtk_table_resize (GTK_TABLE (table), nrows, ncols);
    }

  //printf("%d cols %d rows\n",ncols,nrows);

  onc = (int) gtk_object_get_data (GTK_OBJECT (table), "COLS");
  onr = (int) gtk_object_get_data (GTK_OBJECT (table), "ROWS");


  if (onr < nrows)
    mnr = nrows;
  else
    mnr = onr;
  if (onc < ncols)
    mnc = ncols;
  else
    mnc = onc;

  //printf("old = %d,%d max=%d,%d new=%d,%d\n",onc,onr,mnc,mnr,ncols,nrows);

  for (y = 0; y < mnr; y++)
    {
      for (x = 0; x < mnc; x++)
	{
	  //printf("Look at %d %d\n",x,y);
	  sprintf (buff, "CELL_EVT_%d_%d", x, y);
	  evt = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (table), buff);
	  sprintf (buff, "CELL_LABEL_%d_%d", x, y);
	  label =
	    (GtkWidget *) gtk_object_get_data (GTK_OBJECT (table), buff);

	  if (evt != 0)
	    {
	      if (y >= nrows || x >= ncols)
		{
		  //printf("Hide %d %d\n",x,y);
		  gtk_widget_hide (evt);
		}
	      else
		{
		  //printf("Show\n");
		  gtk_widget_show (evt);
		}
	    }
	  else
	    {
	      //printf("No event\n");
	    }
	  if (label != 0)
	    {
	      if (y >= nrows || x >= ncols)
		{
		  //printf("Hide %d %d\n",x,y);
		  gtk_widget_hide (label);
		}
	      else
		{
		  //printf("Show\n");
		  gtk_widget_show (label);
		}
	    }
	  else
	    {
	      //printf("No label\n");
	    }

	}
    }


  gtk_object_set_data (GTK_OBJECT (table), "COLS", (void *) ncols);
  gtk_object_set_data (GTK_OBJECT (table), "ROWS", (void *) nrows);


  for (x = 0; x < ncols; x++)
    {
      for (y = 0; y < nrows; y++)
	{
	  sprintf (buff, "CELL_EVT_%d_%d", x, y);
	  evt = gtk_object_get_data (GTK_OBJECT (table), buff);
	  if (evt == 0)
	    {
	      evt = gtk_event_box_new ();
	    }
	  if (disable)
	    {
	      gtk_widget_set_name (evt, "CELL_DISABLE");
	    }
	  else
	    {
	      gtk_widget_set_name (evt, "CELL");
	    }
	  sprintf (buff, "CELL_LABEL_%d_%d", x, y);
	  label = gtk_object_get_data (GTK_OBJECT (table), buff);
	  if (label == 0)
	    {
	      label = gtk_label_new ("____");
	    }


	  if (gtk_object_get_data (GTK_OBJECT (evt), "LABEL") == 0)
	    {
	      //printf("Event Add\n");
	      gtk_container_add (GTK_CONTAINER (evt), label);
	    }

	  gtk_object_set_data (GTK_OBJECT (label), "BLOCK",
			       (void *) src_block);
	  gtk_object_set_data (GTK_OBJECT (evt), "BLOCK", (void *) src_block);

	  gtk_object_set_data (GTK_OBJECT (label), "EVT", evt);



	  g_signal_connect (G_OBJECT (evt), "button_press_event",
			    G_CALLBACK (evt_clicked), NULL);


	  gtk_object_set_data (GTK_OBJECT (evt), "LABEL", label);
	  gtk_object_set_data (GTK_OBJECT (label), "TABLE", table);
	  gtk_object_set_data (GTK_OBJECT (evt), "TABLE", table);
	  gtk_widget_set_name (label, "CELL");

	  gtk_drag_source_set (evt, GDK_BUTTON1_MASK | GDK_BUTTON2_MASK,
			       target_entry,
			       sizeof (target_entry) /
			       sizeof (GtkTargetEntry),
			       GDK_ACTION_MOVE | GDK_ACTION_COPY);
	  gtk_signal_connect (GTK_OBJECT (evt), "drag_data_get",
			      GTK_SIGNAL_FUNC (do_data_get_from_layout), evt);

	  gtk_widget_show (label);
	  gtk_widget_show (evt);
	  sprintf (buff, "CELL_EVT_%d_%d", x, y);

	  if (gtk_object_get_data (GTK_OBJECT (table), buff) == 0)
	    {
	      //printf("Table Add\n");
	      gtk_table_attach (GTK_TABLE (table), evt, x, x + 1, y, y + 1, 0,
				0, 2, 2);
	    }

	  sprintf (buff, "CELL_EVT_%d_%d", x, y);
	  gtk_object_set_data (GTK_OBJECT (table), buff, evt);

	  sprintf (buff, "CELL_LABEL_%d_%d", x, y);
	  gtk_object_set_data (GTK_OBJECT (table), buff, label);

	  make_dropable (label, evt);
	}
    }

  gtk_widget_show (table);
  return table;
}

void
resize_table (GtkWidget * table, int nlines, int ncols,int src_block)
{
  printf ("Resize %p to %d lines\n", table, nlines);
  table = make_table (table, ncols, nlines, src_block);
}

void
sb_value_changed (GtkSpinButton * spinbutton, gpointer user_data)
{
  resize_table (GTK_WIDGET (user_data), gtk_spin_button_get_value_as_int (spinbutton), -1,(int) gtk_object_get_data (GTK_OBJECT (spinbutton), "BLOCK"));
}

GtkWidget *
create_block (int n,void *vrbx,int rbs)
{
  GtkWidget *vbox;
  GtkWidget *label;
  //GtkWidget *nlines;
  GtkWidget *sb;
  GtkWidget *hbox;
  GtkWidget *hsep;
  GtkWidget *table;
  struct s_rbx *rbx;
  char buff[256];
// separator & hbox & grid in a vbox
// labels + sb in hbox
//
  vbox = gtk_vbox_new (0, 0);
  hbox = gtk_hbox_new (0, 0);
  hsep = gtk_hseparator_new ();
  rbx=vrbx;


  gtk_container_add (GTK_CONTAINER (vbox), hsep);
  sprintf (buff, "Block : %d (%c %s %d)", n, rbx[n].where, rbx[n].why,
	   rbx[n].rb);
  label = gtk_label_new (buff);
  gtk_widget_set_usize (GTK_WIDGET (label), 300, 20);
  gtk_misc_set_alignment (GTK_MISC (label), 0, 0);

  gtk_widget_show (label);
  gtk_container_add (GTK_CONTAINER (hbox), label);

  gtk_box_set_child_packing (GTK_BOX (hbox), label, 0, 0, 0, GTK_PACK_START);
  label = gtk_label_new ("Lines ");
  gtk_widget_show (label);
  gtk_misc_set_alignment (GTK_MISC (label), 1.0, 0.0);
  gtk_container_add (GTK_CONTAINER (hbox), label);
  gtk_box_set_child_packing (GTK_BOX (hbox), label, 1, 1, 0, GTK_PACK_START);

  sb = create_integer_spin_button ();
  gtk_entry_set_width_chars (GTK_ENTRY (sb), 5);
  gtk_container_add (GTK_CONTAINER (hbox), sb);
  gtk_box_set_child_packing (GTK_BOX (hbox), sb, 0, 0, 0, GTK_PACK_START);
  gtk_object_set_data (GTK_OBJECT (sb), "BLOCK", (void *) n);
  gtk_container_add (GTK_CONTAINER (vbox), hbox);

  table = make_table (0, -1, 1, n);
  gtk_container_add (GTK_CONTAINER (vbox), table);
  gtk_object_set_data (GTK_OBJECT (sb), "TABLE", table);

  gtk_widget_show (label);
  gtk_widget_show (sb);
  gtk_widget_show (hbox);
  gtk_widget_show (vbox);
  gtk_signal_connect (GTK_OBJECT (sb), "value-changed",
		      GTK_SIGNAL_FUNC (sb_value_changed), table);
  if (n >= nblock_tables)
    {
      block_tables = realloc (block_tables, sizeof (GtkWidget *) * (n + 1));
      nblock_tables = n;
      block_tables[n] = table;
    }
  return vbox;
}


void
do_data_get (GtkWidget * widget, GdkDragContext * dc,
	     GtkSelectionData * selection_data, guint info, guint t,
	     gpointer data)
{
  char text[256];
  int rb;
  int entry;
  rb = (int) gtk_object_get_data (GTK_OBJECT (widget), "RB");
  entry = (int) gtk_object_get_data (GTK_OBJECT (widget), "ENTRY");
  sprintf (text, "%d %d 0", rb, entry);

  gtk_selection_data_set (selection_data, GDK_SELECTION_TYPE_STRING, 8,	/* 8 bits per character. */
			  text, strlen (text));
  printf ("do_data_get\n");
}

void
do_data_get_from_layout (GtkWidget * widget, GdkDragContext * dc,
			 GtkSelectionData * selection_data, guint info,
			 guint t, gpointer data)
{
  char text[256];
  int rb;
  int entry;
  GtkWidget *label;
  printf ("do_get_data\n");
  label = gtk_object_get_data (GTK_OBJECT (widget), "LABEL");
  if (label)
    {
      char *s;
      s = (char *) gtk_label_get_text (GTK_LABEL (label));
      if (strlen (s) && strcmp (s, "____") != 0)
	{
	  printf ("s=%s\n", s);
	  rb = -1;
	  entry = -1;
	  sscanf (s, "%d/%d", &rb, &entry);
	  printf ("rb=%d entry=%d\n", rb, entry);
	  if (rb >= 0)
	    {
	      sprintf (text, "%d %d 0", rb, entry);
	      gtk_selection_data_set (selection_data,
				      GDK_SELECTION_TYPE_STRING, 8,
				      /* 8 bits per character. */ text,
				      strlen (text));
	      gtk_label_set_text (GTK_LABEL (label), "____");

	    }
	}
    }
}



void
do_data_get_block (GtkWidget * widget, GdkDragContext * dc,
		   GtkSelectionData * selection_data, guint info, guint t,
		   gpointer data)
{
  char text[256];
  int rb;
  rb = (int) gtk_object_get_data (GTK_OBJECT (widget), "RB");
  sprintf (text, "%d -1 1", rb);
  gtk_selection_data_set (selection_data, GDK_SELECTION_TYPE_STRING, 8,	/* 8 bits per character. */
			  text, strlen (text));
  printf ("do_data_get : Block\n");
}




void
LR_setup_entry (void *report, int b, int e,  void *ev,void *lb)
{
GtkWidget * evt; GtkWidget * label;
evt=ev;
label=lb;
  gtk_drag_source_set (evt, GDK_BUTTON1_MASK | GDK_BUTTON2_MASK, target_entry,
		       sizeof (target_entry) / sizeof (GtkTargetEntry),
		       GDK_ACTION_MOVE | GDK_ACTION_COPY);
  gtk_signal_connect (GTK_OBJECT (evt), "drag_data_get",
		      GTK_SIGNAL_FUNC (do_data_get), evt);
}




void
LR_setup_block (void *report, int b,  void *ev, void *lb)
{
GtkWidget * evt; GtkWidget * label;
evt=ev;
label=lb;
  gtk_drag_source_set (evt, GDK_BUTTON1_MASK | GDK_BUTTON2_MASK, target_block,
		       sizeof (target_block) / sizeof (GtkTargetEntry),
		       GDK_ACTION_MOVE | GDK_ACTION_COPY);
  gtk_signal_connect (GTK_OBJECT (evt), "drag_data_get",
		      GTK_SIGNAL_FUNC (do_data_get_block), evt);
}


void
LR_default_file (void *report,void *rbx, int rbs)
{
  struct csv_report_layout *d;
  char buff[2048];
  d=default_csv(buff,rbx,rbs);
  if (d) {
	remake_table_from_layout(d,rbx,rbs);
  } else {
	msgbox("Failed to create default layout",buff);
  }
}


void
LR_preview_file (void *report)
{
  printf ("preview_file not implemented\n");
}


int LR_save_file(void *report,FILE *fout,void *vrbx, int rbs) {
int a;
GtkWidget *table;
int x;
int y;
int rows;
int cols;
char buff[256];
GtkWidget *label;
char *s;
int rb;
int entry;
struct csv_entry *centry;
struct csv_report_layout out;
struct csv_report_layout *csv_report_layout;
struct s_rbx *rbx;
rbx=vrbx;




/* 
   First we need to copy out of the tables and into some
   generic structure that we can easily read & write
*/
out.nblocks=rbs;
out.blocks=malloc(sizeof(struct csv_blocks)*(out.nblocks+1));

for (a=0;a<rbs;a++) {
	table=block_tables[a];
	if (!table) {
			printf("Internal error - no table\n");
			return 0;
	}
  	cols=(int)gtk_object_get_data (GTK_OBJECT (table), "COLS");
  	rows=(int)gtk_object_get_data (GTK_OBJECT (table), "ROWS");
	out.blocks[a].nrows=rows;
	out.blocks[a].ncols=cols;
	out.blocks[a].matrix=malloc(sizeof(struct csv_entry *)*(out.blocks[a].nrows+1));

        for (y=0;y<out.blocks[a].nrows;y++) {
                out.blocks[a].matrix[y]=(struct csv_entry *)malloc(sizeof(struct csv_entry)*(out.blocks[a].ncols+1));
		memset(out.blocks[a].matrix[y],0,sizeof(struct csv_entry)*(out.blocks[a].ncols+1));

        	for (x=0;x<out.blocks[a].ncols;x++) {
			centry=out.blocks[a].matrix[y];
			centry[x].rb=-1;
			centry[x].entry=-1;
			centry[x].special=0;
		}
	}

	for (y=0;y<rows;y++) {
		for (x=0;x<cols;x++) {
	  		sprintf (buff, "CELL_LABEL_%d_%d", x, y);
			label=gtk_object_get_data(GTK_OBJECT(table),buff);
			if (label) {
				s=(char *)gtk_label_get_text(GTK_LABEL(label));
				if (s&&strlen(s)&&strcmp(s,"____")!=0) {
					rb=-1;
					entry=-1;
					sscanf(s,"%d/%d",&rb,&entry);
					if (rb!=-1) {
						centry=out.blocks[a].matrix[y];
						centry[x].rb=rb;
						centry[x].entry=entry;
						centry[x].special=0;
					} 
				} 
			} 
		}
	}
}


csv_report_layout=&out;

write_csv(fout,csv_report_layout);

return 1;
}







int LR_load_file(void *report,FILE *fin,void *rbx, int rbs) {
struct csv_report_layout *in;

in=read_csv(fin);

if (!in) {
	msgbox("Unable to load","Report layout appears bad");
}

if (in->nblocks!=rbs) {
	msgbox("Unable to load","Report layout appears bad");
	return 0;
}
return remake_table_from_layout(in,rbx,rbs);
}



int remake_table_from_layout(struct csv_report_layout *in,void *rbx,int rbs) {
GtkWidget *table;
int x;
int y;
int a;
int rows;
int cols;
char buff[256];
GtkWidget *label;
int rb;
int entry;
struct csv_entry *centry;

for (a=0;a<rbs;a++) {
	table=block_tables[a];
	if (!table) {
		printf("Internal error - no table\n");
		return 0;
	}

	rows=in->blocks[a].nrows;
	cols=in->blocks[a].ncols;

	resize_table(table,rows?rows:1,cols,a);

	for (y=0;y<rows;y++) {
		for (x=0;x<cols;x++) {
			centry=in->blocks[a].matrix[y];
			rb=centry[x].rb;
			entry=centry[x].entry;
			printf("rb=%d entry=%d x=%d y=%d block=%d\n",rb,entry,x,y,a);
  			sprintf (buff, "CELL_LABEL_%d_%d", x, y);
			label=gtk_object_get_data(GTK_OBJECT(table),buff);
			if (rb>=0) {
				sprintf(buff,"%d/%d",rb,entry);
				gtk_label_set_text(GTK_LABEL(label),buff);
			} else {
				gtk_label_set_text(GTK_LABEL(label),"____");
			}
		}
	}
}
return 1;
}



