
# This utility will translate to and from roman numerals less than 500 million.

# It supports the use of the vincula (overstrike) to denote a factor of 1000,
# and half-frame to denote a factor of 100,000 (http://home.att.net/~numericana/answer/roman.htm)

# Because of ASCII limitations,
# it uses the medieval convention of a trailing 'm' to denote the overstrike
# - but in reverse case, since superscript is not available (eg XLVm ... or xlvM ...);
# and for similar reasons, the half-frame is represented by '|...m|' or '|...M|'.
# BUT BE WARNED, these conventions are not in general use!

# Conversions TO roman add a space after these oddities, to improve readability.
# Conversions from roman will support the space, but do not assume it.

# Conversions FROM roman where the case is inconsistent may produce odd results
# eg CmI=10001 and cMi=10001 (assuming the vincula), but CMI=901 and cmi=901

# Conversions TO roman numerals use the subtractive principle (eg IV is valid)
# and assume the later D,L, and V.

# Conversions FROM roman numerals support the non-use of the subtractive principle (eg IIII is valid)
# and do not assume D or L, though V is assumed.
# A trailing 'j' in place of an 'i' is supported.

	define ERR varchar(50)
{
main
	define i_str varchar(50)

	if num_args()>0 then 
		let i_str=arg_val(1)				# a rudimentary MAIN, to enable library use
		call roman(i_str)
		end if
	end main


}

function get_last_err()
	return ERR
end function

# ===============================================================================
# the following replicates a LIBRARY function - delete it here if the library is used
# ===============================================================================
local function instr(in_long,in_short)		# this is not exported from the library....
	define in_long,in_short char(100)
	define in_i,in_j smallint

	if length(in_long) is null then return 0 ; end if
	if length(in_long)=0 then return 0 ; end if

	let in_i=1
	let in_j=length(in_short)

	while in_i<=length(in_long)
		if length(in_short)=0
			then	if in_long[in_i]=' ' then return in_i end if
			else	if in_long[in_i,in_i+in_j-1]=in_short then return in_i end if
			end if
		let in_i=in_i+1
		end while

	return 0			# not found!
end function
# ===============================================================================

function roman(ro_is)
	define ro_is varchar(50)					# input string

	define ro_os,ro_ts varchar(50)				# output string, temp string`
	define ro_n,ro_tn,ro_sn integer
	define ro_p,ro_vinc smallint

	if length(ro_is)=0 then 
		LET err='ERROR: no argument given' 
		return   NULL
	end if

	let ro_ts=''

	# which way should we go?
	if ro_is[1] matches "[0-9]"			# a crude test for a numeric input

	then								# convert TO roman numbers
		let ro_n=ro_is					# force numeric
		if ro_n=0 or ro_n is NULL then 
			LET err='ERROR: non-numeric input'
			return   NULL
		end if
		if ro_n<0 then 
			LET err='ERROR: negatives not allowed!' 
			return    NULL
		end if
		if ro_n>499999999 then 
			LET err='ERROR: number too large - must be less than 500 million'
			return NULL
		end if
		if ro_n>4999999 then
			let ro_tn=ro_n/100000
			let ro_os=to_roman(ro_tn)
			let ro_ts='|',ro_os,'m| '
			let ro_n=ro_n-(100000*ro_tn)
			end if
		if ro_n>4999 then
			let ro_tn=ro_n/1000
			let ro_os=to_roman(ro_tn)
			let ro_ts=ro_ts,ro_os,'m '
			let ro_n=ro_n-(1000*ro_tn)
			end if
		let ro_os=to_roman(ro_n)
		LET err=""
		return ro_ts||ro_os

	else								# convert to ARABIC numbers
		let ro_ts=''
	
		# are overline conventions in use?
		# (1) is there a half-frame?
		if ro_is[1]='|'
			then	let ro_n=instr(ro_is[2,50],'|')			# ignore the 'm' - might be alternate case...
	
					# is it framed correctly?
					if ro_n=0	then 
						LET err="ERROR: "||ro_is||" badly formed (1)"
						  return   NULL
					end if
					if upshift(ro_is[ro_n])<>'M'
							then  LET err="ERROR: "||ro_is||" badly formed (2)"  return NULL  end if
	
					let ro_ts=upshift(ro_is[2,ro_n-1])		# split the string - separate out the half-frame content
					let ro_is=upshift(ro_is[ro_n+2,50])		# and the rest

					call from_roman(ro_ts) returning ro_n,ro_p
					if ro_p>0 then
						let ro_os=ro_ts[ro_p,50]
						LET err="ERROR: "||ro_ts||" badly formed (3) ("||ro_os||")" return NULL
						end if

					let ro_sn=ro_n
					let ro_sn=100000*ro_sn
	
					# if there are leading spaces, get rid of them
					while length(ro_is)>0 and ro_is[1]=' ' let ro_is=ro_is[2,50]   end while
			end if
	
		# (2) check for a vincula replacement
		let ro_vinc=0
		if ro_is[1] matches "[A-Z]"
			then	let ro_vinc=instr(ro_is,'m')
			end if
		if ro_is[1] matches "[a-z]"
			then	let ro_vinc=instr(ro_is,'M')
			end if
		if ro_vinc
			then	let ro_ts=upshift(ro_is[1,ro_vinc-1])
					call from_roman(ro_ts) returning ro_n,ro_p
					if ro_p>0 then
						let ro_os=ro_is[ro_p,50]
						LET err="ERROR: "||ro_is||" badly formed (4) ("||ro_os||")"
						 return NULL
						end if
					let ro_tn=ro_tn+(1000*ro_n)
	
					let ro_is=ro_is[ro_vinc+1,50]			# adapt the string for next check
					while length(ro_is)>0 and ro_is[1]=' ' let ro_is=ro_is[2,50]   end while
			end if
	
		# so nothing explicitly special ...
		let ro_is=upshift(ro_is)
		call from_roman(ro_is) returning ro_n,ro_p
		let ro_os=ro_is[ro_p,50]
		if ro_os[1]="M" and ro_vinc=0		# is there a vincula here?
			then	let ro_tn=ro_n
					let ro_tn=ro_tn*1000
					let ro_ts=ro_is[ro_p+1,50]
					while length(ro_ts)>0 and ro_ts[1]=' ' let ro_ts=ro_ts[2,50]   end while
					call from_roman(ro_ts) returning ro_n,ro_p

			end if
	
		if ro_p>0 then
			let ro_os=ro_is[ro_p,50]
				LET ERR="ERROR: "||ro_is||" badly formed (5) ("||ro_os||")"
			 	return NULL
			end if
	
		# if we've got here, it's got to be good news...
		let ro_n=ro_n+ro_tn+ro_sn					# in case ro_tn holds anything...
		return ro_n
	end if

	end function

