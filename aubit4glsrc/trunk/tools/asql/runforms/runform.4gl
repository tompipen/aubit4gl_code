globals "globals.4gl"

code
#include <string.h>
#include <stdlib.h>
#ifndef DTYPE_CHAR
#define DTYPE_CHAR      0
#define DTYPE_VCHAR     13
#endif
endcode
define mv_table_cnt integer
define mv_table char(255)

define constant mv_cnt_taglines =40
define mv_taglines array[mv_cnt_taglines] of char(80)
define mv_column_list char(8000)
define b_prepared integer
define mv_field_list array[gv_max_fields] of char(80)
define mv_field_list_dtype array[gv_max_fields] of integer
define mv_field_pointers array[gv_max_fields] of integer

define mv_acurrent_position array[gv_max_tables] of integer
define mv_max_rows          array[gv_max_tables] of integer


define mv_field_list_for char(80)
define mv_table_code integer

define mv_update_columns array[gv_max_fields] of char(80) # We need to maintain a list of columns used for an update
define mv_insert_columns array[gv_max_fields] of char(80) # We need to maintain a list of columns used for an update

code
/* Input binding for the fetch */
struct BINDING *ibind=0;

/* Output bindings for the Insert and Update */
struct BINDING *obind_i=0;
struct BINDING *obind_u=0;
int obind_i_cnt=0; /* Count -noentry/noeditadd fields are excluded from insert list too */
int obind_u_cnt=0; /* Count -serial/noentry   fields are excluded from update list too */

#ifndef HAS_S_FIELD_NAME_LIST
#define HAS_S_FIELD_NAME_LIST

struct s_field_name {
        char *fname;
        int fpos;
};

struct s_field_name_list {
        int nfields;
        struct s_field_name *field_name_list;
};


/* Should really read in libaubit4gl.h for these - but we can't easily - this is a 4gl program.... */

#define DTYPE_SERIAL 6
#define FA_B_NOENTRY 3

#endif

endcode




main 
define a integer
	defer interrupt

	options message line last-1
	let mv_field_list_for=""

	for a=1 to mv_cnt_taglines
		initialize mv_taglines[a] to null
	end for


	for a=1 to gv_max_tables
		let mv_acurrent_position[a]=0
		let gv_prepared[a]=0
		let mv_max_Rows[a]=0
	end for

	if num_args()=0 then
		display "Usage : runform formname"
		exit program 0
		
		#call runform("cust1")
	else
	message "Please wait - loading form..."
		call runform(arg_val(1))
	end if
end main



################################################################################
FUNCTION runform(lv_formname)
define lv_formname char(255)
define a integer
define lv_next_option char(20)
define lv_info char(50)
define lv_dbname char(50)


options form line 3,input wrap

#
# We need to open out form using _variable so we don't add our module name
# prefix to it - that way we can use get_info to get some info about it...


whenever error continue
open form _variable("fxx") from lv_formname
if status!=0 then
	display "Unable to open form :",lv_formname clipped
	exit program 1
end if


display form _variable("fxx")

if status!=0 then
	display "Unable to display form :",lv_formname clipped
	exit program 1
end if

whenever error stop
let lv_dbname=a4gl_get_info("form","fxx","Database")

if lv_dbname="formonly" then
	error "You can't run a 'formonly' form!"
	return
end if
whenever error continue
	database lv_dbname
whenever error stop

if sqlca.sqlcode!=0 then
	error "Unable to connect to database :",sqlca.sqlcode
	return
end if


# We can cycle through all our tables using the 'Table' option
# We need to keep a note of where we are...
let mv_table_cnt=1
let lv_info="TableName",mv_table_cnt-1 using "<<<<"
call a4gl_get_info("form","fxx",lv_info) returning mv_table

if mv_table=" " or mv_table is null then
	let mv_table="???"
end if


# We need to store our descriptions in variables
# because these lines will have the table name of the
# current table included in them

