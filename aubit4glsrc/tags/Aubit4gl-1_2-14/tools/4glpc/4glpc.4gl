pragma force ui "CONSOLE"
pragma debug file "debug.4glpc.out"


DEFINE mv_ansi_mode       SMALLINT

# 4gl -> c/ec
# C-> OBJ
# EC -> C
DEFINE mv_ar_cmd          CHAR(256)
DEFINE mv_ar_opts         CHAR(256)
DEFINE mv_aubit4gllib     CHAR(5000)
DEFINE mv_compile_4gl     CHAR(256)
DEFINE mv_compile_4gl_opts CHAR(256)
DEFINE mv_compile_c       CHAR(256)
DEFINE mv_compile_c_debug CHAR(256)
DEFINE mv_compile_c_opts  CHAR(256)
DEFINE mv_compile_pec     CHAR(256)
DEFINE mv_compile_pec_opts CHAR(256)
DEFINE mv_db              CHAR(128)
DEFINE mv_debug           SMALLINT
DEFINE mv_dll_opts        CHAR(256)
DEFINE mv_dump_strings    INTEGER
DEFINE mv_echomode        SMALLINT
DEFINE mv_errfile         CHAR(256)
DEFINE mv_esql_to_c_first SMALLINT
DEFINE mv_export_symbols  CHAR(256)
DEFINE mv_ignerrs         SMALLINT
DEFINE mv_import_symbols  CHAR(256)
DEFINE mv_include         CHAR(512)
DEFINE mv_keep            SMALLINT
DEFINE mv_lexdialect      CHAR(20)
DEFINE mv_lextype         CHAR(20)
DEFINE mv_libs            CHAR(5000)
DEFINE mv_link            CHAR(256)
DEFINE mv_link_debug      CHAR(256)
DEFINE mv_link_libs       CHAR(256)
DEFINE mv_link_opts       CHAR(256)
DEFINE mv_make_dll        SMALLINT
DEFINE mv_make_globals    SMALLINT
DEFINE mv_makecompile     SMALLINT
DEFINE mv_map             SMALLINT
DEFINE mv_namespace       CHAR(256)
DEFINE mv_newest_obj      CHAR(256)
DEFINE mv_noerrcode       SMALLINT
DEFINE mv_objects         CHAR(20480)
DEFINE mv_output          CHAR(256)
DEFINE mv_output_type     CHAR(20)
DEFINE mv_preprocess      CHAR(256)
DEFINE mv_preprocess_opts CHAR(256)
DEFINE mv_ranlib_cmd      CHAR(256)
DEFINE mv_ranlib_opts     CHAR(256)
DEFINE mv_shared          SMALLINT
DEFINE mv_show_errtail    SMALLINT
DEFINE mv_sqltype         CHAR(255)
DEFINE mv_stacktrace      SMALLINT
DEFINE mv_stage           CHAR(20)
DEFINE mv_static          SMALLINT
DEFINE mv_system4gl       SMALLINT
DEFINE mv_verbose         SMALLINT
DEFINE mv_versioned       INTEGER
DEFINE mv_warnfile        CHAR(256)

#skdebug 120607
#	mv_libs			char(512),
#	mv_aubit4gllib 		char(512)

code

int A4GL_file_length(char *fname);
//int aclfgl_aclfgl_expand_env_vars_in_cmdline(int n);
int A4GL_file_exists(char *fname);
int A4GL_move_file(char *from,char *to);
int isverbose_c(int n) ;
int A4GL_delete_file(char *fname);

endcode




FUNCTION init ()
DEFINE lv_pack            CHAR(256)
DEFINE use_indicators     INTEGER

    LET mv_versioned=1

    IF mv_verbose>=4 THEN
        DISPLAY "Reading packs"
    END IF

    LET lv_pack=mv_lextype

    CALL read_pack(lv_pack)

    LET mv_dump_strings=0
    LET lv_pack=mv_lextype CLIPPED,"_",mv_lexdialect

    CALL read_pack(lv_pack)

    LET lv_pack=fgl_getenv("TARGET_OS")

    CALL read_pack(lv_pack)

    LET lv_pack=fgl_getenv("TARGET_OS"),"__",mv_lextype CLIPPED

    CALL read_pack(lv_pack)

    LET lv_pack=fgl_getenv("TARGET_OS"),"__",mv_lextype CLIPPED,"_",mv_lexdialect

    CALL read_pack(lv_pack)

    LET lv_pack=fgl_getenv("TARGET")

    CALL read_pack(lv_pack)

    LET lv_pack=fgl_getenv("TARGET"),"__",mv_lextype CLIPPED

    CALL read_pack(lv_pack)

    LET lv_pack=fgl_getenv("TARGET"),"__",mv_lextype CLIPPED,"_",
       mv_lexdialect CLIPPED

    CALL read_pack(lv_pack)

    INITIALIZE mv_db,mv_stage,mv_namespace,mv_compile_4gl,mv_compile_4gl_opts,
       mv_compile_c,mv_compile_c_opts,mv_compile_pec,mv_compile_pec_opts,mv_preprocess,
       mv_preprocess_opts,mv_sqltype,mv_show_errtail,mv_link,mv_dll_opts,mv_link_libs,mv_link_opts,
       mv_ar_cmd,mv_ar_opts,mv_ranlib_cmd,mv_ranlib_opts TO NULL
    INITIALIZE mv_newest_obj TO NULL

    LET mv_ansi_mode=0
    LET mv_debug=0
    LET mv_echomode=0
    LET mv_ignerrs=0
    LET mv_keep=-1
    LET mv_makecompile=0
    LET mv_make_dll=0
    LET mv_map=0
    LET mv_noerrcode=0
    LET mv_shared=1
    LET mv_stacktrace=1
    LET mv_system4gl=0
    LET mv_verbose=0
    LET mv_make_globals=0
    LET mv_esql_to_c_first=0
    LET mv_static=0

    IF fgl_getenv("ESQL_TO_C")="Y" THEN
        LET mv_esql_to_c_first=1
    END IF

    LET mv_include="-I\"",fgl_getenv("AUBITDIR"),"/incl\" "

    #IF fgl_getenv("GTK_INC_PATH")!= "" THEN
    #let mv_include=mv_include clipped, " -I\"",fgl_getenv("GTK_INC_PATH"),"\""
    #END IF
    IF isyes(fgl_getenv("VERSIONEDLIB")) THEN
        LET mv_versioned=1
    END IF

    CALL aclfgl_setenv("A4GL_DEBUGFILE","debug.4glc.out")

    LET mv_compile_4gl=fgl_getenv("A4GL_4GLC_COMP")
    LET mv_compile_4gl_opts=fgl_getenv("A4GL_4GLC_OPTS")
    LET mv_compile_c=fgl_getenv("A4GL_C_COMP")
    LET mv_compile_c_opts=fgl_getenv("A4GL_C_OPTS")
    LET mv_compile_c_debug=fgl_getenv("A4GL_C_DEBUG")
    LET mv_compile_pec=fgl_getenv("A4GL_EC_COMP")
    LET mv_compile_pec_opts=fgl_getenv("A4GL_EC_OPTS")
    LET mv_preprocess=fgl_getenv("A4GL_PREC_COMP")
    LET mv_preprocess_opts=fgl_getenv("A4GL_PREC_OPTS")
    LET mv_link=fgl_getenv("A4GL_LINK")
    LET mv_link_opts=fgl_getenv("A4GL_LINK_OPTS")
    LET mv_link_libs=fgl_getenv("A4GL_LINK_LIBS")
    LET mv_dll_opts=fgl_getenv("A4GL_DLL_OPTS")
    LET mv_ar_cmd=fgl_getenv("A4GL_AR_CMD")
    LET mv_ar_opts=fgl_getenv("A4GL_AR_OPTS")
    LET mv_ranlib_cmd=fgl_getenv("A4GL_RANLIB_CMD")
    LET mv_ranlib_opts=fgl_getenv("A4GL_RANLIB_OPTS")
    LET mv_stage="OBJ0?"
    LET mv_import_symbols=fgl_getenv("A4GL_IMPORT_DYNAMIC")
    LET mv_export_symbols=fgl_getenv("A4GL_EXPORT_DYNAMIC")

    IF isyes(fgl_getenv("USE_INDICATOR")) THEN
        LET use_indicators=1
    ELSE
        LET use_indicators=0
    END IF

    IF use_indicators=0 THEN
        LET mv_preprocess_opts=mv_preprocess_opts CLIPPED,
           fgl_getenv("A4GL_NOINDICATORS")
        LET mv_compile_pec_opts=mv_compile_pec_opts CLIPPED,
           fgl_getenv("A4GL_NOINDICATORS")
    END IF

    IF fgl_getenv("A4GL_SHOW_ERRTAIL")="Y" THEN
        LET mv_show_errtail=1
    END IF

    IF fgl_getenv("A4GL_SHOW_ERRTAIL")="N" THEN
        LET mv_show_errtail=0
    END IF

    IF mv_compile_4gl IS NULL OR mv_compile_4gl MATCHES " " THEN
        LET mv_compile_4gl="4glc"
    END IF

    IF mv_link IS NULL OR mv_link MATCHES " " THEN
        LET mv_link="gcc "
    END IF

    IF mv_link_opts IS NULL OR mv_link_opts MATCHES " " THEN
        LET mv_link_opts="-L",fgl_getenv("AUBITDIR") CLIPPED,"/lib"
    END IF

    IF mv_link_libs IS NULL OR mv_link_libs MATCHES " " THEN
        LET mv_link_libs=" "
    END IF

    IF mv_dll_opts IS NULL OR mv_dll_opts MATCHES " " THEN
        LET mv_dll_opts="--shared "
    END IF

    IF mv_ar_cmd IS NULL OR mv_ar_cmd MATCHES " " THEN
        LET mv_ar_cmd="ar "
    END IF

    IF mv_ar_opts IS NULL OR mv_ar_opts MATCHES " " THEN
        LET mv_ar_opts="rc  "
    END IF

    IF mv_ranlib_cmd IS NULL OR mv_ranlib_cmd MATCHES " " THEN
        LET mv_ranlib_cmd="ranlib "
    END IF

    IF mv_ranlib_opts IS NULL OR mv_ranlib_opts MATCHES " " THEN
        LET mv_ranlib_opts=" "
    END IF

    IF mv_compile_c IS NULL OR mv_compile_c MATCHES " " THEN
        LET mv_compile_c="gcc "
    END IF

    IF mv_compile_c_debug IS NULL OR mv_compile_c_debug MATCHES " " THEN
        LET mv_compile_c_debug="-g"
    END IF

    IF mv_link_debug IS NULL OR mv_link_debug MATCHES " " THEN
        LET mv_link_debug="-g"
    END IF

    IF mv_compile_pec IS NULL OR mv_compile_pec MATCHES " " THEN
        LET mv_compile_pec="NO"
    END IF

    IF mv_preprocess IS NULL OR mv_preprocess MATCHES " " THEN
        LET mv_preprocess="NO"
    END IF

    IF mv_compile_c_opts IS NULL THEN
        LET mv_compile_c_opts=" "
    END IF

    IF mv_compile_pec_opts IS NULL THEN
        LET mv_compile_pec_opts=" "
    END IF

    IF mv_lexdialect="INGRES" OR mv_lexdialect="POSTGRES"
        OR fgl_getenv("A4GL_ESQL_TO_C_FIRST")="Y" THEN

        IF mv_verbose>=4 THEN
            DISPLAY "SETTING C_FIRST MODE"
        END IF

        LET mv_esql_to_c_first=1
    END IF

