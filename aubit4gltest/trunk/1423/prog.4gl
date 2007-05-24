{**
 * @file
 * MID 828. WORDWRAP RIGHT MARGIN not working
 * @process TEST_GENERAL
 *}

database test1
 
 define m_t text
 main
 
 define w_t text
 create temp table printext (t text)
 locate w_t in file "printext.txt"
 insert into printext values (w_t)
 
 locate m_t in memory
 select t into m_t from printext
 start report repotext_repo to "repotext.out"
 output to report repotext_repo()
 finish report repotext_repo
 end main
 
 report repotext_repo()
 output
    left margin 0 top margin 0 bottom margin 0 right margin 30 page length 10
 
 format
    on every row
        print COLUMN 1, m_t
        print
        print column 3, m_t wordwrap right margin 20
 end report
