# calculate compound interest using
# 4gl and C - (there are quicker ways of doing this - but this is an example of
# using C within a 4gl program)
#
main
define a float
define b float
define c integer


let a=1 # Initial value
let b=0.03 # Interest rate

# Lets calculate a 100 years of compound interest
# the very long way...
for c=1 to 100
        let a=a*(1+b)
end for
display a


let a=1 # Initial value
let b=0.03 # Interest rate

## Lets do it again - but in C for speed...
code
for (c=1;c<=100;c++) a*=(1.0+b);
endcode

display a
end main

