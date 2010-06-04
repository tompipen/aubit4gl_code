define rec record
  account char(15),
  date date,
  cod integer,
  value integer,
  desc char(5)
end record
  
main
define i smallint

  initialize rec to null

  start report rlis_extconta to "out"

  for i = 1 to 20
    let rec.account = "21111021"
    let rec.date = "2010/06/01"
    let rec.cod = i
    let rec.value = 10+i
    let rec.desc = "desc"
    output to report rlis_extconta(rec.*)
  end for

  finish report rlis_extconta
end main

report rlis_extconta(rec)
define rec record
  account char(15),
  date date,
  cod integer,
  value integer,
  desc char(50)
end record
define flag smallint

output
      left margin    20
      right margin   132
      top margin     0
      bottom margin  0
      page length    72 
        order external by rec.account

format
   first page header
     let flag = 1

   page header
     let flag = 1

   before group of rec.account
      skip to top of page
      print column  1,"Date: ",
            column 70,"Pag.: ",pageno using "###"
      print column  1,"----",
            column 70,"----"
      skip 2 lines
      print column  1, "Account: ", rec.account clipped,
            column 68,"BETWEEN:"
      print column 68,"2000/01/01 e 2010/05/31"
      print column  1, "------------------------------------------------------",
                       "-----------------------------------------------------"
      print column  1, " Date",
            column  7, "Cod",
            column 11, "  Val.",
            column 18, "   Description"
      print column  1, "-----",
            column  7, "---",
            column 11, "------",
            column 18, "--------------"
      let flag = 0

   on every row
      if flag = 1 then
         skip to top of page
         print column  1,"Date: 01/06/2010",
               column 70,"Pag.: ",pageno using "###"
         print column  1,"----",
               column 70,"----"
         skip 2 lines
         print column  1, "Account: ", rec.account clipped,
               column 68,"BETWEEN"
         print column 68,"2000/01/01 e 2010/05/31"
        print column  1, "-------------------------------------------------",
                          "------------------------------------------------"
         print column  1, "Date",
               column  7, "Cod.",
               column 11, "Val.",
               column 18, "Description"
         print column  1, "-----",
               column  7, "---",
               column 11, "------",
               column 18, "---------------"
         let flag = 0
      end if

      print column  1, rec.date using "mm/dd",
            column  7, rec.cod using "##",
            column 11, rec.value using "###",
            column 18, rec.desc

   page trailer
      print column 1, "------------------------------------------------------",
                       "-----------------------------------------------------"
      print column 7, "Totals: ",
            column 56, "0",
            column 73, "0",
            column 90, "0"
      print column 1, "------------------------------------------------------",
                       "-----------------------------------------------------"
      print column 1,"Name",
            column 40,"Document processed by computer"

      skip 11 lines  
end report
