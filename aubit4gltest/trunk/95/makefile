

m1.4ae: m1.4gl
	$(FGLC) m1.4gl -o m1.4ae

compile: m1.4ae
	
run: m1.4ae
	sh ./run_m1
	
	
desc:
	@echo "Old makefile"
	
################
#If database this test runs against MUST have transactions support, set to "1"
#If database this test runs against MUST NOT have transactions support, set to "2"
#"0" means "don't care"
transaction:
	@echo "2"
db_test:
	@echo "1"

ansi_sql_compat:
	@echo "0"




cert_test:
	@echo "1"

