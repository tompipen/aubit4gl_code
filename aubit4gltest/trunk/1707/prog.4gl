main
    DEFINE m money(8,2)
    DEFINE c char(11)
    DEFINE c2 char(11)

    LET m = 123.45
    LET c = m
    LET c2 = m USING "-$$$$$$$&.&&"
    DISPLAY m 
    DISPLAY c
    DISPLAY c2 
end main

