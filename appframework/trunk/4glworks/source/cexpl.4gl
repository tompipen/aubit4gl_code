#	CEXPL.4gl - SQL interpreter: expansions
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Jun 98
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

#include "idefl.4gh"
#define K_varsize	300
#define K_exprsize	300
#define K_stacksize	10
#define K_scriptbuf	32766	#bug in pushquote/popquote! do not use 32767!

#
#  searches & substitutes <+ +> clauses and drops <* *> comments
#
function sql_explode(i_query, hash, verbose, state, s)
    define i_query	char(K_scriptbuf),
	   hash		byte,
	   verbose,
	   state,
	   s		smallint,
	   q_buf	char(K_scriptbuf),
	   q_stack	array[K_stacksize] of smallint,
	   ccnt, qcnt	smallint,
	   qbase, tbase	smallint,
	   b, l		smallint,
	   ts, te	smallint,
	   i, j		smallint,
	   p, q, r, tl	smallint,
	   sep		char(1),
	   quotes	char(2),
	   varname	char(40),
	   dummy	char(40),
	   txt		char(K_varsize),
	   toksep	char(3),
	   p_mode	char(10),
	   e_mode	smallint,
	   multi,
	   i_multi	smallint

    whenever error call trap_err
    let sqlca.sqlcode=0
    if (s<2 or s is null)
    then
	let s=1
	call hst_start(hash, 32)
    end if
    let b=s
    let l=length(i_query)
    let qcnt=0
    let ccnt=0
    let tbase=0
    let qbase=1
    let q_buf=" "
    let toksep=" ", ascii 8, ascii 10
    while true
#
#  looping and looping, we got past the end of the buffer without a thing
#  in our hands!
#
	if (s>l)
	then
	    exit while
	end if
	let ts=posbrk(i_query[s, l], "<*+\\")+s-1
	let te=ts+1
	case
#
#  nothing found or end of buffer
#
	  when (ts<s) or (te>l)
	    exit while
	  when (ccnt>0)
	  when (ts=s)
#
#  copy string before token in expansion buffer if within expansion
#  and not comment
#
	  when (qcnt>0)
	    let p=ts-s+qbase-1
	    let q=ts-1
	    let q_buf[qbase, p]=i_query[s, q]
	    let qbase=p+1
	end case
	case
#
#  we have an escaped sequence here
#
	  when (i_query[ts]="\\")
	    let q=te
	    let te=te+1
	    let r=te+1
	    if (r>l)
	    then
		let r=""
	    end if
	    case
#
#  nothing found or end of buffer again
#
	      when (l-te<1)
	 	exit while
#
#  valid escape
#
	      when (i_query[q, te]="<+") or (i_query[q, te]="<*") or
		   (i_query[q, te]="+>") or (i_query[q, te]="*>")
		case
#
#  inside the comment, just skip
#
		  when (ccnt>0)
		    let s=te+1
#
#  inside an expansion
#
		  when (qcnt>0)
		    let i_query[ts, te]=i_query[q, te], " "
		    let s=te+1
#
#  neither, pass back
#
		  when (ts=b)
		    return "", "", i_query[q, te], r
		  otherwise
		    return b, ts-1, i_query[q, te], r
		end case
#
#  nothing interesting, save & continue scanning
#
	      otherwise
		let p=qbase+1
		let q_buf[qbase, p]="\\"
		let qbase=p+1
		let s=q
	    end case
#
#  comment start
#
	  when (i_query[ts, te]="<*")
	    if (ccnt=0) and (qcnt=0)
	    then
		let tbase=ts-1
	    end if
	    let ccnt=ccnt+1
	    let s=te+1
#
#  comment stop
#
	  when (i_query[ts, te]="*>")
	    let ccnt=ccnt-1
	    let r=te+1
	    if (r>l)
	    then
		let r=""
	    end if
	    case
#
#  still inside comment
#
	      when (ccnt>0)
		let s=te+1
#
#  unbalanced comment
#
	      when (ccnt<0)
		exit while
#
#  within expansion
#
	      when (qcnt>0)
		let s=te+1
