/**
 * @file
 * Gettime function
 * Cannot use calls to debug here!
 */

#include <time.h>

/**
 * Get time in seconds.
 *
 * @return The time in seconds.
 */
long gettime(void) {
return time(0);
}



/**
 * Write a debug message
 *
 * @param s The debug message
 */
/* what is this doing here?
    a4gl_debug.h defines debug as:
    #define debug set_line(__FILE__,__LINE__); debug_full

    it is needed
*/
void debug(char *s)
{
  debug_full("ERROR  - debug called in full with %s",s);
}
