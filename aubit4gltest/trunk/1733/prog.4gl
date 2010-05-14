DEFINE 
	b_p		ARRAY[50] OF RECORD 
		ic_pac	integer,
		dat_zaps	char(14),
		vaha	integer
		END RECORD,
	hlaska		CHAR(80)


MAIN

OPTIONS
        insert key f4,
        delete key f3,
        accept key f12,
        help key f1


OPEN WINDOW w_okno AT 1,1 WITH FORM "testIn"

CALL inp_b()
CLOSE WINDOW w_okno

END MAIN

#######   ..................................................    #######

function inp_b()   
    define
      arr_row		smallint,
	  scr_row		smallint,
      dummy,b_count         integer,
	  exit_code 	char(10)
    
    current window is w_okno
    
    input array b_p without defaults from b_s.* 
        on key (f2)
            let scr_row = scr_line()
            let arr_row = arr_curr()
            if infield(ic_pac) then
              let b_p[arr_row].ic_pac = 333
		if field_touched(ic_pac) then
			display "It was touched before" sleep 2
		end if
              display b_p[arr_row].ic_pac to b_s[scr_row].ic_pac 
		if field_touched(ic_pac) then
			display "It was touched" sleep 2
		end if
            end if
    end input

    let b_count = arr_count()
    let hlaska = "end input arr_count()=",b_count
    display hlaska
    sleep 3
	if b_count!=1 then
		exit program 1
	end if
    return 
end function 
