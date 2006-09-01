code
	char *buff=0;
endcode

FUNCTION dump_proc(lv_procname)
DEFINE lv_procname CHAR(64)
DEFINE lv_str CHAR(256)
DEFINE lv_lastproc integer
DEFINE lv_thisproc integer

LET lv_lastproc=-1
LET lv_thisproc=-1


IF upshift(lv_procname)="ALL" THEN
	LET lv_procname="*"
END IF


DECLARE c_get_proc cursor for
	SELECT sp1.procid, data,seqno 
	FROM sysprocedures sp1,sysprocbody sp2  
	WHERE procname matches lv_procname
	AND sp1.procid=sp2.procid
	AND datakey="T"
	ORDER BY sp1.procid,seqno

FOREACH c_get_proc INTO lv_thisproc,lv_str 

	IF lv_lastproc!=lv_thisproc THEN   # dump buff..
		LET lv_lastproc=lv_thisproc
		CALL dump_buff()
	END IF

code
	if (buff) {
		buff=realloc(buff,strlen(buff)+256+1);
		strcat(buff,lv_str);
	} else {
		buff=malloc(256+1);
		strcpy(buff,lv_str);
	}
endcode


END FOREACH

let lv_thisproc=-1
IF lv_lastproc!=lv_thisproc THEN   # dump buff..
		LET lv_lastproc=lv_thisproc
		CALL dump_buff()
END IF

END FUNCTION

###################################################################

FUNCTION dump_buff()

code
	if (buff) {
		A4GL_trim(buff);
		printf("%s\n",buff);
		printf("\n\n\n\n");
		free(buff);
		buff=0;
	}
endcode

END FUNCTION
