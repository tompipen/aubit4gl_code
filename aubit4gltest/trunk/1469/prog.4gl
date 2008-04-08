main
    call do_it()
end main

function do_it()
define
    va array[7] of char(15)
    , lcv smallint

    let va[1] = '1'
    let va[2] = '1'
    let va[3] = '3'
    let va[4] = 'five'
    let va[5] = 'two' 
    let va[6] = 'two'
    let va[7] = 'two'

    start report cc to 'cc.out'
    start report vc to 'vc.out'

    for lcv = 1 to 7
        output to report cc (va[lcv])
        output to report vc (va[lcv])
    end for

    finish report cc
    finish report vc

end function

report cc(xr_in)
define
    xr_in char(15)

output
    top margin 0
    bottom margin 0
    left margin 1
    right margin 120
    page length 1

order external by xr_in

format
    after group of xr_in
    print xr_in, group count(*) using "#####"
end report
#_ report cc

report vc(xr_in)
define
    xr_in varchar(15)

output
    top margin 0
    bottom margin 0
    left margin 1
    right margin 120
    page length 1

order external by xr_in

format
    after group of xr_in
    print xr_in, group count(*) using "#####"

end report
#_ report vc
