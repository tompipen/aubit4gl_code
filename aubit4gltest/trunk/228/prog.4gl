define lv_rate ASSOCIATE CHAR(3) WITH ARRAY[2000] OF RECORD
		lv_name CHAR(20),
		lv_rates float
end record
define lv_name ASSOCIATE CHAR(3) WITH ARRAY[2000] OF CHAR(20)

#
# Data correct on 19/04/2002
#
main
DEFINE i FLOAT
define cur char(3)
# Use USD as base
	LET lv_rate<<"USD">>.lv_name="US Dollars"
	LET lv_rate<<"USD">>.lv_rates=1.0

	LET lv_rate<<"EUR">>.lv_name="Euro"
	LET lv_rate<<"EUR">>.lv_rates=0.888477

	LET lv_rate<<"GBP">>.lv_name="UK Pounds"
	LET lv_rate<<"GBP">>.lv_rates=1.44621

	LET lv_rate<<"JPY">>.lv_name="Japan Yen"
	LET lv_rate<<"JPY">>.lv_rates=0.00766891

	LET lv_rate<<"NZD">>.lv_name="New Zealand Dollars"
	LET lv_rate<<"NZD">>.lv_rates=0.447180

	LET lv_rate<<"PTE">>.lv_name="Portugal Escudos"
	LET lv_rate<<"PTE">>.lv_rates=0.00443157

let i=5
let cur="USD"
DISPLAY "if I have ",i using "#####&&.&&", " ",cur," (", lv_rate<<cur>>.lv_name clipped,") thats about ",lv_rate<<cur>>.lv_rates*i," US Dollars" 
let cur="EUR"
DISPLAY "if I have ",i using "#####&&.&&", " ",cur," (", lv_rate<<cur>>.lv_name clipped,") thats about ",lv_rate<<cur>>.lv_rates*i," US Dollars" 
let cur="JPY"
DISPLAY "if I have ",i using "#####&&.&&", " ",cur," (", lv_rate<<cur>>.lv_name clipped,") thats about ",lv_rate<<cur>>.lv_rates*i," US Dollars" 
let cur="NZD"
DISPLAY "if I have ",i using "#####&&.&&", " ",cur," (", lv_rate<<cur>>.lv_name clipped,") thats about ",lv_rate<<cur>>.lv_rates*i," US Dollars" 
let cur="PTE"
DISPLAY "if I have ",i using "#####&&.&&", " ",cur," (", lv_rate<<cur>>.lv_name clipped,") thats about ",lv_rate<<cur>>.lv_rates*i," US Dollars" 


end main

