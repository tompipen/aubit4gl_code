# this is only needed to generate the .c files -
# these should be committed to CVS - we dont need to regenerate
# the .c files from the .objspec files all the time...

all: ui_combobox.c ui_curses.c ui_dashboard.c ui_vdc.c ui_browser.c

ui_browser.o: ui_browser.c
	gcc -c -I../../../incl -I.. ui_browser.c

ui_browser.c: ui.browser.objspec  mk_objspec
	sh mk_objspec ui.browser > ui_browser.c

ui_combobox.o: ui_combobox.c
	gcc -c -I../../../incl -I.. ui_combobox.c

ui_combobox.c: ui.combobox.objspec  mk_objspec
	sh mk_objspec ui.combobox > ui_combobox.c

ui_dashboard.o: ui_dashboard.c
	gcc -c -I../../../incl -I.. ui_dashboard.c

ui_dashboard.c: ui.dashboard.objspec  mk_objspec
	sh mk_objspec ui.dashboard > ui_dashboard.c

ui_vdc.o: ui_vdc.c
	gcc -c -I../../../incl -I.. ui_vdc.c

ui_vdc.c: ui.vdc.objspec  mk_objspec
	sh mk_objspec ui.vdc > ui_vdc.c

ui_curses.o: ui_curses.c
	gcc -c -I../../../incl -I.. ui_curses.c

ui_curses.c: ui.curses.objspec  mk_objspec
	sh mk_objspec ui.curses > ui_curses.c