#
#  return uncommented bit
#
	      when (tbase<b)
		return "", "", "", r
	      otherwise
		return b, tbase, "", r
	    end case
#
#  expansion start
#
	  when (i_query[ts, te]="<+")
	    case
#
#  within comment, skip
#
	      when (ccnt!=0)
		let s=te+1
		continue while
	      when (qcnt!=0)
	      when (b=ts)
		let tbase=ts-1
	      otherwise
#
#  we postpone expansion execution until after the sql interpreter has
#  parsed & executed whatever command is already available, so that
#  we can take advantage of it. this does not affect the usage of the
#  expansion facility by other modules
#
		return b, ts-1, "", ts
	    end case
	    let qcnt=qcnt+1
	    let q_stack[qcnt]=qbase
	    let s=te+1
#
#  expansion stop
#
	  when (i_query[ts, te]="+>")
	    case
#
# within comment, skip
#
	      when (ccnt!=0)
		let s=te+1
		continue while
#
# unballanced, bomb out
#
	      when (qcnt=0)
		let qcnt=qcnt-1
		exit while
	    end case
#
#  get option and expansion type
#
	    let p=q_stack[qcnt]
	    let q=qbase-1
	    let i_multi=""
	    let multi=""
	    let e_mode=""
	    let p_mode=""
	    let sep=" "
	    let quotes=""
	    let varname=""
	    while (p is not null)
		let r=p
		call postoken(q_buf[p, q], toksep)
		  returning p_mode, p
		let p=p+r-1
		let p_mode=downshift(p_mode)
		let tl=length(p_mode)
		case
#
#  operation type
#
		  when (pos("read", p_mode)=1)		#remember tl=... if necessary
		    let p_mode="file"
		    exit while
		  when (pos("exec", p_mode)=1)		#remember tl=... if necessary
		    let p_mode="pipe"
		    exit while
		  when (p_mode="select")
		    let p_mode=""
		    let p=r
		    exit while
		  when (pos("get", p_mode)=1) and (e_mode is null)	#remember tl=... if necessary
		    let e_mode=0
		    exit while
		  when (pos("silent", p_mode)=1 and tl>=3 and e_mode is null)
		    let e_mode=1
		  when (pos("coded", p_mode)=1 and e_mode is null)		#remember tl=... if necessary
		    let e_mode=2
		  when (pos("lone", p_mode)=1 and e_mode is null)		#remember tl=... if necessary
		    let e_mode=3
		  when (pos("put", p_mode)=1)		#remember tl=... if necessary
		    if (varname is not null or p is null)
		    then
			let p=""
		    else
			call sql_getvar(q_buf, p, q)
			  returning varname, p
			if (length(varname)=0)
			then
			    let p=""
			end if
		    end if
#
#  if single selection mode, none of this is allowed
#
		  when (not multi)
		    let p=""
		  when (pos("quotes", p_mode)=1)	#remember tl=... if necessary
		    if (p is null or not i_multi)
		    then
			let p=""
		    else
			call sql_evalexpr(q_buf, p, q, hash)
			  returning quotes, i
			case
			  when (i=p)
			    let p=""
			  when (length(quotes)=1)
			    let quotes[2]=quotes[1]
			    let p=i
			  otherwise
			    let p=i
			end case
			let i_multi=true
		    end if
		  when (pos("separator", p_mode)=1 and p is not null)	#remember tl=... if necessary
		    if (p is null or not i_multi)
		    then
			let p=""
		    else
			call sql_evalexpr(q_buf, p, q, hash)
			  returning sep, i
			if (i=p)
			then
			    let p=""
			else
			    let p=i
			end if
			let i_multi=true
		    end if
#
#  if mode selected, no further mode selection
#
		  when (multi is not null)
		    let p=""
		  when (pos("single", p_mode)=1 and tl>=3)	#remember tl=... if necessary
		    if (i_multi)
		    then
			let p=""
		    else
			let multi=false
		    end if
		  when (not i_multi)
		    let p=""
		  when (pos("multiple", p_mode)=1)		#remember tl=... if necessary
		    let multi=true
