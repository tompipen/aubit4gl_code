main
define
	dummy char (1),
    file char(2),
    smallint_val smallint,
    rrr record
        dummy char(1)
    end record

    display "xxx"

#    p4gl: P21.4gl, Line 97: parse error
				let dummy = menu(dummy)

#    p4gl: P71.4gl, Line 697: parse error
				let dummy  = dummy clipped, ".",
                               (smallint_val + 1) using "&&&"

#    p4gl: PR2.4gl, Line 106: parse error
		   construct by name rrr.dummy on vendor.vend_code,
                                            vendor.type_code,
                                            vendor.name_text,
                                            vendor.currency_code,
                                            vendor.term_code,
                                            vendor.tax_code,
                                            voucher.year_num,
                                            voucher.period_num
      attribute(cyan)

#    p4gl: PSL_J.4gl, Line 1007: parse error
            prompt " Enter target file name: " for file

#    p4gl: PSU_J.4gl, Line 131: parse error
            call unload()

#    p4gl: PSV.4gl, Line 68: parse error
         call verify()

#    p4gl: PX3_J.4gl, Line 145: parse error

   select count(unique pay_doc_num) into dummy from tentpays
      where cmpy_code = cmpy
        and cycle_num = pr_cycle_num
        and status_ind = "4"


end main


function menu(dummy)
define dummy char (1)

    return dummy

end function



function unload()

end function



function verify()

end function


report xyz()
define dummy char (1),
    x smallint


format
    on every row

            print "xxx"

#    p4gl: P34k.4gl, Line 509: parse error
				print 54 spaces

#    p4gl: P6A.4gl, Line 479: parse error
				 print column 25, dummy clipped wordwrap right margin x

#    p4gl: P73.4gl, Line 336: parse error
		 print column 10, dummy clipped,
               column 25, dummy clipped wordwrap
                          right margin x #<<<< cause

     print "03",dummy,
            dummy using "ddmmyy",
            (x * 100) using "&&&&&&&&&&&&&"


end report


