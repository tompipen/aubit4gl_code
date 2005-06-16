#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "a4gl_libaubit4gl.h"
#include "a4gl_API_ui_lib.h"

//#define WINCODE 'w'
//#define FORMCODE 'f'
//#define IDCODE 'i'

void do_setup_list(GtkWidget *treeview,int n);
GtkWidget *actionfield;
GtkWidget *beforefield;
int onfield;
int keypressed;
void A4GL_func (GtkWidget * w, char *mode);
char currwin[256];
static int top_level_window(GtkWidget *lv_form) ;
void A4GL_decode_gui_winname (char *name);
void attach_signals(char *name,guint type,GtkWidget *widget) ;
void A4GL_select_row_handler (GtkWidget * w, gint row, gint column, GdkEventButton * event, gpointer user_data);
void A4GL_add_signal_clicked (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_activate (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_grab_focus (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_changed (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_select_row (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_row_activated (GtkWidget * widget, void *funcptr);
void A4GL_clicked_handler (GtkWidget * w, gpointer user_data);
void A4GL_activate_handler (GtkWidget * w, gpointer user_data);
void A4GL_row_activated_handler (GtkTreeView * w, GtkTreePath *path, GtkTreeViewColumn *col, gpointer user_data);
int A4GL_add_gui_id_name(char *s);
void A4GL_changed_handler (GtkWidget * w, gpointer user_data);
void A4GL_grab_focus_handler (GtkWidget * w, gpointer user_data);
void A4GL_ui_init (int argc, char *argv[]);


char *UILIB_A4GL_get_currwin_name (void) {
	return currwin;
}




int UILIB_A4GL_open_gui_form_internal(long *form_variable,char* name_orig,int absolute,int nat,char* like,int disable,void* vhandler_e,void* vhandler_c) {
    GladeXML *xml;
    GList *widgets;
    GList *node;
    GtkWidget *tlw=0;
  void (*handler_c) (void *a,void *b);
  void (*handler_e) (void *a,void *b);
  char name[256];
  char formname[256];
      handler_c=vhandler_c;
      handler_e=vhandler_e;
  strcpy (name, name_orig);
  A4GL_decode_gui_winname (name);
  if (like && strlen (like))
    {
      strcpy (formname, like);
    }
  else
    {
      strcpy (formname, name);
    }

    printf("---> Name='%s'\n",name);

    xml = glade_xml_new("ide.glade", formname,NULL);
    
    /* connect the signals in the interface */
    if (!xml) {
	g_warning("something bad happened while creating the interface");
		A4GL_exitwith("Unable to open glade file\n");
		return 0;
    }

    strcpy(currwin,formname);
    widgets = glade_xml_get_widget_prefix (xml, "");

    node = widgets;
    while (node) {
                const gchar *name;
                GtkWidget *widget;
                widget = node->data;
                name = glade_get_widget_name (widget);
                if (GTK_WIDGET_TOPLEVEL(widget)) {
			tlw=widget;
                        //printf("%s ***\n",name);
                        //gtk_widget_hide(widget);
                } else {
			gtk_object_set_data(GTK_OBJECT(widget),"Attribute",(void *)name);
                //printf("   %s (%s - %d)\n",name,GTK_OBJECT_TYPE_NAME(widget),GTK_OBJECT_TYPE(widget));
                }
                node = g_list_next (node);
    }


    if (tlw==0) {
		printf("No form..");
		A4GL_exitwith("Unable to find form");
		return 0;
    }
    gtk_signal_connect (GTK_OBJECT (tlw), "delete_event", GTK_SIGNAL_FUNC (handler_e), tlw);
    gtk_signal_connect (GTK_OBJECT (tlw), "destroy", GTK_SIGNAL_FUNC (handler_e), tlw);
    gtk_signal_connect (GTK_OBJECT (tlw), "focus_in_event", GTK_SIGNAL_FUNC (handler_e), tlw);

    node = widgets;
    while (node) {
                const gchar *name;
                GtkWidget *widget;
                widget = node->data;
                name = glade_get_widget_name (widget);
                if (GTK_WIDGET_TOPLEVEL(widget)) {
                } else {
                        printf("%s ***\n",name);
			if (GTK_IS_TREE_VIEW(widget)) { do_setup_list(widget,1); }
			gtk_object_set_data(GTK_OBJECT(widget),"HANDLER",handler_c);
			gtk_object_set_data(GTK_OBJECT(tlw),name,(void *)widget);
			attach_signals((char *)GTK_OBJECT_TYPE_NAME(widget),GTK_OBJECT_TYPE(widget),widget);

                }
                node = g_list_next (node);
    }

   *form_variable=(long )tlw;



    printf("setting form variable to %p\n",tlw);
    A4GL_add_pointer(formname,WINCODE,tlw);
    A4GL_add_pointer(formname,FORMCODE,widgets);

    gtk_object_set_data(GTK_OBJECT(tlw),"GLADE_WIDGETS",(void *)widgets);
    handler_c (0, 0);
    if (disable) {
		printf("**************************** MODAL WINDOW *******************************\n");
		gtk_window_set_modal(GTK_WINDOW(tlw),1);
		while (1) {
			if (!top_level_window(tlw)) break;
			UILIB_A4GL_gui_run_til_no_more();
			a4gl_usleep(100); // small sleep..
		}
    }

   
    return (long)(tlw);
}


void
 UILIB_A4GLUI_ui_init (int argc, char *argv[])
{
   gtk_init(&argc, &argv);
   glade_init();
   return;
}


/**
 *
 * @todo Describe function
 */
void A4GL_ui_init (int argc, char *argv[])
{
   gtk_init(&argc, &argv);
   glade_init();
printf("INIT\n");
}

void UILIB_A4GL_gotolinemode(void) {
	//
return ;
}


void UILIB_A4GL_hide_window(char *s) { 
	printf("hide Not implemented yet\n");
}

void UILIB_A4GL_gui_run_til_no_more() {
      while (gtk_events_pending ())
        gtk_main_iteration ();
}



void
A4GL_decode_gui_winname (char *name)
{
  char buff[256];
  char *ptr;
  strcpy (buff, name);
  ptr = (char *)strchr (name, '_');
  A4GL_debug ("Decoding name %s - ptr=%p", name, ptr);
  if (ptr)
    {
      strcpy (buff, ptr + 1);
      A4GL_debug ("Buff=%s\n", buff);
      strcpy (name, buff);
    }
}


int UILIB_A4GL_widget_name_match(void* wv,char* name) {
GtkWidget * w;
  void *s;
int ok;
w=wv;
  if (w == 0) return 0;
//printf("widget name match : %s\n",name);
  s = gtk_object_get_data (GTK_OBJECT (w), "Attribute");
  if (s == 0) {
        //printf("No attribute\n");
    return 0;
  }
	//printf("Compare : %s %s\n",s,name);
  ok=strcasecmp (s, name);
//printf("OK = %d\n",ok);
  if (ok==0) return 1;
	else return 0;
	

}


int UILIB_A4GL_current_window(char *name) {
	strcpy(currwin,name);
	return 1;
}






void A4GL_clicked_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;
  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  A4GL_debug ("Clicked... %p %p", w, user_data);
  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET (l);
    }
  else
    {
      nw = w;
    }
  A4GL_debug ("\nclicked - ptr=%p w=%p\n", ptr, nw);

  //set_widget_data (nw);
  ptr (nw, "clicked");
}


void A4GL_activate_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;
  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  A4GL_debug ("Clicked... %p %p", w, user_data);
  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET (l);
    }
  else
    {
      nw = w;
    }
  A4GL_debug ("\nclicked - ptr=%p w=%p\n", ptr, nw);

  //set_widget_data (nw);
  ptr (nw, "clicked"); // Same as clicked...
}


/**
 *
 * @param w A pointer to the widget.
 * @param user_data
 */
void A4GL_changed_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET (l);      /* Yes - signal the parent */
    }
  else
    {
      nw = w;                   /* No - keep the signal for this widget */
    }
  A4GL_debug ("\nchanged - ptr=%p w=%p\n", ptr, nw);
  //set_widget_data (nw);
  ptr (nw, "on");
}



