main
define lv_record 
	tn char(20),
	tid integer
end record
declare c1 cursor for select tabname,tabid from systables

foreach c1 into lv_record.tn thru lv_record.tid
		display lv_record.tn, " ",lv_record.tid
end foreach

end main

