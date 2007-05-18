main
define
   retire_yr    datetime year to year,
   retire_date  datetime year to month,
   retire_test  datetime year to month,
   rem_mo       interval month to month,
   depr_date    date

let retire_yr = "2007"

let depr_date = extend (retire_yr, year to month)

if depr_date = mdy(1,1,2007) then
   let depr_date = extend (retire_yr, year to day)
       + 6 units month - 1 units day

   if depr_date != mdy(6,30,2007) then
	display "Bad"
      exit program 1
   end if
end if

let retire_test = "2007-01"
let retire_date = extend (retire_yr, year to month)

if retire_date = retire_test then
	display "Good"
   exit program 0
end if

display "Bad"
exit program 1

end main