END FUNCTION



MAIN
DEFINE a                  INTEGER
DEFINE lv_arg             CHAR(200)
DEFINE lv_cnt             INTEGER
DEFINE lv_minus_c         INTEGER
DEFINE lv_minus_e         INTEGER
DEFINE lv_num_args        INTEGER
DEFINE lv_output          CHAR(255)
DEFINE lv_type            CHAR(40)

    CALL aclfgl_setenv("A4GL_UI","CONSOLE")

    LET lv_num_args=num_args()

    IF lv_num_args=0 THEN
        CALL usg()
    END IF

    LET mv_lextype=fgl_getenv("A4GL_LEXTYPE")

    IF mv_lextype IS NULL OR mv_lextype MATCHES " " THEN
        LET mv_lextype="C"
    END IF

    IF mv_lextype="WRITE" THEN

        IF fgl_getenv("A4GL_PACKER") MATCHES "XML*" THEN
            LET mv_stage="XML"
        ELSE
            LET mv_stage="MIF"
        END IF

    END IF

    LET mv_lexdialect=fgl_getenv("A4GL_LEXDIALECT")

    INITIALIZE mv_output TO NULL

    FOR a=1 TO lv_num_args
        LET lv_arg=arg_val(a)

        IF lv_arg MATCHES "-o*" AND lv_arg!="-o" THEN
            LET mv_output=lv_arg[3,200]

            IF mv_verbose>2 THEN
                DISPLAY "(1) mv_output=",mv_output CLIPPED
            END IF

            CONTINUE FOR
        END IF

        CASE lv_arg

            WHEN "-?"
                CALL show_help(2)

                CONTINUE FOR

            WHEN "--verbose"
                LET mv_verbose=mv_verbose+1

                CONTINUE FOR

            WHEN "-V"
                LET mv_verbose=mv_verbose+1

                CONTINUE FOR

            WHEN "-V1"
                LET mv_verbose=1

                CONTINUE FOR

            WHEN "-V2"
                LET mv_verbose=2

                CONTINUE FOR

            WHEN "-V3"
                LET mv_verbose=3

                CONTINUE FOR

            WHEN "-V4"
                LET mv_verbose=4

                CONTINUE FOR

            WHEN "-V5"
                LET mv_verbose=5

                CONTINUE FOR

            WHEN "-versioned"
                LET mv_versioned=1

                CONTINUE FOR

            WHEN "-notversioned"
                LET mv_versioned=0

                CONTINUE FOR

            WHEN "-globcurs"
                CALL aclfgl_setenv("A4GL_GLOBALCURS","Y")

                CONTINUE FOR

            WHEN "-t"
                LET a=a+1
                LET mv_lextype=arg_val(a)

                CALL aclfgl_setenv("A4GL_LEXTYPE",mv_lextype CLIPPED)

                CONTINUE FOR

            WHEN "--lextype"
                LET a=a+1
                LET mv_lextype=arg_val(a)

                CALL aclfgl_setenv("A4GL_LEXTYPE",mv_lextype CLIPPED)

                CONTINUE FOR

            WHEN "-td"
                LET a=a+1
                LET mv_lexdialect=arg_val(a)

                CALL aclfgl_setenv("A4GL_LEXDIALECT",mv_lexdialect CLIPPED)

                CONTINUE FOR

            WHEN "--lexdialect"
                LET a=a+1
                LET mv_lexdialect=arg_val(a)

                CALL aclfgl_setenv("A4GL_LEXDIALECT",mv_lexdialect CLIPPED)

                CONTINUE FOR

            WHEN "--neverconvert"
                CALL aclfgl_setenv("A4GL_NEVERCONVERT","Y")

                CONTINUE FOR

            WHEN "--output"
                LET a=a+1
                LET mv_output=arg_val(a)

                CONTINUE FOR

            WHEN "-o"
                LET a=a+1
                LET mv_output=arg_val(a)

                CONTINUE FOR

        END CASE

    END FOR

    IF mv_verbose>3 THEN
        DISPLAY "(2) mv_output=",mv_output CLIPPED
    END IF

    IF mv_lextype="EC" AND (mv_lexdialect IS NULL OR mv_lexdialect MATCHES " ") THEN
        CALL aclfgl_setenv("A4GL_LEXDIALECT","INFORMIX")

        LET mv_lexdialect="INFORMIX"
    END IF

    IF mv_verbose>=3 THEN
        DISPLAY "mv_lextype=",mv_lextype," dialect=",mv_lexdialect
    END IF

    CALL init()


code
if (mv_versioned) {
	sprintf(mv_aubit4gllib,"aubit4gl-%s_%d", A4GL_internal_version (), A4GL_internal_build ());
} else {
	sprintf(mv_aubit4gllib,"aubit4gl");
}

