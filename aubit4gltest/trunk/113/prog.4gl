{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
#Not needed:
####--! PRAGMA EMULATE INSERT CURSOR FOR c1_invoicedetl
 
database test1
main
define pr_invoicedetl record
		x char (10),
		y char (10)
	end record,
	pr_temp_text char (100)

	create temp table invoicedetl(x char(10), y char(10))

   let pr_temp_text = "select * from subcustomer ",
                       "where cmpy_code='1' ",
                         "and cust_code= ? ",
                         "and ship_code= ? ",
                         "and sub_type_code = ? ",
                         "and part_code= ? ",
                         "and comm_date= ? ",
                         "and end_date= ? "
   prepare s2_subcustomer from pr_temp_text
   declare c2_subcustomer cursor for s2_subcustomer
	
	
	
   declare c1_invoicedetl cursor for
   		insert into invoicedetl values(pr_invoicedetl.*)
		
		BEGIN WORK
   open c1_invoicedetl

   declare c_prodledg cursor for
    insert into prodledg values(pr_prodledg.*)
   
   open c_prodledg
   declare c_subaudit cursor for
    insert into subaudit values(pr_subaudit.*)
   open c_subaudit
   
   
   
   put c1_invoicedetl
   flush c1_invoicedetl

   		ROLLBACK WORK
		
	#exit program (99)	
	
end main

function update_issue()
define pr_temp_text char (200)
define cmpy char (3)
define pr_label, pr_subhead, pr_customer, pr_prodstatus, pr_subcustomer, 
	pr_subdetl, pr_subschedule record
		x char (10),
		y char (10)
	end record
	
	

	
	
define a, b, c, d, e, f char(20)

   begin work
   declare c_label cursor for
    select * from t_label
     where sub_num = pr_subhead.sub_num

  declare c2_subhead cursor for
    select * from subhead
     where sub_num = pr_subhead.sub_num
       and cmpy_code = cmpy
       for update
	   
   declare c2_subdetl cursor for
    select * from subdetl
     where sub_num = pr_label.sub_num
       and sub_line_num = pr_label.sub_line_num
       and cmpy_code = cmpy
       for update
	   
   declare c2_subschedule cursor for
    select * from subschedule
     where sub_num = pr_label.sub_num
       and sub_line_num = pr_label.sub_line_num
       and issue_num = pr_label.issue_num
       and cmpy_code = cmpy
       for update

   declare c_customer cursor for
    select * from customer
     where cmpy_code = cmpy
       and cust_code = pr_invoicehead.cust_code
       for update
   open c_customer
   fetch c_customer into pr_customer.*
   let pr_temp_text = "select * from prodstatus ",
                      " where cmpy_code ='",cmpy,"' ",
                      "   and part_code = ? and ware_code = ? "
   prepare s_prodstatus from pr_temp_text
   declare c_prodstatus cursor for s_prodstatus
   let pr_temp_text = "select * from subcustomer ",
                       "where cmpy_code='",cmpy,"' ",
                         "and cust_code= ? ",
                         "and ship_code= ? ",
                         "and sub_type_code = ? ",
                         "and part_code= ? ",
                         "and comm_date= ? ",
                         "and end_date= ? "
   prepare s2_subcustomer from pr_temp_text
   declare c2_subcustomer cursor for s2_subcustomer
   declare c1_invoicedetl cursor for
    insert into invoicedetl values(pr_invoicedetl.*)
   open c1_invoicedetl
   declare c_prodledg cursor for
    insert into prodledg values(pr_prodledg.*)
   open c_prodledg
   declare c_subaudit cursor for
    insert into subaudit values(pr_subaudit.*)
   open c_subaudit
   open c2_subhead
   fetch c2_subhead into pr_subhead.*
   foreach c_label into pr_label.*
         open c_prodstatus using a,
                                 b
         fetch c_prodstatus into pr_prodstatus.*
      put c1_invoicedetl
      open c2_subcustomer using a,
                                b,
                                c,
                                d,
                                e,
                                f
      fetch c2_subcustomer into pr_subcustomer.*
      open c2_subdetl
      fetch c2_subdetl into pr_subdetl.*
      open c2_subschedule
      fetch c2_subschedule into pr_subschedule.*
   end foreach
   
   flush c1_invoicedetl
         put c1_invoicedetl
         flush c1_invoicedetl
   commit work

end function



