#regression-test.4gl
#
#This file is used as regression test to verify that things still work
#after compiler changes. All code in this file is confirmed to compile
#successfully at some point in time. You can use CVS log on this file
#to find exactly when things worked, and when something was added to this
#file.
#
#To demonstrate new problems, please add them to regression-fails.4gl
#
#If you want to report a syntax problem bug, please add it to
#regression-fails.4gl file, commit it back to CVS and notify developer
#using mailing list. If you do not have access to commit things to CVS,
#please send it to mailing list
#
#
# Do NOT remove existing code!
#
# Thank you for reporting bugs!
#
#
#############
# This used to cause loads of bugs...
# DO NOT ATTEMPT TO RUN THIS!!!
# This is to pick up compiler errors only!
#


##############################
globals
##############################
define

	pr_cal_available_flag
		integer,
	f1
		integer,
	f2 record
		a integer,
		a1 integer
	end record

define
        a_load array [1000] of char (200),
        a_load_size,
        a_load_full,
        idx
            smallint


#globals "regression-test-4gl.4gl"
#globals
#|____^
#| Error at line 53, character 6
#| parse error ()
#above error would happen when GLOBLS "file" is followed by another GLOBALS



    define blah char (4),
    intvar
        integer,
    charvar
        char(10)


##--##Querix will catch this one, but not 4js and Aubit:
##--##define
##--##        a_load array [1000] of char (200)
##--##define idx smallint
##--##define
##--##	f1
##--##		integer,
##--##	f2 record
##--##		a integer,
##--##		a1 integer
##--##	end record
##--##
##--##
##--##


##--##
##--##		a_load_size,
##--##        a_load_full,
##--###| The symbol 'a_load_full' has been defined more than once.
##--###| See error number -4319.
##--##        idx
##--###| The symbol 'idx' has been defined more than once.
##--###| See error number -4319.
##--##            smallint
##--##
##--##
end globals


#module level:
define
	f3,

##--##	charvar
##--##		char(20),
##--##    intvar,
##--##	pr_cal_available_flag,
##--##
    i
		integer,
    datevar
        date,
    datetimevar
        datetime year to second




########
main
########

    display "You are not supposed to run this - this is for testing compiler only!"
    exit program

	#################################################
    #following functions should compile OK:

	call compiles_ok()

	call this_fails_on_19062001()

end main


#####################################################
function compiles_ok()
#####################################################
#code in this function is verified to compile OK in some point in time
#please move all corrected bugs from regression-fails.4gl to
#this file after bug is resolved:

let f1=1

prompt "Hello" attribute(cyan) for f1 attribute(red)
on key(f1) display "f1"
on key(f2) display "f2"
on key(f10) display "f10"
on key(f11,f12,f14) display "f10+"
on key(tab) display "Tab"
end prompt

select * from systables where tabname=user


#Whith 4Js, the following statement requires:
#database maindb
#and it will generate error:
#| The number of columns must match the number of values in the SET clause of an UPDATE statement.
#| See error number -4464.
update maxreport set * = f2.*

menu "m1"
	command "Test0"
	command key(f1)  "Test1"
		display "Hello"
	command key(f2,Q)  "Test1"
		display "Hello"
end menu


select * from mytab where status_ind not in ("4","c")

display "Hello"

##--##Querix don't like this:
##--##go to lab1
##--##
display "Sun"
label lab1:
display "World"

display pr_cal_available_flag

if f3 not matches "[1234]" then
	display "OK"
end if


end function #compiles_ok()


#######################################################################
function this_fails_on_19062001()
#######################################################################
#added by AF, code from Maximise/winds
define
    something char (10)

define g_address record
    oneline char(1),
    anotherline char(2)
end record

define
        a_load array [1000] of char (200),
        a_load_size,
        a_load_full
            smallint


define
  	a_names array[40] of record

        name char(15)
#|___________^
#| Error at line 4298, character 13
#| parse error ()
    end record

#hmmm, this don't work in 4Js eather:
#create database charvar
#| A grammatical error has been found at 'database' expecting: LIKE BYTE CHAR CHARACTER DATE DATETIME ...
#| See error number -6609.


        if a_load[intvar][1,5] = "grant" then
#|_____________________^
#| Error at line 123, character 23
#| parse error ()
        message "blah"
        end if

##################################################

#   while true
#      clear form
#      initialize pa_default.* to null
#      call enter_voucher(cmpy,whom,"","","")
#         returning pr_voucher.*, pr_vouchpayee.*
      let intvar = xmenu(intvar, charvar, f2.*,
#|____________________________________^
#| Error at line 135, character 38
#| parse error ()
                                       f2.*,'1')
