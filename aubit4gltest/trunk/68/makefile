
all4ae: dtblank.4gl
#	(export A4GL_LEXTYPE=C; ${FGLC} dtblank.4gl -o dtblank_i.4ae)
#	(export A4GL_LEXTYPE=EC; export A4GL_LEXDIALECT=INFORMIX;${FGLC} dtblank.4gl -o dtblank_iec.4ae)
#	(export A4GL_LEXTYPE=EC; export A4GL_LEXDIALECT=POSTGRES;${FGLC} dtblank.4gl -o dtblank_pec.4ae)
	${FGLC} dtblank.4gl -o dtblank.4ae
	
compile: all4ae
	
run: compile
	sh ./run_dtblank

ansi_sql_compat:
	@echo "0"