endcode

    #  -l",mv_aubit4gllib clipped
    LET mv_libs="-L",fgl_getenv("AUBITDIR") CLIPPED,"/lib"
    LET lv_minus_c=0
    LET lv_minus_e=0

    # We should really scan first for our output filename...
    LET lv_cnt=0

    FOR a=1 TO lv_num_args
        LET lv_arg=arg_val(a)

        IF lv_arg MATCHES "-o*" THEN
            LET lv_cnt=lv_cnt+1
        END IF

        IF lv_arg="-e" THEN
            LET lv_minus_e=1
        END IF

        IF lv_arg="-c" THEN
            LET lv_minus_c=1
        END IF

    END FOR

    # Darn - more than one...
    IF lv_cnt>1 THEN
        DISPLAY "Error - more than one output specified"

        CALL usg()
    END IF

    # Darn - none at all - guess its an object
    IF lv_cnt=0 AND mv_output_type="UNK" THEN

        IF lv_minus_c THEN
            LET mv_output_type="OBJ"
        ELSE

            IF lv_minus_e THEN
                LET mv_output_type="C"
            ELSE
                LET mv_output_type="OBJ"
            END IF

        END IF

    END IF

    IF lv_cnt=1 THEN

        # OK - find it again..
        FOR a=1 TO lv_num_args
            LET lv_arg=arg_val(a)

            IF lv_arg="-o" THEN
                LET lv_arg=arg_val(a+1)

                EXIT FOR
            END IF

            IF lv_arg MATCHES "-o*" THEN
                LET lv_arg=lv_arg[3,200]

                EXIT FOR
            END IF

        END FOR

        IF fgl_getenv("A4GL_LEXTYPE")="SPL" THEN
            LET mv_output_type="SPL"
        ELSE

            # Guess that its probably an executable..
            LET mv_output_type="EXE"
        END IF

        # Does it look like a static library ?
        LET lv_type=generate_ext("LIB")

        # Its a library
        IF lv_arg MATCHES "*.a" OR lv_arg MATCHES lv_type OR lv_arg MATCHES "*.aox" THEN
            LET mv_output_type="LIB"
        END IF

        LET lv_type=generate_ext("EXE")

        IF lv_arg MATCHES "*.exe" OR lv_arg MATCHES lv_type THEN
            LET mv_output_type="EXE"
        END IF

        IF lv_arg MATCHES "*.xml" OR lv_arg MATCHES "*.xml.gz" THEN
            LET mv_output_type="XML"
        END IF

        # Does it look like a shared library ?
        LET lv_type=generate_ext("DLL")

        # Its a library
        IF lv_arg MATCHES "*.so" OR lv_arg MATCHES lv_type OR mv_make_dll THEN
            LET mv_output_type="DLL"
        END IF

        # Does it look like a object ?
        LET lv_type=generate_ext("OBJ")

        IF lv_arg MATCHES "*.o" OR lv_arg MATCHES "*.ao" OR lv_arg MATCHES "*.4go"
            OR lv_arg MATCHES "*.4pe" OR lv_arg MATCHES lv_type THEN
            LET mv_output_type="OBJ"
        END IF

        # Does it look like an EC module ?
        LET lv_type=generate_ext("EC")

        # Its an esql/c module
        IF lv_arg MATCHES "*.ec" OR lv_arg MATCHES "*.cpc" OR lv_arg MATCHES lv_type
            OR lv_arg MATCHES "*.pgc" THEN
            LET mv_output_type="EC"
        END IF

        # Does it look like a form ?
        LET lv_type=generate_ext("SRCFORM")

        # Its a form
        IF lv_arg MATCHES "*.per" OR lv_arg MATCHES lv_type THEN

            # Shouldn't happen -
            DISPLAY "A form should never be the output."

            CALL usg()
        END IF

        # Does it look like a 4GL module ?
        LET lv_type=generate_ext("4GL")

        # Its a 4GL
        IF lv_arg MATCHES "*.4gl" OR lv_arg MATCHES lv_type THEN

            # Shouldn't happen -
            DISPLAY "A 4gl module should never be the output."

            CALL usg()
        END IF

        # Does it look like a menu ?
        # Its a menu
        IF lv_arg MATCHES "*.menu" THEN
            DISPLAY "A menu module should never be the output."

            CALL usg()
        END IF

        # Does it look like a C file ?
        LET lv_type=generate_ext("C")

        # Its a C file
        IF lv_arg MATCHES "*.c" OR lv_arg MATCHES lv_type THEN
            LET mv_output_type="C"
        END IF

        # Does it look like a message/help file ?
        LET lv_type=generate_ext("MSG")

        # Its a help file
        IF lv_arg MATCHES "*.msg" OR lv_arg MATCHES lv_type OR lv_arg MATCHES "*.hlp"
            THEN
            DISPLAY "A help source module should never be the output."

            CALL usg()
        END IF

        # Does it look like a compiled message/help file ?
        LET lv_type=generate_ext("IEM")

        IF lv_arg MATCHES "*.iem" OR lv_arg MATCHES lv_type THEN
            LET mv_output_type="MSG"
        END IF

    END IF

    IF mv_verbose>3 THEN
        DISPLAY "(3) mv_output=",mv_output CLIPPED
        DISPLAY "mv_output_type=",mv_output_type CLIPPED
    END IF

    LET mv_stage=mv_output_type

    FOR a=1 TO lv_num_args
        LET lv_arg=arg_val(a)

        IF lv_arg!="-o" AND lv_arg MATCHES "-o*" THEN
            LET mv_output=lv_arg[3,200]

            IF mv_verbose>3 THEN
                DISPLAY "mv_output=",mv_output
            END IF

            CONTINUE FOR
        END IF

        CASE lv_arg

            WHEN "-?"
                CALL show_help(2)

                CONTINUE FOR

            WHEN "-help"
                CALL show_help(2)

                CONTINUE FOR

            WHEN "--help"
                CALL show_help(2)

                CONTINUE FOR

            WHEN "--help-short"
                CALL show_help(2)

                CONTINUE FOR

            WHEN "--help-options"
                CALL show_help(3)

                CONTINUE FOR

            WHEN "--help-env"
                CALL show_help(5)

                CONTINUE FOR

            WHEN "--help-types"
                CALL show_help(6)

                CONTINUE FOR

            WHEN "--help-examples"
                CALL show_help(7)

                CONTINUE FOR

            WHEN "--globals"
                LET mv_make_globals=1

                CONTINUE FOR

            WHEN "-G"
                LET mv_make_globals=1

                CONTINUE FOR

            WHEN "-N"
                LET a=a+1
                LET mv_namespace=arg_val(a)

                IF mv_namespace IS NULL THEN
                    LET mv_namespace=" "
                END IF

                CONTINUE FOR

            WHEN "--namespace"
                LET a=a+1
                LET mv_namespace=arg_val(a)

                CONTINUE FOR

            WHEN "-namespace"
                LET a=a+1
                LET mv_namespace=arg_val(a)

                CONTINUE FOR

            WHEN "-noprefix"
                LET mv_namespace=" "

                CONTINUE FOR

            WHEN "--noprefix"
                LET mv_namespace=" "

                CONTINUE FOR

            WHEN "-n"
                LET mv_namespace=" "

                CONTINUE FOR

            WHEN "--stack_trace"
                LET a=a+1
                LET mv_stacktrace=arg_val(a)

                CONTINUE FOR

            WHEN "-s"
                LET mv_stacktrace=1

                CONTINUE FOR

            WHEN "-s0"
                LET mv_stacktrace=0

                CONTINUE FOR

            WHEN "-s1"
                LET mv_stacktrace=1

                CONTINUE FOR

            WHEN "--islibrarymodule"
                CALL aclfgl_setenv("A4GL_COMPILING_LIBRARY","Y")

                CONTINUE FOR

            WHEN "--dump-strings"
                LET mv_dump_strings=1

                CALL aclfgl_setenv("A4GL_DUMPSTRINGS","Y")

                CONTINUE FOR

            WHEN "--dump-strings-ident"
                LET mv_dump_strings=2

                CALL aclfgl_setenv("A4GL_DUMPSTRINGS","ident")

                CONTINUE FOR

            WHEN "--ident-start"
                LET a=a+1

                CALL aclfgl_setenv("A4GL_DUMPSTRINGS_START",arg_val(a))

                CONTINUE FOR

            WHEN "--translation-file"
                LET a=a+1

                CALL aclfgl_setenv("A4GL_TRANSLATEFILE",arg_val(a))

                CONTINUE FOR

            WHEN "--output"
                LET a=a+1
                LET mv_output=arg_val(a)

                CONTINUE FOR

            WHEN "-o"
                LET a=a+1
                LET mv_output=arg_val(a)

                CONTINUE FOR

            WHEN "-c"

                IF mv_output_type!="OBJ" THEN
                    DISPLAY "Invalid combination -c, generating a ",mv_output_type

                    EXIT PROGRAM 2
                END IF

                LET mv_stage="OBJ"

                CONTINUE FOR

            WHEN "-e"

                IF mv_output_type!="C" THEN
                    DISPLAY "Invalid combination -e, generating a ",mv_output_type

                    EXIT PROGRAM 2
                END IF

                LET mv_stage="C"

                CONTINUE FOR

            WHEN "--compile-4gl-only"
                LET mv_stage="EC"

                CONTINUE FOR

            WHEN "--compile-only"
                LET mv_stage="OBJ"

                CONTINUE FOR

            WHEN "--preprocess-only"
                LET mv_stage="C"

                CONTINUE FOR

            WHEN "-t"
                LET a=a+1
                LET mv_lextype=arg_val(a)

                IF mv_lextype="WRITE" THEN

                    IF fgl_getenv("A4GL_PACKER") MATCHES "XML*" THEN
                        LET mv_stage="XML"
                    ELSE
                        LET mv_stage="MIF"
                    END IF

                END IF

                IF mv_lextype="FGL" THEN
			LET mv_stage="FGL"
		END IF

                CONTINUE FOR

            WHEN "--lextype"
                LET a=a+1
                LET mv_lextype=arg_val(a)

                IF mv_lextype="WRITE" THEN

                    IF fgl_getenv("A4GL_PACKER") MATCHES "XML*" THEN
                        LET mv_stage="XML"
                    ELSE
                        LET mv_stage="MIF"
                    END IF

                END IF

                CONTINUE FOR

            WHEN "-td"
                LET a=a+1
                LET mv_lexdialect=arg_val(a)

                CONTINUE FOR

            WHEN "--lexdialect"
                LET a=a+1
                LET mv_lexdialect=arg_val(a)

                CONTINUE FOR

            WHEN "-k"
                LET mv_keep=1

                CONTINUE FOR

            WHEN "--keep"
                LET mv_keep=1

                CONTINUE FOR

            WHEN "-K"
                LET mv_keep=0

                CONTINUE FOR

            WHEN "--clean"
                LET mv_keep=0

                CONTINUE FOR

            WHEN "-nokeep"
                LET mv_keep=0

                CONTINUE FOR

            WHEN "-d"
                LET a=a+1
                LET mv_db=arg_val(a)

                CONTINUE FOR

            WHEN "--database"
                LET a=a+1
                LET mv_db=arg_val(a)

                CONTINUE FOR

            WHEN "--neverconvert"
                CONTINUE FOR

            WHEN "-C"
                LET a=a+1
                LET mv_sqltype=arg_val(a)

                CALL aclfgl_setenv("A4GL_SQLTYPE",mv_sqltype CLIPPED)

                CONTINUE FOR

            WHEN "--sqltype"
                LET a=a+1
                LET mv_sqltype=arg_val(a)

                CALL aclfgl_setenv("A4GL_SQLTYPE",mv_sqltype CLIPPED)

                CONTINUE FOR

            WHEN "--verbose"
                LET mv_verbose=mv_verbose+1

                CONTINUE FOR

            WHEN "-V"
                LET mv_verbose=mv_verbose+1

                CONTINUE FOR

            WHEN "-V1"
                LET mv_verbose=1

                CONTINUE FOR

            WHEN "-V2"
                LET mv_verbose=2

                CONTINUE FOR

            WHEN "-V3"
                LET mv_verbose=3

                CONTINUE FOR

            WHEN "-V4"
                LET mv_verbose=4

                CONTINUE FOR

            WHEN "-V5"
                LET mv_verbose=5

                CONTINUE FOR

            WHEN "-versioned"
                LET mv_versioned=1

                CONTINUE FOR

            WHEN "-notversioned"
                LET mv_versioned=0

                CONTINUE FOR

            WHEN "-S"
                LET mv_verbose=0

                CONTINUE FOR

            WHEN "--silent"
                LET mv_verbose=0

                CONTINUE FOR

            WHEN "-q"
                LET mv_verbose=0

                CONTINUE FOR

            WHEN "--shared"
                DISPLAY "--shared is depreciated - use '--use-shared' instead"

                LET mv_shared=1

                CONTINUE FOR

            WHEN "--static"
                DISPLAY "--static is depreciated - use '--use-static' instead"

                LET mv_shared=0

                CONTINUE FOR

            WHEN "--use-shared"
                LET mv_shared=1

                CONTINUE FOR

            WHEN "--use-static"
                LET mv_shared=0

                CONTINUE FOR

            WHEN "--system4gl"
                LET mv_system4gl=1

                CONTINUE FOR

            WHEN "-4"
                LET mv_system4gl=1

                CONTINUE FOR

            WHEN "--echo"
                LET mv_echomode=1

                CONTINUE FOR

            WHEN "-E"
                LET mv_echomode=1

                CONTINUE FOR

            WHEN "--compile-c"
                LET a=a+1
                LET mv_compile_c=arg_val(a)

                CONTINUE FOR

            WHEN "--compile-ec"
                LET a=a+1
                LET mv_compile_pec=arg_val(a)

                CONTINUE FOR

            WHEN "--preprocess-ec"
                LET a=a+1
                LET mv_preprocess=arg_val(a)

                CONTINUE FOR

            WHEN "--link"
                LET a=a+1
                LET mv_link=arg_val(a)

                CONTINUE FOR

            WHEN "-v"
                CALL show_version(0)

                CONTINUE FOR

            WHEN "--version"
                CALL show_version(0)

                CONTINUE FOR

            WHEN "--version-4glpc"
                CALL show_version(2)

                CONTINUE FOR

            WHEN "-f"
                CALL show_version(1)

                CONTINUE FOR

            WHEN "--version-full"
                CALL show_version(1)

                CONTINUE FOR

            WHEN "--version_full"
                CALL show_version(1)

                CONTINUE FOR

            WHEN "--preview-errors"
                LET mv_show_errtail=1

                CONTINUE FOR

            WHEN "--ignore-errors"
                LET mv_ignerrs=1

                CONTINUE FOR

            WHEN "--noerrcode"
                LET mv_noerrcode=1

                CONTINUE FOR

            WHEN "--map"
                LET mv_map=1

                CONTINUE FOR

            WHEN "--nomap"
                LET mv_map=0

                CONTINUE FOR

            WHEN "--make-compile"
                LET mv_makecompile=1

                CONTINUE FOR

            WHEN "-g"
                LET mv_debug=1

                CONTINUE FOR

            WHEN "--debug"
                LET mv_debug=1

                CONTINUE FOR

            WHEN "-static"
                LET mv_static=1

                CONTINUE FOR

            WHEN "--as-dll"
                LET mv_make_dll=1
                LET mv_stage="DLL"

                IF mv_output="" OR mv_output IS NULL THEN
                    LET mv_output="a.out",get_ext("DLL")
                END IF

                LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," -fPIC"

                CONTINUE FOR

            WHEN "-as-dll"
                LET mv_make_dll=1
                LET mv_stage="DLL"

                IF mv_output="" OR mv_output IS NULL THEN
                    LET mv_output="a.out",get_ext("DLL")
                END IF

                LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," -fPIC"

                CONTINUE FOR

            WHEN "-X4glc"
                LET a=a+1
                LET mv_compile_4gl_opts=mv_compile_4gl_opts CLIPPED," ",arg_val(a)

                CONTINUE FOR

            WHEN "-Xlinker"
                LET a=a+1
                LET mv_link_opts=mv_link_opts CLIPPED," ",arg_val(a)

                CONTINUE FOR

            WHEN "-Xcompiler"
                LET a=a+1
                LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," ",arg_val(a)

                CONTINUE FOR

            WHEN "-Xcompiler-ec"
                LET a=a+1
                LET mv_compile_pec_opts=mv_compile_pec_opts CLIPPED," ",arg_val(a)

                CONTINUE FOR

            WHEN "-Xpreprocess-ec"
                LET a=a+1
                LET mv_preprocess_opts=mv_preprocess_opts CLIPPED," ",arg_val(a)

                CONTINUE FOR

            WHEN "--ansi-warn"
                CALL aclfgl_setenv("A4GL_ANSI_WARN","Y")

            WHEN "--ansi-error"
                CALL aclfgl_setenv("A4GL_ANSI_ERROR","Y")

            WHEN "--no-ansi-warn"
                CALL aclfgl_setenv("A4GL_ANSI_WARN","N")

            WHEN "--no-ansi-error"
                CALL aclfgl_setenv("A4GL_ANSI_ERROR","N")

        END CASE

        IF lv_arg MATCHES "--sqltype=*" THEN
            LET mv_sqltype=lv_arg

            # Skip the "--sqltype=*"
            LET mv_sqltype=mv_sqltype[11,255]

            #display "A4GL_SQLTYPE=",mv_sqltype clipped
            CALL aclfgl_setenv("A4GL_SQLTYPE",mv_sqltype CLIPPED)

            CONTINUE FOR
        END IF

        # If we get to here its either a compile option thats not recognised or
        # its a filename...
        IF lv_arg MATCHES "-Wl,*" THEN
            LET mv_link_opts=mv_link_opts CLIPPED," ",lv_arg

            CONTINUE FOR
        END IF

        IF lv_arg MATCHES "-Wall" THEN
            LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," ",lv_arg
            LET mv_compile_pec_opts=mv_compile_pec_opts CLIPPED," ",lv_arg

            CONTINUE FOR
        END IF

        IF lv_arg MATCHES "-I*" THEN

            IF lv_arg="-I" THEN
                LET a=a+1
                LET lv_arg="-I",arg_val(a)
            END IF

            LET mv_include=mv_include CLIPPED," ",lv_arg

            IF mv_verbose>=5 THEN
                DISPLAY "Setting mv_include because of a -I ",mv_include CLIPPED
            END IF

            CONTINUE FOR
        END IF

        IF lv_arg="-fPIC" THEN
            LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," -fPIC"

            CONTINUE FOR
        END IF

        IF lv_arg MATCHES "-D*" THEN

            IF lv_arg="-D" THEN
                LET a=a+1
                LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," -D ",arg_val(a)
            ELSE
                LET mv_compile_c_opts=mv_compile_c_opts CLIPPED," ",lv_arg
            END IF

            CONTINUE FOR
        END IF

        IF lv_arg MATCHES "-l*" THEN

            IF lv_arg="-l" THEN
                LET a=a+1
                LET lv_arg="-l",arg_val(a)
            END IF

            LET mv_libs=mv_libs CLIPPED," ",lv_arg

            CONTINUE FOR
        END IF

        IF lv_arg MATCHES "-L*" THEN

            IF lv_arg="-L" THEN
                LET a=a+1
                LET lv_arg="-L",arg_val(a)
            END IF

            LET mv_libs=mv_libs CLIPPED," ",lv_arg

            CONTINUE FOR
        END IF

        #display "lv_arg=",lv_arg clipped
        LET lv_type=generate_ext("LIB")

        # Its a library
        IF lv_arg MATCHES "*.a" OR lv_arg MATCHES lv_type OR lv_arg MATCHES "*.aox" THEN
            LET mv_libs=mv_libs CLIPPED," ",lv_arg

            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("DLL")

        # Its a library
        IF lv_arg MATCHES "*.so" OR lv_arg MATCHES lv_type THEN
            LET mv_libs=mv_libs CLIPPED," ",lv_arg

            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("OBJ")

        IF lv_arg MATCHES "*.o" OR lv_arg MATCHES "*.4go" OR lv_arg MATCHES "*.4pe"
            OR lv_arg MATCHES "*.ao" OR lv_arg MATCHES lv_type THEN
            CALL add_obj(lv_arg)

            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("EC")

        # Its an esql/c module
        IF lv_arg MATCHES "*.ec" OR lv_arg MATCHES "*.cpc" OR lv_arg MATCHES lv_type
            OR lv_arg MATCHES "*.pgc" THEN
            CALL make_into(lv_arg,"EC",mv_stage)

            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("SRCFORM")

        # Its a form
        IF lv_arg MATCHES "*.per" OR lv_arg MATCHES lv_type THEN
            CALL make_into(lv_arg,"PER","FRM")

            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("4GL")

        # Its a 4GL
        IF lv_arg MATCHES "*.4gl" OR lv_arg MATCHES lv_type THEN
            CALL make_into(lv_arg,"4GL",mv_stage)

            CONTINUE FOR
        END IF

        # Its a menu
        IF lv_arg MATCHES "*.menu" THEN
            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("C")

        # Its a C file
        IF lv_arg MATCHES "*.c" OR lv_arg MATCHES lv_type THEN
            CALL make_into(lv_arg,"C",mv_stage)

            CONTINUE FOR
        END IF

        LET lv_type=generate_ext("MSG")

        # Its a help file
        IF lv_arg MATCHES "*.msg" OR lv_arg MATCHES lv_type OR lv_arg MATCHES "*.hlp"
            THEN
            CALL make_into(lv_arg,"MSG","IEM")

            CONTINUE FOR
        END IF

        DISPLAY "WARNING : ",lv_arg CLIPPED,
           " not recognised - passing to C-compiler/Linker"
    END FOR

    #call usg()
    IF mv_lextype="WRITE" THEN

        IF fgl_getenv("A4GL_PACKER") MATCHES "XML*" THEN
            LET mv_stage="XML"
        ELSE
            LET mv_stage="MIF"
        END IF

    END IF

    IF mv_verbose>=3 THEN
        DISPLAY ""
        DISPLAY "Generate a ",mv_stage
    END IF

    IF mv_stage="EXE" OR mv_stage="DLL" OR mv_stage="LIB" THEN

        IF mv_stage MATCHES "DLL" THEN
            LET mv_make_dll=1

            IF mv_output MATCHES "*.*" THEN
                CALL run_link(mv_output)
            ELSE
                LET lv_output=get_fname(mv_output,"DLL")

                CALL run_link(lv_output)
            END IF

        END IF

        IF mv_stage="EXE" THEN
            CALL run_link(mv_output)
        END IF

        IF mv_stage="LIB" THEN
            CALL run_link_lib(mv_output)
        END IF

    END IF

