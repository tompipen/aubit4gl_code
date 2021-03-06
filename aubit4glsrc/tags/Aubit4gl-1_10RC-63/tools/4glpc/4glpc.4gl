
pragma force ui "CONSOLE"
pragma debug file "debug.4glpc.out"

define
	mv_debug,
	mv_echomode,
	mv_ignerrs,
	mv_keep,
	mv_makecompile,
	mv_make_dll,
	mv_map,
	mv_noerrcode,
	mv_shared,
	mv_stacktrace,
	mv_system4gl,
	mv_verbose ,
	mv_ansi_mode,
	mv_show_errtail,
	mv_esql_to_c_first,
	mv_make_globals smallint,
	mv_static smallint
define mv_versioned integer
define mv_sqltype char(255)

define mv_export_symbols char(256)
define mv_import_symbols char(256)
define mv_objects char(20480)
define mv_errfile char(256)
define mv_warnfile char(256)
define mv_newest_obj char(256)
define mv_output_type CHAR(20)
define mv_dump_strings integer

define
	mv_db 			char(128),
	mv_lextype 		char(20),
	mv_lexdialect 		char(20),
	mv_stage 		char(20),
	mv_namespace 		char(256),
	mv_output 		char(256),

	mv_compile_4gl		char(256), # 4gl -> c/ec
	mv_compile_4gl_opts	char(256),

	mv_compile_c 		char(256), # C-> OBJ
	mv_compile_c_opts 	char(256), 
	mv_compile_c_debug 	char(256),

	mv_compile_pec 		char(256), # EC -> C
	mv_compile_pec_opts 	char(256),  
 

	mv_preprocess 		char(256),
	mv_preprocess_opts	char(256),

	mv_link 		char(256),
	mv_link_opts 		char(256),
	mv_link_libs 		char(256),
	mv_link_debug 		char(256),
	mv_dll_opts 		char(256),
	mv_include 		char(512),
	mv_libs			char(5000),
	mv_aubit4gllib 		char(5000)
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

function init()
define lv_pack char(256)
define use_indicators integer

	let mv_versioned=1


	if mv_verbose>=4 then display "Reading packs" end if
	let lv_pack=mv_lextype
	call read_pack(lv_pack)
	let mv_dump_strings=0

	let lv_pack=mv_lextype clipped,"_",mv_lexdialect
	call read_pack(lv_pack)


	let lv_pack=fgl_getenv("TARGET_OS")
	call read_pack(lv_pack)

	let lv_pack=fgl_getenv("TARGET_OS"),"__",mv_lextype clipped
	call read_pack(lv_pack)
 
	let lv_pack=fgl_getenv("TARGET_OS"),"__",mv_lextype clipped,"_",mv_lexdialect
	call read_pack(lv_pack)



	let lv_pack=fgl_getenv("TARGET")
	call read_pack(lv_pack)

	let lv_pack=fgl_getenv("TARGET"),"__",mv_lextype clipped
	call read_pack(lv_pack)
 
	let lv_pack=fgl_getenv("TARGET"),"__",mv_lextype clipped,"_",mv_lexdialect clipped

	call read_pack(lv_pack)



	initialize 	mv_db, 
			mv_stage,
			mv_namespace,
			mv_compile_4gl,
			mv_compile_4gl_opts,
			mv_compile_c,
			mv_compile_c_opts ,
			mv_compile_pec,
			mv_compile_pec_opts,
			mv_preprocess,
			mv_preprocess_opts,
			mv_sqltype,
			mv_show_errtail,
			mv_link,
			mv_dll_opts,	
			mv_link_libs,
			mv_link_opts 		to null

	initialize mv_newest_obj to null
	let mv_ansi_mode=0
	let mv_debug=0
	let mv_echomode=0
	let mv_ignerrs=0
	let mv_keep=-1
	let mv_makecompile=0
	let mv_make_dll=0
	let mv_map=0
	let mv_noerrcode=0
	let mv_shared=1
	let mv_stacktrace=1
	let mv_system4gl=0
	let mv_verbose=0
	let mv_make_globals=0
	LET mv_esql_to_c_first=0
	let mv_static=0

	IF fgl_getenv("ESQL_TO_C")="Y" THEN
		LET mv_esql_to_c_first=1
	END IF


	let mv_include="-I\"",fgl_getenv("AUBITDIR"),"/incl\" "


	
#IF fgl_getenv("GTK_INC_PATH")!= "" THEN
		#let mv_include=mv_include clipped, " -I\"",fgl_getenv("GTK_INC_PATH"),"\""
	#END IF
	if isyes(fgl_getenv("VERSIONEDLIB")) THEN
		let mv_versioned=1
	end if

	call aclfgl_setenv("A4GL_DEBUGFILE","debug.4glc.out")

	LET mv_compile_4gl	=fgl_getenv("A4GL_4GLC_COMP")
	LET mv_compile_4gl_opts	=fgl_getenv("A4GL_4GLC_OPTS")

	LET mv_compile_c	=fgl_getenv("A4GL_C_COMP")
	LET mv_compile_c_opts	=fgl_getenv("A4GL_C_OPTS")
	LET mv_compile_c_debug	=fgl_getenv("A4GL_C_DEBUG")

	LET mv_compile_pec	=fgl_getenv("A4GL_EC_COMP")
	LET mv_compile_pec_opts	=fgl_getenv("A4GL_EC_OPTS")

	LET mv_preprocess	=fgl_getenv("A4GL_PREC_COMP")
	LET mv_preprocess_opts	=fgl_getenv("A4GL_PREC_OPTS")

	LET mv_link		=fgl_getenv("A4GL_LINK")
	LET mv_link_opts	=fgl_getenv("A4GL_LINK_OPTS")
	LET mv_link_libs	=fgl_getenv("A4GL_LINK_LIBS")
	LET mv_dll_opts		=fgl_getenv("A4GL_DLL_OPTS")

	LET mv_stage="OBJ0?"

	LET mv_import_symbols	=fgl_getenv("A4GL_IMPORT_DYNAMIC")
	LET mv_export_symbols	=fgl_getenv("A4GL_EXPORT_DYNAMIC")

	if isyes(fgl_getenv("USE_INDICATOR")) then
		let use_indicators=1
	else
		let use_indicators=0
	end if

	IF use_indicators=0 then
		LET mv_preprocess_opts=mv_preprocess_opts clipped, fgl_getenv("A4GL_NOINDICATORS")	
		LET mv_compile_pec_opts=mv_compile_pec_opts clipped, fgl_getenv("A4GL_NOINDICATORS")	
	END IF

	if fgl_getenv("A4GL_SHOW_ERRTAIL")="Y" then
		LET mv_show_errtail=1
	end if

	if fgl_getenv("A4GL_SHOW_ERRTAIL")="N" then
		LET mv_show_errtail=0
	end if

	if mv_compile_4gl is null or mv_compile_4gl matches " " then
		let mv_compile_4gl	="4glc"
	end if

	if mv_link is null or mv_link matches " " then
		let mv_link		="gcc"
	end if

	if mv_link_opts is null or mv_link_opts matches " " then
		let mv_link_opts	="-L",fgl_getenv("AUBITDIR") clipped,"/lib"
	end if
	if mv_link_libs is null or mv_link_libs matches " " then
		let mv_link_libs=" "
	end if
		
	if mv_dll_opts is null or mv_dll_opts matches " " then
		let mv_dll_opts		="--shared "
	end if

	if mv_compile_c is null or mv_compile_c matches " " then
		let mv_compile_c	="gcc"
	end if

	if mv_compile_c_debug is null or mv_compile_c_debug matches " " then
		let mv_compile_c_debug	="-g"
	end if

	if mv_link_debug is null or mv_link_debug matches " " then
		let mv_link_debug	="-g"
	end if

	if mv_compile_pec is null or mv_compile_pec matches " " then
		let mv_compile_pec	="NO"
	end if

	if mv_preprocess is null or mv_preprocess matches " " then
		let mv_preprocess	="NO"
	end if

	if mv_compile_c_opts is null then let mv_compile_c_opts=" " end if
	if mv_compile_pec_opts is null then let mv_compile_pec_opts=" " end if


	IF mv_lexdialect="INGRES" or mv_lexdialect="POSTGRES" or fgl_getenv("A4GL_ESQL_TO_C_FIRST")="Y" THEN
		
   if mv_verbose>=4 then
		DISPLAY "SETTING C_FIRST MODE"
	end if
		LET mv_esql_to_c_first=1
	END IF
