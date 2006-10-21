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

A4GL_INCOMPAT_AT_RUNTIME=YES
export A4GL_INCOMPAT_AT_RUNTIME

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

desc:
	@echo "Test for invalid cursor type & name detection that was causing : \
		Warning - cursor FLUSH was previously thought to be a SELECT cursor \
		but now turns out to be an INSERT cursor.You will need to add \
			PRAGMA EMULATE INSERT CURSOR FOR FLUSH \
		Note that this test explicityly sets A4GL_INCOMPAT_AT_RUNTIME=YES \
		(compiling KL1a.4gl in OneMaxx)"

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
cert_test:				; @echo "1"
compat_test:			; @echo "1"
expect_code:			; @echo "0"
compile_only:			; @echo "1"
unknown_test:			; @echo "0"
need_ifx_version:		; @echo "0"
transaction:			; @echo "0"
sql_features_used:		; @echo "CREATE_TEMP_TABLE ANSI_SELECT INSERT_CURSOR META_TRANSACTION   DEFINE_CHAR PREPARE CURSOR_SELECT ANSI_INSERT BEGIN_WORK OPEN_CURSOR PUT_CURSOR FLUSH ROLLBACK_WORK DEFINE_SMALLINT CURSOR_SELECT_FOR_UPDATE FOREACH COMMIT_WORK"
ansi_sql_compat:		; @echo ""
runtime_err_check:		; @echo ""
need_rdbms:				; @echo ""
need_plugin:			; @echo ""
obsolete_test:			; @echo ""

# ============================= EOF ================================