END MAIN



FUNCTION make_into (lv_fname,lv_from,lv_to)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_from            CHAR(5)
DEFINE lv_to              CHAR(5)

# Normal Variables
DEFINE lv_base            CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_new2            CHAR(512)

    LET lv_base=lv_fname

    IF mv_verbose>=4 THEN
        DISPLAY "Make into ",lv_fname CLIPPED," from=",lv_from CLIPPED," to=",
           lv_to CLIPPED
    END IF


code
{
char *ptr;
ptr=strrchr(lv_base,'.');
if (ptr) {
	*ptr=0;
}
}

endcode

    # Just make sure its nicely formatted...
    LET lv_base=lv_base
    LET lv_new=lv_base

    IF mv_lextype IS NULL THEN
        DISPLAY "LEXTYPE IS NULL!"

        EXIT PROGRAM 1
    END IF

    IF lv_from="4GL" THEN

        IF lv_to="EXE" OR lv_to="DLL" THEN
            CALL make_into(lv_fname,"4GL","OBJ")

            RETURN
        END IF

        IF lv_to="C" AND mv_lextype="EC" THEN

            # We want a preprocessed EC not a -> C
            CALL make_into(lv_fname,"4GL","EC")

            LET lv_new=get_fname(lv_base,"EC")

            CALL run_4glc(lv_fname,lv_new,lv_base)
            CALL make_into(lv_new,"EC","PEC")

            RETURN
        END IF

        IF lv_to IS NULL OR lv_to=" " THEN

            IF mv_compile_c="no" AND mv_compile_pec="no" THEN
                LET lv_to=fgl_getenv("A4GL_LEXTYPE")
            ELSE
                LET lv_to="OBJ"
            END IF

        END IF

        CASE lv_to

            WHEN "C"
                LET lv_new=get_fname(lv_base,"C")

                CALL run_4glc(lv_fname,lv_new,lv_base)

                RETURN

            WHEN "EC"
                LET lv_new=get_fname(lv_base,"EC")

                CALL run_4glc(lv_fname,lv_new,lv_base)

                RETURN

            WHEN "OBJ"

                IF mv_lextype="EC" THEN
                    CALL make_into(lv_fname,"4GL","EC")

                    LET lv_new=get_fname(lv_base,"EC")
                    LET lv_new2=get_fname(lv_base,"OBJ")

                    CALL make_into(lv_new,"EC","OBJ")

                    IF mv_keep=0 THEN
                        CALL remove_file_of_type(lv_base,"EC")
                        CALL remove_file_of_type(lv_base,"C")
                    END IF

                ELSE
                    CALL make_into(lv_fname,"4GL","C")

                    LET lv_new=get_fname(lv_base,"C")
                    LET lv_new2=get_fname(lv_base,"OBJ")

                    CALL make_into(lv_new,"C","OBJ")

                    IF mv_keep=0 THEN
                        CALL remove_file_of_type(lv_base,"C")
                    END IF

                END IF

            WHEN "MIF"

                # 4GL -> Data file
                CALL run_4glc_mif(lv_fname,lv_new,lv_base)

            WHEN "XML"

                # 4GL -> XML Data file
                CALL run_4glc_xmlmif(lv_fname,lv_new,lv_base)

            WHEN "SPL"

                # 4GL -> Stored procedure SQL file
                CALL run_4glc(lv_fname,lv_new,lv_base)

	    WHEN "FGL"

		CALL run_4glc(lv_fname,lv_new,lv_base)


            OTHERWISE
                DISPLAY "Unhandled compilation : FROM=",lv_from," TO=",lv_to," for ",lv_fname

                IF mv_noerrcode=0 THEN
                    EXIT PROGRAM 2
                ELSE
                    EXIT PROGRAM
                END IF

        END CASE

        RETURN
    END IF

    IF lv_from="C" AND lv_to="OBJ" THEN
        LET lv_new=get_fname(lv_base,"OBJ")

        CALL run_compile(lv_fname,lv_new,lv_base)

        RETURN
    END IF

    IF lv_from="EC" AND lv_to="PEC" THEN
        LET lv_new=get_fname(lv_base,"C")

        CALL run_esql_prec(lv_fname,lv_new,lv_base)

        RETURN
    END IF

    IF lv_from="EC" AND lv_to="OBJ" THEN

        IF mv_esql_to_c_first THEN

            IF mv_verbose>=4 THEN
                DISPLAY "C FIRST"
            END IF

            LET lv_new=get_fname(lv_base,"C")

            CALL make_into(lv_fname,"EC","PEC")

            LET lv_new=get_fname(lv_base,"C")

            CALL make_into(lv_new,"C","OBJ")
        ELSE

            IF mv_verbose>=4 THEN
                DISPLAY "STRAIGHT TO OBJ - NO C FIRST"
            END IF

            LET lv_new=get_fname(lv_base,"OBJ")

            CALL run_compile_esql(lv_fname,lv_new,lv_base)
        END IF

        RETURN
    END IF

    IF (lv_to="EXE" OR lv_to="DLL") AND lv_from IN ("EC","C") THEN

        # We need to get these to object code instead of EXE
        CALL make_into(lv_fname,lv_from,"OBJ")

        RETURN
    END IF

    IF lv_from="PER" AND lv_to="FRM" THEN
        CALL run_compile_form(lv_fname)

        RETURN
    END IF

    DISPLAY "Unhandled Compile ",lv_fname CLIPPED," From ",lv_from," to ",lv_to

    IF mv_noerrcode=0 THEN
        EXIT PROGRAM 2
    ELSE
        EXIT PROGRAM
    END IF