function to_roman(to_n)
	define to_n integer
	define to_str varchar(50)

	let to_str=''
	while to_n>=1000	let to_str=to_str,'M' 		let to_n=to_n-1000	end while
	if to_n>=900		then let to_str=to_str,'CM'	let to_n=to_n-900	end if
	if to_n>=500		then let to_str=to_str,'D'	let to_n=to_n-500	end if
	if to_n>=400		then let to_str=to_str,'CD'	let to_n=to_n-400	end if
	while to_n>=100		let to_str=to_str,'C'		let to_n=to_n-100	end while
	if to_n>=90			then let to_str=to_str,'XC'	let to_n=to_n-90	end if
	if to_n>=50			then let to_str=to_str,'L'	let to_n=to_n-50	end if
	if to_n>=40			then let to_str=to_str,'XL'	let to_n=to_n-40	end if
	while to_n>=10		let to_str=to_str,'X'		let to_n=to_n-10	end while
	if to_n>=9			then let to_str=to_str,'IX'	let to_n=to_n-9		end if
	if to_n>=5			then let to_str=to_str,'V'	let to_n=to_n-5		end if
	if to_n>=4			then let to_str=to_str,'IV'	let to_n=to_n-4		end if
	while to_n>=1		let to_str=to_str,'I'		let to_n=to_n-1		end while

	return to_str
	end function

function from_roman(fr_s)
	define fr_s varchar(50)
	define fr_n integer
	define fr_p smallint

	let fr_n=0
	let fr_p=1

	# ...m and |...m| conventions are implemented in the calling code

	while fr_s[1]='M'	let fr_s=fr_s[2,50]			let fr_p=fr_p+1	let fr_n=fr_n+1000		end while
	if fr_s[1,2]='CM'	then let fr_s=fr_s[3,50]	let fr_p=fr_p+2	let fr_n=fr_n+900		end if

	if fr_s[1,3]='DCD'	then return fr_n,fr_p   end if	# rule this out here, to simplify code below
	if fr_s[1]='D'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+500
	else
	if fr_s[1,5]='CCCCC'
						then let fr_s=fr_s[6,50]	let fr_p=fr_p+5	let fr_n=fr_n+500		end if
	end if

	if fr_s[1,2]='CD'	then let fr_s=fr_s[3,50]	let fr_p=fr_p+2	let fr_n=fr_n+400		
	else
	if fr_s[1]='C'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+100		end if		# allow for 3 C
	if fr_s[1]='C'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+100		end if
	if fr_s[1]='C'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+100		end if
	if fr_s[1]='C'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+100		end if		# if no CD, then maybe CCCC
	end if

	if fr_s[1,3]='XCL'	then return fr_n,fr_p end if		# rule this out here, to simplify code below
	if fr_s[1,3]='XCX'	then return fr_n,fr_p end if		# rule this out here, to simplify code below
	if fr_s[1,2]='XC'	then let fr_s=fr_s[3,50]	let fr_p=fr_p+2	let fr_n=fr_n+90		end if
	if fr_s[1]='L'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+50		end if

	if fr_s[1,2]='XL'	then let fr_s=fr_s[3,50]	let fr_p=fr_p+2	let fr_n=fr_n+40
	else
	if fr_s[1]='X'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+10		end if		# allow for 3 X
	if fr_s[1]='X'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+10		end if
	if fr_s[1]='X'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+10		end if
	if fr_s[1]='X'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+10		end if		# if no XL, then maybe XXXX
	end if

	if fr_s[1,3]='IXI'	then return fr_n,fr_p end if		# rule this out here, to simplify code below
	if fr_s[1,3]='IXV'	then return fr_n,fr_p end if		# rule this out here, to simplify code below
	if fr_s[1,2]='IX'	then let fr_s=fr_s[3,50]	let fr_p=fr_p+2	let fr_n=fr_n+9			end if

	if fr_s[1,3]='VIV'	then return fr_n,fr_p end if		# rule this out here, to simplify code below
	if fr_s[1]='V'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+5			end if

	if fr_s[1,2]='IV'	then let fr_s=fr_s[3,50]	let fr_p=fr_p+2	let fr_n=fr_n+4
	else
	if fr_s[1]='I'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+1			end if		# allow for 3 I
	if fr_s[1]='I'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+1			end if
	if fr_s[1]='I'		then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+1			end if
	if fr_s[1]='I' or fr_s[1]='J'
						then let fr_s=fr_s[2,50]	let fr_p=fr_p+1	let fr_n=fr_n+1			end if		# if no 'IV', then maybe IIII
	end if

	if length(fr_s)>0
		then return fr_n,fr_p			# error
		else return fr_n,0
		end if
	end function