END FUNCTION




MAIN 
DEFINE a INTEGER
DEFINE lv_num_args INTEGER
DEFINE lv_arg CHAR(200)
DEFINE lv_type CHAR(40)
DEFINE lv_output char(255)
DEFINE lv_cnt integer
DEFINE lv_minus_c, lv_minus_e INTEGER
  call aclfgl_setenv("A4GL_UI","CONSOLE")

  LET lv_num_args=num_args()
  IF lv_num_args=0 then
	CALL usg()
  END IF


  LET mv_lextype=fgl_getenv("A4GL_LEXTYPE")



  IF mv_lextype IS NULL OR mv_lextype MATCHES " " THEN
  	LET mv_lextype="C"
  END IF

  if mv_lextype="WRITE" then
	if fgl_getenv("A4GL_PACKER") matches "XML*" THEN
		let mv_stage="XML"
	else
		let mv_stage="MIF"
	end if
  end if

  LET mv_lexdialect=fgl_getenv("A4GL_LEXDIALECT")
  initialize mv_output to null

  FOR a=1 to lv_num_args
	LET lv_arg=arg_val(a)

	if lv_arg matches "-o*" and lv_arg!="-o" then
		let mv_output=lv_arg[3,200]
		if mv_verbose>2 then
			display "(1) mv_output=",mv_output clipped
		end if
		continue for
	end if

	CASE lv_arg
		WHEN "-?" 			call show_help(2)  continue for
		WHEN "--verbose"		let mv_verbose=mv_verbose+1 continue for
		WHEN "-V"			let mv_verbose=mv_verbose+1 continue for

		WHEN "-V1"			let mv_verbose=1 continue for
		WHEN "-V2"			let mv_verbose=2 continue for
		WHEN "-V3"			let mv_verbose=3 continue for
		WHEN "-V4"			let mv_verbose=4 continue for
		WHEN "-V5"			let mv_verbose=5 continue for
		WHEN "-versioned"		let mv_versioned=1 continue for
		WHEN "-notversioned"		let mv_versioned=0 continue for
		WHEN "-globcurs"		call aclfgl_setenv("A4GL_GLOBALCURS","Y") continue for

		WHEN "-t"			let a=a+1 let mv_lextype=arg_val(a) 
  							call aclfgl_setenv("A4GL_LEXTYPE",mv_lextype clipped)
					continue for
		WHEN "--lextype"		let a=a+1 let mv_lextype=arg_val(a) 
  							call aclfgl_setenv("A4GL_LEXTYPE",mv_lextype clipped)
					continue for

		WHEN "-td"			let a=a+1 let mv_lexdialect=arg_val(a) 
  							call aclfgl_setenv("A4GL_LEXDIALECT",mv_lexdialect clipped)
							continue for
		WHEN "--lexdialect"		let a=a+1 let mv_lexdialect=arg_val(a) 
  							call aclfgl_setenv("A4GL_LEXDIALECT",mv_lexdialect clipped)
							continue for

		WHEN "--neverconvert"	
					CALL aclfgl_setenv("A4GL_NEVERCONVERT","Y")
					continue for

		WHEN "--output"		let a=a+1 let mv_output=arg_val(a) continue for
		WHEN "-o"		let a=a+1 let mv_output=arg_val(a) continue for
	END CASE
  END FOR

if mv_verbose>3 then
	display "(2) mv_output=", mv_output clipped
end if


  if mv_lextype="EC" and (mv_lexdialect is null  or mv_lexdialect matches " " ) THEN
		CALL aclfgl_setenv("A4GL_LEXDIALECT","INFORMIX")
		LET mv_lexdialect="INFORMIX"
  end if

  if mv_verbose>=3 then
  		display "mv_lextype=",mv_lextype," dialect=",mv_lexdialect
  end if
  CALL init()

code
if (mv_versioned) {
	sprintf(mv_aubit4gllib,"aubit4gl-%s_%d", A4GL_internal_version (), A4GL_internal_build ());
} else {
	sprintf(mv_aubit4gllib,"aubit4gl");
}
endcode

	LET mv_libs="-L",fgl_getenv("AUBITDIR") clipped,"/lib" #  -l",mv_aubit4gllib clipped

  LET lv_minus_c=0
  LET lv_minus_e=0
# We should really scan first for our output filename...
  LET lv_cnt=0
  FOR a=1 to lv_num_args
	LET lv_arg=arg_val(a)
	
	IF lv_arg matches "-o*" THEN
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
  IF lv_cnt=0 and mv_output_type="UNK" THEN
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
  	FOR a=1 to lv_num_args
		LET lv_arg=arg_val(a)
		IF lv_arg="-o" THEN
			LET lv_arg=arg_val(a+1)
			exit for
		END IF
		if lv_arg matches "-o*" then
			let lv_arg=lv_arg[3,200]
			exit for
		end if
  	END FOR

	if fgl_getenv("A4GL_LEXTYPE")="SPL" then
		LET mv_output_type="SPL"
	else
		# Guess that its probably an executable..
		LET mv_output_type="EXE"
	end if

	# Does it look like a static library ?
	let lv_type=generate_ext("LIB")
	IF lv_arg matches "*.a" or lv_arg matches lv_type  # Its a library
	   or lv_arg matches "*.aox" then 
		LET mv_output_type="LIB"
	END IF


	let lv_type=generate_ext("EXE")
	IF lv_arg matches "*.exe" or lv_arg matches lv_type  then
		LET mv_output_type="EXE"
	END IF


	# Does it look like a shared library ?
	let lv_type=generate_ext("DLL")
	if lv_arg matches "*.so" or lv_arg matches lv_type or mv_make_dll then # Its a library
		LET mv_output_type="DLL"
	end if

	# Does it look like a object ?
	let lv_type=generate_ext("OBJ")
	if lv_arg matches "*.o" 
	   or lv_arg matches "*.ao" 
	   or lv_arg matches "*.4go" 
	   or lv_arg matches "*.4pe" 
	   or lv_arg matches lv_type then
		LET mv_output_type="OBJ"
	end if

	# Does it look like an EC module ?
	let lv_type=generate_ext("EC")

	if lv_arg matches "*.ec" 
	   or lv_arg matches "*.cpc" 
	   or lv_arg matches lv_type
	   or lv_arg matches "*.pgc" then # Its an esql/c module
		LET mv_output_type="EC"
	end if

	# Does it look like a form ?
	let lv_type=generate_ext("SRCFORM")
	if lv_arg matches "*.per" or lv_arg matches lv_type then # Its a form
		# Shouldn't happen - 
		DISPLAY "A form should never be the output."
		CALL usg()
	end if
		
	# Does it look like a 4GL module ?
	let lv_type=generate_ext("4GL")
	if lv_arg matches "*.4gl" or lv_arg matches lv_type then # Its a 4GL
		# Shouldn't happen - 
		DISPLAY "A 4gl module should never be the output."
		CALL usg()
	end if

	# Does it look like a menu ?
	if lv_arg matches "*.menu"  then # Its a menu
		DISPLAY "A menu module should never be the output."
		CALL usg()
	end if

	# Does it look like a C file ?
	let lv_type=generate_ext("C")
	if lv_arg matches "*.c"  # Its a C file
	   or lv_arg matches lv_type then
		LET mv_output_type="C"
	end if

	# Does it look like a message/help file ?
	let lv_type=generate_ext("MSG")
	if lv_arg matches "*.msg" or lv_arg matches lv_type 
	   or lv_arg matches "*.hlp" then # Its a help file
		DISPLAY "A help source module should never be the output."
		CALL usg()
	end if

	# Does it look like a compiled message/help file ?
	let lv_type=generate_ext("IEM")
	if lv_arg matches "*.iem" or lv_arg matches lv_type  then
		LET mv_output_type="MSG"
	end if
  END IF

