
# Abertura das janelas para menus verticais

function open_win(lin,col,opc,cmp,nivel_w)
   define
		lin, col, opc, cmp , nivel_w smallint

	case
		when nivel_w = 1
         OPEN WINDOW WmenuVert1 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 2
         OPEN WINDOW WmenuVert2 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 3
         OPEN WINDOW WmenuVert3 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 4
         OPEN WINDOW WmenuVert4 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 5
         OPEN WINDOW WmenuVert5 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 6
         OPEN WINDOW WmenuVert6 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 7
         OPEN WINDOW WmenuVert7 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 8
         OPEN WINDOW WmenuVert8 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
		when nivel_w = 9
         OPEN WINDOW WmenuVert9 AT lin,col WITH opc ROWS, cmp COLUMNS 
		      ATTRIBUTE (BORDER)
	end case
end function


# Faz da janela pretendida a janela corrente

function curr_win(nivel_w)
   define
		nivel_w smallint

	case
		when nivel_w = 1
         CURRENT WINDOW is WmenuVert1
		when nivel_w = 2
         CURRENT WINDOW is WmenuVert2
		when nivel_w = 3
         CURRENT WINDOW is WmenuVert3
		when nivel_w = 4
         CURRENT WINDOW is WmenuVert4
		when nivel_w = 5
         CURRENT WINDOW is WmenuVert5
		when nivel_w = 6
         CURRENT WINDOW is WmenuVert6
		when nivel_w = 7
         CURRENT WINDOW is WmenuVert7
		when nivel_w = 8
         CURRENT WINDOW is WmenuVert8
		when nivel_w = 9
         CURRENT WINDOW is WmenuVert9
	end case
end function


#  ============================================================================ 
#  Fecha a janela correspondente ao menu
#  ============================================================================ 
FUNCTION close_win(nivel_cascata)
{}
  DEFINE nivel_cascata SMALLINT

  CASE
	 WHEN nivel_cascata = 1
     CLOSE WINDOW WmenuVert1
	 WHEN nivel_cascata = 2
     CLOSE WINDOW WmenuVert2
	 WHEN nivel_cascata = 3
     CLOSE WINDOW WmenuVert3
	 WHEN nivel_cascata = 4
     CLOSE WINDOW WmenuVert4
	 WHEN nivel_cascata = 5
     CLOSE WINDOW WmenuVert5
	 WHEN nivel_cascata = 6
     CLOSE WINDOW WmenuVert6
	 WHEN nivel_cascata = 7
     CLOSE WINDOW WmenuVert7
	 WHEN nivel_cascata = 8
     CLOSE WINDOW WmenuVert8
	 WHEN nivel_cascata = 9
     CLOSE WINDOW WmenuVert9 
  END CASE
end function
