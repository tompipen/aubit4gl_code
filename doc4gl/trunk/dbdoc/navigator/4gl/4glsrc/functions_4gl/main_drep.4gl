database despodata 

MAIN
    define
       fmt char(19),
		 pr_diario record
			 ndoc like movico.mov_ndoc,
			 nlanc like movico.mov_nlanc,
			 data like movico.mov_data
		 end record,
		 str_rep char(250),
		 ret_str  char(100),
		 col_curr smallint,
		 tamanho  smallint,
       tp  smallint

    let tp = null

    call d_start_drep()
	 call d_init_drep(6)
	 call d_new_header("Despodata",1,"N")
	 call d_new_header("Diario de operacoes diversas",2,"N")
	 call d_new_header("Movimentos entre 1/1/93 e 1/2/93",3,"S")
	 call d_new_header("NDOC NLANC DATA     ",4,"S")
	 call d_new_separador(4,1,5)
	 call d_new_separador(4,2,11)
	 call d_new_separador(4,3,20)
	 declare cr_diario cursor for
		 select mov_ndoc, mov_nlanc, mov_data from movico9302 
	 open cr_diario
	 call d_format_header()
	 foreach cr_diario into pr_diario.*
	    let col_curr = 1
		 let str_rep = pr_diario.ndoc, pr_diario.nlanc, pr_diario.data
		 let ret_str = pr_diario.ndoc
       call drep_format_column(ret_str,1,"<<<<",4) returning tamanho, ret_str
       if col_curr > 1 then
         let str_rep = str_rep[1,col_curr], ret_str[1,tamanho]
       else
         let str_rep = " ", ret_str[1,tamanho]
       end if
       let col_curr = col_curr + tamanho + 1

		 let ret_str = pr_diario.nlanc
       call drep_format_column(ret_str,1,"<<<<",4) returning tamanho, ret_str
       if col_curr > 1 then
         let str_rep = str_rep[1,col_curr], ret_str[1,tamanho]
       else
         let str_rep = " ", ret_str[1,tamanho]
       end if
       let col_curr = col_curr + tamanho + 1

		 let ret_str = pr_diario.data
       call drep_format_column(ret_str,7,"",8) returning tamanho, ret_str
       if col_curr > 1 then
         let str_rep = str_rep[1,col_curr], ret_str[1,tamanho]
       else
         let str_rep = " ", ret_str[1,tamanho]
       end if
       let col_curr = col_curr + tamanho + 1

		 call d_rd_drep(str_rep,6)
	 end foreach
	 call d_close_drep(6)


	 call d_visualiza_drep()
    call d_end_drep()
END MAIN
