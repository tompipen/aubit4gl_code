database mips_3_3


define lv_colnames array[2000] of char(18)

define lv_st record
	tabname char(64),
	owner char(8),
	tabid integer,
	tabtype char(1)
end record

define lv_sc record
	colname char(64),
	coltype integer,
	collength integer,
	colno integer,
	coldesc char(64)
end record

define lv_i record 
	idxname    char(18),
	owner      char(8),
	tabid      integer,
	idxtype    char(1),
	clustered  char(1),
	part1      smallint,
	part2      smallint,
	part3      smallint,
	part4      smallint,
	part5      smallint,
	part6      smallint,
	part7      smallint,
	part8      smallint,
	part9      smallint,
	part10     smallint,
	part11     smallint,
	part12     smallint,
	part13     smallint,
	part14     smallint,
	part15     smallint,
	part16     smallint
end record


#main
	#call dump_table("w_reg_docs")
	#call dump_table("t_reg_docs")
	#call dump_table("ss1")
#end main

################################################################################
function dump_table(lv_t)
define lv_t char(64)
define lv_str char(256)
define lv_bigstr char(1000000)
define lv_l char(1)
define lv_es,lv_ns  integer
define lv_stid integer,
       lv_stname,lv_so char(18)
define lv_txt CHAR(64)
define lv_c1,lv_c2 integer

let lv_t=downshift(lv_t)

if lv_t="all" then
	declare c_get_tables cursor for
		select tabname from systables where tabid>99
	
	foreach c_get_tables into lv_t
		call dump_table(lv_t)
	end foreach
	return
end if


# Get our basic table information
select tabid,owner,tabtype into lv_st.tabid,lv_st.owner,lv_st.tabtype 
from systables where tabname=lv_t

if sqlca.sqlcode=100 then
	display "Table ",lv_t clipped," not found"
	return
end if



IF lv_st.tabtype="S" THEN
	select btabid into lv_stid from syssyntable where tabid=lv_st.tabid
	select tabname,owner into lv_stname,lv_so from systables where tabid=lv_stid
	call outstr(" ")
	let lv_str="CREATE SYNONYM \"",lv_st.owner,"\".",lv_t clipped, " FOR \"",lv_so clipped,"\".",lv_stname clipped,";"
	call outstr(lv_str)
	call outstr(" ")
	RETURN
END IF


IF lv_st.tabtype="V" THEN
	DECLARE c_get_view CURSOR FOR
	SELECT viewtext,seqno FROM sysviews WHERE tabid=lv_st.tabid
	ORDER BY seqno
	LET lv_bigstr=" "
	let lv_c1=1 
	let lv_c2=64

	FOREACH c_get_view INTO lv_txt
		LET lv_bigstr[lv_c1,lv_c2]=lv_txt
		let lv_c1=lv_c1+64
		let lv_c2=lv_c2+64
	END FOREACH
	
	CALL outstr(lv_bigstr)
	RETURN
END IF