if mv_verbose>3 then
	display "(3) mv_output=", mv_output clipped
	display "mv_output_type=", mv_output_type clipped
	
end if


  LET mv_stage=mv_output_type

  FOR a=1 to lv_num_args
	LET lv_arg=arg_val(a)
	if lv_arg!="-o" and lv_arg matches "-o*" then
		let mv_output=lv_arg[3,200]
		if mv_verbose>3 then
			display "mv_output=",mv_output
		end if
		continue for
	end if
	CASE lv_arg
		WHEN "-?" 			call show_help(2)  continue for
		WHEN "-help" 			call show_help(2)  continue for
		WHEN "--help" 			call show_help(2)  continue for
		WHEN "--help-short"		call show_help(2)  continue for
	
		WHEN "--help-options" 		call show_help(3)  continue for
		WHEN "--help-env" 		call show_help(5)  continue for
		WHEN "--help-types" 		call show_help(6)  continue for
		WHEN "--help-examples" 		call show_help(7)  continue for
	
		WHEN "--globals"		let mv_make_globals=1 continue for
		WHEN "-G"			let mv_make_globals=1 continue for
	
		WHEN "-N"		let a=a+1 let mv_namespace=arg_val(a) continue for
		WHEN "--namespace"		let a=a+1 let mv_namespace=arg_val(a) continue for
		WHEN "-namespace"		let a=a+1 let mv_namespace=arg_val(a) continue for

		WHEN "-noprefix"		let mv_namespace=" " continue for
		WHEN "--noprefix"		let mv_namespace=" " continue for
		WHEN "-n"			let mv_namespace=" " continue for

		WHEN "--stack_trace"		let a=a+1 let mv_stacktrace=arg_val(a) continue for
		WHEN "-s"			let mv_stacktrace=1 continue for
		WHEN "-s0"			let mv_stacktrace=0 continue for
		WHEN "-s1"			let mv_stacktrace=1 continue for


		WHEN "--islibrarymodule"	call aclfgl_setenv("A4GL_COMPILING_LIBRARY","Y") continue for
		WHEN "--dump-strings"		let mv_dump_strings=1 call aclfgl_setenv("A4GL_DUMPSTRINGS","Y")continue for
		WHEN "--dump-strings-ident"	let mv_dump_strings=2 call aclfgl_setenv("A4GL_DUMPSTRINGS","ident") continue for
		WHEN "--ident-start"		let a=a+1 call aclfgl_setenv("A4GL_DUMPSTRINGS_START",arg_val(a)) continue for
		WHEN "--translation-file"	let a=a+1 call aclfgl_setenv("A4GL_TRANSLATEFILE",arg_val(a))continue for
		WHEN "--output"			let a=a+1 let mv_output=arg_val(a) continue for
		WHEN "-o"			let a=a+1 let mv_output=arg_val(a) continue for

		WHEN "-c"			if mv_output_type!="OBJ" then
							display "Invalid combination -c, generating a ",mv_output_type
							exit program 2
						end if
						let mv_stage="OBJ" continue for
						
		WHEN "-e"			if mv_output_type!="C" then
							display "Invalid combination -e, generating a ",mv_output_type
							exit program 2
						end if
						let mv_stage="C" continue for

		WHEN "--compile-4gl-only"	let mv_stage="EC" continue for
		WHEN "--compile-only"		let mv_stage="OBJ" continue for
		WHEN "--preprocess-only"	let mv_stage="C" continue for

		WHEN "-t"			
							let a=a+1 
					let mv_lextype=arg_val(a) 

				if mv_lextype="WRITE" then
					if fgl_getenv("A4GL_PACKER") matches "XML*" then
						let mv_stage="XML"
					else
						let mv_stage="MIF"
					end if
				end if
							continue for
		WHEN "--lextype"		let a=a+1 let mv_lextype=arg_val(a)
				if mv_lextype="WRITE" then
					if fgl_getenv("A4GL_PACKER") matches "XML*" then
						let mv_stage="XML"
					else
						let mv_stage="MIF"
					end if
				end if
					continue for

		WHEN "-td"			let a=a+1 let mv_lexdialect=arg_val(a) continue for
		WHEN "--lexdialect"		let a=a+1 let mv_lexdialect=arg_val(a) continue for

		WHEN "-k"			let mv_keep=1 continue for
		WHEN "--keep"			let mv_keep=1 continue for

		WHEN "-K"			let mv_keep=0 continue for
		WHEN "--clean"			let mv_keep=0 continue for
		WHEN "-nokeep"			let mv_keep=0 continue for

		WHEN "-d"			let a=a+1 let mv_db=arg_val(a) continue for
		WHEN "--database"		let a=a+1 let mv_db=arg_val(a) continue for

		WHEN "--neverconvert"		continue for


		WHEN "-C"			let a=a+1 let mv_sqltype=arg_val(a) call aclfgl_setenv("A4GL_SQLTYPE",mv_sqltype clipped) continue for
		WHEN "--sqltype"		let a=a+1 let mv_sqltype=arg_val(a) call aclfgl_setenv("A4GL_SQLTYPE",mv_sqltype clipped) continue for


		WHEN "--verbose"		let mv_verbose=mv_verbose+1 continue for
		WHEN "-V"			let mv_verbose=mv_verbose+1 continue for

		WHEN "-V1"			let mv_verbose=1 continue for
		WHEN "-V2"			let mv_verbose=2 continue for
		WHEN "-V3"			let mv_verbose=3 continue for
		WHEN "-V4"			let mv_verbose=4 continue for
		WHEN "-V5"			let mv_verbose=5 continue for
		WHEN "-versioned"		let mv_versioned=1 continue for
		WHEN "-notversioned"		let mv_versioned=0 continue for

		WHEN "-S"			let mv_verbose=0 continue for
		WHEN "--silent"			let mv_verbose=0 continue for
		WHEN "-q"			let mv_verbose=0 continue for

		WHEN "--shared"			
						display "--shared is depreciated - use '--use-shared' instead"
						let mv_shared=1 continue for
		WHEN "--static"			
						display "--static is depreciated - use '--use-static' instead"
						let mv_shared=0 continue for

		WHEN "--use-shared"			let mv_shared=1 continue for
		WHEN "--use-static"			let mv_shared=0 continue for

		WHEN "--system4gl"		let mv_system4gl=1 continue for
		WHEN "-4"			let mv_system4gl=1 continue for

		WHEN "--echo"			let mv_echomode=1 continue for
		WHEN "-E"			let mv_echomode=1 continue for

		WHEN "--compile-c"		let a=a+1 let mv_compile_c   =arg_val(a) continue for
		WHEN "--compile-ec"		let a=a+1 let mv_compile_pec =arg_val(a) continue for
		WHEN "--preprocess-ec"		let a=a+1 let mv_preprocess  =arg_val(a) continue for
		WHEN "--link"			let a=a+1 let mv_link        =arg_val(a) continue for
	
		WHEN "-v"		call show_version(0) continue for
		WHEN "--version"		call show_version(0) continue for
		WHEN "--version-4glpc"		call show_version(2) continue for
		WHEN "-f"		call show_version(1) continue for
		WHEN "--version-full"		call show_version(1) continue for
		WHEN "--version_full"		call show_version(1) continue for

		WHEN "--preview-errors"		let mv_show_errtail =1 continue for

		WHEN "--ignore-errors"		let mv_ignerrs  =1 continue for
		WHEN "--noerrcode"		let mv_noerrcode=1 continue for
		WHEN "--map"			let mv_map=1 continue for
		WHEN "--nomap"			let mv_map=0 continue for
		WHEN "--make-compile"		let mv_makecompile=1 continue for

		WHEN "-g"			
					let mv_debug=1 continue for
		WHEN "--debug"			let mv_debug=1 continue for
		WHEN "-static"			let mv_static=1 continue for

		WHEN "--as-dll"			let mv_make_dll=1 let mv_stage="DLL" 
						if mv_output="" or mv_output is null then
							let mv_output="a.out",get_ext("DLL")
						end if
						let mv_compile_c_opts=mv_compile_c_opts clipped," -fPIC"
						continue for

		WHEN "-as-dll"			let mv_make_dll=1 let mv_stage="DLL" 
						if mv_output="" or mv_output is null then
							let mv_output="a.out",get_ext("DLL")
						end if
						let mv_compile_c_opts=mv_compile_c_opts clipped," -fPIC"
						continue for


		WHEN "-X4glc"			let a=a+1 let mv_compile_4gl_opts=mv_compile_4gl_opts clipped," " ,arg_val(a) continue for
		WHEN "-Xlinker"			let a=a+1 let mv_link_opts=mv_link_opts clipped," " ,arg_val(a) continue for
		WHEN "-Xcompiler"		let a=a+1 let mv_compile_c_opts=mv_compile_c_opts clipped," ",arg_val(a) continue for
		WHEN "-Xcompiler-ec"		let a=a+1 let mv_compile_pec_opts=mv_compile_pec_opts clipped, " ", arg_val(a) continue for
		WHEN "-Xpreprocess-ec"		let a=a+1 let mv_preprocess_opts=mv_preprocess_opts clipped," ",arg_val(a) continue for

		WHEN "--ansi-warn"		call aclfgl_setenv("A4GL_ANSI_WARN","Y")
		WHEN "--ansi-error"		call aclfgl_setenv("A4GL_ANSI_ERROR","Y")
		WHEN "--no-ansi-warn"		call aclfgl_setenv("A4GL_ANSI_WARN","N")
		WHEN "--no-ansi-error"		call aclfgl_setenv("A4GL_ANSI_ERROR","N")

	END CASE


	if lv_arg matches "--sqltype=*"	then
			let mv_sqltype=lv_arg
			# Skip the "--sqltype=*"		
			let mv_sqltype=mv_sqltype[11, 255]
			#display "A4GL_SQLTYPE=",mv_sqltype clipped
			call aclfgl_setenv("A4GL_SQLTYPE",mv_sqltype clipped)
		continue for
	end if


	# If we get to here its either a compile option thats not recognised or
	# its a filename...

	if lv_arg matches "-Wl,*" then
		let mv_link_opts=mv_link_opts clipped," ",lv_arg
		continue for
	end if
	if lv_arg matches "-Wall" then
		let mv_compile_c_opts=mv_compile_c_opts clipped," ",lv_arg
		let mv_compile_pec_opts=mv_compile_pec_opts clipped," ",lv_arg
		continue for
	end if

	if lv_arg matches "-I*" then
		if lv_arg="-I" then
			LET a=a+1
			let lv_arg="-I",arg_val(a)
		end if
		let mv_include=mv_include clipped," ",lv_arg
   		if mv_verbose>=5 then
   			display "Setting mv_include because of a -I ",mv_include clipped
   		end if
		continue for
	end if


	if lv_arg = "-fPIC" then
		let mv_compile_c_opts=mv_compile_c_opts clipped," -fPIC"
		continue for
	end if


	if lv_arg MATCHES "-D*" then
		if lv_arg="-D" then
			LET a=a+1
			let mv_compile_c_opts=mv_compile_c_opts clipped," -D ",arg_val(a)
		else
			let mv_compile_c_opts=mv_compile_c_opts clipped," ",lv_arg
		end if
		continue for
	end if

	if lv_arg matches "-l*"  then
		if lv_arg="-l" then
			LET a=a+1
			let lv_arg="-l",arg_val(a)
		end if
		let mv_libs=mv_libs clipped," ",lv_arg
		continue for
	end if

	if lv_arg matches "-L*" then
		if lv_arg="-L" then
			LET a=a+1
			let lv_arg="-L",arg_val(a)
		end if
		let mv_libs=mv_libs clipped," ",lv_arg
		continue for
	end if

	