#      if pr_voucher.vouch_code <= 0 then
#         exit while
#      end if
#   end while


##################################################

#      after field country_code
         clear vendor.country_text
         if something is null
#|__________^
#| Error at line 435, character 12
#| parse error ()
        then
            message "blah"
        end if

LOAD FROM "filename" INSERT INTO table
#|___________________________________^
#| Error at line 6, character 37
#| parse error ()


   for intvar = 1 to 500
      initialize a_names[intvar] to null
#|___________________________________________^
#| Error at line 118, character 45
#| Error processing record - missing item variable ? ()
   end for


------------------

      case # ensure date is still within valid range...
         when datevar is null
            let datevar = null#i.e. 31/12/1899
            error ""
#|________________^
#| Error at line 1537, character 18
#| parse error ()
         when datevar < datevar


---------------------

      let charvar = ascii charvar,
#|___________________________________^
#| Error at line 896, character 37
#| parse error ()
         ascii intvar

      end case

-------------------------




		 if charvar = "2" then
            error" ",charvar clipped,
#|__________________^
#| Error at line 752, character 20
#| parse error ()
                 " is configured as a Terminal"
#            next field dest_print_text
         else
	         message "blah"
         end if

--------------------------


      case # ensure date is still within valid range...
         when datevar is null
            let datevar = null#i.e. 31/12/1899
--#            error ""
         when datevar < datevar
#|____________^
#| Error at line 1538, character 14
#| parse error ()
            let datevar = datevar
            error ""
      end case


-----------------------------------




        initialize g_address to null
#|______________________________^
#| Error at line 1711, character 32
#| Error processing record - missing item variable ? ()


            message""
#|_________________^
#| Error at line 585, character 19
#| parse error ()


                return null
#|________________________^
#| Error at line 1276, character 26
#| parse error ()


    prepare x2 from " insert into act_desc values (?)"
    declare c_read_addr scroll cursor with hold for x2
#|_____________________________^
#| Error at line 1384, character 31
#| parse error ()

#agingfunc.err : ###################################################
    case something

	  when "1"
         let datevar = mdy(month(charvar),1,year(charvar))
         let datevar = datevar + 2 units month
#|___________________________________________________^
#| Error at line 47, character 53
#| parse error ()

    end case

#cpartwind.err : ###################################################
      construct by name charvar on req_num,
                                      person_code,
                                      req_date,
                                      stock_ind,
                                      status_ind
      attribute(cyan)
#|_____________^
#| Error at line 107, character 15
#| parse error ()


#invdfunc.err : ###################################################
#         end if
#         call inv_show(pr_invoicedetl.*)
      on key(return)
#|_________________^
#| Error at line 293, character 19
#| parse error ()
            message "blah"

      end construct

         options accept key control-m

#########################

   input by name charvar
        without defaults
        attribute(cyan)
      before field dest_print_text
         let charvar = 9999
         display by name charvar
            attribute(cyan)
      after field dest_print_text
         select * into charvar from printcodes
          where 1 = 1
         if status = notfound then
            error" Printer Configuration Not found - Try Window "
#|_____________________________________________________________^
#| Error at line 745, character 63
#| parse error ()
            next field dest_print_text
         end if


      end input



#jourintf.26052000.err : ###################################################

    case charvar
         when(intvar < 0)
            let intvar = -intvar
#|________________________________________________^
#| Error at line 282, character 50
#| parse error ()
    end case


#pinfowind.err : ###################################################
#            next field info_ind
#         end if
         if charvar not matches'[1234]' then
#|________________________________________^
#| Error at line 309, character 42
#| parse error ()
            message "blah"
         end if

#reptfunc.err : ###################################################
#                      pr_rmsreps.report_time
   let datetimevar = charvar
   if datetimevar <= current + 1 units minute then
#|_____________________________________^
#| Error at line 545, character 39
#| parse error ()
        message "blah"
   end if

#secufunc.err : ###################################################

   let intvar = false
   let datetimevar = current - 1 units minute
#|________________________________________________^
#| Error at line 237, character 50
#| parse error ()

-----------------------------------

      input charvar without defaults from change_ind
         after field change_ind# prevents null value
            let charvar = get_fldbuf(change_ind)
#|____________________________^
#| Error at line 1586, character 30
#| parse error ()
            if charvar is null then
               let charvar = " "
            end if
      end input
---------------------------


      for intvar = 2 to 3
          for i = 32 to 90
             if (ASCII(i)) = charvar[intvar,intvar] then
#|_____________________^
#| Error at line 1667, character 23
#| parse error ()
                exit for
             end if
          end for
          let i = i - 32
          let intvar = (intvar * 100) + i
      end for

