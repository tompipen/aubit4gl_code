
prog.4ae: prog.4gl
	$(FGLC) prelude.4gl -o prelude
	./prelude
	(export A4GL_SYSCOL_VAL=scv; $(FGLC) prog.4gl -o prog.4ae)

compile: prog.4ae
	
run: prog.4ae
	./prog.4ae
	
clean:
	rm -rf prelude
	