#display "lv_arg=",lv_arg clipped

	let lv_type=generate_ext("LIB")
	IF lv_arg matches "*.a" or lv_arg matches lv_type  # Its a library
	   or lv_arg matches "*.aox" then 
		let mv_libs=mv_libs clipped," ",lv_arg
		continue for
	END IF

	let lv_type=generate_ext("DLL")
	if lv_arg matches "*.so" or lv_arg matches lv_type then # Its a library
		let mv_libs=mv_libs clipped," ",lv_arg
		continue for
	end if

	let lv_type=generate_ext("OBJ")
	if lv_arg matches "*.o" 
	   or lv_arg matches "*.4go" 
	   or lv_arg matches "*.4pe" 
	   or lv_arg matches "*.ao" 
	   or lv_arg matches lv_type then
		call add_obj(lv_arg)
		continue for
	end if

	let lv_type=generate_ext("EC")

	if lv_arg matches "*.ec" 
	   or lv_arg matches "*.cpc" 
	   or lv_arg matches lv_type
	   or lv_arg matches "*.pgc" then # Its an esql/c module

		CALL make_into(lv_arg,"EC",mv_stage) 
		continue for
	end if

	let lv_type=generate_ext("SRCFORM")
	if lv_arg matches "*.per" or lv_arg matches lv_type then # Its a form
		CALL make_into(lv_arg,"PER","FRM") 
		continue for
	end if
		
	let lv_type=generate_ext("4GL")
	if lv_arg matches "*.4gl" or lv_arg matches lv_type then # Its a 4GL
		CALL make_into(lv_arg,"4GL",mv_stage) 
		continue for
	end if

	if lv_arg matches "*.menu"  then # Its a menu
		continue for
	end if

	let lv_type=generate_ext("C")
	if lv_arg matches "*.c"  # Its a C file
	   or lv_arg matches lv_type then
		CALL make_into(lv_arg,"C",mv_stage) 
		continue for
	end if

	let lv_type=generate_ext("MSG")
	if lv_arg matches "*.msg" or lv_arg matches lv_type 
	   or lv_arg matches "*.hlp" then # Its a help file
		CALL make_into(lv_arg,"MSG","IEM") 
		continue for
	end if


	display "WARNING : ",lv_arg clipped," not recognised - passing to C-compiler/Linker"
	#call usg()
   end for


