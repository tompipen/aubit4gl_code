#FIXME: replace -curses with value asigned by autoconf (can be ncurses)

use ExtUtils::MakeMaker;
WriteMakefile(
        'NAME'    => 'aubit4gl_pl',
        'LIBS'=> [ '-laubit4gl -lm -lcurses -lform -lpanel -L..' ], 
        'OBJECT'  => 'lib_wrap.o '
);