-----------------------------------

   let charvar = charvar, ASCII(46), " ",charvar
#|___________________________________^
#| Error at line 1903, character 37
#| parse error ()


------------------------------------


#|____________^
#| Error at line 2278, character 14
#| parse error ()

		let intvar = status

end function #this_fails()


############################# EOF #####################################

function x2menu()
end function



#######################################################################
function this2_fails_on_19062001()
#######################################################################
#added by AF, code from Maximise/winds
define
    something char (10)

define g_address record
    oneline char(1),
    anotherline char(2)
end record

	connect to charvar user charvar using charvar
#|_______^
#| Error at line 82, character 9
#| parse error ()


#actimage.err : ###################################################

      prepare i_1 from "select * from sometable"
      declare ins_j_curs cursor for i_1

	  open ins_j_curs
      for intvar = 1 to intvar
         put ins_j_curs from charvar

#|___________^
#| Error at line 560, character 13
#| parse error ()

    end for

end function #this_fails()


##########################################################################
function fails_on_30_08_01 ()
##########################################################################
   define
      pr_avail_cred_amt dec(16,2),
#|_________________________^
#| Error at line 630, character 27
#| parse error ()

###################################

   password           char(6),
#|__________^
#| Error at line 124, character 12
#| parse error ()
##########################################################

      line char(132),
#|_________^
#| Error at line 269, character 11
#| parse error ()
##########################################################

#   pr_coa record like coa.*,
#|_________________________^
#| Error at line 510, character 27
#| You cannot use LIKE without specifying a database ()
	pr_coa record
		a integer,
		a1 integer
	end record,

   foreign, base, potential, variance char(20),
#|________^
#| Error at line 347, character 10
#| parse error ()
##########################################################

	  exists smallint,
#|___________^
#| Error at line 308, character 13
#| parse error ()
##########################################################

      mode char(4),
#|_________^
#| Error at line 145, character 11
#| parse error ()
##########################################################

      option, msgresp char(1),
#|__________^
#| Error at line 89, character 12
#| parse error ()
##########################################################

	ga_deposit1 ARRAY[200] OF RECORD
       indicator CHAR(2)
#|_______________^
#| Error at line 85, character 17
#| parse error ()
##########################################################
    end record,
    runner,unl_stmt,
	file_name,
    pr_output
		 char (100),
	start_line,
	end_line,
    file_tmp1
        integer


      if sqlca.sqlcode = 0 then
#|_____________________^
#| Error at line 39, character 23
#| parse error ()

        display "xxx"
   end if

##########################################################


   start report print_maxlog to pr_output
   output to report print_maxlog()
#|______________________________^
#| Error at line 244, character 32
#| parse error ()

##################################################

   let unl_stmt = "SELECT tabname, tabid, tabtype ",
                  "FROM 'informix'.systables WHERE tabid > 99 ",
                  "AND tabname matches '",
                  charvar clipped,
                  "'"
   unload to charvar unl_stmt
#|__________________________________^
#| Error at line 296, character 36
#| parse error ()
--

###################################################
#/data2/maximise/max_4.01.12/main/U1D.err :
            if intvar or
               intvar != intvar or
               charvar != intvar or      #M 1588
               intvar != charvar then

               if exists(intvar,
#|______________________^
#| Error at line 282, character 24
#| parse error ()
                         charvar,                    #M 1588
                         intvar) then
                    display "blah"
                end if
            end if

##########################################################

   create temp table t_flatfile(line char(150)) with no log
#|___________________________________^
#| Error at line 53, character 37
#| parse error ()
--


LABEL headlab:
      CALL header()
#|_______________^
#| Error at line 168, character 17
#| parse error ()

##########################################################

   drop index XxZz249
#|__________________^
#| Error at line 853, character 20
#| parse error ()
##########################################################
#/data2/maximise/max_4.01.12/ar/ASW.err :

            if unload(1) then end if
#|___________________^
#| Error at line 129, character 21
#| parse error ()
##########################################################


            let intvar = 0.0
#|____________________________________________^
#| Error at line 154, character 46
#| parse error ()
##########################################################



#######################################################################################################
#######################################################################################################
#
#   This dumps core on CygWin:
#
#######################################################################################################
#######################################################################################################


   update warehouse
      set next_sched_date = current + auto_run_num units minute
#|____________________________________________________________^
#| Error at line 568, character 62
#| parse error ()
##########################################################


#######################################################################################################
#######################################################################################################


   update menu2
      set security_ind = (select (min (menu3.security_ind)) from menu3
#|_______________________________^
#| Error at line 553, character 33
#| parse error ()
                           where menu1_code = pr_menu1.menu1_code
                             and menu2_code = pr_menu2.menu2_code)
    where menu2_code = pr_menu2.menu2_code
      and menu1_code = pr_menu1.menu1_code




