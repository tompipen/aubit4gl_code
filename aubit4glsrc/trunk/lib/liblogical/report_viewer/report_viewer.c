#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "../common/a4gl_lle.h"

void setup_entry(int b,int e,GtkWidget *evt,GtkWidget *lab);
GtkWidget *window;
GtkWidget *notebook;

FILE *fin;

#define XWIDTH 8
#define YHEIGHT 13

#define MIN_PAGE 10
#define MAX_PAGE 10

int last_rb = -1;
int last_entry = -1;
int last_block = -1;

static void add_widget (int rb, int evt, GtkWidget * w);
void edit_lle ();
static void select_widgets (int rb, int evt);
static void unselect_widgets (int rb, int evt);
static int find_block_where (char w1, char *w2);
static int add_block_where (char w1, char *w2);
static void add_widget_block_where (char w1, char *w2, GtkWidget * widget);
static void select_block (int rb);
static void unselect_block (int rb);

char *style_selected = "style \"selected\" {font_name=\"monospace 6\" bg[NORMAL] = \"#ffff77\"} widget \"*.selected\" style \"selected\"";
char *style_unselected = "style \"unselected\" {font_name=\"monospace 6\" bg[NORMAL] = \"#eeeeee\" } widget \"*.unselected\" style \"unselected\"";
char *style_unselectable = "style \"unselectable\" {font_name=\"monospace 6\" bg[NORMAL] = \"#ffffff\" } widget \"*.unselectable\" style \"unselectable\"";


//extern struct r_report *report;

int selectable = 1;



/* ******************************************************************************** */
#ifdef MOVED_TO_MAIN_C
main (int argc, char *argv[])
{
  int npages;
  char buff[256];
  int buff_i;
  char buff_c;


  if (argc != 2)
    {
      printf ("Usage : %s filename\n", argv[0]);
      exit (1);
    }


  report = read_report_output (argv[1]);
  if (report == 0)
    {
      printf ("Unable to open input file : %s\n", argv[1]);
      exit (2);
    }

  gtk_init (&argc, &argv);

  printf ("Time    : %s\n", ctime (&report->ctime));

  printf ("Pages : %d maximum lines/page :%d maximum column position:%d\n",
	  report->max_page, report->max_line, report->max_col);

  gtk_rc_parse_string (style_selected);
  gtk_rc_parse_string (style_unselected);
  gtk_rc_parse_string (style_unselectable);

  gtk_rc_parse_string
    ("style \"fixed\" { bg[NORMAL] = \"#ffffff\" } widget \"*.fixed\" style \"fixed\"");


  edit_lle ();
}
#endif





/* ******************************************************************************** */


static
unselect_all ()
{
  if (last_rb != -1 && last_entry != -1)
    {
      unselect_widgets (last_rb, last_entry);
    }
  if (last_block != -1)
    unselect_block (last_block);
  last_block = -1;
  last_rb = -1;
  last_entry = -1;
}

/* ******************************************************************************** */

static gboolean
label_clicked (GtkWidget * widget, GdkEventButton * event, gpointer user_data)
{
  GtkWidget *status;
  char *style;
  char txt[255];
  char rc_string[256];
  int rb;
  int entry;
  if (!selectable)
    return TRUE;
  unselect_all ();

  rb = (int) gtk_object_get_data (GTK_OBJECT (widget), "RB");
  entry = (int) gtk_object_get_data (GTK_OBJECT (widget), "ENTRY");

  sprintf (txt, "Status: Block %d Entry %d selected", rb, entry);
  status = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (window), "STATUS");


  if (status)
    {
      gtk_label_set_text (GTK_LABEL (status), txt);
    }

  last_rb = rb;
  last_entry = entry;
  select_widgets (last_rb, last_entry);
  set_clicked(rb,entry);

  return TRUE;
}


int fake_clicked(int rb,int entry) {
  unselect_all ();
  if (entry>=0) {
  	last_rb = rb;
  	last_entry = entry;
  	select_widgets (last_rb, last_entry);
  	set_clicked(rb,entry);
  } else {
  	select_block (rb);
  	last_block = rb;
  	set_block_clicked(rb);
  }

}



/* ******************************************************************************** */

static gboolean
evt_clicked (GtkWidget * widget, GdkEventButton * event, gpointer user_data)
{
  printf ("EVT CLICKED\n");
  label_clicked (widget, event, user_data);
  return FALSE;
}



