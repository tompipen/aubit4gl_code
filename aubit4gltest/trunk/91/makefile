
put.4ae: put.4gl
	$(FGLC) put.4gl -o put.4ae

compile: put.4ae
	
run: put.4ae
	sh ./run_put
	

desc:
	@echo "Old makefile"
	
	
################
#If database this test runs against MUST have transactions support, set to "1"
#If database this test runs against MUST NOT have transactions support, set to "2"
#"0" means "don't care"
transaction:
	@echo "2"
