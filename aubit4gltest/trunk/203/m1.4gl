# Dynamic memory allocation
define aa dynamic array of integer
define lv_dtabnames dynamic array of record
		ss char(20)
end record
define lv_t char(20)
main
define a integer

	if fgl_isdynarr_allocated(aa) then
		display "Allocated aa (1)"
	else
		display "Not allocated aa (1)"
	end if

	allocate array aa [33]
	allocate array lv_dtabnames [33]

	let lv_t="Hello"
	display lv_t[2]

	let a=fgl_dynarr_extentsize(aa,1)
	display "size=",a


	for a=1 to 33
		let aa[a]=a*2
	end for

	for a=1 to 33
		display aa[a]
	end for

	resize array aa[22]
	let a=fgl_dynarr_extentsize(aa,1)
	display "size=",a

	for a=1 to 22
		display aa[a]
	end for


	if fgl_isdynarr_allocated(aa) then
		display "Allocated aa (2)"
	else
		display "Not allocated aa (2)"
	end if

	display "Deallocating.."
	deallocate array aa

	if fgl_isdynarr_allocated(aa) then
		display "Allocated aa (3)"
	else
		display "Not allocated aa (3)"
	end if


end main
