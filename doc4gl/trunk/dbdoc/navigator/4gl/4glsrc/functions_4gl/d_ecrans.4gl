#  =================================================================
#  Funcao para escrever uma mensagem de aviso no linha definida para
#  mensagens.
#  -----------------------------------------------------------------
#  entradas:
#    mensagem -> string com a mensagem
#  -----------------------------------------------------------------
#  notas:
#    A variavel mensagem podera' ter o comprimento de 3 linhas
#    (3*79=237). Cada linha devera' ser terminada com o caracter '@'.
#    Caso as linhas nao se encontrem terminadas, as mesmas serao 
#    partidas ao fim de 79 caracteres.
#  =================================================================
FUNCTION d_bottommsg (mensagem)
{}
DEFINE mensagem CHAR (237)

DEFINE ecran    ARRAY [3] OF CHAR (79),
       num_secs,
       lin,comp,
       ini,pos,
       pos_a    SMALLINT

  whenever error call d_erro
  LET ini = 1
  LET pos_a = 1
  LET comp = LENGTH (mensagem)
  IF comp = 0 THEN
    LET ecran [1] = "MENSAGEM NAO DEFINIDA"
    LET pos_a = 2
  ELSE
    FOR pos = 1 TO comp
      IF mensagem [pos] = "@" OR (pos-ini+1) > 79 OR pos = comp THEN
        IF mensagem [pos] = "@" THEN
          LET ecran [pos_a] = mensagem [ini,pos-1]
        ELSE
          LET ecran [pos_a] = mensagem [ini,pos]
        END IF
        LET pos_a = pos_a+1
        IF pos_a > 3 THEN
          EXIT FOR
        END IF
        LET ini = pos + 1
      END IF
    END FOR
  END IF
    
  LET lin = 25 - pos_a
  OPEN WINDOW WMsgErro AT lin,1 WITH pos_a ROWS, 79 COLUMNS
  #CALL MlibNoise ()
  DISPLAY "                                                                               " AT 1,1 ATTRIBUTE (REVERSE)
  FOR pos = 1 TO pos_a - 1
    CALL d_disp_center (1+pos,1,79,ecran [pos])
  END FOR
  LET num_secs = (comp / 60) + 2
  SLEEP (num_secs)
  CLOSE WINDOW WMsgErro

END FUNCTION


#  =================================================================
#  Funcao para fazer o display de uma string centrada.
#  -----------------------------------------------------------------
#  entradas:
#    lin -> linha da janela.
#    col1,col2 -> colunas limite.
#    texto     -> string com o texto.
#  =================================================================
FUNCTION d_disp_center (lin,col1,col2,texto)
DEFINE lin,
       col1,col2,
       offset    SMALLINT,
       texto     CHAR (80)

  LET offset = ((col2 - col1 + 1) - LENGTH (texto)) / 2 + 1

  DISPLAY texto CLIPPED AT lin,offset

END FUNCTION


###########################################################################
# Escreve a mensagem passada como argumento, na linha 24 do ecran         #
###########################################################################
FUNCTION d_mesg(msg)
{}
DEFINE 
	msg CHAR(78),
	dim INTEGER

	OPEN WINDOW w_mesg AT 24, 2 WITH 1 ROWS, 78 COLUMNS
		LET dim=(78-LENGTH(msg CLIPPED))/2
		DISPLAY " ", msg CLIPPED, " " AT 1, dim ATTRIBUTE(REVERSE)
		SLEEP 2
	CLOSE WINDOW w_mesg
		
END FUNCTION

