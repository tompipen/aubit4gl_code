Database aubit_tests
define lv_catalogue record like catalogue.*
define lv_pass array[10] of  char(50)
define lv_result char(1)
define lv_skip_reason char(20)
define lv_ts array[10] of char(19)
define lv_vs array[10] of decimal(4,2)
define lv_vb array[10] of smallint
define lv_codes array[10] of char(10)
define mv_prepare integer
define mv_short_only char(20)

# This assumes all the data has already been loaded into the database
main
define lv_mode integer
define a integer
define lv_fname char(200)
let lv_mode=0
let lv_codes[1]="NODB"
let lv_codes[2]="ESQLI"
let lv_codes[3]="ECI"
let lv_codes[4]="ECP"
let lv_codes[5]="IFXODBC"
let lv_codes[6]="SQLITE"
let lv_codes[7]="PGODBC"
let lv_codes[8]="MYODBC"
let lv_codes[9]=" "
let mv_short_only=" "
--set isolation to dirty read
set lock mode to wait

for a=1 to 10 
	select timestamp,aubit_version,aubit_build into lv_ts[a] ,lv_vs[a],lv_vb[a]
	from test_Run
	where 
	test_run.log_text=lv_codes[a]




end for


if arg_val(1)="SHORT" THEN
	let lv_mode=2
	if num_args() > 1 then
		let mv_short_only=arg_val(2)
		let lv_fname= "rep_tests_short_",mv_short_only clipped,".html"
		start report rep_tests to lv_fname
	else
		start report rep_tests to "rep_tests_short.html"
	end if
		
end if

if arg_val(1)="DB" THEN
	start report rep_tests to "rep_tests_db.html"
	let lv_mode=3
end if

if lv_mode=0 then
	let lv_mode=1
	start report rep_tests to "rep_tests_long.html"
end if
if arg_val(1)="SHORT" then
	delete from catalogue
	load from "/home/aubit4gl/aubit4gltest/docs/catalogue.unl" insert into catalogue
end if

declare c1 cursor for select * from catalogue order by test_no

foreach c1 into lv_catalogue.*
	let lv_pass[1]="?"
	let lv_pass[2]="?"
	let lv_pass[3]="?"
	let lv_pass[4]="?"
	let lv_pass[5]="?"
	let lv_pass[6]="?"
	let lv_pass[7]="?"
	let lv_pass[8]="?"
	let lv_pass[9]="?"
	let lv_pass[10]="?"
	
	let lv_pass[1]=get_result(lv_catalogue.test_no,1)
	let lv_pass[2]=get_result(lv_catalogue.test_no,2)
	let lv_pass[3]=get_result(lv_catalogue.test_no,3)
	let lv_pass[4]=get_result(lv_catalogue.test_no,4)
	let lv_pass[5]=get_result(lv_catalogue.test_no,5)
	let lv_pass[6]=get_result(lv_catalogue.test_no,6)
	let lv_pass[7]=get_result(lv_catalogue.test_no,7)
	let lv_pass[8]=get_result(lv_catalogue.test_no,8)
	#let lv_pass[9]=get_result(lv_catalogue.test_no,9)

	
	
	
	output to report rep_tests(lv_catalogue.*,
		lv_pass[1], lv_pass[2], lv_pass[3], lv_pass[4], lv_pass[5],
		lv_pass[6], lv_pass[7], lv_pass[8], lv_pass[9], lv_pass[10],lv_mode)
	
end foreach
	

finish report rep_tests

















end main





function get_result(lv_test,lv_no)
define lv_no integer
define lv_test integer
define lv_result,lv_skip_reason char(50)
define lv_r integer
define ps1 char(200)
if mv_prepare is null then
		let ps1=" select result,skip_reason from results where test_no=?  and   timestamp=?"
		prepare px1 from ps1
	let mv_prepare=1
end if
execute  px1 into lv_r,lv_skip_reason USING lv_test, lv_ts[lv_no]


if lv_skip_reason is not null and lv_R is null then
	return "!" 
end if


if lv_r=1 then return "1" end if
if lv_r=0 then return "0" end if
if lv_r is null then return "*" end if
return "?"

end function

