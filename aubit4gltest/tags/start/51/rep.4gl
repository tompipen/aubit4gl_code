database test1

#==============================================================================

main

	define	xrec		record
		wac		decimal(2,0),
		delv_dttm	datetime year to second,
		item_upc_cd	char(13),
		item_num	decimal(7,0),
		item_desc	char(30)
	end record
	define	xdec		decimal(2,0)

	initialize xrec to null

	start report xml_item to 'rep.out'

		let xrec.wac        	= 20
		let xrec.delv_dttm	=  "2001-11-11 11:11:00"
		let xrec.item_upc_cd	= "123456"
		let xrec.item_num	= 789
		let xrec.item_desc	= "ITEM-DESC"

display "A:",xrec.wac,"|",xrec.delv_dttm,"|",xrec.item_upc_cd,"|",xrec.item_num, "|",xrec.item_desc
		output to report xml_item(xrec.*)

display "A:",xrec.wac,"|",xrec.delv_dttm,"|",xrec.item_upc_cd,"|",xrec.item_num, "|",xrec.item_desc
		output to report xml_item(xrec.*)

display "A:",xrec.wac,"|",xrec.delv_dttm,"|",xrec.item_upc_cd,"|",xrec.item_num, "|",xrec.item_desc
		output to report xml_item(xrec.*)

	finish report xml_item

end main

################################################################################

report xml_item(xwrk)

	define	xwrk		record
		wac		decimal(2,0),
		delv_dttm	datetime year to second,
		item_upc_cd	char(13),
		item_num	decimal(7,0),
		item_desc	char(30)
	end record

        output  left   margin 0
		top    margin 0
		bottom margin 0
		page   length 1

	format
	on every row

display "B:",xwrk.wac,"|",xwrk.delv_dttm,"|",xwrk.item_upc_cd,"|",xwrk.item_num, "|",xwrk.item_desc
display ""

end report
