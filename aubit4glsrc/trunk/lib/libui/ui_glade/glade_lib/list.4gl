#
define lv_cnt integer

code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

#define WINCODE 'w'
#define INTEGERCODE 'f'
#define IDCODE 'i'


endcode




function list_count_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
let lv_cnt=0
code
//GtkIter root;
	//gtk_tree_model_get_iter_first(gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)),&root);
	lv_cnt=gtk_tree_model_iter_n_children( gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)), 0);
endcode
display "list_count_get : ",lv_form," ",lv_field
return lv_cnt
end function




function list_column_set_header(lv_form,lv_field,lv_title) 
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_title char(255)
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
GtkTreeViewColumn *c;
A4GL_trim(lv_title);
c=gtk_tree_view_get_column(GTK_TREE_VIEW(lv_widget),0);
gtk_tree_view_column_set_title  (c, lv_title);
}
endcode
end function




function list_column_get_header(lv_form,lv_field) 
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_title char(255)
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
GtkTreeViewColumn *c;
c=gtk_tree_view_get_column(GTK_TREE_VIEW(lv_widget),0);
strcpy(lv_title,gtk_tree_view_column_get_title  (c));
A4GL_trim(lv_title);
}
endcode
return lv_title
end function



function list_current_get(lv_form,lv_field)
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


function list_delete(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

end function


function list_directory(lv_form,lv_field,lv_filespec)
define lv_form INTEGER
define lv_field INTEGER
define lv_filespec char(80)
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

end function


function list_insert(lv_form,lv_field,lv_index,lv_entry)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_entry char(255)
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if
code
{
GtkTreeIter iter;
GtkListStore *store;
A4GL_trim(lv_entry);
printf("Insert %s @ %d\n",lv_entry,lv_index);
store=(GtkListStore *)gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget));
gtk_list_store_insert(GTK_LIST_STORE(store),&iter,lv_index);
gtk_list_store_set (store, &iter,0,lv_entry,-1);
}
endcode
end function




function list_append(lv_form,lv_field,lv_entry)
define lv_form INTEGER
define lv_field INTEGER
define lv_entry char(255)
define lv_index integer
code
printf("APPEND - libglade stuff\n");
endcode

#let lv_widget=get_widget_for(lv_form,lv_field)
#if lv_widget=0 then return end if

let lv_index=list_count_get(lv_form,lv_field)

call list_insert(lv_form,lv_field,lv_index+1,lv_entry)
end function


function list_is_selected(lv_form,lv_field,lv_index)
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

function list_select(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

end function

function list_select_match(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

#@ fixme

return 0
end function


function list_text_get(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER
define lv_retvar char(1024)

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return "" end if

code
{
GtkTreeIter iter;
GValue value;
gchar *str_data;
	gtk_tree_model_iter_nth_child(gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)),&iter,0,lv_index-1);
	gtk_tree_model_get( gtk_tree_view_get_model(GTK_TREE_VIEW(lv_widget)), &iter,0,&str_data,-1);
	strcpy(lv_retvar,str_data);
}
endcode
let lv_retvar=lv_retvar
return lv_retvar
end function


function list_text_length_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
{
char *ptr;
	A4GL_push_int(lv_index);
	A4GL_push_int(lv_field);
	A4GL_push_int(lv_form);
	aclfgl_list_text_get(3);
	ptr=A4GL_char_pop();
	lv_index=strlen(ptr);
	free(ptr);
}
endcode

return lv_index
end function


function list_unselect(lv_form,lv_field,lv_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if
#@ fixme


end function


function list_update(lv_form,lv_field,lv_index,lv_entry)
define lv_form INTEGER
define lv_field INTEGER
define lv_index integer
define lv_entry char(255)
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if
#@ fixme

end function


