define mv_exprtext byte



define lv_colnames array[2000] of char(128) #in IDS varchar(128,0)
define mv_idx_cnt smallint
define lv_st record
	tabname char(128), 	#In IDS 9.x tabname (and most indentifiers) are varchar(128,0)
	owner char(32),		#char(32) in IDS
	tabid integer,
	tabtype char(1),
	partnum integer
end record
define dtparts array[10] of char(10)

define lv_sc record
	colname char(128),
	coltype integer,
	collength integer,
	colno integer,
	coldesc char(64)
end record

define lv_i record 
	idxname    char(128), 	# varchar(128,0) in IDS 9
	owner      char(8),		#char 32 in IDS
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
define mv_located integer
define mv_real_table char(64)


#main
	#call dump_table("w_reg_docs",0,0,0)
	#call dump_table("t_reg_docs",0,0,0)
	#call dump_table("ss1",0,0,0)
#end main

################################################################################
function dump_table(lv_t,lv_systables,lv_prefix_idx,lv_no_owner)
define lv_t, lv_owner_i_str, lv_owner_t_str char(64) #In IDS all varchar(128,0)
define lv_str char(256)
define lv_bigstr char(32000)
define lv_l char(1)
define lv_es,lv_ns  integer
define lv_stid integer,
       lv_stname,lv_so char(64)
define lv_txt CHAR(64)
define lv_c1,lv_c2 integer
define lv_nn char(10)
define lv_servname char(64)
define lv_fulldb char(256)
define lv_dbname char(64)
DEFINE lv_systables integer	#true or false, process Informix sys* tables (default=0)
DEFINE lv_prefix_idx smallint  #true or false, add prefic to index names (default=false)
DEFINE lv_no_owner smallint
define lv_qry char(80)
define lv_c integer
define lv_localdb char(64)
define a integer
define lv_ncols integer


