
database despodata



#  ============================================================================ 
#  Verifica se existem as tabelas de modulos na base de dados e se
#  nao existirem cria-as.
#  ============================================================================ 
function 	 create_extensao()
{}
   define
		ans smallint,
		nome char(19)

   select tabname into  nome from systables where tabname="d_modulos"
	if status = notfound then
		let ans = d_dialog(9,15,"SIM","NAO","","Nao existem tabelas",
					"para registo de modulos","",
					"QUER CRIAR","?", "")
		if ans = 1 then
         create table d_modulos 
           (
             codigo char(5),
             nome char(40)
           );
			create unique index mod_prim on d_modulos (codigo)
         create table d_mod_tab 
           (
             codmod char(5),
             tabname char(19)
           );
			create unique index modtab_prim on d_mod_tab (codmod,tabname)
		else
			exit program
		end if
	end if


end function
