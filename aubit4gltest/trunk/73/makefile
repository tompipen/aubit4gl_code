

into.4ae: into.4gl
	@echo "A4GL_SQLTYPE=${A4GL_SQLTYPE}"
	@echo "A4GL_LEXTYPE=${A4GL_LEXTYPE}"
	@echo "A4GL_LEXDIALECT=${A4GL_LEXDIALECT}"
	@aubit-config A4GL_SQLTYPE
	@aubit-config A4GL_LEXTYPE
	@aubit-config A4GL_LEXDIALECT
	$(FGLC) into.4gl -o into.4ae

compile: into.4ae
	
run: into.4ae
	sh ./run_into
	
clean:
	rm -f into.c
