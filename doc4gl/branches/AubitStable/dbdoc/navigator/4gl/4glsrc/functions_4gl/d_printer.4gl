

GLOBALS
  DEFINE dummyAux CHAR(3)
END GLOBALS

#############################################################################
#
#  Funcoes para os REPORTS
#

#  PRINT QUALITY/SPACING
#


FUNCTION d_elite()
  LET dummyAux=ASCII 27,":"
  RETURN dummyAux CLIPPED
END FUNCTION


# ==============================================================================
# Mete o espacamento a 1/10 de polegada
# ==============================================================================
FUNCTION d_um_decimo()
   let dummyAux=ASCII 27,"3", ascii 21
	return dummyAux clipped
END FUNCTION

# ==============================================================================
# Mete o espacamento a 1/6 de polegada (Normal)
# ==============================================================================
FUNCTION d_um_sexto()
   let dummyAux=ASCII 27,"3", ascii 36
	return dummyAux clipped
END FUNCTION

# ==============================================================================
# Mete o espacamento a n/216 de polegada 
# ==============================================================================
FUNCTION d_n_216(val)
  define val integer
   let dummyAux=ASCII 27,"3", ascii val
	return dummyAux clipped
END FUNCTION

# ==============================================================================
# Mete o espacamento a n cm
# ==============================================================================
FUNCTION d_vert_cm(cm)
  define cm, nf smallfloat
  define n integer
	define ajustamentoImpressora decimal(2,1)

	let ajustamentoImpressora = fgl_getenv("AJUST_IMPR")
	if ajustamentoImpressora is not null then
    let nf = 216 * (cm/ajustamentoImpressora) / 2.54
  else
    let nf = 216 * cm / 2.54
	end if
  let n = nf
  let dummyAux = ASCII 27,"3", ascii n
  return dummyAux clipped
END FUNCTION


FUNCTION d_pica()
  LET dummyAux=ASCII 18
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_nlq()
  LET dummyAux=ASCII 27,"I",ASCII 2
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_draft()
  LET dummyAux=ASCII 27,"I0"
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_unl()
  LET dummyAux=ASCII 27,"-",ASCII 1
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_nounl()
  LET dummyAux=ASCII 27,"-0"
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_cond()
  LET dummyAux=ASCII 15
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_nocond()
  LET dummyAux=ASCII 18
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_prop()
  LET dummyAux=ASCII 27,"P",ASCII 1
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_noprop()
  LET dummyAux=ASCII 27,"P0"
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_dstrike()
  LET dummyAux=ASCII 27,"G"
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_nodstrike()
  LET dummyAux=ASCII 27,"H"
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_enlarged()
  LET dummyAux=ASCII 27,"W1"
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_noenlarged()
  LET dummyAux=ASCII 27,"W0"
  RETURN dummyAux CLIPPED
END FUNCTION



# CARACTERES GRAFICOS
#

# CANTO SUPERIOR ESQUERDO
FUNCTION d_cse()             
  LET dummyAux=ASCII 218
  RETURN dummyAux CLIPPED
END FUNCTION

# CANTO SUPERIOR DIREITO
FUNCTION d_csd()
  LET dummyAux=ASCII 191
  RETURN dummyAux CLIPPED
END FUNCTION

#CANTO INFERIOR ESQUERDO
FUNCTION d_cie()
  LET dummyAux=ASCII 192
  RETURN dummyAux CLIPPED
END FUNCTION

#CANTO INFERIOR DIREITO
FUNCTION d_cid()
  LET dummyAux=ASCII 217
  RETURN dummyAux CLIPPED
END FUNCTION

# JUNCAO ESQUERDA
FUNCTION d_je()
  LET dummyAux=ASCII 195
  RETURN dummyAux CLIPPED
END FUNCTION

# JUNCAO DIREITA
FUNCTION d_jd()
  LET dummyAux=ASCII 180
  RETURN dummyAux CLIPPED
END FUNCTION

# JUNCAO CIMA
FUNCTION d_jc()
  LET dummyAux=ASCII 194
  RETURN dummyAux CLIPPED
END FUNCTION

# JUNCAO BAIXO
FUNCTION d_jb()
  LET dummyAux=ASCII 193
  RETURN dummyAux CLIPPED
END FUNCTION

#JUNCAO INTERIOR
FUNCTION d_ji()
  LET dummyAux=ASCII 197
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_th()
  LET dummyAux=ASCII 196
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_tv()
  LET dummyAux=ASCII 179
  RETURN dummyAux CLIPPED
END FUNCTION

FUNCTION d_tv2()
  RETURN "|" 
END FUNCTION

FUNCTION d_traco(n)
DEFINE n SMALLINT
DEFINE i SMALLINT,
		  linha CHAR(300)
  FOR i=1 TO n
	 LET linha[i] = ASCII 196
  END FOR
  RETURN linha CLIPPED
END FUNCTION

FUNCTION d_traco2(n)
DEFINE n SMALLINT
DEFINE i SMALLINT,
		  linha CHAR(300)
  FOR i=1 TO n
	 LET linha[i] = "-"
  END FOR
  RETURN linha CLIPPED
END FUNCTION


