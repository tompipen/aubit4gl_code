{
	WHATSTR
	@(#)Built by: FGLBLDSTR
	@(#)Report code for SPI on Xtable
}

DATABASE Xdbase

GLOBALS "Xformg.4gl"

{ Module variables -- not accessible outside this file }
DEFINE
	sccs		CHAR(1)	{ Identifier string }

#Xopt_rep{ Choose report option }
#Xopt_repFUNCTION rch_xtable()
#Xopt_rep
#Xopt_rep	DEFINE
#Xopt_rep		choice	CHAR(1),
#Xopt_rep		n		INTEGER
#Xopt_rep
#Xopt_rep	LET sccs = "WHATSTR"
#Xopt_rep	LET INT_FLAG = FALSE
#Xopt_rep
#Xopt_rep	LET n = Xcnt_key(ct_xtable.list_number)
#Xopt_rep	LET choice = report_type(ct_xtable.query_done, ct_xtable.rep_query, n)
#Xopt_rep
#Xopt_rep	IF choice = 'Q' THEN
#Xopt_rep		IF rnq_xtable() = FALSE THEN
#Xopt_rep			LET choice = 'E'
#Xopt_rep		ELSE
#Xopt_rep			LET choice = 'R'	{ Re-use enquiry just set up }
#Xopt_rep		END IF
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	RETURN choice
#Xopt_rep
#Xopt_repEND FUNCTION {rch_xtable}
#Xopt_rep
#Xopt_repFUNCTION rln_xtable(rdest, i, pkey)
#Xopt_rep
#Xopt_rep	DEFINE
#Xopt_rep		rdest		INTEGER,
#Xopt_rep		i			INTEGER,
#Xopt_rep		pkey		Xpktype,
#Xopt_rep		retval		INTEGER
#Xopt_rep
#Xopt_rep	LET retval = FALSE
#Xopt_rep	IF INT_FLAG THEN
#Xopt_rep		ERROR "Interrupt detected -- report abandoned"
#Xopt_rep	ELSE
#Xopt_rep		IF rdest != 0 AND i MOD 10 = 0 THEN
#Xopt_rep			MESSAGE "Processing row ", i USING "<<<<"
#Xopt_rep		END IF
#Xopt_rep		IF get_xtable(pkey) = 0 THEN
#Xopt_rep			OUTPUT TO REPORT rpf_xtable(wr_xtable.*)
#Xopt_rep			LET retval = TRUE
#Xopt_rep		END IF
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	RETURN retval
#Xopt_rep
#Xopt_repEND FUNCTION {rln_xtable}
