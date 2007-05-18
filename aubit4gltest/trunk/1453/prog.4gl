
main
define
   retire_yr    datetime year to year,
   depr_date    date

let retire_yr = "2007"

let depr_date = extend (retire_yr, year to day)

if depr_date = mdy(1,1,2007) then
	display "Dates ok1"
   let depr_date = extend (retire_yr, year to day) + 6 units month - 1 units day

   if depr_date = mdy(6,30,2007) then
	display "Good"
      exit program 0
   end if
end if
   
display "Bad:", depr_date
exit program 1

end main