let mv_taglines[1] ="Searches the active database table."
let mv_taglines[2] ="Shows the next row in the Current List."
let mv_taglines[3] ="Shows the previous row in the Current List."
let mv_taglines[4] ="Runs editor commands to display BLOB contents."
let mv_taglines[5] ="Adds a row to the active database table."
let mv_taglines[6] ="Changes a row in the active database table."
let mv_taglines[7] ="Deletes a row from the active database table."
let mv_taglines[8] ="Selects the current table."
let mv_taglines[9] ="Shows the next page of the form."
let mv_taglines[10]="Displays the current row of the current table."
let mv_taglines[11]="Selects the master table of the current table."
let mv_taglines[12]="Selects a detail table of the current table."
let mv_taglines[13]="Outputs selected rows in form or report format."
let mv_taglines[14]="Return to Main Menu."


let mv_taglines[20]="Removes this row from the current table."
let mv_taglines[21]="Does NOT remove this row from the current table."
let mv_taglines[22]="Appends to the end of an existing file"
let mv_taglines[23]="Creates a new file"
let mv_taglines[24]="All currently queried rows"
let mv_taglines[25]="Just this row"



let lv_next_option=" " 

while lv_next_option!="ALLDONE"

	call set_tag_lines()

	menu "APERFORM"
		before menu
			if lv_next_option is not null 
 		   	and lv_next_option not matches " " then
	
				next option lv_next_option
			end if
			set pause mode off
			let mv_table_code=0
	
		# When using tables - we can 3T for the third table
		# so we need to keep a track of these key presses..
		# Pressing anything except a number or 'T' should clear this down...
		command key(1) let mv_table_code=1
		command key(2) let mv_table_code=2
		command key(3) let mv_table_code=3
		command key(4) let mv_table_code=4
		command key(5) let mv_table_code=5
		command key(6) let mv_table_code=6
		command key(7) let mv_table_code=7
		command key(8) let mv_table_code=8
		command key(9) let mv_table_code=9

		command "Query" mv_taglines[1]	
			let mv_table_code=0
			let int_flag=false
			call do_query()

		command "Next" mv_taglines[2]	
			let mv_table_code=0
			call get_next_row()
	
		command "Previous" mv_taglines[3]
			let mv_table_code=0
			call get_previous_row()
	
		command "View" mv_taglines[4]
			let mv_table_code=0
			call do_view()
	
		command "Add" mv_taglines[5]
			let mv_table_code=0
			let int_flag=false
			call do_add(0)
	
		command "Update" mv_taglines[6]
			let mv_table_code=0
			let int_flag=false
			if mv_acurrent_position[mv_table_cnt]=0 then
				error "You must do a query first"
			else
				call do_add(1)
			end if
	
		command "Remove" mv_taglines[7]
			
			let mv_table_code=0
			
			let int_flag=false
			if mv_acurrent_position[mv_table_cnt]=0 then
				error "You must do a query first"
			else
				call do_remove()
			end if
	
		command "Table" mv_taglines[8]
			if  mv_table_code=0 then
				let mv_table_cnt=mv_table_cnt+1
			else
				let mv_table_cnt=mv_table_code
			end if

			let lv_info="TableName",mv_table_cnt-1 using "<<<<"
			call a4gl_get_info("form","fxx",lv_info) returning mv_table
	
			if mv_table=" " or mv_table is null then
				let mv_table_cnt=1
				let lv_info="TableName",mv_table_cnt-1 using "<<<<"
				call a4gl_get_info("form","fxx",lv_info) returning mv_table
			end if
			if mv_table=" " or mv_table is null then
				let mv_table="???"
			else
				if not get_field_list() then	
					error "Internal Error"
				end if 
				call get_and_display_row()

			end if
	
			let lv_next_option="Table"
			set pause mode on
			exit menu
	
		command "Screen" mv_taglines[9]
			
			let mv_table_code=0
			call do_screen()
	
		command "Current" mv_taglines[10]
			let mv_table_code=0
			call get_and_display_row()
	
		command "Master" mv_taglines[11]
			let mv_table_code=0
			call do_master()
	
		command "Detail" mv_taglines[12]
			let mv_table_code=0
			call do_detail()
	
		command "Output" mv_taglines[13] 
			let mv_table_code=0
			call do_output()
	
		command "Exit" mv_taglines[14]
			let mv_table_code=0
			let lv_next_option="ALLDONE"
			exit menu
	end menu
end while
END FUNCTION




################################################################################
FUNCTION set_tag_lines()
define a integer
for a=1 to mv_cnt_taglines
	if mv_taglines[a] is not null then
		let mv_taglines[a][49,80]="** ",mv_table_cnt using "<<<", ": ",mv_table clipped,"**"
	end if
