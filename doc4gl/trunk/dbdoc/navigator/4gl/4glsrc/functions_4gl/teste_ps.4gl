#  ============================================================================ 
#
#  Copyright 1997 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: Carlos Patrao
#                                                        
#  Data de criacao: Tue Sep 08 12:07:07 LISBOA 1997
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Report Postscript para testar funcoes genericas de 
#                  desenvolvimento de relatorios em PS 
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
#
#  ============================================================================ 
GLOBALS "/usr/desenvolv/include/d_libglob.4gl"

MAIN
   DEFER INTERRUPT

   WHENEVER ERROR CALL d_erro
	LET d_nm_log="/tmp/scr_doc.log"
	CALL StartLog(d_nm_log)

   START REPORT Teste to "/tmp/teste.ps" 
     OUTPUT TO REPORT Teste("Olá cá estou eu")
   FINISH REPORT Teste
END MAIN

{
define pr_itemsdoc record like itemsdoc.*,
     numLinhas,numIvas,numLinTot,subTt integer,
     desconto, agravamento, sub_total float,
     ar_iva array[26] of record
        taxa like iva_fac.taxa,
        dizer char(60),
        valor float
     end record,
     pr_entid record like ent_geral.*,
     pr_pais record like paises_fac.*,
     pr_empresa record like ger_empresa.*,
     nomePostal,nomePostalEmp like postal_fac.nome,
     nomeLocal,nomeLocalEmp like localidades.nome,
     changeF, helvP, rectangle, logo char(40),
     errFile char(64),
     i integer

report r_fact697(tipofac,pr_doc_fac,pr_items,pr_impressos)
  define tipofac char(20),
         pr_doc_fac record like doc_fac.* ,
      pr_items record like itemsdoc.*,
      pr_impressos record like impressos.*
  define newPage,printFiles integer,
       pr_descr record like descricoes_fac.*,
      valor char(14),
      valorInt integer,
      str_tel char(100),
      telefone,fax like telefones_emp.numero,
         condicPag like tipopag.design,
      yy char(4),
      cc char(1),
      ivatext char(7),
      extenso char(128),
      observacoes char(350),
      dataExt char(40)

  output
   left margin 0
   right margin 0
   top margin 0
   bottom margin 0
   page length 1 

  format
   first page header
    let changeF="/tmp/cha.ps"
    let helvP="/tmp/heP.ps"
    let rectangle="/tmp/rtg.ps"
    let logo="/tmp/log.ps"
    let printFiles=true
    let newPage=true
    let numLinhas=0
    let numIvas=0
    let desconto=0
    let agravamento=0
    let sub_total=0
    for i=1 to 26
     initialize ar_iva[i].* to null
     let ar_iva[i].taxa=-1
     let ar_iva[i].valor=0
    end for
    initialize pr_entid.*,pr_pais.*,nomePostal,nomeLocal to null
    initialize pr_empresa.*,nomePostalEmp,nomeLocalEmp to null
    initialize telefone,fax,condicPag to null
    select ent_geral.*,postal_fac.nome,localidades.nome,paises_fac.nome 
     into pr_entid.*,nomePostal,nomeLocal,pr_pais.nome 
      from ent_geral,outer postal_fac,outer localidades,outer paises_fac
      where ent_geral.codigo=pr_doc_fac.cliente 
       and ent_geral.localidade=localidades.codigo 
        and ent_geral.pais=paises_fac.cod_num 
         and ent_geral.cod_post=postal_fac.codigo
    if pr_pais.nome is not null then
      let pr_pais.nome=upshift(pr_pais.nome)
    end if

    if pr_impressos.e_timbrado is null or pr_impressos.e_timbrado="N" then
      select ger_empresa.*,postal_fac.nome,localidades.nome 
       into pr_empresa.*,nomePostalEmp,nomeLocalEmp
        from ger_empresa,outer postal_fac,outer localidades
        where ger_empresa.cod_empresa=pr_doc_fac.empresa 
         and ger_empresa.local=localidades.codigo 
          and ger_empresa.codpost=postal_fac.codigo

        let str_tel="select numero from telefones_emp where entidade=",
        pr_empresa.cod_empresa
      let str_tel=str_tel clipped," and tipo=?"
      prepare pstr_tel from str_tel
      declare cr_tel cursor for pstr_tel
      let cc="T"
        open cr_tel using cc 
        fetch cr_tel into telefone
      close cr_tel
      let cc="F"
        open cr_tel using cc 
        fetch cr_tel into fax
      close cr_tel
      free cr_tel
      end if
      select design into condicPag from tipopag 
     where codigo=pr_doc_fac.condicoes

    on last row
    if testNewPage2() or newPage then  # o 2 teste prende-se com o caso
      if NOT newpage then             # especial de 20 linhas de factura
          print("  11 linhasDimVar")
          print("showpage")  
          print("restore")
      end if
        print("save")
        print("  changeFont")
        print("  helvPortuguese")
      print("  helvPort [90 0 0 90 0 0] makefont setfont")
        print("  grayRectangles")
      print("  (VALOR TOTAL)(VALOR UNIT.)(DESCRI\307\303O)(QUANT.) titulos")
        print("  quadroExterno")
        print("  linhasFixas")
        print("  marcDobrFur")
        print("  dizeresMinusculos")
        print("  cliente")
      if pr_impressos.e_timbrado is null or pr_impressos.e_timbrado="N" then
          print("  empresa")
        end if
        print("  ("),tipofac,(") showtipofac ")
        print("  /Courier-Bold findfont 12 scalefont setfont")
    end if
    let yy = 11 - 0.5 * numLinTot
      print("  "),yy,(" linhaDimVar")
    let yy = 8.7 + 0.5 * numLinTot
      print("  19 "),yy,(" 1.3 linhaTotais")
    let yy = yy - 0.4
      if subTt then
      print("  (SUB-TOTAL) 11.5 cm "),yy,(" cm showStr")
      let valor = sub_total using "###,###,##&.##"
      print("  ("),valor clipped,(") 16.5 cm "),yy,(" cm showStr")
      let yy = yy - 0.5
    end if
      if desconto then
      print("  (TOTAL DESCONTOS) 11.5 cm "),yy,(" cm showStr")
      let valor = desconto using "##,###,##&.##"
      let valor = "-",valor clipped
      print("  ("),valor clipped,(") 16.5 cm "),yy,(" cm showStr")
      let yy = yy - 0.5
    end if
      if agravamento then
      print("  (TOTAL AGRAVAMENTOS) 11.5 cm "),yy,(" cm showStr")
      let valor = agravamento using "###,###,##&.##"
      print("  ("),valor clipped,(") 16.5 cm "),yy,(" cm showStr")
      let yy = yy - 0.5
    end if
      if subTt then
      let yy = yy + 0.4
        print ("  4 "),yy,(" 16.3 linhaTotais")
      let yy = yy - 0.4
    end if
    print("  (TOTAL LIQUIDO) 11.5 cm "),yy,(" cm showStr")
    let valor = pr_doc_fac.valor_s_iva using "###,###,##&.##"
    print("  ("),valor clipped,(") 16.5 cm "),yy,(" cm showStr")
    let yy = yy - 0.5
    let observacoes=null
    call sortJoao2()
    for i=1 to 26
      if ar_iva[i].taxa !=-1 then 
        let ivatext = ar_iva[i].taxa using "##&.#"," %"
        print("  (IVA "),ivatext clipped,(") 11.5 cm "),yy,(" cm showStr")
        let valorInt=ar_iva[i].valor+0.5
        let valor = valorInt using "###,###,##&.##"
        print("  ("),valor clipped,(") 16.5 cm "),yy,(" cm showStr")
        let yy = yy - 0.5
        if observacoes is not null then
          let observacoes=observacoes clipped," ",ar_iva[i].dizer clipped
        else
          let observacoes=ar_iva[i].dizer clipped
        end if
      end if
    end for
    declare cr_obs cursor for select * from descricoes_fac 
     where factura=pr_doc_fac.num_prov and tipo=pr_doc_fac.tipo_doc 
      order by ordem
    foreach cr_obs into pr_descr.*
      if observacoes is not null then
        let observacoes=observacoes clipped," ",pr_descr.linha clipped
        else
        let observacoes=pr_descr.linha clipped
        end if
    end foreach
    free cr_obs
    let yy = yy + 0.4
      print ("  4 "),yy,(" 16.3 linhaTotais")
    let yy = yy - 0.4
    print("  (TOTAL) 11.5 cm "),yy,(" cm showStr")
    let valor = pr_doc_fac.valor_total using "###,###,##&.##"
    print("  ("),valor clipped,(") 16.5 cm "),yy,(" cm showStr")
      if pr_doc_fac.valor_total is not null then

        ## EXTENSOS VARIOS
		  if pr_doc_fac.lingua is not null then
		    initialize pr_pais.* to null
		    select * into pr_pais.* from paises_fac 
				where cod_num=pr_doc_fac.lingua
          let pr_pais.nome=upshift(pr_pais.nome) 
          if pr_pais.nome not matches "*PORTUG*" then
			   # Extenso em ingles
			   if pr_doc_fac.moeda is not null then
		        initialize pr_pais.* to null
		        select * into pr_pais.* from paises_fac 
				    where cod_num=pr_doc_fac.moeda
              let pr_pais.nome=upshift(pr_pais.nome) 
              if pr_pais.nome not matches "*PORTUG*" then
				    # Extenso em ingles c/ moeda diferente escudos
                let pr_pais.nome_moeda=downshift(pr_pais.nome_moeda) 
                let pr_pais.decimal_moeda=downshift(pr_pais.decimal_moeda) 
                let extenso=d_extensoEst(pr_doc_fac.valor_total,200,2,
												  pr_pais.nome_moeda,pr_pais.decimal_moeda)
				  else
				    # Extenso em ingles c/ escudos 
                let extenso=d_extensoEst(pr_doc_fac.valor_total,200,2,"escudo","centavo")
				  end if
			   else
				  # Extenso em ingles em escudos 
              let extenso=d_extensoEst(pr_doc_fac.valor_total,200,2,"escudo","centavo") 
			   end if
			 else
		      # Extenso em portugues
			   if pr_doc_fac.moeda is not null then
		        initialize pr_pais.* to null
		        select * into pr_pais.* from paises_fac 
				    where cod_num=pr_doc_fac.moeda
              let pr_pais.nome=upshift(pr_pais.nome) 
              if pr_pais.nome not matches "*PORTUG*" then
				    # Extenso em portugues c/ moeda diferente escudos
                let pr_pais.nome_moeda=downshift(pr_pais.nome_moeda) 
                let pr_pais.decimal_moeda=downshift(pr_pais.decimal_moeda) 
                let extenso=d_extensoEst(pr_doc_fac.valor_total,200,0,pr_pais.nome_moeda,pr_pais.decimal_moeda)
				  else
				    # Extenso totalmente em portuges
                let extenso=d_extenso(pr_doc_fac.valor_total,200)
				  end if
			   else
				  # Extenso totalmente em portuges
              let extenso=d_extenso(pr_doc_fac.valor_total,200)
			   end if
			 end if
        else
			 if pr_doc_fac.moeda is not null then
		      initialize pr_pais.* to null
		      select * into pr_pais.* from paises_fac 
				  where cod_num=pr_doc_fac.moeda
            let pr_pais.nome=upshift(pr_pais.nome) 
            if pr_pais.nome not matches "*PORTUG*" then
				  # Extenso em portugues c/ moeda diferente escudos
              let pr_pais.nome_moeda=downshift(pr_pais.nome_moeda) 
              let pr_pais.decimal_moeda=downshift(pr_pais.decimal_moeda) 
              let extenso=d_extensoEst(pr_doc_fac.valor_total,200,0,pr_pais.nome_moeda,pr_pais.decimal_moeda) 
				else
				  # Extenso totalmente em portugues
              let extenso=d_extenso(pr_doc_fac.valor_total,200)
				end if
			 else
				# Extenso totalmente em portugues
            let extenso=d_extenso(pr_doc_fac.valor_total,200)
			 end if
		  end if

      end if
      print("  ("),extenso clipped,(")")
      print("  ("),observacoes[281,350],(")")
      print("  ("),observacoes[211,280],(")")
      print("  ("),observacoes[141,210],(")")
      print("  ("),observacoes[71,140],(")")
      print("  ("),observacoes[1,70],(")")
      print("  dizeresUltimaPag")
      print("showpage")
      print("restore")
    call delFicheiros2()

end report

function prepareTotais2()
  call valorIvas2() 
  call valDescAgrav2() 
  let sub_total=sub_total+pr_itemsdoc.total
end function

function valDescAgrav2() 
  define auxDesconto,auxAgravamento float

  if pr_itemsdoc.descontos is null then
    let pr_itemsdoc.descontos=0
  end if
  if pr_itemsdoc.agravamentos is null then
    let pr_itemsdoc.agravamentos=0
  end if
  if pr_itemsdoc.total is null then
    let pr_itemsdoc.total=0
  end if

  if pr_itemsdoc.tipo_desc_ag="P" 
  or pr_itemsdoc.tipo_desc_ag is null then
    let auxDesconto=pr_itemsdoc.total*pr_itemsdoc.descontos/100
    let auxAgravamento=pr_itemsdoc.total*pr_itemsdoc.agravamentos/100
  else
    let auxDesconto=pr_itemsdoc.descontos
    let auxAgravamento=pr_itemsdoc.agravamentos
  end if
  let desconto=desconto+auxDesconto
  let agravamento=agravamento+auxAgravamento
end function

function testNewPage2()
  define aux integer

  let subTt=false
  let numLinTot=numIvas+2        # ivas+total_liquido+totalTOTAL
  let aux=numLinTot
  let numLinTot=numLinTot+(desconto!=0)+(agravamento!=0)
  if aux!=numLinTot then
   let subTt=true
    let numLinTot=numLinTot+1    # sub_total 
  end if
  if (numLinTot+numLinhas)>20 then
   return true
  else
   return false
  end if

end function

function delFicheiros2()
  define dummy integer
  let dummy=d_unlink(changeF)
  let dummy=d_unlink(helvP)
  let dummy=d_unlink(rectangle)
  let dummy=d_unlink(logo)
end function

#  Calculo dos montantes do IVA

function valorIvas2()
  define pr_iva_fac record like iva_fac.*

  if pr_itemsdoc.iva is not null  then
   let i=fgl_keyval(pr_itemsdoc.iva)-64
   if ar_iva[i].taxa = -1 then
      select * into pr_iva_fac.* from iva_fac where codigo=pr_itemsdoc.iva
      if status=NOTFOUND then
        return
      end if
      let ar_iva[i].taxa=pr_iva_fac.taxa
      let ar_iva[i].dizer=pr_iva_fac.dizer
      let numIvas=numIvas+1
   end if
   let ar_iva[i].valor=ar_iva[i].valor+pr_itemsdoc.totalLiq*(ar_iva[i].taxa/100)
  end if
end function

function sortJoao2()
  define recAux  record
            taxa like iva_fac.taxa,
            dizer char(60),
            valor float
         end record,
         idx,i integer

  FOR idx=25 TO 1 STEP -1    # 25->dim-1
     FOR i=1 TO idx
       IF ar_iva[i].taxa > ar_iva[i+1].taxa THEN
         # TROCAR
         LET recAux.*=ar_iva[i].*
         LET ar_iva[i].* = ar_iva[i+1].*
         LET ar_iva[i+1].* = recAux.*
       END IF
     END FOR
  END FOR
end function
}

