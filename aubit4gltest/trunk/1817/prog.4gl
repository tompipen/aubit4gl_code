define # module variables
    pr_pkt record
       pktnr integer,         
       lastorder integer            
    end record

main 

   defer interrupt           # unterbrechungen nicht zulaessig
   call startlog("./err.log")
   whenever error call error_treat

   options message line 2,
           prompt line 2,
           form line 3,
           comment line 24,  #or comment line LAST
           error line 2,
           input wrap
#the options statement does not correctly override the I4GL default
#"comment line LAST -1"
#if you move it up a line it works correctly

     open form pkt from "m1"
     menu "LINE1"
        command "1-SRC" "LINE2 CUSTOMERS: Search "
	   call pkt_suchen()
	   if pr_pkt.pktnr is null then
	      call clear_bild()
	      clear form
	      initialize pr_pkt.* to null
	   end if
	   call clear_bild()

           exit program
        command "2-MOD" "LINE2 CUSTOMERS: Modify"
	   if pr_pkt.pktnr is null then
	      call pkt_suchen()
	      if pr_pkt.pktnr is not null then
		 call pkt_bearbeiten()
	      end if
	   else
	      call pkt_bearbeiten()
	   end if
	   call clear_bild()
           exit program
        command "3-ENT" "LINE2 CUSTOMERS: Enter new customers/suppliers"
           call pkt_erfassen()
           call clear_bild()
           exit program
        command "4-X" "LINE2 exit"
		exit menu
     end menu
   close form pkt
end main


#PKT_ERFASSEN
function pkt_erfassen()

   call clear_bild()
   initialize pr_pkt.* to null
   let int_flag = false          # unterbrechungs flag
   while not int_flag

        message "LINE2 <ESC> search, <F9> cancel"
        display form pkt
        input
              pr_pkt.pktnr,
              pr_pkt.lastorder
              without defaults from
              scr_pkt.pktnr,
              scr_pkt.lastorder

            on key (F9)
              let int_flag = true
              exit input     

        end input

       if int_flag then
          let int_flag = false
          call clear_bild()
          exit while
       end if       

   end while  # not int_flag

   initialize pr_pkt.* to null
   call clear_bild()

end function # pkt_erfassen


#PKT_BEARBEITEN
function pkt_bearbeiten()

   let int_flag = false

   while not int_flag

      message "LINE2 <ESC> search <F9> cancel <F2>..<F6> skip"

        input
              pr_pkt.pktnr,
              pr_pkt.lastorder 
              without defaults from
              scr_pkt.pktnr,
              scr_pkt.lastorder 

            on key (F9)
              let int_flag = true
              exit input     

        end input

      if int_flag then
         let int_flag = false
         exit while
      end if # int_flag

      exit while

   end while # not int_flag

   initialize pr_pkt.* to null
   call clear_bild()

end function # pkt_bearbeiten


#PKT_SUCHEN
function pkt_suchen()

define such_string char(200)

   message "LINE2 <ESC> search <F9> cancel <F1>..<F6> skip"
   initialize pr_pkt.* to null
   let int_flag = false
   display form pkt
   clear form   # this generates an error as theres no current form
   construct such_string on
     pkt.pktnr, 
     pkt.lastorder  
   from scr_pkt.pktnr,
        scr_pkt.lastorder 
     on key (F9)
	call aclfgl_dump_screen("out")
        let int_flag = true
        exit construct

   end construct
   message ""

end function # pkt_suchen


function clear_bild()
   define zeile smallint
   for zeile = 3 to 23
     display "" at zeile, 1
   end for
   message ""
end function # clear_bild()


function error_treat()
  define errtext char(100)
  let errtext = err_get(status)
  call errorlog(errtext)
  #update fehler set fehler = "+" where fehler <>"+"
end function

# EOP mike3.4gl