if mv_lextype="WRITE" then
	if fgl_getenv("A4GL_PACKER") matches "XML*" then
		let mv_stage="XML"
	else
		let mv_stage="MIF"
	end if
end if

   if mv_verbose>=3 then
   	display ""
   	display "Generate a ",mv_stage
   end if


   if mv_stage="EXE" or mv_stage="DLL" or mv_stage="LIB" THEN
	if mv_stage matches "DLL" THEN
		let mv_make_dll=1
		if mv_output matches "*.*" then
	
			call run_link(mv_output)
		else
			let lv_output=get_fname(mv_output,"DLL")
			call run_link(lv_output)
		end if
	END IF

	IF mv_stage="EXE" then
		call run_link(mv_output)
	end if

	IF mv_stage="LIB" then
		call run_link_lib(mv_output)
	end if

   end if

end main



function make_into(lv_fname,lv_from,lv_to)
define lv_fname char(512)
define lv_from,lv_to char(5)
define lv_base char(512)
define lv_new char(512)
define lv_new2 char(512)
LET lv_base=lv_fname

if mv_verbose>=4 then 
display "Make into ",lv_fname clipped ," from=",lv_from clipped, " to=",lv_to clipped
end if
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

if mv_lextype is null then
	display "LEXTYPE IS NULL!"
	exit program 1
end if

IF lv_from="4GL"  THEN
	IF lv_to="EXE" or lv_to="DLL" THEN 
		CALL make_into(lv_fname,"4GL","OBJ")
		RETURN
	END IF


	IF lv_to="C" and mv_lextype="EC" THEN
		# We want a preprocessed EC not a -> C
		CALL make_into(lv_fname,"4GL","EC")
		LET lv_new=get_fname(lv_base,"EC")
		call run_4glc(lv_fname,lv_new,lv_base)
		call make_into(lv_new,"EC","PEC")
		RETURN
	END IF


	if lv_to is null or lv_to=" " then
		if mv_compile_c="no" and mv_compile_pec="no" then
			let lv_to=fgl_getenv("A4GL_LEXTYPE")
		else
			let lv_to="OBJ"
		end if
	end if

	CASE lv_to
		WHEN "C"
			LET lv_new=get_fname(lv_base ,"C")
			call run_4glc(lv_fname,lv_new,lv_base)
			RETURN

		WHEN "EC"
			
			LET lv_new=get_fname(lv_base ,"EC")
			call run_4glc(lv_fname,lv_new,lv_base)
			RETURN

		WHEN "OBJ"
			IF mv_lextype="EC" THEN
					
				call make_into(lv_fname,"4GL","EC")
				LET lv_new=get_fname(lv_base ,"EC")
				LET lv_new2=get_fname(lv_base ,"OBJ")
				call make_into(lv_new,"EC","OBJ")

				if mv_keep=0 then
					call remove_file_of_type(lv_base,"EC")
					call remove_file_of_type(lv_base,"C")
				end if
			ELSE
				call make_into(lv_fname,"4GL","C")
				LET lv_new=get_fname(lv_base ,"C")
				LET lv_new2=get_fname(lv_base ,"OBJ")
				call make_into(lv_new,"C","OBJ")

				if mv_keep=0 then
					call remove_file_of_type(lv_base,"C")
				end if
			END IF

		WHEN "MIF"
			# 4GL -> Data file
			call run_4glc_mif(lv_fname,lv_new,lv_base)
			
		WHEN "XML"
			# 4GL -> XML Data file
			call run_4glc_xmlmif(lv_fname,lv_new,lv_base)

		WHEN "SPL"
			# 4GL -> Stored procedure SQL file
			call run_4glc(lv_fname,lv_new,lv_base)

		OTHERWISE
			display "Unhandled compilation : FROM=",lv_from," TO=",lv_to," for ",lv_fname
			if mv_noerrcode=0 then
				exit program 2
			else
				exit program 
			end if
	END CASE
	RETURN
END IF


IF lv_from="C" and lv_to="OBJ" THEN
	LET lv_new=get_fname(lv_base,"OBJ")
	CALL run_compile(lv_fname,lv_new,lv_base)
	RETURN
END IF

IF lv_from="EC" and lv_to="PEC" THEN
	LET lv_new=get_fname(lv_base ,"C")
	CALL run_esql_prec(lv_fname,lv_new,lv_base)
	RETURN
END IF

IF lv_from="EC" and lv_to="OBJ" THEN
	IF mv_esql_to_c_first THEN
if mv_verbose>=4 then display "C FIRST" end if
		LET lv_new=get_fname(lv_base ,"C")
		CALL make_into(lv_fname,"EC","PEC")
		LET lv_new=get_fname(lv_base ,"C")
		CALL make_into(lv_new,"C","OBJ")
	ELSE
if mv_verbose>=4 then display "STRAIGHT TO OBJ - NO C FIRST" end if
		LET lv_new=get_fname(lv_base,"OBJ")
		CALL run_compile_esql(lv_fname,lv_new,lv_base)
	END IF

	RETURN
END IF



IF (lv_to="EXE" OR lv_to="DLL") and lv_from in ("EC","C") THEN
	# We need to get these to object code instead of EXE
	CALL make_into(lv_fname,lv_from,"OBJ")
	RETURN
END IF

IF lv_from="PER" and lv_to="FRM" then
	call run_compile_form(lv_fname)
	RETURN
end if

display "Unhandled Compile ",lv_fname clipped," From ",lv_from," to ",lv_to

if mv_noerrcode=0 then
	exit program 2
else
	exit program 
end if

end function


################################################################################
function usg()
	call show_help(1)
end function


################################################################################
function show_help(lv_n)
define lv_n integer
define filename char(128)
define lv_char integer
define lv_msgline char(256)

let filename=fgl_getenv("AUBITDIR"),"/etc/4glpc.hlp"
call aclfgl_openiem(filename,lv_n) returning lv_char,lv_msgline

if lv_char then
code
A4GL_trim(lv_msgline);
printf("%s\n",lv_msgline);
endcode
        while lv_char!=0
                call aclfgl_fetchiem() returning lv_char,lv_msgline
                if lv_char!=0 then
code
A4GL_trim(lv_msgline);
printf("%s\n",lv_msgline);
endcode
                end if

        end while
else
	display "ERROR: failed to open ",filename clipped
	exit program 2
end if
if lv_n !=1 then
	exit program 0
else
	if mv_noerrcode=0 then
		exit program 2
	else
		exit program 
	end if
end if
end function



