main
define lv_top integer
define lv_sub integer
define lv_str char(255)


let lv_top=A4GL_sxml::sxml_put_next(0,"Area")

let lv_sub=A4GL_sxml::sxml_put_sub(lv_top,"Sub 1")
call A4GL_sxml::sxml_put_value(lv_sub,"Sub 1 value")


let lv_sub=A4GL_sxml::sxml_put_sub(lv_top,"Sub 2")
call A4GL_sxml::sxml_put_value(lv_sub,"Sub 2 value")


let lv_sub=A4GL_sxml::sxml_put_sub(lv_sub,"Sub 2.1")
call A4GL_sxml::sxml_put_value(lv_sub,"Sub 2.1 value")


let lv_sub=A4GL_sxml::sxml_put_sub(lv_sub,"Sub 2.1.1")
call A4GL_sxml::sxml_put_value(lv_sub,"Sub 2.1.1 value")


let lv_sub=A4GL_sxml::sxml_put_next(lv_sub,"Sub 2.1.2")
call A4GL_sxml::sxml_put_value(lv_sub,"Sub 2.1.2 value")


let lv_str=A4GL_sxml::sxml_get_xml_as_text("Head",lv_top)

if A4GL_sxml::sxml_writefile("test.xml",lv_top) then
	display lv_top," ", lv_str
else
	display "Unable to write it.."
end if

call A4GL_sxml::sxml_free_tree(lv_top)

end main
