Hi *,

we now have basic IM (Instant Messaging) and XML parsing/generating 
functionality as part of Aubit 4lg compiler, implemented using IksEmEl 
library. You can send and receive messages to/from other Jabber (and ICQ, 
AIM, MS Messenger, SMS, ... anything supported in your Jabber server) 
clients, to humans using Jabber clients, or other programs, including 
other Aubit 4gl programs.

What is it good for:

We already have RCP in Aubit, but this RCP implementation is usable only 
for talking between Aubit programs; and on LAN, it's just not good for 
Internet. No talking to humans.

Whit JAM (Jabber as Middleware), you can do things like notify the user 
when some condition arises (like, report is finished, expense report is 
waiting for your approval) without the need to have program running on 
your screen. OK, you can send email, but with Jabber, you can reply too. 
For instance, you can click on predefined choices in Jabber message, and 
send waiting report to printer, or to someone else.

Using IksEmEl, you can also create and send XML files, meaning you can 
send fully formatted data, exchange arrays between programs, send HTML XML 
formatted pages, output XML formatted files from 4gl programs...

And Jabber takes care of queuing (if other party is not on-line) 
encryption, firewalls, etc. All you need to know is Jabber ID if your 
correspondent.

To me, Jabber is more then XML-RPC, since it can talk to humans. It can 
perform more/most tasks XML-RPC can. But it is not SOAP.

Where are we:

Code is in tools/jabber

This very early stage, only send and receive is working, with not much 
error checking, in one word, early Alpha code, or maybe more like proof of 
concept code. I tried to do much more, based on JabberX client 
(http://sourceforge.net/projects/jabber-x), but failed miserably because 
of sometimes strange (to me anyway) inner workings of Jabber protocol, 
abandoned a lot of code, and started from scratch directly on top of 
IksEmEl libraries.

Now what we have is very basic handling of Jabber functionality 
(lib4glim.c) and a little 4gl test program (test_im.4gl) in /tools/jabber.

To work, this require IksEmEl library:

http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/jabber-x/iksemel/

More information about Jabber:

www.jabber.org
www.jabbercentral.org

Questions:

* Do you guys like/need this kind of functionality? Better ways? Ideas?

* I need a 4gl language bindings for this; I was looking at syntax used 
for RCP in Aubit, but I don't thing this is a good fit. How about:

	SEND "my message" TO "andrej@jabber.org" USING "somebody@jabber.com" 
	WITH "mypassword"
	RECEIVE INTO my_charvar [charvar_from,] [charvar_when] [ FROM 
	"somebody@jabber.com" ]

There will be some more needed later, like:

	SEND PRESENCE ...
	SUBSCRIBE PRESENCE ...
	GET ROOSTER
	... and more ...

Thanks,


Yours, Andrej Falout, http://www.falout.com/disclaimer.html
Visit the OpenSource alternative, Aubit 4gl: 
http://aubit4gl.sourceforge.net
PLEASE NOTE: All HTML email sent to me WILL BE DELETED AUTOMATICALLY 
WITHOUT READING.