main
define lv_dbname char(64)
define lv_query char(512)
define lv_tabname char(64)
define lv_colsrch char(512)
define lv_colname,lv_coltype, lv_default char(256)

if num_args() != 1 then
	display "Error Usage : ",arg_val(0) clipped," dbname"
	exit program 1
end if

if fgl_getenv("A4GL_SQLTYPE")!="pg8" then
	display "You must set A4GL_SQLTYPE=pg8 before running this program"
	exit program 1
end if



let lv_dbname=arg_val(1)

run "createlang -d "|| lv_dbname clipped||" plpgsql"

database lv_dbname


whenever error continue
execute immediate "CREATE LANGUAGE plpgsql;"
whenever error stop



let lv_colsrch= "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), (SELECT substring(pg_catalog.pg_get_expr(d.adbin, d.adrelid) for 128) FROM pg_catalog.pg_attrdef d WHERE d.adrelid = a.attrelid AND d.adnum = a.attnum AND a.atthasdef)   FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname=? and pg_table_is_visible(b.oid) ORDER BY a.attnum"

prepare p_srch from lv_colsrch

let lv_query=" SELECT c.relname FROM pg_catalog.pg_class c",
     " LEFT JOIN pg_catalog.pg_user u ON u.usesysid = c.relowner",
     " LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace",
     " WHERE c.relkind IN ('r','')",
     " AND n.nspname NOT IN ('pg_catalog', 'pg_toast')",
     " AND pg_catalog.pg_table_is_visible(c.oid)",
     "  ORDER BY 1"

prepare p_q from lv_query

display "Scanning tables... please wait"
declare c_gettables cursor for p_q
foreach c_gettables into lv_tabname

	declare c_get_serials cursor for p_srch
	foreach c_get_serials using lv_tabname into lv_colname,lv_coltype,lv_default
		#display "   lv_colname", lv_colname clipped, " ", lv_coltype
		if lv_coltype matches "int*" or lv_coltype="bigint" then
			if lv_default matches "*nextval*" then
				call create_serial(lv_tabname, lv_colname,lv_default)
			end  if
		end if
	end foreach
end foreach

end main


function create_serial(lv_tabname,lv_colname,lv_default) 
define lv_tabname,lv_colname char(64)
define lv_default char(128)
define lv_str char(1024)
define lv_seq char(512)

define s1 integer
define s2 integer
define a integer

# Lets try to find out sequence..
let s1=0
let s2=0
for a=1 to length(lv_default)
	if lv_default[a]="'" then
		if s1=0 then
			let s1=a+1
		else
			if s2=0 then
				let s2=a-1
			else
				# got confused
				display "Could not create trigger for ",lv_tabname clipped,".",lv_colname clipped," - didn't understand : ",lv_default clipped
				return
			end if
		end if
	end if
end for

if s1=0 or s2=0 then
	display "Could not create trigger for ",lv_tabname clipped,".",lv_colname clipped," - didn't understand : ",lv_default clipped
	return
end if


display "Creating trigger/function for ", lv_tabname clipped,".", lv_colname clipped, " <",lv_default clipped,">"
let lv_seq=lv_default[s1,s2]
let lv_str=
	"CREATE OR REPLACE FUNCTION get_next_", lv_tabname clipped,"_",lv_colname clipped,"() RETURNS TRIGGER AS $$\n", 
        "BEGIN\n ",
        "   IF NEW.",lv_colname clipped," = 0 then\n",
        "SELECT nextval('",lv_seq clipped,"') into NEW.",lv_colname clipped,";\n",
        "ELSE\n",
        "IF NEW.",lv_colname clipped," > 0 THEN\n",
        "PERFORM setval('", lv_seq clipped,"',NEW.",lv_colname clipped,");\n",
        "END IF;\n",
        "END IF;\n",
        "RETURN NEW;\n",
        "END;\n",
        "$$ LANGUAGE plpgsql\n"

display lv_str clipped
execute immediate lv_str

whenever error continue
let lv_str="drop trigger sertrig_",lv_tabname clipped,"_",lv_colname clipped, " on ", lv_tabname clipped
display lv_str clipped
execute immediate lv_str
whenever error stop

let lv_str="create trigger sertrig_",lv_tabname clipped,"_",lv_colname clipped," before insert on ",lv_tabname clipped," for each row execute procedure get_next_", lv_tabname clipped,"_",lv_colname clipped, "();"

display lv_str clipped
execute immediate lv_str

end function