/**
 *
 * @todo Describe function
 */
void A4GL_row_activated_handler (GtkTreeView * w, GtkTreePath *path, GtkTreeViewColumn *col, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET (l);      /* Yes - signal the parent */
    }
  else
    {
      nw = (GtkWidget *)w;                   /* No - keep the signal for this widget */
    }

  //set_widget_data (nw);

  if (ptr)
    ptr (nw, "on");

  else
    {
      printf ("Nothing to do\n");
    }

	printf("ROW ACTIVATED HANDLER............................\n");
}


/**
 *
 * @todo Describe function
 */
void
A4GL_select_row_handler (GtkWidget * w, gint row, gint column, GdkEventButton * event, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET (l);      /* Yes - signal the parent */
    }
  else
    {
      nw = w;                   /* No - keep the signal for this widget */
    }

  //set_widget_data (nw);

  if (ptr)
    ptr (nw, "on");

  else
    {
      printf ("Nothing to do\n");
    }

	printf("SELECT ROW HANDLER............................\n");
}







/**
 *
 * @todo Describe function
 */
void A4GL_grab_focus_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);

  char *l;

  A4GL_debug ("Focus change ");

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET (l);
    }
  else
    {
      nw = w;
    }

  //set_widget_data (nw);
  A4GL_debug ("\nGrab focus w=%p ptr=%p\n", nw, ptr);

  ptr (nw, "grab_focus");
}


