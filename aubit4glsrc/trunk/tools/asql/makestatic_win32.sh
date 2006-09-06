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
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_asql.ao asql.4gl

4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_cedit.ao cedit.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_connection_menu.ao connection_menu.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_database.ao database.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_menus.ao menus.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_execute.ao execute.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_filehand.ao filehand.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_form.ao form.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_infx.ao infx.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_load.ao load.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_main_menu.ao main_menu.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_paginate.ao paginate.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_pick.ao pick.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_query.ao query.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_report.ao report.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_session.ao session.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_table.ao table.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_tools.ao tools.4gl
4glpc -g -DSTATIC_LIBAUBIT4GL -o ifx_user_menu.ao user_menu.4gl
fi


gcc -mms-bitfields -Wl,--export-all-symbols $IFX_LIBS -g  ifx_menus.ao   ifx_asql.ao ifx_connection_menu.ao ifx_pick.ao ifx_database.ao ifx_main_menu.ao ifx_query.ao ifx_session.ao ifx_table.ao ifx_execute.ao ifx_paginate.ao ifx_cedit.ao ifx_filehand.ao ifx_load.ao ifx_form.ao ifx_tools.ao ifx_user_menu.ao ifx_report.ao lex.asql_yy.o simple_parse.o dir.o ifx_infx.ao -o asql_si.exe -LC:/gnu/cygwin/usr/src/aubit/aubit4glsrc/lib  ../../lib/libaubit4gl/libaubit4gl.a -Lc:/gnu/cygwin/usr/src/aubit/aubit4glsrc/tools/cygwin/libform -lform_g c:/gnu/pdc27_ming_w32/panel.a c:/gnu/pdc27_ming_w32/pdcurses.a  "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/isqlt09a.dll" "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/igl4n304.dll" "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/iglxn304.dll" "C:/PROGRA~1/IBM/Informix/CLIENT~1/bin/igo4n304.dll"    -lwsock32
