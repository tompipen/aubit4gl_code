#loads map file into database

define
	l_fname char(264)

####
main
####
define
	type, uid, pwd, db char (20)

	if num_args() = 5 then
		let l_fname=arg_val(1)
		let uid=arg_val(2)
		let pwd=arg_val(3)
		let db=arg_val(4)
		let type=arg_val(5)

		#OPEN SESSION s_ifmx TO DATABASE maxdev as user "informix" password "ifmx"
		#OPEN SESSION s_ifmx TO DATABASE db as user uid password pwd
		#SET SESSION TO s_ifmx
		database db
		display "Connected to the database."

		case type
			when "map"
			    call load_map()
			otherwise
			      display "ERROR: unknown type"
		end case

		#CLOSE SESSION s_ifmx
		close database
	else
	   display "Usage:"
	   display "loadmap file_name uid pwd db [map]"
	end if

end main

function load_map()

	   delete from acl_map where map_module=l_fname
	   load from l_fname insert into acl_map
	   if status <> 0 then
	      display "error loading"
	   end if


end function

#---------------------------- EOF --------------------------------