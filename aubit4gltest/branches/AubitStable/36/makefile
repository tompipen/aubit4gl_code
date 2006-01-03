#temp_ec.4ae: temp.4gl 
#	A4GL_LEXTYPE=EC $(FGLC) temp.4gl -o temp_ec.4ae
temp.4ae: temp.4gl 
	$(FGLC) $< -o $@

#temp_c.4ae: temp.4gl 
#	A4GL_LEXTYPE=C $(FGLC) temp.4gl -o temp_c.4ae
	
#compile: temp_ec.4ae  temp_c.4ae
compile: temp.4ae
	
#run: temp_ec.4ae temp_c.4ae
run: temp.4ae
	sh ./run_temp
db_test:
	 @echo "1"

ansi_sql_compat:
	@echo "0"

desc:
	@echo "Test a foreach when an open has already been done"
	
sql_features_used:
	@echo "CREATE_TEMP_TABLE CLOSE_CURSOR DROP_TABLE"
	
