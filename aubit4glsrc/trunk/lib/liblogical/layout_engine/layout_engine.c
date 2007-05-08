#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
//#define NOUNIXHEADERS
#define NOSTRCPYMAP
#include "a4gl_libaubit4gl.h"
#include "../common/a4gl_lle.h"
#include "API_layout.h"

GtkWidget *window;
char * create_file_selection (char *fname);

struct r_report *rep;

#define XWIDTH 10
#define YHEIGHT 15
int fake_clicked(int a,int b);

static int save_file_internal(char *fname) ;
GtkWidget *create_block (int n);
void msgbox (char *title, char *txt);
static void quit_program (void);
static void save_file (void);
static void start_lle (void);
static void load_file (void);
static void open_rv (void);
static void open_pal (void);
static int load_lrf(char *fname) ;
void set_block_clicked (int rb);
void set_clicked (int rb, int entry);
void setup_entry (int b, int e, GtkWidget * evt, GtkWidget * label);
void setup_block (int b, GtkWidget * evt, GtkWidget * label);
void edit_lle(struct r_report *r);
char sendLRFto[200]="";
int rbs;
char lastLRF[200]=""; 	// Last LRF filename
			// normally loaded from the command line...


char defaultDir[200]=".";

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
  char *fake_argv[100];
  int fake_argc;
  int a;
  int save_new=0;

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
  
  fake_argc=1;

  for (a=1;a<argc;a++) {
		if (strcmp(argv[a],"-display")==0) {
			a++;
			A4GL_setenv("DISPLAY", argv[a],1);
			continue;
		}

		if (strcmp(argv[a],"-sendto")==0) {
			a++;
			strcpy(sendLRFto,argv[a]);
			continue;
		}
		if (strcmp(argv[a],"-defaultdir")==0) {
			a++;
			strcpy(defaultDir,argv[a]);
			continue;
		}

		if (strcmp(argv[a],"-lrf")==0) {
			a++;
			sprintf(lastLRF, "%s", argv[a]);
			continue;
		}


		fake_argv[fake_argc++]= argv[a];
  }

  if (fake_argc != 3)
    {
      printf ("Usage %s type file-name\n", argv[0]);
      exit (1);
    }

  report_internal = read_report_output (fake_argv[2]);

  if (report_internal == 0)
    {
      printf ("Unable to open report output\n");
      exit (2);
    }

  input_fname = fake_argv[2];

  A4GL_convupper (fake_argv[1]);
  sprintf (buff_env, "LOGREP=%s", fake_argv[1]);
  A4GL_setenv ("LOGREP", fake_argv[1], 1);
  A4GLLOGREP_initlib ();

  obtain_rbs_rbx(report_internal,&rbs,&rbx);

  gtk_init (&argc, &argv);

  //gtk_rc_parse_string (style_cell);
  //gtk_rc_parse_string (style_cell_disable);

  start_lle ();
  edit_lle (report_internal);
  if (strlen(lastLRF)) {
		char orig[2000];
		strcpy(orig, lastLRF);
			if (!load_lrf(lastLRF)) {
				// Try in the default diectory...
				sprintf(lastLRF, "%s/%s", defaultDir, orig);
				if (!load_lrf(lastLRF)) {
					// Still nothing...
					// must be new...
					save_new=1;
				}
			}
		}

  if (save_new ) {
	printf("Autosave new file\n");
	save_file_internal(lastLRF);
  }

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
  char *fname;
  int ok;
  fname = create_file_selection (lastLRF);
  if (fname)
    {
 ok=save_file_internal(fname);
      if (!ok) { msgbox ("Some error during save", "Warning - No save performed..."); }
  } else
    {
      msgbox ("Save Aborted", "No save performed...");
    }
}

int save_file_internal(char *fname) {
  FILE *fout;
  int ok;
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

      fclose (fout);

	return ok;
}


int load_lrf(char *fname) {
  FILE *fin=0;
  int ok=0;
  char buff[255]="Error loading file";

        if (load_filter_file_header(fname,&fin,buff)) {
                ok=LR_load_file (report_internal, fin,rbx,rbs);
        } 
	if (fin) {
        	fclose(fin);
	}
	if (!ok)  {
		printf("Unable to open lrf file (fname=%s)\n",fname);
		return 0;
	}
	return 1;
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
	
  fname = create_file_selection (lastLRF);

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
	printf("report_internal->repName=%s\n", report_internal->repName);
	printf("report_internal->modName=%s\n", report_internal->modName);
  sprintf (desc, "Logical Layout Engine (Report : %s from Module : %s)", report_internal->repName, report_internal->modName);
printf("DESCRIPTION: %s\n", desc);
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





#ifdef strcat
#undef strcat
#endif

char *A4GL_strcat(char *a,char *b,char *f,int l,int sd) {
	return strcat(a,b);
}
