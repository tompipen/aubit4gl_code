
dec_round.4ae: dec_round.4gl dec_round2.4gl dec_round3.4gl dec_round4.4gl dec_round5.4gl dec_round6.4gl
	${FGLC} dec_round.4gl -o dec_round.4ae
	${FGLC} dec_round2.4gl -o dec_round2.4ae
	${FGLC} dec_round3.4gl -o dec_round3.4ae
	${FGLC} dec_round4.4gl -o dec_round4.4ae
	${FGLC} dec_round5.4gl -o dec_round5.4ae
	${FGLC} dec_round6.4gl -o dec_round6.4ae

compile: dec_round.4ae dec_round2.4ae dec_round3.4ae dec_round4.4ae dec_round5.4ae dec_round5.4ae
	
run: dec_round.4ae dec_round2.4ae dec_round3.4ae dec_round4.4ae dec_round5.4ae dec_round6.4ae
	sh ./run_dec_round

#Test :  12
#make: *** No rule to make target `dec_round2.4gl', needed by `dec_round.4ae'.  Stop.

ansi_sql_compat:
	@echo "1"
desc:
	@echo "Decimal handling"

sql_features_used:			; @echo "DATABASE_USED DEFINE_LIKE DDL_DECIMAL DDL_DATE DDL_MONEY DDL_DATETIME CREATE_TEMP_TABLE ANSI_INSERT ANSI_DELETE DROP_TABLE DEFINE_CHAR DEFINE_SMALLINT DEFINE_INTEGER DEFINE_FLOAT DEFINE_DECIMAL DEFINE_DATE DEFINE_MONEY DEFINE_DATETIME STATUS IF UI_DISPLAY_LINE_MODE DISPLAY "

