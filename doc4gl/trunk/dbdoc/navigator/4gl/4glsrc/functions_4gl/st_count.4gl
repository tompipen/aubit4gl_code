define
	last_mesg char(50),
	last_printed smallint

#  ======================================================================
#  funcao para abrir a janela informativa
#  desc1 - a mensagem que faz display
#  linha - linha onde abre a janela
#  coluna - coluna onde abre a janela
#  tot_col - total de colunas da janela
#  ======================================================================

function start_count(desc1, linha, coluna, tot_col)
define
	desc1 char(50),
	linha, coluna, tot_col integer

define
	 # contador,i smallint,  Alterado por Joao Costa 21/09/94
	contador,i integer,
	mycol, col_inic integer,
	aux char(25)

  whenever error call d_erro
	let last_printed=0
	if linha > 10 or linha = 0 then
		let linha = 10
	end if
	if coluna > 13 or coluna = 0 then
		let coluna = 13
	end if
	if tot_col = 0 then
		let tot_col = 60
	end if

	let contador = length(desc1 clipped)
	let mycol = (tot_col-contador)/2

	open window w_mesg at linha, coluna with 10 rows, tot_col columns
	attribute(border)
		
	display desc1 clipped at 2, mycol  attribute(reverse)

	let col_inic = (tot_col/2)-13
	let aux = "                         "
	display aux at 7, col_inic attribute(reverse)

end function

# funcao para fechar a janela (w_mesg) aberta na funcao start_count()
function stop_count()
	close window w_mesg
end function


# funcao que faz o display do ponto em que se encontra o processamento
# desc2 - do que esta a ser processado
# nn - ponto em que esta o processamento
# mm - total de processamentos
# tot_col - numero total de coluna, 'e conveniente que seja igual ao valor
#           na funcao start_count()
function st_count(desc2,nn,mm,tot_col)
define 
	desc2 char(50),
	nn, mm, tot_col integer

define
	contador , i integer,
	col, col_inic integer,
	aux char(25)

	if tot_col = 0 then
		let tot_col = 60
	end if

	let col_inic = (tot_col/2)-13
	call fgl_drawbox(3,28,6,col_inic-1)

	let contador = length(desc2 clipped)
	let col = (tot_col-contador)/2
	# sera que e mesmo assim
	if desc2 != last_mesg {and last_mesg is not null and desc2 is not null} then
		display  "                                                           " 
				  at 4,1 
	end if

	display desc2 clipped at 4, col  attribute(reverse)

	let contador = length(aux clipped)
	let col = (tot_col-contador)/2
	let contador = (nn*100)/mm
	let aux = contador using "<<<&", "%"
	display aux clipped at 9, col 

	if last_printed=0 then
		let last_printed=col_inic
	end if
	let contador = (nn*25)/mm
	let contador = col_inic+contador
	for i=last_printed to contador
	   display "." at 7, i
	end for
	let last_printed=i
	let last_mesg=desc2

end function