##########################################################



               insert into t_salescomm values(pr_invoicehead.sale_code,
                                              pr_invoicehead.cust_code,
                                              pr_invoicehead.inv_num,
                                              pr_invoicehead.inv_date,
                                              pr_invoicehead.total_amt,
                                              pr_invoicehead.currency_code,
                                              pr_invoicehead.paid_amt,
                                              100.0
#|________________________________________________^
#| Error at line 215, character 50
#| parse error ()

                                )

##########################################################


            drop index customer3_key
#|_________________________________^
#| Error at line 1065, character 35
#| parse error ()
##########################################################


                    select count(unique cust_code) into charvar from statsale
#|______________________________________^
#| Error at line 548, character 40
#| parse error ()
##########################################################


    display array a_load to screen_rec.*
       on key (esc)
#|________________^
#| Error at line 906, character 18
#| parse error ()

    end display

##########################################################


    input by name f2.a thru f2.a1
#|__________________________________________^
#| Error at line 242, character 44
#| parse error ()
##########################################################


     OPTIONS
        MESSAGE LINE FIRST,
        ACCEPT KEY ESC
#|____________________^
#| Error at line 61, character 22
#| parse error ()
##########################################################

    start report audit to charvar
#|_____________________^
#| Error at line 166, character 23
#| parse error ()

###########################################################



      if intvar = 1.0 then
#|_________________________________^
#| Error at line 237, character 35
#| parse error ()
        display "xxx"
      end if


##########################################################


   if intvar > 999999999.99
#|______________________________________^
#| Error at line 338, character 40
#| parse error ()

    then
        display "xxx"
   end if

##########################################################


      drop index hold_ind
#|______________________^
#| Error at line 145, character 24
#| parse error ()
##########################################################


declare item_curs cursor for
   select colitem.*, mrwitem.*, colitemcolid.id_col_id
     from colitem, mrwitem, outer( colitemcolid )
#|________________________________^
#| Error at line 280, character 34
#| parse error ()
##########################################################


        call update()
#|_________________^
#| Error at line 39, character 19
#| parse error ()
##########################################################


   for i = 2 to 0 step -1
      let intvar = idx / (100 ** intvar)
#|______________________________________________^
#| Error at line 404, character 48
#| parse error ()

    end for

##########################################################


   select * into charvar from glparms
    where cmpy_code = charvar
      and key_code = "1"
   let f2.*  = f2.*
   let intvar   = 0
#|_____^
#| Error at line 644, character 7
#| Number of variables in let not equal to number of values
##########################################################


#######################################################################################################
#######################################################################################################
#
#   This dumps core on CygWin:
#
#######################################################################################################
#######################################################################################################

	  select sum(tran_qty) into intvar from prodledg
       where part_code = charvar
         and cmpy_code = charvar
         and (trantype_ind = "S"
             or trantype_ind = "C")
         and tran_date <= today
         and tran_date >= (today - 1 UNITS YEAR)
#|_____________________________________________^
#| Error at line 286, character 47
#| parse error ()
###########################################################

#######################################################################################################
#######################################################################################################



               let charvar = "ISP - invoice header update"
               update invoicehead
                  set cost_amt =
                     (select sum(ext_cost_amt)
#|___________________________^
#| Error at line 928, character 29
#| parse error ()
                         from invoicedetl
                         where invoicedetl.inv_num = pr_source_num
                           and invoicedetl.cmpy_code = cmpy)
               where inv_num = pr_source_num
                 and cmpy_code = cmpy

##########################################################
# /data2/maximise/max_4.01.12/in/IT3.err :

            select count (unique ware_code)
#|_______________________________^
#| Error at line 235, character 33
#| parse error ()
              into charvar
              from stktakedetl
             where cmpy_code = cmpy
               and cycle_num = charvar

##########################################################

         call warning()
#|___________________^
#| Error at line 407, character 21
#| parse error ()
##########################################################



      let intvar = menu(charvar, charvar, f2.*)
#|____________________________________^
#| Error at line 135, character 38
#| parse error ()
##########################################################


      start report P96_recon to pr_output
      output to report P96_recon()
#|______________________________^
#| Error at line 404, character 32
#| parse error ()
##########################################################


#Running 4glpc PR9.4gl -c -o PR9.ao (in /data2/maximise/max_4.01.12/ap):
########################################## (1) /data2/maximise/max_4.01.12/ap/PR9.err :

           select sum(voucher.total_amt) into intvar from voucher
            where year(voucher.vouch_date) = year(agedate)