static gboolean
label_clicked_block (GtkWidget * widget, GdkEventButton * event,
		     gpointer user_data)
{
  GtkWidget *status;
  char *style;
  char txt[255];
  char rc_string[256];
  int block;
  char *where_why;

  if (!selectable)
    return TRUE;
  unselect_all ();

  where_why = (char *) gtk_object_get_data (GTK_OBJECT (widget), "BLOCK_TXT");
  block = (int) gtk_object_get_data (GTK_OBJECT (widget), "BLOCK");
  sprintf (txt, "Status: Block (%s) selected", where_why);
  status = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (window), "STATUS");


  if (status)
    {
      gtk_label_set_text (GTK_LABEL (status), txt);
    }

  select_block (block);
  last_block = block;
  set_block_clicked(block);
  return TRUE;
}


/* ******************************************************************************** */

static gboolean
evt_clicked_block (GtkWidget * widget, GdkEventButton * event,
		   gpointer user_data)
{
  label_clicked_block (widget, event, user_data);
}



/* ******************************************************************************** */
static gboolean
delete_event (GtkWidget * widget, GdkEvent * event, gpointer data)
{
  /* If you return FALSE in the "delete_event" signal handler,
   * GTK will emit the "destroy" signal. Returning TRUE means
   * you don't want the window to be destroyed.
   * This is useful for popping up 'are you sure you want to quit?'
   * type dialogs. */

  g_print ("delete event occurred\n");

  /* Change TRUE to FALSE and the main window will be destroyed with
   * a "delete_event". */

  return FALSE;
}


/* ******************************************************************************** */

/* Another callback */
static void
destroy (GtkWidget * widget, gpointer data)
{
  gtk_main_quit ();
}


/* ******************************************************************************** */

