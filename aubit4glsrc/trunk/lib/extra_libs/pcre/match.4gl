define mv_arr array[10] of char(255)


code
#include <stdio.h>
#include <string.h>
#include <pcre.h>
#define OVECCOUNT 30
int ovector[OVECCOUNT];
endcode

function pcre_text(i)
define i integer
return mv_arr[i]
end function

function pcre_match(p,s)
define p char(1024)
define s char(1024)
define sl integer
define ok integer
define a integer
for a=1 to 10 
	initialize mv_arr[a] to null
end for

code
{
  const char *error;
  int erroffset;
  pcre *re;
  int rc;
  int i;

  for (a=0;a<OVECCOUNT;a++) ovector[a]=0;

  A4GL_trim (p);
  A4GL_trim (s);
  re = pcre_compile (p,		/* the pattern */
		     0,		/* default options */
		     &error,	/* for error message */
		     &erroffset,	/* for error offset */
		     NULL);

  if (re == 0)
    ok = 0;
  else
    {
      sl = strlen (s);
      rc = pcre_exec (re,	/* the compiled pattern */
		      NULL,	/* no extra data - we didn't study the pattern */
		      s,	/* the subject string */
		      sl,	/* the length of the subject */
		      0,	/* start at offset 0 in the subject */
		      0,	/* default options */
		      ovector,	/* output vector for substring information */
		      OVECCOUNT);

      if (rc < 0)
	{
	  ok = 0;
	}
      else
	{
		for (i = 0; i < rc; i++) {
			char buff[2048];
  			char *substring_start = s + ovector[2*i];
  			int substring_length = ovector[2*i+1] - ovector[2*i];
  			snprintf(buff,2048,"%.*s", substring_length, substring_start);
			buff[2047]=0;
			strncpy(mv_arr[i],buff,255);
			mv_arr[i][255]=0;
  		}
		ok=1;

	}
    }

}
endcode

return ok
end function