define lv_systab_name char(128)
define lv_syscolumns_name char(128)
define lv_syssyntable_name char(128)
define lv_sysviews_name char(128)
define lv_q1 char(512)


	call locate_blob()

	let lv_systab_name="systables"
	let lv_syscolumns_name="syscolumns"
	let lv_syssyntable_name="syssyntable"
	let lv_sysviews_name="sysviews"

	let lv_t=downshift(lv_t)

	if lv_t matches "*:*" then
		let lv_localdb=lv_t
		for a=1 to length(lv_localdb)
			if lv_localdb[a]=":" then
				let lv_t=lv_localdb[a+1,64]
				let lv_localdb=lv_localdb[1,a-1]
				let lv_systab_name=lv_localdb clipped,":systables"
				let lv_syscolumns_name=lv_localdb clipped,":syscolumns"
				let lv_syssyntable_name=lv_localdb clipped,":syssyntables"
				let lv_sysviews_name=lv_localdb clipped,":sysviews"
				exit for
			end if
		end for
	end if
	
	if lv_t="all" then
		let mv_idx_cnt = 0
		if lv_systables = 1 then
				let lv_qry="select tabname,tabid from ",lv_systab_name clipped," order by 2"
		else
				let lv_qry="select tabname,tabid from ",lv_systab_name clipped," where tabid>99 order by 2"
		end if
		
		prepare p_get_tables from lv_qry
			declare c_get_tables cursor for p_get_tables

		foreach c_get_tables into lv_t
			call dump_table(lv_t,lv_systables,lv_prefix_idx,lv_no_owner)
		end foreach
		return
	end if
        if is_online() then
                # Get our basic table information for online
		let lv_q1=" select tabid,owner,tabtype,partnum from ",lv_systab_name," where tabname='",lv_t clipped,"'"
		
	        prepare p_q1 from lv_q1
		declare c_q1 cursor for p_q1 open c_q1 fetch c_q1 into lv_st.tabid,lv_st.owner,lv_st.tabtype ,lv_st.partnum 
        else
                # Get our basic table information for SE
                let lv_st.partnum=-1
		let lv_q1=" select tabid,owner,tabtype from ", lv_systab_name clipped, " where tabname='",lv_t clipped,"'"
	        prepare p_q2 from lv_q1 declare c_q2 cursor for p_q2 open c_q2 fetch c_q2 into lv_st.tabid,lv_st.owner,lv_st.tabtype 
        end if

	
	if sqlca.sqlcode=100 then
		DISPLAY "Table ",lv_t clipped," not found"
		return
	end if
	
	
	
	IF lv_st.tabtype="S" THEN
		# create synonym "aubit4gl".stab2 for test1@mike_2:"informix".systables;
		initialize lv_so to null

		let lv_q1="select servername, dbname, btabid,tabname,owner from ", 
				lv_syssyntable_name clipped, " where tabid=",lv_st.tabid
		#display lv_q1
		prepare p_syn from  lv_q1
		execute p_syn into lv_servname, lv_dbname, lv_stid, lv_stname,lv_so  

		
		if lv_stid is not null  then
			let lv_q1="select tabname,owner from ",lv_systab_name," where tabid=",lv_stid
			prepare p_so from  lv_q1
			execute p_so into lv_stname,lv_so 
		else 
			#
		end if
		if lv_dbname is null then let lv_dbname=" " end if
		if lv_servname is null then let lv_servname=" " end if
		let lv_fulldb=lv_dbname

		if length(lv_servname) then
			let lv_fulldb=lv_dbname clipped, "@",lv_servname
		end if

		if length(lv_fulldb) then
			let lv_fulldb=lv_fulldb clipped,":"
		end if

		if get_mode()=0 then

			call outstr(" ")
			let lv_str="CREATE SYNONYM"
			if lv_no_owner is not null then
				let lv_str=lv_str clipped, " ", lv_stname clipped
			else
				let lv_str=lv_str clipped, " \"",lv_st.owner CLIPPED,"\".",lv_stname clipped
			end if

			let lv_str=lv_str clipped, " FOR ", lv_fulldb clipped, "\"",lv_so clipped,
				"\".",lv_stname clipped,";"
			call outstr(lv_str)
			call outstr(" ")
		else
			call dump_synonym_fileschema(lv_t,lv_fulldb, lv_stname);
		end if
	
		RETURN
	END IF
	
	
	IF lv_st.tabtype="V" and get_mode()!=1  THEN
		let lv_q1="SELECT viewtext,seqno FROM ",lv_sysviews_name," WHERE tabid=",lv_st.tabid," ORDER BY seqno"
		prepare p_sv from  lv_q1
		DECLARE c_get_view CURSOR FOR p_sv
		LET lv_bigstr=" "
		let lv_c1=1 
		let lv_c2=64
	
		FOREACH c_get_view INTO lv_txt
			LET lv_bigstr[lv_c1,lv_c2]=lv_txt
			let lv_c1=lv_c1+64
			let lv_c2=lv_c2+64
		END FOREACH
	
		if get_mode()=0 then
			CALL outstr(lv_bigstr)
		end if
	
		RETURN
	END IF
	
	
	
	
	IF lv_st.tabtype="T" OR (lv_st.tabtype="V" and get_mode()=1) THEN
		# Generate out CREATE TABLE line
	
		if get_mode()=0 then
			let lv_str= "CREATE TABLE"
			if lv_no_owner then
				let lv_str=lv_str clipped," ",lv_t clipped," ("
			else
				let lv_str=lv_str clipped," \"",lv_st.owner clipped,"\".",lv_t clipped," ("			
			end if
			
			call outstr(lv_str clipped)
		else
			if get_mode()=1 then
				if length(mv_real_table)>0 then
				let lv_str="[",mv_real_table clipped," ",lv_st.tabid using "<<<<<<<<<<"," ",lv_st.partnum using "<<<<<<<<<<<<","]"
				else
				let lv_str="[",lv_t clipped," ",lv_st.tabid using "<<<<<<<<<<"," ",lv_st.partnum using "<<<<<<<<<<<<","]"
				end if
				call outstr(lv_str clipped)
			end if
		end if
		
		
 		let lv_q1=" select colname,coltype,collength,colno,'' from ",
				lv_syscolumns_name clipped," where tabid=",lv_st.tabid ," order by colno"
		prepare p_scols from lv_q1
 		declare c2 cursor for  p_scols

		
		let lv_ncols=0
		foreach c2 into lv_sc.*
			let lv_ncols=lv_ncols+1
		end foreach
		
		# Now process each bit of column information
		let lv_str=" "
		foreach c2 into lv_sc.*
			let lv_c=lv_sc.colno
			let lv_colnames[lv_c]=lv_sc.colname
	
	
			case get_mode()
			when 0 
				if lv_str!=" " then 
					let lv_str=lv_str clipped,"," 
					call outstr(lv_str) 
					let lv_str= " " 
				end if
			when 1
				let lv_str=lv_sc.colname clipped," ",lv_sc.coltype using "<<<<<&"," ",decode_collength(lv_sc.coltype, lv_sc.collength) using "<<<<<&"
				call outstr(lv_str) 
				let lv_str= " "
			when 2
				if lv_sc.colno<lv_ncols then
					let lv_str=get_prefix(),".",lv_sc.colname clipped,","
				else
					let lv_str=get_prefix(),".",lv_sc.colname clipped
				end if
				call outstr(lv_str) 
				let lv_str= " "
			end case
				
		
			if lv_sc.coltype>255 then
				let lv_sc.coltype=lv_sc.coltype-256
				let lv_nn=" NOT NULL"
			else
				let lv_nn=""
			end if
	
	
			case lv_sc.coltype
				when 0 let lv_sc.coldesc="CHAR(",lv_sc.collength using "<<<<<<<",")"," ",lv_nn
				when 1 let lv_sc.coldesc="SMALLINT"," ",lv_nn
				when 2 let lv_sc.coldesc="INTEGER"," ",lv_nn
				when 3 let lv_sc.coldesc="FLOAT"," ",lv_nn
				when 4 let lv_sc.coldesc="SMALLFLOAT"," ",lv_nn
	
				when 5 let lv_sc.coldesc="DECIMAL(",decode_decimal(lv_sc.collength),")"," ",lv_nn
	
				when 6 let lv_sc.coldesc="SERIAL"," ",lv_nn
				when 7 let lv_sc.coldesc="DATE"," ",lv_nn
				when 8 let lv_sc.coldesc="MONEY(",decode_decimal(lv_sc.collength),")"," ",lv_nn
				when 9 let lv_sc.coldesc="---"
				when 10 let lv_sc.coldesc="DATETIME ",decode_datetime(lv_sc.collength)," ",lv_nn
				when 11 let lv_sc.coldesc="BYTE"," ",lv_nn
				when 12 let lv_sc.coldesc="TEXT"," ",lv_nn
				when 13 let lv_sc.coldesc="VARCHAR(",decode_varchar(lv_sc.collength) clipped,")"," ",lv_nn
				when 14 let lv_sc.coldesc=decode_interval(lv_sc.collength) clipped," ",lv_nn
				when 15 let lv_sc.coldesc="NCHAR(",lv_sc.collength using "<<<<<<<",")"," ",lv_nn
				when 17 let lv_sc.coldesc="INT8"," ",lv_nn
	#Andrej mod
				#This is just a hack to allow us to retrive Informix sys* tables info
				#and is higly unlikely to be used in 4GL code anyway
	
				#40=indexkeyarray (Used in Informix sys* tables like sysindices)
				when 40 let lv_sc.coldesc="CHAR(",10 using "<<<<<<<",")"," ",lv_nn
				#41=rtnparamtypes (Used in sysprocedures)
				when 41 let lv_sc.coldesc="CHAR(",10 using "<<<<<<<",")"," ",lv_nn
	#Andrej mod end.			
				otherwise
					DISPLAY "INVALID DATATYPE: ",lv_sc.coltype
					exit program 1
			end case
			let lv_str="   ",lv_sc.colname clipped," ",lv_sc.coldesc
		end foreach
		
	
	
		if get_mode()=0 then
			if lv_str!=" " then 
				call outstr(lv_str) 
			end if
		end if
	
	
		# Any server specific stuff ?
		if is_ss() then
			#  Do the server specific stuff..
			if get_mode()=0 then





				select locklevel,fextsize,nextsize into lv_l, lv_es,lv_ns from systables where tabid=lv_st.tabid

				let lv_str=") ", frag_info(lv_st.tabid)
				call outstr(lv_str)

				let lv_str=" EXTENT SIZE ",lv_es using "<<<<<"," NEXT SIZE ",lv_ns using "<<<<<<" 
				if lv_l="P" then
						let lv_str=lv_str clipped," LOCK MODE PAGE"
				Else
						let lv_str=lv_str clipped," LOCK MODE ROW"
				end if
				let lv_str=lv_str clipped,";"
				call outstr(lv_str)
			end if
		else
			if get_mode()=0 then
				let lv_str=");"
				call outstr(lv_str)
			end if
	
		end if
	
	end if
	
	if get_mode()=0 then
		call outstr(" ")
		if get_perms() then
			let lv_str="REVOKE ALL ON \"",lv_st.owner clipped,"\".",
				lv_t clipped," FROM \"public\";"
		call outstr(lv_str)
		end if
	end if
	
	let lv_str=""
	
	
	
	# We don't need to worry about dumping indexes for 
	# fileschema mode
	if get_mode()>=1 then
		return
	end if

	
	###########################################
	# Indexes....
	###########################################
	
	declare c3 cursor for 
		select * from sysindexes where tabid=lv_st.tabid
	
	
	initialize lv_i.* to null
	
	######################
	foreach c3 into lv_i.*
	######################
	
		if lv_prefix_idx then
		 	{
			PG:
			The system uses no more than NAMEDATALEN-1 characters of an 
			identifier; longer names can be written in commands, but they 
			will be truncated. By default, NAMEDATALEN is 64 so the maximum 
			identifier length is 63. If this limit is problematic, it can be 
			raised by changing the NAMEDATALEN constant in src/include/postgres_ext.h.
			
			But some version of Informix database are limited to char(18)
			
			In most RDBMS systems  SQL identifiers and key words must begin with a letter
			
			Problem: trunckating to 16 chars can make index names non-unique
			
			This hack with counter will make sure up to 999 indexes in one 
			database, but it can still happen we get a duplicate name.
			Better sollution is needed
			}
			
			#Some version of Informix RDBMS allow index name to begin 
			#with a space, so we muct get rid of this
			let lv_i.idxname = subst_spaces(lv_i.idxname)
			
			
			let mv_idx_cnt= mv_idx_cnt + 1
			let lv_i.idxname = "I", mv_idx_cnt using "&&&",lv_i.idxname clipped
		end if
		
		let lv_str="Unhandled : '",lv_i.idxtype,"' '",lv_i.clustered,"'"
	
		if lv_no_owner then
			let lv_owner_i_str=""
			let lv_owner_t_str=""
		else
			let lv_owner_i_str="\"",lv_i.owner CLIPPED,"\"."
			let lv_owner_t_str="\"",lv_st.owner CLIPPED,"\"."
		end if
		
		if lv_i.idxtype="U" and (lv_i.clustered="-"  or lv_i.clustered=" ") then
			let lv_str="CREATE UNIQUE INDEX ",lv_owner_i_str clipped,
				lv_i.idxname clipped," ON ",lv_owner_t_str clipped,lv_t clipped," ("
		end if
	
		if lv_i.idxtype="U" and lv_i.clustered="C" then
			let lv_str="CREATE UNIQUE CLUSTER INDEX ",lv_owner_i_str clipped,
				lv_i.idxname clipped," ON ",lv_owner_t_str clipped,lv_t clipped," ("
		end if
	
		if (lv_i.idxtype="-" or lv_i.idxtype="D")  and lv_i.clustered="C" then
			let lv_str="CREATE CLUSTER INDEX ",lv_owner_i_str clipped,
				lv_i.idxname clipped," ON ",lv_owner_t_str clipped,lv_t clipped," ("
		end if
	
		if (lv_i.idxtype="-" or lv_i.idxtype="D") and (lv_i.clustered="-" or lv_i.clustered=" ")  then
			let lv_str="CREATE INDEX ",lv_owner_i_str clipped,
				lv_i.idxname clipped," ON ",lv_owner_t_str clipped,lv_t clipped," ("
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
			DISPLAY "Unexpected error"
		end if
		call outstr(");")
	end foreach

	CALL print_triggers(lv_st.tabid)