end for
END FUNCTION





################################################################################
FUNCTION get_field_list()
define a integer
define b integer
define c integer
define lv_nfields integer
define lv_tmpnam char(255)
define lv_matches char(80)
define lv_info char(80)
define lv_nbytes integer


if mv_table="???" then
	let gv_fields=0
	error "Internal error - no tablename !"
	return 0
end if

if mv_table=mv_field_list_for then
	return 1 		# We've already done it...
end if

	let gv_fields=0

let lv_matches=mv_table clipped,".*"
let lv_nfields=a4gl_get_info("form","fxx","AttributesCount")

let b=1

# go through each attribute - find its name
# this should be tablename.column so we can use the lv_matches
# above to detect this...
#
for a=0 to lv_nfields-1
	let lv_info="FieldName", a using "<<<<<"
	let lv_tmpnam=a4gl_get_info("form","fxx",lv_info)

	if lv_tmpnam not matches lv_matches then
		continue for
	end if

	let mv_field_list[b]=lv_tmpnam
	let mv_field_list_dtype[b]=dbi_get_datatype(lv_tmpnam)

	if gv_field_data[b] is not null then

code
		free((void *)gv_field_data[b-1]);
endcode
	end if

	let lv_info="FieldType", a using "<<<<<"
	let gv_dtypes[b]=a4gl_get_info("form","fxx",lv_info)


	let lv_info="FieldDets", a using "<<<<<"
        let mv_field_pointers[b]=a4gl_get_info("form","fxx",lv_info)

	let lv_info="FieldSize", a using "<<<<<"
	let gv_dtypesize[b]=a4gl_get_info("form","fxx",lv_info)

	let lv_info="FieldBytes", a using "<<<<<"
	let lv_nbytes=a4gl_get_info("form","fxx",lv_info)

	#display gv_dtypes[b]," ",lv_nbytes
code
	gv_field_data[b-1]=(long) malloc(lv_nbytes);
	if (gv_dtypes[b-1]==0 || gv_dtypes[b-1]==13 || gv_dtypes[b-1]==5 || gv_dtypes[b-1]==8) {             /* CHAR or VARCHAR or DECIMAL*/
		gv_edtype[b-1]=gv_dtypes[b-1]+ENCODE_SIZE(gv_dtypesize[b-1]);
		//@FIXME -> SHOULDN'T WE ENCODE DATETIMES, INTERVALS, DECIMALS ETC ? 
	} else {
		gv_edtype[b-1]=gv_dtypes[b-1];
	}
endcode


	let b=b+1

	if b>gv_max_fields then
		error "Only first ",gv_max_fields using "<<<<<<"," fields will be used !"
		exit for
	end if


end for

if b=1 then
	error "No active fields"
	return 0
end if

# Got to here - everything looks good...
let gv_fields=b-1
code
{
  int ni = 0;
  int nu = 0;
  if (ibind)
    free (ibind);
  if (obind_i)
    free (obind_i);
  if (obind_u)
    free (obind_u);


  ibind = (struct BINDING *) malloc (sizeof (struct BINDING) * gv_fields);
  obind_u = (struct BINDING *) malloc (sizeof (struct BINDING) * gv_fields);
  obind_i = (struct BINDING *) malloc (sizeof (struct BINDING) * gv_fields);

  for (a = 0; a < gv_fields; a++)
    {
      void *f;
      ibind[a].ptr = (void *) gv_field_data[a];
      ibind[a].dtype = gv_dtypes[a];
      ibind[a].size = gv_dtypesize[a];
      ibind[a].start_char_subscript = 0;
      ibind[a].end_char_subscript = 0;


      if (!A4GL_has_bool_attribute ((void *) mv_field_pointers[a], FA_B_NOENTRY) || gv_dtypes[a] == DTYPE_SERIAL)
	{
	 
	  strcpy (mv_insert_columns[ni], mv_field_list[a]);
	  if (strchr(mv_insert_columns[ni],'.')) {
	  	strcpy (mv_insert_columns[ni], strchr(mv_field_list[a],'.')+1);
	  }
	  obind_i[ni].ptr = (void *) gv_field_data[a];
	  obind_i[ni].dtype = gv_dtypes[a];
	  obind_i[ni].size = gv_dtypesize[a];
	  obind_i[ni].start_char_subscript = 0;
	  obind_i[ni].end_char_subscript = 0;
	  ni++;
	  obind_i_cnt = ni;
	} 

      if (gv_dtypes[a] != DTYPE_SERIAL
	  && !A4GL_has_bool_attribute ((void *) mv_field_pointers[a],
				       FA_B_NOENTRY))
	{
	  
	  strcpy (mv_update_columns[nu], mv_field_list[a]);
	  if (strchr(mv_update_columns[nu],'.')) {
		// We don't need no stinkin' table name on an update...
	  	strcpy (mv_update_columns[nu], strchr(mv_field_list[a],'.')+1   );
	  }
	  obind_u[nu].ptr = (void *) gv_field_data[a];
	  obind_u[nu].dtype = gv_dtypes[a];
	  obind_u[nu].size = gv_dtypesize[a];
	  obind_u[nu].start_char_subscript = 0;
	  obind_u[nu].end_char_subscript = 0;
	  nu++;
	  obind_u_cnt = nu;
	}
    }
}
endcode
let mv_field_list_for=mv_table
return 1
END FUNCTION




