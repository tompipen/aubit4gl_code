#demonstrates how to use full reg-ex matching..
#
main
        if a4gl_pcre::pcre_match("dog|cat","The cat sat on a hat") then
                display ":",a4gl_pcre::pcre_text(1)
        end if
end main
