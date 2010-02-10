main
define lv_message integer
define lv_mainpart integer
define lv_textpart integer
define lv_htmlpart integer
define lv_pdfpart integer

let lv_message=fgl_smtp::start_message("mike.aubury@aubit.com","Another New Test Message")
call fgl_smtp::send_to(lv_message,"mike.aubury@aubit.com")
let lv_mainpart = fgl_smtp::mime_type_new(lv_message,0,"multipart/mixed")
let lv_textpart = fgl_smtp::mime_type_new(lv_message,lv_mainpart,"text/plain")
let lv_pdfpart=fgl_smtp::mime_type_new_with_description(lv_message,lv_mainpart,"application/pdf","m1.pdf")
call fgl_smtp::connect(lv_message,"localhost",0,0,1)
call fgl_smtp::part_send_txt(lv_message,"Your report output is attached",0)
call fgl_smtp::part_send_file(lv_message,"m1.pdf",1)
call fgl_smtp::disconnect(lv_message)

end main