################################################################################
FUNCTION get_where()
define lv_where_clause char(8000)
define lv_cnt integer
define lv_column_list char(8000)
define a integer


if not get_field_list() then
	initialize lv_where_clause to null
	return lv_where_clause
end if
let int_flag=false


code
{
  struct BINDING ibind[1];
  static struct s_constr_list *constr_flds=0;
  int _fld_dr = -100;
  int _exec_block = 0;
  char *fldname;
  char _sio_2[1000];
  char _inp_io_type = 'C';
  char *_sio_kw_2 = "s_screenio";
  int _forminit = 1;
  static struct s_field_name_list list={0,0};


  if (constr_flds) { // Free up what was there before - its static...
		int c;
		for (c=0;constr_flds[c].tabname;c++) {
			free(constr_flds[c].tabname);
			free(constr_flds[c].colname);
		}
  }

 ibind[0].ptr=NULL;
 ibind[0].dtype=0;
 ibind[0].size=8000;
 ibind[0].start_char_subscript=0;
 ibind[0].end_char_subscript=0;
 ibind[0].libptr=0;

  // We just want our where clause popping - its a CONSTRUCT
  ibind[0].ptr = (void *)&lv_where_clause;
  // Number of fields...
  list.nfields=gv_fields;
  list.field_name_list=(struct s_field_name *)realloc(list.field_name_list,sizeof(list.field_name_list[0])*gv_fields);
  constr_flds=(struct s_constr_list *)realloc(constr_flds,sizeof(struct s_constr_list)*(gv_fields+1));

  for (lv_cnt=0;lv_cnt<gv_fields;lv_cnt++) {
		char *ptr0;
		char *ptr1;
		char buff[200];
		strcpy(buff,mv_field_list[lv_cnt]);
		A4GL_trim(buff);
		ptr0=strchr(buff,'.');
		if (ptr0)  {
			*ptr0=0;
			constr_flds[lv_cnt].tabname=strdup(buff);
			ptr0++;
			constr_flds[lv_cnt].colname=strdup(ptr0);
		} else {
			constr_flds[lv_cnt].tabname=strdup("");
			constr_flds[lv_cnt].colname=strdup(buff);
			
		}
		A4GL_trim(constr_flds[lv_cnt].tabname);
		A4GL_trim(constr_flds[lv_cnt].colname);
		if (strlen(lv_column_list)) strcat(lv_column_list,",");
		strcat(lv_column_list,constr_flds[lv_cnt].colname);
		list.field_name_list[lv_cnt].fname=strdup(mv_field_list[lv_cnt]);
		A4GL_trim(list.field_name_list[lv_cnt].fname);
		list.field_name_list[lv_cnt].fpos=0;
  }

  constr_flds[lv_cnt].tabname=0;
  constr_flds[lv_cnt].colname=0;
  

  while (_fld_dr != 0)
    {
      if (_exec_block == 0)
        {
          SET ("s_screenio", _sio_2, "vars", ibind);
          SET ("s_screenio", _sio_2, "processed_onkey",0);
          SET ("s_screenio", _sio_2, "novars", gv_fields);
          SET ("s_screenio", _sio_2, "attrib", 0);
          SET ("s_screenio", _sio_2, "currform", A4GL_get_curr_form (1));
          SET ("s_screenio", _sio_2, "currentfield", 0);
          SET ("s_screenio", _sio_2, "currentmetrics", 0);
          SET ("s_screenio", _sio_2, "constr", constr_flds);
          SET ("s_screenio", _sio_2, "mode", 3);
          SET ("s_screenio", _sio_2, "nfields", A4GL_gen_field_list_from_slist ((void ***) GETPTR ("s_screenio", _sio_2, "field_list"), (void *) GET ("s_screenio", _sio_2, "currform"), &list ));
          {
            int _sf;
            _sf = A4GL_set_fields (&_sio_2);
            if (_sf == 0)
              {
                _fld_dr = 0;
                break;
              }
          }
          _fld_dr = -1;
        }                       /* end of initialization */
      if (_exec_block == 1)
        {
          break;
        }
      {
        static struct aclfgl_event_list _sio_evt[] = {
          {-94, 1, 0, ""},
          {0}
        };
        _exec_block = A4GL_form_loop_v2 (&_sio_2, _forminit, _sio_evt);
        _forminit = 0;
        if (_exec_block > 0) _fld_dr = _sio_evt[_exec_block - 1].event_type;
        else _fld_dr = -1;
      }
    }
  A4GL_push_constr (&_sio_2);
  A4GL_pop_params (ibind, 1);
}
endcode

