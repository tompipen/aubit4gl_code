
main
define  p_parm          array[5] of record
        f1      char(1),
        f2      char(1),
        f3      char(1)
end record
define i integer
define xrow integer
define xscr integer
define a integer
define lv_n integer
define lv_name char(18)
define lv_dim integer

        open window genparmwin at 2, 2 with 16 rows, 46 columns
        attribute (green, border)
        open form _variable("gen_form") from "v"
        display form _variable("gen_form") attribute (cyan)

        if find_record_size("gen_form","parm_scr") != 5 then
		display "Did not get correct record size"
		exit program 2
	end if
end main

function find_record_size(lv_form, lv_name)
define lv_name,lv_form char(20)
define a integer
define lv_norecs integer
let lv_norecs=a4gl_get_info("Form","gen_form","ScreenRecordCount")

for a=0 to lv_norecs-1 # 0 indexed..
        if lv_name=a4gl_get_info("Form","gen_form","ScreenRecordName"||a using "&<<") then
                return a4gl_get_info("Form","gen_form","ScreenRecordSize"||a using "&<<")
        end if
end for

return 0
end function

