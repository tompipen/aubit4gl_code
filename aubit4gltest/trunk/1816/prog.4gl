
define p_date          date,
       p_datetime      datetime year to year,
       year1             integer,
       year2             integer


main

  let p_date = mdy(10,14,2000)
  let p_datetime = "2000-10-14 12:13:14"
  let year1 = year(p_date)
  let year2 = year(p_datetime)

  display p_date using "dd/mm/yyyy"
  display year1
  display p_datetime
  display year2

  if year(p_date) <> year(p_datetime) then
    display "doesnt match"
  else
    display "match"
  end if

end main
