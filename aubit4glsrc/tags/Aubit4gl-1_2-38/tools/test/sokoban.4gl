globals
define mv_level array[25] of char(80)
end globals

define mv_last_level array[25] of char(80)
define mv_Display_type integer

define mv_player char(1)
define mv_diamond char(1)
define mv_hole char(1)
define mv_diamond_in_hole char(1)
define mv_brick char(1)
define mv_moves integer
define mv_pushes integer
define mv_complete integer
define mv_player_x, mv_player_y integer
define mv_board_width, mv_board_height integer
define mv_this_level integer
define mv_sw integer


main
define lv_dummy char(1)
let mv_Display_type=0
let mv_sw=80
{!
if fgl_getenv("COLUMNS") then
	let mv_sw=fgl_getenv("COLUMNS")
end if
if fgl_getenv("A4GL_UI")="GTK" or fgl_getenv("A4GL_UI")="HL_GTK" then
	let mv_display_type=1
end if
!}

	options prompt line last
	let mv_this_level=1

	let mv_player		= "@"
	let mv_diamond		= "$"
	let mv_hole		= "."
	let mv_diamond_in_hole	= "*"
	let mv_brick		= "#"


	while true
		call load_level()
		

		let mv_moves=0
		let mv_pushes=0

		while true

			call display_board()

			if level_complete() then
				exit while
			end if
	
			prompt "" for char lv_dummy attribute(invisible)
	
				on key(control-k) 
					if change_level() then
						call load_level()
					end if

				on key(left)
					call move_left()
	
				on key(right)
					call move_right()
	
				on key(up)
					call move_up()
	
				on key(down)
					call move_down()
	
				on key(escape)
					call load_level()
	
			end prompt
		end while
		let mv_this_level=mv_this_level+1
	end while

end main


function get_level()
	return mv_this_level
end function

function display_board()
define lv_offx,lv_offy integer
define lv_x,lv_y integer
define a,b integer
define c char(1)

{! set pause mode on !}

	let lv_offy=(24-mv_board_height)/2
	let lv_offx=(mv_sw-mv_board_width)/2

	for a=1 to mv_board_height
		let lv_y=a+lv_offy
		if mv_display_type=0 then
			display mv_level[a] clipped at lv_y,lv_offx
		else
			for b=1 to mv_board_width
				let lv_x=lv_offx-1+b
				let c=mv_level[a][b]
				case c
				when mv_brick 
					display " " at lv_y,lv_x attribute(red)

				when mv_diamond 
					display " " at lv_y,lv_x attribute(blue)

				when mv_diamond_in_hole
					display " " at lv_y,lv_x attribute(yellow)

				when mv_hole
					display " " at lv_y,lv_x attribute(green)

				otherwise
					display " " at lv_y,lv_x 
				end case
			end for
				
				
		end if
	end for

	let lv_y=mv_player_y+lv_offy
	let lv_x=mv_player_x+lv_offx-1

	display mv_player at lv_y,lv_x attribute(cyan)

	display "Moves:",mv_moves using "<<<<<<" at 1,1 
	display "Level:",mv_this_level using "<<<<<<" at 1,30
	display "Pushes:",mv_pushes using "<<<<<<" at 1,65
{! set pause mode off !}
end function



function find_player()
define a,b integer
	let mv_player_x=0
	let mv_player_y=0

	for a=1 to 25
		for b=1 to 80
			if mv_level[a][b]=mv_player then
				let mv_player_x=b
				let mv_player_y=a
				let mv_level[a][b]=" " # Remove the player...
				return
			end if
		end for
	end for
end function



function clear_board()
define a integer
	for a=1 to 25
		let mv_level[a]=" "
		if a>1 and a<24 then
			display " ","" at a,1
		end if
	end for
end function



function size_board()
define a integer
define lv_maxx integer
define lv_maxy integer
	let lv_maxx=0
	let lv_maxy=0

	for a=1 to 25
		if length(mv_level[a])=0 then
			let lv_maxy=a-1
			exit for
		end if
	
		if length(mv_level[a])>lv_maxx then
			let lv_maxx=length(mv_level[a])
		end if
	end for
	let mv_board_width=lv_maxx
	let mv_board_height=lv_maxy
end function

function change_level()
define lvl integer
define lv_wx integer
let lv_wx=get_x(30)
	open window w_chg at 10,lv_wx with 3 rows, 30 columns attribute(border)
	let int_flag=false
	prompt "Enter level" for lvl
	close window w_chg
	if int_flag=false then
		let mv_this_level=lvl
		return 1
	end if
	return 0
end function
	


function load_level()
	call clear_board()
	call set_level()
	call find_player()
	if mv_player_x=0 or mv_player_y=0 then
		display "Unable to find player..."
		exit program
	end if
	call size_board()
end function


