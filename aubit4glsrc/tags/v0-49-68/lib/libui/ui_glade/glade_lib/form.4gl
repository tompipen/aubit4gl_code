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





function form_is_open(lv_form)
define lv_form INTEGER
define lv_ok INTEGER
if lv_form is null then
	return 0
end if
code
{
GList *list;
int a;
lv_ok=0;

list=gtk_window_list_toplevels();
for (a=0;a<g_list_length(list);a++) {
	if ((gpointer)lv_form==g_list_nth_data(list,a)) {
		lv_ok=1;
		break;
	}
}
}
endcode
return lv_ok
end function


function form_caption_set(lv_form,lv_caption) 
define lv_form integer
define lv_caption char(80)

code
A4GL_trim(lv_caption);
printf("\n\n\n\n\nSetting caption to %s\n\n\n\n\n",lv_caption);
gtk_window_set_title(GTK_WINDOW(lv_form),lv_caption);
endcode
end function

function form_caption_get(lv_form)
define lv_form integer
define lv_buff char(512)
code
{
char *ptr;
ptr=gtk_window_get_title(GTK_WINDOW(lv_form));
strcpy(lv_buff,ptr);
}
endcode
return lv_buff
end function
