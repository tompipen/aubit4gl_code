main
define 
	p_integer integer,
	p_smallint smallint ,
	p_decimal decimal ,
	p_money money ,
	p_char20 char(20),
	p_float float ,
	p_smallfloat smallfloat ,
	p_serial serial ,
	p_date date,
	q_integer integer,
	q_smallint smallint ,
	q_decimal decimal ,
	q_money money ,
	q_char20 char(20),
	q_float float ,
	q_smallfloat smallfloat ,
	q_serial serial ,
	q_date date


let         q_integer=1
let q_smallint =1
let q_decimal =1
let q_money =1
let q_char20="1"
let q_float =1
let q_smallfloat=1
let q_serial=1
let q_date=1

	initialize p_integer ,
	p_smallint ,
	p_decimal ,
	p_money ,
	p_char20 ,
	p_float ,
	p_smallfloat ,
	p_serial ,
	p_date  TO NULL


if NOT (p_integer=q_integer) then
   display "Blah integer integer"
else
   display "Fail integer integer"
   exit program 1
end if
if NOT (p_integer=q_smallint) then
   display "Blah integer smallint"
else
   display "Fail integer smallint"
   exit program 1
end if
if NOT (p_integer=q_decimal) then
   display "Blah integer decimal"
else
   display "Fail integer decimal"
   exit program 1
end if
if NOT (p_integer=q_money) then
   display "Blah integer money"
else
   display "Fail integer money"
   exit program 1
end if
if NOT (p_integer=q_char20) then
   display "Blah integer char20"
else
   display "Fail integer char20"
   exit program 1
end if
if NOT (p_integer=q_float) then
   display "Blah integer float"
else
   display "Fail integer float"
   exit program 1
end if
if NOT (p_integer=q_smallfloat) then
   display "Blah integer smallfloat"
else
   display "Fail integer smallfloat"
   exit program 1
end if
if NOT (p_integer=q_serial) then
   display "Blah integer serial"
else
   display "Fail integer serial"
   exit program 1
end if
if NOT (p_integer=q_date) then
   display "Blah integer date"
else
   display "Fail integer date"
   exit program 1
end if
if NOT (p_smallint=q_integer) then
   display "Blah smallint integer"
else
   display "Fail smallint integer"
   exit program 1
end if
if NOT (p_smallint=q_smallint) then
   display "Blah smallint smallint"
else
   display "Fail smallint smallint"
   exit program 1
end if
if NOT (p_smallint=q_decimal) then
   display "Blah smallint decimal"
else
   display "Fail smallint decimal"
   exit program 1
end if
if NOT (p_smallint=q_money) then
   display "Blah smallint money"
else
   display "Fail smallint money"
   exit program 1
end if
if NOT (p_smallint=q_char20) then
   display "Blah smallint char20"
else
   display "Fail smallint char20"
   exit program 1
end if
if NOT (p_smallint=q_float) then
   display "Blah smallint float"
else
   display "Fail smallint float"
   exit program 1
end if
if NOT (p_smallint=q_smallfloat) then
   display "Blah smallint smallfloat"
else
   display "Fail smallint smallfloat"
   exit program 1
end if
if NOT (p_smallint=q_serial) then
   display "Blah smallint serial"
else
   display "Fail smallint serial"
   exit program 1
end if
if NOT (p_smallint=q_date) then
   display "Blah smallint date"
else
   display "Fail smallint date"
   exit program 1
end if
if NOT (p_decimal=q_integer) then
   display "Blah decimal integer"
else
   display "Fail decimal integer"
   exit program 1
end if
if NOT (p_decimal=q_smallint) then
   display "Blah decimal smallint"
else
   display "Fail decimal smallint"
   exit program 1
end if
if NOT (p_decimal=q_decimal) then
   display "Blah decimal decimal"
else
   display "Fail decimal decimal"
   exit program 1
end if
if NOT (p_decimal=q_money) then
   display "Blah decimal money"
else
   display "Fail decimal money"
   exit program 1
