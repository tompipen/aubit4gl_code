
#
define lv_cnt integer

code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

#define WINCODE 'w'
#define INTEGERCODE 'f'
#define IDCODE 'i'
void do_setup_list(GtkWidget *treeview,int n) ;


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



void do_setup_list(GtkWidget *treeview,int n) {
      GtkCellRenderer *renderer;
      GtkTreeViewColumn *column;
      GtkTreeModel *model;
GList *cols;
      int a;
      //GtkWidget *treeview;
      model = create_model (n);

printf("setup_list\n");
      gtk_tree_view_set_model (GTK_TREE_VIEW(treeview),0);



	cols=gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview));

      	a=0;

	while (1) {
		GtkTreeViewColumn *column;
		column=g_list_nth_data(cols,a);
	    	if (!gtk_tree_view_remove_column(GTK_TREE_VIEW(treeview),GTK_TREE_VIEW_COLUMN(column))) break;
		a++;
        }


      //gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview), TRUE);
      //g_object_unref (model);


      for (a=0;a<n;a++) {
		char buff[256];
     		renderer = gtk_cell_renderer_text_new ();
		sprintf(buff,"Column %d",a);
      		column = gtk_tree_view_column_new_with_attributes (buff, renderer, "text", a, NULL);
      		gtk_tree_view_column_set_sort_column_id (column, a);
                gtk_tree_view_append_column (GTK_TREE_VIEW(treeview), column);
        }
      gtk_tree_view_set_model (GTK_TREE_VIEW(treeview),model);
}

endcode




function mlist_count_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
let lv_cnt=0
code
	lv_cnt=gtk_tree_model_iter_n_children( gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)), 0);
endcode
return lv_cnt
end function



function mlist_set_columns(lv_form,lv_field,lv_cnt) 
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_title char(255)
define lv_cnt integer
define lv_a integer

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

code
printf("Set_column\n");
do_setup_list((GtkWidget *)lv_widget,lv_cnt);
endcode

end function


function mlist_column_set_header(lv_form,lv_field,lv_cnt,lv_title) 
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_title char(255)
define lv_cnt integer

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
GtkTreeViewColumn *c;
A4GL_trim(lv_title);

printf("Set_column header\n");
c=gtk_tree_view_get_column(GTK_TREE_VIEW(lv_widget),lv_cnt);
if (c==0) {
	gtk_tree_view_insert_column(GTK_TREE_VIEW(lv_widget),gtk_tree_view_column_new() ,lv_cnt);
	c=gtk_tree_view_get_column(GTK_TREE_VIEW(lv_widget),lv_cnt);
}

gtk_tree_view_column_set_title  (c, lv_title);
}
endcode
end function




function mlist_column_get_header(lv_form,lv_field,lv_cnt) 
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_title char(255)
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
GtkTreeViewColumn *c;
c=gtk_tree_view_get_column(GTK_TREE_VIEW(lv_widget),lv_cnt);
strcpy(lv_title,gtk_tree_view_column_get_title  (c));
A4GL_trim(lv_title);
}
endcode
return lv_title
end function



function mlist_current_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_int integer
let lv_int=-1


let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
GList *list;
GtkTreeModel *model;
GtkTreePath *path;
gint *ints;
	list=gtk_tree_selection_get_selected_rows(gtk_tree_view_get_selection(GTK_TREE_VIEW(lv_widget)),&model);
	if (list!=0)  {
		path=g_list_nth_data(list,0);
		if (path!=0) {
			ints=gtk_tree_path_get_indices(path);
			lv_int=ints[0]+1;
		}
	}
}
endcode

return lv_int
end function


function mlist_delete(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

end function


function mlist_directory(lv_form,lv_field,lv_filespec)
define lv_form INTEGER
define lv_field INTEGER
define lv_filespec char(80)
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

end function


function mlist_insert(lv_form,lv_field,lv_index,lv_cnt,lv_entry)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_entry char(255)
define lv_widget INTEGER
define lv_cnt integer
define lv_a integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if
code
{
gchar *x;
static GtkTreeIter iter;
static int last_cnt=-1;
static int last_index=-1;
static int last_widget=-1;
static GtkListStore *store=0;
A4GL_trim(lv_entry);

if (last_widget!=lv_widget || 1)  {
	store=(GtkListStore *)gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget));
}


if (last_widget==lv_widget  && lv_index==last_index && 1==0)  ;
else {
	//printf("last_widget=%p widget=%p ",last_widget,lv_widget); printf("last_index=%d index=%d\n",last_index,lv_index);
	lv_a=gtk_tree_model_iter_n_children( gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)), 0);
	while (lv_a<lv_index) {
		gtk_list_store_insert(GTK_LIST_STORE(store),&iter,lv_index);
		lv_a++;
	}
	last_index=lv_index;
	last_widget=lv_widget;
}
gtk_tree_model_iter_nth_child(gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)),&iter,0,lv_index-1);


gtk_list_store_set (store, &iter,lv_cnt-1,lv_entry,-1);

}
endcode
end function




function mlist_append(lv_form,lv_field,lv_entry)
define lv_form INTEGER
define lv_field INTEGER
define lv_entry char(255)
define lv_index integer
code
//
endcode

#let lv_widget=get_widget_for(lv_form,lv_field)
#if lv_widget=0 then return end if

let lv_index=list_count_get(lv_form,lv_field)

call list_insert(lv_form,lv_field,lv_index+1,0,lv_entry)
end function





function mlist_is_selected(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER
define lv_ok INTEGER
define lv_int integer
let lv_ok=0

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if

code
{
GList *list;
GtkTreeModel *model;
GtkTreePath *path;
gint *ints;
int a;
        list=gtk_tree_selection_get_selected_rows(gtk_tree_view_get_selection(GTK_TREE_VIEW(lv_widget)),&model);

        if (list!=0)  {
		for (a=0;a<=g_list_length(list);a++) {
                	path=g_list_nth_data(list,a);
                	if (path!=0) {
                        	ints=gtk_tree_path_get_indices(path);
                        	lv_int=ints[0]+1;
				if (lv_int==lv_index) lv_ok=1;
                	}
		}
        }
}
endcode
return lv_ok
end function

function mlist_select(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

end function

function mlist_select_match(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

return 0
end function


function mlist_text_get(lv_form,lv_field,lv_index,lv_cnt)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER
define lv_retvar char(1024)
define lv_cnt integer

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return "" end if

code
{
GtkTreeIter iter;
GValue value;
gchar *str_data;
	gtk_tree_model_iter_nth_child(gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)),&iter,0,lv_index-1);
	gtk_tree_model_get( gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)), &iter,lv_cnt,&str_data,-1);
	strcpy(lv_retvar,str_data);
}
endcode
let lv_retvar=lv_retvar
return lv_retvar
end function


function mlist_text_length_get(lv_form,lv_field,lv_cnt)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER
define lv_cnt integer

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
char *ptr;
	A4GL_push_int(lv_index);
	A4GL_push_int(lv_field);
	A4GL_push_int(lv_form);
	A4GL_push_int(lv_cnt);
	aclfgl_mlist_text_get(4);
	ptr=A4GL_char_pop();
	lv_index=strlen(ptr);
	free(ptr);
}
endcode

return lv_index
end function


function mlist_unselect(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if
#@ fixme


end function


function mlist_update(lv_form,lv_field,lv_index,lv_entry)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_entry char(255)
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if
#@ fixme

end function


