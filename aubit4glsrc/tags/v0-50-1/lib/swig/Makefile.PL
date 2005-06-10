#FIXME: replace -curses with value asigned by autoconf (can be ncurses)

#why do we need -lcurses -lform -lpanel anyway - UI output is done
#via Aubit plug-in liUI_xxxx.so anyway, which is already linked with appropriate
#libraries, including -lcurses -lform -lpanel
#also, libaubit4gl.so is already linked with -lm

use ExtUtils::MakeMaker;

WriteMakefile(
        'NAME'    => 'aubit4gl_pl',
        'LIBS'=> [ '-laubit4gl -lm -lncurses -lform -lpanel -L..' ], 
        'OBJECT'  => 'lib_wrap.o '
);


