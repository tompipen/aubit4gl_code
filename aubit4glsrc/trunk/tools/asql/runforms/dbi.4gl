globals "globals.4gl"
define constant mv_limit=1000
define mv_serial integer


code
/* Input binding for the fetch */
extern struct BINDING *ibind;
/* Output bindings for the Insert and Update */
extern struct BINDING *obind_i;
extern struct BINDING *obind_u;
extern int obind_i_cnt; /* Count -noentry/noeditadd fields are excluded from insert list too */
extern int obind_u_cnt; /* Count -serial/noentry   fields are excluded from update list too */
endcode





################################################################################
FUNCTION dbi_fill_query_rows_table(lv_tabno,lv_str)
define lv_tabno integer
define lv_str char(5000)
define lv_cnt integer
define lv_id integer

call list_init(lv_tabno)

if lv_str is null or lv_str matches " " then
	return 
end if

prepare p_make_table from lv_str
declare c_make_table cursor for p_make_table
let lv_cnt=1

foreach c_make_table into lv_id

	call list_add(lv_tabno,lv_cnt,lv_id)

	if lv_cnt>mv_limit then
		error "Too many rows - limiting to first ",mv_limit
		exit foreach
	end if
	let lv_cnt=lv_cnt+1
end foreach

return lv_cnt

END FUNCTION



################################################################################
FUNCTION dbi_get_and_display(lv_tabno,lv_sql,lv_pos)
define lv_tabno integer
define lv_sql char(5000)
define lv_pos integer
define lv_id integer
define a integer
define lv_p char(20)
define lv_c char(20)

let lv_pos=list_get(lv_tabno,lv_pos)


IF lv_pos<0 THEN
	ERROR "Some error getting unique ID"
	RETURN
end if


LET lv_c="c_get_row",lv_tabno using "<<<<"

IF gv_prepared[lv_tabno] IS NULL OR gv_prepared[lv_tabno]=0 THEN 
		let lv_p="p_get_row",lv_tabno using "<<<<"
		PREPARE _variable(lv_p) FROM lv_sql
		DECLARE v_c CURSOR FOR v_p
		DECLARE _variable(lv_c) CURSOR FOR _variable(lv_p)

		LET gv_prepared[lv_tabno]=1
END IF

OPEN   _variable(lv_c) using lv_id


code
        for (a=0;a<gv_fields;a++) {
                A4GL_setnull(gv_dtypes[a],(void *)gv_field_data[a],gv_dtypesize[a]);
        }

	A4GLSQL_fetch_cursor(lv_c, 2,1,gv_fields,ibind);

endcode

END FUNCTION


################################################################################
FUNCTION dbi_get_unique_where(lv_tabno,lv_pos)
DEFINE lv_tabno integer
DEFINE lv_str char(256)
DEFINE lv_id integer
DEFINE lv_pos integer

let lv_pos=list_get(lv_tabno,lv_pos)

IF lv_pos>=0 THEN
	LET lv_str=dbi_get_rowid() CLIPPED, " = ",lv_id
ELSE
	ERROR "Some error getting unique ID"
	LET lv_str="1=0"
END IF

RETURN lv_str

END FUNCTION





################################################################################
FUNCTION dbi_get_Rowid()
        RETURN "rowid"
END FUNCTION




################################################################################
FUNCTION dbi_execute_sql_using_obind_u(lv_sql)
define lv_sql char(10000)
	display "U:",lv_sql clipped
sleep 4
END FUNCTION


################################################################################
FUNCTION dbi_last_Serial()
return mv_serial
END FUNCTION


################################################################################
FUNCTION dbi_execute_sql_using_obind_i(lv_sql,lv_nextcnt,lv_tabno)
define lv_sql char(10000)
define lv_tabno integer
define lv_nextcnt integer
define lv_rowid integer
display lv_sql clipped
initialize mv_serial to null
code
	A4GL_trim(lv_sql);
	A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(obind_i,obind_i_cnt,0,0,lv_sql),1);
        if (a4gl_sqlca.sqlcode<0)  {
			A4GL_chk_err(0,_module_name);
        }
endcode

if sqlca.sqlcode<0 then
	Error "FAILED:",sqlca.sqlcode
	return 0
end if
let mv_serial=sqlca.sqlerrd[2]
let lv_rowid=sqlca.sqlerrd[6]

if lv_rowid>0 then
	call list_add(lv_tabno,lv_nextcnt,lv_rowid)
else
	error "Unable to identify new row"
end if

return 1

END FUNCTION

################################################################################
FUNCTION dbi_execute_sql(lv_tabno,lv_sql,lv_thispos)
define lv_sql char(10000)
define lv_thispos integer
define lv_tabno integer

	call list_remove(lv_tabno,lv_thispos)
	display "E:",lv_sql clipped
sleep 2
return 1
END FUNCTION