################################################################################
function show_version(lv_type)
define lv_type integer
if lv_type=2 then
	display "4glpc v0.8 (c) 2005-2006 Aubit Computing Ltd"
	exit program 0
end if
if lv_type=0 then
	call runit("4glc --version")
else
	call runit("4glc --version_full")
end if
exit program 0
end function


################################################################################
function runit(lv_str)
define lv_str char(10240)

RUN lv_str clipped

end function

################################################################################
function generate_ext(lv_otype)
define lv_otype,lv_type char(200)
let lv_type=lv_otype
let lv_type="A4GL_",lv_type clipped,"_EXT"
let lv_type=fgl_getenv(lv_type)

if lv_type is null or lv_type matches " " then
	LET lv_type="*.",lv_otype
else
	let lv_type="*",lv_type
end if

if mv_verbose>=4 then
	display "Generating extention for ",lv_otype clipped, " gives ",lv_type clipped
end if
return lv_type
end function


function get_ext(lv_otype)
define lv_otype,lv_type char(200)
let lv_type=lv_otype
let lv_type="A4GL_",lv_type clipped,"_EXT"
let lv_type=fgl_getenv(lv_type)

if lv_type is null or lv_type matches " " then
	LET lv_type=".",downshift(lv_otype)
else
	let lv_type=lv_type
end if

return lv_type
end function


################################################################################

function run_4glc(lv_fname,lv_new,lv_base)
define lv_fname char(512)
define lv_new char(512)
define lv_base char(512)
define lv_runstr char(10000)
define lv_status integer


if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times for ",lv_fname clipped, " and ",lv_new clipped
	end if
	if compare_file_times(lv_fname,lv_new) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_new clipped, " is newer than ",lv_fname clipped
		end if
		return
	end if
end if

#
# Lets force the output filename to be what we're expecting it to
# be - this gets around any issues with 'A4GL_LOCALOUTPUT' when
# in a different directory
#


if mv_verbose>=2 then
	display "Compiling ",lv_fname clipped
	display "Hopefully generating : ", lv_base
end if

let lv_runstr=mv_compile_4gl clipped, " ",mv_compile_4gl_opts clipped

if mv_stacktrace is not null then
	let lv_runstr=lv_runstr clipped," -s",mv_stacktrace
end if

if mv_make_globals then
	let lv_runstr=lv_runstr clipped," -G"
end if

if mv_verbose>1 then
	let lv_runstr=lv_runstr clipped, " -V"
end if

if mv_db is not null and mv_db not matches " " then
	let lv_runstr=lv_runstr clipped, " -d ",mv_db
end if

if mv_namespace is not null then
	let lv_runstr=lv_runstr clipped ," -N '",mv_namespace clipped,"'"
end if


if mv_lextype is not null then
	call aclfgl_setenv("A4GL_LEXTYPE",mv_lextype clipped)
end if

if mv_keep!=-1 then
	if mv_keep=1 then
		let lv_runstr=lv_runstr clipped ," -k"
	else
		let lv_runstr=lv_runstr clipped ," -K"
	end if
end if

if mv_system4gl then
	let lv_runstr=lv_runstr clipped," --system4gl"
end if

let mv_errfile=lv_base clipped,get_ext("ERR")
let mv_warnfile=lv_base clipped,get_ext("WARN")


let lv_runstr=lv_runstr clipped," ",lv_fname clipped
#," 2> ",mv_errfile

if mv_verbose>=2 then
	display lv_runstr clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr CLIPPED RETURNING lv_status

call check_exit_status(lv_status,lv_fname,lv_runstr)

end function


function run_4glc_xmlmif(lv_fname,lv_new,lv_base)
define lv_fname char(512)
define lv_new char(512)
define lv_base char(512)
define lv_runstr char(10000)
define lv_status integer


if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times for ",lv_fname clipped, " and ",lv_new clipped
	end if
	if compare_file_times(lv_fname,lv_new) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_new clipped, " is newer than ",lv_fname clipped
		end if
		return
	end if
end if

#
# Lets force the output filename to be what we're expecting it to
# be - this gets around any issues with 'A4GL_LOCALOUTPUT' when
# in a different directory
#


if mv_verbose>=2 then
	display "Compiling ",lv_fname clipped
	display "Hopefully generating : ", lv_base
end if

if mv_output!=" " then
	let lv_runstr="OVERRIDE_PACKER_OUTPUT=",mv_output
end if
if fgl_getenv("A4GL_PACKER") matches "*XML*" then
	let lv_runstr=lv_runstr clipped," ",mv_compile_4gl clipped, " ",mv_compile_4gl_opts clipped
else
	let lv_runstr=lv_runstr clipped," A4GL_PACKER=XML ",mv_compile_4gl clipped, " ",mv_compile_4gl_opts clipped
end if

if mv_stacktrace is not null then
	let lv_runstr=lv_runstr clipped," -s",mv_stacktrace
end if

if mv_make_globals then
	let lv_runstr=lv_runstr clipped," -G"
end if

if mv_verbose>1 then
	let lv_runstr=lv_runstr clipped, " -V"
end if

if mv_db is not null and mv_db not matches " " then
	let lv_runstr=lv_runstr clipped, " -d ",mv_db
end if

if mv_namespace is not null then
	let lv_runstr=lv_runstr clipped ," -N '",mv_namespace clipped,"'"
end if


if mv_lextype is not null then
	call aclfgl_setenv("A4GL_LEXTYPE",mv_lextype clipped)
end if



let lv_runstr=lv_runstr clipped," ",lv_fname clipped

if mv_verbose>=2 then
	display lv_runstr clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr CLIPPED RETURNING lv_status

call check_exit_status(lv_status,lv_fname,lv_runstr)

end function


function run_4glc_mif(lv_fname,lv_new,lv_base)
define lv_fname char(512)
define lv_new char(512)
define lv_base char(512)
define lv_runstr char(10000)
define lv_status integer


if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times for ",lv_fname clipped, " and ",lv_new clipped
	end if
	if compare_file_times(lv_fname,lv_new) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_new clipped, " is newer than ",lv_fname clipped
		end if
		return
	end if
end if

#
# Lets force the output filename to be what we're expecting it to
# be - this gets around any issues with 'A4GL_LOCALOUTPUT' when
# in a different directory
#


if mv_verbose>=2 then
	display "Compiling ",lv_fname clipped
	display "Hopefully generating : ", lv_base
end if

if mv_output!=" " then
	let lv_runstr="OVERRIDE_PACKER_OUTPUT=",mv_output
end if
let lv_runstr=lv_runstr clipped," A4GL_PACKER=PACKED ",mv_compile_4gl clipped, " ",mv_compile_4gl_opts clipped

if mv_stacktrace is not null then
	let lv_runstr=lv_runstr clipped," -s",mv_stacktrace
end if

if mv_make_globals then
	let lv_runstr=lv_runstr clipped," -G"
end if

if mv_verbose>1 then
	let lv_runstr=lv_runstr clipped, " -V"
end if

if mv_db is not null and mv_db not matches " " then
	let lv_runstr=lv_runstr clipped, " -d ",mv_db
end if

if mv_namespace is not null then
	let lv_runstr=lv_runstr clipped ," -N '",mv_namespace clipped,"'"
end if


if mv_lextype is not null then
	call aclfgl_setenv("A4GL_LEXTYPE",mv_lextype clipped)
end if



let lv_runstr=lv_runstr clipped," ",lv_fname clipped

