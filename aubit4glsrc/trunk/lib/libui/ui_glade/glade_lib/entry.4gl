code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>
endcode





function entry_line_count_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if

return lv_cnt
end function




function entry_line_from_char_get(lv_form,lv_field,lv_char_index)
define lv_form INTEGER
define lv_field INTEGER
define lv_char_index integer
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_cnt
end function




function entry_line_length_get(lv_form,lv_field,lv_line)
define lv_form INTEGER
define lv_field INTEGER
define lv_line integer
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_cnt
end function




function entry_line_start_get(lv_form,lv_field,lv_line)
define lv_form INTEGER
define lv_field INTEGER
define lv_line integer
define lv_widget INTEGER
define lv_cnt integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return lv_cnt
end function


function entry_line_text_get(lv_form,lv_field,lv_line)
define lv_form INTEGER
define lv_field INTEGER
define lv_line integer
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
return ""
end function



function entry_max_chars_set(lv_form,lv_field,lv_chars)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_chars integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
gtk_entry_set_max_length(lv_widget,lv_chars);
endcode
return 
end function

function entry_max_chars_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_chars integer
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0 end if
code
lv_chars=gtk_entry_get_max_length(lv_widget);
endcode
return lv_chars
end function





function entry_selected_text_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_start,lv_length INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return "" end if
return  ""
end function


function entry_selected_text_update(lv_form,lv_field,lv_replace_with)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_replace_with CHAR(255)
define lv_start,lv_length INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return end if

call entry_selection_get(lv_form,lv_field) returning lv_start,lv_length
call entry_selection_delete(lv_form,lv_field)
code
A4GL_trim(lv_replace_with);
gtk_editable_insert_text(lv_widget,lv_replace_with,lv_length,lv_start);
endcode
return 
end function


function entry_selection_delete(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER

let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if

code
gtk_editable_delete_selection(lv_widget);
endcode

return 
end function


function entry_selection_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_start,lv_length INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return 0,0  end if
code
gtk_editable_get_selection_bounds(lv_widget,&lv_start,&lv_length);
if (lv_start==0) lv_length=0;
else {lv_length=lv_length-lv_start;}
endcode
return lv_start,lv_length
end function


function entry_selection_set(lv_form,lv_field,lv_start,lv_length)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
define lv_start,lv_length INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return  end if
code
gtk_editable_select_region(lv_widget,lv_start,lv_start+lv_length);
endcode
return
end function


function entry_text_get(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_widget INTEGER
let lv_widget=get_widget_for(lv_form,lv_field)
if lv_widget=0 then return ""  end if
code
{
A4GL_push_char(gtk_entry_get_text(lv_widget));
A4GLSTK_popFunction();
return 1;
}
endcode
return ""
end function