void
edit_lle ()
{
  int a;
  GtkWidget *label;
  GtkWidget *fixed;
  char buff[255];
  int entry, block;
  char where_why[256];
  GtkWidget *vbox;
  GtkWidget *sw;
  char desc[256];

#define DRAG_TARGET_NAME_0 "ReportBlock"
#define DRAG_TARGET_INFO_0 0

  GtkTargetEntry target_entry[]={
	{DRAG_TARGET_NAME_0,0,DRAG_TARGET_INFO_0}
  };

  /* This is called in all GTK applications. Arguments are parsed
   * from the command line and are returned to the application. */

  gtk_rc_parse_string (style_selected);
  gtk_rc_parse_string (style_unselected);
  gtk_rc_parse_string (style_unselectable);

  gtk_rc_parse_string
    ("style \"fixed\" { bg[NORMAL] = \"#ffffff\" } widget \"*.fixed\" style \"fixed\"");



  /* create a new window */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_widget_set_usize (GTK_WIDGET (window),500,300);
  sprintf(desc,"Report Output Viewer (Report : %s from Module : %s)",report->repName,report->modName);
  gtk_window_set_title (GTK_WINDOW (window), desc);

  /* When the window is given the "delete_event" signal (this is given
   * by the window manager, usually by the "close" option, or on the
   * titlebar), we ask it to call the delete_event () function
   * as defined above. The data passed to the callback
   * function is NULL and is ignored in the callback function. */
  g_signal_connect (G_OBJECT (window), "delete_event",
		    G_CALLBACK (delete_event), NULL);

  /* Here we connect the "destroy" event to a signal handler.  
   * This event occurs when we call gtk_widget_destroy() on the window,
   * or if we return FALSE in the "delete_event" callback. */
  g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);


  notebook = gtk_notebook_new ();
  gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_LEFT);

  for (a = 0; a < report->max_page; a++)
    {
	GtkWidget *fixed2;
      if (a >= MIN_PAGE && a < report->max_page - MAX_PAGE) continue;
      sprintf (buff, "Page %d", a + 1);
      label = gtk_label_new (buff);
      fixed = gtk_fixed_new ();
      gtk_fixed_set_has_window (GTK_FIXED (fixed), 1);
      gtk_widget_set_usize (GTK_WIDGET (fixed),
			    (report->max_col + 1+report->left_margin) * XWIDTH,
			    report->page_length * YHEIGHT);
      gtk_widget_set_name (fixed, "fixed");
      gtk_object_set_data (GTK_OBJECT (notebook), buff, fixed);

      gtk_notebook_append_page (GTK_NOTEBOOK (notebook), fixed, label);
    }



  vbox = gtk_vbox_new (0, 0);



  gtk_container_add (GTK_CONTAINER (window), vbox);

	
  label = gtk_label_new ("Your Report");
  gtk_container_add (GTK_CONTAINER (vbox), label);
  gtk_box_set_child_packing (GTK_BOX (vbox), label, 0, 0, 0, GTK_PACK_START);




  sw = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (sw), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_widget_show (sw);
  gtk_container_add (GTK_CONTAINER (vbox), sw);
	fixed=gtk_fixed_new();
  gtk_fixed_put(fixed, notebook,0,0);
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(sw),fixed);


  label = gtk_label_new ("Status: Nothing selected");
  gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
  gtk_container_add (GTK_CONTAINER (vbox), label);
  gtk_box_set_child_packing (GTK_BOX (vbox), label, 0, 0, 0, GTK_PACK_END);


  gtk_object_set_data (GTK_OBJECT (window), "STATUS", label);


  for (block = 0; block < report->nblocks; block++)
    {
      for (entry = 0; entry < report->blocks[block].nentries; entry++)
	{
	  struct r_report_block_entries *centry;
	  int x, y;
	  centry = &report->blocks[block].entries[entry];
	  sprintf (buff, "Page %d", centry->page_no);
	  fixed =
	    (GtkWidget *) gtk_object_get_data (GTK_OBJECT (notebook), buff);
	  if (fixed)
	    {
	      char rc_string[256];
	      char buff_style[256];
	      GtkWidget *evt;

	      sprintf (where_why, "%c %s", report->blocks[block].where, report->blocks[block].why);

	      sprintf (desc, "%c %s %d %d", report->blocks[block].where, report->blocks[block].why, report->blocks[block].rb, centry->entry_id);
	      evt = gtk_event_box_new ();
	      gtk_object_set_data (GTK_OBJECT (evt), "RB", (void *) report->blocks[block].rb);
	      gtk_object_set_data (GTK_OBJECT (evt), "ENTRY", (void *) centry->entry_id);

	      label = gtk_label_new (centry->string);

	      g_signal_connect (G_OBJECT (evt), "button_press_event", G_CALLBACK (evt_clicked), NULL);
	      g_signal_connect (G_OBJECT (label), "button_press_event", G_CALLBACK (label_clicked), NULL);

	      gtk_object_set_data (GTK_OBJECT (label), "RB", (void *) report->blocks[block].rb);
	      gtk_object_set_data (GTK_OBJECT (label), "ENTRY", (void *) centry->entry_id);
	      gtk_object_set_data (GTK_OBJECT (label), "DESCRIPTION", (void *) desc);


		setup_entry(block,entry,evt,label);

                //gtk_drag_source_set( evt, GDK_BUTTON1_MASK | GDK_BUTTON2_MASK, target_entry, sizeof(target_entry) / sizeof(GtkTargetEntry), GDK_ACTION_MOVE | GDK_ACTION_COPY);


	      add_widget (report->blocks[block].rb, centry->entry_id, evt);
	      add_widget (report->blocks[block].rb, centry->entry_id, label);

	      if (selectable)
		{
		  gtk_widget_set_name (GTK_WIDGET (label), "unselected");
		  gtk_widget_set_name (GTK_WIDGET (evt), "unselected");
		}
	      else
		{
		  gtk_widget_set_name (GTK_WIDGET (label), "unselectable");
		  gtk_widget_set_name (GTK_WIDGET (evt), "unselectable");
		}

	      x = (centry->col_no + report->left_margin) * XWIDTH;
	      y = (centry->line_no + report->top_margin) * YHEIGHT;

	      gtk_fixed_put (GTK_FIXED (fixed), evt, x, y);
	      gtk_container_add (GTK_CONTAINER (evt), label);
	      sprintf (buff, "Line %d", centry->line_no);


	      if (gtk_object_get_data (GTK_OBJECT (fixed), buff) == 0
		  && selectable)
		{
		  label = gtk_label_new (">");
		  evt = gtk_event_box_new ();
		  gtk_widget_set_name (GTK_WIDGET (label), "unselected");
		  gtk_widget_set_name (GTK_WIDGET (evt), "unselected");

		  setup_block(block,evt,label);
		  add_widget_block_where(report->blocks[block].where, report->blocks[block].why,label);
		  add_widget_block_where(report->blocks[block].where, report->blocks[block].why,evt);

		  gtk_object_set_data (GTK_OBJECT (evt), "BLOCK_TXT",
				       (void *) strdup (where_why));
		  gtk_object_set_data (GTK_OBJECT (evt), "BLOCK",
				       (void *) find_block_where (report->
								  blocks
								  [block].
								  where,
								  report->
								  blocks
								  [block].
								  why));


		  gtk_container_add (GTK_CONTAINER (evt), label);
		  gtk_fixed_put (GTK_FIXED (fixed), evt, 0, y);
		  g_signal_connect (G_OBJECT (evt), "button_press_event",
				    G_CALLBACK (evt_clicked_block), NULL);
		  g_signal_connect (G_OBJECT (label), "button_press_event",
				    G_CALLBACK (label_clicked_block), NULL);
		  gtk_object_set_data (GTK_OBJECT (fixed), buff,
				       (void *) evt);
		}

	    }
	}
    }
  gtk_widget_show_all (window);


}



