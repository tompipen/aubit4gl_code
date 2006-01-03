database test1
main
	define vend_case_wgt decimal(13,2)
	define t1  decimal(13,2)
call startlog("t.out")
	create temp table aa ( decvar decimal(13,2))
	insert into aa values ( 123.34 )
	
	open form tform from "t"
	display form tform
	
	select decvar into vend_case_wgt from aa
	display by name vend_case_wgt
	call errorlog(vend_case_wgt)

	input by name vend_case_wgt without defaults
	error vend_case_wgt
	call errorlog(vend_case_wgt)
	update aa set decvar = vend_case_wgt
	select * into t1 from aa
	call errorlog(t1)
	display t1 at 2,1

end main


