#	ITIML.4gl - Timer routines
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: May 97
#	Current release: Jan 02
#
#	This library is free software; you can redistribute it and/or
#	modify it under the terms of the GNU Lesser General Public
#	License as published by the Free Software Foundation; either
#	version 2.1 of the License, or (at your option) any later version.
#
#	This library is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#	Lesser General Public License for more details.
#
#	You should have received a copy of the GNU Lesser General Public
#	License along with this library; if not, write to the Free Software
#	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

#include "itiml.4gh"

define	tim_rec	array[10] of record
				time,
				delay		integer,
				left		smallint,
				appwide,
				alarmtype	smallint,
				msg,
				parm		smallint,
				eventid		integer
			     end record,
	tim_cur,
	tim_cnt,
	key_idx,
	key_eval	smallint,
	tim_id		integer

#
#  module initialization
#
function tim_init()
    whenever error call trap_err
    let tim_cnt=0
    let tim_cur=0
    let tim_id=0
    let key_idx=""
    let key_eval=""
end function
#
#  enter a wake-up
#
function tim_set(d, l, a, k, m, p)
    define d		integer,
	   l, a, k	smallint,
	   m, p		smallint,
	   idx, i, j	smallint

    if (tim_cnt<10) and (d>0) and (m is not null or p is not null)
    then
	case
	  when (k=A_keyboard) and (key_idx is null)
	    let idx=tim_cnt+1
	    let key_idx=idx
	  when (k=A_keyboard) or (key_idx is null)
	    let idx=tim_cnt+1
	  otherwise
	    for i=tim_cnt to key_idx step -1
		let j=i+1
		let tim_rec[j].*=tim_rec[i].*
	    end for
	    let idx=key_idx
	    let key_idx=key_idx+1
	end case
	let tim_cnt=tim_cnt+1
	let tim_rec[idx].delay=d
#
#  in the tim_event routines, we need a fast datetime comparison,
#  so it seemed reasonable not to mess with datetimes and go down
#  to OS time instead. Now, time (2) and alarm (2) are the only system
#  calls available in all UNIX flavours, and they only go down to the
#  second. This poses resolution problems for very short delays (I am
#  thinking of 1 sec delays here), which we try to circunvene with the
#  following code. If the port in use does not support fractions, too bad!
#  
	if (current fraction to fraction(1) >
	    datetime(.4) fraction to fraction(1))
	then
	    let d=d+1
	end if
	let tim_rec[idx].time=get_time()+d
	let tim_rec[idx].left=l
	let tim_rec[idx].appwide=a
	let tim_rec[idx].alarmtype=k
	let tim_rec[idx].msg=m
	let tim_rec[idx].parm=p
	let tim_id=tim_id+1
	let tim_rec[idx].eventid=tim_id
	call nextalarm_tim()
	if (key_idx is not null) and (key_eval is null)
        then
	    let key_eval=true
	end if
	return tim_id
    end if
    return ""
end function
#
#  remove a wake-up
#
function tim_drop(e)
    define e		integer,
	   i, j, k	smallint

    for i=1 to tim_cnt
	if tim_rec[i].eventid=e
	then
	    call remove_tim(i)
	    call nextalarm_tim()
	    exit for
	end if
    end for
end function
#
#  remove viewer dependent wake_ups
#
function tim_clear()
    define i, j, k	smallint

    for i=1 to tim_cnt
	if not tim_rec[i].appwide
	then
	    call remove_tim(i)
	end if
    end for
    call nextalarm_tim()
end function
#
#  returns an event to horz/vert menu
#
function tim_event()
    define keyhit	char(1),
	   i, k, m, p	smallint

    if (tim_cnt>0)
    then
	if (tim_rec[tim_cur].time<=get_time())
	then
#
#  Uh, Oh! we may have unfired messages, here
#
	    for i=1 to tim_cnt
		case
		  when (i>=key_idx) and (key_eval)
		    exit for
#
#  for the time being an expired kbd alarm gets rescheduled as all the others
#  (what I mean for expired is that the user has spent far too much time on an
#  INPUT or similar statement *invoked by a timer generated message* - an
#  unlikely situation - if you don't like that, here's the place to make
#  changes)
#
#		  when (i>=key_idx)
#
		  when (tim_rec[i].time<=get_time())
		    let m=tim_rec[i].msg
		    let p=tim_rec[i].parm
		    let k=tim_rec[i].alarmtype
		    call reschedule_tim(i)
		    if (k=A_mandatory) and pan_test(m)
		    then
			call nextalarm_tim()
			return "", m, p
		    end if
		end case
	    end for
	    call nextalarm_tim()
	end if
        if key_eval
	then
	    for i=key_idx to tim_cnt
		let tim_rec[i].time=get_time()+tim_rec[i].delay
	    end for
	    let key_eval=false
	    call nextalarm_tim()
	end if
	if (tim_cnt>0)
	then
	    call tim_setalarm(tim_rec[tim_cur].time)
	end if
    end if
    let keyhit=readkey()		#readkey disables the alarm
    case
      when (tim_cnt=0)
      when (tim_alarmstate())
	let int_flag=false
	let m=tim_rec[tim_cur].msg
	let p=tim_rec[tim_cur].parm
	if (tim_rec[tim_cur].alarmtype=A_countpriority)
        then
	    let tim_rec[tim_cur].left=tim_rec[tim_cur].left-1
	end if
	call reschedule_tim(tim_cur)
	call nextalarm_tim()
	if pan_test(m)
	then
	    return "", m, p
	end if
       when (key_idx is not null)
	let key_eval=true
    end case
    return keyhit, "", ""
end function
#
#  work out next wake up
#
function nextalarm_tim()
    define i	smallint

    let tim_cur=1
    for i=2 to tim_cnt
	if tim_rec[i].time<tim_rec[tim_cur].time
	then
	    let tim_cur=i
	end if
    end for
end function
#
#  reschedule current alarm
#
function reschedule_tim(idx)
    define idx smallint

    if (tim_rec[idx].alarmtype!=A_countpriority)
    then
	let tim_rec[idx].left=tim_rec[idx].left-1
    end if
    let tim_rec[idx].time=tim_rec[idx].time
			   +tim_rec[idx].delay
    while (tim_rec[idx].time<=get_time()) and (tim_rec[idx].left!=0)
	let tim_rec[idx].left=tim_rec[idx].left-1
	let tim_rec[idx].time=tim_rec[idx].time
				+tim_rec[idx].delay
    end while
    if (tim_rec[idx].left=0)
    then
	call remove_tim(idx)
    end if
end function
#
#  internal routine to drop an event
#
function remove_tim(idx)
    define idx		integer,
	   i, j		smallint

    for i=idx to tim_cnt
	let j=i+1
	let tim_rec[i].*=tim_rec[j].*
    end for
    let tim_cnt=tim_cnt-1
    case
      when (idx<key_idx)
	let key_idx=key_idx-1
      when (key_idx>tim_cnt)
	let key_idx=""
	let key_eval=""
    end case
end function