#|____________________^
#| Error at line 325, character 22
#| parse error ()
##########################################################



                     let intvar
                       = intvar
                       - (idx * (intvar / 100.0))
#|__________________________________________________________________________^
#| Error at line 4277, character 76
#| parse error ()
##########################################################


   create temp table t_flatfile(line char(150)) with no log
#|___________________________________^
#| Error at line 111, character 37
#| parse error ()

        UPDATE appeal
        SET    cost_items =
            	(SELECT sum(appeal_cost.amount)
#|___________________^
#| Error at line 242, character 21
#| parse error ()

		 FROM   appeal_cost
        	 WHERE  appeal_cost.appeal_year = gr_table_rec.appeal_year
        	 AND    appeal_cost.source_code = gr_table_rec.source_code
        	 AND    appeal_cost.disp_code   = gr_table_rec.disp_code),
               last_modify_by = gv_username,
               last_modify_date = gv_current
        WHERE  appeal.appeal_year      = gr_table_rec.appeal_year
        AND    appeal.source_code      = gr_table_rec.source_code
        AND    appeal.disp_code        = gr_table_rec.disp_code



##########################################################

    input by name charvar

    ON KEY(ESC)  ### doesn't seem to work
#|____________^
#| Error at line 776, character 14
#| parse error ()

        message "blah"

    end input


##########################################################

   lock table jmj_impresttran in exclusive mode
#|____________________________________________^
#| Error at line 183, character 46
#| parse error ()
##########################################################

         lock table cashreceipt in share mode
#|__________________________________________^
#| Error at line 225, character 44
#| parse error ()
##########################################################




end function



##########################################################################
report report_fails_on_30_08_01(pr_vendor)
##########################################################################
define
	l2_vend_bal_amt,
	l3_vend_bal_amt,
	tot_vend_local_bal_amt
		integer,
    where_text
        char (100),
#      pr_vendor record like vendor.*,
#|__________________________________^
#| Error at line 963, character 36
#| You cannot use LIKE without specifying a database ()
	pr_vendor record
		a integer,
		a1 integer,
        vend_code char (10)
	end record,


#      pr_voucher record like voucher.*,
#|____________________________________^
#| Error at line 973, character 38
#| You cannot use LIKE without specifying a database ()
#      pr_voucherpays record like voucherpays.*

pr_voucherpays record
		a integer,
		a1 integer
	end record

   output
      left margin 0
   format
   page header


###########################################################
   #/data2/maximise/max_4.01.12/ap/PR9.err :

            print
			column intvar, charvar," (Menu-PR9)"
      print column 1,"--------------------------------------------",
                     "--------------------------------------------",
                     "--------------------------------------------"
      if pageno = 1 then
         let l3_vend_bal_amt = 0
         let tot_vend_local_bal_amt = 0
      end if


   on last row
      skip to top of page
      skip 4 lines
      print column  1, "Selection Criteria:",
            column 25, where_text clipped wordwrap right margin 68
#|_________________________________________________^
#| Error at line 183, character 51
#| parse error ()
##########################################################

      if group sum(intvar) = 0 then
         print column 18, "Avg Rate",
               column 39, 0.00;
#|__________________________^
#| Error at line 721, character 28
#| parse error ()

    end if

##########################################################


         let charvar = "Job Management Product Issue",
                     3 spaces, "Date:", 1 spaces,
                     today, 1 space, time
#|_________________________________^
#| Error at line 1066, character 35
#| parse error ()
##########################################################



         print column 1, charvar clipped,":",
                         1 space
#|______________________________^
#| Error at line 375, character 32
#| parse error ()
##########################################################


end report


#****************************************************************************

function resource(intvar)
define
    intvar
        integer

#|_______________^
#| Error at line 511, character 17
#| parse error ()
##########################################################


end function



report audit(charvar, intvar, idx,mess)
#|__________^
#| Error at line 191, character 12
#| parse error ()
##########################################################

define
    mess,charvar, intvar, idx
        char (100)


   output
      left margin 0
   format
   page header

    print "blah"


end report

function update_part(hold)
#|_______________________^
#| Error at line 657, character 25
#| parse error ()
define
    hold
        char (3)


##########################################################

end function


report P96_recon()

   output
      left margin 0
   format
   page header

   print "blah"

end report

function menu(cmpy, whom, f2)
define
cmpy, whom
    integer,
	f2 record
		a integer,
		a1 integer
	end record

    return 1


end function


FUNCTION lock_record(fv_table_name, fv_rowid)

