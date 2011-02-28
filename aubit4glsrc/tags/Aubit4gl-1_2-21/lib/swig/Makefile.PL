use ExtUtils::MakeMaker;

WriteMakefile(
        'NAME'    => 'aubit4gl_pl',
        'LIBS'=> [ '-laubit4gl -lm -L..' ], 
        'OBJECT'  => 'lib_wrap.o'
);


