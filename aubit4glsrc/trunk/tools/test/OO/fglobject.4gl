
class  fglObject

	function add(a,b)
		define a,b integer
		display "In fglObject add"
		return a+b
	end function



	function sub(a,b)
		define a,b integer
		display "In fglObject sub"
		return a-b
	end function

	function poly_add(a,b)
	define a,b integer	
	return a+b
	end function

	function poly_add(a,b)
	define a,b char(400)

		if length(a) then
			return a clipped||" "||b clipped
		else
			return b
		end if
	end function
	
end class
