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
run: compile ; ${DEFAULT_DIFF}
# ${DEFAULT_DUMP_DIFF}
# ${DEFAULT_RUN}
#	

## ======================================================================
##                  Test desctiptions
## ======================================================================

desc: ; @echo "declare.. into..  fetch (no var)";


db_test: 				; @echo "1"
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
sql_features_used:		; @echo "CREATE_TEMP_TABLE ANSI_INSERT CURSOR_SELECT  DEFINE_CHAR DEFINE_INTEGER FOREACH UI_DISPLAY_LINE_MODE DISPLAY"
ansi_sql_compat:		; @echo ""
runtime_err_check:		; @echo ""
need_rdbms:				; @echo ""
need_plugin:			; @echo ""


# ============================= EOF ================================

