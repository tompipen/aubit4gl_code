# For help on using / editing this makefile, please see the fully documented
# version of it in template/makefile-described

include ${MAKEFILE_COMMON}
FORMS=	${PER:.per=${A4GL_FORMEXT}}
MODULES=${FGL:.4gl=${OBJ_EXT}}
HELP=	${MSG:.msg=${HLP_EXT}}
A4GL_KEYFILE=keys.in
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

desc: ; @echo "ENTER not working in PAUSE if MENU is active. MID 979"

db_test: 				; @echo "0"
ec_test: 				; @echo "0"
nosilent_test:			; @echo "0"
tui_test:				; @echo "1"
form_test:				; @echo "0"
report_test:			; @echo "1"
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
sql_features_used:		; @echo "UI_MENU EXIT_MENU DEFINE_INTEGER USE_REPORT FOR ON_EVERY_ROW REPORT_PAGE_TRAILER"
ansi_sql_compat:		; @echo ""
runtime_err_check:		; @echo ""
need_rdbms:				; @echo ""
need_plugin:			; @echo ""


# ============================= EOF ================================
