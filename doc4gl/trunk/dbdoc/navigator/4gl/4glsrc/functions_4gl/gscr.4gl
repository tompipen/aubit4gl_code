
#DATABASE despodata
database sysmaster

# GLOBALS "gl_fps.4gl"

#
#  Gestao de entradas de dados multi-input e multi-ecran
#  O objectivo eh reduzir ao minimo a gestao dos ecrans para quem esta a 
#  programar. Numa segunda fase pode-se pensar em geracoes automaticas
#
# 
# ??? Ainda falta a gestao dos displays (por causa dos reverses)
# ??? Falta posicionamento directo dentro dos ecrans( ex: do 1 para o 5 )
# ??? Devia-se pensar na possibilidade de mudar de registo sem ESC
# ??? Devias

# ??? Nao permite master e detail na mesma gestao (por enquanto fica assim)

#  Variaveis necessarias para controlar um programa de insercao de informacao
#  multi-ecran.
  define
   CurrEcran      smallint,           # Apontador de ecra corrente
   NEcrans        smallint,           # Maximo de ecrans
   FlagAccaoInput char(6),           # Accao que o utilizador efectuou no input
   PaCtlEcrans array[100] of record   # Array de Ecras
   	NInputs   smallint,            # Numero de Input(s)
   	CurrInput smallint,            # Input Corrente
   		PaCtlInput array[10] of record # Array de Input(s) em cada ecra
  	      Tipo      char(5),          # Tipo (Free Form ou Grid)
  	      IdxPa     smallint,         # Posicao Corrente no array do programa
  	      IdxSa     smallint,         # Posicao corrente no array do ecran
  	      MaxSa     smallint,         # Numero de linhas do array de ecran
  	      TotPa     smallint          # Numero de records programa preenchidos
      End record
   end record


#  ===========================================================================
#  Seleccao generica de mudanca de input
#  ??? Falta dar mensagens interactivas ou escrever no log
#  A FlagAccao Input nao eh reafectada pois ira servir para o alto nivel efectuar
#  o que tiver de fazer
#  faz parte da livaria de gestao de multi-ecrans.
#  ===========================================================================
Function DScrSelectInput()
   CASE
     
	  WHEN FlagAccaoInput = "Cima"
         if PaCtlEcrans[CurrEcran].CurrInput <= 1 then
            if CurrEcran <= 1 then
               if DScrMsg("PrimeiroEcran") then    end if
            else
               return false     # Vai um ecran para cima
            end if
         else
            LET PaCtlEcrans[CurrEcran].CurrInput = 
					 PaCtlEcrans[CurrEcran].CurrInput - 1
         end if
     
	  WHEN FlagAccaoInput = "Baixo"
         if PaCtlEcrans[CurrEcran].CurrInput >= 
			   PaCtlEcrans[CurrEcran].NInputs
         then
            if CurrEcran >= NEcrans  then
               if DScrMsg("UltimoEcran") then   end if
            else
               return false     # Vai um ecran para baixo
            end if
         else
            LET PaCtlEcrans[CurrEcran].CurrInput = 
					 PaCtlEcrans[CurrEcran].CurrInput + 1
         end if
      
		WHEN FlagAccaoInput = "Grava"
         return false
      
		WHEN FlagAccaoInput = "Aborta"
         return false

      When FlagAccaoInput = "ECima"
			  if CurrEcran <= 1 then
		       if DScrMsg("PrimeiroEcran") then    
			    end if
			  else
				  return false     # Vai um ecran para cima
			  end if
		
		When FlagAccaoInput = "EBaixo"
			if CurrEcran >= NEcrans  then
			  if DScrMsg("UltimoEcran") then  
			  end if
			  else
				 return false     # Vai um ecran para baixo
			  end if
		
		When FlagAccaoInput = "Icima"
		
		When FlagAccaoInput = "IBaixo"
   END CASE
   let FlagAccaoInput = ""
   return true
end function


#  ===========================================================================
#  Mensagens da gestao de entradas de dados multi-input e multi-ecran
#  inputs e multi-ecran.
#  ===========================================================================
Function DScrMsg(TipoMesg)
   define
      TipoMesg char(8),
      ans      smallint

   let ans = true
   case
		when TipoMesg="erro"
			call d_dialogOk(9,15,""," Não existem ECRÃNS",                                                             "","","","") 
      when TipoMesg="PrimeiroEcran"
         call d_dialogOk(9,15,"","Primeiro ecran","","","","")
      when TipoMesg="UltimoEcran"
         call d_dialogOk(9,15,"","Último ecran","","","","")
      when TipoMesg="Aborta"
         if d_dialog(9,15,"NAO","SIM","","",
		"QUER MESMO ABORTAR","",
		   "A OPERAÇÃO CORRENTE","?", "") = 1 # 2 
         then
            let ans = false
				# return -1
         end if
      when TipoMesg = "Grava"

         if d_dialog(9,15,"Gravar","Cancelar","","",
		"QUER MESMO GRAVAR","",
		   "A OPERAÇÃO CORRENTE","?", "") = 2 
         then
				let ans=false
         end if
      otherwise
         #mensagem inexistente
   end case
   return ans