report rep_tests(lv_cat, lv_p1,lv_p2,lv_p3,lv_p4,lv_p5,lv_p6,lv_p7,lv_p8,lv_p9,lv_p10,lv_mode)
define lv_cat record like catalogue.*
define lv_p1, lv_p2, lv_p3, lv_p4, lv_p5, lv_p6, lv_p7, lv_p8, lv_p9, lv_p10 char(1)
define lv_mode integer
define lv_arr array[10] of  record
	ok integer,
	fail integer,
	skip integer,
	notdone integer,
	query integer
end record
define  a integer
define lv_so integer
output left margin 0
top margin 0
bottom margin 0
format
first page header
for a=1 to 10
	let lv_arr[a].ok=0
	let lv_arr[a].fail=0
	let lv_arr[a].skip=0
	let lv_arr[a].notdone=0
	let lv_arr[a].query=0
end for

print "<table>";
print "<tr valign=top>";
print "<td></td>";
print title(1,1) clipped;
print title(2,1) clipped;
print title(3,1) clipped;
print title(4,1) clipped;
print title(5,1) clipped;
print title(6,1) clipped;
print title(7,1) clipped;
print title(8,1) clipped;
--print title(9,1) clipped;
--print title(10) clipped;
print "</tr>"

print "<tr valign=top>";
print "<td></td>";
print title(1,2) clipped;
print title(2,2) clipped;
print title(3,2) clipped;
print title(4,2) clipped;
print title(5,2) clipped;
print title(6,2) clipped;
print title(7,2) clipped;
print title(8,2) clipped;
--print title(9,2) clipped;
--print title(10) clipped;
print "</tr>"

print "<tr valign=top>";
print "<td></td>";
print title(1,3) clipped;
print title(2,3) clipped;
print title(3,3) clipped;
print title(4,3) clipped;
print title(5,3) clipped;
print title(6,3) clipped;
print title(7,3) clipped;
print title(8,3) clipped;
--print title(9,3) clipped;
--print title(10) clipped;
print "</tr>"

print "<tr valign=top>";
print "<th>Test No</th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th></th>";
print "<th>Description</th>";
print "</tr>"





on every row

case lv_p1
when "1" let lv_arr[1].ok=lv_arr[1].ok+1
when "0" let lv_arr[1].fail=lv_arr[1].fail+1 
when "!" let lv_arr[1].skip=lv_arr[1].skip+1 
when "*" let lv_arr[1].notdone=lv_arr[1].notdone+1 
when "?" let lv_arr[1].query=lv_arr[1].query+1 
end case

case lv_p2
when "1" let lv_arr[2].ok		=lv_arr[2].ok+1
when "0" let lv_arr[2].fail		=lv_arr[2].fail+1 
when "!" let lv_arr[2].skip		=lv_arr[2].skip+1 
when "*" let lv_arr[2].notdone	=lv_arr[2].notdone+1 
when "?" let lv_arr[2].query	=lv_arr[2].query+1 
end case

case lv_p3
when "1" let lv_arr[3].ok		=lv_arr[3].ok+1
when "0" let lv_arr[3].fail		=lv_arr[3].fail+1 
when "!" let lv_arr[3].skip		=lv_arr[3].skip+1 
when "*" let lv_arr[3].notdone	=lv_arr[3].notdone+1 
when "?" let lv_arr[3].query	=lv_arr[3].query+1 
end case

case lv_p4
when "1" let lv_arr[4].ok		=lv_arr[4].ok+1
when "0" let lv_arr[4].fail		=lv_arr[4].fail+1 
when "!" let lv_arr[4].skip		=lv_arr[4].skip+1 
when "*" let lv_arr[4].notdone	=lv_arr[4].notdone+1 
when "?" let lv_arr[4].query	=lv_arr[4].query+1 
end case

case lv_p5
when "1" let lv_arr[5].ok		=lv_arr[5].ok+1
when "0" let lv_arr[5].fail		=lv_arr[5].fail+1 
when "!" let lv_arr[5].skip		=lv_arr[5].skip+1 
when "*" let lv_arr[5].notdone	=lv_arr[5].notdone+1 
when "?" let lv_arr[5].query	=lv_arr[5].query+1 
end case

case lv_p6
when "1" let lv_arr[6].ok=lv_arr[6].ok+1
when "0" let lv_arr[6].fail=lv_arr[6].fail+1 
when "!" let lv_arr[6].skip=lv_arr[6].skip+1 
when "*" let lv_arr[6].notdone=lv_arr[6].notdone+1 
when "?" let lv_arr[6].query=lv_arr[6].query+1 
end case

