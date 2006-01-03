main 
define f1 char(1) 
define f2 char(1) 
define f3 char(1) 

options input no wrap 

open window genparmwin at 2, 2 with 16 rows, 46 columns 
attribute (green, border) 
open form gen_form from "m" 
display form gen_form attribute (cyan) 

input by name f1,f2,f3 without defaults 
on key(f1) 
exit input 
end input 

end main 