end function


################################################################################
function get_column(lv_tid,lv_colno)
define lv_tid integer
define lv_colno integer
define lv_asc char(1)
if lv_colno<0 then
	let lv_colno=0-lv_colno 
	return "   "||lv_colnames[lv_colno]|| " DESC"
else
	return "   "||lv_colnames[lv_colno]
end if
end function



################################################################################
function decode_decimal(a)
define a integer
define lv_str char(20)
define m integer
	let m=a mod 256
	let a=(a-m)/256
	
	#NOTE: must use '&' so that we dont get empyt output when zero
	
	if m=255 then
		let lv_str=a using "<<<<&"
	else
		let lv_str=a using "<<<<&", ",", m using "<<<<&"
	end if
	
	return lv_str clipped
end function


################################################################################
function decode_interval(a)
define a integer
define pt1,pt2 integer
define lv_part1,lv_part2 char(20)
define lv_str char(40)
define fr1,fr2 integer
define p1,p2 integer

	call set_dtparts()

        let p1 = (a / 16) MOD 16;
	if p1 <= 10 then
		let pt1=  (p1 / 2) 
	else 
		let pt1= 6
	end if

        let fr2 = (a MOD 16) - 10;

        let p2 = a MOD 16;

	if (p2 <= 10) then
		let pt2= (p2 / 2) 
	else 
		let pt2= 6
	end if

        if pt1 != 6 then
            	let fr1 = (a / 256) + p1 - p2
		if fr1!=2 then
			let lv_part1=dtparts[pt1+1] clipped,"(",fr1 using "<<<<<",")"
		else
			let lv_part1=dtparts[pt1+1] clipped,"(",fr1 using "<<<<<",")"
		end if
        else
		let lv_part1=dtparts[pt1+1];
	end if

        if pt2 = 6  then
		let lv_part2=dtparts[pt2+1] clipped,"(",fr2 using "<<<<<",")"
        else
		let lv_part2=dtparts[pt2+1]
	end if

	let lv_str= "INTERVAL ", lv_part1 clipped, " TO ", lv_part2 ;

	return lv_str
