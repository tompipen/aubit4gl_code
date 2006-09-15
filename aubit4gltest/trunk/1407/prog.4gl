main

call test_if()

end main

function test_if()
define
   p_rec record
      col1   char(10),
      col2   char(10),
      col3   char(10),
      col4   char(10),
      col5   char(10),
      col6   char(10),
      col7   char(10),
      col8   char(10)
   end record

initialize p_rec.* to null

let p_rec.col2 = "FOO"

if p_rec.col1 clipped is null and
   p_rec.col2 clipped is null and
   p_rec.col3 clipped is null and
   p_rec.col4 clipped is null and
   p_rec.col5 clipped is null and
   p_rec.col6 clipped is null and
   p_rec.col7 clipped is null and
   p_rec.col8 clipped is null then

   display "shouldn't see this"
	exit program 1
else
   display "should see this"
	exit program 0
end if

end function
