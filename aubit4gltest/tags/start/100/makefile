
rep.4ae: rep.4gl
	$(FGLC) rep.4gl -o rep.4ae

compile: rep.4ae
	
run: rep.4ae
	sh ./run_rep
	
desc:
	@echo "Old makefile"
	
	
################
#If database this test runs against MUST have transactions support, set to "1"
#If database this test runs against MUST NOT have transactions support, set to "2"
#"0" means "don't care"
transaction:
	@echo "2"