end function



################################################################################
function decode_varchar(a)
define a integer
define lv_str char(20)
if ((a / 256) MOD 256) then
let lv_str=(a MOD 256) using "<<<<",",",((a / 256) MOD 256) USING "<<<<"
else
let lv_str=(a MOD 256) using "<<<<"
end if

return lv_str clipped
end function



################################################################################
function decode_datetime(a)
define a integer
define pt1,pt2 integer
define lv_part1,lv_part2 char(20)
define lv_str char(20)
define fr2 integer
call set_dtparts()
if ((a/16) MOD 16) <= 10  THEN 
  	let pt1=(((a / 16) MOD 16) / 2) 
else 
	let pt1=6;
end if

let lv_part1=dtparts[pt1+1]



if (a MOD 16) <= 10 then
	let pt2= ((a MOD 16) / 2) 
	let lv_part2=dtparts[pt2+1] clipped
else 
	let pt2=6
	let fr2 = (a mod 16) - 10
	let lv_part2=dtparts[pt2+1] clipped,"(", fr2  using "<<<<<",")"
end if

let lv_str= lv_part1 clipped," TO ",lv_part2 
return lv_str
end function









################################################################################
function set_dtparts()
if dtparts[1] is null then
	let dtparts[1]="YEAR"
	let dtparts[2]="MONTH"
	let dtparts[3]="DAY"
	let dtparts[4]="HOUR"
	let dtparts[5]="MINUTE"
	let dtparts[6]="SECOND"
	let dtparts[7]="FRACTION"