#
#  syntax error, no valid operation
#
		  otherwise
		    let p=""
		end case
	    end while
	    case
#
#  syntax error
#
	      when (p is null)
		exit while
	      when (e_mode=0)
#
#  nothing to do?!
#
	      when (length(q_buf[p, q])=0)
		exit while
#
#  no option specified, default is single pick list expansion
#
	      when e_mode is null
		let e_mode=2
	    end case
	    case
	      when (multi is not null)
	      when (i_multi is null)
		let multi=false
	      otherwise
		let multi=i_multi
	    end case
#
#  do actual expansion
#
	    case
	      when (not state)
		let txt=""
	      when (e_mode=0)
		let txt=evalget_sql(hash, q_buf[p, q], K_varsize, sep, quotes)
	      when (e_mode=1)
		let txt=silent_sql(p_mode, q_buf[p, q], K_varsize, sep, quotes, multi)
	      when (usr_isbatch())
#
#  when not in form mode, non silent expansions are disallowed
#
		let sqlca.sqlcode=-201
	      when (e_mode=3)
		call sql_givestatus(verbose, "")
		if multi
		then
		    let txt=multi_desc(p_mode, q_buf[p, q], K_varsize, sep, quotes, "")
		else
		    let txt=uni_desc(p_mode, q_buf[p, q], "")
		end if
		call sql_givestatus(verbose, "wa")
	      when multi
		call sql_givestatus(verbose, "")
		let txt=multi_help(p_mode, q_buf[p, q], K_varsize, sep, quotes, "")
		call sql_givestatus(verbose, "wa")
	      otherwise
		call sql_givestatus(verbose, "")
		call uni_help(p_mode, q_buf[p, q], false, "")
		  returning txt, dummy
		call sql_givestatus(verbose, "wa")
	    end case
	    case
#
#  picklist barfed
#
	      when sqlca.sqlcode!=0
		return "", "", "", ""
#
#  get or silent expansions are allowed not to return any text
#  (usefull to execute child processes)
#
	      when (e_mode=0) or (e_mode=1) or (not state)
#
#  user aborted or no result found
#
	      when txt is null
		let sqlca.sqlcode=notfound
		return "", "", "", ""
	    end case
#
#  store result
#
	    if (length(varname))
	    then
		call hst_enter(hash, varname, txt)
	    end if
	    let r=te+1
	    if (r>l)
	    then
		let p=""
	    end if
	    let p=q_stack[qcnt]
	    let qcnt=qcnt-1
	    case
#
#  still expansions on the stack
#
	      when (qcnt>0)
		let q=p+length(txt)-1
		let q_buf[p, q]=txt clipped
		let qbase=q+1
		let s=te+1
#
#  done with this one - return
#
	      when (tbase<b)
		return "", "", txt, r
	      otherwise
		return b, tbase, txt, r
	    end case
#
#  whatever it is, it's not interesting
#
	  otherwise
	    let s=te
	    if (qcnt>0) and (ccnt=0)
	    then
		let q_buf[qbase]=i_query[ts]
		let qbase=qbase+1
	    end if
	end case
    end while
    case
#
#  unbalanced comment or expansion - flag syntax error
#
      when (ccnt!=0) or (qcnt!=0)
	let sqlca.sqlcode=-201
	return "", "", "", ""
#
#  just for safety
#
      when (b<1) or (b>l)
	return "", "", "", ""
#
#  nothing interesting, pass back search string, flag search over
#
      otherwise
	return b, l, "", ""
    end case
