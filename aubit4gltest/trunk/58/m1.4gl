main 
define phone_num char(12) 
define f2 char(1) 

options input wrap, 
accept key f12 

open window genparmwin at 2, 2 with 16 rows, 46 columns 
attribute (green, border) 
open form gen_form from "pn" 
display form gen_form attribute (cyan) 

input by name phone_num,f2 without defaults 
on key(f1) 
exit input 
end input 
display "phone : ",phone_num 

end main 