/**
 * Add a clicked standard (in this library) event listener.
 *
 * @param widget The widget that we want to add a listener.
 * @param funcptr A pointer to an aditional listener callback.
 */
void
A4GL_add_signal_clicked (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "clicked",
                      GTK_SIGNAL_FUNC (A4GL_clicked_handler), funcptr);
}


void
A4GL_add_signal_activate (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "activate", GTK_SIGNAL_FUNC (A4GL_activate_handler), funcptr);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_add_signal_grab_focus (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "grab-focus",
                      GTK_SIGNAL_FUNC (A4GL_grab_focus_handler), funcptr);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_add_signal_changed (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "changed",
                      GTK_SIGNAL_FUNC (A4GL_changed_handler), funcptr);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_add_signal_select_row (GtkWidget * widget, void *funcptr)
{

printf("add_signal_seelct_row\n");
  gtk_signal_connect (GTK_OBJECT (widget), "select_row",
                      GTK_SIGNAL_FUNC (A4GL_select_row_handler), funcptr);
printf("done add_signal_seelct_row\n");
}



void
A4GL_add_signal_row_activated (GtkWidget * widget, void *funcptr)
{

printf("add_signal_row_Activated\n");
  gtk_signal_connect (GTK_OBJECT (widget), "row_activated", GTK_SIGNAL_FUNC (A4GL_row_activated_handler), funcptr);
printf("done add_signal_seelct_row\n");
}



/**
 * Default A4GL_func to be used as a listener callback for handling an event.
 * @param w The widget where the event ocurred.
 * @param mode
 */
void A4GL_func (GtkWidget * w, char *mode)
{

  //printf("MJAMJA (func)- widget=%p\n", w);
  if (gtk_object_get_data (GTK_OBJECT (w), "HANDLER") != 0)
    {
      /* void (*hand)(); */
      void (*hand) (GtkWidget * w, char *mode);

      //printf ("MJAMJA------------> Own handler....\n");
      hand = gtk_object_get_data (GTK_OBJECT (w), "HANDLER");
      hand (w, mode);
      return;
    }

  if (strcasecmp (mode, "grab_focus") == 0)
    {
      A4GL_debug ("grab focus detected...\n");
      fflush (stdout);

      A4GL_debug ("setting A4GL_action field=%p", w);
      actionfield = w;

      beforefield = (void *)1;
      return;
    }

  if (strcmp (mode, "clicked") == 0)
    {
      char *key;
      int m;
      onfield = 1;
	printf("click..\n");
      A4GL_debug ("setting A4GL_action field=%p", w);
      actionfield = w;

      key = gtk_object_get_data (GTK_OBJECT (w), "KEY");
      A4GL_debug ("Key=%p\n", key);
      fflush (stdout);

      if (key)
        {
          A4GL_debug ("Substituting specified key: %s\n", key);
          fflush (stdout);

          if (strcasecmp (key, "ACCEPT") == 0)
            {
              keypressed = 27;  /* FIXME */
            }
          else
            {
              if (strcasecmp (key, "INTERRUPT") == 0)
                {
                  keypressed = 3;       /* FIXME */
                }
              else
                {
		void *xxx;
			xxx=&m;
                  gtk_accelerator_parse (key, &keypressed, xxx);
                  if (m & 4 && tolower (keypressed) >= 'a'
                      && tolower (keypressed) <= 'z')
                    keypressed = tolower (keypressed) - 'a' + 1;
                  A4GL_debug ("keypressed=%x m=%x\n", keypressed, m);
                  fflush (stdout);
                }
            }
        }
    }


#ifdef TESTING
  /*
     if (strcmp (field, "formonly.btn1[0]") == 0
     && strcmp (mode, "clicked") == 0)
     {
     testfunc ();
     }
   */
#endif


  A4GL_debug ("All done");
  return;
}


