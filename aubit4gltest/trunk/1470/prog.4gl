database test1
main
    call do_it()
end main

function do_it()
define
    va array[7] of record
      c char(15)
      , d interval hour(2) to second
    end record
    , lcv smallint

    let va[1].c = '1'
    let va[2].c = '1'
    let va[3].c = '3'
    let va[4].c = 'five'
    let va[5].c = 'two' 
    let va[6].c = 'two'
    let va[7].c = 'two'

    let va[1].d = ' 2:01:01'
    let va[2].d = ' 2:02:01'
    let va[3].d = ' 2:03:01'
    let va[4].d = ' 2:07:01'
    let va[5].d = '12:00:01'
    let va[6].d = ' 8:00:01'
    let va[7].d = ' 1:33:09'

    start report cc to './cc.out'

    for lcv = 1 to 7
        output to report cc (va[lcv].c, va[lcv].d)
    end for

    finish report cc

end function

report cc(xr_inRec)
define
    xr_inRec record
      c char(15)
    , d interval hour(2) to second
    end record

output
    top margin 0
    bottom margin 0
    left margin 1
    right margin 120
    page length 1

#order external by xr_inRec.c
order by xr_inRec.c

format
   
    after group of xr_inRec.c
    print xr_inRec.c , group count(*) using "#####" , group avg(xr_inRec.d)
    print
    print
        

    #on every row
    #print xr_inRec.c, xr_inRec.d - 2 units minute, xr_inRec.d xr_inRec.d + 30 units second

end report
#_ report cc
