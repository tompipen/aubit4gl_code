

####
main
####
	define l_fname char(64)

	# Change to the database on the following line to point to the
	# database you wish to store your mapfile data in
	#database informix

#FIXME: take from parameters:
#db name
#username
#password
#file to load



	OPEN SESSION s_ifmx TO DATABASE maindb as user "informix" password "ifmx"
    SET SESSION TO s_ifmx



	if num_args() > 0 then
	   let l_fname=arg_val(1)
	   delete from acl_map where map_module=l_fname
	   load from l_fname insert into acl_map
	   if status <> 0 then
	      display "error loading"
	   end if
	else
	   display "No file to load"
	end if

    CLOSE SESSION s_ifmx


end main

#---------------------------- EOF --------------------------------