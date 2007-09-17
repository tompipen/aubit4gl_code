

m1.4ae: m1.4gl
	$(FGLC) m1.4gl -o m1.4ae

compile: m1.4ae
	
run: m1.4ae
	sh ./run_m1
	
	
desc:
	@echo "UPDATE ... WHERE CURRENT OF.."
	
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

sql_features_used:
	@echo "CREATE_TEMP_TABLE SELECT_FOR_UPDATE UPDATE_WHERE_CURRENT_OF  DEFINE_INTEGER DEFINE_CHAR ANSI_INSERT CURSOR_SELECT_FOR_UPDATE CURSOR_SELECT FOREACH UPDATE_COLUMN_EQ_VALUE_LIST ORDER_BY UI_DISPLAY_LINE_MODE DISPLAY  BEGIN_WORK COMMIT_WORK"

