DEFINE
 a, b, c1 INTEGER,
 c2 DOUBLE PRECISION,
 c3 FLOAT
MAIN

LET a = 5
LET b = 2

LET c1 = a / b
LET c2 = a / b
LET c3 = a / b

DISPLAY "a: '", a, "', b: '", b, "'"
DISPLAY  "c1(int): '", c1, "'"
DISPLAY  "c2(dbl): '", c2, "'"
DISPLAY  "c3(flt): '", c3, "'"

END MAIN
