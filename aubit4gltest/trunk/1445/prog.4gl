database sysmaster

main
define
   q_txt      char(200),
   q_txt2     char(200)

open window win1 at 2, 2 with form "test10" attribute (border)

display "1","1","1","1" to tabname, tabid, rowsize,ncols
construct q_txt on sysmaster.tabname, sysmaster.tabid
   from formonly.tabname, formonly.tabid

construct q_txt2 on sysmaster.rowsize, sysmaster.ncols
   from formonly.rowsize, formonly.ncols
	on key(f1)
		call aclfgl_dump_screen("out")
end construct

close window win1

end main