IF lv_st.tabtype="T" THEN
	# Generate out CREATE TABLE line
	let lv_str= "CREATE TABLE \"",lv_st.owner clipped,"\".",lv_t clipped," ("
	call outstr(lv_str clipped)
	
	declare c2 cursor for 
	select colname,coltype,collength,colno,"" from syscolumns
	where tabid=lv_st.tabid 
	order by colno
	
	
	# Now process each bit of column information
	let lv_str=" "
	foreach c2 into lv_sc.*
	
		let lv_colnames[lv_sc.colno]=lv_sc.colname
		if lv_str!=" " then 
				let lv_str=lv_str clipped,"," call outstr(lv_str) 
		end if
	
		case lv_sc.coltype
			when 0 let lv_sc.coldesc="CHAR(",lv_sc.collength using "<<<<<<<",")"
			when 1 let lv_sc.coldesc="SMALLINT"
			when 2 let lv_sc.coldesc="INTEGER"
			when 3 let lv_sc.coldesc="FLOAT"
			when 4 let lv_sc.coldesc="SMALLFLOAT"
			when 5 let lv_sc.coldesc="DECIMAL(",lv_sc.collength using "<<<<<<<",")"
			when 6 let lv_sc.coldesc="SERIAL"
			when 7 let lv_sc.coldesc="DATE"
			when 8 let lv_sc.coldesc="MONEY"
			when 9 let lv_sc.coldesc="---"
			when 10 let lv_sc.coldesc="DATETIME"
			when 11 let lv_sc.coldesc="BYTE"
			when 12 let lv_sc.coldesc="TEXT"
			when 13 let lv_sc.coldesc="VARCHAR(",lv_sc.collength using "<<<<<<<",")"
			when 14 let lv_sc.coldesc="INTERVAL(",lv_sc.collength using "<<<<<<<",")"
		end case
		let lv_str="   ",lv_sc.colname clipped," ",lv_sc.coldesc
	end foreach
	
	if lv_str!=" " then call outstr(lv_str) end if



	# Any server specific stuff ?
	if is_ss() then
		#  Do the server specific stuff..
	
		select locklevel,fextsize,nextsize into lv_l, lv_es,lv_ns from systables where tabid=lv_st.tabid
	
		let lv_str=") EXTENT SIZE ",lv_es using "<<<<<"," NEXT SIZE ",lv_ns using "<<<<<<" 
		if lv_l="P" then
				let lv_str=lv_str clipped," LOCK MODE PAGE"
		Else
				let lv_str=lv_str clipped," LOCK MODE ROW"
		end if
		let lv_str=lv_str clipped,";"
		call outstr(lv_str)
	else
		let lv_str=");"
		call outstr(lv_str)

	end if

end if


call outstr(" ")
let lv_str="REVOKE ALL ON \"",lv_st.owner clipped,"\".",lv_t clipped," FROM \"public\";"
call outstr(lv_str)

let lv_str=""

# Indexes....


declare c3 cursor for 
	select * from sysindexes where tabid=lv_st.tabid


initialize lv_i.* to null