case lv_p7
when "1" let lv_arr[7].ok=lv_arr[7].ok+1
when "0" let lv_arr[7].fail=lv_arr[7].fail+1 
when "!" let lv_arr[7].skip=lv_arr[7].skip+1 
when "*" let lv_arr[7].notdone=lv_arr[7].notdone+1 
when "?" let lv_arr[7].query=lv_arr[7].query+1 
end case

case lv_p8
when "1" let lv_arr[8].ok=lv_arr[8].ok+1
when "0" let lv_arr[8].fail=lv_arr[8].fail+1 
when "!" let lv_arr[8].skip=lv_arr[8].skip+1 
when "*" let lv_arr[8].notdone=lv_arr[8].notdone+1 
when "?" let lv_arr[8].query=lv_arr[8].query+1 
end case

case lv_p9
when "1" let lv_arr[9].ok=lv_arr[9].ok+1
when "0" let lv_arr[9].fail=lv_arr[9].fail+1 
when "!" let lv_arr[9].skip=lv_arr[9].skip+1 
when "*" let lv_arr[9].notdone=lv_arr[9].notdone+1 
when "?" let lv_arr[9].query=lv_arr[9].query+1 
end case

case lv_p10
when "1" let lv_arr[10].ok=lv_arr[10].ok+1
when "0" let lv_arr[10].fail=lv_arr[10].fail+1 
when "!" let lv_arr[10].skip=lv_arr[10].skip+1 
when "*" let lv_arr[10].notdone=lv_arr[10].notdone+1 
when "?" let lv_arr[10].query=lv_arr[10].query+1 
end case



if lv_mode=1 then
	print 	"<tr>",
		td(lv_cat.test_no),
		td(ft(lv_p1)),
		td(ft(lv_p2)),
		td(ft(lv_p3)),
		td(ft(lv_p4)),
		td(ft(lv_p5)),
		td(ft(lv_p6)),
		td(ft(lv_p7)),
		td(ft(lv_p8)),
		--td(ft(lv_p9)),
		td(lv_cat.test_desc_txt),
		"</tr>"

end if

if lv_mode=2 then
	let lv_so=0
	if mv_short_only=" " then
		if lv_p1="0" or lv_p2="0" or lv_p3="0" or lv_p4="0" or lv_p5="0" or lv_p6="0" or lv_p7="0" or lv_p8="0" or lv_p8="0" then # Only show where something has failed
			let lv_So=1
		end if
	else
		if mv_short_only=lv_codes[1] and lv_p1="0" then let lv_so=1 end if
		if mv_short_only=lv_codes[2] and lv_p2="0" then let lv_so=2 end if
		if mv_short_only=lv_codes[3] and lv_p3="0" then let lv_so=3 end if
		if mv_short_only=lv_codes[4] and lv_p4="0" then let lv_so=4 end if
		if mv_short_only=lv_codes[5] and lv_p5="0" then let lv_so=5 end if
		if mv_short_only=lv_codes[6] and lv_p6="0" then let lv_so=6 end if
		if mv_short_only=lv_codes[7] and lv_p7="0" then let lv_so=7 end if
		if mv_short_only=lv_codes[8] and lv_p8="0" then let lv_so=8 end if
		--if mv_short_only=lv_codes[9] and lv_p9="0" then let lv_so=9 end if
	end if


	if lv_so then
		print 	"<tr>";
			print td(lv_cat.test_no);
			print td(ft(lv_p1));
			print td(ft(lv_p2));
			print td(ft(lv_p3));
			print td(ft(lv_p4));
			print td(ft(lv_p5));
			print td(ft(lv_p6));
			print td(ft(lv_p7));
			print td(ft(lv_p8));
			--print td(ft(lv_p9));
;
			print td(lv_cat.test_desc_txt);
			print "</tr>"
	end if
end if

