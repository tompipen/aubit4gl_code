DATABASE test1
MAIN
#MID 512
	call xx()
end main

FUNCTION xx()
DEFINE
     i,j        SMALLINT,
     xx_array   RECORD
        xx      LIKE  tab1.x,
        yy      LIKE  tab1.y
     END RECORD

OPTIONS
   COMMENT LINE 23

DISPLAY  aclfgl_sizeof(xx_array), " ",aclfgl_sizeof(i)
END FUNCTION
