#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"
{
	From: 	W. Haslbeck <spam.langweilt@gmx.de>
To: 	aubit4gl-discuss@lists.sourceforge.net
Subject: 	[Aubit4gl-discuss] BUG: construct by name
Date: 	Mon, 8 Mar 2004 18:37:51 +0100	
Hi,

I get an segfault when I try to use 'construct by name' on the latest CVS 
aubit-version:

When I use 'construct l on test.a, test.b, test.c from a,b,c' everything works 
as expected.
}
main
define l char(500)
define a,b,c char(5)
    open window w_test at 2,2 with form "f_t" attribute(border)
    #construct l on test.a, test.b, test.c from a, b, c
    construct by name l on test.a, test.b, test.c
    close window w_test
    display l clipped
	if l="test.a>'1' and test.b matches '*a' and test.c<='3'" then
		exit program 0
	else
		exit program 1
	end if
end main


