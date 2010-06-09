
define p_date          date,
       p_datetime      datetime year to year,
       year1             integer,
       year2             integer


main

  let p_date = today
  let p_datetime = current year to year
  let year1 = year(p_date)
  let year2 = year(p_datetime)

  display p_date
  display year1
  display p_datetime
  display year2

  if year(p_date) <> year(p_datetime) then
    display "doesnt match"
  else
    display "match"
  end if

end main