DEFINE
    fv_table_name CHAR(20),
    fv_rowid INTEGER,
    fv_statement_str CHAR(80)

    BEGIN WORK

    LET fv_statement_str =
       "SELECT * FROM ", fv_table_name CLIPPED,
       " WHERE rowid = ? FOR UPDATE"

    PREPARE lock_id FROM fv_statement_str
    DECLARE update_curs CURSOR FOR lock_id
    OPEN    update_curs USING  fv_rowid
    FETCH   update_curs INTO   f2.*

END FUNCTION




###################################
function at_05_09_2001()
###################################
define
	runner,unl_stmt,
	file_name,
    pr_output,
    comment
		 char (100),
	start_line,
	end_line,
    file_tmp1
        integer


########################################## (1) /data2/maximise/max_4.01.12/contr/C21.err :

#    DISPLAY gr_cont_line.cont_code THRU gr_cont_line.bank_branch
     DISPLAY f2.a THRU f2.a1


#|______________________________________^
#| Error at line 1368, character 40
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/contr/C24.err :

INSERT INTO cont_trans VALUES (charvar,
#    fr_cont_line.cont_code THRU fr_cont_line.disp_code,
    f2.a THRU f2.a1,
#|______________________________^
#| Error at line 309, character 32
#| parse error ()
	charvar)                                      #MJW


#######################################
#/data2/maximise/max_4.01.12/csimods/URS.err:

      let runner = "sed -n \"",start_line using "<<<<<<" clipped,",",
                    end_line using "<<<<<<" clipped," p\"",
                   " < ",file_name clipped, "| sed \"s/$/\
/\" > ",
                   file_tmp1 clipped," 2>>maxlog"
      run runner


##--##
##--##      let runner = "sed -n \"",start_line using "<<<<<<" clipped,",",
##--##                    end_line using "<<<<<<" clipped," p\"",
##--##                   " < ",file_name clipped, "| sed \"s/$/\
##--###|_______________________________________________________^
##--###| Error at line 1071, character 57
##--###| parse error ()
##--#############################################
##--##/\" > ",
##--##                   file_tmp1 clipped," 2>>maxlog"
##--##




#This should need (????):
#########################
#declare zz cursor for
#########################
      select glparms.*
         into f2.*
         from glparms
         where glparms.cmpy_code = charvar
           and glparms.key_code = "1"
         for update of next_jour_num
#|_____________________^
#| Error at line 319, character 23
#| parse error ()
##########################################################



############################################################


            let intvar =
            ( ( intvar
             * intvar) +
             + ( intvar *
#|______________^
#| Error at line 818, character 16
#| parse error ()
                 intvar))
            /(intvar+intvar)

##########################################################


##########################################################
#/data2/maximise/max_4.01.12/contr/CZ1.err :

   CALL lock_record(charvar, intvar)

    UPDATE mail_disc SET * = (gr_table_rec.mail_code, gr_table_rec.description, USER, TODAY) WHERE CURRENT OF update_curs
#|___________________________________________________^
#| Error at line 280, character 53
#| parse error ()

    IF STATUS THEN
        display "cxcccx"
    end if

########################################## (1) /data2/maximise/max_4.01.12/dvfund/V22.err :
    DISPLAY by name comment, charvar
#|_____________^
#| Error at line 902, character 15
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/dvfund/VS3.err :

    DECLARE batch_ucurs CURSOR FOR
        SELECT dt.*
           INTO f2.*
           FROM deposit_trans dt
           WHERE dt.trans_code = charvar
             AND dt.gl_period  = charvar
             ###AND dt.posted_flag != "Y"
             AND (dt.posted_flag IS null
              OR dt.posted_flag = "N"
              OR dt.posted_flag != "Y")
        FOR UPDATE OF dt.posted_flag
#|_______________________^
#| Error at line 312, character 25
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/eo/ES2.err :

               update statistics
#|_____________________________^
#| Error at line 115, character 31
#| parse error ()

########################################## (1) /data2/maximise/max_4.01.12/gl/GCEb.err :
         select sum(tran_amt),sum(disc_amt)
            into charvar,intvar
            from t_bkdetl
            where ref_num = charvar
              and ref_code = intvar
              and (select entry_type_code
#|________________________^
#| Error at line 433, character 26
#| parse error ()
                      from t_bkstate
                      where seq_num = t_bkdetl.seq_num) = "RE"

########################################## (1) /data2/maximise/max_4.01.12/gl/GCEd.err :
   select sum(tran_amt + disc_amt)
      into charvar
      from t_bkdetl
     where ref_num = pr_inv_num
       and seq_num != pr_seq_num
       and ((select entry_type_code
#|__________________^
#| Error at line 825, character 20
#| parse error ()
               from t_bkstate
               where seq_num = t_bkdetl.seq_num) = "RE")

