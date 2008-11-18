
code
#include <sys/types.h>
#include <sys/stat.h>
endcode


function compare_file_times(lv_f1,lv_f2)
define lv_f1,lv_f2 char(512)
define lv_t1,lv_t2 integer
initialize lv_t1 to null
initialize lv_t2 to null

code
{
struct stat buf;
A4GL_trim(lv_f1);
A4GL_trim(lv_f2);

if (stat(lv_f1,&buf)>=0) { lv_t1=buf.st_mtime; }
if (stat(lv_f2,&buf)>=0) { lv_t2=buf.st_mtime; }
}
endcode


if lv_t1<lv_t2 then
	return 1
end if

return 0


end function


