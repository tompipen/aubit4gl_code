/**
 *  * Trim the spaces at the right part of a string.
 *   *
 *    * @param s The string to be trimmed
 *     */
static void trim_spaces (char *s)
{
	  int l;
	    for (l = strlen (s) - 1; l >= 0; l--)
		        {
				      if (s[l] == ' ')
					              s[l] = 0;
				            else
						            break;
					        }
}