if mv_verbose>=2 then
	display lv_runstr clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr CLIPPED RETURNING lv_status

call check_exit_status(lv_status,lv_fname,lv_runstr)

end function





################################################################################
function check_exit_status(p_status,p_filename,p_runstr)
define p_status integer
define p_filename char(512)
define p_runstr char(10240)
define lv_runstr char(10240)
define lv_errsize integer

#call remove_file(mv_warnfile)

if p_status<0 then
	let p_status=1
end if

if p_status > 255 then
	let p_status=p_status/256
end if

if mv_verbose>4 then
	display "Status : ",p_status
end if

IF file_exists(mv_errfile) THEN
	let lv_errsize=file_size(mv_errfile)
ELSE
	LET lv_errsize=0
END IF

if lv_errsize<0 and p_status=0 then
	if mv_verbose>4 then
		display "Error - unable to find the size of the error file (",mv_errfile clipped,")"
	end if
	return
end if

if lv_errsize>0 then
	if p_status=0 then
		display "Warning : Error file is not empty - but I got no error"
		if mv_verbose>4 then
			call head_file(mv_errfile,55)
		end if
		#display "mv_errfile=",mv_errfile
		#display "mv_warnfile=",mv_warnfile
		if  not rename_file(mv_errfile,mv_warnfile) then
			display "Error : unable to copy ",mv_errfile clipped, " to ", mv_warnfile
			let p_status=1 # fake an exit status so the .err is not removed
		else
			display "Check ", mv_warnfile clipped, " for details"
		end if
	end if
end if


if p_status=0 then 
	call remove_file(mv_errfile)
	return 
end if

display "Error compiling ",p_filename clipped
if mv_verbose>=1 then
	display "while executing ", p_runstr clipped
end if

if mv_show_errtail then
	call tail_file(mv_errfile,12);
end if

if mv_noerrcode=0 then
	display "Exit program..",p_status
	exit program p_status
else
	display "Exit program.."
	exit program
end if

end function

################################################################################
function run_esql_prec(lv_fname,lv_new,lv_base)
define lv_fname char(512)
define lv_new char(512)
define lv_base char(512)
define lv_runstr char(10240)
define lv_status integer

if mv_verbose>=1 then
	DISPLAY "ESQL_PREC     :",lv_fname clipped," ",lv_new clipped
end if

if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times"
	end if
	if compare_file_times(lv_fname,lv_new) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_new clipped, " is newer than ",lv_fname clipped
		end if
		return
	end if
end if

if 0 then
let mv_errfile=lv_base clipped,get_ext("ERR")
let mv_warnfile=lv_base clipped,get_ext("WARN")
let lv_runstr=mv_preprocess clipped," ",mv_preprocess_opts clipped," ",mv_include clipped," -o ",lv_new clipped, " ",lv_fname clipped ," 2> ",mv_errfile
else
let mv_warnfile=lv_base clipped,get_ext("WARN")
let mv_errfile=lv_base clipped,get_ext("ERR")
let lv_runstr=mv_preprocess clipped," ",mv_preprocess_opts clipped," ",lv_fname clipped ," 2> ",mv_errfile
end if

if mv_verbose>=2 then
	display lv_runstr clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr CLIPPED RETURNING lv_status
call check_exit_status(lv_status,lv_fname,lv_runstr)
end function



################################################################################
function run_compile(lv_fname,lv_new,lv_base)
define lv_fname char(512)
define lv_new char(512)
define lv_base char(512)
define lv_runstr char(10240)
define lv_compile_c_opts char(512)
define lv_status integer

if mv_verbose>=2 then
	DISPLAY "RUN_COMPILE     :",lv_fname clipped," ",lv_new clipped
end if


if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times"
	end if
	if compare_file_times(lv_fname,lv_new) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_new clipped, " is newer than ",lv_fname clipped
		end if
		call add_obj(lv_new)
		return
	end if
end if

let mv_errfile=lv_base clipped,get_ext("ERR")
let mv_warnfile=lv_base clipped,get_ext("WARN")
if mv_verbose>=4 then
	display "compile_c=",mv_compile_c clipped
	display "compile_c_opts=",mv_compile_c_opts clipped
	display "include=",mv_include clipped
end if

let lv_compile_c_opts=mv_compile_c_opts


#if mv_compile_c="esql" then
	#let lv_compile_c_opts=mv_compile_c_opts clipped," -I",fgl_getenv("INFORMIXDIR") clipped,"/incl"
#end if
#if mv_compile_c="ecpg_wrap" then
	#let lv_compile_c_opts=mv_compile_c_opts clipped," -I/usr/local/pgsql/include"
#end if

let lv_runstr=mv_compile_c clipped," ",lv_compile_c_opts clipped," "

if mv_debug then
	let lv_runstr=lv_runstr clipped," ",mv_compile_c_debug
end if

let lv_runstr=lv_runstr clipped, " ",mv_include clipped," -o ",lv_new clipped,
		" -c ",lv_fname clipped," 2> ",mv_errfile

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)

if mv_verbose>=2 then
	display "Running : ",lv_runstr clipped
end if


RUN lv_runstr CLIPPED RETURNING lv_status
call check_exit_status(lv_status,lv_fname,lv_runstr)

call add_obj(lv_new)
end function



################################################################################
function run_compile_esql(lv_fname,lv_new,lv_base)
define lv_fname char(512)
define lv_new char(512)
define lv_base char(512)
define lv_runstr char(10240)
define lv_status integer

if mv_makecompile then
        if mv_verbose>=3 then
                display "Make Compile - checking file times"
        end if
        if compare_file_times(lv_fname,lv_new) then
                if mv_verbose>=2 then
                        display "Make Compile specified - file skipped as ",lv_new clipped, " is newer than ",lv_fname clipped
                end if
                call add_obj(lv_new)
                return
        end if
end if

if mv_verbose>2 then
DISPLAY "RUN_COMP_ESQL :",lv_fname clipped," ",lv_new clipped
end if


let mv_warnfile=lv_base clipped,get_ext("WARN")
let mv_errfile=lv_base clipped,get_ext("ERR")

let lv_runstr=mv_compile_pec clipped," ",mv_compile_pec_opts clipped

if mv_debug then
	let lv_runstr=lv_runstr clipped," -g "
end if

IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
	let lv_fname=get_basename(lv_fname)
END IF

let lv_runstr=lv_runstr clipped ," ",mv_include clipped," -o ",lv_new clipped, " -c ",lv_fname clipped," 2> ",mv_errfile
if mv_verbose>=2 then
        display lv_runstr clipped
end if


let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr clipped RETURNING lv_status
call check_exit_status(lv_status,lv_fname,lv_runstr)
call add_obj(lv_new)
end function

function run_compile_form(lv_fname)
define lv_runstr char(1045)
define lv_status integer
define lv_fname char(256)
let lv_runstr="fcompile " 
IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
	let lv_fname=get_basename(lv_fname)
END IF

let lv_runstr=lv_runstr clipped ," ",lv_fname clipped
if mv_verbose>=2 then
        display lv_runstr clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr clipped RETURNING lv_status

call check_exit_status(lv_status,lv_fname,lv_runstr)

end function

################################################################################
function run_link(lv_output)
define lv_status integer
define  lv_output char(512)
define lv_runstr char(10240)

