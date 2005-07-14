#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
//#define NOUNIXHEADERS
#include "a4gl_libaubit4gl.h"
#include "../common/a4gl_lle.h"
#include "API_layout.h"

GtkWidget *window;
char * create_file_selection (char *fname);

struct r_report *rep;

#define XWIDTH 10
#define YHEIGHT 15
int fake_clicked(int a,int b);

GtkWidget *create_block (int n);
void msgbox (char *title, char *txt);
static void quit_program (void);
static void save_file (void);
static void start_lle (void);
static void load_file (void);
static void open_rv (void);
static void open_pal (void);
void set_block_clicked (int rb);
void set_clicked (int rb, int entry);
void setup_entry (int b, int e, GtkWidget * evt, GtkWidget * label);
void setup_block (int b, GtkWidget * evt, GtkWidget * label);
void edit_lle(struct r_report *r);


int rbs;



struct r_report *report_internal;
struct s_rbx *rbx = 0;


char *input_fname;
int lc_entry = -1;
int lc_rb = -1;


static void
default_file (void)
{
  LR_default_file (report_internal,rbx,rbs);
}

static void
preview_file (void)
{
  LR_preview_file (report_internal);
}

/* ******************************************************************************** */

int main (int argc, char *argv[])
{
  char buff_env[256];


  //int npages;
  //char buff[256];
  //int buff_i;
  //char buff_c;
  //int c;
  //int a, b;
  //int found;
  //int block_cnt;
  //int rblock_cnt;
  //int entry_cnt;
  rbs = 0;
  rbx = 0;

  if (argc != 3)
    {
      printf ("Usage %s type file-name\n", argv[0]);
      exit (1);
    }
  report_internal = read_report_output (argv[2]);

  if (report_internal == 0)
    {
      printf ("Unable to open report output\n");
      exit (2);
    }
  input_fname = argv[2];
  A4GL_convupper (argv[1]);
  sprintf (buff_env, "LOGREP=%s", argv[1]);
  A4GL_setenv ("LOGREP", argv[1], 1);
  A4GLLOGREP_initlib ();

#ifdef MOVED_TO_COMMON

  for (a = 0; a < report_internal->nblocks; a++)
    {
      found = 0;
      if (rbs)
	{
	  for (b = 0; b < rbs; b++)
	    {
	      if (report_internal->blocks[a].rb == rbx[b].rb)
		{
		  found = 1;
		  break;
		}
	    }
	}
      if (found)
	continue;
      rbs++;
      rbx = realloc (rbx, sizeof (struct s_rbx) * rbs);
      rbx[rbs - 1].rb = report_internal->blocks[a].rb;
      rbx[rbs - 1].why = report_internal->blocks[a].why;
      rbx[rbs - 1].where = report_internal->blocks[a].where;
    }

  printf ("%d distinct blocks...\n", rbs);

  for (block_cnt = 0; block_cnt < rbs; block_cnt++)
    {
      int *tmp_space_e;
      int *tmp_space_s;
      rbx[block_cnt].max_entry = 0;
      rbx[block_cnt].entry_nos = 0;
      rbx[block_cnt].nentry_nos = 0;
      rbx[block_cnt].max_size_entry = 0;

      for (rblock_cnt = 0; rblock_cnt < report_internal->nblocks; rblock_cnt++)
	{
	  if (rbx[block_cnt].rb != report_internal->blocks[rblock_cnt].rb)
	    {
	      continue;
	    }

	  for (entry_cnt = 0; entry_cnt < report_internal->blocks[rblock_cnt].nentries;
	       entry_cnt++)
	    {
	      if (report_internal->blocks[rblock_cnt].entries[entry_cnt].entry_id >=
		  rbx[block_cnt].max_entry)
		{
		  int nmax;
		  nmax =
		    report_internal->blocks[rblock_cnt].entries[entry_cnt].entry_id +
		    1;

		  rbx[block_cnt].entry_nos =
		    realloc (rbx[block_cnt].entry_nos, sizeof (int) * (nmax));
		  rbx[block_cnt].max_size_entry =
		    realloc (rbx[block_cnt].max_size_entry,
			     sizeof (int) * (nmax));
		  for (a = rbx[block_cnt].max_entry; a < nmax; a++)
		    {
		      rbx[block_cnt].entry_nos[a] = -1;
		      rbx[block_cnt].max_size_entry[a] = 0;
		    }
		  rbx[block_cnt].max_entry = nmax;
		}

	      if (strlen
		  (report_internal->blocks[rblock_cnt].entries[entry_cnt].string))
		{
		  rbx[block_cnt].entry_nos[entry_cnt] = entry_cnt;
		  rbx[block_cnt].max_size_entry[entry_cnt] =
		    strlen (report_internal->blocks[rblock_cnt].entries[entry_cnt].
			    string);
		}
	    }
	}

      // By the time we get here - we should have all our fields sized up
      // some may not be used  - so we'll have -1 for the entry_nos.
      // Some may have a size of zero - ie they are not used..
      // Lets take these out...
      b = 0;
      tmp_space_e = malloc (sizeof (int) * rbx[block_cnt].max_entry);
      tmp_space_s = malloc (sizeof (int) * rbx[block_cnt].max_entry);
      for (a = 0; a < rbx[block_cnt].max_entry; a++)
	{
	  if (rbx[block_cnt].entry_nos[a] >= 0
	      && rbx[block_cnt].max_size_entry[a])
	    {
	      tmp_space_e[b] = rbx[block_cnt].entry_nos[a];
	      tmp_space_s[b] = rbx[block_cnt].max_size_entry[a];
	      b++;
	    }
	  else
	    {
	      printf ("Discarding block %d entry %d - %d %d\n", block_cnt, a,
		      rbx[block_cnt].entry_nos[a],
		      rbx[block_cnt].max_size_entry[a]);
	    }
	}
      rbx[block_cnt].nentry_nos = b;
      memcpy (rbx[block_cnt].entry_nos, tmp_space_e,
	      sizeof (int) * rbx[block_cnt].nentry_nos);
      memcpy (rbx[block_cnt].max_size_entry, tmp_space_s,
	      sizeof (int) * rbx[block_cnt].nentry_nos);
      free (tmp_space_e);
      free (tmp_space_s);
    }

#endif


  obtain_rbs_rbx(report_internal,&rbs,&rbx);

  gtk_init (&argc, &argv);

  //gtk_rc_parse_string (style_cell);
  //gtk_rc_parse_string (style_cell_disable);

  start_lle ();
  edit_lle (report_internal);
  gtk_main ();
return 0;
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

void quit_program (void)
{
  gtk_main_quit ();
}

void save_file (void)
{
  FILE *fout;
  char *fname;
  int ok;
  fname = create_file_selection (0);
  if (fname)
    {
      char *ptr;
      printf ("fname==%s\n", fname);
      ptr = strrchr (fname, '/');
      if (ptr == 0)
	ptr = fname;
      if (strchr (ptr, '.') == 0)
	{
	  strcat (fname, ".lrf");
	}
      printf ("fname==%s\n", fname);
      fout = fopen (fname, "w");
	if (!fout) {
		msgbox ("Can't open file", "I can't seem to write that file...");
		return;
	}
      fprintf (fout, "A4GL_LOGICAL_REPORT %s\n", acl_getenv ("LOGREP"));
      fprintf (fout, "%s %s\n", report_internal->repName, report_internal->modName);
      fprintf (fout, "%s\n", input_fname);
      ok=LR_save_file (report_internal,fout,rbx,rbs);
      if (!ok) {
		msgbox ("Some error during save", "Warning - No save performed...");
	}
      fclose (fout);
    }
  else
    {
      msgbox ("Save Aborted", "No save performed...");
    }
}

void load_file (void)
{
  FILE *fin;
  char *fname;
  int ok;
  char buff[255]="Error loading file";
  //char logrep[255];
  //char orig[255];
  //char rname[255];
  //char mname[255];
	
  fname = create_file_selection (0);

  if (fname) {
	ok=0;
  	if (load_filter_file_header(fname,&fin,buff)) {
      		ok=LR_load_file (report_internal, fin,rbx,rbs);
  	}
	fclose(fin);

   	if (!ok) {
		msgbox ("Some error during load",buff);
        }
  } else {
      msgbox ("Load Aborted", "No load performed...");
  }
}

void open_rv (void)
{
  edit_lle (report_internal);
}

void open_pal (void)
{
  printf ("Not implemented yet open_pal");
}

static void
start_lle ()
{
  /* create a new window */
  char desc[255];
  char buff[1024];

  GtkItemFactory *ifac;
  GtkAccelGroup *acc;
  GtkWidget *menu_bar;
  GtkWidget *vbox;
  GtkWidget *vbox_in_sw;
  GtkWidget *sw;
  GtkWidget *l;
  //int block;

  static GtkItemFactoryEntry entries[] = {

    {"/File/_Save Layout", "<CTRL>S", save_file, 1, "<StockItem>", GTK_STOCK_SAVE},
    {"/File/_Load Layout", "<CTRL>L", load_file, 1, "<StockItem>", GTK_STOCK_OPEN},
    {"/File/_Default", "<CTRL>D", default_file, 1, "<Item>"},
    {"/File/_Preview", "<CTRL>W", preview_file, 1, "<Item>"},
    {"/File/sep1", NULL, NULL, 0, "<Separator>"},
    {"/Source/_Report Viewer", "<CTRL>R", open_rv, 1, "<Item>"},
    {"/Source/_Palette", "<CTRL>P", open_pal, 1, "<Item>"},
    {"/File/_Quit", "<CTRL>Q", quit_program, 0, "<StockItem>", GTK_STOCK_QUIT}
  };


  acc = gtk_accel_group_new ();
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  sprintf (desc, "Logical Layout Engine (Report : %s from Module : %s)",
	   report_internal->repName, report_internal->modName);
  gtk_window_set_title (GTK_WINDOW (window), desc);
  gtk_widget_set_usize (GTK_WIDGET (window), 400, 400);

/* Menu Creation */

  ifac = gtk_item_factory_new (GTK_TYPE_MENU_BAR, "<layout_engineMain>", acc);


  gtk_item_factory_create_items (ifac,
				 sizeof (entries) /
				 sizeof (GtkItemFactoryEntry), entries, 0);
  gtk_window_add_accel_group (GTK_WINDOW (window), acc);
  menu_bar = gtk_item_factory_get_widget (ifac, "<layout_engineMain>");


  vbox = gtk_vbox_new (0, 0);
  gtk_container_add (GTK_CONTAINER (window), vbox);
  gtk_container_add (GTK_CONTAINER (vbox), menu_bar);
  gtk_box_set_child_packing (GTK_BOX (vbox), menu_bar, 0, 0, 0,
			     GTK_PACK_START);
  gtk_widget_show (menu_bar);
  sw = gtk_scrolled_window_new (0, 0);
  gtk_container_add (GTK_CONTAINER (vbox), sw);
  gtk_widget_show (sw);
  gtk_widget_show (vbox);
  vbox_in_sw = gtk_vbox_new (0, 0);
  gtk_widget_show (vbox_in_sw);
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (sw),
					 vbox_in_sw);


  sprintf (buff,
	   "Version : %d\nCtime=%d\nTop Margin=%d Bottom Margin=%d Left Margin=%d Right Margin=%d\n"
	   "Page Length=%d Max Page=%d Max Line=%d Max Col=%d",
	   report_internal->version_no, report_internal->ctime, report_internal->top_margin,
	   report_internal->bottom_margin, report_internal->left_margin, report_internal->right_margin,
	   report_internal->page_length, report_internal->max_page, report_internal->max_line,
	   report_internal->max_col);

  l = gtk_label_new (buff);
  gtk_widget_show (l);
  gtk_misc_set_alignment (GTK_MISC (l), 0, 0);
  gtk_container_add (GTK_CONTAINER (vbox_in_sw), l);

  LR_setup_callback(fake_clicked);
  LR_show_layout_rest (report_internal,vbox_in_sw,rbx,rbs);

  gtk_widget_show_all (window);

  g_signal_connect (G_OBJECT (window), "delete_event",
		    G_CALLBACK (delete_event), NULL);
  g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);

  return;
}






void set_clicked (int rb, int entry)
{
  lc_entry = entry;
  lc_rb = rb;
}

void set_block_clicked (int rb)
{
  lc_entry = -1;
  lc_rb = rb;
}


void setup_entry (int b, int e, GtkWidget * evt, GtkWidget * label)
{
  LR_setup_entry (report_internal,b, e, evt, label);
}

void setup_block (int b, GtkWidget * evt, GtkWidget * label)
{
  LR_setup_block (report_internal,b, evt, label);
}


void
msgbox (char *title, char *txt)
{
  GtkWidget *dialog;
  dialog =
    gtk_message_dialog_new (0, GTK_DIALOG_DESTROY_WITH_PARENT,
			    GTK_MESSAGE_INFO, GTK_BUTTONS_OK, txt);
  if (title)
    {
      gtk_window_set_title (GTK_WINDOW (dialog), title);
    }
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}



void *
acl_realloc_full (void *a, long b, char *r, char *f, int l)
{
  void *p;
  p = realloc (a, b);
  if (p == 0)
    {
      printf ("Unable to allocate memory\n");
      exit (2);
    }
  return p;
}
