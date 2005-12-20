
main
	start report lister to "out"

	output to report lister('alpha',' ','London')
	output to report lister('alpha',' ','York')
	output to report lister('alpha',' ','Chester')
	output to report lister('alpha',' ','Exeter')
	output to report lister('alpha','Belgium','Brussels')
	output to report lister('alpha','USA','New York')
	output to report lister('alpha','USA','Washington')
	output to report lister('alpha','USA','Seattle')

	finish report lister
end main

report lister(hdr,subh,dtl)
	define hdr,subh,dtl varchar(50)
	#define prev varchar(50)

	order external by hdr, subh

	format
	#first page header
		#let prev=' '
	before group of hdr
		if lineno>1 then skip to top of page   end if
		print hdr

	before group of subh
		skip 2 lines   
		if length(subh)=0  then print '[UK]' else print subh end if
		print ""

	after group of subh
		print '======================='

	on every row
		print hdr clipped,column 20,subh clipped, column 40,dtl
end report
