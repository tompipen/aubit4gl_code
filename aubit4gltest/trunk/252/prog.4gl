MAIN
	DEFINE
		x	INTEGER,
		y	INTEGER

define ans char

	OPEN FORM arr4 FROM "t508"
	DISPLAY FORM arr4 ATTRIBUTE (CYAN)
	call aclfgl_dump_screen("out")
	sleep 50
end main
