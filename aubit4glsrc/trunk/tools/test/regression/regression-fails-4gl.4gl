#regression-fails.4gl
#
#This file is used to demonstrate new bugs caused by syntax errors while
#compiling
#
#
#If you want to report a syntax problem bug, please add it to
#regression-fails.4gl file, commit it back to CVS and notify developer
#using mailing list. If you do not have access to commit things to CVS,
#please send it to mailing list
#
# Do NOT remove existing code!
#
# After problem is ficxed, please move that code to regression-test.4gl
#
# Thank you for reporting bugs!
#
#
#
#############
# DO NOT ATTEMPT TO RUN THIS!!!
# This is to pick up compiler errors only!
#
database maindb
globals "regression-test-4gl.4gl"


globals
   define
      msgresp char(1),
      pr_company record like company.*,
      pr_wA630,
      pr_wA144 smallint
end globals


main

    display "You are not supposed to run this - this is for testing compiler only!"
    exit program

end main


function disp_info(buttons)
#|________________________^
#| Error at line 142, character 26
#| parse error ()

define buttons char (15)

end function


########################
function fails_still()
########################
define
	l_wcol,
    l_depth,
	m_width,
	l_menuline
        smallint ,
    a,
    b,
    c
        char(20) ,
      pr_src_prodstatus,
      pr_dst_prodstatus record like prodstatus.*
#|______________________^
#| Error at line 3593, character 24
#| Too many variables ()




grant connect to "nobody";


revoke all on notes from "public";


create table whics_payments
  (
    create_date_time datetime year to fraction(3)
  );



########################################## (1) /data2/maximise/max_4.01.12/eo/E52e.err :

#                  let pa_line[idx][6,66] = charvar
                  let a_load[idx][6,66] = charvar
#|_________________________________^
#| Error at line 255, character 35
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/dvfund/dvfund_mod2.err :
      alter table tax_trans add (tax_rate decimal(8,2))
#|________________^
#| Error at line 12, character 18
#| parse error ()




#this one should have "msgresp" defined in GLOABLS "filename" and will fail:
########################################## (2) /data2/maximise/max_4.01.12/main/UPOSMENUR.err :
#      let msgresp = maxmsg("U",1,"This Program can only be run from TOPMENUR")
#|_________________^
#| Error at line 76, character 19
#| msgresp is not a variable ()



      OPEN WINDOW qdwin AT 6, l_wcol
      WITH l_depth ROWS, m_width COLUMNS
      ATTRIBUTE(BORDER, CYAN, MESSAGE LINE LAST, MENU LINE l_menuline)
#|___________________________________________________________________^
#| Error at line 393, character 69
#| parse error ()


        connect to ptest user "postgres" using "pg"
#|_______________________^
#| Error at line 173, character 25
#| parse error ()


#This WILL compile to C, but cause "ptest undeclared" when linking:

--!		connect to ptest user "postgres" using "pg"

#it should detect not defined variable in 4glc, like 4Js does:
#| The symbol 'ptest' does not represent a defined variable.
#| See error number -4369.





display ' \"'
#|__________^
#| Error at line 6, character 12
#| parse error ()


	display array a_load to screenrec.*

	ON KEY(f28,nextpage,CONTROl-N) #edna stranica nadolu
#|_________________^
#| Error at line 396, character 19
#| parse error ()

    end display


menu "select db"
    command "maindb"

                database maindb
#|____________________________^
#| Error at line 111, character 30
#| 'database' does not represent a defined variable (1) ()

                exit menu
end menu



end function

#################################################
function inv_lineshow(cmpy,pr_arparms,
                           pr_invoicehead,
                           pr_customer,
                           pr_customership)
#################################################
   define
      pr_invoicehead record like invoicehead.*,
      pr_customer record like customer.*,
      pr_arparms record like arparms.*,
      pr_customership record like customership.*,
      cmpy char(2)
   let quit_flag = false
   return
end function
#|_________^
#| Error at line 26, character 11
#| FUNC was not last block command
# ()


#################################################
report blah22()
#################################################
define
oparr array[30] of record       #za zadawane na operacii i prioritetite im
                        op char(10),
                        prior smallint,
#|_______^
#| Error at line 49, character 9
#| parse error ()
                        arg smallint
   end record


   OUTPUT REPORT TO PRINTER
#|________________________^
#| Error at line 606, character 26
#| parse error ()

    format

        on every row
            print "xxx"
end report


############################# EOF #####################################


