#define lv_dtabnames dynamic array of char(20)
define lv_tabnames array[20] of char(20)

main
define conn integer
define lv_rcode integer
define lv_a integer

#allocate array lv_dtabnames[20]
#let lv_dtabnames[1]="Hello"

for lv_a=1 to 20
	let lv_tabnames[lv_a]="TABLE_",lv_a using "<<<<"
end for




display "Creating"
let conn=A4GL_memcache::mc_new()
if conn =0 then
	display "Unable to connect"
	exit program 1
end if

display "connecting"
let lv_rcode= A4GL_memcache::mc_server_add(conn,"192.168.2.21","11211")
if lv_rcode<0 then
	display "Unable to add server.."
	exit program 2
end if

sleep 1

display "adding"
call A4GL_memcache::mc_add(conn,"tables",ACLFGL_ADDRESSOF(lv_tabnames),ACLFGL_SIZEOF(lv_tabnames))

call A4GL_memcache::mc_add_str(conn,"Bibble","Hello World")

sleep 1

display "getting"

display "--->", A4GL_memcache::mc_aget_str(conn,"Bibble")


end main
