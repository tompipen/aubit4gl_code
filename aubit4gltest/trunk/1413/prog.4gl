database test1
main

define t,c char(20)
define n integer



	declare c1 cursor for
		select tabname,colname,colno from systables,syscolumns
		where systables.tabid=syscolumns.tabid and systables.tabid<=3
		order by 1,2,3


    	start report r1 to convertible
	
	foreach c1 into t,c,n
			output to report r1 (t,c,n)
	end foreach
	
	finish report r1 converting to "myfile1.pdf" AS "PDF"


    	start report r1 to convertible
	
	foreach c1 into t,c,n
			output to report r1 (t,c,n)
	end foreach
	
	# if you want to render to multiple outputs - use 'to many'
	finish report r1 converting to many


# All of these will be generated from the temporary file generated when the report was run..
# no going back to the database or redoing any portion of the report

	convert report r1 to "myfile2.pdf" AS "PDF"
	convert report r1 to "myfile2.txt" AS "TXT"
	convert report r1 to "myfile2.csv" AS "CSV"
	convert report r1 to "editme.loe" AS "SAVE" # THIS IS SPECIAL - you can edit a layout using this

	display "VIA"
	convert report r1 via test1
	display "DONE VIA"
	
	free report r1 # But you'll need to 'free' the temporary file it'll create...



#  You should now be able to use the editme.loe to fine tune the output (especially useful for CSV and PDF)
# eg :
#   $ layout_engine CSV editme.loe
# or
#   $ layout_engine PDF editme.loe


DISPLAY "Doing just via"
	start report r1 to convertible

	foreach c1 into t,c,n

		output to report r1 (t,c,n)
	end foreach

	finish report r1 converting via test1
DISPLAY "Done just via"



end main

#########################
report r1(t,c,n)
#########################
define t,c  char(20)
define n integer
#order external  by t,n

format
first page header
	print "Table Dump First Page"

page header
	print column 2,"Table Dump", column 120 ,"Page : ",pageno using "<<<"


on every row

	print column 20,c

before group of t
	print "";
	print t clipped

after group of t
	print group count(*) using "<<<<"," Columns"
	skip 3 lines

end report


function test1(a)
define a chaR(20)
# This function needs to return 4 values 
# filename, type, layout file, 0 for file/1 for pipe

return a clipped||".txt","TXT","",0

end function


#----------------------------- EOF -------------------------------------
