code
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
endcode

WHENEVER ERROR CONTINUE
WHENEVER ANY ERROR CONTINUE
WHENEVER SQLERROR CONTINUE


# Maybe we should be using a module level variable - and 'loading' a key
# rather than passing it backwards and forwards
DEFINE mv_key char(500)

####################################
FUNCTION get_privatekey(p_filename)
####################################
DEFINE p_filename char(256)

return get_privatekey_with_passphrase(p_filename,NULL)

END FUNCTION



FUNCTION get_privatekey_with_passphrase(p_filename,p_passphrase)
DEFINE  p_filename char(256),
	p_passphrase char(255)
DEFINE lv_use_passphrase INTEGER

if p_passphrase is null then
	let lv_use_passphrase=false
else 
	let lv_use_passphrase=true
end if

code
	A4GL_trim(p_filename);
	A4GL_trim(p_passphrase);
	// REAL SSL CODE HERE...
endcode

RETURN "Blah"

END FUNCTION


FUNCTION sign_with_key (p_string, p_crypttext, p_key)
DEFINE p_string char(30000)
define p_crypttext char(256)
define p_key char(500)

code
{
	// REAL SSL CODE HERE...
}
endcode

return ""

END FUNCTION


function free_key(p_key)
define p_key CHAR(500)
end function
