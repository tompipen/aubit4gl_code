

prog.4ae: prog.4gl
	fcompile g1.per
	$(FGLC)  prog.4gl -o prog.4ae
desc:
	@echo "This test exercises the 'scroll' command"

compile: prog.4ae
	
run: prog.4ae
	sh ./run_prog
