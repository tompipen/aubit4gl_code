database test1

main
define
   rec record
            inv_entry_no integer,
            ap_inv_no char(15),
            bank_id char(3),
            inv_date date,
            due_date date,
            disc_bal decimal(16,2),
            to_pay_amt decimal(16,2),
            aft_disc decimal(16,2)
   end record

create temp table testdata
(
            inv_entry_no integer,
            ap_inv_no char(15),
            bank_id char(3),
            inv_date date,
            due_date date,
            disc_bal decimal(16,2),
            to_pay_amt decimal(16,2),
            aft_disc decimal(16,2)
) with no log

load from "data.unl"
insert into testdata

declare curs cursor for
 select * from testdata order by inv_entry_no

start report report2 to "out"

foreach curs into rec.*
   output to report report2 (rec.*)
end foreach

finish report report2

end main

#######################################################################
report report2(rpt)
#######################################################################
#
    define
        rpt record                  # record for the report
            inv_entry_no integer,
            ap_inv_no char(15),
            bank_id char(3),
            inv_date date,
            due_date date,
            disc_bal decimal(16,2),
            to_pay_amt decimal(16,2),
            aft_disc decimal(16,2)
        end record,
                inv_count       smallint

    output
        top margin     3
        bottom margin  3
        left margin    0
        right margin   132
        page length    66

    order external by rpt.inv_entry_no

    format
        page header
            print column 40, "test report"
            print
                column   1, "========================================",
                column  41, "========================================",
                column  81, "========================================",
                column 121, "============"

	{on every row
		print "ENTRY : ",rpt.inv_entry_no," ",rpt.to_pay_amt}


        after group of rpt.inv_entry_no
            print
                column  37, rpt.ap_inv_no,
                column  53, rpt.bank_id,
                column  58, rpt.inv_date,
                column  67, rpt.due_date,
                column  76, group sum(rpt.to_pay_amt) using "((((,(((,(((.&&)",
                column  95, group sum(rpt.disc_bal) using "((((,(((,(((.&&)",
                column 117, group sum(rpt.to_pay_amt - rpt.disc_bal)
                                                        using "((((,(((,(((.&&)"
                        let inv_count = inv_count + 1


                on last row
            print
            print
            print
                column   1, "Grand Total",
                column  76, sum(rpt.to_pay_amt) using "((((,(((,(((.&&)",
                column  95, sum(rpt.disc_bal) using "((((,(((,(((.&&)",
                column 117, sum(rpt.to_pay_amt - rpt.disc_bal)
                                                        using "((((,(((,(((.&&)"

end report

