{
From: 	W. Haslbeck <spam.langweilt@gmx.de>
To: 	aubit4gl-discuss@lists.sourceforge.net
Subject: 	[Aubit4gl-discuss] display numbers to 'to small' formfields
Date: 	Tue, 9 Mar 2004 22:28:53 +0100	


When you run this on i4gl or 4js, '***' is displayed in the formfield to show 
that the number does not fit in the formfield. With a4gl '000' is displayed 
(no matter what UI). I think Aubit should behave like i4gl here and show 
'***'.

}

main
define a smallint
    open window w at 2,2 with form "f_t"
    let a = 1000
    display by name a
    sleep 3
	call aclfgl_dump_screen("out")	
    close window w
end main

