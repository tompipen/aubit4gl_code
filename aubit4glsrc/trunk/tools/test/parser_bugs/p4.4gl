define xcmd char(1000)
main
        let xcmd = "cat /usr/isd/cron/isdmenu 2>/dev/null | ",
                   " grep 'isdsales.t D' 2>/dev/null | ",
                   " awk '{print $5""|""$2""|""$1""||""}' > /tmp/isdmenu.unl ",
                   " 2>/dev/null"
        run     xcmd
end main
