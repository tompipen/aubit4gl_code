FUNCTION d_accept_null(tabela,coluna)

DEFINE tabela CHAR(18),
       coluna CHAR(18),
       var SMALLINT

  whenever error call d_erro
IF tabela IS NOT NULL OR coluna IS NOT NULL THEN
   SELECT coltype
          INTO var
          FROM systables,syscolumns
          WHERE systables.tabid = syscolumns.tabid
          AND systables.tabname = tabela
          AND syscolumns.colname = coluna
    
    IF var >= 256 THEN
       RETURN(FALSE)
    ELSE
       RETURN(TRUE)
    END IF

ELSE
   RETURN(FALSE)
END IF

END FUNCTION 

