unset DEBUG
export A4GL_LEXTYPE=EC
export A4GL_LEXDIALECT=INFORMIX
export AUBITDIR=c:/gnu/cygwin/usr/src/aubit/aubit4glsrc
export PATH=$PATH:/usr/src/aubit/aubit4glsrc/bin:/usr/src/aubit/aubit4glsrc/lib:$AUBITDIR/bin:$AUBITDIR/lib

cd /usr/src/aubit/aubit4glsrc/lib/libui/ui_curses
make -f makefile.win32
cd /usr/src/aubit/aubit4glsrc/lib/libaubit4gl
make -f makefile.static
cd /usr/src/aubit/aubit4glsrc/tools/asql

if [ "$1" = 4gl ]
then
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_asql.ao asql.4gl

4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_cedit.ao cedit.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_connection_menu.ao connection_menu.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_database.ao database.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_menus.ao menus.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_execute.ao execute.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_filehand.ao filehand.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_form.ao form.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_infx.ao infx.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_load.ao load.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_main_menu.ao main_menu.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_paginate.ao paginate.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_pick.ao pick.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_query.ao query.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_report.ao report.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_session.ao session.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_table.ao table.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_tools.ao tools.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o sifx_user_menu.ao user_menu.4gl
fi


gcc -mms-bitfields -Wl,--export-all-symbols $IFX_LIBS -g sifx_menus.ao  sifx_asql.ao sifx_connection_menu.ao sifx_pick.ao sifx_database.ao sifx_main_menu.ao sifx_query.ao sifx_session.ao sifx_table.ao sifx_execute.ao sifx_paginate.ao sifx_cedit.ao sifx_filehand.ao sifx_load.ao sifx_form.ao sifx_tools.ao sifx_user_menu.ao sifx_report.ao lex.asql_yy.o simple_parse.o dir.o sifx_infx.ao -o asql_si.exe -LC:/gnu/cygwin/usr/src/aubit/aubit4glsrc/lib  ../../lib/libaubit4gl/libaubit4gl.a -Lc:/gnu/cygwin/usr/src/aubit/aubit4glsrc/tools/cygwin/libform -lform_g c:/gnu/pdc27_ming_w32/panel.a c:/gnu/pdc27_ming_w32/pdcurses.a  "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/isqlt09a.dll" "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/igl4n304.dll" "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/iglxn304.dll" "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/igo4n304.dll"    -lwsock32