function move_left()
define lv_newx integer
define lv_newy integer
define lv_newx2 integer
define lv_newy2 integer

	let lv_newx=mv_player_x-1
	let lv_newx2=mv_player_x-2
	let lv_newy=mv_player_y
	let lv_newy2=mv_player_y
	
	call move(lv_newx,lv_newy,lv_newx2,lv_newy2)
end function



function move_right()
define lv_newx integer
define lv_newy integer
define lv_newx2 integer
define lv_newy2 integer

	let lv_newx=mv_player_x+1
	let lv_newx2=mv_player_x+2
	let lv_newy=mv_player_y
	let lv_newy2=mv_player_y
	
	call move(lv_newx,lv_newy,lv_newx2,lv_newy2)
end function


function move_up()
define lv_newx integer
define lv_newy integer
define lv_newx2 integer
define lv_newy2 integer

	let lv_newx=mv_player_x
	let lv_newx2=mv_player_x
	let lv_newy=mv_player_y-1
	let lv_newy2=mv_player_y-2
	
	call move(lv_newx,lv_newy,lv_newx2,lv_newy2)
end function

function move_down()
define lv_newx integer
define lv_newy integer
define lv_newx2 integer
define lv_newy2 integer

	let lv_newx=mv_player_x
	let lv_newx2=mv_player_x
	let lv_newy=mv_player_y+1
	let lv_newy2=mv_player_y+2
	
	call move(lv_newx,lv_newy,lv_newx2,lv_newy2)
end function





function move(lv_newx,lv_newy,lv_newx2,lv_newy2)
define lv_newx integer
define lv_newy integer
define lv_newx2 integer
define lv_newy2 integer

	if lv_newx=0 or lv_newx>=80 or lv_newy=0 or lv_newy>=24 then
		return
	end if
	
	if mv_level[lv_newy][lv_newx]=" " or mv_level[lv_newy][lv_newx]=mv_hole then
		let mv_player_x=lv_newx
		let mv_player_y=lv_newy
		let mv_moves=mv_moves+1
		return
	end if
	
	
	# We can't walk through walls...
	if mv_level[lv_newy][lv_newx]=mv_brick then
		return
	end if
	
	# We want to push a diamond..
	if mv_level[lv_newy][lv_newx]=mv_diamond then
		if mv_level[lv_newy2][lv_newx2]!=" " and mv_level[lv_newy2][lv_newx2]!=mv_hole then
			# We can only push onto a hole
			# or a space..
			return
		end if
	
		let mv_player_x=lv_newx
		let mv_player_y=lv_newy
		if mv_level[lv_newy2][lv_newx2]=" " then
				let mv_level[lv_newy2][lv_newx2]=mv_diamond
				let mv_level[lv_newy][lv_newx]=" "
		else
			# must be a hole
				let mv_level[lv_newy2][lv_newx2]=mv_diamond_in_hole
				let mv_level[lv_newy][lv_newx]=" "
		end if
		let mv_pushes =mv_pushes+1
		let mv_moves  =mv_moves+1
	end if

	# We want to push a diamond out of a hole..
	if mv_level[lv_newy][lv_newx]=mv_diamond_in_hole then
		if mv_level[lv_newy2][lv_newx2]!=" " and mv_level[lv_newy2][lv_newx2]!=mv_hole then
			# We can only push onto a hole
			# or a space..
			return
		end if
	
		let mv_player_x=lv_newx
		let mv_player_y=lv_newy
		if mv_level[lv_newy2][lv_newx2]=" " then
				let mv_level[lv_newy2][lv_newx2]=mv_diamond
				let mv_level[lv_newy][lv_newx]="."
		else
			# must be a hole
				let mv_level[lv_newy2][lv_newx2]=mv_diamond_in_hole
				let mv_level[lv_newy][lv_newx]="."
		end if
		let mv_pushes =mv_pushes+1
		let mv_moves  =mv_moves+1
	end if




end function

function level_complete()
define a integer
define lv_wx integer
let lv_wx=get_x(30)
for a=1 to mv_board_height
	if mv_level[a] matches "*$*" then
		return 0
	end if
end for
open window x1 at 10,lv_wx with 3 rows, 18 columns attribute(border,reverse,blue)
display " LEVEL COMPLETE!!" at 2,1
sleep 2
close window x1
return 1

end function

function display_copywrite(auth,copywrite,name)
define auth,copywrite,name char(40)
define lv_wx integer
let lv_wx=get_x(40)
open window cc1 at 10,lv_wx with 4 rows,40 columns attribute(border,reverse,red)
	display "Level ",name at 1,1
	display auth at 3,1
	display copywrite at 4,1
sleep 2
close window cc1
end function

function levels_finished()
define lv_wx integer
let lv_wx=get_x(30)
open window x1 at 10,lv_wx with 3 rows, 30 columns attribute(border,reverse,blue)
display "ALL LEVEL COMPLETE  !!" at 2,1
sleep 2
close window x1
exit program
end function

function get_x(n)
define n integer
let n=(mv_sw-n)/2
return n
end function
