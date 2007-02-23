    main
 define w_file CHAR(40)
 
 let w_file = "repoascii.out.expected"
 {! let w_file = "repoascii.out" }
 start report repoascii_repo to w_file
 output to report repoascii_repo()
 finish report repoascii_repo
 end main
 
 report repoascii_repo()
 
 output
 left margin 0 bottom margin 0 top margin 0 page length 1
 
 format
    on every row
        print "1", "23456";
        print column 7, "7th"
        print ascii 49, "23456";
        print column 7, "7th"
        print ascii 31, "23456";
        print column 7, "7th"
 end report