end function

#  ===========================================================================
#  Inicializacoes das variaveis de controlo de um programa multi-ecran
#  ===========================================================================
    #Function DScrInit()
    #  let FlagAccaoInput = null
    #end function

#  ===========================================================================
#  Testa se o utilizador tem ou nao de ir para cima e afecta com a accao 
#  correspondente.
#  ??? Falta verificar es existe alguma coisa para cima e dar mensagem
#  ??? Falta comportar-se de forma diferente consoante o tipo de input
#  ===========================================================================
Function DScrVaiParaCima()
   IF  fgl_lastkey() = fgl_keyval("up") THEN 
      LET FlagAccaoInput = "Cima"
		return true
   END IF
	IF  fgl_lastkey() = fgl_keyval("F9") THEN
		LET FlagAccaoInput = "ECima"
		return true
	END IF
	return false
end function

#  ===========================================================================
#  Valida se o utilizador entra no Input a partir de baixo o que siginifica 
#  que devera ir para o ultimo campo do Input.
#  ===========================================================================
Function DScrVemdeBaixo()
   if ( fgl_lastkey() = fgl_keyval("up")  OR
		  fgl_lastkey() = fgl_keyval("F9")   ) THEN
      return true
   end if
   return false
end function

#  ===========================================================================
#  Testa se o utilizador tem ou nao de ir para baixo e afecta com a accao 
#  correspondente.
#  ??? Falta verificar es existe alguma coisa para baixo e dar mensagem
#  ??? Falta comportar-se de forma diferente consoante o tipo de input
#  ===========================================================================
Function DScrVaiParaBaixo()
    
	 #DEFINE 
	 # aux char(20)
	 # let aux = fgl_lastkey()
	 #display " O fgl_lastkey vale  =  ",aux at 9,8
	 #sleep 5
   
	IF ( fgl_lastkey() = fgl_keyval("down") OR 
		  fgl_lastkey() = 13                   )  THEN
			LET FlagAccaoInput = "Baixo"
			return true
		END IF
	IF fgl_lastkey() = fgl_keyval("F10") THEN
		LET FlagAccaoInput = "EBaixo"
		return true
	END IF
	return false
end function

#  ===========================================================================
#  Quando executada depois de um input permite confirmar a gravacao de 
#  alteracoes ou confirmar abortar edicao
#  ===========================================================================
Function DScrAfterInput()
   # Quando vai para cima e para baixo

	If DscrInputAbortado() then
      return true
   end if

   IF DScrGravaAlteracoes() then
      return true
   END IF
	If FlagAccaoInput is not null then
			return true
	end if
   return false
end function


#  ===========================================================================
#  Pergunta ao utilizador se deseja, de facto abortar a alteracao da informacao
#  ===========================================================================
Function DScrInputAbortado()
   if not int_flag then
      return false
   end if
   if DScrMsg("Aborta") then
      LET FlagAccaoInput = "Aborta"
      return true
   end if
   let FlagAccaoInput = ""
   let int_flag = false
   return false
end function

#  ===========================================================================
#  Pergunta ao utilizador se deseja, de facto gravar a alteracao da informacao
#  ===========================================================================
Function DScrGravaAlteracoes()
   if fgl_lastkey() != fgl_keyval("accept") then
      return false
   end if
   if DScrMsg("Grava") then
      LET FlagAccaoInput = "Grava"
      return true
   end if
   let FlagAccaoInput = ""
   return false
end function


#  ===========================================================================
#  Actualiza os contadores usados num input array
#  Podera tambem vir a servir para posicionamento na ultima linha do array
#  ===========================================================================
Function DScrActualizaContadores()
   define
		CurrInput smallint

	LET CurrInput = PaCtlEcrans[CurrEcran].CurrInput

   LET PaCtlEcrans[CurrEcran].PaCtlInput[CurrInput].IdxPa = arr_curr()
   LET PaCtlEcrans[CurrEcran].PaCtlInput[CurrInput].IdxSa = scr_line()
   LET PaCtlEcrans[CurrEcran].PaCtlInput[CurrInput].TotPa = arr_count()
end function

