#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: Joao
#         Pedro Higgs Menezes
#                                                        
#  Data de criacao: Tue Dec 20 11:37:55 LISBOA 1994
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : 
#  ---------------------------------------------------------------------------
#  DESCRICAO: 
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
# 
#  ---------------------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#     Alterado por Pedro Higgs Menezes em 20/12/94. Se for o owner nao faz mais
#    mais, pois tem permissao, e retorna true
#
#  ============================================================================ 
# Colocar aqui o header

#FIXME:
database sysmaster
#database despodata

globals "4glsrc/functions_4gl/d_libglob.4gl"

#  ============================================================================ 
# Funcao que recebe o nome da tabela e o previlegio.
# devolve true se a tabela tiver a permissao (previlegio) para o utilizador
# corrente
#  ============================================================================ 
function d_auth(tabela,previlegio)
{}
   define
		tabela        char(18),
      previlegio    char(18),
      pr_systabauth record
         grantor    like systabauth.grantor,
         grantee    like systabauth.grantee,
         tabid      like systabauth.tabid,
         tabauth    like systabauth.tabauth
		end record,
      pr_systables  record
         tabname     like systables.tabname,
         owner       like systables.owner,
         tabid       like systables.tabid,
         rowsize     like systables.rowsize,
         ncols       like systables.ncols,
         nindexes    like systables.nindexes,
         nrows       like systables.nrows,
         created     like systables.created,
         version     like systables.version,
         tabtype     like systables.tabtype
		end record
 
	 # ??? Isto tem de ser modificado rapidamente pois agota
	 #     nao valida nada
	 return true

   whenever error call d_erro

   if d_user is null then
	   call d_init_user()
   end if 

   select systables.tabname,systables.owner,
          systables.tabid,systables.rowsize,
			 systables.ncols,systables.nindexes,
			 systables.nrows,systables.created,
			 systables.version,systables.tabtype
   into pr_systables.tabname,pr_systables.owner,
        pr_systables.tabid,pr_systables.rowsize,
		  pr_systables.ncols,pr_systables.nindexes,
		  pr_systables.nrows,pr_systables.created,
		  pr_systables.version,pr_systables.tabtype
   from systables
   where systables.tabname = tabela

   if d_user = pr_systables.owner then
	   return true
   else
      declare cr_auth cursor for 
         select systabauth.grantor,systabauth.grantee,
                systabauth.tabid,systabauth.tabauth
         from systabauth,systables
         where systables.tabname = tabela           and
		         systables.tabid   = systabauth.tabid and
		         ( grantee = d_user or grantee = "public" )
   
      foreach cr_auth into pr_systabauth.grantor,
                           pr_systabauth.grantee,
                           pr_systabauth.tabid,
                           pr_systabauth.tabauth

         if pr_systabauth.grantee = "public" then
            return true
         end if
         case 
            when previlegio = "all"      
               if pr_systabauth.tabauth matches "su?idxa" then
                  return true
               else
                  return false
               end if
            when previlegio = "alter"      # 7
               if pr_systabauth.tabauth[7] = '-' then
                  return false
               else
                  return true
               end if
            when previlegio = "delete"     # 5
               if pr_systabauth.tabauth[5] = '-' then
                  return false
               else
                  return true
               end if
            when previlegio = "index"      # 6
               if pr_systabauth.tabauth[6] = '-' then
                  return false
               else
                  return true
               end if
            when previlegio = "insert"     # 4
               if pr_systabauth.tabauth[4] = '-' then
                  return false
               else
                  return true
               end if
            when previlegio = "select"     # 1
               if pr_systabauth.tabauth[1] = '-' then
                  return false
               else
                  return true
               end if
            when previlegio = "update"     # 2
               if pr_systabauth.tabauth[2] = '-' then
                  return false
               else
                  return true
               end if
            otherwise
               call d_dialogOk(9,15,"","Previlégio e",
												   previlegio,"não existe",
												   "!","")
               return false
         end case

      end foreach

   end if

   return true

end function
