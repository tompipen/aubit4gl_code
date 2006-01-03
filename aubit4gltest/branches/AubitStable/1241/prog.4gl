Database test1
main
define lv_a char(8)
define lv_o char(8)

	create temp table bibble (
		u char(8)
	)

	insert into bibble values(user)

	select * into lv_o from bibble
	if lv_o matches " " or lv_o is null then
		exit program 1
	end if

	display lv_o

	select * into lv_a from  bibble where u=user
	display lv_a
	if lv_a!=lv_o then exit program 1 end if

	select user into lv_a from  bibble
	display lv_a
	if lv_a!=lv_o then exit program 1 end if

	exit program 0

end main

