globals
    define s28    char(31)
    define s29    char(31)
    define s30    char(31)
    define s28_2  char(31)
    define s30_2  char(31)
    define s30_10 char(31)
    define s30_20 char(31)
    define s30_29 char(31)
    define s30_30 char(31)
end globals

main
    call init()
    call dec_1arg_display()
    call dec_2arg_display()
    call dec_2arg_arithmetics()
end main

function init()
    let s28    = "3333333333333333333333333333"
    let s28_2  = "33333333333333333333333333.33"
    let s29    = "33333333333333333333333333333"
    let s30    = "333333333333333333333333333333"
    let s30_2  = "3333333333333333333333333333.33"
    let s30_10 = "33333333333333333333.3333333333"
    let s30_20 = "3333333333.33333333333333333333"
    let s30_29 = "3.33333333333333333333333333333"
    let s30_30 = ".333333333333333333333333333333"
end function

function dec_1arg_display()
    define d decimal(30)
    define s char(31)
    define src char(31)
    define l int
   
    let src = s28
    let d = src
    let s = d
    let l = length(src)
    display "a1:Decimal (30) <-   <", src clipped , "> length=", l clipped
    display "    dec(30)        = <", d clipped, ">"
    display "    dec(30) using  = <", d using "##############################", ">"
    display "    dec(30)->str   = <", s clipped, ">"
    display ""

    let src = s29
    let d = src
    let s = d
    let l = length(src)
    display "a2:Decimal (30) <-   <", src clipped , "> length=", l clipped
    display "    dec(30)        = <", d clipped, ">"
    display "    dec(30) using  = <", d using "##############################", ">"
    display "    dec(30)->str   = <", s clipped, ">"
    display ""

    let src = s30
    let d = src
    let s = d
    let l = length(src)
    display "a3:Decimal (30) <-   <", src clipped , "> length=", l clipped
    display "    dec(30)        = <", d clipped, ">"
    display "    dec(30) using  = <", d using "##############################", ">"
    display "    dec(30)->str   = <", s clipped, ">"
    display ""

    let src = s28_2
    let d = src
    let s = d
    let l = length(src)
    display "a4:Decimal (30) <-   <", src clipped , "> length=", l clipped
    display "    dec(30)        = <", d clipped, ">"
    display "    dec(30) using  = <", d using "############################.##", ">"
    display "    dec(30)->str   = <", s clipped, ">"
    display ""

    let src = s30_2
    let d = src
    let s = d
    let l = length(src)
    display "a5:Decimal (30) <-   <", src clipped , "> length=", l clipped
    display "    dec(30)        = <", d clipped, ">"
    display "    dec(30) using  = <", d using "############################.##", ">"
    display "    dec(30)->str   = <", s clipped, ">"
    display ""

    display ""
end function

function dec_2arg_display()
    define d30_0 decimal(30,0)
    define d30_2 decimal(30,2)
    define d30_10 decimal(30,10)
    define d30_20 decimal(30,20)
    define d30_29 decimal(30,29)
    define d30_30 decimal(30,30)
    define s char(31)
    define src char(31)
    define l int

    let src = s30
    let d30_0 = src
    let s = d30_0
    let l = length(src)
    display "b1:Decimal (30,0) <-  <", src clipped , "> length=", l clipped
    display "    dec(30,0)       = <", d30_0 clipped, ">"
    display "    dec(30,0) using = <", d30_0 using "##############################", ">"
    display "    dec(30,0)->str  = <", s clipped, ">"
    display ""

    let src = s30_2
    let d30_2 = src
    let s = d30_2
    let l = length(src)
    display "b2:Decimal (30,2) <-  <", src clipped , "> length=", l clipped
    display "    dec(30,2)       = <", d30_2 clipped, ">"
    display "    dec(30,2) using = <", d30_2 using "############################.##", ">"
    display "    dec(30,2)->str  = <", s clipped, ">"
    display ""

    let src = s30_10
    let d30_10 = src
    let s = d30_10
    let l = length(src)
    display "b3:Decimal (30,10) <- <", src clipped , "> length=", l clipped
    display "    dec(30,10)       =<", d30_10 clipped, ">"
    display "    dec(30,10) using =<", d30_10 using "####################.##########", ">"
    display "    dec(30,10)->str  =<", s clipped, ">"
    display ""

    let src = s30_20
    let d30_20 = src
    let s = d30_20
    let l = length(src)
    display "b4:Decimal (30,20) <- <", src clipped , "> length=", l clipped
    display "    dec(30,20)       =<", d30_20 clipped, ">"
    display "    dec(30,20) using =<", d30_20 using "##########.####################", ">"
    display "    dec(30,20)->str  =<", s clipped, ">"
    display ""

    let src = s30_29
    let d30_29 = src
    let s = d30_29
    let l = length(src)
    display "b5:Decimal (30,29) <- <", src clipped , "> length=", l clipped
    display "    dec(30,29)       =<", d30_29 clipped, ">"
    display "    dec(30,29) using =<", d30_29 using "#.#############################", ">"
    display "    dec(30,29)->str  =<", s clipped, ">"
    display ""

    let src = s30_30
    let d30_30 = src
    let s = d30_30
    let l = length(src)
    display "b6:Decimal (30,30) <- <", src clipped , "> length=", l clipped
    display "    dec(30,30)       =<", d30_30 clipped, ">"
    display "    dec(30,30) using =<", d30_30 using ".##############################", ">"
    display "    dec(30,30) using2=<", d30_30 using "#.##############################", ">"
    display "    dec(30,30)->str  =<", s clipped, ">"
    display ""

    display ""