########################################## (1) /data2/maximise/max_4.01.12/jm/J33csi.err :

         declare c_jobledger cursor for                 #M J33csi
             select distinct JL.*, TH.person_code       #M J33csi
             from jobledger JL, OUTER (ts_detail TD, ts_head TH), resbill R #M J33csi
#|__________________________________________________^
#| Error at line 648, character 52
#| parse error ()
             where  R.cmpy_code = cmpy                  #M J33csi
               and R.job_code = pr_temp.job_code        #M J33csi
               and R.var_code = pr_temp.var_code        #m J33csi
               and R.activity_code = pr_temp.activity_code #M J33csi
               and R.inv_num = pr_temp.inv_num          #M J33csi
               and R.line_num = pr_temp.line_num        #M J33csi
               and R.seq_num = pr_temp.seq_num          #M J33csi
               and JL.cmpy_code = R.cmpy_code           #M J33csi
               and JL.job_code = R.job_code             #M J33csi
               and JL.var_code = R.var_code             #M J33csi



########################################## (1) /data2/maximise/max_4.01.12/jm/JRI.err :
   create temp table t_testdir(file char (10)) with no log
#|__________________________________^
#| Error at line 52, character 36
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/main/U19.err :
      unload to charvar
         select username,
                usertype
         from "informix".sysusers
#|_______________________^
#| Error at line 367, character 25
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/work/make_dwqry.err :
create table sales_transactions (
  sales_person_key     char(8),
  customer_key         char(8),
  location_key         char(2),
  division_key         char(2),
  day                  smallint,
  month                smallint,
  year                 smallint,
  calander_key         varchar(40,0),
#|____________________________^
#| Error at line 68, character 30
#| parse error ()
  job_key              char(8),
  company_key          char(2),
  resource_key         char(8),
  currency_code        char(3),
  line_number          integer
  )


########################################## (1) /data2/maximise/max_4.01.12/ap/P36_J.err :
   insert into t_cheque select v.vend_code,
                               c.cheq_code,
                               c.cheq_date,
                               v.com1_text
                          from cheque      c,
                               voucher     v,
                               voucherpays p
                         where c.cmpy_code     = cmpy
                           and c.cheq_date     = pr_cheque_date
                           and p.cmpy_code     = cmpy
                           and p.vend_code     = c.vend_code
                           and p.pay_type_code = 'CH'
                           and p.pay_num       = c.cheq_code
                           and p.pay_date      = pr_cheque_date
                           and v.cmpy_code     = cmpy
                           and v.vouch_code    = p.vouch_code
                           and v.vend_code     = p.vend_code
                           and v.com1_text[1,5]= 'WORK '
#|______________________________________________^
#| Error at line 165, character 48
#| 'com1_text' does not represent a defined variable (7) ()




end function

#######################
report beforegrouof(pr_vendor)
#######################
define
	l2_vend_bal_amt,
	l3_vend_bal_amt,
	tot_vend_local_bal_amt
		integer,
    where_text
        char (100),
#      pr_vendor record like vendor.*,
#      pr_voucher record like voucher.*,
#      pr_voucherpays record like voucherpays.*,
      pr_vendor record
		a integer,
		a1 integer,
		vend_code char (10)

		end record,

      pr_voucher record
		a integer,
		a1 integer
		end record,

      pr_voucherpays record
		a integer,
		a1 integer
		end record,


	x
        integer
define
    type char(1),                                                     #M 1507
#|___________^
#| Error at line 841, character 13
#| parse error ()

      file char(100),
#|_________^
#| Error at line 1006, character 11
#| parse error ()
#         date                   like tentpays.vouch_date,
        date char(16),

#|____________^
#| Error at line 171, character 14
#| parse error ()
         text                   char(15),
         delete char(1),
#|______________^
#| Error at line 127, character 16
#| parse error ()


    g_comment
#        record like comment.*,
    record
		a integer,
		a1 integer
		end record,




#|_________________________^
#| Error at line 39, character 27
#| parse error ()


        esc char(1)
#|__________^
#| Error at line 185, character 12
#| parse error ()


    DEFINE fr_services
#		RECORD LIKE services.*,
    record
		a integer,
		a1 integer
		end record,



           fv_today                           DATE,
           fv_ra_num                          INT
#|_______________________________________________^
#| Error at line 242, character 49
#| parse error ()


########################################## (1) /data2/maximise/max_4.01.12/ap/P96a.err :

   output
      top of page "^L"
#|________^
#| Error at line 41, character 10
#| parse error ()
      page length 60
      top margin 0
      bottom margin 0
      left margin 0

   format
   page header