/* ******************************************************************************** */


struct rb_event_widgets
{
  int nwidgets;
  GtkWidget **widgets;
};

struct rb_widgets
{
  int nevt;
  struct rb_event_widgets *evt;
};


struct rb_widgets *block_widgets = 0;
int block_widgets_cnt = 0;



/* ******************************************************************************** */

static void
add_widget (int rb, int evt, GtkWidget * w)
{
struct rb_widgets *bwidgets;
struct rb_event_widgets *ewidgets;


/* make sure our block is allocated.. */
  while (rb >= block_widgets_cnt)
    {
      block_widgets_cnt++;
      block_widgets =
	(struct rb_widgets *) realloc (block_widgets,
				       sizeof (struct rb_widgets) *
				       block_widgets_cnt);
      block_widgets[block_widgets_cnt - 1].nevt = 0;
      block_widgets[block_widgets_cnt - 1].evt = 0;
    }

   bwidgets=&block_widgets[rb];

/* Make sure our widget list is allocated */

  while (evt >= bwidgets->nevt)
    {
      bwidgets->nevt++;
      bwidgets->evt = (struct rb_event_widgets *) realloc (bwidgets->evt, sizeof (struct rb_event_widgets) * bwidgets->nevt);
	
      bwidgets->evt[bwidgets->nevt - 1].nwidgets = 0;
      bwidgets->evt[bwidgets->nevt - 1].widgets = 0;
    }

/* Finally - add our widget */
  ewidgets=&bwidgets->evt[evt];

  ewidgets->nwidgets++;
  ewidgets->widgets = (GtkWidget **) realloc (ewidgets->widgets, sizeof (GtkWidget *) * ewidgets->nwidgets);

  ewidgets->widgets[ewidgets->nwidgets-1]=w;

}





/* ******************************************************************************** */
static void
select_widgets (int rb, int evt)
{
  int a;
  struct rb_event_widgets *x;
  printf ("select %d %d\n", rb, evt);
  x = &block_widgets[rb].evt[evt];
  for (a = 0; a < x->nwidgets; a++)
    {
      gtk_widget_set_name (x->widgets[a], "selected");
    }

}

/* ******************************************************************************** */
static void
unselect_widgets (int rb, int evt)
{
  int a;
  struct rb_event_widgets *x;
  printf ("unselect %d %d\n", rb, evt);
  x = &block_widgets[rb].evt[evt];
  for (a = 0; a < x->nwidgets; a++)
    {
      gtk_widget_set_name (x->widgets[a], "unselected");
    }

}


/* ******************************************************************************** */

struct block_indicator
{
  char where_why[128];
  int nwidgets;
  GtkWidget **widgets;
};

struct block_indicator *bi = 0;
int bi_cnt = 0;


/* ******************************************************************************** */
static int
find_block_where (char w1, char *w2)
{
  int a;
  char buff[256];
  sprintf (buff, "%c%s", w1, w2);
  for (a = 0; a < bi_cnt; a++)
    {
      if (strcmp (buff, bi[a].where_why) == 0)
	{
	  return a;
	}
    }
  return -1;
}


/* ******************************************************************************** */
static int
add_block_where (char w1, char *w2)
{
  char buff[256];
  int a;
  a = find_block_where (w1, w2);
  if (a != -1)
    return a;
  sprintf (buff, "%c%s", w1, w2);
  bi_cnt++;
  bi =
    (struct block_indicator *) realloc (bi,
					sizeof (struct block_indicator) *
					bi_cnt);
  strcpy (bi[bi_cnt - 1].where_why, buff);
  bi[bi_cnt - 1].nwidgets = 0;
  bi[bi_cnt - 1].widgets = 0;
  return bi_cnt - 1;
}

/* ******************************************************************************** */
static void
add_widget_block_where (char w1, char *w2, GtkWidget * widget)
{
  int a;
  a = add_block_where (w1, w2);
//printf("a=%d\n",a);
  bi[a].nwidgets++;
  bi[a].widgets =
    (GtkWidget **) realloc (bi[a].widgets,
			    sizeof (GtkWidget *) * bi[a].nwidgets);
  bi[a].widgets[bi[a].nwidgets - 1] = widget;
}

/* ******************************************************************************** */
static void
select_block (int rb)
{
  int a;
  for (a = 0; a < bi[rb].nwidgets; a++)
    {
      gtk_widget_set_name (bi[rb].widgets[a], "selected");
    }

}

/* ******************************************************************************** */
static void
unselect_block (int rb)
{
  int a;
  for (a = 0; a < bi[rb].nwidgets; a++)
    {
      gtk_widget_set_name (bi[rb].widgets[a], "unselected");
    }

}