END FUNCTION



################################################################################
FUNCTION usg ()

    CALL show_help(1)

END FUNCTION



################################################################################
FUNCTION show_help (lv_n)
# Parameters
DEFINE lv_n               INTEGER

# Normal Variables
DEFINE filename           CHAR(128)
DEFINE lv_char            INTEGER
DEFINE lv_msgline         CHAR(256)

    LET filename=fgl_getenv("AUBITDIR"),"/etc/4glpc.hlp"

    CALL aclfgl_openiem(filename,lv_n)
     RETURNING lv_char,lv_msgline

    IF lv_char THEN

code
A4GL_trim(lv_msgline);
printf("%s\n",lv_msgline);

endcode


        WHILE lv_char!=0

            CALL aclfgl_fetchiem()
             RETURNING lv_char,lv_msgline

            IF lv_char!=0 THEN

code
A4GL_trim(lv_msgline);
printf("%s\n",lv_msgline);

endcode

            END IF

        END WHILE

    ELSE
        DISPLAY "ERROR: failed to open ",filename CLIPPED

        EXIT PROGRAM 2
    END IF

    IF lv_n!=1 THEN
        EXIT PROGRAM
    ELSE

        IF mv_noerrcode=0 THEN
            EXIT PROGRAM 2
        ELSE
            EXIT PROGRAM
        END IF

    END IF

END FUNCTION



################################################################################
FUNCTION show_version (lv_type)
# Parameters
DEFINE lv_type            INTEGER

    IF lv_type=2 THEN
        DISPLAY "4glpc v0.8 (c) 2005-2006 Aubit Computing Ltd"

        EXIT PROGRAM
    END IF

    IF lv_type=0 THEN
        CALL runit("4glc --version")
    ELSE
        CALL runit("4glc --version_full")
    END IF

    EXIT PROGRAM

END FUNCTION



################################################################################
FUNCTION runit (lv_str)
# Parameters
DEFINE lv_str             CHAR(32000)

    RUN lv_str CLIPPED

END FUNCTION



################################################################################
FUNCTION generate_ext (lv_otype)
# Parameters
DEFINE lv_otype           CHAR(200)

# Normal Variables
DEFINE lv_type            CHAR(200)

    LET lv_type=lv_otype
    LET lv_type="A4GL_",lv_type CLIPPED,"_EXT"
    LET lv_type=fgl_getenv(lv_type)

    IF lv_type IS NULL OR lv_type MATCHES " " THEN
        LET lv_type="*.",lv_otype
    ELSE
        LET lv_type="*",lv_type
    END IF

    IF mv_verbose>=4 THEN
        DISPLAY "Generating extention for ",lv_otype CLIPPED," gives ",lv_type CLIPPED
    END IF

    RETURN lv_type

END FUNCTION



FUNCTION get_ext (lv_otype)
# Parameters
DEFINE lv_otype           CHAR(200)