if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times"
	end if
	if compare_file_times(mv_newest_obj,lv_output) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_output clipped, " is newer than ",mv_newest_obj clipped
		end if
		return
	end if
end if



let mv_warnfile=lv_output clipped,get_ext("WARN")
let mv_errfile=lv_output clipped,get_ext("ERR")

let lv_runstr=mv_link

if mv_make_dll then
	let lv_runstr=lv_runstr clipped," ",mv_dll_opts
end if

if mv_static then
	let lv_runstr=lv_runstr clipped, " -static" 
end if

if mv_debug then
	let lv_runstr=lv_runstr clipped," ",mv_link_debug
end if

if mv_verbose>=5 then
	display "mv_objects  =",mv_objects clipped
	display "lv_output   =",lv_output clipped
	display "mv_libs     =",mv_libs clipped
	display "mv_link     =",mv_link clipped
	display "mv_link_libs=",mv_link_libs clipped
	display "mv_link_opts=",mv_link_opts clipped
end if

let lv_runstr=lv_runstr clipped, " ",mv_objects clipped, " -o ",lv_output clipped," ",mv_libs clipped," ",mv_link_libs clipped, " ",mv_link_opts clipped," 2>",mv_errfile clipped

if mv_verbose>=1 then
	display "Linking ",lv_output  clipped
end if

if mv_verbose>=2 then
	display lv_runstr clipped
end if

if mv_verbose>=4 then
	display "OBJECTS       : ",mv_objects clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr CLIPPED RETURNING lv_status

if mv_verbose>=5 then
	display "Ran command"
end if

call check_exit_status(lv_status,lv_output,lv_runstr)

end function


################################################################################
function run_link_lib(lv_output)
define lv_status integer
define  lv_output char(512)
define lv_runstr char(10240)

if mv_makecompile then
	if mv_verbose>=3 then
		display "Make Compile - checking file times"
	end if
	if compare_file_times(mv_newest_obj,lv_output) then
		if mv_verbose>=2 then
			display "Make Compile specified - file skipped as ",lv_output clipped, " is newer than ",mv_newest_obj clipped
		end if
		return
	end if
end if



let mv_warnfile=lv_output clipped,get_ext("WARN")
let mv_errfile=lv_output clipped,get_ext("ERR")

let lv_runstr="rm -f ",lv_output 
RUN lv_runstr CLIPPED RETURNING lv_status
let lv_runstr="ar rc ",lv_output clipped, " ", mv_objects

if mv_verbose>=1 then
	display "Archiving ",lv_output  clipped
end if
if mv_verbose>=2 then
	display lv_runstr clipped
end if
if mv_verbose>=4 then
	display "OBJECTS       : ",mv_objects clipped
end if

let lv_runstr=aclfgl_expand_env_vars_in_cmdline(lv_runstr)
RUN lv_runstr CLIPPED RETURNING lv_status

if mv_verbose>=5 then
	display "Ran command"
end if
call check_exit_status(lv_status,lv_output,lv_runstr)

RUN lv_runstr CLIPPED RETURNING lv_status
let lv_runstr="ranlib ",lv_output clipped

if mv_verbose>=2 then
	display lv_runstr clipped
end if

RUN lv_runstr CLIPPED RETURNING lv_status

if mv_verbose>=5 then
	display "Ran command"
end if
call check_exit_status(lv_status,lv_output,lv_runstr)



end function




function add_obj(lv_obj)
define lv_obj char(256)
define lv_chk char(255)

# Check to see if we've already added this object
let lv_chk="* ",lv_obj clipped," *"

if mv_objects matches lv_chk then
	# Its already in our list...
	return
end if

let lv_chk="* ",lv_obj

if mv_objects matches lv_chk then
	# Its already in our list...
	return
end if



	if mv_verbose>=5 then
		DISPLAY "ADD OBJ : ",lv_obj clipped
	end if
	LET mv_objects=mv_objects clipped," ",lv_obj

	if mv_newest_obj is null then
		let mv_newest_obj=lv_obj
		return
	end if

	if compare_file_times(mv_newest_obj,lv_obj) then
		let mv_newest_obj=lv_obj
	end if
end function


function rename_file(m1, m2)
define m1 char(255)
define m2 char(255)
define lv_str char(1000)
define a integer
code
{
A4GL_trim(m1);
A4GL_trim(m2);
a=A4GL_move_file(m1,m2);
}
endcode


return a

end function



function tail_file(mv_file,n)
define mv_file char(512)
define n integer
define a integer
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
end function

function head_file(mv_file,n)
define mv_file char(512)
define n integer
define a integer
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
end function

function file_exists(s)
define s char(512)
define a integer
code
{
A4GL_trim(s);
a=A4GL_file_exists(s);
}
endcode
return a
end function

function file_size(s)
define s char(512)
define l integer
let l=-1
code
{
A4GL_trim(s);
l=A4GL_file_length(s);
}
endcode
return l
end function


function remove_file(s)
define s char(512)
code
{
A4GL_trim(s);
A4GL_delete_file(s);
}
endcode
end function


function verbosity()
return mv_verbose
end function

code
int isverbose_c(int n) {
	return mv_verbose>n;
}
endcode


function isverbose(n)
define n integer
if mv_verbose>=n then
	return 1
else
	return 0
end if
end function

function get_basename(lv_fname)
define lv_fname char(256)
define a integer
for a=length(lv_fname) to 1 step -1
	if lv_fname[a]="/" or lv_fname[a]="\\" then
		return lv_fname[a+1,256]
	end if
end for
return lv_fname
end function


function get_fname(lv_base,lv_ext_type) 
define lv_base char(256)
define lv_ext_type char(10)
define lv_new char(256)
if mv_verbose>=5 then 
	display "lv_ext_type=",lv_ext_type clipped," base=",lv_base clipped," otype=",mv_output_type clipped, " output=",mv_output clipped
end if


if lv_ext_type=mv_output_type then
if mv_verbose>3 then
	display "We're producing final output, mv_output=", mv_output
end if
	if mv_output="" or mv_output is null then
		LET lv_new=lv_base clipped,get_ext(lv_ext_type)
		IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
			# Trim off any leading path - it'll be dumped in the local directory
			let lv_new=get_basename(lv_new)
		END IF
	else
		LET lv_new=mv_output
	end if
else
	LET lv_new=lv_base clipped,get_ext(lv_ext_type)
	IF fgl_getenv("A4GL_LOCALOUTPUT")="Y" THEN
		# Trim off any leading path - it'll be dumped in the local directory
		let lv_new=get_basename(lv_new)
	END IF
end if 


return lv_new
end function

FUNCTION  remove_file_of_type(lv_fname,lv_type)
define lv_fname char(256)
define lv_type CHAR(10 )

IF mv_keep!=0 THEN
	return
END IF


IF lv_type="C" THEN
	#  DELETE THE INTERMEDIATE FILES...
	CALL remove_file(get_fname(lv_fname clipped,"C"))
	CALL remove_file(get_fname(lv_fname clipped,"H"))
END IF

IF lv_type="EC" THEN
	#  DELETE THE INTERMEDIATE FILES...
	CALL remove_file(get_fname(lv_fname clipped,"EC"))
	CALL remove_file(get_fname(lv_fname clipped,"H"))
END IF
END FUNCTION


function isyes(s) 
define s char(20)
if upshift(s[1]) = "Y" or s="1" or  upshift(s)="TRUE" then
	return 1
else
	return 0
end if
end function

