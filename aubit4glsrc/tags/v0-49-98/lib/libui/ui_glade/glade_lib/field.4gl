code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

#define WINCODE 'w'
#define INTEGERCODE 'f'
#define IDCODE 'i'


endcode





function field_hide(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
	gtk_widget_hide(lv_widget);
endcode
end function



function field_show(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
	gtk_widget_show(lv_widget);
endcode
end function




function field_hwnd_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_widget
end function

