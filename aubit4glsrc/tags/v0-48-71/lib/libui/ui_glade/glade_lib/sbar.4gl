#
code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

#define WINCODE 'w'
#define INTEGERCODE 'f'
#define IDCODE 'i'

endcode





function sbar_text_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_text char(255)
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return "" end if
code
{
int context;
context=gtk_object_get_data(GTK_OBJECT(lv_widget),"STATUS_CONTEXT");
if (!context) {
	strcpy(lv_text,"");
} else {
	strcpy(lv_text,gtk_object_get_data(GTK_OBJECT(lv_widget),"STATUS_CONTENTS"));
}
}
endcode
call yield()
return lv_text
end function


function sbar_text_set(lv_form,lv_field,lv_text)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_text char(255)
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return "" end if
code
{
int context;
char buff[255];
char *ptr;
A4GL_trim(lv_text);
sprintf(buff,"%p_%p_%p",lv_form,lv_field,lv_widget);
context=gtk_statusbar_get_context_id(GTK_STATUSBAR(lv_widget),buff);
gtk_object_set_data(GTK_OBJECT(lv_widget),"STATUS_CONTEXT",context);
ptr=gtk_object_get_data(GTK_OBJECT(lv_widget),"STATUS_CONTENTS");
if (ptr) {
	gtk_statusbar_pop(GTK_STATUSBAR(lv_widget),context);
}
gtk_statusbar_push(GTK_STATUSBAR(lv_widget),context,lv_text);
gtk_object_set_data(GTK_OBJECT(lv_widget),"STATUS_CONTENTS",lv_text);
}
endcode
call yield()
end function




