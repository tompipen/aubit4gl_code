main
define a integer
let a=0
{let a=a+1}
{!let a=a+2!}
{!
let a=a+4
!}

{! 
code 
 a+=8; 
endcode
!} 

#Should also test -! end-of-line Aubit specific non-comment

display a
end main
