#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>



static GtkTreeModel * create_model (int n)
{
  gint i = 0;
  GtkListStore *store;
  GtkType *types;

  types=(GtkType*)malloc(sizeof(GtkType)*n);
  for (i=0;i<n;i++) {
	types[i]=G_TYPE_STRING;
  }
  /* create list store */
  store = gtk_list_store_newv (n, types);
  return GTK_TREE_MODEL(store);
}



void do_setup_list(GtkWidget *treeview) {
      GtkCellRenderer *renderer;
      GtkTreeViewColumn *column;
      GtkTreeModel *model;
      //GtkWidget *treeview;
      model = create_model (1);
      gtk_tree_view_set_model (treeview,model);


	printf("****** TREE VIEW !");

      gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview), TRUE);
      //g_object_unref (model);
      renderer = gtk_cell_renderer_text_new ();
      column = gtk_tree_view_column_new_with_attributes ("Column", renderer, "text", 0, NULL);
      gtk_tree_view_column_set_sort_column_id (column, 0);
      gtk_tree_view_append_column (GTK_TREE_VIEW(treeview), column);
}


/*
additems() 
{
  GtkTreeIter iter;
  for (i = 0; i < G_N_ELEMENTS (data); i++)
    {
      gtk_list_store_append (store, &iter);
      gtk_list_store_set (store, &iter,
                          COLUMN_FIXED, data[i].fixed,
                          COLUMN_NUMBER, data[i].number,
                          COLUMN_SEVERITY, data[i].severity,
                          COLUMN_DESCRIPTION, data[i].description,
                          -1);
    }

  return GTK_TREE_MODEL (store);
}
*/
