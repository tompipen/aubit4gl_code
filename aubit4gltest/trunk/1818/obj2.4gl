class math extends fglObject

private
	define lv_somedata integer
	define lv_str char(30)


	function bibble(a,b) 
	define a,b integer
		display "bibble"
	end function


	function add(a,b)
	define a,b integer
		display "IN math.add"
		return a+b
	end function
	
	object function sub_object(a,b)
	define a,b integer
		display "IN math.sub"
		return a-b
	end function

end class