########################################## (1) /data2/maximise/max_4.01.12/wo/WQB.err :
   let charvar = "   Order Customer",8 spaces,"Line",2 spaces,
                                 "Reference",23 spaces,"Ware",6 spaces,"Code",6 spaces,"Unit Amount    ",5 spaces,"Quantity",10 spaces,"Value"
#|____________________________________________________________________^
#| Error at line 417, character 70
#| '6spaces' does not represent a defined variable (1) ()


########################################## (1) /data2/maximise/max_4.01.12/ap/P6A.err :
         print column 10, charvar clipped,
               column 25,charvar clipped wordwrap right margin x
#|__________________________________________________________________^
#| Error at line 489, character 68
#| parse error ()


#######################

   before group of pr_vendor.vend_code
#4Js comment:
#| An ORDER BY or GROUP item specified within a report must be one of the report parameters.
#| See error number -4415.
        let l2_vend_bal_amt = 0
#|__________^
#| Error at line 321, character 12
#| pr_vendor.vend_code is not in the order by list ()
##########################################################

##################################
#NOTE: it look like there is problem with detection of ORDER BY
##################################


########################################## (1) /data2/maximise/max_4.01.12/main/U14.err :
	  on every row
         print file "../reports/maxlog"
#|__________________^
#| Error at line 270, character 20
#| parse error ()




end report

########################################## (2) /data2/maximise/max_4.01.12/winds/invdfunc.err :
function blah()

   return
end function
#|_________^
#| Error at line 323, character 11
#| FUNC was not last block command
# ()


########################################
function huuuuhhsaaaastilllfaillls()
#########################################

########################################## (1) /data2/maximise/max_4.01.12/ar/A41e.err :
   let intvar = + intvar
#|________________________________________^
#| Error at line 102, character 42
#| parse error ()
                           + idx



########################################## (1) /data2/maximise/max_4.01.12/gl/GP2.err :
   declare upd_gl_curs cursor for
     select * from glparms
       where key_code = "1"
         and cmpy_code = cmpy
     for update of post_total_amt,
#|______________________________^
#| Error at line 318, character 32
#| parse error ()
                   next_post_num,
                   last_post_date,
                   next_seq_num


########################################## (1) /data2/maximise/max_4.01.12/eo/E11f.err :
   declare c_orderpart cursor for
      select offer_code
        from t_orderpart
       where offer_code != "###"
         and offer_qty > 0
       order by offer_code
   foreach c_orderpart into charvar
      select desc_text into charvar
        from offersale
       where cmpy_code = charvar
         and offer_code = intvar
      update t_orderpart set desc_text = charvar
       where offer_code = intvar
      let intvar = 0
      let charvar = ""
      let idx = idx + 1
      let intvar = intvar + 1
      if intvar > 5 then
         scroll f2.* up by 1
#|______________^
#| Error at line 131, character 16
#| parse error ()
         let intvar = 5
      end if

########################################## (1) /data2/maximise/max_4.01.12/eo/E53a.err :

      flush c_orderpart #s1_t_invdetl ## insert rows so reoccurrence of order no
#|__________^
#| Error at line 406, character 12
#| parse error ()
                         ## can be identified in next iteration



	end foreach


########################################## (1) /data2/maximise/max_4.01.12/eo/E53b.err :

   let charvar = "update orderdetl ",
                         "set inv_qty = inv_qty + ?,",
                             "back_qty = back_qty + ?,",
                             "sched_qty = sched_qty - ?,",
                             "picked_qty = picked_qty - ?,",
                             "conf_qty = conf_qty - ? ",
                         "where cmpy_code= '",charvar,"' ",
                           "and order_num= ? ",
                           "and line_num = ? "
   prepare c_orderdetl from charvar


        execute c_orderdetl using charvar,
                                               "0", ## Back_qty
#|________________________________________________^
#| Error at line 676, character 50
#| parse error ()
                                               "0", ## Sched_qty
                                               "0", ## Picked_qty
                                               charvar,
                                               charvar ,
                                               charvar

end function


function header()
#    return 0
end function

function update()
#    return 0
end function

function warning()
#    return 0
end function

function xmenu(intvar, charvar, f2,f2,charvar)
define
	f2 record
		a integer,
		a1 integer
	end record


end function

report print_maxlog ()

   output
      left margin 0

   format
   page header

   print "blah"

end report

function unload(intvar)
define
    intvar
        integer


    return true
end function

function exists(intvar, charvar, intvar)
define
    intvar
        integer,
    charvar
        char(1)



	return true

end function


#------------------------------ EOF --------------------------------
