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
       lv_stname,lv_so char(18)
define lv_txt CHAR(64)
define lv_c1,lv_c2 integer
define lv_nn char(10)
DEFINE lv_systables integer	#true or false, process Informix sys* tables (default=0)
DEFINE lv_prefix_idx smallint  #true or false, add prefic to index names (default=false)
DEFINE lv_no_owner smallint
define lv_qry char(80)
define lv_c integer


	call locate_blob()

	let lv_t=downshift(lv_t)
	
	if lv_t="all" then
		let mv_idx_cnt = 0
		if lv_systables = 1 then

				let lv_qry="select tabname from systables "
		else
				let lv_qry="select tabname from systables where tabid>99"
		end if
		
		prepare p_get_tables from lv_qry
			declare c_get_tables cursor for p_get_tables
		foreach c_get_tables into lv_t
			call dump_table(lv_t,lv_systables,lv_prefix_idx,lv_no_owner)
		end foreach
		return
	end if
	
	
	# Get our basic table information
	select tabid,owner,tabtype,partnum into lv_st.tabid,lv_st.owner,lv_st.tabtype ,lv_st.partnum
	from systables where tabname=lv_t
	
	if sqlca.sqlcode=100 then
		DISPLAY "Table ",lv_t clipped," not found"
		return
	end if
	
	
	
	IF lv_st.tabtype="S" THEN
		select btabid into lv_stid from syssyntable where tabid=lv_st.tabid
		select tabname,owner into lv_stname,lv_so from systables where tabid=lv_stid
	
		if get_mode()=0 then

			call outstr(" ")
			let lv_str="CREATE SYNONYM"
			if lv_no_owner then
				let lv_str=lv_str clipped, " ",lv_t clipped
			else
				let lv_str=lv_str clipped, " \"",lv_st.owner CLIPPED,"\".",lv_t clipped
			end if
			let lv_str=lv_str clipped, " FOR \"",lv_so clipped,
				"\".",lv_stname clipped,";"
			call outstr(lv_str)
			call outstr(" ")
		end if
	
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
	
		if get_mode()=0 then
			CALL outstr(lv_bigstr)
		end if
	
		RETURN
	END IF
	
	
	
	
	IF lv_st.tabtype="T" THEN
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
			let lv_str="[",lv_t clipped," ",lv_st.tabid using "<<<<<<<<<<"," ",lv_st.partnum using "<<<<<<<<<<<<","]"
			call outstr(lv_str clipped)
		end if
		
		
		declare c2 cursor for 
		select colname,coltype,collength,colno,"" from syscolumns
		where tabid=lv_st.tabid 
		order by colno
		
		
		# Now process each bit of column information
		let lv_str=" "
		foreach c2 into lv_sc.*
			let lv_c=lv_sc.colno
			let lv_colnames[lv_c]=lv_sc.colname
	
	
			if get_mode()=0 then
				if lv_str!=" " then 
					let lv_str=lv_str clipped,"," 
					call outstr(lv_str) 
					let lv_str= " " 
				end if
			else
				let lv_str=lv_sc.colname clipped," ",lv_sc.coltype using "<<<<<&"," ",lv_sc.collength using "<<<<<&"
				call outstr(lv_str) 
				let lv_str= " "
			end if
		
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
	if get_mode()=1 then
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

end function


################################################################################
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
				let lv_qry="select tabname from systables "
		else
				let lv_qry="select tabname from systables where tabid>99"
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
			when "U" DISPLAY "UNLOAD TO '",lv_t clipped,".unl' SELECT * FROM ",lv_t clipped,";"
			when "L" 
				DISPLAY "LOAD FROM '",lv_t clipped,".unl' INSERT INTO ",lv_t clipped,";"
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
					DISPLAY "IF dbms_dialect()='POSTGRESQL' THEN"
					DISPLAY "	let lv = \"SELECT setval('",
						lv_t clipped,"_",
						lv_serial_colname clipped,"_seq', max(",
						lv_serial_colname clipped,")) FROM ",
						lv_t clipped,";\""
					DISPLAY "	PREPARE cur1 FROM lv"
					DISPLAY "	EXECUTE cur1"
					DISPLAY "END IF"
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

	#display "...."
	#display lv_rec.evalpos," ",lv_rec.strat
	if lv_rec.evalpos=0 then
		if lv_rec.strat="R" then
			let lv_str="FRAGMENT BY ROUND ROBIN IN ",lv_rec.dbspace
		end if

		if lv_rec.strat="E" then
			#display "Calling byte as str"
                         let lv_str="FRAGMENT BY EXPRESSION ",aclfgl_byte_as_str(mv_exprtext)," IN ",lv_rec.dbspace
		end if
	else
		let lv_str=lv_str clipped,","
		if lv_rec.strat="R" then
			let lv_str=lv_str clipped," ",lv_rec.dbspace
		end if
		if lv_rec.strat="E" then
			#display "Calling byte as str"
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

