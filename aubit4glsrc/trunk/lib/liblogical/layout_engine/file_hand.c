#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

char * create_file_selection (char *fname);



/*
void
store_filename (GtkWidget * widget, gpointer user_data)
{
  //GtkWidget *file_selector = (GtkWidget *) user_data;
  //const gchar *selected_filename;

  //g_print ("Selected filename: %s\n", selected_filename);
}
*/



char *
create_file_selection (char *fname)
{
  GtkWidget *file_selector;
  static char ifname[1024] = "";
  gint result;
  /* Create the selector */
  if (fname)
    strcpy (ifname, fname);



  file_selector =
    gtk_file_selection_new ("Please select a file for editing.");

  if (strlen (ifname))
    {
      gtk_file_selection_set_filename (GTK_FILE_SELECTION (file_selector),
				       ifname);
    }

  gtk_widget_show (file_selector);


  result = gtk_dialog_run (GTK_DIALOG (file_selector));

  printf ("result=%d\n", result);
  switch (result)
    {
    case GTK_RESPONSE_ACCEPT:
    case GTK_RESPONSE_OK:
      strcpy (ifname,
	      gtk_file_selection_get_filename (GTK_FILE_SELECTION
					       (file_selector)));
      gtk_widget_destroy (file_selector);
      return ifname;
    default:
      gtk_widget_destroy (file_selector);
      return 0;
    }

}