if int_flag then
	initialize lv_where_clause to null
	return lv_where_clause
end if

if lv_where_clause is null then
	let lv_where_clause=" "
end if

let mv_column_list=lv_column_list
return lv_where_clause

END FUNCTION





################################################################################
FUNCTION do_query()
define lv_where_clause char(8000)
define lv_cnt integer
define lv_str char(200)
define lv_id integer


call get_where() returning lv_where_clause

if lv_where_clause is null then
	# they cancelled - or there was some other error...
	return
end if


let lv_str="SELECT ",dbi_get_rowid()," id from ",mv_table clipped," WHERE ",lv_where_clause clipped
call dbi_fill_Query_rows_table(mv_table_cnt,lv_str) returning lv_cnt

if lv_cnt =0 then
	error "No Rows found"
	let mv_acurrent_position[mv_table_cnt]=0
	call clr_form()
end if

message (lv_cnt-1) using "<<<<<<<", " row(s) found"
let mv_acurrent_position[mv_table_cnt]=1
let mv_max_rows[mv_table_cnt]=lv_cnt-1
call get_and_display_row()
END FUNCTION



################################################################################
FUNCTION get_next_row()
IF mv_max_rows[mv_table_cnt]=0 then
	error "No Results!"
	return
end if

If mv_acurrent_position[mv_table_cnt]>=mv_max_rows[mv_table_cnt] then
	error "No more rows in that direction" 
	return
end if

let mv_acurrent_position[mv_table_cnt]=mv_acurrent_position[mv_table_cnt]+1
call get_and_display_row()
message mv_acurrent_position[mv_table_cnt] using "<<<<", " of ",mv_max_rows[mv_table_cnt]  using "<<<<<"
END FUNCTION


################################################################################
FUNCTION get_previous_row()
IF mv_max_rows[mv_table_cnt]=0 then
	error "No Results!"
	return
end if

if mv_acurrent_position[mv_table_cnt]=1 then
	error "No more rows in that direction" 
	return
end if
let mv_acurrent_position[mv_table_cnt]=mv_acurrent_position[mv_table_cnt]-1
call get_and_display_row()
message mv_acurrent_position[mv_table_cnt] using "<<<<", " of ",mv_max_rows[mv_table_cnt]  using "<<<<<"
END FUNCTION


################################################################################
FUNCTION get_and_display_row()
define lv_id integer
define lv_sql char(8000)
define a integer

if mv_max_rows[mv_table_cnt]=0 then
	error "No Results!"
	return
end if



let lv_sql="select ",mv_column_list clipped, " from ",mv_table clipped, " where ",dbi_get_rowid(),"= ?"

call dbi_fetch(mv_table_cnt,lv_sql,mv_acurrent_position[mv_table_cnt]) 

set pause mode on
call clr_form()
for a=1 to  gv_fields

