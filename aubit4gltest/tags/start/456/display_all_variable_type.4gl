
MAIN 
  DEFINE intVar INTEGER
  DEFINE smallintVar INTEGER
  DEFINE decimalVar DECIMAL(14,2)
	DEFINE moneyVar MONEY(16,2)
	DEFINE floatVar FLOAT
	DEFINE smallFloatVar SMALLFLOAT
	DEFINE dateVar DATE
	DEFINE datetimeVar DATETIME YEAR TO FRACTION(3)
	DEFINE intervalVar INTERVAL DAY TO FRACTION(3)
	DEFINE charVar CHAR(20)
	DEFINE varcharVar VARCHAR(255,50)

  LET intVar = 30000
  LET smallintVar = 23000
  LET decimalVar = 55.45
	LET moneyVar = 20.33
	LET floatVar = 10.54
	LET smallFloatVar = 100.87
	LET dateVar = mdy(12,31,1999)
	LET datetimeVar = CURRENT
	LET intervalVar = 1 UNITS DAY
	LET charVar = "Hello world"
	LET varcharVar = "Hello varchar world"

	DISPLAY "VARS: ",
    " : INT - ", intVar,
    " : SMALLINT - ", smallintVar,
    " : DECIMAL - ", decimalVar,
	  " : MONEY - ", moneyVar,
	  " : FLOAT - ", floatVar,
	  " : SMALLFLOAT - ", smallFloatVar,
	  " : DATE - ", dateVar,
	  " : DATETIME - ", datetimeVar,
	  " : INTERVAL - ", intervalVar,
	  " : CHAR - ", charVar,
	  " : VARCHAR - ", varcharVar
END MAIN
