main
define lv_rec record
        uname char(8),
        passwd char(20),
        uid integer,
        gid integer,
        udesc char(50),
        uhome char(50),
        ushell char(50)
end record
define lv_in char(10)
define lv_out char(10)
define b integer

let lv_in="fin"
let lv_out="fout"

call channel::open_file("fin","/etc/passwd","r")
call channel::open_file("fout","passwd.new","w")

call channel::set_delimiter("fin",":")
call channel::set_delimiter("fout",":")

call channel::read(lv_in,[lv_rec.*]) returning b

display "First line : ", "Uname=",lv_rec.uname," uid=",lv_rec.uid

call channel::write(lv_out,[lv_Rec.*])

while channel::read(lv_in,[lv_Rec.*])

        call channel::write(lv_out,[lv_Rec.*])

        display "Uname=",lv_rec.uname," uid=",lv_rec.uid
end while

call channel::close("fin")
call channel::close("fout")
end main
