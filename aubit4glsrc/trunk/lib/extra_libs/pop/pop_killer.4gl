# POP3 mailbox delete program
# Check the rules carefully before running!!!

define lv_delcnt integer
define lv_started integer
define lv_stime datetime year to second
define lv_ival interval second(10) to second
define lv_etime datetime year to second


main
define lv_details  record
	server char(40),
	userid char(20),
	passwd char(20)
end record

let int_flag=false

# Initialize our stats counters...
let lv_stime=current year to second
let lv_delcnt=0

if num_args()=0 then
	open window w1 at 10,20 with form "test" attribute(border)
	input by name lv_details 
	close window w1
	if int_flag=true then
		exit program
	end if
else
	let lv_details.server=arg_val(1)
	let lv_details.userid=arg_val(2)
	let lv_details.passwd=arg_val(3)
end if


call display_messages(lv_details.*)


end main



function display_messages(lv_details)
define lv_details  record
	server char(20),
	userid char(20),
	passwd char(20)
end record
define id char(20)
define i integer
define nmsg integer
define txt char(2048)
define tmptxt char(2048)
define tmpstr char(20)
define subject char(80)
define lv_t float

let lv_started=0
while true
	set pause mode off
	call banner("Connecting to server....")

	if lv_started then
		CALL A4GL_pop::popend()
		let lv_started=0
	end if

	if A4GL_pop::popbegin(lv_details.server,lv_details.userid,lv_details.passwd) then
		let lv_started=1
		call banner("Connected OK")
	else
		call banner("Connection Failed")
		continue while
	end if


        call banner("Collecting Data")

set pause mode on
clear screen
call banner("POP SESSION ACTIVE")
let nmsg=A4GL_pop::popnum()

display "You have ", nmsg USING "####&"," Messages" at 4,1
for i=1 to nmsg


		let txt=A4GL_pop::popgethead(i)
		let subject=txt
code 
{
int a;
char *ptr;
for (a=0;a<strlen(txt);a++) if (txt[a]<' '||!isprint(txt[a])) txt[a]='^';
ptr=strstr(txt,"^^Subject:");

if (ptr) {
	ptr+=strlen("^^Subject: ");
	strncpy(subject,ptr,sizeof(subject));
	subject[sizeof(subject)-1]=0;
	ptr=strstr(subject,"^^");
	if (ptr) *ptr=0;
} else {
	strcpy(subject,"No Subject");
}
}
endcode


	if i+5<=23 then
		display i using "####" at i+5,1
		display " ",subject clipped  at i+5,6
	end if

# Do we want to delete this message ?

	if subject="Re: Re: My details" or subject="Re: Wicked screensaver"
		or subject matches "Disallowed attachment type found in sent message*" 
		or subject ="Re: Your application"
		or subject ="Returned mail: see transcript for details"
		or subject ="Your details"
		or subject ="Thank you!"
		or subject="Re: That movie"
		or subject="Re: Thank you!"
		or subject="Re: Details"
		or subject="Re: Approved"
		or subject matches "Virus Found in message *"
		or subject ="Undelivered Mail Returned to Sender"
 	then
		if i+5<23 then
		display "-" at i+5,6 attribute(red,reverse)
		display subject clipped  at i+5,7 attribute(red)
		end if
		message "Deleting :",i
		set pause mode off
		set pause mode on
		call A4GL_pop::popdelmsg(i)
		let lv_delcnt=lv_delcnt+1
	end if

end for
display "Deleted : ",lv_delcnt using "<<<<<<"," messages" at 24,20

let lv_etime=current year to second
let lv_ival=lv_etime-lv_stime

let tmpstr=lv_ival
let i=tmpstr
let lv_t=lv_delcnt
let lv_t=lv_t/i
let i=i/60
let lv_t=lv_t*60
display "In ",i ," minutes ",lv_t using "###&.&&","/m" at 24,45
set pause mode off
if lv_started then
	CALL A4GL_pop::popend()
	let lv_started=0
end if
call banner("POP SESSION INACTIVE")
sleep 10
end while

end function
function banner(s)
define s char(80)
let s[50,80]=" "
let s[50,65]=today
let s[65,80]=current hour to second
display s,"" at 1,1 attribute(reverse,cyan)
end function
