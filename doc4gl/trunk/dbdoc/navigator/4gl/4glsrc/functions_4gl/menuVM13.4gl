FUNCTION menuVertMarc13(lin,col,opc,str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11,str12)
{}

DEFINE
	lin,col,opc SMALLINT,
   str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11,str12 CHAR(40)

DEFINE
	str13 CHAR(13),
	pos INTEGER

   CALL menuMarc(lin,col,opc,"","*************",
			 str0,str1,str2,str3,str4,str5,str6,str7,str8,
					  str9,str10,str11,str12,"","","","","","")
    RETURNING pos,str13

   RETURN pos,str13 clipped

END FUNCTION
