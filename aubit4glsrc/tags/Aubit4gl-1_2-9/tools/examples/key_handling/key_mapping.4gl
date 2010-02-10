#
# This demonstrates mapping of keys
# on a linux console - the Home and End keys are mapped to be F20 and F21
# This means we can detect those key presses by looking for F20 and F21 in 
# our prompt/menu/input statements (etc)
#
main
define b char(20)
        call aclfgl_add_keymap( 65290,3019) # Home -> F20
        call aclfgl_add_keymap( 65291,3020) # End  -> F21
        while true
                prompt "Enter 'A' 'B' (in upper case)" for b
                on key(f20) display "Home" at 2,2
                on key(f21) display "End " at 2,2
                end prompt
        end while
end main
