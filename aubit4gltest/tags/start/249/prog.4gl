main
define a array[100] of record
    a integer,
    b date
    end record,
    i integer

    for i = 1 to 10
        let a[i].a=i
        let a[i].b=today
    end for
    open window w at 2,2 with form "v1" attribute(border)
    call set_count(10)
    input array a without defaults from s.*
    close window w
end main
