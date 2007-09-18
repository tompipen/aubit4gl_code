main
define s1 char(200)
	open window w1 at 1,1 with form "bibble"
	construct by name s1 on  b.somecol
	if s1!="b.somecol='01/01/2006'" then
		exit program 1
	end if


end main
