main
define y,x integer
whenever error continue
for y=1 to 24
display "................................................................................" at y,1
end for
open window w2 at 10,10 with 10 rows,20 columns attribute(border)
call aclfgl_dump_screen("sizing.out");
sleep 3
for y=1 to 24
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at y,1
end for

call window_size() returning y,x

call aclfgl_dump_screen("sized.out");
if y!=10 or x!=20 then
	display "Got the wrong size...",y,",",x
	exit program 1
end if

exit program 0
end main





function window_size()
# return window-height, window-width (smallint)
#-----------------------------------------------------------------------------#
    define
        n,w,h            smallint

    # find height, starting at row 24
    let status = 0
    for n = 25 to 1 step -1
        display "" at n , 1
        if status = 0 then let h=n exit for end if
    end for

    let status = 0
    for n = 80 to 1 step -1
        display "" at h, n
        if status = 0 then let w=n exit for end if
    end for
    return h, w
    whenever error stop
end function