foreach c3 into lv_i.*

	let lv_str="Unhandled : '",lv_i.idxtype,"' '",lv_i.clustered,"'"

	if lv_i.idxtype="U" and (lv_i.clustered="-"  or lv_i.clustered=" ") then
		let lv_str="CREATE UNIQUE INDEX \"",lv_i.owner,"\".",lv_i.idxname clipped," ON \"",lv_st.owner,"\".",lv_t clipped," ("
	end if

	if lv_i.idxtype="U" and lv_i.clustered="C" then
		let lv_str="CREATE UNIQUE CLUSTER INDEX \"",lv_i.owner,"\".",lv_i.idxname clipped," ON \"",lv_st.owner,"\".",lv_t clipped," ("
	end if

	if (lv_i.idxtype="-" or lv_i.idxtype="D")  and lv_i.clustered="C" then
		let lv_str="CREATE CLUSTER INDEX \"",lv_i.owner,"\".",lv_i.idxname clipped," ON \"",lv_st.owner,"\".",lv_t clipped," ("
	end if

	if (lv_i.idxtype="-" or lv_i.idxtype="D") and (lv_i.clustered="-" or lv_i.clustered=" ")  then
		let lv_str="CREATE INDEX \"",lv_i.owner,"\".",lv_i.idxname clipped," ON \"",lv_st.owner,"\".",lv_t clipped," ("
	end if

	call outstr(" ")

	call outstr(lv_str)

	if lv_i.part1!=0 then
	  let lv_str=get_column(lv_st.tabid,lv_i.part1)
	  if lv_i.part2!=0 then	
	    let lv_str=lv_str clipped,","
	    call outstr(lv_str)
	    let lv_str=get_column(lv_st.tabid,lv_i.part2)
	    if lv_i.part3!=0 then	
	      let lv_str=lv_str clipped,","
	      call outstr(lv_str)
	      let lv_str=get_column(lv_st.tabid,lv_i.part3)
	      if lv_i.part4!=0 then	
	        let lv_str=lv_str clipped,","
	        call outstr(lv_str)
	        let lv_str=get_column(lv_st.tabid,lv_i.part4)
	        if lv_i.part5!=0 then	
	          let lv_str=lv_str clipped,","
	          call outstr(lv_str)
	          let lv_str=get_column(lv_st.tabid,lv_i.part5)
	          if lv_i.part6!=0 then	
	            let lv_str=lv_str clipped,","
	            call outstr(lv_str)
	            let lv_str=get_column(lv_st.tabid,lv_i.part6)
	            if lv_i.part7!=0 then	
	              let lv_str=lv_str clipped,","
	              call outstr(lv_str)
	              let lv_str=get_column(lv_st.tabid,lv_i.part7)
	              if lv_i.part8!=0 then	
	                let lv_str=lv_str clipped,","
	                call outstr(lv_str)
	                let lv_str=get_column(lv_st.tabid,lv_i.part8)
	                if lv_i.part9!=0 then	
	                  let lv_str=lv_str clipped,","
	                  call outstr(lv_str)
	                  let lv_str=get_column(lv_st.tabid,lv_i.part9)
	                  if lv_i.part10!=0 then	
	                    let lv_str=lv_str clipped,","
	                    call outstr(lv_str)
	                    let lv_str=get_column(lv_st.tabid,lv_i.part10)
	                    if lv_i.part11!=0 then	
	                      let lv_str=lv_str clipped,","
	                      call outstr(lv_str)
	                      let lv_str=get_column(lv_st.tabid,lv_i.part11)
	                      if lv_i.part12!=0 then	
	                        let lv_str=lv_str clipped,","
	                        call outstr(lv_str)
	                        let lv_str=get_column(lv_st.tabid,lv_i.part12)
	                        if lv_i.part13!=0 then	
	                          let lv_str=lv_str clipped,","
	                          call outstr(lv_str)
	                          let lv_str=get_column(lv_st.tabid,lv_i.part13)
	                          if lv_i.part14!=0 then	
	                            let lv_str=lv_str clipped,","
	                            call outstr(lv_str)
	                            let lv_str=get_column(lv_st.tabid,lv_i.part14)
	                            if lv_i.part15!=0 then	
	                              let lv_str=lv_str clipped,","
	                              call outstr(lv_str)
	                              let lv_str=get_column(lv_st.tabid,lv_i.part15)
	                              if lv_i.part16!=0 then	
	                                let lv_str=lv_str clipped,","
	                                call outstr(lv_str)
	                                let lv_str=get_column(lv_st.tabid,lv_i.part16)
	                              else
	                                call outstr(lv_str)
	                              end if
	                            else
	                              call outstr(lv_str)
	                            end if
	                          else
		                    call outstr(lv_str)
	                          end if
	                        else
		                  call outstr(lv_str)
	                        end if
	                      else
		                call outstr(lv_str)
	                      end if
	                    else
		              call outstr(lv_str)
	                    end if
	                  else
		            call outstr(lv_str)
	                  end if
	                else
		          call outstr(lv_str)
	                end if
	              else
		          call outstr(lv_str)
	              end if
	            else
		      call outstr(lv_str)
	            end if
	          else
		    call outstr(lv_str)
	          end if
	        else
		  call outstr(lv_str)
	        end if
	      else
	        call outstr(lv_str)
	      end if
	    else
	      call outstr(lv_str)
	    end if
	  else
	    call outstr(lv_str)
	  end if
	else
		# Should have at least one....
		display "Unexpected error"
	end if
	call outstr(");")
end foreach

end function





function get_column(lv_tid,lv_colno)
define lv_tid integer
define lv_colno integer
define lv_asc char(1)
if lv_colno<0 then
	return "   "||lv_colnames[lv_colno]|| " DESC"
else
	return "   "||lv_colnames[lv_colno]
end if
end function