end function

function dec_2arg_arithmetics()
    define s char(31)
    define s1 char(31)
    define s2 char(31)
    define src char(31)

    define d1_30_29 decimal(30,29)
    define d2_30_29 decimal(30,29)
    define r_30_29  decimal(30,29)

    define d1_24_23 decimal(24,23)
    define d2_24_23 decimal(24,23)
    define r_24_23  decimal(24,23)

    define d1_30_23 decimal(30,23)
    define d2_30_23 decimal(30,23)
    define r_30_23  decimal(30,23)

    let d1_30_29 = "1.33333333333333333"
    let d2_30_29 = "3.77777777777777777"
    let s1 = d1_30_29 
    let s2 = d2_30_29 
    let r_30_29 = d1_30_29 + d2_30_29
    let s = r_30_29
    display "c1:Decimal (30,29)    <", s1 clipped , "> + <", s2 clipped, ">"
    display "    dec(30,29)       =<", r_30_29 clipped, ">"
    display "    dec(30,29) using =<", r_30_29 using "#.############################", ">"
    display "    dec(30,29)->str  =<", s clipped, ">"
    display ""

    let d1_30_29 = "1.333333333333333333333"
    let d2_30_29 = "3.777777777777777777777"
    let s1 = d1_30_29 
    let s2 = d2_30_29 
    let r_30_29 = d1_30_29 + d2_30_29
    let s = r_30_29
    display "c2:Decimal (30,29)    <", s1 clipped , "> + <", s2 clipped, ">"
    display "    dec(30,29)       =<", r_30_29 clipped, ">"
    display "    dec(30,29) using =<", r_30_29 using "#.############################", ">"
    display "    dec(30,29)->str  =<", s clipped, ">"
    display ""

    let d1_30_23 = "1.333333333333333333333"
    let d2_30_23 = "3.777777777777777777777"
    let s1 = d1_30_23 
    let s2 = d2_30_23 
    let r_30_23 = d1_30_23 + d2_30_23
    let s = r_30_23
    display "c3:Decimal (30,23)    <", s1 clipped , "> + <", s2 clipped, ">"
    display "    dec(30,23)       =<", r_30_23 clipped, ">"
    display "    dec(30,23) using =<", r_30_23 using "#.############################", ">"
    display "    dec(30,23)->str  =<", s clipped, ">"
    display ""

    let d1_24_23 = "1.333333333333333333333"
    let d2_24_23 = "3.777777777777777777777"
    let s1 = d1_24_23 
    let s2 = d2_24_23 
    let r_24_23 = d1_24_23 + d2_24_23
    let s = r_24_23
    display "c4:Decimal (24,23)    <", s1 clipped , "> + <", s2 clipped, ">"
    display "    dec(24,23)       =<", r_24_23 clipped, ">"
    display "    dec(24,23) using =<", r_24_23 using "#.############################", ">"
    display "    dec(24,23)->str  =<", s clipped, ">"
    display ""

    let d1_30_29 = 1
    let d2_30_29 = 3
    let r_30_29 = d1_30_29 * d2_30_29
    display "c5:Decimal (30,29)    <", d1_30_29 clipped , "> * <", d2_30_29 clipped, ">"
    display "    dec(30,29)       =<", r_30_29 clipped, ">"
    display "    dec(30,29) using =<", r_30_29 using "#.############################", ">"
    display "    dec(30,29)->str  =<", s clipped, ">"
    display ""

    let d1_30_29 = 1
    let d2_30_29 = 3
    let r_30_29 = d1_30_29 / d2_30_29
    let s = r_30_29
    display "c6:Decimal (30,29)    <", d1_30_29 clipped , "> / <", d2_30_29 clipped, ">"
    display "    dec(30,29)       =<", r_30_29 clipped, ">"
    display "    dec(30,29) using =<", r_30_29 using "#.############################", ">"
    display "    dec(30,29)->str  =<", s clipped, ">"
    display ""

    let d1_24_23 = 1
    let d2_24_23 = 3
    let r_24_23 = d1_24_23 / d2_24_23
    let s = r_24_23
    display "c7:Decimal (24,23)    <", d1_24_23 clipped , "> / <", d2_24_23 clipped, ">"
    display "    dec(24,23)       =<", r_24_23 clipped, ">"
    display "    dec(24,23) using =<", r_24_23 using "#.############################", ">"
    display "    dec(24,23)->str  =<", s clipped, ">"
    display ""

    display ""
end function