end if
if NOT (p_decimal=q_char20) then
   display "Blah decimal char20"
else
   display "Fail decimal char20"
   exit program 1
end if
if NOT (p_decimal=q_float) then
   display "Blah decimal float"
else
   display "Fail decimal float"
   exit program 1
end if
if NOT (p_decimal=q_smallfloat) then
   display "Blah decimal smallfloat"
else
   display "Fail decimal smallfloat"
   exit program 1
end if
if NOT (p_decimal=q_serial) then
   display "Blah decimal serial"
else
   display "Fail decimal serial"
   exit program 1
end if
if NOT (p_decimal=q_date) then
   display "Blah decimal date"
else
   display "Fail decimal date"
   exit program 1
end if
if NOT (p_money=q_integer) then
   display "Blah money integer"
else
   display "Fail money integer"
   exit program 1
end if
if NOT (p_money=q_smallint) then
   display "Blah money smallint"
else
   display "Fail money smallint"
   exit program 1
end if
if NOT (p_money=q_decimal) then
   display "Blah money decimal"
else
   display "Fail money decimal"
   exit program 1
end if
if NOT (p_money=q_money) then
   display "Blah money money"
else
   display "Fail money money"
   exit program 1
end if
if NOT (p_money=q_char20) then
   display "Blah money char20"
else
   display "Fail money char20"
   exit program 1
end if
if NOT (p_money=q_float) then
   display "Blah money float"
else
   display "Fail money float"
   exit program 1
end if
if NOT (p_money=q_smallfloat) then
   display "Blah money smallfloat"
else
   display "Fail money smallfloat"
   exit program 1
end if
if NOT (p_money=q_serial) then
   display "Blah money serial"
else
   display "Fail money serial"
   exit program 1
end if
if NOT (p_money=q_date) then
   display "Blah money date"
else
   display "Fail money date"
   exit program 1
end if
if NOT (p_char20=q_integer) then
   display "Blah char20 integer"
else
   display "Fail char20 integer"
   exit program 1
end if
if NOT (p_char20=q_smallint) then
   display "Blah char20 smallint"
else
   display "Fail char20 smallint"
   exit program 1
end if
if NOT (p_char20=q_decimal) then
   display "Blah char20 decimal"
else
   display "Fail char20 decimal"
   exit program 1
end if
if NOT (p_char20=q_money) then
   display "Blah char20 money"
else
   display "Fail char20 money"
   exit program 1
end if
if NOT (p_char20=q_char20) then
   display "Blah char20 char20"
else
   display "Fail char20 char20"
   exit program 1
end if
if NOT (p_char20=q_float) then
   display "Blah char20 float"
else
   display "Fail char20 float"
   exit program 1
end if
if NOT (p_char20=q_smallfloat) then
   display "Blah char20 smallfloat"
else
   display "Fail char20 smallfloat"
   exit program 1
end if
if NOT (p_char20=q_serial) then
   display "Blah char20 serial"
else
   display "Fail char20 serial"
   exit program 1
end if
if NOT (p_char20=q_date) then
   display "Blah char20 date"
else
   display "Fail char20 date"
   exit program 1
end if
if NOT (p_float=q_integer) then
   display "Blah float integer"
else
   display "Fail float integer"
   exit program 1
end if
if NOT (p_float=q_smallint) then
   display "Blah float smallint"
else
   display "Fail float smallint"
   exit program 1
end if
if NOT (p_float=q_decimal) then
   display "Blah float decimal"
else
   display "Fail float decimal"
   exit program 1
end if
if NOT (p_float=q_money) then
   display "Blah float money"
else
   display "Fail float money"
   exit program 1
end if
if NOT (p_float=q_char20) then
   display "Blah float char20"
else
   display "Fail float char20"
   exit program 1
end if
if NOT (p_float=q_float) then
   display "Blah float float"
else
   display "Fail float float"
   exit program 1
end if
if NOT (p_float=q_smallfloat) then
   display "Blah float smallfloat"
else
   display "Fail float smallfloat"
   exit program 1