end if
end function


function dump(lv_type,lv_t,lv_systables) 
define lv_t char(128) #table name - In IDS 9.x tabname (and most indentifiers) are varchar(128,0)
define lv_type char(1)	#type of statement to dump: (L)OAD or (U)NLOAD
DEFINE lv_systables integer	#true or false, process Informix sys* tables (default=0)
define lv_serial_colname char(128) #name of the colums that is defines as SERIAL type
define lv_tmp_string char(128)
define lv_qry char(256)

	let lv_t=downshift(lv_t)
	
	if lv_t="all" then
		if lv_systables = 1 then
				let lv_qry="select tabname,created,tabid from systables order by created,tabid"
		else
				let lv_qry="select tabname,created,tabid from systables where tabid>99 order by created,tabid"
		end if
		
		prepare p_get_tables2 from lv_qry
			declare c_get_tables2 cursor for p_get_tables2
		foreach c_get_tables2 into lv_t
			call dump(lv_type,lv_t,lv_systables)
		end foreach
		return
	end if

	#Filter-out (skip) table names that begin with user specified prefix
	if get_filter_out_table_prefix() is not null then
		let lv_tmp_string = get_filter_out_table_prefix() clipped, "*"
		if lv_t matches lv_tmp_string then
			#DISPLAY "LOAD/UNLOAD: Filtering out ", lv_t clipped
			return
		end if
	end if
	
	#must make sure we unload/load only tables not views or synonyms
	select tabtype,tabid into lv_st.tabtype, lv_st.tabid
		from systables 
			where tabname = lv_t
	
	if lv_st.tabtype = "" or lv_st.tabtype IS NULL then
		DISPLAY "Error: cannot get tabtype for ",lv_t clipped
		exit program 1
	end if

	select colname into lv_serial_colname
		from syscolumns
			where tabid=lv_st.tabid
				and coltype = 6 #SERIAL
	
	if status = notfound then
		initialize lv_serial_colname to null
	end if 
				
	if lv_st.tabtype = "T" then
		case lv_type
			when "U" call outstr("UNLOAD TO '"||lv_t clipped||".unl' SELECT * FROM "||lv_t clipped||";")
			when "L" call outstr("LOAD FROM '"||lv_t clipped||".unl' INSERT INTO "||lv_t clipped||";")
{				
issue - when loading data using LOAD FROM .... INSERT INTO ...
that contains SERIAL column, data will be loaded, but associated sequence will 
not get updated. So the first INSERT of 0 (zero) to that SERAIL column will fail,
because the sequence does not "know" that there are rows allready in that table.

Sollution: 
identify tables using SERIAL in adbschemma before printing LOAD FROM stmt;
Add this stmt after every LOAD FROM statement:
	SELECT setval('tablename_colname_seq', max(colname)) FROM tablename;
}				
				if lv_serial_colname is not NULL then
					call outstr( "IF dbms_dialect()='POSTGRESQL' THEN")
					call outstr( "	let lv = \"SELECT setval('"|| lv_t clipped||"_"||lv_serial_colname clipped||"_seq', max("||lv_serial_colname clipped||")) FROM "||lv_t clipped||";\"")
					call outstr( "	PREPARE cur1 FROM lv")
					call outstr( "	EXECUTE cur1")
					call outstr( "END IF")
				end if
				
			otherwise
				DISPLAY "Operation >",lv_type, "< on table >", lv_t clipped, 
					"< not implemented yet"
				exit program 1
		end case
	end if
	
