

t.4ae: t.4gl
	$(FGLC) t.4gl -o t.4ae
	fcompile t.per

compile: t.4ae
	
run: t.4ae
	sh ./run_t
	
clean:
	rm -f t.out.nodate
	

ansi_sql_compat:
	@echo "0"

sql_features_used:
	@echo "CREATE_TEMP_TABLE"

