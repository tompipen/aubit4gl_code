#This program demonstrates ussage of PDF report capability in Aubit 4gl

define mv_logo byte

####
main
####

define t,c char(20)
define n integer

#database stores7
database maindb


#You may want to try with a small mod, change it to an order by on the select
#and an order external in the report - otherwise it has to create and populate
#a table which may be where the problem lies (not set it to read - only have
#you ?)


#Try again - with an order by on the sql and an order external on the report.
#I think the error may be when trying to insert new rows into the report table
#(which is used to do an ordinary 'order by' within the report).

	declare c1 cursor for
		select tabname,colname,colno from systables,syscolumns
		where systables.tabid=syscolumns.tabid
		and systables.tabid<99
		#and systables.tabid>99
#		order by 1,2,3


    start report r1  to "rr1.pdf"
	
	foreach c1 into t,c,n
        	#display "Processing table ", t clipped
			output to report r1 (t,c,n)
	end foreach
	
	finish report r1

    display "Finished, see result in rr1.pdf"

end main

#########################
pdfreport r1(t,c,n)
#########################
define t,c  char(20)
define n integer
#order external  by t,n

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
	display "Processing table", t
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

#----------------------------- EOF -------------------------------------