REPORT Teste(str_teste)
  DEFINE str_teste CHAR(256)

  #
  # Variaveis locais
  #
  DEFINE fich_change_font  CHAR(30)
  DEFINE fich_helv_por     CHAR(30)
  DEFINE fich_cour_por     CHAR(30)
  DEFINE fich_courb_por    CHAR(30)
  DEFINE fich_rectangle    CHAR(30)
  DEFINE fich_rectangle_mm CHAR(30)
  DEFINE fich_logo         CHAR(30)
  DEFINE flag_1_pag        SMALLINT

  #
  # Corpo do Report
  #
  OUTPUT
    LEFT MARGIN 0
    RIGHT MARGIN 0
    TOP MARGIN 0
    BOTTOM MARGIN 0
    PAGE LENGTH 1 

  FORMAT
    FIRST PAGE HEADER
		LET flag_1_pag=TRUE
      LET fich_change_font="/tmp/cha.ps"
      LET fich_helv_por="/tmp/heP.ps"
      LET fich_cour_por="/tmp/coP.ps"
      LET fich_courb_por="/tmp/cbP.ps"
      LET fich_rectangle="/tmp/rtg.ps"
      LET fich_rectangle_mm="/tmp/rtg_mm.ps"
      LET fich_logo="/tmp/log.ps"

    ON EVERY ROW
		IF flag_1_pag THEN
		  LET flag_1_pag=FALSE

        PRINT DeclareCm() 
        PRINT DeclareMm() 

        CALL ChangeFont(fich_change_font)
        PRINT FILE (fich_change_font)

        CALL helvPortug(fich_helv_por)
        PRINT FILE (fich_helv_por)

        CALL FontPortug("Courier",fich_cour_por)
        PRINT FILE (fich_cour_por)

        CALL FontPortug("Courier-Bold",fich_courb_por)
        PRINT FILE (fich_courb_por)

        #CALL Rectangles(fich_rectangle)
        #PRINT FILE (fich_rectangle)

		  CALL RectangulosMm(fich_rectangle_mm)
        PRINT FILE (fich_rectangle_mm)

        CALL LogoTipo(fich_logo)
        PRINT FILE (fich_logo)

        #
		  # Linhas Fixas
		  #
        PRINT("/linhasFixas {")
        PRINT DrawLine(163,197,-110,"V")
        PRINT DrawLine(13,187,190,"H")
        PRINT("}def")

		  #
		  #   Linha Dim Var
		  #
        PRINT
        PRINT("/linhaDimVar {")
        PRINT("  dup")
        PRINT("  3.2 cm 19.7 cm moveto")
        PRINT("  -1 mul cm 0 exch")
        PRINT("  rlineto")
        PRINT("  13.3 cm 19.7 cm moveto")
        PRINT("  -1 mul cm 0 exch")
        PRINT("  rlineto")
        PRINT("  stroke")
        PRINT("}def")

		  #
		  # Linha Totais
		  #
        PRINT
        PRINT("/linhaTotais {")
        PRINT("  cm")
        PRINT("  exch")
        PRINT("  cm")
        PRINT("  moveto")
        PRINT("  cm")
        PRINT("  0 rlineto")
        PRINT("  stroke")
        PRINT("}def")

		  #
		  # MarcDobrFur 
	  	  #
        PRINT
        PRINT("/marcDobrFur {")
        PRINT("  0 9.9 cm moveto")
        PRINT("  1 cm 0 rlineto")
        PRINT("  0 19.8 cm moveto")
        PRINT("  1 cm 0 rlineto")
        PRINT("  0 14.85 cm moveto")
        PRINT("  1 cm 0 rlineto")
        PRINT("  stroke")
        PRINT("}def")

		  #
		  # Dizeres Minusculos
		  #
        PRINT
        PRINT("/dizeresMinusculos {")
        PRINT("  gsave")
        PRINT("    helvPort [5.4 0 0 5.4 0 0] makefont setfont")
        PRINT("    1.3 cm .7 cm moveto")
        PRINT("    (processado por computador) show")
        PRINT("    -90 rotate")
        PRINT("    -4 cm 20.2 cm moveto")
        PRINT("    (Factura modelo 697 \251 despodata 1993) show")
        PRINT("  grestore")
        PRINT("}def")

		  #
		  # Empresa
		  #
        PRINT
        PRINT("/empresa {")
        PRINT("  gsave")
        PRINT("    .8 28.2 logotipo")
        PRINT("    helvPort [6 0 0 6 0 0] makefont setfont")
        PRINT("    1 cm 26 cm moveto")
        PRINT("    (DespoData) show")
        PRINT("    1 cm 25.7 cm moveto")
        PRINT("    ("),pr_empresa.morada,(") show")
        PRINT("    1 cm 25.4 cm moveto")
        PRINT("    (Lisboa) show")
        PRINT("    1 cm 25.1 cm moveto")
        PRINT("    (1100 Lisboa) show")
        PRINT("    1 cm 24.8 cm moveto")
        PRINT("    (Telefone: 888 01 48 - Fax: 887 92 66) show")
        PRINT("    1 cm 24.5 cm moveto")
        PRINT("    (N.\353 de Contribuinte: 333 444 555) show")
        PRINT("  grestore")
        PRINT("}def")


		  #
		  # Dizeres ultima pagina
	  	  #
        PRINT
        PRINT("/dizeresUltimaPag {")
        PRINT("  gsave")
        PRINT("    helvPort [9 0 0 9 0 0] makefont setfont")
        PRINT("    2 cm 3.5 cm moveto")
        PRINT("    (OBSERVA\307\325ES:) show")
        PRINT("    2.2 cm 3 cm moveto")
        PRINT("    show")
        PRINT("    2.2 cm 2.6 cm moveto")
        PRINT("    show")
        PRINT("    2.2 cm 2.2 cm moveto")
        PRINT("    show")
        PRINT("    2.2 cm 1.8 cm moveto")
        PRINT("    show")
        PRINT("    2.2 cm 1.4 cm moveto")
        PRINT("    show")
        PRINT("    2 cm 8 cm moveto")
        PRINT("    (Importa o total em: ) show")
        PRINT("    show")
        PRINT("    2 cm 7 cm moveto")
        PRINT("    (CONDI\307\325ES DE PAGAMENTO: ) show")
        PRINT("    /Helvetica-Bold findfont 9 scalefont setfont")
        PRINT("    (Pronto pagamento) show")
        PRINT("  grestore")
        PRINT("}def")

		  #
		  # Titulos
	  	  #
        PRINT
        PRINT("/titulos {")
        PRINT("  gsave")
        PRINT("    1.4 cm 19 cm moveto")
        PRINT("    helvPort [12.5 0 0 12.5 0 0] makefont setfont")
        PRINT("    show ")
        PRINT("    3.8 cm 0 rmoveto")
        PRINT("    show ")
        PRINT("    4 cm 0 rmoveto")
        PRINT("    show ")
        PRINT("    .5 cm 0 rmoveto")
        PRINT("    show ")
        PRINT("  grestore")
        PRINT("}def")

		  #
		  # GrayRectangles
		  #
        PRINT
        PRINT("/grayRectangles{")
        PRINT GrayRectangle(95,35,257,95,90) 
        PRINT GrayRectangle(190,10,197,13,90) 
        PRINT("}def")

		  #
		  # Quadro Externo
		  #
        PRINT
        PRINT("/quadroExterno{")
		  PRINT Rectangle(190,110,197,13,2)
        PRINT("}def")

        PRINT DeclareShowStr() 

        PRINT("save")
        PRINT("  changeFont")
        PRINT("  helvPortuguese")
        PRINT("  helvPort [90 0 0 90 0 0] makefont setfont")
        PRINT("  grayRectangles")
        PRINT("  (VALOR TOTAL)(VALOR UNIT.)(DESCRI\307\303O)(QUANT.) titulos")
        PRINT("  quadroExterno")
        PRINT("  linhasFixas")
        PRINT("  marcDobrFur")
        PRINT("  dizeresMinusculos")
        PRINT("  /Courier-Bold findfont 12 scalefont setfont")
		  #PRINT(" ("),str_teste CLIPPED,(") showStr")  
		  PRINT ShowString("Olá cá estou Eu !!!",91,112)
        PRINT("showpage")
        PRINT("restore")

		  PRINT BeginPag()
        PRINT("  helvPortuguese")
        PRINT("  helvPort [90 0 0 90 0 0] makefont setfont")
        PRINT("  grayRectangles")
        PRINT("  (VALOR TOTAL)(VALOR UNIT.)(DESCRI\307\303O)(QUANT.) titulos")
        PRINT("  quadroExterno")
        PRINT("  linhasFixas")
        PRINT("  marcDobrFur")
        PRINT("  dizeresMinusculos")
        PRINT SetFont("Courier-Bold",18) 
		  PRINT ShowString("Olá cá estou Eu !!! OUTRA VEZ",91,112)
		  PRINT EndPag()

		END IF

END REPORT
