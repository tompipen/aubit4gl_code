/**
 * @file
 *
 * Part of run time library.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */


extern int ui_mode; 

/**
 * 
 * @param a 
 */
int screen_mode(int a) 
{
  static int smode=1;
  if (a==-1) 
	  return smode;
  
  if (a==smode) 
    return smode;
  if (a==0) 
  {
    smode=0;
    return smode;
  }
  smode=1;
  zrefresh(); 
	return smode;
}

/**
 * Write a debug message
 *
 * @param s The debug message
 */
void debug(char *s) 
{
  debug_full("ERROR  - debug called in full with %s",s);
}


