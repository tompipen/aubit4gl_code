code
#include <sys/types.h>
#include <sys/stat.h>
endcode


function get_file_time(lv_name)
define lv_name char(256)
define lv_t1 integer
code
{
struct stat buf;
A4GL_trim(lv_name);
if (stat(lv_name,&buf)>=0) { lv_t1=buf.st_mtime; }
}
endcode
message "Getting times for ",lv_name clipped," :",lv_t1 sleep 4
return lv_t1

end function
