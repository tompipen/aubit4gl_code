main
display "Start"

start report r1 to "r1.out"
output to report r1 (1)


# The first finish should be fine...
display "Finish 1"
finish report r1

# But a second one without starting it again....
display "Finish 2"
whenever error continue
finish report r1

if status=0 then
	# It worked - shouldn't happen
	# the original bug caused a core dump before here...
	exit program 9
else
# Yippee - it didn't work!
	display "Skipped - status=",status
end if

exit program 0
end main

report r1 (a )
define a integer
format
every row 
end report
