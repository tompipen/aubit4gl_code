database test1

main
	define a char(6),b char(3),c dec(8,2)
	define p smallint
	define x char(1)

	
	create temp table p369(a1 char(6),a2 char(3),v1 dec(8,2))

	for p=1 to 200
		insert into p369 values ('aasdf','rtg',1234.56)
	end for

	start report r1 		#to pipe "less"

	declare c1 cursor for select * from p369

	foreach c1 into a,b,c
		output to report r1(a,b,c)
	end foreach

	finish report r1


end main

report r1(rpt)
	define rpt record 
		a char(40),
		b char(3),
		c dec(8,2)
		end record

	output
		top margin 0
		left margin 0
		bottom margin 0
		page length 24
		#report to pipe 'less'
		report to 'out'

	format
	on every row
		print rpt.a clipped, column 50, rpt.b, column 55,rpt.c

	on last row
		print "END OF REPORT"
end report
