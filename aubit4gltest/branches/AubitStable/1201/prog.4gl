database  test1
 main 
 define xuc char(13) 
	 create temp table abc(uc char(13)) 
	 select uc 
	 into xuc 
	 from abc 
	 where uc = 'x' 
	 display "Status=",status 
	 
	 let xuc = "a 4gl statement" 
	 display "Status again=", status 
end main 


	

