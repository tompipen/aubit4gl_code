
#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"


{
	From: 	W. Haslbeck <spam.langweilt@gmx.de>
To: 	aubit4gl-discuss@lists.sourceforge.net
Subject: 	[Aubit4gl-discuss] Strange behaviour of 'comments' with non-ascii chars...
Date: 	Mon, 8 Mar 2004 22:47:46 +0100	
Hi,

if you use non-ascii chars (e.g. german umlauts) in the 'comments' directive 
of a screen-form, every non-ascii char is displayed reverse, blinking and 
underlined. This only happens with HL_TUI and only to the 'comments' string, 
all other non-ascii are displayed correct... strange, strange:



> For UI=HL_TUI, I get reverse video on the comments, but still nothing
> displayed.

I just checked out the latest CVS and now it works fine with HL_TUI.

> For UI=HL_TUIN, I get everything displayed - but the comments are still
> reverse video...

> (This could just be a feature of my environment - not being configured for
> german characters and hence not 'isprint' able)

sure. I normaly use "de_DE@euro" as LANG setting. If I set LANG to "C",
I ONLY see the umlauts in the comments, but no umlauts in the screen
input field and the screen.

}


main
define x char(50)
    open window w_t at 2,2 with form "f_t"
    let x="form field: ö ä ü Ö Ä Ü ß µ ?"
    input by name x without defaults
		on key (f10)
			call aclfgl_dump_screen("out")
	end input
	
	
end main
