#       repwrap.4gl
#       This program demonstrates whether the print attribute: wordwrap
#       is implemented OK.
#       The output should be 5 lines as follows:
#       Talk to me
#       0123456789
#       9 of the above followed by 10 spaces (not wrapped)
#       the above wrapped at the right margin
#       time
#
main
        start report fred
        output to report fred('Talk to me')
        finish report fred
end main

report fred( l )
        define l char(10)
        define l_long char(100)
        define l_ten char(10)
	define l_time datetime hour to second
output
        report to "out"
        page length 10
        right margin 60

format
first page header
        let l_ten = '0123456789'
        let l_long = l_ten || l_ten || l_ten || l_ten || l_ten ||
                 l_ten || l_ten || l_ten || l_ten || '         '

on every row
	let l_time="11:49:41"
        print l
        print l_ten
        print l_long, ']'
        print l_long wordwrap
        print l_time
end report
