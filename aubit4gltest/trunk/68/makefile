
all4ae: dtblank.4gl
#	(export A4GL_LEXTYPE=C; 4glpc dtblank.4gl -o dtblank_i.4ae)
#	(export A4GL_LEXTYPE=EC; export A4GL_LEXDIALECT=INFORMIX;4glpc dtblank.4gl -o dtblank_iec.4ae)
#	(export A4GL_LEXTYPE=EC; export A4GL_LEXDIALECT=POSTGRES;4glpc dtblank.4gl -o dtblank_pec.4ae)
	4glpc dtblank.4gl -o dtblank.4ae
	
compile: all4ae
	
run: compile
	sh ./run_dtblank
