define
	a_receive array [8] of record
        line char (60)
    end record,
    a_receive_size, a_receive_full smallint,
	IM_LOG, IM_USER, IM_PASS char (60),
	IM_DEBUG smallint

####
main
####
	let IM_LOG 		= "mylogfile.log"
	let IM_DEBUG 	= true
	let a_receive_size = 8

	###############################################
    #PLEASE! DO NOT FORGET TO CHANGE LOGIN INFO!!!
	###############################################
	#Jabber Account this program will use to connect to Jabber server:
	let IM_USER 	= "andrejipaq3@jabber.org"
	#...And it's password:
	let IM_PASS 	= "mysecretpassword"
	#Jabber account to talk to:
	call chat("andrej@jabber.org")

end main

###############
function chat(msg_to)
###############
define
    send char (1000),
    msg_to char (40),
	success,timeout,do_receive smallint,
	msg char (4000),
    rcv_from char (40)

	let a_receive_full = 0
	open window w_chat at 1,1 with form "test_im"
    display by name msg_to
	call legend()

    ##################
	input by name send
    ##################
        before input
			call legend()
        ################
		after field send #send and receive after ENTER
        ################
            call GET_FLDBUF(send) returning send
            call send_it(send,msg_to,timeout,do_receive)
        ###################
        on key(F6) #to be able to check foe waiting message, without sending one:
        ###################
            call GET_FLDBUF(send) returning send
            call send_it(send,msg_to,timeout,do_receive)
    #########
	end input
    #########
    close window w_chat
end function

################################################
function send_it(send,msg_to,timeout,do_receive)
################################################
define
    send char (1000),
    msg_to char (40),
	success,timeout,do_receive smallint,
	msg char (4000),
    rcv_from char (40)

		let timeout = 10
        let do_receive = true
        initialize msg,rcv_from to null

			if length (send) > 0 then
				let send = "I say: ",send clipped
				let a_receive_full = calc(a_receive_full)
				display send to s_receive[a_receive_full].receive attribute (green)
				let a_receive[a_receive_full].line = send clipped
				display "Sending / receiving ...                          " at 2,2
            else
				display "Receiving ...                                    " at 2,2
			end if

			call Im_exchange(send,msg_to,timeout,do_receive,im_log,im_user,im_pass,im_debug)
				returning success, msg, rcv_from

            if success > 0 then
                error "Error sending/receiving (", success,")"
            else
	            if length(msg) > 0 then
	                let msg = rcv_from clipped," say: ", msg clipped
					let a_receive_full = calc(a_receive_full)
					display msg to s_receive[a_receive_full].receive attribute (red)
					let a_receive[a_receive_full].line = msg clipped
	            end if

				initialize send to null
				display by name send

			end if

            call legend()

end function


################################
function calc(a_receive_full)
################################
define a_receive_full smallint

    let a_receive_full = a_receive_full + 1

    if a_receive_full > a_receive_size then
		let a_receive_full = 1
    end if

    return a_receive_full

end function

#################
function legend()
#################

	#bug: message is not working:
    #message "F6 send, ESC exit"
    display "F6 send, ESC exit                    " at 2,2

end function

#=============== Jabber library gunction call warpers =================

#################################################################################
function Im_exchange(msg,address,timeout,receive,im_log,im_user,im_pass,im_debug)
#################################################################################

define
    msg, rcv_msg, tmpmsg char(4000),
    address, rcv_from char (40),
    timeout, success integer,
    receive integer,
	IM_LOG, IM_USER, IM_PASS char (60),
	IM_DEBUG smallint

    initialize rcv_msg, rcv_from to null

code
{
    trim(msg);
    trim(address);
	trim(im_log);
	trim(im_user);
	trim(im_pass);

    success = fgl_4glim(msg,timeout,address,receive,rcv_msg,rcv_from,im_log,im_user,im_pass,im_debug);

	trim(rcv_msg);
	trim (rcv_from);

}
endcode

    if length(rcv_msg) <1 then
        initialize rcv_msg to null
    end if

    if length(rcv_from) <1 then
        initialize rcv_from to null
    end if

    return
        success,
        rcv_msg,
        rcv_from

end function


#-------------------------------- EOF ------------------------------