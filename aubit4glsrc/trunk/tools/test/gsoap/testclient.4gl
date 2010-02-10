database test1
main
define lv_id integer
define lv_tabname char(18)
define lv_rec record like systables.*
{
	call get_tabid("http://localhost:9090","syscolumns") returning lv_id
	display lv_id
}

	call get_tabname(54321) returning lv_tabname
	display lv_tabname,":"
{

	call get_tabrecord("http://localhost:9090",1) returning lv_rec.*
	display lv_rec.tabname," ",lv_rec.created
	call get_tabname("http://localhost:9090",54321) returning lv_tabname
	display lv_tabname,":"
}
end main

