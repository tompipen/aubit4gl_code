function dump_dbperms()
define lv_str char(256)
define lv_uname char(8),lv_ptype  char(1)

let lv_str="SELECT username, CASE usertype WHEN 'D' THEN 1 WHEN 'R' THEN 2 ",
                "    WHEN 'C' THEN 3 WHEN 'G' THEN 4 END usertype ",
                "FROM 'informix'.sysusers ORDER BY 2,1" 

prepare p_get_dbperms from lv_str
declare c_get_dbperms cursor for p_get_dbperms
foreach c_get_dbperms into lv_uname,lv_ptype
	case lv_ptype
	WHEN 1 let lv_str="GRANT DBA TO \"",lv_uname clipped,"\";"
	WHEN 2 let lv_str="GRANT RESOURCE TO \"",lv_uname clipped,"\";"
	WHEN 3 let lv_str="GRANT CONNECT TO \"",lv_uname clipped,"\";"
	WHEN 4 let lv_str="CREATE ROLE \"",lv_uname clipped,"\";"
	end case

	call outstr(lv_str)
end foreach

call outstr(" ")

end function

function dump_perms()
end function


function dump_procedures() 
end function

