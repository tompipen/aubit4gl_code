/**
 * @file
 *
 * Part of run time library.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#include "a4gl_dbform.h" //needed for struct s_form_dets in function find_attribute


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

// moved here from lib/libform/form_xdr/readforms.c

char *
find_attribute (struct s_form_dets *f, int field_no)
{
  int a;

  for (a = 0; a < f->fileform->attributes.attributes_len; a++)
    {

      if (f->fileform->attributes.attributes_val[a].field_no == field_no)
	{
	  debug ("FIeld no %d is reference by attribute %d\n", field_no, a);
	  return (char *) &f->fileform->attributes.attributes_val[a];
	}
    }
  debug ("Couldnt find entry for field no %d\n", field_no);
  return 0;

}

// ============================ EOF ============================
