#start of source
main
        start report rpt1 to "rpt1.out"
        output to report rpt1()
        finish report rpt1

        start report rpt2 to "rpt2.out"
        output to report rpt2()
        finish report rpt2
end main

report rpt1()

        output left margin 0
                top  margin 0
                bottom margin 0
                page length 1

        format
        on every row
        print column 0, "output"

end report

report dummy()
        output  left margin 5
                page length 60
                top of page "^L"

        format
        on every row
        print column 0, "dummy"
end report

report rpt2()

        output left margin 0
                top  margin 0
                bottom margin 0
                page length 1

        format
        on every row
        print column 0, "output"

end report
