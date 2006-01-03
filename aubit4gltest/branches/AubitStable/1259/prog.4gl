main

if fgl_getenv("XXX_SOMETHING_NOT_SET") is not null then
    display "set"
    exit program 1
else
    display "not set"
end if

if fgl_getenv("AUBITDIR") is not null then
    display "set"
else
    display "not set"
    exit program 1
end if


end main