if lv_mode=3 then
	if lv_p2="0" or lv_p3="0" or lv_p4="0" or lv_p5="0" or lv_p6="0" or lv_p7="0" or lv_p8="0" or lv_p8="0"  
	 or lv_p2="1" or lv_p3="1" or lv_p4="1" or lv_p5="1" or lv_p6="1" or lv_p7="1" or lv_p8="1" or lv_p8="1"  
		then # Only show where something has failed
		print 	"<tr>";
		print td(lv_cat.test_no);
		print td(ft(lv_p1));
		print td(ft(lv_p2));
		print td(ft(lv_p3));
		print td(ft(lv_p4));
		print td(ft(lv_p5));
		print td(ft(lv_p6));
		print td(ft(lv_p7));
		print td(ft(lv_p8));
		--print td(ft(lv_p9));
		print td(lv_cat.test_desc_txt);
		print "</tr>"
	end if
end if



on last row 
	print "<tr valign=top>";
	print td("");
	print tdt(summary( lv_arr[1].ok, lv_arr[1].fail, lv_arr[1].skip, lv_arr[1].notdone, lv_arr[1].query));
	print tdt(summary( lv_arr[2].ok, lv_arr[2].fail, lv_arr[2].skip, lv_arr[2].notdone, lv_arr[2].query));
	print tdt(summary( lv_arr[3].ok, lv_arr[3].fail, lv_arr[3].skip, lv_arr[3].notdone, lv_arr[3].query));
	print tdt(summary( lv_arr[4].ok, lv_arr[4].fail, lv_arr[4].skip, lv_arr[4].notdone, lv_arr[4].query));
	print tdt(summary( lv_arr[5].ok, lv_arr[5].fail, lv_arr[5].skip, lv_arr[5].notdone, lv_arr[5].query));
	print tdt(summary( lv_arr[6].ok, lv_arr[6].fail, lv_arr[6].skip, lv_arr[6].notdone, lv_arr[6].query));
	print tdt(summary( lv_arr[7].ok, lv_arr[7].fail, lv_arr[7].skip, lv_arr[7].notdone, lv_arr[7].query));
	print tdt(summary( lv_arr[8].ok, lv_arr[8].fail, lv_arr[8].skip, lv_arr[8].notdone, lv_arr[8].query));
	--print tdt(summary( lv_arr[9].ok, lv_arr[9].fail, lv_arr[9].skip, lv_arr[9].notdone, lv_arr[9].query));
	print "</tr>"

	print "</table>"

end report


function summary(o,f,s,n,q)
define o,f,s,n,q integer
define lv_buff char(200)
define t integer
let lv_buff=""
if o or 1 then let lv_buff=lv_buff clipped,o using "<<<<<","&nbsp;OK<br>" end if
if f or 1 then let lv_buff=lv_buff clipped,f using "<<<<<","&nbsp;Fail<br>" end if
if s or 1 then let lv_buff=lv_buff clipped,s using "<<<<<","&nbsp;Skip<br>" end if
#if n then let lv_buff=lv_buff clipped,n using "<<<<<","&nbsp;Not Done<br>" end if
#if q then let lv_buff=lv_buff clipped,q using "<<<<<","&nbsp;Query<br>" end if

let t=o+f
if t>0 then
	let t=(o*100)/t
	let lv_buff=lv_buff clipped,t using "<<<<","%&nbsp;OK"
end if
return lv_buff
end function

function td(lv_str)
define lv_str char(256)
let lv_str="<td>",lv_str clipped,"</td>"
return lv_str clipped
end function

function tdt(lv_str)
define lv_str char(256)
let lv_str="<td valign=top>",lv_str clipped,"</td>"
return lv_str clipped
end function

function ft(x) 
define x char(1)
define lv_buff char(200)
let lv_buff="?"
if x="1" then let lv_buff="<img src=ok.gif alt=ok>" end if
if x="0" then let lv_buff="<img src=fail.gif alt=fail>" end if
if x="!" then let lv_buff="<img src=skip.gif alt=skip>" end if
if x="*" then let lv_buff="<img src=notdone.gif alt=notdone>" end if
if x="?" then let lv_buff="<img src=query.gif alt=unknown>" end if
return lv_buff
end function



function title(a,l)
define a integer
define lv_str char(255)
define lv_t char(20)
define l integer
let lv_t=lv_ts[a]
let lv_t[11]=" " 
if l=1 then
	
	let lv_str="<td width=40 align=center><bold>",lv_codes[a] clipped,"</bold></td>"
end if
if l=2 then
	
	let lv_str="<td><small>",lv_t clipped,"</td>"
end if
if l=3 then
	let lv_str= "<td><small>",lv_vs[a] using "&.&&","-",lv_vb[a],"</small></td>"
end if
return lv_str
end function
