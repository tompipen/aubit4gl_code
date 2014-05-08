define mv_cnt integer
define mv_rec array[200] of record
        code char(30),
        txt char(60)
end record



################################################################################
function findit_load_data(lv_sql,lv_val)
define lv_sql char(512)
define lv_val char(40)

if lv_sql="-" then
        ## will already be set up...
        return
end if


prepare p_findit from lv_sql
let mv_cnt=1

declare c_findit cursor for p_findit
open c_findit using lv_val

while true
        fetch c_findit into mv_rec[mv_cnt].code, mv_rec[mv_cnt].txt
        if sqlca.sqlcode!=0 then
                exit while
        end if
        let mv_cnt=mv_cnt+1
        if mv_cnt>200 then
                error "Too many values - only first 200 are displayed"
                exit while
        end if
end while
let mv_cnt=mv_cnt-1
#message "mv_cnt=",mv_cnt


end function





################################################################################
# Paramaters : lv_sql - select statement to execute, 
#                       should return 2 columns, code & text 
#              lv_val - value to search for
################################################################################
function findit_with_initial_value(lv_sql,lv_val)
define lv_sql char(512)
define lv_val char(40)
define lv_sval char(40)

define lv_cnt integer
#initialize lv_val to null


if lv_sql="-" then
	open window w_findit at 4,4 with form "finditnosql" attribute(border,green)
else
	open window w_findit at 4,4 with form "findit" attribute(border)
end if

call banner("Find",60)
let lv_cnt=0

while true
	while true
		let int_flag=false

		options input no wrap
		if lv_cnt=0 and lv_val is not null then
			# Use the value we already have for now..
			let lv_cnt=1
		else
			if lv_sql="-" then
			        initialize lv_val to null
			else
				input lv_val without defaults from s_key
			end if
			
			
		end if
		



		if lv_val matches " " then
			initialize lv_val to null
		end if

		if int_flag=true then
			let int_flag=false
			close window w_findit
			initialize lv_val to null
			return lv_val
		end if

		if lv_val is null then
			let lv_sval="*"
                else
                        let lv_sval = upshift(lv_val) clipped, "*"
		end if

		call findit_load_data(lv_sql,lv_sval)

		if mv_cnt=1 then
			# single row - bonus!
			close window w_findit
			let int_flag=false
			return mv_rec[1].code
		end if

		if mv_cnt=0 then
			error "No rows found"
			continue while
		else
			exit while
		end if
	end while

	if lv_sql!="-" then
		display lv_val to s_key
	end if

	let int_flag=false

	call set_count(mv_cnt)
	display array mv_rec to s_array.* attribute(current row display="reverse")
		on key(return)
			exit display
	end display

	if int_flag=true then
		let int_flag=false
		initialize lv_val to null
		continue while
	else
		exit while
	end if

end while
close window w_findit

let mv_cnt=arr_curr()
return mv_rec[mv_cnt].code
end function






function zoom(lv_col,lv_val)
define lv_col,lv_val char(50)
define lv_sql char(200)
if lv_col is null or lv_col matches " " then
	ERROR "No column passed to zoom!!!"
	exit program 2
end if

        initialize lv_sql to null

        case lv_col
                #when "cust_fnc_code"
                        #let lv_sql="select fc_fnc_code, fc_fin_charge from ar_fnc_table where fc_fnc_code matches ?"

		when "authmode"
                        let mv_cnt=3
                        let lv_sql="-"
                        let mv_rec[1].code="W" let mv_rec[1].txt="Web"
                        let mv_rec[2].code="N" let mv_rec[2].txt="None"
                        let mv_rec[3].code="F" let mv_rec[3].txt="Form"

		when "connmode"
			LET mv_cnt=2
			let lv_sql="-"
                        let mv_rec[1].code="P" let mv_rec[1].txt="PROXY"
                        let mv_rec[2].code="S" let mv_rec[1].txt="SSH"
                        let mv_rec[3].code="C" let mv_rec[2].txt="CMDLINE"

		when "application"
			let lv_sql="select application,application from web_application where application matches ?"

		when "4glapplication"
			let lv_sql="select progname,progname from program where progname matches ?"

		when "username"
			let lv_sql="select username,username from web_user where user matches ?"

	end case


        if lv_sql is null then
                error "no search for : '", lv_col clipped ,"' defined "
                sleep 4
                return lv_val
        end if


        return findit_with_initial_value(lv_sql,lv_val)

end function



local function banner(lv_s,lv_width)
define lv_s char(132)
define lv_s2 char(132)
define lv_width integer
define lv_start integer

    let lv_s2=" "
    let lv_start=(lv_width-length(lv_s))/2
    let lv_s2[lv_start,lv_width]=lv_s
    display lv_s2 at 1,1 attribute(reverse,cyan)
end function