code
{
char buff[1024];
	A4GL_push_param((void *)gv_field_data[a-1],gv_edtype[a-1]);
	strcpy(buff, mv_field_list[a-1]);
	A4GL_debug("Pushing : %p %x displaying to field %s",gv_field_data[a-1],gv_edtype[a-1],buff);
	if ((gv_edtype[a-1]&0xff)==0) {
		A4GL_debug("DATA is a string : %s\n",gv_field_data[a-1]);
	}
	A4GL_trim(buff);
   	A4GL_disp_fields(1,0x0, buff,1 ,0);
}
endcode
end for
set pause mode off

END FUNCTION


################################################################################
function clr_form()
define a integer

for a=1 to  gv_fields
code
{
	char buff[1024];
	A4GL_push_null(2,0);
	strcpy(buff, mv_field_list[a-1]);
	A4GL_debug("Pushing : %p %x displaying to field %s",gv_field_data[a-1],gv_edtype[a-1],buff);
	if ((gv_edtype[a-1]&0xff)==0) {
		A4GL_debug("DATA is a string : %s\n",gv_field_data[a-1]);
	}
	A4GL_trim(buff);
   	A4GL_disp_fields(1,0x0, buff,1 ,0);
}
endcode
end for

end function



################################################################################
function do_view() 
	error "do_view not implemented"
end function





################################################################################
function do_add(lv_isupd) 
define lv_isupd integer
define lv_cnt integer

if not get_field_list() then
	return 
end if

if gv_fields<1 or gv_fields is null or gv_fields>1000 then
	error "Bad fields"
	return
end if

call disp_field_2()
let int_flag=false

code
{
  int _fld_dr = -100;
  int _exec_block = 0;
  char *fldname;
  char sio_2[74];
  char _inp_io_type = 'I';
  char *sio_kw_2 = "s_screenio";
  int _forminit = 1;
  struct aclfgl_event_list sio_evt[] = { 
	 					{-99,2,0,""},
						{-94, 1, 0, ""}, 
						{0} 
  };
  struct s_field_name_list list = { 0, 0 }; 
  list.nfields = gv_fields;
  list.field_name_list = (struct s_field_name *) realloc (list.field_name_list, sizeof (list.field_name_list[0]) * gv_fields);

  for (lv_cnt = 0; lv_cnt < gv_fields; lv_cnt++)
    {
      list.field_name_list[lv_cnt].fname = strdup (mv_field_list[lv_cnt]);
      A4GL_trim (list.field_name_list[lv_cnt].fname);
      list.field_name_list[lv_cnt].fpos = 0;
    }


  while (_fld_dr != 0)
    {
      if (_fld_dr == -100)
	{
	    int _sf;
	  SET ("s_screenio", sio_2, "currform", A4GL_get_curr_form (1));
	  if ((int) GET ("s_screenio", sio_2, "currform") == 0) break;
	  SET ("s_screenio", sio_2, "vars", ibind);
	  SET ("s_screenio", sio_2, "attrib", 0);
	  SET ("s_screenio", sio_2, "novars", gv_fields);
	  SET ("s_screenio", sio_2, "help_no", 0);
	  SET ("s_screenio", sio_2, "field_list", 0);
	  SET ("s_screenio", sio_2, "currentfield", 0);
	  SET ("s_screenio", sio_2, "currentmetrics", 0);
	  SET ("s_screenio", sio_2, "mode", 1 + lv_isupd);
	  SET ("s_screenio", sio_2, "nfields", A4GL_gen_field_list_from_slist ((void ***) GETPTR ("s_screenio", sio_2, "field_list"), 
				(void *) GET ("s_screenio", sio_2, "currform"), &list));

	  if ((int) GET ("s_screenio", sio_2, "nfields") == -1) break;
	  _sf = A4GL_set_fields (&sio_2);
	  if (_sf == 0) {
		_fld_dr = 0;
		break;
	  }
	  _fld_dr = -1;
	  _exec_block = 0;
	}			/* end of initialization */


      if (_exec_block == 1) { 
			if (lv_isupd) {
				A4GL_push_char("U");
			} else {
				A4GL_push_char("I");
			}
			aclfgl_null_check_obind(1);
			if (A4GL_pop_long()) {
				break;
			}
	}


      if (_exec_block == 2) { 
		int a;
		// Before input...

		if (!lv_isupd) {
			for (a=0;a<gv_fields;a++) {
				if (gv_dtypes[a]==DTYPE_SERIAL) {
					// Its a serial field
					*(long *)gv_field_data[a]=0;
					A4GL_push_char("0");
					A4GL_disp_fields(1,0x0, list.field_name_list[a].fname,1 ,0);
				}
			}
		}
       }

      _exec_block = A4GL_form_loop_v2 (&sio_2, _forminit, sio_evt);

      _forminit = 0;

      if (_exec_block > 0) {
		_fld_dr = sio_evt[_exec_block - 1].event_type;
      }
      else _fld_dr = -1;
    }

A4GL_finish_screenio (sio_2, sio_kw_2);
}
endcode



