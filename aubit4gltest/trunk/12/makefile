
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