end function

#Substiture spaces in string with underline symbol
function subst_spaces(lv_string)
define 
	lv_string char (128),
	lv_length, cnt smallint
	
	let lv_length = length(lv_string)
	
	for cnt = 1 to lv_length
		if lv_string[cnt] = " " then
			let lv_string[cnt] = "_"
		end if
	end for
	
	return lv_string
	
end function



function frag_info(lv_tid) 
define lv_tid integer
define lv_str char(2048)
define lv_rec record
	lv_ftype char(1),
	indexname char(128),
	strat char(1),
	evalpos integer,
	dbspace char(128)
end record
	
whenever error stop
call locate_blob()


DECLARE frags CURSOR FOR 
SELECT exprtext,fragtype,  indexname, strategy, evalpos,  dbspace 
into 
mv_exprtext, lv_rec.lv_ftype , lv_rec.indexname , lv_rec.strat , lv_rec.evalpos ,  lv_rec.dbspace 
FROM sysfragments 
WHERE tabid = lv_tid AND fragtype = 'T' 
ORDER BY evalpos


call locate_blob()
foreach  frags

	if lv_rec.evalpos=0 then
		if lv_rec.strat="R" then
			let lv_str="FRAGMENT BY ROUND ROBIN IN ",lv_rec.dbspace
		end if

		if lv_rec.strat="E" then
                         let lv_str="FRAGMENT BY EXPRESSION ",aclfgl_byte_as_str(mv_exprtext)," IN ",lv_rec.dbspace
		end if
	else
		let lv_str=lv_str clipped,","
		if lv_rec.strat="R" then
			let lv_str=lv_str clipped," ",lv_rec.dbspace
		end if
		if lv_rec.strat="E" then
                         let lv_str=lv_str clipped," ",aclfgl_byte_as_str(mv_exprtext)," IN ",lv_rec.dbspace
		end if
	
	end if
end foreach
#display "lv_str=",lv_str clipped
return lv_str

END FUNCTION



function locate_blob()


if mv_Exprtext is null then
	let mv_located=0
end if
	
if mv_located is null or mv_located=0 then
        locate  mv_exprtext in memory
        let mv_located=1
end if

end function


function is_online()
define a integer

let a=0
select 1 into a from syscolumns
where colname="partnum" and tabid=1
if sqlca.sqlcode=100 then
        return 0
end if

return a

end function



