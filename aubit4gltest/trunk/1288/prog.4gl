
  
 main 
  
 define P_REC record 
 REC_ID char(8), 
 REC_DESC char(30), 
 REC_STR char(80), 
 REC_FLAG char(1) 
 end record 
  
 open window W_REC at 1,1 with form "F_REC" 
  
 let P_REC.REC_ID = "SAMSUNG" 
 let P_REC.REC_DESC = "Samsung Landscape" 
 let P_REC.REC_STR = "a2ps --borders=no -B -r --columns=1 -L 66 -P samsung" 
 let P_REC.REC_FLAG = "N" 
  
 clear form 
  
 display by name P_REC.REC_DESC, P_REC.REC_STR 
  
 input by name P_REC.REC_ID, P_REC.REC_FLAG 
 without defaults 
 attribute(red, reverse) 
  
 after field REC_ID 
 display by name P_REC.REC_DESC, P_REC.REC_STR attribute(cyan) 
  
 end input 
  
 close window W_REC 
  
 display "REC_ID=", P_REC.REC_ID clipped, "= ", 
 "REC_DESC=", P_REC.REC_DESC clipped, "= ", 
 "REC_STR=", P_REC.REC_STR clipped, "= ", 
 "REC_FLAG=", P_REC.REC_FLAG, "= " 
 end main 
