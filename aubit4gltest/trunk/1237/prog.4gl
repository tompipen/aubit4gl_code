main
 define
    stdstat_p char(01)
 
 let stdstat_p = "2"
 
 if stdstat_p not matches "[0123456789CDSTRP]" or
    stdstat_p is null or length(stdstat_p) = 0 then
    display "no match"
 end if
 
end main
