main
define lv_rec record
	ipaddress char(20),
	router char(20),
	network char(20),
	broadcast char(20),
	hostname char(20),
	domain char(20),
	wanaddr char(20),
	nat char(1)
end record

	
call form_is_compiled(v1,"MEMPACKED","GENERIC")

open window abc at 3,3 with form "v1" attribute(border)

input by name lv_rec.*

end main


