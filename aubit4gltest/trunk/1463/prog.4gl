database test1

main
define
   latrad_p   decimal(13,10),
   lonrad_p   decimal(13,10),
   outline    char(30),
   toutline   char(30)

create temp table customer_t
(  mfg    char(02),
   cust   char(07),
   latdeg DECIMAL(13,10),
   londeg DECIMAL(13,10),
   latrad DECIMAL(13,10),
   lonrad DECIMAL(13,10)
) with no log

insert into customer_t (mfg,cust,latdeg,londeg)
values ('HY','  IL072',41.50632,-87.7446)


select nvl(latrad,nvl(latdeg,0)*0.0174532925199433),
       nvl(lonrad,nvl(londeg,0)*-0.0174532925199433)
  into latrad_p, lonrad_p
  from customer_t
 where mfg = 'HY'
   and cust  = '  IL072'

# from sqlcmd and asql_i know result sb
# 0.724421944386372991656 1.53143217084541688118
# so rounded to 10 decimal poistions sb
# 0.7244219444 and 1.5314321708 this is what c4gl shows also

if  latrad_p != 0.7244219444 or lonrad_p != 1.5314321708 then
   display "rounding error in prog variable"
   exit program 1
end if

let outline =  latrad_p using "----.----------", "|",
               lonrad_p using "----.----------", "|"

let toutline = "    .7244219444|   1.5314321708|"


if outline != toutline then
   display outline
   display "should be"
   display toutline
   exit program 1
end if
   
exit program 0

end main
