# For help on using / editing this makefile, please see the fully documented
# version of it in template/makefile-described

include ${MAKEFILE_COMMON}
FORMS=	${PER:.per=${A4GL_FORMEXT}}
MODULES=${FGL:.4gl=${OBJ_EXT}}
HELP=	${MSG:.msg=${HLP_EXT}}
ifneq "${A4GL_KEYFILE}" ""
	export A4GL_KEYFILE A4GL_KEYDELAY
endif
ADD_CLEAN=

## ======================================================================
##                 	Local Targets
## ======================================================================

progname${TARGET_EXT}: ${MODULES} ; ${DEFAULT_LINK}
compile: progname${TARGET_EXT} ${FORMS} ${HELP}
run: compile ; ${DEFAULT_RUN}
#	${DEFAULT_DIFF} ${DEFAULT_DUMP_DIFF}

## ======================================================================
##                  Test desctiptions
## ======================================================================

desc: ; @echo "This is not a test but a Testing template. Please describe here."

db_test: 				; @echo "0"
ec_test: 				; @echo "0"
nosilent_test:			; @echo "0"
tui_test:				; @echo "0"
form_test:				; @echo "0"
report_test:			; @echo "0"
graphic_test:			; @echo "0"
console_prompt_test:	; @echo "0"
dump_screen_test:		; @echo "0"
long_test:				; @echo "0"
cert_test:				; @echo "0"
obsolete_test:			; @echo "0"
compat_test:			; @echo "0"
expect_code:			; @echo "0"
compile_only:			; @echo "0"
unknown_test:			; @echo "0"
need_ifx_version:		; @echo "0"
transaction:			; @echo "0"
sql_features_used:		; @echo "DATABASE_USED DEFINE_DECIMAL DEFINE_CHAR DDL_DECIMAL SELECT_INTO_TEMP_WITH_NO_LOG CREATE_TEMP_TABLE INSERT_COLUMNLIST_EQ_VALUELIST ANSI_INSERT IF UI_DISPLAY_LINE_MODE DISPLAY EXIT_PROGRAM_EXPR "
ansi_sql_compat:		; @echo ""
runtime_err_check:		; @echo ""
need_rdbms:				; @echo ""
need_plugin:			; @echo ""


# ============================= EOF ================================