if int_flag=true then
	# the user has just aborted...
	# If we're on a row - redisplay it to remove any changes
	if mv_acurrent_position[mv_table_cnt]>0 then
		call get_and_display_row()
	else
		# No current row - so just clear it down...
		call clr_form()
	end if

	return
end if




if lv_isupd then
	# Update - we don't want to update the PK or Serial columns if we can help it...
	#
	call generate_and_execute_update_stmt() 
else
	# Straight insert...
	call generate_and_execute_insert_stmt() 
end if


end function




################################################################################
function disp_field_2()
define a integer
define buff char(256)
code
{
char *p;
p=(char *)gv_field_data[1];
strcpy(buff,p);
}
endcode
let buff=buff;
display "FIELD2=",buff
end function




################################################################################
function do_remove()
	menu "REMOVE"
		command "Yes" mv_taglines[20]
			call generate_and_execute_delete_stmt()
			exit menu

		command "No" mv_taglines[21]
			exit menu
	end menu
end function


################################################################################
function do_screen()
define lv_screen integer
define lv_max_screen integer

let lv_screen=a4gl_get_page()
let lv_screen=lv_screen+1
call a4gl_get_info("form","fxx","screens") returning lv_max_screen
if lv_screen>=lv_max_screen then
	let lv_screen=0
end if
call a4gl_set_page(lv_screen)
error "Screen ", (lv_screen+1)," of ",lv_max_screen
end function


################################################################################
function do_output()
define lv_fname char(255)
define lv_mode char(1)
define lv_what char(1)
define lv_format char(1)

	let int_flag=false

	prompt "Enter output file (default is aperform.out):" for lv_fname

	if int_Flag=true then	
		return
	end if

	if lv_fname is null or lv_fname=" " then
		let lv_fname="aperform.out"
	end if

	menu "Output File"
		command "Append" mv_taglines[22]
			let lv_mode="A" exit menu

		command "Create" mv_taglines[23]
			let lv_mode="C" exit menu
	end menu

	menu "Output File List"
		command "Current-list" mv_taglines[24]
			let lv_what="A" exit menu
		command "One-page" mv_taglines[25]
			let lv_what="A" exit menu
	end menu

	menu "Format"
		command "Screen-format" mv_taglines[24]
			let lv_format="S" exit menu

		command "Unload-format" mv_taglines[25]
			let lv_format="U" exit menu
	end menu
	
	error "That was a little pointless - not implemented"
end function


################################################################################
function do_master()
	error "do_master not implemented yet"
end function


################################################################################
function do_detail()
	error "do_detail not implemented yet"
end function





################################################################################
function generate_and_execute_update_stmt() 
define sql char(75000)
define lv_head char(80)
define a integer
let lv_head="UPDATE ",mv_table clipped," SET "
code
A4GL_trim(lv_head);
sprintf(sql,"%s ",lv_head);


for (a=0;a<obind_u_cnt;a++) {
	char buff[200];
	if (a) strcat(sql,",");
	strcpy(buff,mv_update_columns[a]);
	A4GL_trim(buff);
	strcat(sql,buff);
	strcat(sql," = ?");
}
// Finally - add on the where clause
endcode

let sql=sql clipped," WHERE ",dbi_get_unique_where(mv_table_cnt,mv_acurrent_position[mv_table_cnt])
if not dbi_execute_sql_using_obind_u(sql) then
	# didn't work...
end if
end function



