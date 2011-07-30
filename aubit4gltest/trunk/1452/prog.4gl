database test1

main
define
   q_txt      char(200)

open window win1 at 2, 2 with form "test14" attribute (border)

construct q_txt on systables.tabname, systables.version
   from formonly.tabname, formonly.version

close window win1

display q_txt clipped

if q_txt <> "systables.version in ('12345678','12345678','12345678','12345678','12345678','12345678')" then
    display "bad"
	sleep 1
    exit program 1
end if
display "Good"
	sleep 1
exit program 0
end main
