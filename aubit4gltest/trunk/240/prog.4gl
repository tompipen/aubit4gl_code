Define lv_date date
define lv_num float
main
let lv_date=mdy(2,13,1970)



LET lv_num= 0 
DISPLAY lv_num USING "#####"," ","#####"
LET lv_num= -1 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= 0 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= 1 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= 12 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= 123 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= 1234 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= 12345 
DISPLAY lv_num USING "##,###"," ","##,###"
LET lv_num= -0.01 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 0.01 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 0.12 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 1.23 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 12.34 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 123.45 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 1234.56 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 12345.67 
DISPLAY lv_num USING "##,###.##"," ","##,###.##"
LET lv_num= 0 
DISPLAY lv_num USING "$$$$$"," ","$$$$$"
LET lv_num= 0 
DISPLAY lv_num USING "$$,$$$"," ","$$,$$$"
LET lv_num= 1 
DISPLAY lv_num USING "$$,$$$"," ","$$,$$$"
LET lv_num= 12 
DISPLAY lv_num USING "$$,$$$"," ","$$,$$$"
LET lv_num= 123 
DISPLAY lv_num USING "$$,$$$"," ","$$,$$$"
LET lv_num= 1234 
DISPLAY lv_num USING "$$,$$$"," ","$$,$$$"
LET lv_num= 12345 
DISPLAY lv_num USING "$$,$$$"," ","$$,$$$"
LET lv_num= 0.00 
DISPLAY lv_num USING "$$,$$$.##"," ","$$,$$$.##"
LET lv_num= 1234.00 
DISPLAY lv_num USING "$$,$$$.##"," ","$$,$$$.##"
LET lv_num= 1234.56 
DISPLAY lv_num USING "$$,$$$.$$"," ","$$,$$$.$$"
LET lv_num= 12345.67 
DISPLAY lv_num USING "$$,$$$.$$"," ","$$,$$$.$$"
LET lv_num= 0.00 
DISPLAY lv_num USING "$$,$$$.&&"," ","$$,$$$.&&"
LET lv_num= 1234.00 
DISPLAY lv_num USING "$$,$$$.&&"," ","$$,$$$.&&"
LET lv_num= .12 
DISPLAY lv_num USING "$***,***.&&"," ","$***,***.&&"
LET lv_num= 1.23 
DISPLAY lv_num USING "$***,***.&&"," ","$***,***.&&"
LET lv_num= 12.34 
DISPLAY lv_num USING "$***,***.&&"," ","$***,***.&&"
LET lv_num= 123.45 
DISPLAY lv_num USING "$***,***.&&"," ","$***,***.&&"
LET lv_num= 1234.56 
DISPLAY lv_num USING "$***,***.&&"," ","$***,***.&&"
LET lv_num= 12345.67 
DISPLAY lv_num USING "$***,***.&&"," ","$***,***.&&"
LET lv_num= 0 
DISPLAY lv_num USING "&&&&&"," ","&&&&&"
LET lv_num= 0 
DISPLAY lv_num USING "&&,&&&"," ","&&,&&&"
LET lv_num= 1 
DISPLAY lv_num USING "&&,&&&"," ","&&,&&&"
LET lv_num= 12 
DISPLAY lv_num USING "&&,&&&"," ","&&,&&&"
LET lv_num= 123 
DISPLAY lv_num USING "&&,&&&"," ","&&,&&&"
LET lv_num= 1234 
DISPLAY lv_num USING "&&,&&&"," ","&&,&&&"
LET lv_num= 12345 
DISPLAY lv_num USING "&&,&&&"," ","&&,&&&"
LET lv_num= 0.01 
DISPLAY lv_num USING "&&,&&&.&&"," ","&&,&&&.&&"
LET lv_num= 123.45 
DISPLAY lv_num USING "&&,&&&.&&"," ","&&,&&&.&&"
LET lv_num= 1234.56 
DISPLAY lv_num USING "&&,&&&.&&"," ","&&,&&&.&&"
LET lv_num= 12345.67 
DISPLAY lv_num USING "&&,&&&.&&"," ","&&,&&&.&&"
LET lv_num= -123.45 
DISPLAY lv_num USING "($$$,$$$.&&)"," ","($$$,$$$.&&)"
LET lv_num= -1234.56 
DISPLAY lv_num USING "($$$,$$$.&&)"," ","($$$,$$$.&&)"
LET lv_num= -12345.67 
DISPLAY lv_num USING "($$$,$$$.&&)"," ","($$$,$$$.&&)"
LET lv_num= 123.45 
DISPLAY lv_num USING "($$$,$$$.&&)"," ","($$$,$$$.&&)"
LET lv_num= 1234.56 
DISPLAY lv_num USING "($$$,$$$.&&)"," ","($$$,$$$.&&)"
LET lv_num= 12345.67 
DISPLAY lv_num USING "($$$,$$$.&&)"," ","($$$,$$$.&&)"
LET lv_num= -1.23 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= -12.34 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= -123.45 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= -1234.56 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= -12345.67 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= 1.23 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= 12.34 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= 123.45 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= 1234.56 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= 12345.67 
DISPLAY lv_num USING "(($$,$$$.&&)"," ","(($$,$$$.&&)"
LET lv_num= -.12 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= -1.23 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= -12.34 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= -123.45 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= -1234.56 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= -12345.67 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= .12 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= 1.23 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= 12.34 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= 123.45 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= 1234.56 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= 12345.67 
DISPLAY lv_num USING "((((,(($.&&)"," ","((((,(($.&&)"
LET lv_num= 0 
DISPLAY lv_num USING "*****"," ","*****"
LET lv_num= 0 
DISPLAY lv_num USING "**,***"," ","**,***"
LET lv_num= 1 
DISPLAY lv_num USING "**,***"," ","**,***"
LET lv_num= 12 
DISPLAY lv_num USING "**,***"," ","**,***"
LET lv_num= 123 
DISPLAY lv_num USING "**,***"," ","**,***"
LET lv_num= 1234 
DISPLAY lv_num USING "**,***"," ","**,***"
LET lv_num= 12345 
DISPLAY lv_num USING "**,***"," ","**,***"
LET lv_num= -12.34 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= -123.45 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= -12345.67 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= 12.34 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= 123.45 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= 1234.56 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= 12345.67 
DISPLAY lv_num USING "-##,###.##"," ","-##,###.##"
LET lv_num= -123.45 
DISPLAY lv_num USING "-$$$,$$$.&&"," ","-$$$,$$$.&&"
LET lv_num= -1234.56 
DISPLAY lv_num USING "-$$$,$$$.&&"," ","-$$$,$$$.&&"
LET lv_num= -12345.67 
DISPLAY lv_num USING "-$$$,$$$.&&"," ","-$$$,$$$.&&"
LET lv_num= -12.34 
DISPLAY lv_num USING "--#,###.##"," ","--#,###.##"
LET lv_num= 12.34 
DISPLAY lv_num USING "--#,###.##"," ","--#,###.##"
LET lv_num= -1.23 
DISPLAY lv_num USING "--$$,$$$.&&"," ","--$$,$$$.&&"
LET lv_num= -12.34 
DISPLAY lv_num USING "--$$,$$$.&&"," ","--$$,$$$.&&"
LET lv_num= -123.45 
DISPLAY lv_num USING "--$$,$$$.&&"," ","--$$,$$$.&&"
LET lv_num= -1234.56 
DISPLAY lv_num USING "--$$,$$$.&&"," ","--$$,$$$.&&"
LET lv_num= -12345.67 
DISPLAY lv_num USING "--$$,$$$.&&"," ","--$$,$$$.&&"
LET lv_num= -12.34 
DISPLAY lv_num USING "---,###.##"," ","---,###.##"
LET lv_num= 12.34 
DISPLAY lv_num USING "---,###.##"," ","---,###.##"
LET lv_num= -12.34 
DISPLAY lv_num USING "---,-##.##"," ","---,-##.##"
LET lv_num= 12.34 
DISPLAY lv_num USING "---,-##.##"," ","---,-##.##"
LET lv_num= -1.00 
DISPLAY lv_num USING "---,--#.##"," ","---,--#.##"
LET lv_num= 1.00 
DISPLAY lv_num USING "---,---.##"," ","---,---.##"
LET lv_num= -.01 
DISPLAY lv_num USING "---,---.--"," ","---,---.--"
LET lv_num= -.12 
DISPLAY lv_num USING "----,--$.&&"," ","----,--$.&&"
LET lv_num= -1.23 
DISPLAY lv_num USING "----,--$.&&"," ","----,--$.&&"
LET lv_num= -12.34 
DISPLAY lv_num USING "----,--$.&&"," ","----,--$.&&"
LET lv_num= -123.45 
DISPLAY lv_num USING "----,--$.&&"," ","----,--$.&&"
LET lv_num= -1234.56 
DISPLAY lv_num USING "----,--$.&&"," ","----,--$.&&"
LET lv_num= -12345.67 
DISPLAY lv_num USING "----,--$.&&"," ","----,--$.&&"
LET lv_num= -.01 
DISPLAY lv_num USING "----,---.&&"," ","----,---.&&"
LET lv_num= 12 
DISPLAY lv_num USING "<<<,<<<"," ","<<<,<<<"
LET lv_num= 123 
DISPLAY lv_num USING "<<<,<<<"," ","<<<,<<<"
LET lv_num= 1234 
DISPLAY lv_num USING "<<<,<<<"," ","<<<,<<<"
LET lv_num= 12345 
DISPLAY lv_num USING "<<<,<<<"," ","<<<,<<<"
LET lv_num= 0 
DISPLAY lv_num USING "<<<<<"," ","<<<<<"


DISPLAY lv_date USING "(ddd) mmm. dd, yyyy" ," ","(ddd) mmm. dd,yyyy"
DISPLAY lv_date USING "ddd, mmm. dd, yyyy" ," ","ddd, mmm. dd, yyyy"
DISPLAY lv_date USING "ddmmyy" ," ","ddmmyy"
DISPLAY lv_date USING "mmddyy" ," ","mmddyy"
DISPLAY lv_date USING "mmm dd yyyy" ," ","mmm dd yyyy"
DISPLAY lv_date USING "mmm. dd, yyyy" ," ","mmm. dd, yyyy"
DISPLAY lv_date USING "yy mm dd" ," ","yy mm dd"
DISPLAY lv_date USING "yy-mm-dd" ," ","yy-mm-dd"
DISPLAY lv_date USING "yy/mm/dd" ," ","yy/mm/dd"
DISPLAY lv_date USING "yymmdd" ," ","yymmdd"
DISPLAY lv_date USING "yyyy dd mm" ," ","yyy dd mm"



end main