# Normal Variables
DEFINE lv_type            CHAR(200)

    LET lv_type=lv_otype
    LET lv_type="A4GL_",lv_type CLIPPED,"_EXT"
    LET lv_type=fgl_getenv(lv_type)

    IF lv_type IS NULL OR lv_type MATCHES " " THEN
        LET lv_type=".",DOWNSHIFT(lv_otype)
    ELSE
        LET lv_type=lv_type
    END IF

    RETURN lv_type

END FUNCTION



################################################################################
FUNCTION run_4glc (lv_fname,lv_new,lv_base)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_base            CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times for ",lv_fname CLIPPED," and ",
               lv_new CLIPPED
        END IF

        IF compare_file_times(lv_fname,lv_new) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_new CLIPPED,
                   " is newer than ",lv_fname CLIPPED
            END IF

            RETURN
        END IF

    END IF

    #
    # Lets force the output filename to be what we're expecting it to
    # be - this gets around any issues with 'A4GL_LOCALOUTPUT' when
    # in a different directory
    #
    IF mv_verbose>=2 THEN
        DISPLAY "Compiling ",lv_fname CLIPPED
        DISPLAY "Hopefully generating : ",lv_base
    END IF

    LET lv_runstr=mv_compile_4gl CLIPPED," ",mv_compile_4gl_opts CLIPPED

    IF mv_stacktrace IS NOT NULL THEN
        LET lv_runstr=lv_runstr CLIPPED," -s",mv_stacktrace
    END IF

    IF mv_make_globals THEN
        LET lv_runstr=lv_runstr CLIPPED," -G"
    END IF

    IF mv_verbose>1 THEN
        LET lv_runstr=lv_runstr CLIPPED," -V"
    END IF

    IF mv_db IS NOT NULL AND mv_db NOT MATCHES " " THEN
        LET lv_runstr=lv_runstr CLIPPED," -d ",mv_db
    END IF

    IF mv_namespace IS NOT NULL THEN
        LET lv_runstr=lv_runstr CLIPPED," -N '",mv_namespace CLIPPED,"'"
    END IF

    IF mv_lextype IS NOT NULL THEN
        CALL aclfgl_setenv("A4GL_LEXTYPE",mv_lextype CLIPPED)
    END IF

    IF mv_keep!=-1 THEN

        IF mv_keep=1 THEN
            LET lv_runstr=lv_runstr CLIPPED," -k"
        ELSE
            LET lv_runstr=lv_runstr CLIPPED," -K"
        END IF

    END IF

    IF mv_system4gl THEN
        LET lv_runstr=lv_runstr CLIPPED," --system4gl"
    END IF

    LET mv_errfile=lv_base CLIPPED,get_ext("ERR")
    LET mv_warnfile=lv_base CLIPPED,get_ext("WARN")
    LET lv_runstr=lv_runstr CLIPPED," ",lv_fname CLIPPED

    #," 2> ",mv_errfile
    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)

END FUNCTION



FUNCTION run_4glc_xmlmif (lv_fname,lv_new,lv_base)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_base            CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times for ",lv_fname CLIPPED," and ",
               lv_new CLIPPED
        END IF

        IF compare_file_times(lv_fname,lv_new) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_new CLIPPED,
                   " is newer than ",lv_fname CLIPPED
            END IF

            RETURN
        END IF

    END IF

    #
    # Lets force the output filename to be what we're expecting it to
    # be - this gets around any issues with 'A4GL_LOCALOUTPUT' when
    # in a different directory
    #
    IF mv_verbose>=2 THEN
        DISPLAY "Compiling ",lv_fname CLIPPED
        DISPLAY "Hopefully generating : ",lv_base
    END IF

    IF mv_output!=" " THEN
        LET lv_runstr="OVERRIDE_PACKER_OUTPUT=",mv_output
    END IF

    IF fgl_getenv("TARGET_OS")="mingw" THEN

        IF fgl_getenv("A4GL_PACKER") MATCHES "*XML*" THEN
            LET lv_runstr=lv_runstr CLIPPED,"set A4GL_LEXTYPE=WRITE&& ",
               mv_compile_4gl CLIPPED," ",mv_compile_4gl_opts CLIPPED
        ELSE
            LET lv_runstr=lv_runstr CLIPPED,
               "set A4GL_LEXTYPE=WRITE&& set A4GL_PACKER=XML&& ",mv_compile_4gl CLIPPED," ",mv_compile_4gl_opts CLIPPED
        END IF

    ELSE

        IF fgl_getenv("A4GL_PACKER") MATCHES "*XML*" THEN
            LET lv_runstr=lv_runstr CLIPPED," A4GL_LEXTYPE=WRITE ",mv_compile_4gl CLIPPED,
               " ",mv_compile_4gl_opts CLIPPED
        ELSE
            LET lv_runstr=lv_runstr CLIPPED," A4GL_LEXTYPE=WRITE A4GL_PACKER=XML ",
               mv_compile_4gl CLIPPED," ",mv_compile_4gl_opts CLIPPED
        END IF

    END IF

    #if mv_stacktrace is not null then
    #let lv_runstr=lv_runstr clipped," -s",mv_stacktrace
    #end if
    #if mv_make_globals then
    #let lv_runstr=lv_runstr clipped," -G"
    #end if
    IF mv_verbose>1 THEN
        LET lv_runstr=lv_runstr CLIPPED," -V"
    END IF

    IF mv_db IS NOT NULL AND mv_db NOT MATCHES " " THEN
        LET lv_runstr=lv_runstr CLIPPED," -d ",mv_db
    END IF

    IF mv_namespace IS NOT NULL THEN
        LET lv_runstr=lv_runstr CLIPPED," -N '",mv_namespace CLIPPED,"'"
    END IF

    IF mv_lextype IS NOT NULL THEN
        CALL aclfgl_setenv("A4GL_LEXTYPE",mv_lextype CLIPPED)
    END IF

    LET lv_runstr=lv_runstr CLIPPED," ",lv_fname CLIPPED

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)

    IF mv_verbose>3 THEN
        DISPLAY "Ran command"
    END IF

END FUNCTION



FUNCTION run_4glc_mif (lv_fname,lv_new,lv_base)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_base            CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times for ",lv_fname CLIPPED," and ",
               lv_new CLIPPED
        END IF

        IF compare_file_times(lv_fname,lv_new) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_new CLIPPED,
                   " is newer than ",lv_fname CLIPPED
            END IF

            RETURN
        END IF

    END IF

    #
    # Lets force the output filename to be what we're expecting it to
    # be - this gets around any issues with 'A4GL_LOCALOUTPUT' when
    # in a different directory
    #
    IF mv_verbose>=2 THEN
        DISPLAY "Compiling ",lv_fname CLIPPED
        DISPLAY "Hopefully generating : ",lv_base
    END IF

    IF fgl_getenv("TARGET_OS")="mingw" THEN

        IF mv_output!=" " THEN
            LET lv_runstr="set OVERRIDE_PACKER_OUTPUT=",mv_output CLIPPED,"&&"
        END IF

        LET lv_runstr=lv_runstr CLIPPED," set A4GL_PACKER=PACKED&& ",
           mv_compile_4gl CLIPPED," ",mv_compile_4gl_opts CLIPPED
    ELSE

        IF mv_output!=" " THEN
            LET lv_runstr="OVERRIDE_PACKER_OUTPUT=",mv_output
        END IF

        LET lv_runstr=lv_runstr CLIPPED," A4GL_PACKER=PACKED ",mv_compile_4gl CLIPPED,
           " ",mv_compile_4gl_opts CLIPPED
    END IF

    IF mv_stacktrace IS NOT NULL THEN
        LET lv_runstr=lv_runstr CLIPPED," -s",mv_stacktrace
    END IF

    IF mv_make_globals THEN
        LET lv_runstr=lv_runstr CLIPPED," -G"
    END IF

    IF mv_verbose>1 THEN
        LET lv_runstr=lv_runstr CLIPPED," -V"
    END IF

    IF mv_db IS NOT NULL AND mv_db NOT MATCHES " " THEN
        LET lv_runstr=lv_runstr CLIPPED," -d ",mv_db
    END IF

    IF mv_namespace IS NOT NULL THEN
        LET lv_runstr=lv_runstr CLIPPED," -N '",mv_namespace CLIPPED,"'"
    END IF

    IF mv_lextype IS NOT NULL THEN
        CALL aclfgl_setenv("A4GL_LEXTYPE",mv_lextype CLIPPED)
    END IF

    LET lv_runstr=lv_runstr CLIPPED," ",lv_fname CLIPPED

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)

END FUNCTION



################################################################################
FUNCTION check_exit_status (p_status,p_filename,p_runstr)
# Parameters
DEFINE p_status           INTEGER
DEFINE p_filename         CHAR(512)
DEFINE p_runstr           CHAR(10240)

