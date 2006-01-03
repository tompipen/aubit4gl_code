
#if you need to use database, use "test1"
#database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"


{
	From: 	Bernard Moreton <moreton@rolvenden.freeserve.co.uk>
To: 	aubit <aubit4gl-discuss@lists.sourceforge.net>
Subject: 	[Aubit4gl-discuss] Problem in DISPLAY variable_list TO FORMFIELD_LIST
Date: 	Thu, 11 Mar 2004 18:50:27 +0000	
AUBIT 0.47-35

Walter Haslbeck recently (10 March) raised the issue of AUBIT not displaying overflows properly in form fields.  That was actually quite a considerable help in diagnosing my problem here - could we have an environmental variable to allow/disallow that normal behaviour?

My problem is in displaying a list of variables to a list of form fields.  What happens on a straight 
DISPLAY variable_list TO formfield_list
is that only the last variable is displayed, in the last formfield.  If, however, the variables are DISPLAYED in the main screen before the form is opened, then the second variable is displayed in all the relevant fields (truncated in shorter fields) except the last, where the last variable is again displayed correctly.  IF THIS HAS BEEN CURED SINCE THE BUILD I'M USING, PLEASE FORGIVE!  I KNOW I'M OVERDUE FOR AN UPDATE....

The code is as follows - not in best-practice shape, I know, but it's in the course of being translated from a BASIC dialect on DOS, so mere functionality will do at this stage!

Have I screwed up the above DISPLAY statement, or is there a bug here?  Why should a preliminary DISPLAY to screen change the functionality of the DISPLAY to FORM?  And why is the second field being picked out rather than any of the others??  I have no problem in DISPLAY variable TO formfield, so I can do this the long way round;  but shorter would be better!

}

schema simas

define
        my_db char(4),
        my_flag char(12),
    nextprog char(8),
        yrset char(1),
        ans char(1),
        sys_name like sysdata.sysname,
        cy like sysdata.curr,                           # currency character
        # sx record
                btsno smallint, btval dec(8,2), btono smallint,
                ubsno smallint, ubval dec(8,2), ubono smallint,
        l_nasn like sysdata.nasn,
            l_nasv like sysdata.nasv,
            l_naon like sysdata.naon,
        l_nbsn like sysdata.nbsn,
            l_nbsv like sysdata.nbsv,
            l_nbon like sysdata.nbon
                # end record

main
  let my_db=fgl_getenv('MY_DB')
  if my_db = "" then let my_db='hbs'
        end if
  database my_db
  database simas

  select sysname into sys_name from sysdata
  select curr into cy from sysdata

  let my_flag=fgl_getenv('MY_DB')
  # if my_flag <> "" then fgl_putenv('MY_DB=""')
  if my_flag<>"bk_conv_done"
        then
    # -------------- INITIALIZE VARIABLES ------------      
    let nextprog="menu"
        let yrset=0
    let btsno=0
        let btono=0
        let btval=0
    let ubsno=0
        let ubono=0
        let ubval=0
  end if
  
  clear screen
  display sys_name at 0,2
  display "SUBSCRIPTION PROCESSING" at 1,2
  
  clear screen
  display sys_name at 1,2
  display "SUBSCRIPTION PROCESSING" at 2,2
 
  select nasn into l_nasn from sysdata
  select nasv into l_nasv from sysdata
  select naon into l_naon from sysdata
  select nbsn into l_nbsn from sysdata
  select nbsv into l_nbsv from sysdata
  select nbon into l_nbon from sysdata

# UNCOMMENT THE FOLLOWING LINE TO GET A WEIRD CHANGE IN DISPLAY
 display l_nasn, ' ', l_nasv, ' ', l_naon, ' ', l_nbsn, ' ', l_nbsv, ' ', l_nbon at 18,5  

  open window wx at 4,38 with form "subs_sx" attribute (border)
  display l_nasn, l_nasv, l_naon, l_nbsn, l_nbsv, l_nbon to
                        s_nasn, s_nasv, s_naon, s_nbsn, s_nbsv, s_nbon
  display l_nasn to s_nasn
  

end main
