
database test1

define bksa array[80] of record
		cat char(1),
		volno smallint,
		vol char(4),
		newbook char(1),
		sq smallint,
		sdt date,
		isd smallint,
		stock smallint,
		late smallint,
		pubrtn smallint,
		p_adj smallint
	end record

main
	define n smallint
	define nv char(1), sq,stock,late,rtn,isd smallint
	define sdt date

	define lvol char(4)


	# initialize program variables
	let nv='0'
	let sq=1
	let stock=111
	let late=11
	let rtn=101
	let isd=10
	let sdt=mdy(31,1,2005)

	let lvol='aaaa'

	# create (temp) table and load it
	create temp table abc (cat char(1),volno smallint,vol char(4),stkadj smallint)
	insert into abc values ('B',2,'bbbb',2)
	insert into abc values ('A',1,'aaaa',1)

	# select table data plus program variable values into array lines
	select cat,volno,vol,nv,sq,sdt,isd,stock,late,rtn,stkadj
			into bksa[2].* from abc where vol=lvol
	let bksa[2].sdt=mdy(31,1,2005)						# correct the false NULL
	let lvol='bbbb'
	select cat,volno,vol,nv,sq,sdt,isd,stock,late,rtn,stkadj
			into bksa[1].* from abc where vol=lvol
	let bksa[1].sdt=mdy(31,1,2005)-1						# correct the false NULL

	# clear the (temp) table
	drop table abc


	# kick off the report
	start report ud_stkrpt to "out" with
			top margin 0,
			left margin 0,
			bottom margin 0,
			page length 6

	# pass array data to the report
	let n=1
	while n<3				
		output to report ud_stkrpt(bksa[n].cat,bksa[n].volno,bksa[n].vol,bksa[n].newbook,
					bksa[n].sq,bksa[n].sdt,bksa[n].isd,bksa[n].stock,
					bksa[n].late,bksa[n].pubrtn,bksa[n].p_adj)
		let n=n+1
		end while

	# finish it, display the array data, and CAT the report
	finish report ud_stkrpt
	display bksa[1].vol,' ',bksa[1].sdt
	display bksa[2].vol,' ',bksa[2].sdt
	run "cat arrdaterpt.txt"
	end main

report ud_stkrpt(cat,volno,vol,newbook,sq,sd,isd,stock,late,pubrtn,xstkadj)
	define cat char(1)
	define volno smallint
	define vol char(4)
	define sd date, newbook,sq,isd,stock,late,pubrtn,xstkadj smallint

	output
		top margin 0
		left margin 0
		bottom margin 0
		page length 6

	# if order EXTERNAL, then no temp database table, and no date problems
	#order external by cat,volno,sq
	order by cat,volno,sq

	format
	on every row
			print cat," ",volno using "##&","  ",vol,column 18,sd,isd using "#######&",
				stock+late using "-----------&",pubrtn using "-----------&",
				stock+late-pubrtn using "-------&",xstkadj using "-------&",
				xstkadj+stock+late-pubrtn using "-------&"
	end report

