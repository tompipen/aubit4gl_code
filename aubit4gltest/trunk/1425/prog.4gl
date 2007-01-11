main
    define
        path_name char(200),
        string char(1000),
        stat_flag integer,
        len integer

    let path_name = "myfile"
    call channel::open_file("myfile", path_name, "r")
    if status = 0
    then
        let stat_flag = TRUE

	call channel::read("myfile", string) # No return values
        while stat_flag
            #call channel::read("myfile", string) 
            #call channel::read("myfile", string) returning stat_flag
            let stat_flag=channel::read("myfile", string) 

            let len = length(string)
            display stat_flag, ":", len, ":", string clipped
        end while
    else
        display "can't open ", path_name
    end if
end main
