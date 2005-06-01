#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

void print_arguments(GtkObject* object);

void print_arguments(GtkObject* object)
{
/*
  GtkType type;
  type = GTK_OBJECT_TYPE(object);

  do {
    GtkArg* args;
    guint32* flags;
    guint n_args;
    guint i;

    args = gtk_object_query_args(type,
                                 &flags, 
                                 &n_args);
  
    printf("Displaying arguments for object type `%s'\n",
           gtk_type_name(type));

    i = 0;
    while (i < n_args)
      {
        printf(" - Argument %u is called `%s' and has type `%s'\n",
               i, 
               args[i].name, 
               gtk_type_name(args[i].type));
      
        ++i;
      }

    g_free(args);
    g_free(flags);

    type = gtk_type_parent(type);
  } 
  while (type != GTK_TYPE_INVALID);
*/
}

