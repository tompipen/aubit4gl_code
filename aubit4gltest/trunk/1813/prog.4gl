define aaa smallint,
       bbb date
main
OPEN WINDOW wokno AT 1,1 WITH  FORM "ftest"

input aaa from fl1
#end input

#input bbb from fl2
#end input

close window wokno

if aaa!=123 then
	exit program 2
end if

end main

