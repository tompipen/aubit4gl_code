FUNCTION menuVertMarc(lin,col,opc,str0,str1,str2,str3,str4,str5,str6,str7,str8)

DEFINE
	lin,col,opc SMALLINT,
   str0,str1,str2,str3,str4,str5,str6,str7,str8 CHAR(40)

DEFINE
	str9 CHAR(9),
	pos INTEGER

   CALL menuMarc(lin,col,opc,"","",str0,str1,str2,str3,str4,str5,str6,str7,str8,
					  "","","","","","","","","","")
    RETURNING pos,str9

   RETURN pos,str9 clipped

END FUNCTION
