FUNCTION menuVert(lin,col,opc,str0,str1,str2,str3,str4,str5,str6,str7,str8)

DEFINE
	lin,col,opc SMALLINT,
   str0,str1,str2,str3,str4,str5,str6,str7,str8 CHAR(40),
	ans         smallint,
	nullstr     char(2)


	let nullstr = null
   let ans = menuVertCasc(lin,col,opc,nullstr,nullstr,nullstr,
							  str0,str1,str2,str3,str4,str5,str6,
	                    str7,str8,nullstr,nullstr,nullstr,nullstr,nullstr,
							  nullstr,nullstr,nullstr,nullstr,nullstr)

   return ans
END FUNCTION
