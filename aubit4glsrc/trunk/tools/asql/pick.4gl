define mv_arr array[100] of char(18)
define mv_cnt integer
define mv_curr_option integer
define mv_rows integer

function show_pick() 
define a,x,y integer
define yinc integer

if mv_cnt<4*9 then
	let yinc=2
else 
	let yinc=1
end if
	
let x=1
let y=6
let mv_rows=0
let y=y-yinc
set pause mode on
for a=1 to mv_cnt

	let y=y+yinc

	if y>=24 then
		if mv_rows=0 then
			let mv_rows=a-1
		end if
		let y=6
		let x=x+20
	end if


	if a=mv_curr_option then
		display mv_arr[a][1,18]  at y,x attribute(reverse)
	else
		display mv_arr[a][1,18]  at y,x
	end if
end for
set pause mode off
end function

function set_pick(lv_sub,lv_value)
define lv_sub integer
define lv_value char(255)
let mv_arr[lv_sub]=lv_value
end function


function set_pick_cnt(lv_cnt)
define lv_cnt integer
let mv_cnt=lv_cnt
let mv_curr_option=1
end function



function prompt_pick(lv_txt,lv_value)
define lv_txt char(80)
define lv_value char(80)
call clear_screen_portion()

if mv_cnt >=1 then
	let int_flag=false
	call show_pick()
	prompt lv_txt clipped for lv_value #attribute(normal)

	on key(down)
		if mv_curr_option+1<=mv_cnt then
			let mv_curr_option=mv_curr_option+1
			call show_pick()
		end if
		continue prompt
	
	on key(right)
		if mv_curr_option+mv_rows<=mv_cnt then
			let mv_curr_option=mv_curr_option+mv_rows
			call show_pick()
		end if
		continue prompt
	
	
	on key(up)
		if mv_curr_option-1>=1 then
			let mv_curr_option=mv_curr_option-1
			call show_pick()
		end if
		continue prompt
	
	on key(left)
		if mv_curr_option-mv_rows>=1 then
			let mv_curr_option=mv_curr_option-mv_rows
			call show_pick()
		end if
		continue prompt
	
	end prompt

	if int_flag=true then
		call clear_screen_portion()
		return ""
	end if
else
	let int_flag=false
	prompt lv_txt clipped for lv_value
	if int_flag=true then
		call clear_screen_portion()
		return ""
	end if
end if

if lv_value is null or lv_value matches " " then
	let lv_value=mv_arr[mv_curr_option]
end if
	
call clear_screen_portion()
return lv_value
end function