end function
#
#  plain expansion
#
function silent_sql(tbl, cond, ln, sep, quotes, multi)
    define
	tbl	char(4),
	cond	char(K_exprsize),
	ln	smallint,
	sep	char(1),
	quotes	char(2),
	multi	smallint,
	fname	char(64),
	str	char(K_varsize),
	o_str	char(K_varsize),
	fd, j 	smallint

    let o_str=""
    case
      when (tbl="file")
	call get_token(cond)
	   returning fname, cond
	while (length(fname)>0)
	    let fd=file_open(filepath(fgl_getenv("DBPATH"), fname), "r")
	    while (not fd_eof(fd))
		let str=txt_commentdrop(fd_read(fd))
		call fd_droptoeol(fd)
		let o_str=o_str clipped, padstr_sql(o_str, str, quotes, sep)
		case
		  when (length(o_str)=0)
		  when multi and (length(o_str)<ln)
		  otherwise
		    let cond=""
		    exit while
		end case
	    end while
	    let j=fd_close(fd)
	    call get_token(cond)
	      returning fname, cond
	end while
      when (tbl="pipe")
	let fd=pipe_open(cond, "r")
	while (not fd_eof(fd))
	    let str=txt_commentdrop(fd_read(fd))
	    call fd_droptoeol(fd)
	    let o_str=o_str clipped, padstr_sql(o_str, str, quotes, sep)
	    case
	      when (length(o_str)=0)
	      when multi and (length(o_str)<ln)
	      otherwise
		exit while
	    end case
	end while
	let j=fd_close(fd)
      otherwise
	if (tbl is not null)
	then
	    if cond clipped!=" "
	    then
		let cond="where ", cond clipped
	    end if
	    let cond="select code_", tbl,", desc_", tbl," from ", tbl,
		     " ", cond clipped, " order by code_", tbl
	end if
	whenever error continue
	prepare sql_search from cond
	whenever error call trap_err
	if (sqlca.sqlcode=0)
	then
	    declare sql_hlp cursor for sql_search
	    foreach sql_hlp into str
		let o_str=o_str clipped, padstr_sql(o_str, str, quotes, sep)
		case
		  when (length(o_str)=0)
		  when multi and (length(o_str)<ln)
		  otherwise
		    exit foreach
		end case
	    end foreach
	    SQ_freecurs sql_hlp
	    free sql_search
	end if
    end case
    return o_str
end function
#
#  evaluate expression list
#
function evalget_sql(hash, varlist, ln, sep, quotes)
    define
	hash	text,
	varlist	char(K_exprsize),
	ln	smallint,
	sep	char(1),
	quotes	char(2),
	str,
	o_str	char(K_varsize),
	f, l,
	f1, k 	smallint

    let o_str=""
    let f=1
    let l=length(varlist)
    let k=1
    while (k)
	call sql_evalexpr(varlist, f, l, hash)
	  returning str, f1
	case
	  when status
	    let sqlca.sqlcode=status
	    return ""
	  when f1=f
	    let sqlca.sqlcode=-201
	    return ""
	  otherwise
	    let f=f1
	    let o_str=o_str clipped, padstr_sql(o_str, str, quotes, sep)
	    if (length(o_str)>=ln)
	    then
		return o_str
	    end if
	end case
	call getlist_sql(varlist, f, l, ",")
	  returning f, k
    end while
    return o_str
end function
#
#  return next expansion line
#
function padstr_sql(o_str, str, q, s)
    define o_str,
	   str		char(K_varsize),
	   q		char(2),
	   s		char(1)

    case
      when (length(str)=0)
	return ""
      when (length(o_str)=0)
	let str=q[1] clipped, str clipped, q[2] clipped
      otherwise
	let str=s, q[1] clipped, str clipped, q[2] clipped
    end case
    return str
end function
#
#  unfolds list of strings/variables
#
function getlist_sql(query, f, l, sep)
    define query	char(K_scriptbuf),
	   f, l		smallint,
	   sep		char(2),
	   r		smallint

    if (f>l)
    then
	return f, 0
    end if
    let f=f+skipspaces_sql(query, f, l)
    let r=f+length(sep)-1
    case
      when (f>l)
	return f, 0
      when (query[f, r]!=sep)
	return f, 0
      otherwise
	return f+1, 1
    end case
end function
#
#  skips token separators, if any
#
function skipspaces_sql(query, f, l)
    define query	char(K_scriptbuf),
	   f, l		smallint,
	   toksep	char(3),
	   i		smallint

    let toksep=" ", ascii 8, ascii 10
    if (f<=l)
    then
	let i=posnbrk(query[f, l], toksep)
	if (i)
	then
	    return i-1
	else
	    return l-f+1
	end if
    end if
    return 0
end function
