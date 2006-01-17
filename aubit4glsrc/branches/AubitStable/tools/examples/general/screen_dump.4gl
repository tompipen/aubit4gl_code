main
        call aclfgl_setenv("PRINTSCRFILE","wibble.out")
        display "Hello" at 1,1
        call aclfgl_dump_screen()
        display "World" at 2,1
        call aclfgl_setenv("PRINTSCRFILE","bibble.out")
        call aclfgl_dump_screen()
end main