# Normal Variables
DEFINE lv_errsize         INTEGER
DEFINE lv_runstr          CHAR(32000)

    #call remove_file(mv_warnfile)
    IF p_status<0 THEN
        LET p_status=1
    END IF

    IF p_status>255 THEN
        LET p_status=p_status/256
    END IF

    IF mv_verbose>4 THEN
        DISPLAY "Status : ",p_status
    END IF

    IF file_exists(mv_errfile) THEN
        LET lv_errsize=file_size(mv_errfile)
    ELSE
        LET lv_errsize=0
    END IF

    IF lv_errsize<0 AND p_status=0 THEN

        IF mv_verbose>4 THEN
            DISPLAY "Error - unable to find the size of the error file (",mv_errfile CLIPPED
               ,")"
        END IF

        RETURN
    END IF

    IF lv_errsize>0 THEN

        IF p_status=0 THEN
            DISPLAY "Warning : Error file is not empty - but I got no error"

            IF mv_verbose>4 THEN
                CALL head_file(mv_errfile,55)
            END IF

            #display "mv_errfile=",mv_errfile
            #display "mv_warnfile=",mv_warnfile
            IF NOT(rename_file(mv_errfile,mv_warnfile)) THEN
                DISPLAY "Error : unable to copy ",mv_errfile CLIPPED," to ",mv_warnfile

                # fake an exit status so the .err is not removed
                LET p_status=1
            ELSE
                DISPLAY "Check ",mv_warnfile CLIPPED," for details"
            END IF

        END IF

    END IF

    IF p_status=0 THEN
        CALL remove_file(mv_errfile)

        RETURN
    END IF

    DISPLAY "Error compiling ",p_filename CLIPPED

    IF mv_verbose>=1 THEN
        DISPLAY "while executing ",p_runstr CLIPPED
    END IF

    IF mv_show_errtail THEN
        CALL tail_file(mv_errfile,12)
    END IF

    IF mv_noerrcode=0 THEN
        DISPLAY "Exit program..",p_status

        EXIT PROGRAM p_status
    ELSE
        DISPLAY "Exit program.."

        EXIT PROGRAM
    END IF

END FUNCTION



################################################################################
FUNCTION run_esql_prec (lv_fname,lv_new,lv_base)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_base            CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_verbose>=1 THEN
        DISPLAY "ESQL_PREC     :",lv_fname CLIPPED," ",lv_new CLIPPED
    END IF

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times"
        END IF

        IF compare_file_times(lv_fname,lv_new) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_new CLIPPED,
                   " is newer than ",lv_fname CLIPPED
            END IF

            RETURN
        END IF

    END IF

    IF 0 THEN
        LET mv_errfile=lv_base CLIPPED,get_ext("ERR")
        LET mv_warnfile=lv_base CLIPPED,get_ext("WARN")
        LET lv_runstr=mv_preprocess CLIPPED," ",mv_preprocess_opts CLIPPED," ",
           mv_include CLIPPED," -o ",lv_new CLIPPED," ",lv_fname CLIPPED," 2> ",mv_errfile
    ELSE
        LET mv_warnfile=lv_base CLIPPED,get_ext("WARN")
        LET mv_errfile=lv_base CLIPPED,get_ext("ERR")
        LET lv_runstr=mv_preprocess CLIPPED," ",mv_preprocess_opts CLIPPED," ",
           lv_fname CLIPPED," 2> ",mv_errfile
    END IF

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)

END FUNCTION



################################################################################
FUNCTION run_compile (lv_fname,lv_new,lv_base)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_base            CHAR(512)

# Normal Variables
DEFINE lv_compile_c_opts  CHAR(512)
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_verbose>=2 THEN
        DISPLAY "RUN_COMPILE     :",lv_fname CLIPPED," ",lv_new CLIPPED
    END IF

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times"
        END IF

        IF compare_file_times(lv_fname,lv_new) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_new CLIPPED,
                   " is newer than ",lv_fname CLIPPED
            END IF

            CALL add_obj(lv_new)

            RETURN
        END IF

    END IF

    LET mv_errfile=lv_base CLIPPED,get_ext("ERR")
    LET mv_warnfile=lv_base CLIPPED,get_ext("WARN")

    IF mv_verbose>=4 THEN
        DISPLAY "compile_c=",mv_compile_c CLIPPED
        DISPLAY "compile_c_opts=",mv_compile_c_opts CLIPPED
        DISPLAY "include=",mv_include CLIPPED
    END IF

    LET lv_compile_c_opts=mv_compile_c_opts

    #if mv_compile_c="esql" then
    #let lv_compile_c_opts=mv_compile_c_opts clipped," -I",fgl_getenv("INFORMIXDIR") clipped,"/incl"
    #end if
    #if mv_compile_c="ecpg_wrap" then
    #let lv_compile_c_opts=mv_compile_c_opts clipped," -I/usr/local/pgsql/include"
    #end if
    LET lv_runstr=mv_compile_c CLIPPED," ",lv_compile_c_opts CLIPPED," "

    IF mv_debug THEN
        LET lv_runstr=lv_runstr CLIPPED," ",mv_compile_c_debug
    END IF

    LET lv_runstr=lv_runstr CLIPPED," ",mv_include CLIPPED," -o ",lv_new CLIPPED,
       " -c ",lv_fname CLIPPED," 2> ",mv_errfile
    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    IF mv_verbose>=2 THEN
        DISPLAY "Running : ",lv_runstr CLIPPED
    END IF

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)
    CALL add_obj(lv_new)

END FUNCTION



################################################################################
FUNCTION run_compile_esql (lv_fname,lv_new,lv_base)
# Parameters
DEFINE lv_fname           CHAR(512)
DEFINE lv_new             CHAR(512)
DEFINE lv_base            CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times"
        END IF

        IF compare_file_times(lv_fname,lv_new) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_new CLIPPED,
                   " is newer than ",lv_fname CLIPPED
            END IF

            CALL add_obj(lv_new)

            RETURN
        END IF

    END IF

    IF mv_verbose>2 THEN
        DISPLAY "RUN_COMP_ESQL :",lv_fname CLIPPED," ",lv_new CLIPPED
    END IF

    LET mv_warnfile=lv_base CLIPPED,get_ext("WARN")
    LET mv_errfile=lv_base CLIPPED,get_ext("ERR")

    if mv_lexdialect="INFORMIX" then
	# make sure its set in the environment to what we think 
	# it should be set to - either internally - or in the aubitrc
	if fgl_getenv("INFORMIXC")!=" " then
		call aclfgl_setenv("INFORMIXC",fgl_getenv("INFORMIXC"))
	end if
    end if

    LET lv_runstr=mv_compile_pec CLIPPED," ",mv_compile_pec_opts CLIPPED

    IF mv_debug THEN
        LET lv_runstr=lv_runstr CLIPPED," -g "
    END IF

    IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
        LET lv_fname=get_basename(lv_fname)
    END IF

    LET lv_runstr=lv_runstr CLIPPED," ",mv_include CLIPPED," -o ",lv_new CLIPPED,
       " -c ",lv_fname CLIPPED," 2> ",mv_errfile

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)
    CALL add_obj(lv_new)

END FUNCTION



FUNCTION run_compile_form (lv_fname)
# Parameters
DEFINE lv_fname           CHAR(256)

# Normal Variables
DEFINE lv_runstr          CHAR(1045)
DEFINE lv_status          INTEGER

    LET lv_runstr="fcompile "

    IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
        LET lv_fname=get_basename(lv_fname)
    END IF

    LET lv_runstr=lv_runstr CLIPPED," ",lv_fname CLIPPED

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    CALL check_exit_status(lv_status,lv_fname,lv_runstr)

END FUNCTION



################################################################################
FUNCTION run_link (lv_output)
# Parameters
DEFINE lv_output          CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times"
        END IF

        IF compare_file_times(mv_newest_obj,lv_output) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_output CLIPPED,
                   " is newer than ",mv_newest_obj CLIPPED
            END IF

            RETURN
        END IF

    END IF

    if mv_lexdialect="INFORMIX" then
	# make sure its set in the environment to what we think 
	# it should be set to - either internally - or in the aubitrc
	if fgl_getenv("INFORMIXC")!=" " then
		call aclfgl_setenv("INFORMIXC",fgl_getenv("INFORMIXC"))
	end if
    end if

    LET mv_warnfile=lv_output CLIPPED,get_ext("WARN")
    LET mv_errfile=lv_output CLIPPED,get_ext("ERR")
    LET lv_runstr=mv_link

    IF mv_make_dll THEN
      IF fgl_getenv("TARGET_OS")="darwin" THEN
            # Darwin has two types of "shared" output  bundles and shared libraries
            IF lv_output matches "*.so" or lv_output matches "*.dylib" THEN
               LET mv_dll_opts=fgl_getenv("A4GL_DLL_SHARED_OPTS")
            END IF
      END IF
      
        LET lv_runstr=lv_runstr CLIPPED," ",mv_dll_opts
    END IF

    IF mv_static THEN
        LET lv_runstr=lv_runstr CLIPPED," -static"
    END IF

    IF mv_debug THEN
        LET lv_runstr=lv_runstr CLIPPED," ",mv_link_debug
    END IF

    IF mv_verbose>=5 THEN
        DISPLAY "mv_objects  =",mv_objects CLIPPED
        DISPLAY "lv_output   =",lv_output CLIPPED
        DISPLAY "mv_libs     =",mv_libs CLIPPED
        DISPLAY "mv_link     =",mv_link CLIPPED
        DISPLAY "mv_link_libs=",mv_link_libs CLIPPED
        DISPLAY "mv_link_opts=",mv_link_opts CLIPPED
    END IF

    LET lv_runstr=lv_runstr CLIPPED," ",mv_objects CLIPPED," -o ",lv_output CLIPPED,
       " ",mv_libs CLIPPED," ",mv_link_libs CLIPPED," ",mv_link_opts CLIPPED," 2>",
       mv_errfile CLIPPED

    IF mv_verbose>=1 THEN
        DISPLAY "Linking ",lv_output CLIPPED
    END IF

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    IF mv_verbose>=4 THEN
        DISPLAY "OBJECTS       : ",mv_objects CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    IF file_exists(mv_errfile) AND fgl_getenv("DISPLAYLINKERRFILE")="Y" THEN

        IF file_size(mv_errfile) THEN

            IF fgl_getenv("TARGET_OS")="mingw" THEN
                RUN "type "||mv_errfile CLIPPED
            ELSE
                RUN "cat "||mv_errfile CLIPPED
            END IF

        END IF

    END IF

    IF mv_verbose>=5 THEN
        DISPLAY "Ran command"
    END IF

    CALL check_exit_status(lv_status,lv_output,lv_runstr)

