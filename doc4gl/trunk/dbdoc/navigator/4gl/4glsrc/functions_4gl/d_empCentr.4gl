#DATABASE despodata
database sysmaster

globals "4glsrc/functions_4gl/d_libglob.4gl"

define empresa like ger_empresa.cod_empresa,
		 centro like centros.codigo

FUNCTION 	 d_empCentr(fl_centro,alteracao)
{}
   define
	  fl_centro,alteracao integer
	DEFINE 
	  utilizador CHAR(18),
	  aux integer

	IF d_user IS NULL THEN
	  CALL d_init_user()
	END IF
	initialize empresa,centro,utilizador to null
	if not alteracao then
     SELECT emp_curr.empresa,emp_curr.centro,emp_curr.utilizador
	   INTO empresa,centro,utilizador FROM emp_curr
		  WHERE emp_curr.utilizador=d_user
   end if

   IF status = NOTFOUND or alteracao THEN 
		declare cr_empresas cursor for select cod_empresa from ger_empresa
		open cr_empresas
		fetch cr_empresas into empresa
		if status=notfound then    # Nao existem empresas
		  if fl_centro then
          call d_dialogOk(9,15,"","Nao existem registos de empresas",
									  "nem de centros de custo.",
									  "Deve criar estes registos",
									  "antes de correr esta aplicacao","")
        else
          call d_dialogOk(9,15,"","Nao existe registo de empresa",
									  "Deve criar este registo",
									  "antes de correr esta aplicacao","","")
		  end if
        return "",""
		end if
		fetch next cr_empresas into empresa   # teste se uma ou varias empresas
		if status=notfound then    # So existe uma empresa
		  if fl_centro then
		    if not d_get_centros(true) then   # vai buscar centro de custo
			  return "",""
          end if
        else
		    call d_showEmp(empresa,centro)
        end if
		else    # existem varias empresas deve escolher uma
		  if fl_centro then
          CALL d_dialogOk(9,15,"","",
									"Escolha empresa e",
									"centro de custo correntes.","","")
        else
          CALL d_dialogOk(9,15,"","", "Escolha empresa corrente.","","","")
		  end if
        CALL d_lov(8,2,2,1,1,FALSE,"Seleccionar empresa","ger_empresa","cod_empresa",
					    "nome","")
        RETURNING empresa
		  if empresa is null then
			 return "",""
		  end if
		  if fl_centro then
		    if not d_get_centros(false) then   # vai buscar centro de custo
			  return "",""
          end if
        end if
		end if
		close cr_empresas
		if alteracao then
		  update emp_curr set (empresa,centro)=(empresa,centro) where
			 @utilizador=d_user
		else
	     INSERT INTO emp_curr(utilizador,empresa,centro) 
						VALUES(d_user,empresa,centro)
		end if
	ELSE
		call d_showEmp(empresa,centro)
   END IF
	return empresa,centro
END FUNCTION

function d_showEmp(empresa,centro)
  define empresa like ger_empresa.cod_empresa,
			centro like centros.codigo,
			empnome like ger_empresa.nomer,
			centronome like centros.nomer,
			strEmp,strRec char(48)

  if empresa is null and centro is null then
	 return
  end if
  initialize strEmp,strRec to null
  if empresa is not null then
    select nomer into empnome from ger_empresa where cod_empresa=empresa
    let strEmp="Empresa : ",empnome clipped
  end if
  if centro is not null then
    select nomer into centronome from centros where codigo=centro
    let strRec="Centro de custo : ",centronome clipped
  end if
  call d_dialogOk(9,15,"","",strEmp,strRec,"","")
end function

function d_get_centros(modo)
  define modo integer
  define auxStr char(30)

  declare cr_centros cursor for select codigo from centros 
		 where @empresa=empresa
  open cr_centros
  fetch cr_centros into centro
  if status=notfound then    # Nao existem centros de custo
        call d_dialogOk(9,15,"","Nao existem registos",
							    "de centros de custo.",
							    "Deve criar estes registos",
							    "antes de correr esta aplicacao","")
        return false
  end if
  fetch next cr_centros into centro  # teste se um ou mais centros
  if status=notfound then    # So existe um centro
    call d_showEmp(empresa,centro)
  else   # Existem varios centros deve escolher um
	 if modo then
      call d_showEmp(empresa,"")
    end if 
    CALL d_dialogOk(9,15,"","","Nao existe definicao",
									"de centro de custo corrente.",
									"Deve escolher um!","")
	 let auxStr="empresa=",empresa
    CALL d_lov(8,2,2,1,1,FALSE,"Seleccionar centros","centros","codigo",
					      "nomer",auxStr)
    RETURNING centro
	 if centro is null then
			return false
	 end if
  end if
  close cr_centros
  return true
end function