int UILIB_A4GL_fgl_fieldnametoid(char* f,char* s,int n) {
//static int no=0;
//int k;
return A4GL_add_gui_id_name(s);
}


void
 UILIB_A4GL_display_internal (int x, int y, char *s, int a, int clr_line)
{
  printf ("%s\n", s);
}



void attach_signals(char *name,guint type,GtkWidget *widget) {
//guint n_ids;
//guint *signals;
//int a;
int indent;
//char buff[255];
	printf("Attach signals for : %s - %p\n",name,widget);
	if (strcmp(name,"GtkButton")==0) {
			A4GL_add_signal_clicked (widget, 0);
			//A4GL_add_signal_changed (widget, 0);
			//A4GL_add_signal_grab_focus (widget, 0);
			return;
	}

	if (strcmp(name,"GtkImageMenuItem")==0|| strcmp(name,"GtkMenuItem")==0) {
			A4GL_add_signal_activate (widget, 0);
			return ;
	}

	if (strcmp(name,"GtkList")==0) {
			printf("Add1\n");
			A4GL_add_signal_select_row (widget, 0);
		printf("Done add..\n");

	}
	if (strcmp(name,"GtkTreeView")==0) {
			A4GL_add_signal_row_activated (widget, 0);
	}


	indent=0;


	printf("Name : %s\n",name);

/*
	while (1) {
		if (!G_TYPE_IS_DERIVED(type)) break;

		if (type==g_type_from_name("GtkWidget")) break;
		signals=g_signal_list_ids(type,&n_ids);
		memset(buff,' ',255); buff[254]=0; buff[indent*3]=0;
		printf("%sI see %d signals for %s that\n",buff,n_ids,g_type_name(type));
		for (a=0;a<n_ids;a++) {
			printf("%s%d - %x (%s)\n",buff,a,signals[a],g_signal_name(signals[a]));
		}
		type=g_type_parent(type);
		if (type==0) break;
		indent++;
	}
*/

}



void
 UILIB_A4GL_close_form (char *name_orig)
{
  GtkWidget *tlw;
  char name[255];
  strcpy(name,name_orig);
  A4GL_decode_gui_winname (name);
  tlw=A4GL_find_pointer(name,WINCODE);
  if(tlw) gtk_widget_destroy(tlw);
  else {
	A4GL_exitwith("Form was not opened");
  }
}



static int top_level_window(GtkWidget *lv_form) {
GList *list;
int a;
int lv_ok;
lv_ok=0;

list=gtk_window_list_toplevels();
for (a=0;a<g_list_length(list);a++) {
        if ((gpointer)lv_form==g_list_nth_data(list,a)) {
                lv_ok=1;
                break;
        }
}
return lv_ok;
}

static int has_top_level_window(void ) {
GList *list;
int a;
int lv_ok;
lv_ok=0;

list=gtk_window_list_toplevels();
a=g_list_length(list);
if (a) return 1;
else return 0;
}


int UILIB_aclfgl_a4gl_run_gui(int n) {
  while (has_top_level_window()) {
    	a4gl_usleep (100);
        A4GL_gui_run_til_no_more ();
  }
  return 0;
}




//
// Called when SET PAUSE MODE ON/OFF is set
// and to check which is in effect (a==-1)
//
int
UILIB_A4GL_screen_mode (int a)
{
  static int smode = 1;
  if (a == -1)
    return smode;

  if (a == smode)
    return smode;
  if (a == 0)
    {
      smode = 0;
      return smode;
    }
  smode = 1;
  A4GL_zrefresh ();
  return smode;
}





void UILIB_A4GLUI_set_intr(void ) {
}
