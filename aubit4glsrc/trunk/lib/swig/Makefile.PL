#FIXME: replace -curses with value asigned by autoconf (can be ncurses)

use ExtUtils::MakeMaker;
WriteMakefile(
        'NAME'    => 'aubit4gl_pl',
        'LIBS'=> [ '-lm -lcurses -lform -lpanel' ], 
        'OBJECT'  => 'lib_wrap.o ../libaubit4gl.so'
);


