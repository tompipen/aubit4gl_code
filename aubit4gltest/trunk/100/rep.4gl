database test1

main
define lv_systables record
	tabname char(18),
	tabid integer
end record
define a, cnt integer,
ins_text char(180)
define lv_a integer
define lv_b char(20)


############################
#testing insert cursor
############################

display "creating..."
	create temp table rtab1111111 (tabname CHAR (18),tabid INTEGER )

      let ins_text = " insert into rtab1111111 values (?,?)"
display "preparing..."
	  prepare i_1 from ins_text
display "declaring..."
	  declare ins_j_curs cursor for i_1
display "opening..."

      begin work

	  open ins_j_curs
      for cnt = 1 to 3
display "PUT:"
let lv_a=909
let lv_b="abc"
		 put ins_j_curs from "abc", lv_a
      end for

display "closing..."
	  close ins_j_curs

      commit work

display "declaring..."
	declare c2 cursor for
		select * from rtab1111111

	foreach c2 into lv_systables.*
		display lv_systables.tabid ,">", lv_systables.tabname clipped , "<"
	end foreach


delete from rtab1111111

############################
#now let's test insert-select
############################

    insert into rtab1111111
        select tabname,tabid from systables where
			(tabid<30 or tabid>89) and tabid <> 3 and tabid < 100



	declare c1 cursor for
		select tabname,tabid from rtab1111111 where
			(tabid<30 or tabid>89) and tabid <> 3 and tabid < 100

#<                3 sysindices
#---
#>                3 sysindexes



	start report r1  to "rep.out"
	foreach c1 into lv_systables.*
		#display lv_systables.tabid ,">", lv_systables.tabname clipped , "<"
		output to report r1 (lv_systables.*)
	end foreach


# ORDER BY temp table fails to populate char filed:
{
	declare c2 cursor for
		select * from 	#rtab134524352
						rtab134525472

	foreach c2 into lv_systables.*
		display lv_systables.tabid ,">", lv_systables.tabname clipped , "<"
	end foreach
}
	finish report r1

end main

report r1 (rv_systables)
define rv_systables record
	tabname char(18),
	tabid integer
end record
#FIXME: ORDER BY nulls rv_systables.tabname on SQLite connection
	order by rv_systables.tabid
	format
	on every row

	#display rv_systables.tabid ,">", rv_systables.tabname clipped , "<"
	#display rv_systables.tabid ,">", rv_systables.tabname, "<"


#without CLIPPED SQLite will return char(128) padded with spaces
#          1>systables                                                                                                                       <
#		tabname varchar (128,0),
#FIXME: in Aubit sql.c set option to SQLite driver NOT to padd with spaces. Untill
#or is this OK? maybe it was becuase I have IDS 9.x with systables defined as varchar?
#then I'll add CLIPPED here

	#print rv_systables.tabid," ",rv_systables.tabname
	print rv_systables.tabid," ",rv_systables.tabname CLIPPED
end report
