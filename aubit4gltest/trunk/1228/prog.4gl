
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
	define nv char(1), sq,stock,late,rtn,isd smallint
	define sdt date
	define lvol char(4)


	# initialise program variables
	let nv='0'
	let sq=1
	let stock=111
	let late=11
	let rtn=101
	let isd=10
	let sdt=today

	let lvol='aaaa'

	# create a (temp) table and load it
	create temp table abc (cat char(1),volno smallint,vol char(4),stkadj smallint)
	insert into abc values ('A',1,'aaaa',1)

	# select table data plus program variable values into array record
	select cat,volno,vol,nv,sq,sdt,isd,stock,late,rtn,stkadj
			into bksa[1].* from abc where vol=lvol

	# and what have we got?
	display bksa[1].* at 2,1
	display bksa[1].sq at 3,1
	display bksa[1].sdt using "dd/mm/yyyy" at 4,1
	if bksa[1].sdt is NULL then display "NULL DATE" at 4,20 ; end if
	display bksa[1].isd at 5,1
	display bksa[1].stock at 6,1
	display bksa[1].late at 7,1
	display bksa[1].pubrtn at 7,10
	display bksa[1].p_adj at 7,20

	drop table abc

	end main