END FUNCTION



################################################################################
FUNCTION run_link_lib (lv_output)
# Parameters
DEFINE lv_output          CHAR(512)

# Normal Variables
DEFINE lv_runstr          CHAR(32000)
DEFINE lv_status          INTEGER

    IF mv_makecompile THEN

        IF mv_verbose>=3 THEN
            DISPLAY "Make Compile - checking file times"
        END IF

        IF compare_file_times(mv_newest_obj,lv_output) THEN

            IF mv_verbose>=2 THEN
                DISPLAY "Make Compile specified - file skipped as ",lv_output CLIPPED,
                   " is newer than ",mv_newest_obj CLIPPED
            END IF

            RETURN
        END IF

    END IF

    LET mv_warnfile=lv_output CLIPPED,get_ext("WARN")
    LET mv_errfile=lv_output CLIPPED,get_ext("ERR")
    LET lv_runstr="rm -f ",lv_output

    RUN lv_runstr CLIPPED RETURNING lv_status

    LET lv_runstr=mv_ar_cmd CLIPPED," ",mv_ar_opts CLIPPED," ",lv_output CLIPPED," "
       ,mv_objects

    IF mv_verbose>=1 THEN
        DISPLAY "Archiving ",lv_output CLIPPED
    END IF

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    IF mv_verbose>=4 THEN
        DISPLAY "OBJECTS       : ",mv_objects CLIPPED
    END IF

    LET lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

    RUN lv_runstr CLIPPED RETURNING lv_status

    IF mv_verbose>=5 THEN
        DISPLAY "Ran command"
    END IF

    CALL check_exit_status(lv_status,lv_output,lv_runstr)

    LET lv_runstr=mv_ranlib_cmd CLIPPED," ",mv_ranlib_opts CLIPPED," ",
       lv_output CLIPPED

    IF mv_verbose>=2 THEN
        DISPLAY lv_runstr CLIPPED
    END IF

    RUN lv_runstr CLIPPED RETURNING lv_status

    IF mv_verbose>=5 THEN
        DISPLAY "Ran command"
    END IF

    CALL check_exit_status(lv_status,lv_output,lv_runstr)

END FUNCTION



FUNCTION add_obj (lv_obj)
# Parameters
DEFINE lv_obj             CHAR(256)

# Normal Variables
DEFINE lv_chk             CHAR(255)

    # Check to see if we've already added this object
    LET lv_chk="* ",lv_obj CLIPPED," *"

    IF mv_objects MATCHES lv_chk THEN

        # Its already in our list...
        RETURN
    END IF

    LET lv_chk="* ",lv_obj

    IF mv_objects MATCHES lv_chk THEN

        # Its already in our list...
        RETURN
    END IF

    IF mv_verbose>=5 THEN
        DISPLAY "ADD OBJ : ",lv_obj CLIPPED
    END IF

    LET mv_objects=mv_objects CLIPPED," ",lv_obj

    IF mv_newest_obj IS NULL THEN
        LET mv_newest_obj=lv_obj

        RETURN
    END IF

    IF compare_file_times(mv_newest_obj,lv_obj) THEN
        LET mv_newest_obj=lv_obj
    END IF

END FUNCTION



FUNCTION rename_file (m1,m2)
# Parameters
DEFINE m1                 CHAR(255)
DEFINE m2                 CHAR(255)

# Normal Variables
DEFINE a                  INTEGER
DEFINE lv_str             CHAR(1000)


code
{
A4GL_trim(m1);
A4GL_trim(m2);
a=A4GL_move_file(m1,m2);
}

endcode

    RETURN a

END FUNCTION



FUNCTION tail_file (mv_file,n)
# Parameters
DEFINE mv_file            CHAR(512)
DEFINE n                  INTEGER

# Normal Variables
DEFINE a                  INTEGER


code
{
FILE *f;
char *ptr;
A4GL_trim(mv_file);
f=fopen(mv_file,"r");
if (f!=0) {
	fseek(f,0,SEEK_END);
	a=ftell(f);
	rewind(f);
	ptr=acl_malloc2(a+1);
	fread(ptr,a,1,f);
	fclose(f);
	while (a) {
		if (ptr[a]=='\n') {
			if (n==0) {
				printf("%s",&ptr[a+1]);
				break;
			}
			n--;
		}
		a--;
	}
	free(ptr);
}
}

endcode

END FUNCTION



FUNCTION head_file (mv_file,n)
# Parameters
DEFINE mv_file            CHAR(512)
DEFINE n                  INTEGER

# Normal Variables
DEFINE a                  INTEGER


code
{
FILE *f;
char *ptr;
char *lptr;
A4GL_trim(mv_file);
f=fopen(mv_file,"r");
if (f!=0) {
	int c;
	fseek(f,0,SEEK_END);
	a=ftell(f);
	rewind(f);
	ptr=acl_malloc2(a+1);
	memset(ptr,0,a+1);
	fread(ptr,a,1,f);
	fclose(f);
	lptr=ptr;
	c=0;
	while (n && c<a) {
		if (ptr[c]=='\n') {
			ptr[c]=0;
			printf("%s\n",lptr);
			lptr=&ptr[c+1];
			n--;
		}
		c++;
	}
	free(ptr);
}
}

endcode

END FUNCTION



FUNCTION file_exists (s)
# Parameters
DEFINE s                  CHAR(512)

# Normal Variables
DEFINE a                  INTEGER


code
{
A4GL_trim(s);
a=A4GL_file_exists(s);
}

endcode

    RETURN a

END FUNCTION



FUNCTION file_size (s)
# Parameters
DEFINE s                  CHAR(512)

# Normal Variables
DEFINE l                  INTEGER

    LET l=-1


code
{
A4GL_trim(s);
l=A4GL_file_length(s);
}

endcode

    RETURN l

END FUNCTION



FUNCTION remove_file (s)
# Parameters
DEFINE s                  CHAR(512)


code
{
A4GL_trim(s);
A4GL_delete_file(s);
}

endcode

END FUNCTION



FUNCTION verbosity ()

    RETURN mv_verbose

END FUNCTION


code
int isverbose_c(int n) {
	return mv_verbose>n;
}

endcode




FUNCTION isverbose (n)
# Parameters
DEFINE n                  INTEGER

    IF mv_verbose>=n THEN
        RETURN 1
    ELSE
        RETURN 0
    END IF

END FUNCTION



FUNCTION get_basename (lv_fname)
# Parameters
DEFINE lv_fname           CHAR(256)

# Normal Variables
DEFINE a                  INTEGER

    FOR a=length(lv_fname) TO 1 STEP -1

        IF lv_fname[a]="/" OR lv_fname[a]="\\" THEN
            RETURN lv_fname[a+1,256]
        END IF

    END FOR

    RETURN lv_fname

END FUNCTION



FUNCTION get_fname (lv_base,lv_ext_type)
# Parameters
DEFINE lv_base            CHAR(256)
DEFINE lv_ext_type        CHAR(10)

# Normal Variables
DEFINE lv_new             CHAR(256)

    IF mv_verbose>=5 THEN
        DISPLAY "lv_ext_type=",lv_ext_type CLIPPED," base=",lv_base CLIPPED," otype=",
           mv_output_type CLIPPED," output=",mv_output CLIPPED
    END IF

    IF lv_ext_type=mv_output_type THEN

        IF mv_verbose>3 THEN
            DISPLAY "We're producing final output, mv_output=",mv_output
        END IF

        IF mv_output="" OR mv_output IS NULL THEN
            LET lv_new=lv_base CLIPPED,get_ext(lv_ext_type)

            IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN

                # Trim off any leading path - it'll be dumped in the local directory
                LET lv_new=get_basename(lv_new)
            END IF

        ELSE
            LET lv_new=mv_output
        END IF

    ELSE

        # Trim off any leading path - it'll be dumped in the local directory
        LET lv_new=lv_base CLIPPED,get_ext(lv_ext_type)

        IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
            LET lv_new=get_basename(lv_new)
        END IF

    END IF

    RETURN lv_new

END FUNCTION



FUNCTION remove_file_of_type (lv_fname,lv_type)
# Parameters
DEFINE lv_fname           CHAR(256)
DEFINE lv_type            CHAR(10)

    IF mv_keep!=0 THEN
        RETURN
    END IF

    IF lv_type="C" THEN

        #  DELETE THE INTERMEDIATE FILES...
        CALL remove_file(get_fname(lv_fname CLIPPED,"C"))
        CALL remove_file(get_fname(lv_fname CLIPPED,"H"))
    END IF

    IF lv_type="EC" THEN

        #  DELETE THE INTERMEDIATE FILES...
        CALL remove_file(get_fname(lv_fname CLIPPED,"EC"))
        CALL remove_file(get_fname(lv_fname CLIPPED,"H"))
    END IF

END FUNCTION



FUNCTION isyes (s)
# Parameters
DEFINE s                  CHAR(20)

    IF UPSHIFT(s[1])="Y" OR s="1" OR UPSHIFT(s)="TRUE" THEN
        RETURN 1
    ELSE
        RETURN 0
    END IF

END FUNCTION
