code
//char **columnNames=0;
//int *columnWidths=0;
//int *columnAlign=0;
endcode


define sqleditor integer
#

define buffer char(32000)
function bibble()
end function


function open_sqleditor()
	OPEN FORM sqleditor USING sqleditor_fh
end function



formhandler sqleditor_fh
input
	on b_run,mn_execute
		#call A4GL_glade::textview_text_get(sqleditor,id_to_int(txt)) returning buffer
		#message buffer clipped
		call qry_run()




	on mn_clear
		call A4GL_glade::textview_new_file(sqleditor,id_to_int(txt),0)

	on mn_save
		call save_editor()

	on mn_load
		call load_editor()

	on mn_cut
		call A4GL_glade::textview_selection_cut(sqleditor,id_to_int(txt))

	on mn_paste
		call A4GL_glade::textview_selection_paste(sqleditor,id_to_int(txt))

	on mn_copy
		call A4GL_glade::textview_selection_copy(sqleditor,id_to_int(txt))

	on mn_delete
		call A4GL_glade::textview_selection_delete(sqleditor,id_to_int(txt))

	on b_quit,mn_quit

		close form sqleditor
end input
end formhandler


function save_editor()
	if A4GL_glade::textview_save_file(sqleditor,id_to_int(txt),"test1.txt") then
	else
		message "Unable to save file!"
	end if
end function

function load_editor()
	if A4GL_glade::textview_open_file(sqleditor,id_to_int(txt),"test1.txt") then
	else
		message "Unable to open file!"
	end if
end function




function qry_run()
define a integer
call A4GL_glade::textview_text_get(sqleditor,id_to_int(txt)) returning buffer

code
{
static char buff[256]="";

extern FILE *yyin;
extern struct element *list;
extern int list_cnt;
if (strlen(buff)==0) {
	tmpnam(buff);
}
yyin=fopen(buff,"w");
A4GL_trim(buffer);
fwrite(buffer,strlen(buffer),1,yyin);
fclose(yyin);
yyin=fopen(buff,"r");
clr_stmt();
a=yyparse();
a=list_cnt;
}
endcode

message a using "<<<<"," statements to execute"


if not execute_queries(0) then
	error "Some problem"
end if

end function






function add_to_list(lv_col,lv_data,lv_row)
define lv_col integer,lv_data char(255)
define lv_row integer
define a integer

let a=A4GL_glade::mlist_count_get(sqleditor, id_to_int(output_view))


while a < lv_row
        call A4GL_glade::mlist_insert(sqleditor,id_to_int(output_view),a+1,0,"")
	let a=a+1
end while
call A4GL_glade::mlist_insert(sqleditor,id_to_int(output_view),lv_row,lv_col,lv_data)
end function




function sel(n)
define n integer
Call A4GL_glade::mlist_set_columns(sqleditor, id_to_int(output_view),n)


end function

code
set_execute_list(int n) {
	A4GL_push_int(n);
	aclfgl_sel(1);
}
endcode



function setup_header(a,b)
define a char(50)
define b integer
call A4GL_glade::mlist_column_set_header(sqleditor, id_to_int(output_view),b,a)
end function