################################################################################
function generate_and_execute_insert_stmt() 
define sql char(75000)
define lv_head char(80)
define a integer
define lv_last_serial integer
define has_serial integer

let has_serial=0
let lv_head="INSERT INTO ",mv_table clipped," ( "
code
A4GL_trim(lv_head);
sprintf(sql,"%s ",lv_head);


for (a=0;a<obind_i_cnt;a++) {
	char buff[200];
	if (a) strcat(sql,",");
	strcpy(buff,mv_insert_columns[a]);
	A4GL_trim(buff);
	strcat(sql,buff);
}

strcat(sql,") VALUES (");

for (a=0;a<obind_i_cnt;a++) {
	if (a) strcat(sql,",");

	if (obind_i[a].dtype==DTYPE_SERIAL) {
		long *p;
		has_serial=1;
		p=obind_i[a].ptr;
		*p=0;
		strcat(sql,"?");
	} else {
		strcat(sql,"?");
	}
}

strcat(sql,")");
endcode

if mv_acurrent_position[mv_table_cnt]=0 then
	call dbi_fill_query_rows_table(mv_table_cnt,"") 
end if


if dbi_execute_sql_using_obind_i(sql,mv_max_rows[mv_table_cnt]+1,mv_table_cnt) then
	message "Executes ok..."
	sleep 1
	let mv_max_rows[mv_table_cnt]= mv_max_rows[mv_table_cnt]+1
	let mv_acurrent_position[mv_table_cnt]=mv_max_rows[mv_table_cnt]

	if has_serial=1 then
		let lv_last_serial=dbi_last_serial()
code
for (a=0;a<obind_i_cnt;a++) {
	if (obind_i[a].dtype==DTYPE_SERIAL) {
			long *p;
			char buff[80];
			p=(long *)obind_i[a].ptr;
			*p=lv_last_serial;
			A4GL_push_long(*p);
			strcpy(buff,mv_field_list[a]);
			A4GL_trim(buff);
			A4GL_disp_fields(1,0x0, buff,1 ,0);
			break;
	}
}
endcode
	end if
end if
end function


################################################################################
function generate_and_execute_delete_stmt() 
define lv_sql char(75000)
define lv_head char(80)
define a integer

let lv_sql="DELETE FROM  ",mv_table clipped," WHERE ",dbi_get_unique_where(mv_table_cnt,mv_acurrent_position[mv_table_cnt])

if dbi_execute_sql(mv_table_cnt,lv_sql,mv_acurrent_position[mv_table_cnt]) then
	let mv_max_rows[mv_table_cnt]=mv_max_rows[mv_table_cnt]-1

	# Did we remove the last row ?
	if mv_acurrent_position[mv_table_cnt]>mv_max_rows[mv_table_cnt] then
		let mv_acurrent_position[mv_table_cnt]=mv_max_rows[mv_table_cnt]
	end if
end if

if  mv_acurrent_position[mv_table_cnt]>0 then
	call get_and_display_row()
end if
end function


################################################################################


function  null_check_obind(lv_type)
# I for Insert, U for Update
define lv_type char (1) 
define lv_cnt integer
define lv_err char(80)

let lv_err=" "
code
{
	for ( lv_cnt=0;lv_cnt<gv_fields;lv_cnt++) {
		if (A4GL_isnull(ibind[lv_cnt].dtype, ibind[lv_cnt].ptr)) { 
			// We've got a null in our field..
			// Does the field allow nulls ?
			A4GL_push_long(ibind[lv_cnt].ptr);
			if (mv_field_list_dtype[lv_cnt]&256) {
				/* No - it doesnt! */
				char *ptr;
				char *cptr;
				ptr=strdup(mv_field_list[lv_cnt]);
				A4GL_trim(ptr);
				if ((mv_field_list_dtype[lv_cnt]&255)==DTYPE_CHAR || (mv_field_list_dtype[lv_cnt]&255)==DTYPE_VCHAR) { // 
					cptr=(char *)ibind[lv_cnt].ptr;
					cptr[0]=' '; // JUst make it a space for now..
					cptr[1]=0; // JUst make it a space for now..
				} else {
					sprintf(lv_err,"Error: field '%s' does not allow nulls",ptr);
					free(ptr);
					break;
				}
			}
		}
	}
}

endcode

if length(lv_err) then
	error lv_err
	return false
end if

return true
end function