end if
if NOT (p_float=q_serial) then
   display "Blah float serial"
else
   display "Fail float serial"
   exit program 1
end if
if NOT (p_float=q_date) then
   display "Blah float date"
else
   display "Fail float date"
   exit program 1
end if
if NOT (p_smallfloat=q_integer) then
   display "Blah smallfloat integer"
else
   display "Fail smallfloat integer"
   exit program 1
end if
if NOT (p_smallfloat=q_smallint) then
   display "Blah smallfloat smallint"
else
   display "Fail smallfloat smallint"
   exit program 1
end if
if NOT (p_smallfloat=q_decimal) then
   display "Blah smallfloat decimal"
else
   display "Fail smallfloat decimal"
   exit program 1
end if
if NOT (p_smallfloat=q_money) then
   display "Blah smallfloat money"
else
   display "Fail smallfloat money"
   exit program 1
end if
if NOT (p_smallfloat=q_char20) then
   display "Blah smallfloat char20"
else
   display "Fail smallfloat char20"
   exit program 1
end if
if NOT (p_smallfloat=q_float) then
   display "Blah smallfloat float"
else
   display "Fail smallfloat float"
   exit program 1
end if
if NOT (p_smallfloat=q_smallfloat) then
   display "Blah smallfloat smallfloat"
else
   display "Fail smallfloat smallfloat"
   exit program 1
end if
if NOT (p_smallfloat=q_serial) then
   display "Blah smallfloat serial"
else
   display "Fail smallfloat serial"
   exit program 1
end if
if NOT (p_smallfloat=q_date) then
   display "Blah smallfloat date"
else
   display "Fail smallfloat date"
   exit program 1
end if
if NOT (p_serial=q_integer) then
   display "Blah serial integer"
else
   display "Fail serial integer"
   exit program 1
end if
if NOT (p_serial=q_smallint) then
   display "Blah serial smallint"
else
   display "Fail serial smallint"
   exit program 1
end if
if NOT (p_serial=q_decimal) then
   display "Blah serial decimal"
else
   display "Fail serial decimal"
   exit program 1
end if
if NOT (p_serial=q_money) then
   display "Blah serial money"
else
   display "Fail serial money"
   exit program 1
end if
if NOT (p_serial=q_char20) then
   display "Blah serial char20"
else
   display "Fail serial char20"
   exit program 1
end if
if NOT (p_serial=q_float) then
   display "Blah serial float"
else
   display "Fail serial float"
   exit program 1
end if
if NOT (p_serial=q_smallfloat) then
   display "Blah serial smallfloat"
else
   display "Fail serial smallfloat"
   exit program 1
end if
if NOT (p_serial=q_serial) then
   display "Blah serial serial"
else
   display "Fail serial serial"
   exit program 1
end if
if NOT (p_serial=q_date) then
   display "Blah serial date"
else
   display "Fail serial date"
   exit program 1
end if
if NOT (p_date=q_integer) then
   display "Blah date integer"
else
   display "Fail date integer"
   exit program 1
end if
if NOT (p_date=q_smallint) then
   display "Blah date smallint"
else
   display "Fail date smallint"
   exit program 1
end if
if NOT (p_date=q_decimal) then
   display "Blah date decimal"
else
   display "Fail date decimal"
   exit program 1
end if
if NOT (p_date=q_money) then
   display "Blah date money"
else
   display "Fail date money"
   exit program 1
end if
if NOT (p_date=q_char20) then
   display "Blah date char20"
else
   display "Fail date char20"
   exit program 1
end if
if NOT (p_date=q_float) then
   display "Blah date float"
else
   display "Fail date float"
   exit program 1
end if
if NOT (p_date=q_smallfloat) then
   display "Blah date smallfloat"
else
   display "Fail date smallfloat"
   exit program 1
end if
if NOT (p_date=q_serial) then
   display "Blah date serial"
else
   display "Fail date serial"
   exit program 1
end if
if NOT (p_date=q_date) then
   display "Blah date date"
else
   display "Fail date date"
   exit program 1
end if

end main
