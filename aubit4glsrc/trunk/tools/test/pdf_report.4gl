#This program demonstrates ussage of PDF report capability in Aubit 4gl


database maindb
define mv_logo byte


main

define t,c char(20)
define n integer

	declare c1 cursor for
		select tabname,colname,colno from systables,syscolumns
		where systables.tabid=syscolumns.tabid
		and systables.tabid>99

        start report r1  to "rr1.pdf"
	foreach c1 into t,c,n
        	output to report r1 (t,c,n)
	end foreach
	finish report r1

end main

pdfreport r1(t,c,n)
define t,c  char(20)
define n integer
order  by t,n

format
first page header
	call pdf_function("set_font_size",16);
	print column 2 inches,"Table Dump First Page"

page header
	call pdf_function("set_font_size",14);
	print column 2 inches,"Table Dump", column 6 inches,"Page : ",pageno using "<<<"
	call pdf_function("set_font_size",10);


on every row

	print column 2 inches,c

before group of t
	print "";
	call pdf_function("set_font_size",20);
	call pdf_function("set_parameter","underline","true");
	print t clipped
	call pdf_function("set_parameter","underline","false");
	call pdf_function("set_font_size",10);

after group of t
	print column 5 inches, group count(*) using "<<<<"," Columns"
	skip 3 lines

end report