function print_triggers(lv_tabid)
DEFINE lv_tabid INTEGER
DEFINE lv_trigname CHAR(128)
DEFINE lv_t record
   trigid INTEGER,
   trigname CHAR(18),
   owner CHAR(8),
   tabid INTEGER,
   event CHAR(1),
   old CHAR(18),
   new CHAR(18),
   mode CHAR(1)
END RECORD
DEFINE lv_s RECORD
   trigid INTEGER,
   datakey CHAR(1),
   seqno INTEGER,
   data CHAR(256)
END RECORD
DEFINE lv_x CHAR(20000)
DEFINE lv_lastname CHAR(128)
LET lv_lastname="-"
DECLARE trigs CURSOR FOR
	SELECT * from systriggers WHERE tabid=lv_tabid

FOREACH trigs into lv_t.*
	CALL outstr("")
	DECLARE trigdata CURSOR FOR
        	SELECT stb.*
        	FROM  systrigbody stb
        	WHERE lv_t.trigid = stb.trigid
        	AND datakey in ( 'D', 'A' )
        	ORDER BY datakey desc, seqno

	FOREACH trigdata INTO lv_s.*
		if length(lv_s.data)=256 THEN
			CALL outstr_n256(lv_s.data)
		ELSE
			CALL outstr(lv_s.data)
		END IF
	END FOREACH
END FOREACH
END FUNCTION


FUNCTION dump_synonym_fileschema(p_tabname,p_fulldb, p_stname)
define p_tabname, p_fulldb, p_stname char(200)
let mv_real_table=p_tabname
let p_stname=p_fulldb clipped, p_stname clipped
call dump_table(p_stname,0,0,0)
let mv_real_table=""
END FUNCTION


code

#ifndef DTYPE_DECIMAL
#define DTYPE_DECIMAL 5
#endif

#ifndef DTYPE_MONEY
#define DTYPE_MONEY 8
#endif

#ifndef DTYPE_DTIME
#define DTYPE_DTIME 10
#endif

#ifndef DTYPE_INTERVAL
#define DTYPE_INTERVAL 14
#endif

#define TU_END(qual) (qual & 0xf)
#define TU_START(qual) ((qual>>4) & 0xf)
#define TU_LEN(qual) ((qual>>8) & 0xff)


#define TU_YEAR 0
#define TU_MONTH 2
#define TU_DAY 4
#define TU_HOUR 6
#define TU_MINUTE 8
#define TU_SECOND 10
#define TU_FRAC 12
#define TU_F1 11
#define TU_F2 12
#define TU_F3 13
#define TU_F4 14
#define TU_F5 15


static int
Infx_dt_to_A4gl_dt (int n)
{
  switch (n)
    {
    case TU_YEAR:
      return 1;
    case TU_MONTH:
      return 2;
    case TU_DAY:
      return 3;
    case TU_HOUR:
      return 4;
    case TU_MINUTE:
      return 5;
    case TU_SECOND:
      return 6;
    case TU_F1:
      return 7;
    case TU_F2:
      return 8;
    case TU_F3:
      return 9;
    case TU_F4:
      return 10;
    case TU_F5:
      return 11;
    }
  // Shouldn't get to here
  return 3;
}


static long
fixlength (int dtype, int length)
{
  int n1, n2,n3;
  if (dtype > 255)
    dtype -= 256;
  A4GL_debug ("Got datatype : %d length %d\n", dtype, length);
  if (dtype==DTYPE_DECIMAL||dtype==DTYPE_MONEY) {
        int a1,a2;
        a1=length&0xff;
        a2=length>>8;
        if (a1==0xff) {
                a1=2; a2+=5;
                if (a2>32) a2=32;
                length=(a2<<8)+a1;
                return length;
        }

  }


  if (dtype == DTYPE_DTIME)
    {
      n1 = Infx_dt_to_A4gl_dt (TU_START (length));
      n2 = Infx_dt_to_A4gl_dt (TU_END (length));
      return (n1 * 16) + n2;
    }

  if (dtype == DTYPE_INTERVAL)
    {
      n1 = Infx_dt_to_A4gl_dt (TU_START (length));
      n2 = Infx_dt_to_A4gl_dt (TU_END (length));
      n3 = length>>8;

      return (n3<<8)+(n1 * 16) + n2;
    }

  return length;
}
endcode

function decode_collength(lv_t, lv_l) 
define lv_t,lv_l integer
code
lv_t=fixlength (lv_t,lv_l);
endcode
return lv_t
end function

