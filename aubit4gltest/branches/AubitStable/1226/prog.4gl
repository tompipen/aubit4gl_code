main
define w_inv_date date
define w_inv_day integer
define inv_month integer
define due_year integer


initialize w_inv_date  to null


       let w_inv_day = DAY(w_inv_date)
       let inv_month = MONTH(w_inv_date)
       let due_year = YEAR(w_inv_date)


if w_inv_day is null then
        display "w_inv_day is null"
else
        display w_inv_day
end if

if inv_month is null then
        display "inv_month is null"
else
        display inv_month
end if

if due_year is null then
        display "due_year is null"
else
        display due_year
end if


let w_inv_date=mdy(w_inv_day,inv_month,due_year)
if w_inv_date is null then
        display "w_inv_date is null"
else
        display w_inv_date
end if
end main

