use ExtUtils::MakeMaker;
WriteMakefile(
        'NAME'    => 'aubit4gl_pl',
        'LIBS'=> [ '-lm -lcurses -lform -lpanel' ], 
        'OBJECT'  => 'lib_wrap.o ../libaclall-noodbc.a'
);


